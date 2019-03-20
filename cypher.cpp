#include "cypher.h"

Cypher::Cypher()
{
    this->io = new IO;

}
Cypher::~Cypher(){
    io->Output();
}
void Cypher::Init(string inout, wstring textOrDir, string lang) {

    io->SetAlphabet(lang);
    io->SetInputOutputMode(inout);
    io->Input(textOrDir);

    alphabet    = io->GetAlphabet();
    frequency   = io->GetFrequency();
    input       = io->GetInputText();
    output      = io->GetOutputText();
    alphabetLenght = io->GetAlphabetLenght();

}

bool Cypher::Encrypt(){
    return true;
}
bool Cypher::Decrypt(){
    return true;
}
