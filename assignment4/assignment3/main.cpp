//
//  main.cpp
//  assignment3
//
//  Created by Natalie Wintour on 1/17/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>

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

vector<string> splitVector(vector<string> in) {
    vector<string> result;
    for(string s: in) {
        istringstream iss(s);
        for(string s; iss >> s; ) {
            result.push_back(s);
            // cout << s << endl;
        }
    }
    return result;
}

// helper method to print for testing in console
void printVector(vector<string> input) {
    for (auto i = input.begin(); i != input.end(); ++i) {
        cout << *i << ' ';
    }
}

//////////////////////////////////////////////////////////////////////

// function to find the slope of a straight line

vector<double> stringToDouble(vector<string> s) {
    vector<double> points;

        double x1, y1, x2, y2, x3, y3, x4, y4;
        x1 = 0.0;
        y1 = 0.0;
        x2 = atof(s.at(0).c_str());
        y2 = atof(s.at(1).c_str());
        x3 = atof(s.at(2).c_str());
        y3 = atof(s.at(3).c_str());
        x4 = atof(s.at(4).c_str());
        y4 = atof(s.at(5).c_str());
        
        points.push_back(x1);
        points.push_back(y1);
        points.push_back(x2);
        points.push_back(y2);
        points.push_back(x3);
        points.push_back(y3);
        points.push_back(x4);
        points.push_back(y4);
        
     // cout << "points : " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    
    return points;
}

float slope(float x1, float y1, float x2, float y2) {
    return (y2 - y1) / (x2 - x1);
}

vector<double> calculateSlopes(vector<string> s) {
    vector<double> slopes;

        vector<double> points = stringToDouble(s);
        double x1, y1, x2, y2, x3, y3, x4, y4;
        
        x1 = points.at(0);
        y1 = points.at(1);
        x2 = points.at(2);
        y2 = points.at(3);
        x3 = points.at(4);
        y3 = points.at(5);
        x4 = points.at(6);
        y4 = points.at(7);
    
        double slope1 = slope(x1, y1, x2, y2);
        double slope2 = slope(x2, y2, x3, y3);
        double slope3 = slope(x3, y3, x4, y4);
        double slope4 = slope(x4, y4, x1, y1);
        
        slopes.push_back(slope1);
        slopes.push_back(slope2);
        slopes.push_back(slope3);
        slopes.push_back(slope4);

    return slopes;
}

// https://www.geeksforgeeks.org/program-calculate-distance-two-points/

float calculateDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


vector<double> calculateSideLength(vector<string> s) {
    vector<double> sides;

        vector<double> points = stringToDouble(s);
        double x1, y1, x2, y2, x3, y3, x4, y4;
        double side1, side2, side3, side4;
    
        x1 = points.at(0);
        y1 = points.at(1);
        x2 = points.at(2);
        y2 = points.at(3);
        x3 = points.at(4);
        y3 = points.at(5);
        x4 = points.at(6);
        y4 = points.at(7);
    
        side1 = calculateDistance(x1, y1, x2, y2);
        side2 = calculateDistance(x2, y2, x3, y3);
        side3 = calculateDistance(x3, y3, x4, y4);
        side4 = calculateDistance(x4, y4, x1, y1);
      // cout << "sides : " << side1 << " " << side2 << " " << side3 << " " << side4 << endl;
   
        sides.push_back(side1);
        sides.push_back(side2);
        sides.push_back(side3);
        sides.push_back(side4);
    
    return sides;
}

///////////////////////////////////////////////////////////////////////////// boolean for shapes

bool isSquare(vector<double>& sides, vector<double>& points) {
    double firstSide = sides.at(0);
    for(double s: sides) {
        if(s != firstSide) {
            return false;
        }
    }
    if(points.at(1) != points.at(3) || points.at(2) != points.at(4) || points.at(5) != points.at(7)) {
        return false;
    }
    return true;
}

bool isRectangle(vector<double>& sides, vector<double>& points) {
    if(isSquare(sides, points) == true) {
        return false;
    }
    if(points.at(1) != points.at(3) || points.at(2) != points.at(4) || points.at(5) != points.at(7)) {
        return false;
    }
    if(sides.at(0) == sides.at(2) && sides.at(1) == sides.at(3)) {
        return true;
    }
    return false;
}

