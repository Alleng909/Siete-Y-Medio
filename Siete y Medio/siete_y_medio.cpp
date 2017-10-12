#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	srand(time(0));
	//Single Test
	Card* c = new Card();
	cout << c->get_english_rank() << " " << c->get_english_suit() << endl << c->get_rank() << endl << c->get_spanish_rank() << " " << c->get_spanish_suit() << endl;
	//Multi Test
	vector<Card*> hand;
	hand.push_back(new Card());
	hand.push_back(new Card());
	hand.push_back(new Card());
	for (auto x : hand) {
		cout << x->get_english_rank() << " " << x->get_english_suit() << endl;
	}
	
	return 0;
}