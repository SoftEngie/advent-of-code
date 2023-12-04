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

int main(int argc, char** argv){
    //declare variables here
    int result = 0, result2 = 0;
    std::string line;
    std::ifstream input_file("template.input");
    if (input_file.is_open()){
        while(getline(input_file, line)){
            // add your code for each line here
        }

        // add your code when finished to read input or after input computation

        //print the result
        std::cout << "Result is : " << result << std::endl;
        std::cout << "Result for part 2 is : " << result << std::endl;
    }

}