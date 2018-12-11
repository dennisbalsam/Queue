//Include Headers
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ArrayQueue.h"
#include "Customer.h"
#include "Teller.h"
#include <time.h> 

using namespace std;

//Driver
int main()
{

	ArrayQueue<Customer> Line;
	Teller Server; 
	Customer CurrentCustomer;
	int Customernumber = 0;
	int totalwaittime = 0;
	int unabletoserve = 0;
	double  averagewaittime = 0.0;
	int currentcustomerarrival = 0;
	//srand(time(0));
	for (int Currentime = 1; Currentime <= 100; Currentime++)
	{
		if (Currentime == 100)
		{
			cout << "The bank is now closing, please come back tomorrow " << endl;
			cout << "The customer at the server will be the last customer" << endl;
			CurrentCustomer = Line.peekFront();
			currentcustomerarrival = CurrentCustomer.GetArrivalTime();
			totalwaittime += Currentime - currentcustomerarrival;
			while (Line.isEmpty() == false)
			{
				Line.dequeue();
				unabletoserve++;
			}
			cout << unabletoserve << " Customers were not served " << endl;
		}
		else {
			cout << "The time is " << Currentime << endl;
			if ((float(rand()) / float(RAND_MAX)) <= 0.2)
			{
				Customernumber++;
				Line.enqueue(Customer(Currentime, Customernumber));
				cout << "Arrival time of the new customer was: " << Currentime << " ,they are customer number " << Customernumber << endl;
			}

			if (Server.GetTellerStatus() == true)
			{
				if (Line.isEmpty() != true)
				{

					CurrentCustomer = Line.peekFront();
					currentcustomerarrival = CurrentCustomer.GetArrivalTime();

					cout << "Teller is Free, Please come to the window " << endl;
					cout << "Customer number " << CurrentCustomer.GetCustomerNumber() << " Is approaching the window" << endl;
					cout << "The current customer waited " << Currentime - currentcustomerarrival << " minutes" << endl;
					totalwaittime += Currentime - currentcustomerarrival;
					currentcustomerarrival = CurrentCustomer.GetArrivalTime();
					Line.dequeue();
					Server.TellerIsNotFree();
					cout << "The remaining transaction time is: " << Server.TransactionDuration() << endl;
					cout << endl;


				}
			}
			else
			{

				Server.DecrementTranscationTime();
				cout << "The remaining transaction duration of the current customer is: " << Server.TransactionDuration() << " minutes" << endl;
				cout << endl;
				if (Server.TransactionDuration() == 1)
				{
					Server.ResetTransactionTime();
					Server.TellerIsFree();
				}
			}
		}
	
	}
	cout << (Customernumber - unabletoserve) << " customers were served today" << endl;
	averagewaittime = totalwaittime / (Customernumber - unabletoserve); 
	cout << endl;
	cout << "The average wait time between all the customers was: " << averagewaittime << " minutes" << endl;
	system("pause");
	return 0;

}