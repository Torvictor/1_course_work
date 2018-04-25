#include <iostream>

using namespace std;

/*
BM-searching:
text - source string;
templ - search string;
text_len - length of the text;
templ_len length of the search string;
Result - array of the results.
*/
int BMsearch(char *text, char *templ, int text_len, int templ_len, int *Result);
void PrintArrBM(int *Arr, int size);

int *CreateSuffixTable(char *templ, int templ_len);

int FindPosBM(char *templ, int templ_len, char symbol);

/*construction of the table of the most right occurrences
characters of the alphabet (consisting of Latin letters,
arabic numerals, partitions and white space):
*/
int *CreateStopTable(char *templ, int templ_len);
