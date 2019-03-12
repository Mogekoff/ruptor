                                        #####  #    # #####  #####  ####  #####
                                        #    # #    # #    #   #   #    # #    #
                                        #    # #    # #    #   #   #    # #    #
                                        #####  #    # #####    #   #    # ##### 
                                        #   #  #    # #        #   #    # #   # 
                                        #    #  ####  #        #    ####  #    #
<h2>* Description:</h2>

This program analyse, encrypt and decrypt information.
Supported algorythms(2): <b>Caesar</b>, <b>XOR</b>

<cite> Created by mogekoff. </cite>

<h2>* Compiling:</h2>

Just open <b>"ruptor.pro"</b> file in Qt Creator and compile this with GCC.

<h2>* <b>Installing:</b></h2>

1) Type this commands:
  
Navigate to the folder with ruptor_installer.

<b> ```./ruptor_installer``` </b>

P.S. The installer will do everything for you

2) Thats is. Now you can use it just like this:<br> 

<b>```ruptor -h```</b>
  
<h2>* Example Using: </h2>

This command analyse text by symbol.<br>
<b>```ruptor analysis --text "Hello World!"```</b>

This command ENCRYPT ENglish Text with CAESAR algorytm using letter shift-key 4:<br>
<b>```ruptor encrypt -t "Hello World!" en caesar 4```</b>

Does the opposite:<br>
<b>```ruptor decrypt -t "Hello World!" en caesar 4```</b>
  
Bruteforce of text in file:<br>
<b>```ruptor decrypt -f "/path/to/file" en caesar --brute```</b>

Decoding attempt based on frequency analysis of letters of the alphabet<br>
<b>```ruptor decrypt -f "/path/to/file" en caesar --frequency```</b>

<cite> Thanks for using my programm! </cite>
                                 <cite> ©Мogekkof </cite> 
