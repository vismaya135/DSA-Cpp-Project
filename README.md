# DSA-Cpp-Project
```markdown
#### Game Project
```markdown


## Project Features
- **Playing the game**
- **Choosing difficulty level**
- **Buying hints to move ahead**
- **Showing Leaderboard**
- **Showing Player Stats**
- **Exiting the game**

## Functionality

### Private Members
- **playerName**: Stores the player's name.
- **playerScore**: Stores the player's score.
- **playerHints**: Stores the number of hints the player has.

### Public Methods (Functions)
- **player(const string& name)**: Constructor that initializes a player with a name, sets the score to 0, and assigns the default number of hints based on the easy mode.
- **string getName() const**: Returns the player's name.
- **int getScore() const**: Returns the player's score.
- **int getHints() const**: Returns the player's remaining hints.
- **void updateScore(int points)**: Adds the specified points to the player's score.
- **void updateHints(int hints)**: Adds the specified hints to the player's hints.
- **static int getMaxHints(int mode)**: Returns the maximum number of hints allowed based on the game mode (Easy, Medium, Hard).
- **vector<int> generateNumbers(int mode, int range)**: Generates a random number within the given range and returns it in a vector.
- **void playGame()**: Manages the gameplay, including taking user input for range and mode, generating the number to guess, and handling guesses and scoring.
- **void buyHint()**: Allows the player to buy a hint by deducting points from their score.

### Utility Functions
- **showLeaderboard(const vector<Player>& players)**: Displays the leaderboard, showing player names and their scores.
- **showPlayerStats(const Player& player)**: Displays the statistics of the specified player, including their name, total points earned, and remaining hints.

### Main Function
1. **Initialize Random Seed**: Seeds the random number generator with the current time to ensure different random numbers in each run.
2. **Create Leaderboard**: Initializes a vector to store players on the leaderboard.
3. **Get Player Name**: Prompts the user to enter their name and creates a Player object with that name.
4. **Main Menu Loop**: Displays a menu with options to play the game, show the leaderboard, buy a hint, show player stats, and exit. It handles user input and calls the appropriate methods based on the user's choice.
5. **Update Leaderboard**: After each game, the leaderboard is updated with the player's score. If the player is already on the leaderboard, their score is updated; otherwise, they are added to the leaderboard. The leaderboard is then sorted in descending order of scores.
6. **Exit**: Displays a thank-you message when the user chooses to exit the game.

## Game Details

### 1. Play Game
- The player is prompted to enter a range and choose a mode.
- A random number is generated within the specified range.
- The player has a limited number of tries (3) to guess the number.
- If the guess is correct, the player earns points (deducting points if hints were used).
- If the guess is incorrect, the player loses a try.
- The game ends when the player either guesses the number correctly or runs out of tries.

### 2. Buy Hint
- The player can buy a hint by spending 20 points from their score.
- If the player does not have enough points, a message is displayed indicating insufficient points.

### 3. Show Leaderboard
- Displays the current leaderboard with player names and scores.

### 4. Show Player Stats
- Displays the current player's statistics, including their name, total points earned, and remaining hints.

### 5. Exit
- The game loop ends and the program exits with a thank-you message.
```
![Screenshot (20)](https://github.com/user-attachments/assets/c9fde0be-e485-41d8-aa8e-6bc783332e3a)
![Screenshot (19)](https://github.com/user-attachments/assets/7603d8e3-63ce-49a2-ad02-499307a72251)
![Screenshot (18)](https://github.com/user-attachments/assets/e7e23f6d-56dc-43a3-89e1-58ebc6feebc7)


