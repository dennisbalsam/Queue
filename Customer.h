#ifndef CUSTOMER
#define CUSTOMER

//Customer Class
class Customer {
	private:
		//What time they arrived
		int arrivaltime;
		//What number customer they are
		int customernumber;


	public:
		//Default constructor
		Customer();
		//Constructor with arrival time
		Customer(int arrival, int Customernumber);
		//Returns arrival time
		int GetArrivalTime();
		//Returns what customer number they are
		int GetCustomerNumber();
};

//Default constructor
Customer::Customer() : arrivaltime(0),customernumber(0),departuretime(0)
{
	//Empty on purpose
}


//Constructor with arrival time
Customer::Customer(int arrival, int Customernumber): arrivaltime(arrival), customernumber(Customernumber)
{
	//Empty on purpose
}


//Returns arrival time
int Customer::GetArrivalTime()
{
	return arrivaltime;
}

//Returns what customer number they are
int Customer::GetCustomerNumber()
{
	return customernumber;
}


#endif
