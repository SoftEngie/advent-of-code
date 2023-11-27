#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct TopThree
{
    int top1 = 0;
    int top2 = 0;
    int top3 = 0;

    void insert(int newValue){
        if (newValue > top1) {
            top3 = top2;
            top2 = top1;
            top1 = newValue;
        }
        else if (newValue > top2) {
            top3 = top2;
            top2 = newValue;
        }
        else if (newValue > top3) {
            top3 = newValue;
        }
    }

    int getTotal(){
        return top1 + top2 + top3;
    }
};

int main(int argc, char** argv){
    //int max_calories = 0;
    TopThree top;
    std::string line;
    std::ifstream input_file("1.input");
    int calories = 0;
    if (input_file.is_open()){
        while(getline(input_file, line)){
            if(!line.empty()){
                calories += std::stol(line);
            }
            else {
                top.insert(calories);
                calories = 0;
            }
        }
        std::cout << "Total of top three elves with max calories is : " << top.getTotal() << std::endl;
       //std::cout << "Elf with max calories is : " << elf_with_max_calories << " with "<< max_calories << " calories !" << std::endl;
    }
    
}