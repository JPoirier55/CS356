Jake Poirier
CS356 PA1_partA
9/13/2016

******* ASSUMPTIONS *********

1. This program takes input from the user for each key
2. Each key is used the same direction - EG if the user enters 'cornflakes' for key one, and 'blackhorse' for key 2
    during encryption, the user for decryption must use 'cornflakes' for key one, and 'blackhorse' for key 2
3. Spaces are kept in the file, periods are used for breaks in messages like in special forces, which end up being 'XX'
    in the encrypted message, and get removed on write file as a .
4. Keys must be less than 10 chars, and not have double chars, or the user will be prompted again
5. File must only use A-Z and a-z chars, with the exception of a period for message splits, all other chars will
    be removed on file read
6. X is kept at the end of the decrypted file to signal EOF

*****************************

TO COMPILE:
$ cd Encrypt
$ make

$ cd ../Decrypt
$ make

TO RUN:
$ cd ..
$ ./Encrypt/transposition-encr <unencrypted_filename>

$ ./Decrypt/transposition-decr <encrypted_filename>


EXAMPLE WITH TEST.TXT:

$ cat test.txt
send resupply to the bridge by the church. ammo needed urgently with magazines

$ ./Encrypt/transposition-encr test.txt
KEY# 1 - Please enter a valid 10 character key code:
cornflakes
KEY# 2 - Please enter a valid 10 character key code:
blackhorse
$ cat jake-poirier-encrypted-str.txt
hntrdrzsuXeiyeagyhoepdmbdecXtreehahupXXbtienrmeglscwhdnosmntytelguXiea

$ ./Decrypt/transposition-decr jake-poirier-encrypted-str.txt
KEY# 1 - Please enter a valid 10 character key code:
cornflakes
KEY# 2 - Please enter a valid 10 character key code:
blackhorse
$ cat jake-poirier-decrypted-str.txt
sendresupplytothebridgebythechurchXXammoneededurgentlywithmagazinesXXX