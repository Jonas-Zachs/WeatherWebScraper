#pragma once

#include "ui_WeatherWebScraper.h"

class WeatherWebScraper : public QMainWindow
{
    Q_OBJECT

public:
    WeatherWebScraper(QWidget *parent = nullptr);
    ~WeatherWebScraper();

private slots:
    void on_pbSearch_clicked();

private:
    Ui::WeatherWebScraperClass ui;
};