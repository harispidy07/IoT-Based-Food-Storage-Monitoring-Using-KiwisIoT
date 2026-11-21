#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <DHT.h>

// Wi-Fi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// DHT11 Configuration
#define DHT_PIN D4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

// MQ-135 Analog Pin
#define MQ135_PIN A0

// Monitoring Limits
const float TEMP_LIMIT = 30.0;
const float HUMIDITY_LIMIT = 70.0;

// Experimental MQ-135 Threshold
const int AIR_THRESHOLD = 400;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;
const unsigned long interval = 3000;

void setup() {
  Serial.begin(115200);

  dht.begin();
  kiwisiot.begin();

  Serial.println("Food Storage Monitoring Started");
}

void loop() {
  kiwisiot.run();

  if (millis() - previousMillis >= interval) {
    previousMillis = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int airQuality = analogRead(MQ135_PIN);

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("DHT11 Sensor Error");
      return;
    }

    bool alert =
      temperature > TEMP_LIMIT ||
      humidity > HUMIDITY_LIMIT ||
      airQuality > AIR_THRESHOLD;

    String storageStatus = alert ? "ALERT" : "NORMAL";

    Serial.println("\n--- FOOD STORAGE MONITOR ---");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("MQ-135 Analog Reading: ");
    Serial.println(airQuality);

    Serial.print("Storage Status: ");
    Serial.println(storageStatus);

    // Send data to KiwisIoT
    kiwisiot.send("0", String(temperature, 1));
    kiwisiot.send("1", String(humidity, 1));
    kiwisiot.send("2", String(airQuality));
    kiwisiot.send("3", storageStatus);
  }
}