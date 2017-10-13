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
void deal(Hand* h);

// Non member functions implementations (if any)
void deal(Hand* h) {
	Card* freshlyDealt = new Card();
	cout << "New card:\n";
	h->add(freshlyDealt);
	freshlyDealt->print();
	return;
}

// Stub for main
int main() {
	srand(time(0)); //Set a random seed for later card generation.
	Player* p = new Player(startingAmount);


	while (p->getAmount() > 0 && p->getAmount() < startingAmount + maxPayout) {//Game betting loop
		
		//Taking valid user input
		cout << "You have $" << p->getAmount() << ". Enter bet: ";
		int bet = maxPayout + startingAmount; //Too high to get without winning, triggering for loop. 
		while (bet > p->getAmount() || bet <= 0) {
			cin >> bet;
			if (bet > p->getAmount() || bet <= 0) {
				cout << "\nYou have $" << p->getAmount() << " and that is an invalid amount, enter new bet: ";
			}
		}
		
		//Playing cards.
		Hand* pHand = new Hand();
		Hand* dHand = new Hand();
		pHand->add(new Card());
		cout << "Your cards:\n";
		pHand->print();
		string cardRequest = "y";
		while (cardRequest == "y") { //Player's turn
			cout << "Your total is " << pHand->getTotal() << ". Do you want another card (y/n)? ";
			cin >> cardRequest;
			if (cardRequest == "y") {
				deal(pHand);
				cout << "\nYour cards:\n";
				pHand->print();
				if (pHand->getTotal() > 7.5) {
					cout << "You busted with " << pHand->getTotal() << ".\nToo bad. You lose " << bet << ".\n";
					p->add(-bet);
					break;
				}
			}
		}

		if (pHand->getTotal() <= 7.5) { //Dealer's turn.
			dHand->add(new Card());
			cout << "Dealer's cards:\n";
			dHand->print();
			while (dHand->getTotal() < 5.5) {
				cout << "The dealer's total is " << dHand->getTotal() << ".\n";
				deal(dHand);
				cout << "Dealer's cards:\n";
				dHand->print();
			}
			cout << "The dealer's total is " << dHand->getTotal() << ".\n";
		}
	}
	
	return 0;
}