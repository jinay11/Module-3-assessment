#include <iostream>   // For input/output
#include <stdlib.h>   // For srand(), rand()
#include <ctime>      // For time()

using namespace std;

// Class definition for Rock Paper Scissors Game
class RockPaperScissorGame {
public:
    // Function to display menu
    void displayMenu() {
        cout << "----------------------------\n";
        cout << " Rock Paper Scissors Game\n";
        cout << "----------------------------\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }

    // Function to play the game
    void playGame() {
        int userChoice;
        while (true) { // Loop until user decides to exit
            displayMenu();
            cin >> userChoice;

            if (userChoice == 4) {
                cout << "Thank you for playing!\n";
                break;
            }

            if (userChoice < 1 || userChoice > 4) {
                cout << "Invalid choice. Please try again.\n\n";
                continue;
            }

            // Generate computer choice
            srand(time(0));              // Seed for random number generator
            int computerChoice = (rand() % 3) + 1; // Generates 1,2,3

            // Display choices
            cout << "\nYou chose: " << choiceToString(userChoice) << endl;
            cout << "Computer chose: " << choiceToString(computerChoice) << endl;

            // Determine winner
            determineWinner(userChoice, computerChoice);
            cout << endl;
        }
    }

private:
    // Function to convert choice number to string
    string choiceToString(int choice) {
        switch (choice) {
            case 1: return "Rock";
            case 2: return "Paper";
            case 3: return "Scissors";
            default: return "Unknown";
        }
    }

    // Function to determine the winner
    void determineWinner(int user, int computer) {
        if (user == computer) {
            cout << "It's a tie!";
        }
        else if ((user == 1 && computer == 3) ||
                 (user == 2 && computer == 1) ||
                 (user == 3 && computer == 2)) {
            cout << "You win!";
        }
        else {
            cout << "Computer wins!";
        }
    }
};

// Main function
int main() {
    RockPaperScissorGame game; // Create object
    game.playGame();           // Invoke method through object
    return 0;
}
