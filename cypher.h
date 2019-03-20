#pragma once
#include <io.h>

class Cypher                //Абстрактный базовый класс для всех алгоритмов шифрования
{
private:
    IO *io;                 //Экземпляр класса ввода-вывода

protected:                  //Общие параметры, нужные всем алгоритмам
    wstring *alphabet;      //Строка с алфавитом
    wstring *frequency;     //Строка с частотностью букв в алфавите
    wstring *input;         //Строка с исходным текстом
    wstring *output;        //Строка с результирующим текстом
    int *alphabetLenght;    //Кол-во букв в алфавите

public:
    Cypher();
    virtual ~Cypher();
    virtual void Init(string inout, wstring textOrDir, string lang);    //Методия инициализации. Доставляет общие параметры классу алгоритма
    virtual bool Encrypt();                                             //Метод шифрования
    virtual bool Decrypt();                                             //Метод расшифровки (в сим. алг-мах повторяет Encrypt() )
};

