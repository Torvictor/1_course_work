#include <iostream>

using namespace std;

void PrintArrayRK(int *Arr, int size);

unsigned long int HashFunc(char* templ, int templ_len, int* Code);

unsigned long int HashRecalculation(int templ_len, unsigned long int hash_value, int del_symb, int add_symb);

char* TakeSubText(int start_pos, int templ_len, char* text);

int RabinKarp_Search(char* text, int text_len, char* templ, int templ_len, unsigned long int hash_templ, int* Result, int size);

void PrintResultRK(int* Result, int size);