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

struct Shape {
    string error;
    vector<double> points;
    vector<double> sides;
    vector<double> slopes;
};

vector<string> splitString(string s) {
    vector<string> result;
    istringstream iss(s);
    for(string s; iss >> s; ) {
        result.push_back(s);
        // cout << s << endl;
    }
    return result;
}

bool numberPoints(string line) {
    vector<string> result = splitString(line);
    if(result.size() != 6) {
        return false;
    } else {
        return true;
    }
}

bool containsLetterOrSymbol(string line) {
    for(char c: line) {
        if(ispunct(c) || isalpha(c)) {
            return true;
        }
    }
    return false;
}

bool outOfRange(vector<string> points) {
    for(string s: points) {
        int i = stoi(s);
        if(i > 100 || i < 0) {
            return true;
        }
    }
    return false;
}

void validateError2(Shape s) { // check for duplicate points
    double array[10];
    ::copy(s.points.begin(), s.points.end(), array);
    if(s.points.at(0) == s.points.at(3) || s.points.at(0) == s.points.at(6) || s.points.at(0) == s.points.at(9)) {
        if(s.points.at(0) == s.points.at(3) && s.points.at(1) == s.points.at(4)) {
            s.error = "error 2";
        } else if(s.points.at(0) == s.points.at(6) && s.points.at(1) == s.points.at(7)) {
            s.error = "error 2";
        } else if(s.points.at(0) == s.points.at(9) && s.points.at(1) == s.points.at(10)) {
            s.error = "error 2";
        }
    } // checked 0,0
    
    if(s.points.at(3) == s.points.at(6) && s.points.at(4) == s.points.at(7)) {
        s.error = "error 2";
    } else if(s.points.at(3) == s.points.at(9) && s.points.at(4) == s.points.at(10)) {
        s.error = "error 2";
    } // check the other three aren't the same
}


// helper method to validate numbers of points
string validateError1(string& line) {
    if(line.size() == 0) { // check for blank line or line size
        return line = "Error 1: Input size.";
    } else if(!(numberPoints(line))) {
        return line = "error 1: spaces";
    } else if(containsLetterOrSymbol(line)) {
        return line = "error 1: letter";
    }
    
    vector<string> testingPoints = splitString(line);
    
    if(outOfRange(testingPoints)) {
        return line = "error 1: out of range";
    }
    
    return line;
}

vector<string> splitVector(vector<string> in) {
    vector<string> result;
    for(string s: in) {
        if(isalpha(s[0])) {
            result.push_back(s);
           // cout << s << endl;
        } else {
            istringstream iss(s);
            for(string s; iss >> s; ) {
                result.push_back(s);
               // cout << s << endl;
            }
        }
    }
    return result;
}

vector<string> readFile(ifstream& in) {
    vector<string> fileLines;
    string line;
    while(!in.eof()){
        getline(in, line);
        validateError1(line);
        //cout << line << endl;
        fileLines.push_back(line);
    }
    // vector<string> splitPoints = splitVector(fileLines);
    return fileLines;
}

// helper method to print for testing in console
void printVector(vector<string> input) {
    for (auto i = input.begin(); i != input.end(); ++i) {
        cout << *i << endl;
    }
}

//////////////////////////////////////////////////////////////////////

// function to find the slope of a straight line

void stringToDouble(Shape &s, vector<string> positions) {
    vector<double> points;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = 0.0;
    y1 = 0.0;
    x2 = atof(positions.at(0).c_str());
    y2 = atof(positions.at(1).c_str());
    x3 = atof(positions.at(2).c_str());
    y3 = atof(positions.at(3).c_str());
    x4 = atof(positions.at(4).c_str());
    y4 = atof(positions.at(5).c_str());
    
    s.points.push_back(x1);
    s.points.push_back(y1);
    s.points.push_back(x2);
    s.points.push_back(y2);
    s.points.push_back(x3);
    s.points.push_back(y3);
    s.points.push_back(x4);
    s.points.push_back(y4);

}

