CREATE TABLE Customer
(
CNIC varchar(255) NOT NULL,
Name varchar(255) NULL,
_Address varchar(255),
Phone_no varchar(255),
PRIMARY KEY (CNIC)
)
CREATE TABLE Hall
(
Id int IDENTITY(1,1) not null,
_Type varchar(255) NULL,
PRIMARY KEY (Id)
)
CREATE TABLE [dbo].[Hall](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[_Type] [varchar](255) NULL,
PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO


CREATE TABLE Reservation
(
hall_id int not null,
customer_id varchar(255) not NULL,
PRIMARY KEY (hall_id,customer_id),
Foreign Key(hall_id) references Hall(Id),
Foreign Key(customer_id) references Customer(CNIC)
)

CREATE TABLE [dbo].[Table](
	[Id] [int] IDENTITY(1,1) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

ALTER TABLE [dbo].[Table]
ADD no_of_customers int null

CREATE TABLE [dbo].[Reservation_Table](
	[_date] [varchar](100) NOT NULL,
	[_time] [varchar](100) NOT NULL,
	[table_id] [int] NOT NULL,
	[customer_id] [varchar](255) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[_date] ASC,
	[_time] ASC,
	[table_id] ASC,
	[customer_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

ALTER TABLE [dbo].[Reservation_Table]  WITH CHECK ADD FOREIGN KEY([customer_id])
REFERENCES [dbo].[Customer] ([CNIC])
GO

ALTER TABLE [dbo].[Reservation_Table]  WITH CHECK ADD FOREIGN KEY([table_id])
REFERENCES [dbo].[Table] ([Id])
GO

CREATE TABLE [dbo].[Dine_in](
	[waiter_cnic] [varchar](100) NOT NULL,
	[table_id] [int] NOT NULL,
	[customer_id] [varchar](255) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[waiter_cnic] ASC,
	[table_id] ASC,
	[customer_id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]

GO

SET ANSI_PADDING OFF
GO

create table Employee
(
	CNIC varchar(50) not null primary key,
	Name varchar(50) not null,
	Phone_no varchar(50),
	_Type varchar(50)
)

create table Waiter
(
	CNIC varchar(50) foreign key references Employee(CNIC),
	Warning_Count varchar(50)
)

create procedure addEmployee
@type varchar(50),
@Name varchar(50),
@CNIC varchar(50),
@Phone_no varchar(50),
@Warning_count int
as
begin
	if(@type is not null)
	begin
		insert into EMPLOYEE values(@CNIC,@Name,@Phone_no,@type)
		if(@type='waiter')
		begin
			insert into Waiter values(@CNIC,@Warning_count)
		end
	end
end
go


alter table Dine_in add _date varchar(50) not null
alter table Dine_in add _time varchar(50) not null

ALTER TABLE [Waiter] ALTER COLUMN [CNIC]  varchar (50) NOT NULL
alter table Waiter add Primary Key (CNIC)
alter table Reservation_Table ADD FOREIGN KEY (waiter_cnic)
REFERENCES Waiter(CNIC)

CREATE TABLE Menu
(
Id int IDENTITY(1,1) not null,
Name varchar(255) NOT NULL,
_Description varchar(255) NULL,
Price float,
_type varchar(255),
PRIMARY KEY (id)
)


select*from Customer
select * from waiter
select * from employee
 create table Deal
(
	deal_id int identity(1,1),
	name varchar(50),
	price int,
	food_id int,
	PRIMARY KEY (name,food_id),
	foreign key (food_id) references Menu(Id)
)
/*removed
create table FoodItem
(
	deal_name varchar(50) foreign key references Deal(name),
	name varchar(50),
	price int,
	_type varchar(50)
)*/
create table _Order
(
	customerid varchar(255) foreign key references Customer(CNIC),
	item_or_deal_name varchar(50),
	amount float ,
	isDeal varchar(50)
)
alter table Customer add waiter_cnic varchar(50)  
alter table Customer add Foreign key(waiter_cnic) references Waiter(CNIC)

alter table Employee add Salary float

insert into Employee(Name,CNIC,Phone_no,_Type,Salary) values('arslan','162836','123123856','123123',' ')

create table Warning
(
	CNIC varchar(50),
	cnt int
)

insert into Employee values('1234567890456','Usama','654654654','waiter',0);

insert into Waiter values('1234567890456',3)

create table [Food Item]
(
	name varchar(50) primary key,
	Price float,
	details varchar(50),
	units varchar(10),
	type varchar(30)
)

select * from [Food Item]

create table deals
(
	name varchar(50),
	price float,
	details varchar(50)
)

create table dealitems
(
	name varchar(50),
	fooditem varchar(50),
	quantity int
)

insert into Menu(Name,_Description,Price,_type) values('soufle','  ',200,'Appetizer')
select * from Menu

insert into Menu(Name,_Description,Price,_type) values('burger','zinger burger',250,'Appetizer')
insert into Menu(Name,_Description,Price,_type) values('bottle','coke',70,'Appetizer')
insert into Deal(name,price,food_id) values('Happy Meal',320,20)

insert into Menu(Name,_Description,Price,_type) values('burger','chicken burger',220,'Appetizer')
insert into Menu(Name,_Description,Price,_type) values('bottle','fanta',70,'Appetizer')
insert into Deal(name,price,food_id) values('Chicky Meal',290,21)

insert into deals(name,price,details) values('Happy Meal',330,'very delicious')
insert into dealitems(name,fooditem,quantity) values('Happy Meal','burger',1)
insert into dealitems(name,fooditem,quantity) values('Happy Meal','bottle',1)

insert into deals(name,price,details) values('Chicky Meal',390,'very delicious')
insert into dealitems(name,fooditem,quantity) values('Chicky Meal','burger',1)
insert into dealitems(name,fooditem,quantity) values('Chicky Meal','bottle',1)

insert into Warning('1234567890789',3)

insert into Employee(CNIC,Name,Phone_no,_Type,Salary) values('1234567890789','Usama Iftikhar','03001234567','waiter',100)
insert into Employee(CNIC,Name,Phone_no,_Type,Salary) values('1234567890745','Mudassir Talal','03001234578','chef',100)

insert into Warning values('1234567890789',3)
insert into Warning values('1234567890746',4)
