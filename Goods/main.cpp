#include "GoodsStore.h"
#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;
int main()
{
	setlocale(0, "russian");
	Goods g("aaa", "2020.12.12",6, 89, 99,0);
	cout << g;
	g.Print_Num();
	return 0;
}