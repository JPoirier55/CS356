//
// Created by Jake on 9/9/2016.
//

#ifndef PROJECT1_356_FILEMANAGER_H
#define PROJECT1_356_FILEMANAGER_H
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::vector;

class FileManager {
public:
    int Read(istream& iss, string &messageString);
    int Error(string errStr, int lineNum);
    int WriteOutput(string &encryptedMessage, string filename);
};
#endif //PROJECT1_356_FILEMANAGER_H