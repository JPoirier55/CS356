OBJS= FileManager.o Decryptor.o Message.o main.o

transposition-decr: $(OBJS)
	g++ FileManager.o Decryptor.o Message.o main.o -o transposition-decr
FileManager.o: FileManager.cpp FileManager.h Message.h
	g++ -c -std=c++11 -I. FileManager.cpp
Decryptor.o: Decryptor.cpp Decryptor.h Message.h
	g++ -c -std=c++11 -I. Decryptor.cpp
main.o: main.cpp FileManager.h Decryptor.h Message.h
	g++ -c -std=c++11 -I. main.cpp
clean:
	rm $(OBJS) transposition-decr
