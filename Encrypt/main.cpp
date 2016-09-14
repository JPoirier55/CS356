#include <iostream>
#include "FileManager.h"
#include "Message.h"
#include "Encryptor.h"

using std::cin;

int Usage(string exec){
    cerr << "USAGE: " << exec << " <inputfilename>" << endl;
}

int main(int argc, char *argv[]) {

    if(argc < 2){
        return Usage(argv[0]);
    }

    FileManager fileManager;
    Message message;
    Encryptor encryptor;
    encryptor.ProcessInput();

    std::ifstream istr(argv[1]);
    if (istr.fail())
        return fileManager.Error("File IO error", 0);
    if (fileManager.Read(istr, message.messageString) == -1) {
        return -1;
    }

    string firstEncrypted = encryptor.Encrypt(message.messageString, 1);
    string secondEncrypted = encryptor.Encrypt(firstEncrypted, 2);
    fileManager.WriteOutput(secondEncrypted, argv[1]);
    return 1;
}