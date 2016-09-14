OBJS= FileManager.o Encryptor.o Message.o main.o

PA1_Encrypt: $(OBJS)
	g++ FileManager.o Encryptor.o Message.o main.o -o PA1_Encrypt
FileManager.o: FileManager.cpp FileManager.h Message.h
	g++ -c -std=c++11 -I. FileManager.cpp
Encryptor.o: Encryptor.cpp Encryptor.h Message.h
	g++ -c -std=c++11 -I. Encryptor.cpp
main.o: main.cpp FileManager.h Encryptor.h Message.h
	g++ -c -std=c++11 -I. main.cpp
clean:
	rm $(OBJS) PA1_Encrypt
