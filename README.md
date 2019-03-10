
                                            #####  #    # #####  #####  ####  #####
                                            #    # #    # #    #   #   #    # #    #
                                            #    # #    # #    #   #   #    # #    #
                                            #####  #    # #####    #   #    # #####
                                            #   #  #    # #        #   #    # #   #
                                            #    #  ####  #        #    ####  #    #

<h2>* Description:</h2>

This program analyse, encrypt and decrypt information.
Supported algorythms(2): Caesar, XOR

<h2>* Compiling:</h2>

1) Ehh, just open "ruptor.pro" file in Qt Creator and compile this with GCC.
2) ???
3) PROFIT!!1

<h2>* <b>Installing:</b></h2>

1) Type this commands:
  
``` cd /path/to/ruptor ```<br>
```  sudo ln -s ./ruptor /usr/bin/ruptor```

2) Thats is. Now you can use it just like this:<br> 

```ruptor -h```
  
<h2>* Using:</h2>

This command analyse text by symbol.<br>
```ruptor analysis --text "Hello World!"```

This command ENCRYPT ENglish Text with CAESAR algorytm using letter shift-key 4:<br>
```ruptor encrypt -t "Hello World!" en caesar 4```

Does the opposite:<br>
```ruptor decrypt -t "Hello World!" en caesar 4```
  
Bruteforce of text in file:<br>
```ruptor decrypt -f "/path/to/file" en caesar --brute```

Decoding attempt based on frequency analysis of letters of the alphabet<br>
```ruptor decrypt -f "/path/to/file" en caesar --frequency```
