Jake Poirier
CS356 PA1_partA
9/13/2016

******* ASSUMPTIONS *********

1. This program takes input from the user for each key
2. Each key is used the same direction - EG if the user enters 'cornflakes' for key one, and 'blackhorse' for key 2
    during encryption, the user for decryption must use 'cornflakes' for key one, and 'blachorse' for key 2
3. Spaces are neglected, as per the special forces code example, but periods are turned into 'XX', the decryption
    neglects these and leaves them as XX, same as the special forces example
4. Keys must be less than 10 chars, and not have double chars, or the user will be prompted again
5. File overwrites the given input file, does not save a copy of unencrypted data
6. File must only use A-Z and a-z chars, with the exception of a period for message splits, all other chars will
    be removed on file read

*****************************

TO COMPILE:
$ cd Encrypt
$ make

$ cd ../Decrypt
$ make

TO RUN:
$ cd ..
$ ./Encrypt/PA1_Encrypt <unencrypted_filename>

$ ./Decrypt/PA1_Decrypt <encrypted_filename>


EXAMPLE WITH TEST.TXT:

$ cat test.txt
send resupply to the bridge by the church. ammo needed urgently with magazines

$ ./Encrypt/PA1_Encrypt test.txt
KEY# 1 - Please enter a valid 10 character key code:
cornflakes
KEY# 2 - Please enter a valid 10 character key code:
blackhorse
$ cat test.txt
hntrdrzsuXeiyeagyhoepdmbdecXtreehahupXXbtienrmeglscwhdnosmntytelguXiea

$ ./Decrypt/PA1_Decrypt test.txt
KEY# 1 - Please enter a valid 10 character key code:
cornflakes
KEY# 2 - Please enter a valid 10 character key code:
blackhorse
$ cat test.txt
sendresupplytothebridgebythechurchXXammoneededurgentlywithmagazinesXXX