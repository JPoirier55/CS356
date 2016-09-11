#include <iostream>
#include "FileManager.h"
#include "Message.h"
#include "Encryptor.h"

using std::cin;


int main(int argc, char *argv[]) {

    FileManager fileManager;
    Message message;
    Encryptor encryptor;
    encryptor.ProcessInput();

    std::ifstream istr("C:\\Users\\Jake\\git3\\Project1_356\\output.txt");
    if (istr.fail())
        return fileManager.Error("File IO error", 0);
    if (fileManager.Read(istr, message.messageString) == -1) {
        return -1;
    }

    string firstEncrypted = encryptor.Encrypt(message.messageString, 1);
    string secondEncrypted = encryptor.Encrypt(firstEncrypted, 2);
    fileManager.WriteOutput(secondEncrypted, "C:\\Users\\Jake\\git3\\Project1_356\\output2.txt");
    return 1;
}