#include "alphabet.h"

void getAlphabet(string &abc, string &ABC, int &size, int &SIZE, const string &lang){
    string line;

    ifstream file ("./"+lang);

    if (file.is_open())
    {
        getline (file, line);
        getline (file, line);
        abc = line;
        size = signed(abc.length());
        getline (file, line);
        ABC = line;
        SIZE = signed(ABC.length());
        file.close();
    }
}

void getAlphabet(int &size, int &SIZE, const string &lang){
    string line;

    ifstream file ("./"+lang);

    if (file.is_open())
    {
        getline (file, line);
        getline (file, line);
        size = signed(line.length());
        getline (file, line);
        SIZE = signed(line.length());
        file.close();
    }
}

void getAlphabet(int &size, const string &lang){
    string line;

    ifstream file ("./"+lang);

    if (file.is_open())
    {
        getline (file, line);
        size = signed(line.length());

        file.close();
    }
}

