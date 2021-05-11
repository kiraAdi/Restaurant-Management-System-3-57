#include"dal.h"
class bal
{
private:

public:
	bal()
	{
		
	}
	QSqlQuery getdata(QString qry)
	{
		dal d;
		QSqlQuery query=	d.getdata(qry);
		return query;
	}
};
