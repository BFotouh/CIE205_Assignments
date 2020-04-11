#include "Customer.h"

Customer::Customer(int id, int ArrT, int serT)
{
	ID = id;
	ArrTick = ArrT;
	ServTicks = serT;
}

Customer::~Customer()
{
}

int Customer::GetID() const
{
	return ID;
}

int Customer::getArrTick() const
{
	return ArrTick;
}

int Customer::getServTicks() const
{
	return ServTicks;
}

int Customer::getFinishTick() const
{
	return FinishTick;
}

int Customer::getWaitTicks() const
{
	return WaitTicks;
}

void Customer::setID(int id)
{
	ID = id;
}

void Customer::setArrTick(int at)
{
	ArrTick = at;
}

void Customer::setServTicks(int st)
{
	ServTicks = st;
}

void Customer::setFinishTick(int ft)
{
	FinishTick = ft;
}

void Customer::setWaitTicks(int wt)
{
	WaitTicks = wt;
}
