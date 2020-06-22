#include "Date.h"
#include "Money.h"
#include "StrNumData.h"
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
class Goods
{
	enum class TYPE
	{
		FOOD=0,
		STATIONERY=1,
		CLOTHER=2,
		SHOES=3,
		APPLIANCE=4,
		HOUSE_CHEMICALS=5

	};
	string m_name;
	Date m_reg;
	time_t t_reg;
	int m_shelf_life;
	Money m_price;
	TYPE m_type;
	int m_id=0;
	int m_amount=0;
	static int s_id_gen;
	
	Money Total_price()
	{
		 return m_price* double(m_amount);
	}
	string Type(bool print)
	{
		switch (m_type)
		{
		case TYPE::FOOD :
		{
			if (print)
			{
				return "Food";
			}
			return "10";
		}break;
		case TYPE::STATIONERY:
		{
			if (print)
			{
				return "Stationary";
			}
			return "unlimited";
		}break;
		case TYPE::CLOTHER:
		{
			if (print)
			{
				return "Clother";
			}
		    return "unlimited";
		}break;
		case TYPE::SHOES:
		{
			if (print)
			{
				return "Shoes";
			}
			return "unlimited";			
		}break;
		case TYPE::APPLIANCE:
		{
			if (print)
			{
				return "Appliance";
			}
		return "unlimited";
		}break;
		case TYPE::HOUSE_CHEMICALS:
		{
			if (print)
			{
				return "House chemicals";
			}
			return "20";
		}break;
		default: return "Unknown type"; break;
		}
	}
	long long ProcSec()
	{
		time_t t = time(NULL);
		return t-t_reg;
	}
	void SetSale()
	{
		static Money first_price = m_price;
		long long t_duration = ProcSec() - m_shelf_life;
		if (t_duration >= m_shelf_life)
		{
			m_price = m_price * (1 - 0.01 * t_duration / m_shelf_life);
			cout << "\nSale: -" << first_price - m_price<<" RUB ";
		}
	}
public:
	Goods(string name, string reg_date,int amount,long price_one_rub, short price_one_k,int type)
	{
		m_id=++s_id_gen;
		m_name = name;
		m_amount = amount;
		m_type = TYPE(type);
		m_shelf_life = atoi(Type(false).c_str());
		t_reg = time(NULL);
		m_price.SetAcc(price_one_rub, price_one_k);
		m_reg(reg_date.c_str());
	}
	
	void SetAmount(int delta_amount)
	{
		m_amount += delta_amount;
		Total_price();
	}
	void SetPrice(long price_one_rub, short price_one_k)
	{
		m_price.SetAcc(price_one_rub, price_one_k);
		Total_price();
	}
	void ToString()
	{
		string buff[15];
		StrNumData s;
		s.Print(buff, m_price.GetRub(), m_price.GetKop());
	}
	friend ostream& operator<<(ostream& out, Goods& g)
	{
		g.SetSale();
		out << "\nName: " << g.m_name << "\nID: " << g.m_id << "\nType: " << g.Type(true) <<"\nShelf life: "<<g.m_shelf_life <<" days\nAmount: " << g.m_amount << "\nPrice: " << g.m_price<<" RUB ";
		return out;
	}
};