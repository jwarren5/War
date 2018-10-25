/**
	CS 231 Project 3
	deck.cpp
	Purpose: Implementation of the Deck class for the "War!" game.
	
	@author <insert your name here>
	@version 1.0
*/

#include <iostream>
#include <cstdlib>
#include "deck.h"

/**
    CONSTRUCTOR

    @param fill A boolean flag; a value of "true" will cause the deck to be filled with cards,
    and a value of "false" will leave it empty.
*/
Deck::Deck(bool fill) {
	
	size = 0;
	head = nullptr;

	const int NUM_RANKS = 13;
	const int NUM_SUITS = 4;
	
	/* If "fill" argument is TRUE, fill the deck; otherwise, leave it empty */
	
	if (fill) {
		
		/* Fill the deck with cards */
	
		Suit suits[] = { CLUB, DIAMOND, HEART, SPADE };
		char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
		
		Card *c;
		
		for ( int i = 0; i < NUM_RANKS; ++i ) {
				
			for ( int j = 0; j < NUM_SUITS; ++j ) {
				
				/* Create new cards by pairing up each suit with every rank */
				
				c = new Card(suits[j], ranks[i]);
				
				/* Insert new card at the end of the deck */
				
				insert_card(c);
					
			} // End inner for()
			
		} // End outer for()
		
	} // End if()
		
} // End constructor



/**
    Calls "draw_card()" to remove the first card from deck.
    
    @returns A pointer to the Card that has been removed from the deck.
*/
Card* Deck::draw_first_card() {
	
	return ( draw_card(0) );
	
}



/**
    Calls "draw_card()" to remove a randomly-selected card from the deck.
    
    @returns A pointer to the Card that has been removed from the deck.
*/
Card* Deck::draw_random_card() {
	
	/* If deck is empty, return a null pointer (avoids division by zero) */
	
	if ( !head ) {
		
		return 0;
		
	}
	
	/* If deck is not empty, select a random card to draw */
	
	else {
		
		return ( draw_card( rand() % size ) );
		
	}
	
}



/**
    Prints each card in the deck.
*/
void Deck::print_deck() {
	
	/* Initialize pointers */
	
	Card *current = head;
	
	/* Is deck empty?  If so, print a message */
	
	if ( !head ) {
		
		cout << "DECK EMPTY!\n";
		
	}
	
	/* If not, traverse the deck and print each card individually */
	
	else {
	
		while ( current ) {
			
			cout << ( current -> to_string() ) << '\n';
			current = current -> next;
			
		}
		
	}
	
}



/**
    Returns the current deck size (the number of cards in the deck).
    
    @returns An integer representing the size.
*/
int Deck::get_size() { return size; }



/**
    Insert the given card to the end (back) of the deck.
    
    @param c A pointer to the Card object which represents the new card to be added to the deck.
*/
void Deck::insert_card(Card* c) {
	
	/* Start at the beginning */
	
	Card* current = head;
	
	/* Sever any ties to the previous deck */
	
	c -> next = nullptr;
	
	/* Is this card the first one in the deck? */
	
	/* If so, point the Head pointer to this new card */
	
	if ( !head ) {
		
		head = c;
		current = head;
		
	}
	
	/* If not, follow the list of Cards to the end */
	
	else {
		
		while ( current -> next ) {
			
			current = current -> next;
			
		}
		
		current -> next = c;
		
	}
	
	++size;

}



/**
    Removes and returns the card at the specified position (offset) in the deck.
    
    @param offset An integer corresponding to the offset of the card that is to be removed.
    @returns A pointer to the Card that has been removed from the deck.
*/
Card* Deck::draw_card(int offset) {
	
	/* Card pointers */
	
	Card *current, *previous;
	
	/* Is deck empty? (Is head pointer null?) */
	/* If so, return a null pointer */

	if ( !head ) {
		
		cout << "DECK EMPTY!\n";
		return nullptr;
		
	} // end if()
	
	/* If deck is NOT empty, iterate through list until the card at the specified position (offset)
	/* is found, then remove the card from the deck and return a pointer to it */
	
	else if (offset > (size - 1)) {
		cerr << "NO SUCH CARD!";
		return nullptr;		
	}
	
	else if (offset == 0) {
		current = head;
		head = head -> next;	
	}
	
	else {
		
		current = head;
		previous = head;
		for (int i = 0; i < offset; ++i) {
			previous = current;
			current = current -> next;
		}
		previous -> next = current -> next;
		
	} // end else()
	current -> next = nullptr;
	--size;
	return current;
	
}



/**
    DESTRUCTOR
*/
Deck::~Deck() {
	
	/* Initialize pointers */
	
	Card *current = head, *previous = head;
	
	/* If the deck is already empty, there is nothing to do */
	
	if ( !head ) {
		
		return;
		
	} // end if()
	
	/* If the deck is not empty, traverse the deck, deleting each card */
	
	else {
	
		while ( current ) {
			
			previous = current;
			current = current -> next;
			delete previous;
			--size;
			
		} // End while()
		
	} // End else()
	
} // End destructor
