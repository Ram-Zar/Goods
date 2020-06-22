#include "GoodsStore.h"
#include <iostream>
#include <cstring>
#include <clocale>
#include "windows.h"
#pragma warning (disable:4996)
using namespace std;
int main()
{
	setlocale(0, "russian");
	Goods g("Творог", "2020.06.18", 6, 69, 99, 0);
	Sleep(20000);
	cout << g;
	g.ToString();
	return 0;
}