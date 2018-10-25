/**
	CS 231 Project 3
	card.cpp
	Purpose: Implementation of the Card class for the "War!" game.
	
	@author <insert your name here>
	@version 1.0
*/

#include <stdexcept>
#include "card.h"

/**
    CONSTRUCTOR

    @param s The Suit for the new card
    @param r The rank for the new card
*/
Card::Card(Suit s, char r) {
	
	next = nullptr;
	suit = s;
	
	/* Validate Rank */
	
	switch( r ) {
		
		case 'A': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': case 'T':
		case 'J': case 'Q': case 'K':
			rank = r;
			break;
		default:
			throw runtime_error("ERROR: Bad Card Constructor Argument!");
			
	}
	
}


/**
    Return card suit/rank as a printable string
    
    @returns A string representing the card's suit and rank, in the format "RANK/SUIT"
*/
string Card::to_string() {
	
	string s = "";
	
	s += rank;
	s += '/';
	
	switch( suit ) {
		
		case CLUB:
			s += "CLUB";
			break;
		case DIAMOND:
			s += "DIAMOND";
			break;
		case HEART:
			s += "HEART";
			break;
		case SPADE:
			s += "SPADE";
			break;
			
	}

	return s;
	
}


/**
    Return the card's rank
    
    @returns A char value corresponding to the card's rank
*/
char Card::get_rank() { return rank; }


/**
    Return the card's Suit
    
    @returns A Suit value corresponding to the card's suit
*/
Suit Card::get_suit() { return suit; }
