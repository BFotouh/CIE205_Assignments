#pragma once

using namespace std;

class Customer
{
	int ID, ArrTick, ServTicks, FinishTick, WaitTicks = 0;
public:
	Customer(int id, int ArrT, int serT);
	virtual ~Customer();

	// getters
	int GetID() const;
	int getArrTick() const;
	int getServTicks() const;
	int getFinishTick() const;
	int getWaitTicks() const;

	// setters
	void setID(int);
	void setArrTick(int);
	void setServTicks(int);
	void setFinishTick(int);
	void setWaitTicks(int);
};