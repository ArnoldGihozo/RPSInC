/**
 * Author: Arnold Gihozo
 * Class: AUCSC 370
 * Date Created: September 25, 2020
 * Date Last Modified: October 2, 2020
 *
 * Description:
 * The program bellow executes a simple Rock Paper Scissor game between the computer and the user. This program
 * was created within the scope of the AUCSC 370 class at the University of Alberta- Augustana Campus. Its main goal
 * is to get use with the C programming language. The RPS game last for 10 rounds and is played between a computer
 * and a user. The game is played over terminal where the user has to input either "rock, paper or scissor" any any
 * format and length (maximum 100 character). The program will accept the input as long as the first letter of the
 * input matches one of the 3 options, othewise, the user will be asked to try again. At the end of the 10 rounds,
 * the game will display the final score, the number of tied rounds, the final champion and asks the user to press
 * "ENTER" to finish the game!
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

/**
 * Function examines whether the game is over or not. Keeps count of player's score and terminates after 10 rounds.
 */
void isGameOver() {

    int computerScore = 0;
    int userScore = 0;
    int tiedRounds = 0;
    for (int counter = 10; counter--;) { // auto decrements the rounds of the game
        int winnerRound = gameRound();
        switch (winnerRound) {
            case 1:
                userScore++;
                break;
            case 2:
                computerScore++;
                break;
            default:
                tiedRounds++;
                break;
        }//switch
    }// for loop
    winnerDisplay(computerScore, userScore, tiedRounds);
}// isGameOver

/**
 * This function takes in a user input prints the valid user choice and computer choice. If the input
 * made by the user is invalid, it asks for another input
 *
 * @return -- returns an integer of who won the current round that is being played
 *          *  0 = Tie
 *          *  1 = user won
 *          *  2 = computer won
 */
int gameRound() {
    char word[100];
    printf("Please enter your choice: \"Rock\",\"Paper\", or \"Scissors\" ");
    scanf("%s", word);
    int inputUser = checkForCorrectUserInput(word);
    int inputComputer = computerTurn();
    if (inputUser == None) {
        printf("Not sure of your selection. Try again \n");
        gameRound();
    } else {
        printf("You entered ");
        displayInput(inputUser);
        printf("Computer chose ");
        displayInput(inputComputer);
        int roundWinner = checkWinnerRound(inputUser,inputComputer);
        printf("\n");
        return roundWinner;
    } // else
}// gameRound

/**
 * This function will print the final champion!
 *
 * @param computerScore -- integer of computer's score
 * @param userScore  -- integer of player's score
 * @param tiedRounds -- integer for how many rounds userScore == computerScore
 */
void winnerDisplay(int computerScore, int userScore, int tiedRounds) {
    printf("Game Over! You won %d rounds and computer won %d rounds, tied %d rounds \n",
           userScore, computerScore, tiedRounds);
    if (userScore > computerScore) {
        printf("Champion: YOU \n");
    }
    if (computerScore > userScore) {
        printf("Champion: COMPUTER \n");
    }
    if (computerScore == userScore) {
        printf("Champion: NO ONE :( It is a tie! \n");
    }// if
}// winnerDisplay


/**
 * This function will take in the valid user and computer input and checks for the winner of the round. It will first
 * check if the two inputs are equal. Then it will use modulo to evaluate whether the user or computer has won. The
 * way it is doing this is by "thinking of an imaginary circle". In other words, we know that ROCK > SCISSORS >
 * PAPER > ROCK > SCISSORS etc... (its a circle going on).
 *
 * This function then will always check for the next option after user input. If the next input (ie:computer input),
 * is the same as the user input, then that means the user has lost. If it is not tho, that means the computer
 * input is before user input, meaning the user has won. Hence why this function only has 3 checks (tie, userWin or
 * computerWin)
 *
 * @param inputUser -- the input made by the user (either, Rock, Paper or Scissor) as an integer
 * @param inputComputer -- the random input by the computer (either, Rock, Paper or Scissor) as an integer
 * @return -- this function returns the value addOfPoint which specifies who should be getting the point. It specifies
 * the winner of that specific round
 * addOfPoint = 0 --> means there was no winner! It was a tie
 * addOfPoint = 1 --> meaning the user won the round
 * addOfPoint = 2 --> meaning the computer won the round.
 */
