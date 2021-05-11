#include "customer.h"
#include "menu.h"

Customer::Customer()
{

}

Customer::Customer(string c,string n, string a, string p):CNIC(c),name(n),address(a),phone_no(p)
{}

Customer::Customer(const Customer& obj)
{
	CNIC=obj.CNIC;
	name=obj.name;
	address=obj.address;
	phone_no=obj.phone_no;
	order=obj.order;
	reservation=obj.reservation;
}

void Customer::setOrderList(const vector<Order>& orderlist)
{
	order=orderlist;
}

void Customer::setReservationList(const vector<Reservation>& myList)
{
	reservation=myList;
}

void Customer::placeOrder(vector<ItemWithAmount> Item)
{
	Order newOrder;
	int size=Item.size();
	for(int i=0;i<size;++i)
		newOrder.addItemWithAmount(Item[i]);
	order.emplace_back(newOrder);
}

void Customer::giveFeedbackForWaiter(int rate)
{
	if(rate==-1)
		provider->incrementWarningCount();
}

void Customer::giveFeedbackForOrder(vector<int> rate)
{
	order[order.size()-1].setItemsRating(rate);		
}

Priority::Priority(string c,string n, string add, string p):Customer(c,n,add,p)
{
	membershipTime=QDateTime::currentDateTime();
	isMember=true;
}

int Priority:: payBill(Customer*& obj)
{
    int bill=order[order.size()-1].calculateBill();
	if(membershipTime.addYears(1)==QDateTime::currentDateTime())
	{

		string n,cnic,add,number;
		vector<Order> newOrder=this->order;
		vector<Reservation> newReservation=this->reservation;
		n=this->name;
		cnic=CNIC;
		add=address;
		number=phone_no;
		
		obj=new Normal(cnic,n,add,number);
		obj->setOrderList(newOrder);	
		obj->setReservationList(newReservation);
		obj->payBill(obj);
		delete this;
	}
else{
        bill-=discount;
    }

    return bill;

}
Menu Customer::getMenu(Menu m)
{
	Menu customerMenu;
	int orderCount=order.size();
	for(int i=orderCount-1;i>=0;--i)
	{
		for(int j=0;j<order[i].getItemList().size();++j)
			customerMenu.displayMenu().emplace_back(order[i].getItemList()[j].getFoodItem());
		for(int j=0;j<order[i].getDealsOrdered().size();++j)
			customerMenu.getDealList().emplace_back(order[i].getDealsOrdered()[j]);
	}
	int menuCount=m.displayMenu().size();
	for(int i=0;i<menuCount;++i)
	{
		int j=0;
		for(;j<customerMenu.displayMenu().size();++j)
		{
			if(customerMenu.displayMenu()[j]==m.displayMenu()[i])
				break;
		}
		if(j==customerMenu.displayMenu().size())
			customerMenu.displayMenu().emplace_back(m.displayMenu()[i]);
	}
	int menuDealCount=m.getDealList().size();
	for(int i=0;i<menuDealCount;++i)
	{
		int j=0;
		for(;j<customerMenu.getDealList().size();++j)
		{
			if(customerMenu.getDealList()[j]==m.getDealList()[i])
				break;
		}
		if(j==customerMenu.getDealList().size())
			customerMenu.getDealList().emplace_back(m.getDealList()[i]);
	}
//	customerMenu.displayMenu().assign(s1.begin(),s1.end());//erase( unique( customerMenu.displayMenu().begin(), customerMenu.displayMenu().end() ), customerMenu.displayMenu().end() );
	//customerMenu.getDealList().assign(s2.begin(),s2.end());//.erase( unique( customerMenu.getDealList().begin(), customerMenu.getDealList().end() ), customerMenu.getDealList().end() );
	return customerMenu;
}

int Customer::payBill(Customer*&)
{
	int bill=order[order.size()-1].calculateBill();
	return bill;
}

bool Customer::getMembership(Customer*&)
{
	return false;
}

Normal::Normal(string c,string n, string add, string p):Customer(c,n,add,p)
{
	isMember=false;
}

bool Normal::getMembership(Customer*& obj)
{
	string n,cnic,add,number;
	vector<Order> newOrder=this->order;
	vector<Reservation> newReservation=this->reservation;
	n=this->name;
	cnic=CNIC;
	add=address;
	number=phone_no;
	
	obj=new Priority(cnic,n,add,number);
	obj->setOrderList(newOrder);	
	obj->setReservationList(newReservation);
	delete this;
	return true;
}

void Customer::addOrder(const Order &o)
{
	order.emplace_back(o);
}
