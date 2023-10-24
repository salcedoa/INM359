#include <iostream>
#include <exception>
#include <string>
#include <vector>

// Week 2
class Account {

private:
	std::string name;
	double balance;
public:
	// account(string n) : name(n) balance(0) {}
	Account(std::string n, double b = 0); 

  // Name getter method
	std::string get_name() const {
    return name;
  }
	
	// Balance getter method
  double get_balance() const {
  	return balance;
  }
	
	// Method to deposit an amount to balance
  void deposit(double amount) {
    balance += amount;
  }

	// Withdraw from balance
  void withdraw(double amount) {
    if (balance - amount < 0) {
      throw std::runtime_error("Not enough funds");
    } else {
      balance -= amount;
    }
  }
};

// Constructor defined outside of class
Account::Account(std::string n, double b) : name(n), balance(b) {
	if (n == "" || balance < 0) {
		throw std::runtime_error("account(): invalid parameters");
	};
};

// Bank class - Exercise 4/6
class Bank {
private:
	std::vector<Account> account_list;

public:
	void add_account(Account a) {
		account_list.push_back(a);
	}

	void print_accounts() {
		
		std::cout << "\nBank Statements ==================================" << "\n";
		
		for (int i = 0, size = account_list.size(); i < size; i++) {	
			std::cout << "Name:\t\t" << account_list[i].get_name()  << "\n";
			std::cout << "Balance:\t" << account_list[i].get_balance()  << "\n\n";
		}
	}

	void deposit(std::string name, double amount) {
		// Search through all onjects in the vector
		for (int i = 0, size = account_list.size(); i < size; i++) {
			if (account_list[i].get_name() == name) {
				account_list[i].deposit(amount);
			}
		}
	}

	void withdraw(std::string name, double amount) {
		// Search through all onjects in the vector
		for (int i = 0, size = account_list.size(); i < size; i++) {
			if (account_list[i].get_name() == name) {
				account_list[i].withdraw(amount);
			}
		}
	}

	void add_interest(double rate) {
		for (int i = 0, size = account_list.size(); i < size; i++) {
			double added_value = account_list[i].get_balance() * (rate / 100.0);
			account_list[i].deposit(added_value);
		}
	}

};

int main() {
	
  // Create account object
	Account x("Bob", 40.0);
  
	// Print outputs
  std::cout << "Account Name\t" << x.get_name()  << std::endl; 
	std::cout << "Balance:\t"  <<  x.get_balance()  << std::endl;
	
	// Use withdraw and deposit money
	x.deposit(20);
	x.withdraw(5);

	// Test again after operations
	std::cout << "\n";
	std::cout << "Account Name\t" << x.get_name() << std::endl; 
	std::cout << "Balance:\t"  << x.get_balance() << std::endl;
	
	// Exercise 4: Bank class test
	Account y("Steve");
	Account z("Mary", 78.0);

	Bank barclays;
	barclays.add_account(x);
	barclays.add_account(y);
	barclays.add_account(z);
	barclays.print_accounts();
	
	// Exercise 5: Bank methods test
	barclays.withdraw("Mary",10.0);
	barclays.deposit("Steve", 10.0);
	barclays.print_accounts();
	
	// Exercise 6: Interest method test
	barclays.add_interest(3.5);
	barclays.print_accounts();

	return 0;
}