float slope(float x1, float y1, float x2, float y2) {
    return (y2 - y1) / (x2 - x1);
}

bool colinear(Shape s) {
    if(s.slopes.at(0) == s.slopes.at(1)) {
        return true;
    } else if(s.slopes.at(1) == s.slopes.at(2)) {
        return true;
    } else if(s.slopes.at(2) == s.slopes.at(3)){
        return true;
    }
    return false;
}

void calculateSlopes(Shape &s) {
    
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    x1 = s.points.at(0);
    y1 = s.points.at(1);
    x2 = s.points.at(2);
    y2 = s.points.at(3);
    x3 = s.points.at(4);
    y3 = s.points.at(5);
    x4 = s.points.at(6);
    y4 = s.points.at(7);
    
    double slope1 = slope(x1, y1, x2, y2);
    double slope2 = slope(x2, y2, x3, y3);
    double slope3 = slope(x3, y3, x4, y4);
    double slope4 = slope(x4, y4, x1, y1);
    
    s.slopes.push_back(slope1);
    s.slopes.push_back(slope2);
    s.slopes.push_back(slope3);
    s.slopes.push_back(slope4);
}

// https://www.geeksforgeeks.org/program-calculate-distance-two-points/

float calculateDistance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


void calculateSideLength(Shape &s) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double side1, side2, side3, side4;
    
    x1 = s.points.at(0);
    y1 = s.points.at(1);
    x2 = s.points.at(2);
    y2 = s.points.at(3);
    x3 = s.points.at(4);
    y3 = s.points.at(5);
    x4 = s.points.at(6);
    y4 = s.points.at(7);
    
    side1 = calculateDistance(x1, y1, x2, y2);
    side2 = calculateDistance(x2, y2, x3, y3);
    side3 = calculateDistance(x3, y3, x4, y4);
    side4 = calculateDistance(x4, y4, x1, y1);
    // cout << "sides : " << side1 << " " << side2 << " " << side3 << " " << side4 << endl;
    
    s.sides.push_back(side1);
    s.sides.push_back(side2);
    s.sides.push_back(side3);
    s.sides.push_back(side4);
}

///////////////////////////////////////////////////////////////////////////// boolean for shapes

bool isSquare(const Shape &s) {
    double firstSide = s.sides.at(0);
    for(double s: s.sides) {
        if(s != firstSide) {
            return false;
        }
    }
    if(s.points.at(1) != s.points.at(3) || s.points.at(2) != s.points.at(4) || s.points.at(5) != s.points.at(7)) {
        return false;
    }
    return true;
}

bool isRectangle(const Shape &s) {
    if(isSquare(s) == true) {
        return false;
    }
    if(s.points.at(1) != s.points.at(3) || s.points.at(2) != s.points.at(4) || s.points.at(5) != s.points.at(7)) {
        return false;
    }
    if(s.sides.at(0) == s.sides.at(2) && s.sides.at(1) == s.sides.at(3)) {
        return true;
    }
    return false;
}

bool isRhombi(const Shape &s) {
    if(isSquare(s) == true) {
        return false;
    }
    double sideLength = s.sides.at(0);
    for(double si: s.sides) {
        if(si != sideLength) {
            return false;
        }
    }
    if(s.slopes.at(0) == s.slopes.at(2) && s.slopes.at(1) == s.slopes.at(3)) {
        return true;
    }
    return false;
}

bool isKite(const Shape &s) {
    if(isSquare(s) == true) {
        return false;
    } else if(s.sides.at(0) != s.sides.at(1) && s.sides.at(0) != s.sides.at(3)) {
        return false;
    } else if(s.sides.at(0) == s.sides.at(1) && s.sides.at(2) == s.sides.at(3) && s.sides.at(1) != s.sides.at(2)) {
        return true;
    } else if(s.sides.at(0) == s.sides.at(3) && s.sides.at(1) == s.sides.at(2) && s.sides.at(3) != s.sides.at(2)) {
        return true;
    }
    return false;
}

