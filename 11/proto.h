#include <iostream>

using namespace std;

struct StackASY
{
	char elstack;
	StackASY *next;
};

StackASY* PushToStackASY(StackASY **begin, const char &add_el);

char PopFromStackASY(StackASY **b);

int PriorOfSigns(char sign);

void ResPolishNote(char* InStr, char* OutStr, int outstr_len, StackASY* cur);