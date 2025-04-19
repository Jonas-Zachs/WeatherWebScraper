# WeatherWebScraper

## Introduction
WeatherWebScraper is a Qt‑based C++ desktop application that fetches weather data from [wttr.in](https://wttr.in) and displays it in a simple GUI

---

## Prerequisites
- **Visual Studio 2022** (Desktop development with C++)
- **Qt Visual Studio Tools extension** (for Qt integration in Visual Studio)
- **libcurl** built with SSL/TLS support, for making HTTPS requests (already provided in the "Dependencies" folder)
- A valid **`cacert.pem`** CA-bundle file:
  - Download the latest from [curl.se](https://curl.se/docs/caextract.html) and save it locally.

---

## Building
1. **Clone the repository**
2. **Open** `WeatherWebScraper.sln` in Visual Studio 2022
3. **Build** the solution

---

## Usage
1. Run the compiled `WeatherWebScraper.exe`.
2. Enter a location (e.g., `Berlin`, `London`, or `Vienna`) in the text field.
3. Click **Search** to fetch and display the current weather forecast.

---

## Notes
- **SSL certificate path**: if libcurl reports certificate errors, verify that `CURLOPT_CAINFO` in `Fetcher.cpp` points to your local `cacert.pem` file
