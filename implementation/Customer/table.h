#ifndef TABLE_H
#define TABLE_H


class Table
{
private:
    int table_no;
    bool isReserved;
public:
    Table();
    int getNum();
    bool getStatus();
};

#endif // TABLE_H
