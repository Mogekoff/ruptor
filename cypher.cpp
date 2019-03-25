#include "cypher.h"

Cypher::Cypher()
{
    this->io = new IO;

}
Cypher::~Cypher(){
    io->Output();
    delete io;
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
    inputLenght    = io->GetInputLenght();

    if (*alphabet == L"") {                         //Catch error. If /langs doesn't exist
        cout<<"Not found \""<<lang<<"\" alphabet. \nMake sure that dir \"/langs\" exists and located in folder with ruptor."<<endl;
        this->~Cypher();
    }

}

bool Cypher::Encrypt(){
    return true;
}
bool Cypher::Decrypt(){
    return true;
}