int checkWinnerRound(int inputUser, int inputComputer) {
    int addOfPoint;
    if(inputUser == inputComputer){
        printf("TIE \n");
        addOfPoint = 0;
        return addOfPoint;
    }else if((inputUser + 1) % 3 == inputComputer % 3){ // checks for nextInput based on user and compare to cmputInput.
        printf("Winner is COMPUTER \n");
        addOfPoint = 2;
        return addOfPoint;
    }else{
        printf("Winner is YOU \n");
        addOfPoint = 1;
        return addOfPoint;
    }//else

}//checkWinner

/**
 * This function takes in an input and displays it. The input can be either from computer or user. The input taken
 * is an integer than then be converted into a strong. Remember that the following integer are displayed as:

 * @param chosenElement -- the chosen element by either a computer or user. The variable is an integer
 *
 * The function does not return anything, instead, it prints directly onto the terminal the equivalent of the integer
 * given.
 *
 */
void displayInput(int chosenElement) {
    switch (chosenElement) {
        case Rock:
            printf("ROCK  ");
            break;
        case Paper:
            printf("PAPER  ");
            break;
        case Scissor:
            printf("SCISSORS  ");
            break;
        default:
            printf(" NONE ");
            break;

    }// switch

} // diplayInput()

/**
 * This function choses a random integer between 0 - 2 in order to display computer's input. In order to ensure
 * that the number chosen are random, this function is using the time library in which it generates a seed based
 * on the computer internal clock. Since the time is constantly changing, the seed will also be consistantly changing
 * thereofre, giving us random integers (or at least limist parterns between ints).
 *
 * @return -- based on the integer chosen, function will either return Rock(0), Paper(1), Scissor(2) or
 * None(any other numbers) as an element type
 *
 */
element computerTurn() {

    srand((unsigned) time(NULL));
    int computerChoice;
    computerChoice = (rand() % 3);
    switch (computerChoice) {
        case 0:
            return Rock;
        case 1:
            return Paper;
        case 2:
            return Scissor;
        default:
            return None;
    }// switch

}// computerTurn

/**
 * This function checks for users input by evaluating whether the first letter of the aWord (the user input) is
 * either an R,r,P,p,S,s. Each letter corresponds to the first letter of either Rock, Paper or Scissor. The program
 * does account for capital and small letter input and only checks only for the first letter of the user input.
 * It does not go through the entire input
 *
 * @param aWord -- char[] of the userInput
 * @return -- returns an element of either Rock, Paper or Scissor
 *
 */
element checkForCorrectUserInput(const char aWord[]) {
    switch (aWord[0]) {
        case 'R':case 'r':
            return Rock;
        case 'P':case 'p':
            return Paper;
        case 'S':case 's':
            return Scissor;
        default:
            return None;
    }// switch
}//checkforCorrectUserInput

/**
 * This function is diplayed at the end of the game. It awaits the users input to press "ENTER" on their keyboad
 * before terminating. For that, it looks for an extra new line put into terninal.
 *
 * @return --> return  True if a new line is produced (Meaning enter is pressed) or False if a character or any other
 * key is pressed. The function will be recursivelly called in main until "ENTER" is pressed.
 */
boolean endTerminal() {
    if (getchar() != '\n')
        return False;
    else if (getchar() == '\n')
        return True;
    getchar();

}

/**
 * Prints a welcome message at the begining of the game.
 */
void welcomeMessage() {
    printf("Welcome to ROCK PAPER SCISSOR game\n");
    printf("------------------------------------\n");
}

/**
 * Program execution starts here
 */
int main() {
    welcomeMessage();
    isGameOver();
    printf("Press [Enter] to close the terminal ... ");
    if (endTerminal() != True)
        endTerminal();

    return (0);
}//main


