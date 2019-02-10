#pragma once
#include "headers.h"
#include "alphabet.h"
void clear(vector<char>&symbols, vector<int>&times, string &lang);
void analysis (const string &text,vector<char>&symbols, vector<int>&times);
void frequency(vector<char>&symbols, vector<int>&times, const string &lang);
void frequency(vector<char>&symbols, vector<int>&times, const string &lang, string &text);
void printAnalysis(const vector<char>&symbols, const vector<int>&times);
void printAnalysis(const vector<char>&symbols, const vector<int>&times,string &text);
