//
//  TestCases.m
//  TestCases
//
//  Created by Natalie Wintour on 1/29/19.
//  Copyright © 2019 Natalie Wintour. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface TestCases : XCTestCase

@end

@implementation TestCases

- (void)setUp {
    super.setUp()
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    super.tearDown()
}

- (void)XCAssert {
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
    
    vector<vector<string>> test() {
        ifstream in1("randomSquares.txt");
        ifstream in2("randomRhombi.txt");
        ifstream in3("randomKites.txt");
        ifstream in4("randomQuadrilaterals.txt");
        ifstream in5("randomTrapezoids.txt");
        ifstream in6("randomParallelograms.txt");
        
        vector<string> inFile1 = readFile(in1);
        vector<string> inFile2 = readFile(in2);
        vector<string> inFile3 = readFile(in3);
        vector<string> inFile4 = readFile(in4);
        vector<string> inFile5 = readFile(in5);
        vector<string> inFile6 = readFile(in6);
        
        vector<vector<string>> files = {inFile1, inFile2, inFile3, inFile4, inFile5, inFile6};
        return files;
    }
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
