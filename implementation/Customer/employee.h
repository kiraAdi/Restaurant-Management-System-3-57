#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Customer;
#include "deal.h"
#include "sitting_arrangement.h"
class Order;
#include<string>
#include <vector>

using namespace std;
//enum class string { Manager,AssistantManager, Chef,FullTimeReceptionisit,PartTimeReceptionist,FullTimeWaiter,PartTimeWaiter,FullTimeSecurity,PartTimeSecurity };

class Employee
{
protected://made protected to access it through all derived classes
    string name;
    string CNIC;
    string phone_no;
    string type;
    public:
    virtual double getSalary()=0;
	virtual string getType()=0;
};

class FullTimeOnly:public Employee
{
private:
    double fixedPay;
public:
    virtual double getSalary();
    virtual string getType();

};

class ManagingStaff:public FullTimeOnly
{
private:
    double managingPay;
public:
    double getSalary();
    string getType();
};

class Chef:public FullTimeOnly
{
private:
    int warningCount;
public:	
    double getSalary();
	string getType();
    void cookFood();
	void incrementWarningCount();
	Chef& operator=(const Chef&);
};

class Manager:public ManagingStaff
{
private:
	double extraPay;
	vector<FoodItem*> food_item;
	vector<Deal*> deal;
public:
    double getSalary();
    string getType();
    void manageEmployee(string empCNIC);
    void manageItem(string itemName);
    void manageDeal(string dealName);
};

class AssistantManager:public ManagingStaff
{
private:
    SittingArrangement* sitting_arrangement;
    vector<Ceremony*> ceremony;
public:
    double getSalary();
    string getType();
    float checkRating();
    void requestManager(string employee);
};

class Receptionist:public Employee{
public:
    virtual double getSalary()=0;
    virtual string getType()=0;
    void receiveCall(string purpose);
    void allocateTable();
    void allocateWaiter(int table_no);
	void addCustomer(Customer obj);
    void sendDelivery(string address);
};

class FullTimeReceptionisit:public Receptionist
{
private:
    double fixedPay;
public:
    double getSalary();
    string getType();
};

class PartTimeReceptionisit:public Receptionist
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    string getType();
};

class Security:public Employee
{
public:
    double getSalary()=0;
    string getType()=0;
};

class FullTimeSecurity:public Security
{
private:
    double fixedPay;
public:
    double getSalary();
    string getType();
};

class PartTimeSecurity:public Security
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    string getType();
};

class Waiter:public Employee
{
private:
	int warningCount;
	vector<Order> order;
public:
    double getSalary()=0;
    string getType()=0;
    void provideFood(int table_no);
    bool receiveBill(int amount);
	//-------------------------------------//
	Waiter(const Waiter&);
	void incrementWarningCount();
	Waiter& operator=(const Waiter&);
};

class FullTimeWaiter:public Waiter
{
private:
    double fixedPay;
public:
    double getSalary();
    string getType();
};

class PartTimeWaiter:public Waiter
{
private:
    int ratePerHour;
    int hours;
public:
    double getSalary();
    string getType();
};

#endif // EMPLOYEE_H
