/**
	CS 231 Project 3
	card.h
	Purpose: Header for the Card class for the "War!" game.
	
	@author <insert your name here>
	@version 1.0
*/

#include <string>

using namespace std;

/* DATA TYPE DEFINITIONS */

enum Suit { CLUB, DIAMOND, HEART, SPADE };

class Card {
	
	public:
		
		/**
		    CONSTRUCTOR
		
		    @param a The Suit for the new card
		    @param r The rank for the new card
		*/
		Card(Suit, char);		// CONSTRUCTOR
		
		
		
		/**
		    Return card suit/rank as a printable string
		    
		    @returns A string representing the card's suit and rank, in the format "RANK/SUIT"
		*/
		string to_string();		// Returns card's suit/rank as a printable string



		/**
		    Return the card's rank
		    
		    @returns A char value corresponding to the card's rank
		*/
		char get_rank();		// Returns rank



		/**
		    Return the card's Suit
		    
		    @returns A Suit value corresponding to the card's suit
		*/
		Suit get_suit();		// Returns suit



		Card* next;				// Pointer to next card in the deck	
		
	private:
		
		char rank;				// Card's rank
		Suit suit;				// Card's suit
   
};
