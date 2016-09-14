#include <iostream>
#include "FileManager.h"
#include "Message.h"
#include "Decryptor.h"

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
    Decryptor decryptor;
    decryptor.ProcessInput();

    std::ifstream istr(argv[1]);
    if (istr.fail())
        return fileManager.Error("File IO error", 0);
    if (fileManager.Read(istr, message.messageString) == -1) {
        return -1;
    }

    string firstDecrypted = decryptor.Decrypt(message.messageString, 1);
    string secondDecrypted = decryptor.Decrypt(firstDecrypted, 2);
    fileManager.WriteOutput(secondDecrypted, argv[1]);
    return 1;
}