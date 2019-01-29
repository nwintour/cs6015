//
//  TestCases.cpp
//  assignment3
//
//  Created by Natalie Wintour on 1/29/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#include "TestCases.hpp"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> readFile(ifstream& in) {
    vector<string> fileLines;
    string line;
    while(in >> line){
        // cout << line;
        fileLines.push_back(line);
        getline(in, line);
        // cout << line;
        fileLines.push_back(line);
        // cout << line;
    }
    // auto it = fileLines.insert(fileLines.begin(), 2, "0");
    return fileLines;
}


// ifstream in("randomRhombi.txt");
// ifstream in("randomKites.txt");
// ifstream in("randomQuadrilaterals.txt");
// ifstream in("randomTrapezoids.txt");
//     ifstream in("randomParallelograms.txt");

void testSquare() {
    ifstream in("randomSquares.txt");
    vector<string> inFile = readFile(in);
    printShapes(inFile);
}
