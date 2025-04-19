#include "pch.h"
#include "Parser.h"
#include "TrimString.h"

// Function to parse the current weather data from the HTML response
WeatherData parse_current(const std::string& html) {
    WeatherData result;  // Declare a WeatherData object to store the parsed data
    std::smatch match;  // Declare a smatch object to hold the regex match results

    // Location: Search for the "Location:" text and capture the location
    if (std::regex_search(html, match, std::regex(R"(Location:\s*([^\n<]+))"))) {
        result.location = trim(match[1].str());  // Trim and store the captured location in the result
    }

    // Weather Condition: Search for the weather condition that appears after the first </span> tag
    if (std::regex_search(html, match, std::regex(R"(</span>\s*([^\n<]+))"))) {
        result.condition = trim(match[1].str());  // Trim and store the captured weather condition in the result
    }

    // Temperature: Capture the first visible temperature value (positive or negative number) after <span> with class "ef"
    if (std::regex_search(html, match, std::regex(R"(<span class="ef\d+">([+-]?\d+)</span>\s*\()"))) {
        result.temperature = trim(match[1].str()) + " \u00B0C";  // Trim the captured temperature and append " °C" to it
    }

    // Precipitation: Capture the precipitation value in the format of a floating-point number followed by "mm |"
    if (std::regex_search(html, match, std::regex(R"((\d+\.\d+)\s*mm\s*\|)"))) {
        result.precipitation = trim(match[1].str()) + " mm";  // Trim and store the precipitation value with " mm" appended
    }

    return result;  // Return the parsed weather data
}