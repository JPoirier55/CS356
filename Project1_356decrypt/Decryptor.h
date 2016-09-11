//
// Created by Jake on 9/10/2016.
//

#ifndef PROJECT1_356DECRYPT_DECRYPTOR_H
#define PROJECT1_356DECRYPT_DECRYPTOR_H

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

class Decryptor {
public:
    string key1;
    string key2;

    string Decrypt(string &messageString, int iteration);
    void ProcessInput();
    bool VerifyKey(string key);
    string TakeInput(string key, int keyNum);
};

#endif //PROJECT1_356DECRYPT_DECRYPTOR_H