bool isPara(const Shape &s) {
    if(isRectangle(s) == true || isSquare(s) == true || isRhombi(s) == true) {
        return false;
    }
    if(s.slopes.at(0) == s.slopes.at(2) && s.slopes.at(1) == s.slopes.at(3)) {
        if(s.sides.at(0) == s.sides.at(2) && s.sides.at(1) == s.sides.at(3)) {
            return true;
        }
    }
    return false;
}

bool isTrap(const Shape &s) {
    if(s.slopes.at(0) == s.slopes.at(2) && s.slopes.at(1) != s.slopes.at(3)) {
        return true;
    } else if (s.slopes.at(0) != s.slopes.at(2) && s.slopes.at(1) == s.slopes.at(3)) {
        return true;
    }
    return false;
}

vector<Shape> makeShapeVector(vector<string> splitBySpace) {
    vector<Shape> allShapes;
    int marker = 0;
    for(int i = 0; i < splitBySpace.size(); i+= 6) {
        Shape _shape;
        if(isalpha(splitBySpace.at(i)[0])) {
            _shape.error = splitBySpace.at(i);
            i -= 5;
            allShapes.push_back(_shape);
        } else {
            vector<string> holdPoints;
            for(int j = 0; j < 6; ++j) {
                marker = i + j;
                holdPoints.push_back(splitBySpace.at(marker));
            }
            stringToDouble(_shape, holdPoints); // points
            //         cout << "shape points at 0: " << _shape.points.at(4) << endl;
            calculateSideLength(_shape); // sides
            //         cout << "shape points at 0: " << _shape.sides.at(3) << endl;
            calculateSlopes(_shape); // slopes
            //         cout << "shape points at 0: " << _shape.slopes.at(2) << endl;
            if(colinear(_shape)) {
                _shape.error = "error 3";
            }
            allShapes.push_back(_shape);
        }
    }
    return allShapes;
}

void printShapes(vector<Shape> &all) {
    
    for(Shape s: all) {
        if(s.error != "") {
            cout << s.error << endl;
           // EXIT_FAILURE;
        } else {
            if (isSquare(s) == true) {
                cout << "square" << endl;
            } else if(isRectangle(s) == true) {
                cout << "rectangle" << endl;
            } else if(isRhombi(s) == true) {
                cout << "rhombi" << endl;
            } else if(isPara(s) == true) {
                cout << "parallelogram" << endl;
            } else if(isKite(s) == true) {
                cout << "kite" << endl;
            } else if(isTrap(s) == true) {
                cout << "trapezoid" << endl;
            } else {
                cout << "quadrilateral" << endl;
            }
        }
    }
}


////////////////////////////////////////////////////////////////////// main

int main(int argc, const char * argv[]) {
    

    // this is tested
    ifstream in (argv[1]);
    ofstream out(argv[2]);
    cout.rdbuf(out.rdbuf());

  //  ifstream in ("testBasic.txt");
  //  ifstream in ("testgen.txt");

//      ifstream in ("randomSquares.txt");
  // ifstream in("randomRhombi.txt");
 //  ifstream in("randomKites.txt");
  // ifstream in("randomQuadrilaterals.txt");
//    ifstream in("randomTrapezoids.txt");
//    ifstream in("randomParallelograms.txt");

//    string test = "16 33 49 49 33 16";
//    cout <<  numberPoints(test) << endl;
//    vector<string> test2 = splitString(test);
//    for(string c: test2) {
//        cout << c << endl;
//    }
//    cout << outOfRange(test2);
    
    vector<string> inFile = readFile(in);
    vector<string> splitBySpace = splitVector(inFile);
   // cout << "size before split: " << inFile.size() << endl;
  //  printVector(splitBySpace);
  //  cout << "size after split: " << splitBySpace.size() << endl;
    vector<Shape> allShapes = makeShapeVector(splitBySpace);
    printShapes(allShapes);
//    out.close();
}
