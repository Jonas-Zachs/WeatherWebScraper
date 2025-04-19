#include "pch.h"
#include "WeatherWebScraper.h"
#include "WeatherData.h"
#include "Fetcher.h"
#include "Parser.h"
#include "TrimString.h"

WeatherWebScraper::WeatherWebScraper(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

WeatherWebScraper::~WeatherWebScraper()
{}

// Slot function triggered when the "Search" button is clicked
void WeatherWebScraper::on_pbSearch_clicked()
{
    // Construct the URL for the weather service (wttr.in) by appending the user input location
    std::string url = "https://wttr.in/" + trim(ui.leSearchLocation->text().toStdString());

    // Fetch the HTML content from the constructed URL
    std::string html_content = fetchWebsite(url);

    // Parse the HTML content to extract the weather data
    WeatherData data = parse_current(html_content);

    // Update the UI elements with the parsed weather data
    ui.leLocation->setText(QString::fromStdString(data.location));  // Display the location
    ui.leTemperature->setText(QString::fromStdString(data.temperature));  // Display the temperature
    ui.leCondition->setText(QString::fromStdString(data.condition));  // Display the weather condition
    ui.lePrecipitation->setText(QString::fromStdString(data.precipitation));  // Display the precipitation
}