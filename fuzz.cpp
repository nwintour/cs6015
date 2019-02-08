//
//  fuzz.cpp
//  fuzz
//
//  Created by Natalie Wintour on 2/5/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ostream>

using namespace std;

vector<string> splitString(string s) {
    vector<string> result;
    istringstream iss(s);
    for(string s; iss >> s; ) {
        result.push_back(s);
    }
    return result;
}

string makeSquare() {
    int random = rand() % 100;
    string ret = to_string(random) + ' ' + to_string(0) + ' ' + to_string(random) + ' ' + to_string(random) + ' ' + to_string(0) + ' ' + to_string(random);
    return ret;
}

string makeRectangle() {
    int random = rand() % 100;
    int secondRandom = rand() % 100;
    string ret = to_string(random) + ' ' + to_string(0) + ' ' + to_string(random) + ' ' + to_string(secondRandom) + ' ' + to_string(0) + ' ' + to_string(secondRandom);
    return ret;
}

string makeRhombus() {
    string random = makeSquare();
    vector<string> split = splitString(random);
    int tran = stoi(split.at(2)) + 1;
    int tran2 = stoi(split.at(5)) + 1;
    split.at(2) = to_string(tran);
    split.at(5) = to_string(tran2);
    string ret = split.at(0) + ' ' + split.at(1) + ' ' + split.at(2) + ' ' + split.at(3) + ' ' + split.at(4) + ' ' + split.at(5);
    return ret;
}

string makePara() {
    string random = makeRectangle();
    vector<string> split = splitString(random);
    int tran = stoi(split.at(2)) + 1;
    int tran2 = stoi(split.at(5)) + 1;
    split.at(2) = to_string(tran);
    split.at(5) = to_string(tran2);
    string ret = split.at(0) + ' ' + split.at(1) + ' ' + split.at(2) + ' ' + split.at(3) + ' ' + split.at(4) + ' ' + split.at(5);
    return ret;
}

string makeTrap() {
    string random = makeRectangle();
    vector<string> split = splitString(random);
    int tran = stoi(split.at(2)) + 1;
    int tran2 = stoi(split.at(5)) + 5;
    split.at(2) = to_string(tran);
    split.at(5) = to_string(tran2);
    string ret = split.at(0) + ' ' + split.at(1) + ' ' + split.at(2) + ' ' + split.at(3) + ' ' + split.at(4) + ' ' + split.at(5);
    return ret;
}

string makeKite() {
    string random = makeSquare();
    vector<string> split = splitString(random);
    int tran = stoi(split.at(2)) + 1;
    int tran2 = stoi(split.at(3)) + 1;
    split.at(2) = to_string(tran);
    split.at(3) = to_string(tran2);
    string ret = split.at(0) + ' ' + split.at(1) + ' ' + split.at(2) + ' ' + split.at(3) + ' ' + split.at(4) + ' ' + split.at(5);
    return ret;
}

int main(int argc, const char * argv[]) {
   // freopen("small_input.txt","w",stdout);
    string square = makeSquare();
    string rectangle = makeRectangle();
    string rhombus = makeRhombus();
    string para = makePara();
    string trap = makeTrap();
    string kite = makeKite();
    cout << square << endl << rectangle << endl << rhombus << endl << para << endl << trap << endl << kite << endl;
}