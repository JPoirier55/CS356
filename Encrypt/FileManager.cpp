//
// Created by Jake on 9/9/2016.
//

#include "Message.h"
#include "FileManager.h"

int FileManager::Read(istream& iss, string &messageString) {
    string line;
    char c;
    int lineNum = 0;
    if (iss.fail()) {
        return Error("Cannot read file, returning: ", lineNum);
    } else {
        while (getline(iss, line)) {
            std::istringstream iss(line);
            lineNum += 1;

            while (!iss.eof()) {
                int t = iss.get();
                if(t == 46) {
                    messageString += "XX";
                }else if(((t >= 65)&&(t <=91))||((t >=96)&&t<=122)||(t == 32)){
                    messageString+=char(t);
                }
            }
        }
    }
    return 1;
}

int FileManager::WriteOutput(string &encryptedMessage, string outputfilename){
    std::ofstream outputfile;
    outputfile.open(outputfilename);

    outputfile << encryptedMessage;

    outputfile.close();
    return 1;
}


int FileManager::Error(string errStr, int lineNum){
    cerr << "\033[1;31mERROR : \033[0m" << errStr <<  " line: "<< lineNum << endl;
    return -1;
}


