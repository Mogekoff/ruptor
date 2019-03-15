#include "cypher.h"

Cypher::Cypher()
{

    this->io = new IO;

}

void Cypher::DoCypher(string inout, wstring textOrDir, string lang) {

    io->SetAlphabet(lang);
    io->SetInputOutputMode(inout);
    io->Input(textOrDir);

    alphabet = io->GetAlphabet();
    frequency = io->GetFrequency();

    input = io->GetInputText();
    output = io->GetOutputText();

}
