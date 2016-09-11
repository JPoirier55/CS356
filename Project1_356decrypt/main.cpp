#include <iostream>
#include "FileManager.h"
#include "Message.h"
#include "Decryptor.h"

using std::cin;


int main(int argc, char *argv[]) {

    FileManager fileManager;
    Message message;
    Decryptor decryptor;
    decryptor.ProcessInput();

    std::ifstream istr("C:\\Users\\Jake\\git3\\Project1_356decrypt\\output.txt");
    if (istr.fail())
        return fileManager.Error("File IO error", 0);
    if (fileManager.Read(istr, message.messageString) == -1) {
        return -1;
    }

    string firstDecrypted = decryptor.Decrypt(message.messageString, 1);
    string secondDecrypted = decryptor.Decrypt(firstDecrypted, 2);
    fileManager.WriteOutput(secondDecrypted, "C:\\Users\\Jake\\git3\\Project1_356decrypt\\output2.txt");
    return 1;
}