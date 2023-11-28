#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Pet {
protected:
	string _name;
public:
	Pet(string name) : _name(name) {}
	virtual string sound() const = 0;
	virtual void speak() const {
		cout << _name << ": " << sound() << "!\n";
	}
};

class Dog : public Pet {
public:
	Dog(string name) : Pet(name) {}
	virtual string sound() const { return "woof"; }
	
	// Exercise 2
	virtual void speak() const;
	/* virtual void speak() const {
		Pet::speak();
		cout << '(' << _name << " wags tail)\n";
	} */
};

// Exercise 2
// Move the speak function outside of dog
void Dog::speak() const {
	Pet::speak();
	cout << '(' << _name << " wags tail)\n";
}

class Dalmatian : public Dog {
	int _spots;
public:
	Dalmatian(string name, int spots) :
		Dog(name), _spots(spots) {}
	
	// Exercise 4
	// Redefine the speak method
	virtual void speak() const {
		Pet::speak();
		cout << _name << " has " << _spots << " spots." << endl;
	}
};

class Cat : public Pet {
public:
	Cat(string name) : Pet(name) {}
	virtual string sound() const { return "miao"; }
};

void speakTwice(const Pet &pet) {
	pet.speak();
	pet.speak();
}

// Exercise 1
// Create main function and compile
int main() {
	// Exercise 3
	// Try declaring a variable of type pet, this is not allowed as it's an abstract class
	// Pet x;

	Dog steve("Steve");
	steve.speak();

	Dalmatian joe("Joe", 4);
	joe.speak();

	// Exercise 5
	// Copy a Dalmation object into a Dog object and call speak()
	// It resutls in the Dog version instead of the Dalmation version
	Dog dog_joe = joe;
	dog_joe.speak();

	// Exercise 6
	// Create a vector of Pet pointers and make them all call speak()
	Cat fred("Fred");
	vector<Pet *> pets;
	pets.push_back(&steve);
	pets.push_back(&joe);
	pets.push_back(&fred);

	for (int i = 0; i != pets.size(); ++i) {
		pets[i]->speak();
	}

	// Exercise 7
	// Repeat Ex 6 but use a list and an interator to traverse it.
	list<Pet *> pets_list;
	pets_list.push_back(&steve);
	pets_list.push_back(&joe);
	pets_list.push_back(&fred);
	for (auto p = pets_list.begin(); p != pets_list.end(); ++p) {
		(*p)->speak();
	}

	return 0;
}
