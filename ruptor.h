#pragma once
#include <headers.h>

class Ruptor
{
private:
    string arg1,    //command (a,e,d)           //analysis -t "sfaw"    analysis -t "safa" en   decrypt -t "eae" en caesar 2    decrypt -t "eae" en caesar brute   decrypt -t "eae" en caesar freq
           arg2,    //text or file(t,f)         //encrypt -t "0101" xor "10101"     encrypt -t "sad" caesar 5
           arg3,    //arg for arg2
           arg4,    //language (ru,en)
           arg5,    //crypt algorythm
           arg6;    //optional


    void Help();    //show help
    void Version(); //show version
public:
    Ruptor(int &ArgumnetsCount, char **Arguments);

};

