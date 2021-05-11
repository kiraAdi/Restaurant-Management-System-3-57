#include "fooditem.h"
#include "employee.h"

FoodItem::FoodItem()
{

}


FoodItem::FoodItem(string n,string i,int p,string _type):name(n),ingredients(i),price(p),type(_type)
{
}

FoodItem::FoodItem(const FoodItem& obj)
{
	name=obj.name;
	ingredients=obj.ingredients;
	price=obj.price;
	type=obj.type;
	cook=obj.cook;
}

bool FoodItem::operator==(const FoodItem& obj)
{
	return (name==obj.name);
}

double FoodItem::getPrice()
{
	return price;
}

void FoodItem::rateCook(int r)
{
	if(r==-1)
		cook->incrementWarningCount();
}

FoodItem& FoodItem::operator=(const FoodItem& obj)
{
	name=obj.name;
	ingredients=obj.ingredients;
	price=obj.price;
	type=obj.type;
	cook=obj.cook;
	return *this;
}

string FoodItem::getIngredients()
{
	return ingredients;
}

string FoodItem::getName()
{
	return name;
}
