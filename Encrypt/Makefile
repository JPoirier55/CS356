OBJS= FileManager.o Encryptor.o Message.o main.o

transposition-encr: $(OBJS)
	g++ FileManager.o Encryptor.o Message.o main.o -o transposition-encr
FileManager.o: FileManager.cpp FileManager.h Message.h
	g++ -c -std=c++11 -I. FileManager.cpp
Encryptor.o: Encryptor.cpp Encryptor.h Message.h
	g++ -c -std=c++11 -I. Encryptor.cpp
main.o: main.cpp FileManager.h Encryptor.h Message.h
	g++ -c -std=c++11 -I. main.cpp
clean:
	rm $(OBJS) transposition-encr
