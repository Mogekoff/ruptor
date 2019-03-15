#pragma once
#include <io.h>

class Cypher
{
private:


public:
    Cypher();
    virtual void DoCypher(string inout, wstring textOrDir, string lang);
    wstring alphabet;
    wstring frequency;
    wstring input;
    wstring output;

    IO *io;
};

