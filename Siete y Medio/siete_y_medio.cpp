#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)
const int startingAmount = 100;
const int maxPayout = 900;

// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	srand(time(0)); //Set a random seed for later card generation.
	Player* p = new Player(startingAmount);


	while (p->getAmount() > 0 && p->getAmount() < startingAmount + maxPayout) {//Game betting loop
		cout << "You have $" << p->getAmount() << ". Enter bet: ";
		int bet = maxPayout + startingAmount; //Too high to get without winning, triggering for loop. 
		while (bet > p->getAmount() || bet <= 0) {
			cin >> bet;
			if (bet > p->getAmount() || bet <= 0) {
				cout << "\nYou have $" << p->getAmount() << " and that is an invalid amount, enter new bet: ";
			}
		}
		std::cout << "\nA valid bet of " << bet << " has been placed.\n";

	}



	//Single Test
	//Card* c = new Card();
	//cout << c->get_english_rank() << " " << c->get_english_suit() << endl << c->get_rank() << endl << c->get_spanish_rank() << " " << c->get_spanish_suit() << endl;
	//Multi Test
	//vector<Card*> hand;
	//hand.push_back(new Card());
	//hand.push_back(new Card());
	//hand.push_back(new Card());
	//for (auto x : hand) {
	//	cout << x->get_english_rank() << " " << x->get_english_suit() << endl;
	//}
	
	return 0;
}