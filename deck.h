/**
	CS 231 Project 3
	deck.h
	Purpose: Header for the Deck class for the "War!" game.
	
	@author <insert your name here>
	@version 1.0
*/

#include "card.h"

/* DATA TYPE DEFINITIONS */

class Deck {
	
	public:
		
		/**
		    CONSTRUCTOR
		
		    @param fill A boolean flag; "true" will cause the deck to be filled with cards,
		    and "false" will leave it empty.
		*/
		Deck(bool);						// CONSTRUCTOR



		/**
		    Calls "draw_card()" to remove the first card from deck.
		    
		    @returns A pointer to the Card that has been removed from the deck.
		*/
		Card* draw_first_card();		// Draw/remove the first card from deck



		/**
		    Calls "draw_card()" to remove a randomly-selected card from the deck.
		    
		    @returns A pointer to the Card that has been removed from the deck.
		*/
		Card* draw_random_card();		// Draw/remove a random card from the deck

		

		/**
		    Insert the given card to the end (back) of the deck.
		    
		    @param c A pointer to the Card object which represents the card to be added to the deck.
		*/
		void insert_card(Card*);		// Insert card at the end of the deck



		/**
		    Prints each card in the deck.
		*/
		void print_deck();				// Prints cards in deck



		/**
		    Returns the current deck size (the number of cards in the deck).
		    
		    @returns An integer representing the size.
		*/
		int get_size();					// Returns number of cards in deck
		


		/**
		    DESTRUCTOR
		*/
		~Deck();						// DESTRUCTOR		
		
		
		
	private:
		
		/**
		    Removes and returns the card at the specified position (offset) in the deck.
		    
		    @param offset An integer corresponding to the offset of the card that is to be removed.
		    @returns A pointer to the Card that has been removed from the deck.
		*/
		Card* draw_card(int);			// Draw/remove specified card from deck
		
		
		
		int size;						// Number of cards in the deck
		Card* head;						// Pointer to first card in the deck
   
};
