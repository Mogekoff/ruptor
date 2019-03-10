
                                            #####  #    # #####  #####  ####  #####
                                            #    # #    # #    #   #   #    # #    #
                                            #    # #    # #    #   #   #    # #    #
                                            #####  #    # #####    #   #    # #####
                                            #   #  #    # #        #   #    # #   #
                                            #    #  ####  #        #    ####  #    #

* Description:

This program analyse, encrypt and decrypt information.
Supported algorythms(2): Caesar, XOR

* Compiling:

1) Ehh, just open "ruptor.pro" file in Qt Creator and compile this with GCC.
2) ???
3) PROFIT!!1

* Installing:

1) Type this commands:
  
cd /path/to/ruptor
sudo ln -s ./ruptor /usr/bin/ruptor

2) Thats is. Now you can use it just like this: 

ruptor -h
  
* Using:

This command analyse text by symbol.
ruptor analysis --text "Hello World!"

This command ENCRYPT ENglish Text with CAESAR algorytm using letter shift-key 4:
ruptor encrypt -t "Hello World!" en caesar 4

Does the opposite:
ruptor decrypt -t "Hello World!" en caesar 4
  
Bruteforce of text in file:
ruptor decrypt -f "/path/to/file" en caesar --brute

Decoding attempt based on frequency analysis of letters of the alphabet
ruptor decrypt -f "/path/to/file" en caesar --frequency
