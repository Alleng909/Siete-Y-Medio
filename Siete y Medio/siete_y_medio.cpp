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
			while (!(cin >> bet)) {
				cin.clear();
				cin.ignore();
			}
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

		//Comparison logic.
		if (pHand->getTotal() > 7.5) {
			cout << "\nYou busted with " << pHand->getTotal() << ".\nToo bad. You lose " << bet << ".\n";
			p->add(-bet);
		}
		else if (dHand->getTotal() > 7.5) {
			cout << "\nYou win " << bet << ".\n";
			p->add(bet);
		}
		else if (dHand->getTotal() > pHand->getTotal()) {
			cout << "\nToo bad. You lose " << bet << ".\n";
			p->add(-bet);
		}
		else if (pHand->getTotal() > dHand->getTotal()) {
			cout << "\nYou win " << bet << ".\n";
			p->add(bet);
		}
		else {
			cout << "\nNobody wins!\n";
		}
	}

	//Ending line
	if (p->getAmount() == 0) {
		cout << "\nYou have $0. GAME OVER!\nCome back when you have more money.\n\nBye!\n";
	}
	else if (p->getAmount() >= startingAmount + maxPayout) {
		cout << "\nCongratulations. You beat the casino with $" << p->getAmount() << ".\n\nNow shoo!\n";
	}
	else {
		cout << "\nYou ended the game prematurely somehow? Congrats on getting this message, now what did you do?";
	}
	
	return 0;
}