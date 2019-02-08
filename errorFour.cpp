//
//  errorFour.cpp
//  four
//
//  Created by Natalie Wintour on 2/7/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#include <iostream>
#include <string>

std::string errorFourOne() { // letters
    int number = 1;
    int number2 = 1;
    int number3 = 2;
    int number4 = 2;
    int number5 = 0;
    int number6 = 1;
    std::string ret = std::to_string(number) + ' ' + std::to_string(number2) + ' ' + std::to_string(number3) + ' ' + std::to_string(number4) + ' ' + std::to_string(number5) + ' ' + std::to_string(number6);
    return ret;
}

std::string errorFourTwo() { // letters
    int number = 99;
    int number2 = 1;
    int number3 = 98;
    int number4 = 2;
    int number5 = 97;
    int number6 = 3;
    std::string ret = std::to_string(number) + ' ' + std::to_string(number2) + ' ' + std::to_string(number3) + ' ' + std::to_string(number4) + ' ' + std::to_string(number5) + ' ' + std::to_string(number6);
    return ret;
}

int main(int argc, const char * argv[]) {
    // freopen("small_input.txt","w",stdout);
    srand(time(0));
    int decision = rand() % 10 + 1;
    if(decision >= 5) {
        std::string one = errorFourOne();
        std::cout << one;
    } else {
        std::string two = errorFourTwo();
        std::cout << two;
    }
}