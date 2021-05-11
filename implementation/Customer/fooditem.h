#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
class Chef;
using namespace std;

class FoodItem
{
private:
    string name;
    double price;
    string type;
	//---------------------------------------------------//
	string ingredients;
	Chef* cook;
public:
    FoodItem(string n,string i,int p,string _type );
	FoodItem();
    virtual string getType()=0;
	//---------------------------------------------------//
    double getPrice();
	string getName();
	string getIngredients();
	void rateCook(int);
	FoodItem(const FoodItem&);
	FoodItem& operator=(const FoodItem& obj);
	bool operator ==(const FoodItem&);
};
class Appetizer:public FoodItem
{
public:
    Appetizer(string n,string i,double p):FoodItem(n,i,p,"Appetizer"){}
    string getType()
	{
		return "Appetizer";
	}

};
class MainCourse:public FoodItem
{
public:
    MainCourse(string n,string i,double p):FoodItem(n,i,p,"MainCourse"){}
    string getType()
	{
		return "MainCourse";
	}
};
class Chinese:public MainCourse
{

};
class Italian:public MainCourse
{

};
class Other:public MainCourse
{

};
class Dessert:public FoodItem
{
public:
    Dessert(string n,string i,double p):FoodItem(n,i,p,"Dessert"){}
    string getType()
	{
		return "Dessert";
	}
};
#endif // FOODITEM_H
