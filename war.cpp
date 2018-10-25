/**
	CS 231 Project 3
	war.cpp
	Purpose: Implementation of the game logic for the "War!" game.
	
	@author <insert your name here>
	@version 1.0
*/

#include <iostream>
#include <ctime>
#include "deck.h"

using namespace std;

/* FUNCTION PROTOTYPES */

void print_instructions();
int rank_to_value(char);

/* CONSTANT DEFINITIONS */

const int WINNING_COUNT = 52;

/* FUNCTION DEFINITIONS */

int main(int argc, char** argv) {
	
	/* Seed random number generator */
	
	srand( time(NULL) );
	
	/* Create full deck of cards */

	Deck source_deck(true);
	
	/* Create player and computer stacks (initially empty) */
	
	Deck player_stack(false);
	Deck computer_stack(false);
	
	/* Create empty player and computer "war stacks" (for cards dealt during war rounds) */
	
	Deck player_war_stack(false);
	Deck computer_war_stack(false);
	
	/* State variables */
	
	bool game_over = false;				// Main loop flag
	bool at_war = false;				// War loop flag
	
	int player_count = 0;				// Player's card count
	int computer_count = 0;				// Computer's card count
	
	int player_card_value = 0;			// Player's card value
	int computer_card_value = 0;		// Computer's card value
	char player_card_rank;				// Player's card rank
	char computer_card_rank;			// Computer's card rank
	
	int total_war_cards = 0;			// Total cards awarded to winner after war round
	
	Card *player_card, *computer_card;	// Card pointers
	char player_input;					// Player's input
	
	/* Randomly deal 26 cards to each player, resulting in two shuffled stacks */
	
	for (int i = 0; i < 26; ++i) {
		
		/* Draw card and add to player player's stack */
		
		player_card = source_deck.draw_random_card();
		player_stack.insert_card(player_card);
		
		/* Draw card and add to computer player's stack */
		
		computer_card = source_deck.draw_random_card();
		computer_stack.insert_card(computer_card);
		
	}
	
	/* Print greetings and instructions */
	
	print_instructions();
	
	/* MAIN LOOP */
	
	while ( !game_over ) {
		
		/* Prompt player for input */
		
		cout << "Enter (D) to deal or (Q) to quit: ";
		cin >> player_input;
		player_input = toupper(player_input);
		
		/* Did player choose "Q"?  If so, break out of main loop */
		
		if ( player_input == 'Q' ) {
			
			game_over = true;
			
		}
		
		/* If not, proceed to start a new round */
		
		else {
			
			/* Human and computer players each draw one card */
			
			player_card = player_stack.draw_first_card();
			computer_card = computer_stack.draw_first_card();
			
			/* Determine rank and corresponding value of each card */
			
			player_card_rank = ( player_card -> get_rank() );
			computer_card_rank = ( computer_card -> get_rank() );
			
			player_card_value = rank_to_value( player_card_rank );
			computer_card_value = rank_to_value( computer_card_rank );
			
			/* Show both cards */
			
			cout << "\nYour Card: " << ( player_card -> to_string() ) << '\n';
			cout << "Computer's Card: " << ( computer_card -> to_string() ) << "\n\n";
			
			/* Is player rank greater?  If so, add both cards to player's stack */
			
			if ( player_card_value > computer_card_value ) {
				
				cout << "You won this round!\n\n";
				player_stack.insert_card(player_card);
				player_stack.insert_card(computer_card);
				
			} // End if() (player wins round)
			
			/* Is computer rank greater?  If so, add both cards to computer's stack */
			
			else if ( computer_card_value > player_card_value ) {
				
				cout << "The computer won this round!\n\n";
				computer_stack.insert_card(computer_card);
				computer_stack.insert_card(player_card);
				
			} // End if() (computer wins round)
			
			/* If both ranks are equal, it's war! */
			
			else {
				
				/* Print war message */
	
				cout << "RANKS MATCH ... IT'S WAR!\n";
				cout << "Each player will now deal one card \"face down\" and one card \"face up.\"\n";
				cout << "If the ranks of the \"face-up\" cards are different, the player with the\n";
				cout << "highest rank gets ALL the cards; if the ranks are the same, another\n";
				cout << "pair of cards will be drawn.  We will now begin drawing the cards ...\n\n";
				at_war = true;
	
				/* Save previously dealt cards to players' war stacks */
				
				player_war_stack.insert_card(player_card);
				computer_war_stack.insert_card(computer_card);
				
				/* Main war loop */
				
				while ( at_war ) {
				
					/* Each player draws their first card, shown "face down" */
					
					player_card = player_stack.draw_first_card();
					computer_card = computer_stack.draw_first_card();
		
					cout << "Your First Card: <FACE DOWN>\n";
					cout << "Computer's' First Card: <FACE DOWN>\n\n";
					
					/* Add cards to war stacks */
					
					player_war_stack.insert_card(player_card);
					computer_war_stack.insert_card(computer_card);
					
					/* Each player draws their second card, shown "face up" */
					
					player_card = player_stack.draw_first_card();
					computer_card = computer_stack.draw_first_card();
					
					/* Show cards */
		
					cout << "Your Second Card: " << ( player_card -> to_string() ) << '\n';
					cout << "Computer's Second Card: " << ( computer_card -> to_string() ) << '\n';
					
					/* Add cards to war stacks */
					
					player_war_stack.insert_card(player_card);
					computer_war_stack.insert_card(computer_card);
					
					/* Get and compare ranks of second cards */
					
					player_card_rank = ( player_card -> get_rank() );
					computer_card_rank = ( computer_card -> get_rank() );
					
					player_card_value = rank_to_value( player_card_rank );
					computer_card_value = rank_to_value( computer_card_rank );
					
					/* Are their ranks different?  If so, break out of war loop */
					
					if ( player_card_value != computer_card_value ) {
						
						at_war = false;
						
					}
					
					/* If the same, print a message and repeat the loop */
					
					else {
						
						cout << "\nRanks match, drawing another pair of cards ...\n\n";
						
					}
				
				} // End while()
				
				/* Get total number of cards to be given to the winner */
				
				total_war_cards = player_war_stack.get_size() + computer_war_stack.get_size();
				
				/* Does the player get the cards? */
				
				if ( player_card_value > computer_card_value ) {
					
					cout << "\nCongratulations, you get all " << total_war_cards << " cards!\n\n";
					
					/* Draw all cards from player's war stack, adding each to player's main stack */
					
					for (int i = player_war_stack.get_size(); i > 0; --i) {
						
						player_card = player_war_stack.draw_first_card();
						player_stack.insert_card(player_card);
						
					}
					
					/* Draw all cards from computer's war stack, adding each to player's main stack */
					
					for (int i = computer_war_stack.get_size(); i > 0; --i) {
						
						computer_card = computer_war_stack.draw_first_card();
						player_stack.insert_card(computer_card);
						
					}
					
				} // End if()
				
				/* Does the computer get the cards? */
				
				if ( computer_card_value > player_card_value ) {
					
					cout << "\nToo bad, the computer gets all " << total_war_cards << " cards!\n\n";
					
					/* Draw all cards from computer's war stack, adding each to computer's main stack */
					
					for (int i = computer_war_stack.get_size(); i > 0; --i) {
						
						computer_card = computer_war_stack.draw_first_card();
						computer_stack.insert_card(computer_card);
						
					}
					
					/* Draw all cards from player's war stack, adding each to computer's main stack */
					
					for (int i = player_war_stack.get_size(); i > 0; --i) {
						
						player_card = player_war_stack.draw_first_card();
						computer_stack.insert_card(player_card);
						
					}
					
				} // End if()
				
			} // End if() (war)
			
			/* Print end-of-round counts */
			
			player_count = player_stack.get_size();
			computer_count = computer_stack.get_size();
			
			cout << "Your Count: " << player_count << '\n';
			cout << "Computer Count: " << computer_count << "\n\n\n";
			
			/* Check to see if player or computer has won the game */
			
			if ( (player_count == WINNING_COUNT) || (computer_count == WINNING_COUNT) ) {
				
				game_over = true;
				
			}
			
		} // End else()
		
	} // End while() (main loop)
	
	/* Game is over; print final counts and exit */
	
	cout << "\nGAME OVER!  Here are your final counts:\n\n";
	
	player_count = player_stack.get_size();
	computer_count = computer_stack.get_size();
	
	cout << "Your Final Count: " << player_count << '\n';
	cout << "Computer Final Count: " << computer_count << "\n\n";
	
	cout << "Thanks for playing!\n";

} // End main()



