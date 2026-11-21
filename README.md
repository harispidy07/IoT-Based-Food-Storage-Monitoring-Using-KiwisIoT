# IoT-Based Food Storage Monitoring Using KiwisIoT

## Project Overview

This project uses IoT technology to monitor environmental conditions in food storage areas. The NodeMCU ESP8266 collects temperature and humidity data and sends it to the KiwisIoT dashboard, helping users monitor storage conditions and maintain food quality.

## Hardware Components

- NodeMCU ESP8266
- Temperature and Humidity Sensor
- Jumper wires
- Breadboard
- Power supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- Sensor Library
- KiwisIoT Arduino Library
- KiwisIoT Dashboard

## Circuit Connections

Connect the temperature and humidity sensor to the NodeMCU according to the sensor pin configuration used in the project.

## Working Principle

The sensor measures the temperature and humidity inside the food storage area. The ESP8266 reads the sensor values and transmits them to the KiwisIoT platform over Wi-Fi.

The dashboard provides real-time environmental data, allowing users to remotely monitor storage conditions and identify changes that could affect stored food.

## KiwisIoT Dashboard

- Monitor real-time temperature.
- Monitor humidity levels.
- View storage conditions remotely.
- Track environmental changes through the dashboard.

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the project configuration.

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

## Applications

- Food storage facilities
- Grocery stores
- Cold storage units
- Restaurants and commercial kitchens
- Food warehouses

## Project Reference

**Hackster.io Project:**  
[IoT-Based Food Storage Monitoring Using KiwisIoT](https://www.hackster.io/harispidy07/iot-based-food-storage-monitoring-using-kiwisiot-c00d2c)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Smart food storage monitoring through real-time IoT connectivity._
