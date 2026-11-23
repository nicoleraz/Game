#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// Asks the player for a whole number between low and high.
// Keeps asking until the input is valid.
int readNumber(const string &prompt, int low, int high) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= low && value <= high) {
            return value;
        }
        cout << "Please enter a number from " << low << " to " << high << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Counts how many of the two guesses are correct (0, 1 or 2).
int countMatches(int guess1, int actual1, int guess2, int actual2) {
    int matches = 0;
    if (guess1 == actual1) matches++;
    if (guess2 == actual2) matches++;
    return matches;
}

// 2 matches: win 2x the bet, 1 match: win 1x the bet, 0 matches: lose the bet.
void updateCoins(int matches, int betAmount, int &coins) {
    if (matches == 2) {
        coins += betAmount * 2;
    } else if (matches == 1) {
        coins += betAmount;
    } else {
        coins -= betAmount;
    }
}

// Plays one full round.
void playRound(int &coins) {
    int randomNum1 = rand() % 6;
    int randomNum2 = rand() % 6;

    cout << "\nYour coins: " << coins << "\n";
    int guess1 = readNumber("Guess number 1 (0-5): ", 0, 5);
    int guess2 = readNumber("Guess number 2 (0-5): ", 0, 5);
    int betAmount = readNumber("Your bet: ", 1, coins);

    cout << "\nThe random number 1 is: " << randomNum1;
    cout << "\nThe random number 2 is: " << randomNum2;

    int matches = countMatches(guess1, randomNum1, guess2, randomNum2);
    cout << "\nCorrect guesses: " << matches;

    updateCoins(matches, betAmount, coins);
    cout << "\nYour coins: " << coins << "\n";
}

int main() {
    srand(time(0));  // seed once, so every round gets different numbers

    int coins = 1000;
    int playAgain = 1;

    cout << "=== Number Guessing Game ===\n";
    cout << "Guess two numbers from 0 to 5 and bet your coins.\n";

    while (playAgain == 1 && coins > 0) {
        playRound(coins);

        if (coins <= 0) {
            cout << "\nYou ran out of coins!";
            break;
        }
        playAgain = readNumber("\nPlay again? 1 for YES, 2 for NO: ", 1, 2);
    }

    cout << "\nThanks for playing! Final coins: " << coins << "\n";
    return 0;
}
