#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>

double convert(double degrees, double minutes, double seconds, char direction) {
    double decimal_degrees = degrees + minutes / 60 + seconds / 3600;
    if (direction == 'S' || direction == 'W') {
        decimal_degrees *= -1;
    }
    return decimal_degrees;
}

std::vector<double> parse_dms(const std::string& dms_str) {
    std::regex pattern(R"((\d+)\s*deg\s*(\d+)'\s*([\d\.]+)\"\s*([NSEW]))");
    std::smatch matches;
    std::vector<double> coordinates;

    auto begin = std::sregex_iterator(dms_str.begin(), dms_str.end(), pattern);
    auto end = std::sregex_iterator();

    if (std::distance(begin, end) != 2) {
        throw std::invalid_argument("Invalid DMS coordinates");
    }

    for (std::sregex_iterator i = begin; i != end; ++i) {
        matches = *i;
        double degrees = std::stod(matches[1].str());
        double minutes = std::stod(matches[2].str());
        double seconds = std::stod(matches[3].str());
        char direction = matches[4].str()[0];
        double dd = convert(degrees, minutes, seconds, direction);
        coordinates.push_back(dd);
    }

    return coordinates;
}

int main() {
    std::string dms_input;
    std::cout << "Enter DMS coordinates (Example: 35 deg 39' 56.27\" N, 139 deg 41' 32.50\" E): ";
    std::getline(std::cin, dms_input);

    try {
        std::vector<double> coordinates = parse_dms(dms_input);
        std::cout << coordinates[0] << " degrees Latitude, " << coordinates[1] << " degrees Longitude" << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "Press Enter to exit...";
    std::cin.get();    
    
    return 0;
}

