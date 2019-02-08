//
//  errorThree.cpp
//  three
//
//  Created by Natalie Wintour on 2/7/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#include <iostream>
#include <string>

std::string errorThreeOne() { // letters
    int number = 50;
    int number2 = 50;
    int number3 = 10;
    int number4 = 10;
    int number5 = 24;
    int number6 = 24;
    std::string ret = std::to_string(number) + ' ' + std::to_string(number2) + ' ' + std::to_string(number3) + ' ' + std::to_string(number4) + ' ' + std::to_string(number5) + ' ' + std::to_string(number6);
    return ret;
}

std::string errorThreeTwo() { // letters
    int number = 50;
    int number2 = 50;
    int number3 = 25;
    int number4 = 75;
    int number5 = 10;
    int number6 = 0;
    std::string ret = std::to_string(number) + ' ' + std::to_string(number2) + ' ' + std::to_string(number3) + ' ' + std::to_string(number4) + ' ' + std::to_string(number5) + ' ' + std::to_string(number6);
    return ret;
}

int main(int argc, const char * argv[]) {
    // freopen("small_input.txt","w",stdout);
    srand(time(0));
    int decision = rand() % 10 + 1;
    if(decision >= 5) {
        std::string one = errorThreeOne();
        std::cout << one;
    } else {
        std::string two = errorThreeTwo();
        std::cout << two;
    }
}