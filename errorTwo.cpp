//
//  errorTwo.cpp
//  two
//
//  Created by Natalie Wintour on 2/7/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#include <iostream>
#include <string>

std::string errorTwo() { // letters
    srand(time(0));
    int random = rand() % 100;
    int random2 = rand() % 100;
    int random3 = rand() % 100;
    int random4 = rand() % 100;
    std::string ret = std::to_string(random) + ' ' + std::to_string(random2) + ' ' + std::to_string(random3) + ' ' + std::to_string(random4) + ' ' + std::to_string(random) + ' ' + std::to_string(random2);
    return ret;
}

int main(int argc, const char * argv[]) {
    std::string test = errorTwo();
    std::cout << test;
}
