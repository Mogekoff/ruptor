#include "text.h"

void getTextFromFile(const string &dir, string &text){

    string line;

    ifstream file (dir);

    if (file.is_open())
    {
      while ( getline (file, line) )
      {
        text+= line + '\n';
      }
      text.pop_back();
      file.close();
    }
}
