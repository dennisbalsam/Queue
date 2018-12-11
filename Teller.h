#ifndef TELLER
#define TELLER

//Teller Class
class Teller {
	private:
		//Whether the teller is free or not
		bool available;
		//How long the transaction has gone
		int transactiontime;
	public:
		//Default constructor
		Teller();
		//Returns whether the teller is free or not
		bool GetTellerStatus();
		//Changes the bool when teller is free
		void TellerIsFree();
		//Changes the bool when teller is not free
		void TellerIsNotFree();
		//Returns how long the transaction has gone
		int TransactionDuration();
		//Increments transaction time
		void DecrementTranscationTime();
		//Resets transaction time
		void ResetTransactionTime();
};
//Defualt constructor
Teller::Teller() : available(true), transactiontime(6)
{
	//Empty on purpose
}

//Returns if the teller is free or not
bool Teller::GetTellerStatus()
{
	return available;
}
//Returns how long the transaction has gone so far
int Teller::TransactionDuration()
{
	return transactiontime;
}
//Increments the time of the transaction
void Teller::DecrementTranscationTime()
{
	transactiontime--;
}
//Changes the bool of the teller to true
void Teller::TellerIsFree()
{
	available = true;
}
//Changes the bool of the teller to false
void Teller::TellerIsNotFree()
{
		available = false;
}

//Resets transaction time
void Teller::ResetTransactionTime()
{
	transactiontime = 6;
}
#endif