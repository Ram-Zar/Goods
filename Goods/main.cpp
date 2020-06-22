#include "GoodsStore.h"
#include <iostream>
#include <cstring>
#include <clocale>
#include "windows.h"
using namespace std;
int main()
{
	setlocale(0, "russian");
	Goods g("Творог", "2020.06.18", 6, 69, 99, 0);//0 - FOOD,1 - STATIONERY,2 - CLOTHER ,3 - SHOES,4 - APPLIANCE,5 - HOUSE_CHEMICALS	
	cout << g;
	Sleep(20000);//Нужно для того, чтоюы увидеть, как падает цена
	cout <<"\n"<< g;
	g.ToString();
	return 0;
}