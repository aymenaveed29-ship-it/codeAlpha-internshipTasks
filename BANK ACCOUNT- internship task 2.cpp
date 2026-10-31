#include <iostream>
#include <string>
//to store & maintain multiple transactions (container)
#include <vector>
using namespace std;

class customer {
	private:
		int customerId;
		string customerName;
		double customerPhoneNum;
	
	public:
		customer() {}
		//cunstructor
		customer (int customerId, string customerName, double CustomerPhoneNum) {
			this->customerId = customerId;
			this->customerName = customerName;
			this->customerPhoneNum = customerPhoneNum;
		}
};

class transaction {
	private:
		int transactionId;
		string transactionType;
		double transactionAmount;
		string transactionDetails;
	public:
		transaction (int transactionId, string transactionType, double transactionAmount, string transactionDetails) {
			this->transactionId = transactionId;
			this->transactionType = transactionType;
			this->transactionAmount = transactionAmount;
			this->transactionDetails = transactionDetails;
		}
		
		void displayTransaction() {
			//first transaction
			cout <<"==========TRNSACTION HISTORY==========="<<endl;
			cout <<"Transaction Id: " << transactionId << endl;
			cout <<"Transaction Type: " << transactionType <<endl;
			cout <<"Transaction Amount: " << transactionAmount <<endl;
			cout <<"Transaction Details: " << transactionDetails <<endl;
		}
};

class account {
	private:
		int accountNumber;
		double accountBalance;
		int transactionCounter=1;
		//complete customer object-connection 
		customer accountOwner;
		//to store & maintain of multiple transactions 
		vector<transaction> transactions;
	public:
		account(int accountNumber, double accountBalance, customer accountOwner) {
			this->accountNumber = accountNumber;
			this->accountBalance = accountBalance;
			this->accountOwner = accountOwner;
	}
			//function
		void displayAccount() 
		{
			cout << "========= BANKING SYSTEM ==========" <<endl;
			cout <<"Account Number: " << accountNumber <<endl;
			cout <<"Current Account Balance: " <<accountBalance <<endl;
		}
		
		void deposit (double amount) {
			if (amount > 0) {
				accountBalance = accountBalance + amount;
				
				transaction t1(transactionCounter, "Deposit", amount, "Money deposited");
				transactions.push_back(t1);
				transactionCounter++;
				
				cout <<"Deposit Successfull! " <<endl;
				cout <<"Updated amount: " << accountBalance <<endl;
			} 
			else {
				cout <<"Invalid deposit amount! " <<endl;
			}
		}
		
		void withDraw(double amount) {
			if (amount <= 0) {
				cout <<"Invalid withdrawl amount! " <<endl;
			} 
			else if (amount>accountBalance) {
				cout <<"Insufficeint balance for withdrawl ";
			}
			else {
				accountBalance = accountBalance - amount;
				//both deposits and withdrawals share the same counter.
				transaction t1(transactionCounter, "Withdrawal", amount, "Money withdrawn");
                transactions.push_back(t1);
                transactionCounter++;
                
                cout << "Withdrawal successful!" << endl;
				cout << "Updated Account Balance after withdrawl: " << accountBalance <<endl;
			}
			
		}
		//display all transaction
		void displayTransactionHistory() {
        cout << "\n--- Transaction History ---" << endl;

      for (int i = 0; i < transactions.size(); i++) {
      	//function call
        transactions[i].displayTransaction();
    }
   }

};


int main () {
	double amount;
	//object creation
	customer c1(101, "Ali", 03064500412);
	account a1(123, 20000, c1);
	a1.displayAccount();
	
	cout <<"Enter the amount you want to deposit: ";
	cin >> amount;
	a1.deposit(amount);
	cout <<"Enter the amount you want to withdraw: ";
	cin >> amount;
	a1.withDraw(amount);
	a1.displayTransactionHistory();
	
}