bool isRhombi(vector<string> s, vector<double>& sides, vector<double>& points) {
    if(isSquare(sides, points) == true) {
        return false;
    }
    double sideLength = sides.at(0);
    for(double si: sides) {
        if(si != sideLength) {
            return false;
        }
    }
    vector<double> slopes = calculateSlopes(s);
    if(slopes.at(0) == slopes.at(2) && slopes.at(1) == slopes.at(3)) {
        return true;
    }
    return false;
}

bool isKite(vector<double>& sides, vector<double>& points) {
    if(isSquare(sides, points) == true) {
        return false;
    } else if(sides.at(0) != sides.at(1) && sides.at(0) != sides.at(3)) {
        return false;
    } else if(sides.at(0) == sides.at(1) && sides.at(2) == sides.at(3) && sides.at(1) != sides.at(2)) {
        return true;
    } else if(sides.at(0) == sides.at(3) && sides.at(1) == sides.at(2) && sides.at(3) != sides.at(2)) {
     return true;
    }
    return false;
}

bool isPara(vector<string>& s, vector<double>& sides, vector<double>& points) {
    if(isRectangle(sides, points) == true || isSquare(sides, points) == true || isRhombi(s, sides, points) == true) {
        return false;
    }
    vector<double> slopes = calculateSlopes(s);
    if(slopes.at(0) == slopes.at(2) && slopes.at(1) == slopes.at(3)) {
        if(sides.at(0) == sides.at(2) && sides.at(1) == sides.at(3)) {
            return true;
        }
    }
    return false;
}

bool isTrap(vector<string>& s) {
    vector<double> slopes = calculateSlopes(s);
    if(slopes.at(0) == slopes.at(2) && slopes.at(1) != slopes.at(3)) {
        return true;
    } else if (slopes.at(0) != slopes.at(2) && slopes.at(1) == slopes.at(3)) {
        return true;
    }
    return false;
}
                          

//bool isQuad(vector<double>& angles) {
//    return true;
//}

///////////////////////////////////////////////////////////////////// print function

void printShapes(vector<string> s) {
    
    vector<string> splitBySpace = splitVector(s);
    
    vector<string> shape;
    
    for(int i = 0; i < splitBySpace.size() ; i+= 6) {
        
        if(i > splitBySpace.size()) {
            return;
        }
        
        // cout << i << endl;
        
        shape = {splitBySpace.at(i), splitBySpace.at(i+1), splitBySpace.at(i+2), splitBySpace.at(i+3), splitBySpace.at(i+4), splitBySpace.at(i+5)};
        
        // printVector(shape);
        
        vector<double> points = stringToDouble(shape);
    
        vector<double> sides = calculateSideLength(shape);
    
        vector<double> slopes = calculateSlopes(shape);
        
        if (isSquare(sides, points) == true) {
            cout << "square" << endl;
        } else if(isRectangle(sides, points) == true) {
            cout << "rectangle" << endl;
        } else if(isRhombi(shape, sides, points) == true) {
            cout << "rhombi" << endl;
        } else if(isPara(shape, sides, points) == true) {
            cout << "parallelogram" << endl;
        } else if(isKite(sides, points) == true) {
            cout << "kite" << endl;
        } else if(isTrap(shape) == true) {
            cout << "trapezoid" << endl;
        } else {
            cout << "quadrilateral" << endl;
        }
        
        shape.clear();

    }

    
}


////////////////////////////////////////////////////////////////////// main

int main(int argc, const char * argv[]) {
    
//    while(!cin.eof()) {
//         ifstream in("testfile.txt");
//    }
    
     ifstream in("randomSquares.txt");
    // ifstream in("randomRhombi.txt");
    // ifstream in("randomKites.txt");
    // ifstream in("randomQuadrilaterals.txt");
    // ifstream in("randomTrapezoids.txt");
//     ifstream in("randomParallelograms.txt");
//
    vector<string> inFile = readFile(in);
//
//    vector<string> inFile;
//        string line;
//    while(cin >> line) {
//        inFile.push_back(line);
//        getline(cin, line);
//        inFile.push_back(line);
//    }

    printShapes(inFile);
    
}