/**
    Converts a card's rank to the corresponding numeric value;
	allows cards to be compared quantitatively.
    
    @param ranks A char representing the card's rank
    @returns An integer value corresponding to the card's rank:
	
	'2' through '9': returns the corresponding numeric value,
	'T': returns 10,
	'J': returns 11,
	'Q': returns 12,
	'K': returns 13,
	'A': returns 14
*/
int rank_to_value(char rank) {
	
	int value = 0;
	
	switch (rank) {
		
		case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			value = rank - '0'; // 2-9
			break;
		case 'T':				// T(10)
			value = 10;
			break;
		case 'J':				// J = 11
			value = 11;
			break;
		case 'Q':				// Q = 12
			value = 12;
			break;
		case 'K':				// K = 13
			value = 13;
			break;
		case 'A':				// A = 14
			value = 14;
		
	}
	
	return value;
	
}



/**
    Prints greetings and game instructions
*/
void print_instructions() {
	
	cout << "Welcome to WAR, the ultimate one-on-one card game!\n\n";

	cout << "The goal of this game is to be the first player to win all 52 cards.  At\n";
	cout << "the start of the game, the deck is divided evenly, with each player,\n";
	cout << "human and computer, receiving 26 cards.  The ranking of the cards, from\n";
	cout << "highest to lowest, is as follows:\n\n";

	cout << "A K Q J T(10) 9 8 7 6 5 4 3 2\n\n";

	cout << "At the start of each round, both players turn up one card at the same\n";
	cout << "time.  The player with the higher card takes both cards and moves them\n";
	cout << "to the bottom of their stack.\n\n";

	cout << "If the cards are the same rank ... it's War!  Each player turns up two\n";
	cout << "more cards, one \"face down\" (hidden) and one \"face up\" (revealed).  The\n";
	cout << "player with the higher card takes both piles (six cards).  If the turned-\n";
	cout << "up cards are again the same rank, the process is repeated, with each\n";
	cout << "player turning up two more cards in the same way.  The player with the\n";
	cout << "higher card takes all 10 cards, and so on.\n\n";

	cout << "The game is over when one player has won all 52 cards.\n\n";
	
}
