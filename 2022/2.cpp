#include<string>
#include<vector>
#include<map>
#include<fstream>
#include <iostream>
#include <functional>

enum class RPSChoice {Rock, Paper, Scissor};

int match(const RPSChoice& elve_choice, const RPSChoice& your_choice){
    if (your_choice == elve_choice){
        return 3;
    }
    if ( (your_choice == RPSChoice::Rock && elve_choice == RPSChoice::Scissor) ||(your_choice == RPSChoice::Paper && elve_choice == RPSChoice::Rock) ||(your_choice == RPSChoice::Scissor && elve_choice == RPSChoice::Paper) ){
        return 6;
    }
    return 0;
}

RPSChoice getWinningHand(const RPSChoice& choice){
    if(choice == RPSChoice::Rock){
        return RPSChoice::Paper;
    } else if (choice == RPSChoice::Paper){
        return RPSChoice::Scissor;
    } else if (choice == RPSChoice::Scissor) {
        return RPSChoice::Rock;
    }
    return RPSChoice::Rock;
}

RPSChoice getLoosingHand(const RPSChoice& choice){
    if(choice == RPSChoice::Rock){
        return RPSChoice::Scissor;
    } else if (choice == RPSChoice::Paper){
        return RPSChoice::Rock;
    } else if (choice == RPSChoice::Scissor) {
        return RPSChoice::Paper;
    }
    return RPSChoice::Rock;
}

RPSChoice getEqualHand(const RPSChoice& choice){
    if(choice == RPSChoice::Rock){
        return RPSChoice::Rock;
    } else if (choice == RPSChoice::Paper){
        return RPSChoice::Paper;
    } else if (choice == RPSChoice::Scissor) {
        return RPSChoice::Scissor;
    }
    return RPSChoice::Rock;
}



int main(int argc, char** argv){
    std::map<RPSChoice, int> point{{RPSChoice::Rock, 1}, {RPSChoice::Paper, 2}, {RPSChoice::Scissor, 3}};
    std::map<std::string, RPSChoice> elveToRPS{{"A", RPSChoice::Rock}, {"B", RPSChoice::Paper}, {"C", RPSChoice::Scissor}}; 
    // std::map<std::string, RPSChoice> youToRPS{{"X", RPSChoice::Rock}, {"Y", RPSChoice::Paper}, {"Z", RPSChoice::Scissor}}; 
    std::map<std::string, std::function<RPSChoice(RPSChoice)>> youToRPS{{"X", getLoosingHand}, {"Y", getEqualHand}, {"Z", getWinningHand}}; 
    int points = 0;
    RPSChoice elve_choice;
    RPSChoice your_choice;
    std::string line;
    std::ifstream input_file("2.input");
    if (input_file.is_open()){
        while(getline(input_file, line)){
            points += match(elveToRPS[line.substr(0, 1)] , youToRPS[line.substr(2,1)](elveToRPS[line.substr(0, 1)]));
            points += point[youToRPS[line.substr(2,1)](elveToRPS[line.substr(0, 1)])];
        }
        std::cout << "Total of points you will collect : " << points << std::endl;
    }
    
}