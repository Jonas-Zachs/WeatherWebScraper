#include "pch.h"
#include "WeatherWebScraper.h"

int main(int argc, char* argv[])
{
    // Initialize the global CURL library environment for multi-threaded use
    if (curl_global_init(CURL_GLOBAL_ALL) != 0) {
        std::cerr << "Error: curl_global_init() failed.\n";
        return 1;
    }

    QApplication a(argc, argv);
    WeatherWebScraper w;
    w.show();

    // Clean up the global CURL environment before exiting the application
    curl_global_cleanup();

    return a.exec();
}