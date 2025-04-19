#include "pch.h"
#include "Fetcher.h"

// Callback function to write the response data to a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;  // Calculate total size of the data
    output->append(static_cast<char*>(contents), totalSize);  // Append the data to the output string
    return totalSize;  // Return the total size of the data
}

// Function to fetch website content
std::string fetchWebsite(const std::string& url) {
    CURL* curl = curl_easy_init();  // Initialize CURL
    if (!curl) {
        std::cerr << "Error: CURL could not be initialized.\n";  // If CURL initialization fails
        return "Error";
    }

    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());  // Set the URL for the request
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);  // Set the callback function for writing data
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);  // Set the string where the response will be stored

    // SSL/TLS Options
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);  // Verify the peer's SSL certificate
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);  // Verify the host's SSL certificate

    // Accept encoding (empty means all encodings are accepted)
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "");

    // Path to cacert.pem for SSL verification
    curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");

    CURLcode res = curl_easy_perform(curl);  // Perform the request
    if (res == CURLE_OK) {
        std::cout << "SSL/TLS connection successful.\n";  // If the connection was successful
    }
    else {
        std::cerr << "Error: " << curl_easy_strerror(res) << "\n";  // Print the error if the connection failed
        curl_easy_cleanup(curl);  // Cleanup CURL resources
        return "Error";
    }

    curl_easy_cleanup(curl);  // Cleanup CURL resources
    return response;  // Return the response content
}