#include "reservation.h"

Reservation::Reservation()
{

}

Reservation::Reservation(const Reservation& obj)
{
	date=obj.date;
	time=obj.time;
	utilized=obj.utilized;
}

Reservation& Reservation::operator=(const Reservation& obj)
{
	date=obj.date;
	time=obj.time;
	utilized=obj.utilized;
	return *this;
}
