#ifndef DEAL_H
#define DEAL_H
#include "itemwithamount.h"
#include <string>
using namespace std;
class Deal
{
private:
    string name;
    int price;
    vector<ItemWithAmount> item_with_amount;
public:
    Deal();
	Deal(string ,int);
	Deal(const Deal&);
	Deal& operator=(const Deal&);
	void addItemWithAmount(const ItemWithAmount&);
	string getItemNames();
	string getName()
	{
		return name;
	}
	int getPrice()
	{
		return price;
	}
	bool operator ==(const Deal&);
};

#endif // DEAL_H
