#pragma once
#include <cypher.h>             //Базовый класс всех алгоритмов для наследования

class Caesar : public Cypher    //Само наследование от него
{
private:
    int key;                    //Ключ сдвига по алгоритму Цезаря
public:
    Caesar(bool isEncryptOrElse, string inout, wstring textOrDir, string lang, string p1);
    bool Encrypt() override;
    bool Decrypt() override;
};
