#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Player class to manage player information and actions
class Player {
private:
    string playerName;
    int playerScore;
    int playerHints;

public:
    // Constructor to initialize player with a name, score, and hints
    Player(const string& name) {
        playerName = name;
        playerScore = 0;
        playerHints = getMaxHints(1); // Default to Easy mode hints
    }

    // Getter for player name
    string getName() const {
        return playerName;
    }

    // Getter for player score
    int getScore() const {
        return playerScore;
    }

    // Getter for player hints
    int getHints() const {
        return playerHints;
    }

    // Method to update player score
    void updateScore(int points) {
        playerScore += points;
    }

    // Method to update player hints
    void updateHints(int hints) {
        playerHints += hints;
    }

    // Static method to get maximum hints based on game mode
    static int getMaxHints(int mode) {
        switch (mode) {
            case 1: return 5;  // Easy
            case 2: return 3;  // Medium
            case 3: return 1;  // Hard
            default: return 0;
        }
    }

    // Method to generate numbers to be guessed based on mode and range
    vector<int> generateNumbers(int mode, int range) {
        vector<int> numbers;
        numbers.push_back(rand() % (range + 1)); // Generate a random number within the range
        return numbers;
    }

    // Method to play the game
    void playGame() {
        int range, mode;
        cout << "Enter the range (starting from 0): ";
        cin >> range;
        cout << "Choose mode: 1. Easy 2. Medium 3. Hard: ";
        cin >> mode;

        int maxHints = getMaxHints(mode);
        int hintsLeft = playerHints;

        vector<int> numbersToGuess = generateNumbers(mode, range);
        int triesLeft = 3;
        int guess;
        bool won = false;

        // Main game loop
        while (triesLeft > 0) {
            cout << "You have " << triesLeft << " tries left. Enter your guess: ";
            cin >> guess;

            // Check if the guess is correct
            if (find(numbersToGuess.begin(), numbersToGuess.end(), guess) != numbersToGuess.end()) {
                cout << "Correct! You win!\n";
                int pointsWon = 10;
                if (hintsLeft > 0) {
                    pointsWon -= 2; // Deduct points if hints were used
                    hintsLeft--;
                }
                updateScore(pointsWon);
                cout << "You earned " << pointsWon << " points. Total points: " << getScore() << "\n";
                won = true;
                break;
            } else {
                cout << "Incorrect guess.\n";
                triesLeft--;
            }
        }

        // If the player runs out of tries
        if (!won) {
            cout << "You lost! The correct number was " << numbersToGuess[0] << ".\n";
        }

        playerHints = hintsLeft; // Update player hints
    }

    // Method to buy a hint
    void buyHint() {
        if (playerScore >= 20) {
            playerScore -= 20;
            playerHints++;
            cout << "You have successfully bought a hint! 20 points deducted.\n";
            cout << "Total points: " << playerScore << "\n";
        } else {
            cout << "Insufficient points to buy a hint. You need 20 points but have only " << playerScore << " points.\n";
        }
    }
};

// Function to display the leaderboard
void showLeaderboard(const vector<Player>& players) {
    cout << "\n--- Leaderboard ---\n";
    for (const auto& player : players) {
        cout << player.getName() << ": " << player.getScore() << " points\n";
    }
    cout << "-------------------\n";
}

// Function to display player statistics
void showPlayerStats(const Player& player) {
    cout << "\n--- Player Stats ---\n";
    cout << "Player Name: " << player.getName() << "\n";
    cout << "Total points earned: " << player.getScore() << "\n";
    cout << "Hints left: " << player.getHints() << "\n";
    cout << "--------------------\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    vector<Player> leaderboard; // Vector to store players on the leaderboard
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    Player currentPlayer(playerName); // Create a new player

    int choice;

    // Main menu loop
    do {
        cout << "\n1. Play Game\n2. Show Leaderboard\n3. Buy Hint\n4. Show Player Stats\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                currentPlayer.playGame(); // Play the game
                break;
            case 2:
                showLeaderboard(leaderboard); // Show the leaderboard
                break;
            case 3:
                currentPlayer.buyHint(); // Buy a hint
                break;
            case 4:
                showPlayerStats(currentPlayer); // Show player statistics
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        // Update leaderboard if the game was played
        if (choice == 1) {
            bool found = false;
            for (auto& player : leaderboard) {
                if (player.getName() == currentPlayer.getName()) {
                    player = currentPlayer;
                    found = true;
                    break;
                }
            }
            if (!found) {
                leaderboard.push_back(currentPlayer);
            }
            // Sort leaderboard by score in descending order
            sort(leaderboard.begin(), leaderboard.end(), [](const Player& a, const Player& b) {
                return a.getScore() > b.getScore();
            });
        }
    } while (choice != 5);

    cout << "Thank you for playing!\n";

    return 0;
}
