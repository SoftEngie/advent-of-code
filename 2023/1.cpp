#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, std::string> numberMap = {
    {"one", "1"},
    {"two", "2"},
    {"three", "3"},
    {"four", "4"},
    {"five", "5"},
    {"six", "6"},
    {"seven", "7"},
    {"eight", "8"},
    {"nine", "9"}
};

std::string convertDigit(const std::string& writtenNumber) {
    auto it = numberMap.find(writtenNumber);
    return (it != numberMap.end()) ? it->second : writtenNumber;
}

int main(int argc, char** argv){
    int result = 0;
    std::string line;
    std::ifstream input_file("1.input");
    std::regex digit("(?=(one|two|three|four|five|six|seven|eight|nine|\\d))");
    // F overlaps !!! like oneight --> only one was matched... Lookahead and lookbehind for regex is awesome
    std::sregex_iterator end;
    if (input_file.is_open()){
        while(getline(input_file, line)){
            std::sregex_iterator it(line.begin(), line.end(), digit);
            std::vector<std::string> matches{};
            for (std::smatch sm; it!=end; it++) {
                sm = *it;
                matches.push_back(convertDigit(sm.str(1)));
            }

            std::string calibration{matches[0]+matches[matches.size()-1]};
            result += std::stoi(calibration);
        }
        std::cout << "Result is : " << result << std::endl;
    }

}