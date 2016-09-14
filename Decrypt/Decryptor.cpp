//
// Created by Jake on 9/10/2016.
//

#include "Decryptor.h"
#include <algorithm>
using std::cin;
using std::vector;

string Decryptor::Decrypt(string &messageString, int iteration) {

    string key;

    if(iteration == 1){
        key = key2;
    }else{
        key = key1;
    }

    std::map<char,vector<char>> keyMap;
    vector<vector<char>> chars;

    vector<char> temp;
    int messageIndex = 0;
    int colSize = messageString.length()/10;
    while(messageIndex<messageString.length()){
        for(std::size_t i = 0; i < colSize; i++){
            temp.push_back(char(messageString[messageIndex]));
            messageIndex++;
        }
        chars.push_back(temp);
        temp = {};
    }

    string key_sorted = key.substr(0,10);
    std::sort(key_sorted.begin(), key_sorted.end());
    vector<char> tempchars;
    for(size_t i = 0; i<10;i++) {
        for(size_t k = 0; k<chars[i].size();k++) {
            tempchars.push_back(chars[i][k]);
        }
        keyMap[key_sorted[i]] = tempchars;
        tempchars = {};
    }

    string decryptedMessage;
    for(size_t i = 0; i < colSize; i++){
        for(size_t j = 0; j < 10; j++){
            decryptedMessage+= keyMap[key[j]][i];
        }
    }
    return decryptedMessage;
}

bool Decryptor::VerifyKey(string key){
    if(key.length() < 10){
        return false;
    }
    string key_sorted = key;
    std::sort(key_sorted.begin(), key_sorted.end());
    for(std::size_t i = 1; i < key_sorted.length(); i++){
        if(key_sorted[i] == key_sorted[i-1]){
            cerr << "There are doubles in this string" << endl;
            return false;
        }
    }
    return true;
}

string Decryptor::TakeInput(string key, int keyNum){
    cerr << "KEY# "<< keyNum << " - Please enter a valid 10 character key code:   " << endl;
    cin >> key;
    return key;
}

void Decryptor::ProcessInput(){

    bool key1verified = false;
    bool key2verified = false;
    while(!key1verified) {
        key1 = TakeInput(key1, 1);
        if (VerifyKey(key1)) {
            key1verified = true;
        }
    }while(!key2verified){
        key2 = TakeInput(key2,2);
        if (VerifyKey(key2)) {
            key2verified = true;
        }
    }
}