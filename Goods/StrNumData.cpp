#include "StrNumData.h"
#include <cstring>
int StrNumData::_Search_(string buff[], int summ,int kopeyki)
{
	int i = 0, count = -1, Scount;
	while (kopeyki > 0)
	{
		++count;
		if (count % 3 == 0)
		{
			if ((kopeyki % 10 == 1) && (kopeyki / 10 % 10 != 1))
			{
				buff[i].append(R_K[3]);
			}
			else
			{
				if ((kopeyki % 10 > 1) && (kopeyki % 10 < 5) && (kopeyki / 10 % 10 != 1))
				{
					buff[i].append(R_K[4]);
				}
				else
				{
					buff[i].append(R_K[5]);
				}
			}
			++i;
		}
		if ((count % 3 == 0) && (kopeyki / 10 % 10 == 1))
		{
			buff[i].append(DecData[kopeyki % 100 % 10]);
			++count;
			kopeyki /= 10;
		}
		else
		{
			if (kopeyki % 10 != 0)
			{
				buff[i].append(data1[kopeyki % 10 - 1][count % 3]);
			}			
		}
		++i;
		kopeyki /= 10;
	}
	count = -1;
	while (summ > 0)
	{
		++count;
		Scount = count / 3;
		if (count % 3 == 0)
		{
			if ((summ % 10 == 1) && (summ / 10 % 10 != 1))
			{
				if (Scount == 0)
				{
					buff[i].append(R_K[0]);
				}
				if (Scount == 1)
				{
					buff[i].append(S_M[0]);
				}
				if (Scount == 2)
				{
					buff[i].append(S_M[3]);
				}
			}
			else
			{
				if ((summ % 10 > 1) && (summ % 10 < 5) && (summ / 10 % 10 != 1))
				{
					if (Scount == 0)
					{
						buff[i].append(R_K[1]);
					}
					if (Scount == 1)
					{
						buff[i].append(S_M[1]);
					}
					if (Scount == 2)
					{
						buff[i].append(S_M[4]);
					}
				}
				else
				{
					if (Scount == 0)
					{
						buff[i].append(R_K[2]);
					}
					if (Scount == 1)
					{
						buff[i].append(S_M[2]);
					}
					if (Scount == 2)
					{
						buff[i].append(S_M[5]);
					}
				}
			}
			++i;
		}
        if ((count % 3 == 0) && (summ / 10 % 10 == 1))
		{
			buff[i].append(DecData[summ % 100 % 10]);
			++count;
			++i;
			summ /= 10;
		}
		else
		{
			if (summ % 10 != 0)
		    {
				if ((count % 3 == 0) && (Scount == 1) && ((summ % 10 == 1) || (summ % 10 == 2)))
				{
					buff[i].append(data1[summ % 10 - 1][3]);
				}
				else
				{
					buff[i].append(data1[summ % 10 - 1][count % 3]);
				}
			++i;
			}
		}
	summ /= 10;
	}
	return i;
}
const string StrNumData::data1[9][4] =
{
	"����",
	"-1",
	"���",
	"����",
	"���",
	"��������",
	"������",
	"���",
	"���",
	"��������",
	"������",
	"-1",
	"������",
	"�����",
	"���������",
	"-1",
	"����",
	"���������",
	"�������",
	"-1",
	"�����",
	"����������",
	"��������",
	"-1",
	"����",
	"���������",
	"�������",
	"-1",
	"������",
	"�����������",
	"���������",
	"-1",
	"������",
	"���������",
	"���������",
	"-1"
};
const string StrNumData::S_M[6] =
{
	"������",
	"������",
	"�����",
	"�������",
	"��������",
	"���������"
};

const string  StrNumData::DecData[10] =
{
	"������",
	"�����������",
	"����������",
	"����������",
	"������������",
	"����������",
	"�����������",
	"����������",
	"������������",
	"������������"
};
const string StrNumData::R_K[6] =
{
	"�����",
	"�����",
	"������",
	"�������",
	"�������",
	"������"
};
