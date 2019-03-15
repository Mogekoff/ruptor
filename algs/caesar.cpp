#include "caesar.h"


Caesar::Caesar(bool isEncryptOrElse, string inout, wstring textOrDir, string lang, string p1)
{
    Cypher::DoCypher(inout, textOrDir,lang);

    this->key = stoi(p1);

    if (isEncryptOrElse)
        Encrypt();
    else
        Decrypt();

    io->Output();

}
bool Caesar::Encrypt(){



    return true;

}
bool Caesar::Decrypt(){


    return true;
}
