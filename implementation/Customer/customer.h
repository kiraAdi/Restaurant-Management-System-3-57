#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "order.h"
class Menu;
#include "reservation.h"
#include "itemwithamount.h"
#include <qdatetime.h>
#include "employee.h"
#include <string>
#include <vector>
using namespace std;
class Customer
{
protected://All data members are protected
    string name;
    string address;
    string phone_no;
    vector<Order> order;
    vector<Reservation> reservation;
	bool isMember;
	//---------------------------------------------//
	Waiter* provider;
	string CNIC;
public:
    Customer();
    void placeOrder(vector<ItemWithAmount> itemList);
	virtual bool isAMember()=0;
    virtual bool getMembership(Customer*&);//changed
    virtual int payBill(Customer*&);//changed
	//--------------------------------------------//
	Customer(string,string,string,string);
	Customer(const Customer&);
	string getCNIC()
	{
		return CNIC;
	}
	void giveFeedbackForWaiter(int);
	void giveFeedbackForOrder(vector<int>);
	void setOrderList(const vector<Order>&);
	void setReservationList(const vector<Reservation>&);
	Menu getMenu(Menu);
	void addOrder(const Order&);
	Order* getLatestOrder()
	{
		return &order[order.size()-1];
	}
};
class Priority:public Customer
{
private:
	QDateTime membershipTime;
    float discount;
public:
	int payBill(Customer*&);//changed
	//-----------------------------------------------//
	Priority(string,string,string,string);
	bool isAMember()
	{
		return true;

	}
};

class Normal:public Customer
{
public:
	bool getMembership(Customer*&);//changed
	//-------------------------------------------------//
	Normal(string,string,string,string);
	bool isAMember()
	{
		return false;
	}
};

#endif // CUSTOMER_H
