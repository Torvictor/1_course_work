#include <iostream>

using namespace std;

void PrintArrayKMP(int *Arr, int quant);

void PrefixFunction(char* text, int *Arr, int length);

void Combination(char* str, char* text, char* common_str, int common_len);

void KMP_Search(char* str, int str_len, int common_len, int* PrefixArr);