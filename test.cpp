/**
	CS 231 Project 3
	test.cpp
	Purpose: A simple program to test the Card and Deck classes for the "War!" game.
	
	@author <insert your name here>
	@version 1.0
*/

#include <iostream>
#include <ctime>
#include "deck.h"

using namespace std;

int main(int argc, char** argv) {
	
	/* Seed pseudorandom number generator */
	
	srand( time(NULL) );
	
	/* Create new deck and card pointer */
	
	Deck d(true);
	Card *c;
	
	/* Print contents of new deck */
	
	cout << "Here are all the cards in our brand new (unshuffled) deck:\n\n";
	
	d.print_deck();
	
	/* Begin randomly drawing cards from deck */
	
	cout << "\n\nNext, let's randomly draw all 52 cards from the deck:\n\n";
	
	for ( int i = 0; i < 52; ++i ) {
		
		c = d.draw_random_card();										// Draw next card
		
		if (c) {														// If card exists,
			cout << (i + 1) << ": " << ( c -> to_string() ) << '\n';	// Print counter and card suit/rank
			delete c;													// Destroy card (to prevent memory leaks!)
		}
		
	}
	
	/* Print the contents of the deck again (you should see "DECK EMPTY!" here) */
	
	cout << "\n\nNow, let's try to re-print the deck (which should now be empty):\n\n";
	
	d.print_deck();
	
	/* EXIT */
	
	return 0;
	
}
