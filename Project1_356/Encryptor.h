//
// Created by Jake on 9/9/2016.
//

#ifndef PROJECT1_356_ENCRYPTOR_H
#define PROJECT1_356_ENCRYPTOR_H
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include "Message.h"

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::vector;

class Encryptor {
public:
    string key1;
    string key2;

    string Encrypt(string &messageString, int iteration);
    void ProcessInput();
    bool VerifyKey(string key);
    string TakeInput(string key, int keyNum);
};


#endif //PROJECT1_356_ENCRYPTOR_H
