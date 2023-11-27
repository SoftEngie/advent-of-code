#include<string>
#include<vector>
#include<map>
#include<fstream>
#include <iostream>
#include <functional>
#include <set>
#include <regex>
#include <algorithm>

struct Range {
    int start = 0;
    int end = 0;

    bool isContained(const Range& range) { return end <= range.end && start >= range.start ; }
    bool isOverlapping(const Range& range) { return std::max(start, range.start) <= std::min(end, range.end); }
};

int main(int argc, char** argv){
    int result = 0;
    std::string line;
    std::regex pattern("(\\d+)-(\\d+),(\\d+)-(\\d+)");
    std::smatch match;
    std::ifstream input_file("4.input");
    Range range1;
    Range range2;
    
    if (input_file.is_open()){
        while(getline(input_file, line)){
            if (std::regex_match(line, match, pattern)) {
                range1.start = std::stoi(match[1].str());
                range1.end = std::stoi(match[2].str());
                range2.start = std::stoi(match[3].str());
                range2.end = std::stoi(match[4].str());
                //if (range1.isContained(range2) || range2.isContained(range1)){
                if (range1.isOverlapping(range2)){
                    result++;
                }
            }
        }
        std::cout << "Total of points you will collect : " << result << std::endl;
    }
    
}