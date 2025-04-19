#include "pch.h"
#include "TrimString.h"

// Function to trim leading and trailing whitespace from a string
std::string trim(const std::string& str) {
    // Check if the input string is valid (non-empty)
    if (str.empty()) {
        return "";  // Return an empty string if the input is empty
    }

    // Find the first character that is not a whitespace from the beginning of the string
    auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) { return std::isspace(ch); });

    // Find the first character that is not a whitespace from the end of the string
    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) { return std::isspace(ch); }).base();

    // If the start position is less than the end position, return a substring without leading and trailing spaces
    // Otherwise, return an empty string (in case the string only contains whitespace)
    return (start < end) ? std::string(start, end) : std::string();
}