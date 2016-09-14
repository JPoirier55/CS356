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
5. File must only use A-Z and a-z chars, with the exception of a period for message splits, all other chars will
    be removed on file read
6. X's are kept at the end of the decrypted file if the file length%10 == 0

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
$ cat jake-poirier-encrypted-str.txt
hntrdrzsuXeiyeagyhoepdmbdecXtreehahupXXbtienrmeglscwhdnosmntytelguXiea

$ ./Decrypt/PA1_Decrypt jake-poirier-encrypted-str.txt
KEY# 1 - Please enter a valid 10 character key code:
cornflakes
KEY# 2 - Please enter a valid 10 character key code:
blackhorse
$ cat jake-poirier-decrypted-str.txt
sendresupplytothebridgebythechurchXXammoneededurgentlywithmagazinesXXX