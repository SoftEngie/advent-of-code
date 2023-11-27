#include<string>
#include<vector>
#include<map>
#include<fstream>
#include <iostream>
#include <functional>
#include <set>

int charToNumber(char c){
    if (c >= 'a' && c <= 'z'){
        return c - 'a' + 1;
    }
    else if (c >= 'A' && c <= 'Z'){
        return c - 'A' + 27;
    }
    return 0;
}

// int main(int argc, char** argv){
//     int result = 0;
//     std::string line;
//     std::ifstream input_file("3.input");
//     if (input_file.is_open()){
//         std::string first_compartment{};
//         std::string second_compartment{};
//         while(getline(input_file, line)){
//             std::set<char> rucksack_items_1{};
//             std::set<char> rucksack_items_2{};
//             size_t half = line.length() / 2;
//             first_compartment = line.substr(0, half);
//             second_compartment = line.substr(half);
//             for(size_t i=0; i<half; i++){
//                 auto it = rucksack_items_2.find(first_compartment[i]);
//                 if( it == rucksack_items_2.end()){
//                     rucksack_items_1.insert(first_compartment[i]);
//                 } else {
//                     result += charToNumber(first_compartment[i]);
//                     break;
//                 }
//                 it = rucksack_items_1.find(second_compartment[i]);
//                 if( it == rucksack_items_1.end()){
//                     rucksack_items_2.insert(second_compartment[i]);
//                 } else {
//                     result += charToNumber(second_compartment[i]);
//                     break;
//                 }
//             }
//         }
//         std::cout << "Total of points you will collect : " << result << std::endl;
//     }
    
// }

int main(int argc, char** argv){
    int result = 0;
    std::string line1;
    std::string line2;
    std::string line3;
    std::ifstream input_file("3.input");
    if (input_file.is_open()){
        while(getline(input_file, line1) && getline(input_file, line2) && getline(input_file, line3)){
            std::set<char> rucksack_items_1{line1.begin(), line1.end()};
            std::set<char> rucksack_items_2{line2.begin(), line2.end()};
            std::set<char> rucksack_items_3{line3.begin(), line3.end()};

            for (auto const& item: rucksack_items_1) {
                if (rucksack_items_2.count(item) && rucksack_items_3.count(item)) {
                    result += charToNumber(item);
                    break;
                }
            }
        }
        std::cout << "Total of points you will collect : " << result << std::endl;
    }
    
}