/**
 * Author: Arnold Gihozo
 * Class: AUCSC 370
 * Date Created: September 25, 2020
 * Date Last Modified: October 2, 2020
 *
 * Description:
 *  This file contains an overview of the functions within main.c file. These functions are made
 *  in order to make a Rock, Paper, Scissor game.
 *
*/

#ifndef GAME_HEADER_H
#define GAME_HEADER_H


typedef enum{          
    False, True
}
boolean;

typedef enum {
    Rock, Paper, Scissor, None
}
element;
/**
 * Asks for a user input, checks if
 */
int gameRound();

/**
 * Prints a welcome message at the very begining of the game
 */
void welcomeMessage();

/**
 * Displays the input put in by the player or computer
 * @param chosenElement -- can be either "rock,paper or scissor"
 */
void displayInput(int chosenElement);

/**
 * Computer turn to chose a a random choice (between Rock, Paper, or Scissor)
 * @return -- the choice returned
 */
element computerTurn();

/**
 * This function checks the winner of each round and returns the winner under the form
 * of an integer.
 *
 * @param userInput -- the input made by user as "element" type.
 * @param computerInput -- the random input of computer of "element" type.
 * @return -- returns an int of whether the user won (1), the computer won (2) or if it was a tie (0)
 */
int checkWinnerRound(int inputUser, int inputComputer);

/**
 * Function that looks for user to press "ENTER" to finish the game.
 * @return-- returns True if the "ENTER" key was pressed, False otherwise
 */
boolean endTerminal();

/**
 * This function checks whether the first character within a given words is either "R,r,P,p,S,s" in order
 * to validate the word as either Rock, Paper or Scissor. It only checks the begining of the first character of the
 * world.
 *
 * @param aWord -- word inputed by the user in order to be check for correct input
 * @return -- returns an "element" type of either Rock, Paper, Scissor or None if the input was invalid
 */
element checkForCorrectUserInput(const char aWord[]);

/**
 * This function simply displays the winner of all rounds combined at the end of the game.
 *
 * @param computerScore -- score of the computer as an integer
 * @param userScore  -- score of the user as an integer
 * @param tiedRounds -- number of times where user and computer had the same input (tie)
 */
void winnerDisplay(int computerScore, int userScore, int tiedRounds);

/**
 * This function oversees the entire game. It tracks down the number rounds left (10) and tallies the score
 * of both the computer and the user.
 */
void isGameOver();

#endif
