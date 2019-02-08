//
//  errorOne.cpp
//  one
//
//  Created by Natalie Wintour on 2/7/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string errorOneOne() { // letters
    srand(time(0));
    int random = rand() % 100;
    int random2 = rand() % 100;
    int random3 = rand() % 100;
    int random4 = rand() % 100;
    int random5 = rand() % 100;
    char random6 = 'a' + rand() % 26;
    std::string ret = std::to_string(random) + ' ' + std::to_string(random2) + ' ' + std::to_string(random3) + ' ' + std::to_string(random4) + ' ' + std::to_string(random5) + ' ' + std::to_string(random6);
    return ret;
}

std::string errorOneTwo() { // empty string
    std::string ret = "";
    return ret;
}

std::string errorOneThree() { // invalid spaces in front
    srand(time(0));
    int random = rand() % 100;
    int random2 = rand() % 100;
    int random3 = rand() % 100;
    int random4 = rand() % 100;
    int random5 = rand() % 100;
    int random6 = rand() % 100;
    std::string ret = "      " + std::to_string(random) + std::to_string(random2) + std::to_string(random3) + std::to_string(random4) + std::to_string(random5) + std::to_string(random6);
    return ret;
}

std::string errorOneFour() { // out of range
    srand(time(0));
    int random = rand() % 1000;
    int random2 = rand() % 1000;
    int random3 = rand() % 1000;
    int random4 = rand() % 1000;
    int random5 = rand() % 1000;
    int random6 = rand() % 1000;
    std::string ret = std::to_string(random) + ' ' + std::to_string(random2) + ' ' + std::to_string(random3) + ' ' + std::to_string(random4) + ' ' + std::to_string(random5) + ' ' + std::to_string(random6);
    return ret;
}

int main(int argc, const char * argv[]) {
    // freopen("small_input.txt","w",stdout);
    srand(time(0));
    int decision = rand() % 10 + 1;
    if(decision <= 3) {
        std::string test = errorOneOne();
        std::cout << test;
    } else if(decision > 3 && decision <= 6) {
        std::string test = errorOneTwo();
        std::cout << test;
    } else if(decision > 6 && decision <= 8) {
        std::string test = errorOneThree();
        std::cout << test;
    } else {
        std::string test = errorOneFour();
        std::cout << test; 
    } 
}
