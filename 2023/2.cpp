// General useful import
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>


// Devlare here global constant and additional function
int main(int argc, char** argv) {
    int max_red = 12, max_green = 13, max_blue = 14;
        
    //declare variables here
    int result = 0, result2 = 0 , game_id = 1, quantity = 0;
    std::regex game_outline("(\\d+)\\s*(red|green|blue)|(\\;)");
    std::string line, color;
    std::sregex_iterator end;
    std::smatch match;
    std::ifstream input_file("2.input");
    if (input_file.is_open()){
        std::string game_turn;
        while(getline(input_file, line)){
            int max_red_seen = 0, max_green_seen = 0, max_blue_seen = 0;
            std::sregex_iterator it(line.begin(), line.end(), game_outline);
            int red = 0, green = 0, blue = 0;
            while(it != end){
                
                match = *it;
                if(match[0].str() == ";"){
                    if (red > max_red_seen){
                        max_red_seen = red;
                    }   
                    if (blue > max_blue_seen){
                        max_blue_seen = blue;
                    }   
                    if (green > max_green_seen) {
                        max_green_seen = green;
                    }
                    red = 0;
                    green = 0;
                    blue = 0;
                }
                else{ 
                    quantity = std::stoi(match[1].str());
                    color = match[2].str();
                    if (color == "red") {
                        red += quantity;
                    } else if(color == "green") {
                        green += quantity;
                    } else if (color == "blue") {
                        blue += quantity;
                    }
                }
                ++it;
            }
            if (red > max_red_seen){
                max_red_seen = red;
            }   
            if (blue > max_blue_seen){
                max_blue_seen = blue;
            }   
            if (green > max_green_seen) {
                max_green_seen = green;
            }
                    

            if (!(max_red_seen > max_red | max_green_seen > max_green | max_blue_seen > max_blue)){
                result += game_id;
            }
            result2 += max_red_seen*max_green_seen*max_blue_seen;
            game_id++; 
        }

        // add your code when finished to read input or after input computation

        //print the result
        std::cout << "Result is : " << result << std::endl;
        std::cout << "Result 2 is : " << result2 << std::endl;
    }
}