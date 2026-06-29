#include <string>

namespace log_line {

std::string message(std::string line) {
    std::size_t index = line.find(":");
    return line.substr(index + 2); 
}

std::string log_level(std::string line) {
    std::size_t index = line.find(":");
    // Fix: We need the length of the substring, not the ending index.
    return line.substr(1, index - 2); 
}

std::string reformat(std::string line) {
    // Fix: Add a space before the opening parenthesis to match standard log formats
    return message(line) + " (" + log_level(line) + ")";
}

}  // namespace log_line