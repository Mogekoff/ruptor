#pragma once
#include <cypher.h>

class Caesar : public Cypher
{
private:
    int key;
public:
    Caesar(bool isEncryptOrElse, string inout, wstring textOrDir, string lang, string p1);
    bool Encrypt(); //renamed from DoCypher to Encrypt
    bool Decrypt();
};
