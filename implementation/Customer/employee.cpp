
#include "employee.h"
#include "order.h"

string Chef::getType()
{
	return "Chef";
}

void Chef::cookFood()
{
	for(int i=0;i<30;++i);
}

void Chef::incrementWarningCount()
{
	++warningCount;
	if(warningCount>5)
		;//Insert query for notifying manager
}

Chef& Chef::operator=(const Chef& obj)
{
	CNIC=obj.CNIC;
	name=obj.name;
	phone_no=obj.phone_no;
	warningCount=obj.warningCount;
	return *this;
}

Waiter::Waiter(const Waiter& obj)
{
	CNIC=obj.CNIC;
	name=obj.name;
	phone_no=obj.phone_no;
	warningCount=obj.warningCount;
	order=obj.order;
}

Waiter& Waiter::operator = (const Waiter& obj)
{
	CNIC=obj.CNIC;
	name=obj.name;
	phone_no=obj.phone_no;
	warningCount=obj.warningCount;
	order=obj.order;
	
	return *this;
}

void Waiter::incrementWarningCount()
{
	++warningCount;
	if(warningCount>5)
		;//Insert query for notifying manager
}
