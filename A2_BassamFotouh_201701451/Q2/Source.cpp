#include <iostream>
#include <iomanip>
#include "Classes/Queue.h"
#include "Customer.h"

using namespace std;

void EnterParameters(int& qsp, int& pca, int& mtd, int& sd, int& rs);
void QueueSimulate(int qsp, int pca, int mtd, int sd, int rs, int& wc, int& avr_wt, int& long_wt, int& rc);
void PrintStat(int& wc, int& avr_wt, int& long_wt, int& rc);

int main(void)
{
	int qspairs, prop_Carrives, max_transd, sim_dur, rand_seed;
	int waitingCustomer, avr_waitingtime, lng_waitingtime, rem_customer;

	// prompting the user for inputs and initializing variables
	EnterParameters(qspairs, prop_Carrives, max_transd, sim_dur, rand_seed);

	// Queue Simulation
	QueueSimulate(qspairs, prop_Carrives, max_transd, sim_dur, rand_seed, waitingCustomer, avr_waitingtime, lng_waitingtime, rem_customer);

	// print Output statistics
	PrintStat(waitingCustomer, avr_waitingtime, lng_waitingtime, rem_customer);
}

void EnterParameters(int& qsp, int& pca, int& mtd, int& sd, int& rs)
{
	cout << "Enter these parameters of the simulation: " << endl;
	do
	{
		cout << "The number of queue/server pairs: ";
		cin >> qsp;
	} while (!(qsp < 10 && qsp > 1));
	do
	{
		cout << "The probability that a customer arrives in one tick (%): ";
		cin >> pca;
	} while (pca > 100 || pca < 0);
	cout << "The maximum duration of a transaction in ticks: ";
	cin >> mtd;
	cout << "The duration of the simulation in ticks: ";
	cin >> sd;
	cout << "Enter a random number seed: ";
	cin >> rs;
}

void QueueSimulate(int qsp, int pca, int mtd, int sd, int rs, int& wc, int& avr_wt, int& long_wt, int& rc)
{
	// build the customer queues
	Queue<Customer*>* CustArr = new Queue<Customer*>[qsp];

	srand(rs);
	int CurrentTickStep = 1, TotalCusts = 0, srvdCusts = 0, leftCusts = 0, totalWait = 0, longWait = 0;
	while (CurrentTickStep <= sd)
	{
		int minSize = CustArr[0].size();
		Queue<Customer*>* minQueue = &CustArr[0];
		for (int i = 1; i < qsp; i++)
		{
			if (minSize > CustArr[i].size())
			{
				minSize = CustArr[i].size();
				minQueue = &CustArr[i];
			}
		}

		int prob = rand() % 100;
		if (prob <= pca)
		{
			int st = 1 + rand() % mtd;
			Customer* cust = new Customer(TotalCusts + 1, CurrentTickStep, st);
			minQueue->enqueue(cust);
			TotalCusts++;
		}

		// dequeue for the lists
		for (int i = 0; i < qsp; i++)
		{
			if (!CustArr[i].isEmpty())
			{
				Customer* cust;
				CustArr[i].peekFront(cust);
				if (CurrentTickStep - cust->getFinishTick()>0)
				{
					CustArr[i].dequeue(cust);
				}
				CustArr[i].peekFront(cust);
				if (CurrentTickStep >= cust->getArrTick() + cust->getServTicks() + cust->getWaitTicks())
				{
					cust->setFinishTick(CurrentTickStep);
					srvdCusts++;
					totalWait += cust->getWaitTicks();
					if (longWait < cust->getWaitTicks())
					{
						longWait = cust->getWaitTicks();
					}
				}
				else
				{
					Queue<Customer*> tempQ;
					CustArr[i].dequeue(cust);
					cust->setFinishTick(cust->getArrTick() + cust->getServTicks() + cust->getWaitTicks());
					tempQ.enqueue(cust);

					while (CustArr[i].dequeue(cust))
					{
						cust->setWaitTicks(cust->getWaitTicks() + 1);
						tempQ.enqueue(cust);
					}
					while (tempQ.dequeue(cust))
					{
						CustArr[i].enqueue(cust);
					}
				}
			}
		}

		// printing at each tick
		cout << setw(3) << CurrentTickStep;
		Customer* cust = nullptr;
		if (CustArr[0].peekFront(cust))
		{
			cout << setw(4) << abs(CurrentTickStep - cust->getFinishTick()) << "   ";
		}
		else
		{
			cout << setw(4) << "0" << "   ";
		}
		int size;
		Customer** CustArrDraw = CustArr[0].toArray(size);
		for (int j = 0; j < size; j++)
		{
			cout << setw(4) << CustArrDraw[j]->getArrTick() << " ";
		}
		cout << endl;

		for (int i = 1; i < qsp; i++)
		{
			Customer* cust = nullptr;
			if (CustArr[i].peekFront(cust))
			{
				cout << "   " << setw(4) << abs(CurrentTickStep - cust->getFinishTick()) << "   ";
			}
			else
			{
				cout << "   " << setw(4) << "0" << "   ";
			}
			int size;
			Customer** CustArrDraw = CustArr[i].toArray(size);
			for (int j = 0; j < size; j++)
			{
				cout << setw(4) << CustArrDraw[j]->getArrTick() << " ";
			}
			cout << endl;
		}
		CurrentTickStep++;
	}
	for (int i = 0; i < qsp; i++)
	{
		Customer* cust;
		while (CustArr[i].dequeue(cust))
		{
			leftCusts++;
		}
	}
	wc = srvdCusts;
	avr_wt = totalWait / srvdCusts;
	long_wt = longWait;
	rc = leftCusts;
}

void PrintStat(int& wc, int& avr_wt, int& long_wt, int& rc)
{
	cout << "\n" << wc <<" customers waited an average of " << avr_wt <<" ticks.";
	cout << "\nThe longest time a customer waited was " << long_wt <<" ticks.";
	cout << "\n" << rc << " customers remain in the lines";
}
