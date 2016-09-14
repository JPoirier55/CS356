//
// Created by Jake on 9/9/2016.
//

#include <algorithm>
#include "Encryptor.h"
using std::cin;
using std::vector;

string Encryptor::Encrypt(string &messageString, int iteration) {

    string key;

    if(iteration == 1){
        key = key1;
    }else{
        key = key2;
    }

    std::map<char,vector<char>> keyMap;
    vector<vector<char>> chars;

    if(messageString.length()%10 !=0){
        for(size_t i = 0; i < messageString.length()%10;i++){
            messageString += "X";
        }
    }

    vector<char> temp;
    int messageIndex = 0;
    while(messageIndex<messageString.length()){
        for(std::size_t i = 0; i < 10; i++){
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
        for(size_t k = 0; k<chars.size();k++) {
            tempchars.push_back(chars[k][i]);
        }
        keyMap[key[i]] = tempchars;
        tempchars = {};
    }
    string encryptedMessage;
    for(size_t i = 0; i < 10; i++){
        for(size_t j = 0; j < keyMap[key_sorted[i]].size(); j++){
            encryptedMessage+= keyMap[key_sorted[i]][j];
        }
    }
    return encryptedMessage;
}

bool Encryptor::VerifyKey(string key){
    if(key.length() < 10){
        cerr << "Key too short, please enter a longer key" << endl;
        return false;
    }
    string key_sorted = key;
    std::sort(key_sorted.begin(), key_sorted.end());
    for(std::size_t i = 1; i < key_sorted.length(); i++){
        if(key_sorted[i] == key_sorted[i-1]){
            cerr << "There are doubles in this key" << endl;
            return false;
        }
    }
    return true;
}

string Encryptor::TakeInput(string key, int keyNum){
    cerr << "KEY# "<< keyNum << " - Please enter a valid 10 character key code:   " << endl;
    cin >> key;
    return key;
}

void Encryptor::ProcessInput(){

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