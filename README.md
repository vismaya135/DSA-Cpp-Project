#Game Project
```markdown![Screenshot (24)](https://github.com/user-attachments/assets/997bedcf-b8be-4fb3-a490-2243ace926ce)
![Screenshot (23)](https://github.com/user-attachments/assets/77d6bc54-9897-43f8-8cf6-87e404781308)
![Screenshot (22)](https://github.com/user-attachments/assets/4d0cf2f8-8c31-409a-8c61-843cdaabca57)



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

# TO DO LIST

This application allows users to manage tasks with the following features:

1. **Add Task**: Add new tasks with description, category, priority, and due date.
2. **View Tasks by Priority**: View tasks sorted by priority (HIGH, MEDIUM, LOW).
3. **Remind Tasks Past Due**: Display tasks that are past their due date.
4. **Sort Tasks by Due Date**: View tasks sorted by their due date (earliest first).
5. **Filter Tasks by Category**: Filter and view tasks based on their category (e.g., Work, Personal).
6. **Mark Task as Completed**: Mark a specific task as completed.
7. **Delete Task**: Delete a specific task.
8. **Exit**: Exit the application.

## Classes and Data Structures

### 1. Task Class

**Attributes**:
- `description`: Description of the task.
- `category`: Category of the task (e.g., Work, Personal).
- `priority`: Priority of the task (HIGH, MEDIUM, LOW).
- `dueDate`: Due date of the task in "YYYY-MM-DD" format.
- `completed`: Boolean indicating whether the task is completed.

**Constructor**: Initializes the task attributes.

### 2. Global Data Structures

- `NotesAdded`: A vector to store all tasks.
- `categories`: A vector of predefined categories.

## Functions

### 1. displayTasksByPriority

**Functionality**: Sorts tasks by priority and displays them.

**Details**: Tasks are sorted in descending order of priority (HIGH, MEDIUM, LOW). If two tasks have the same priority, they maintain their relative order.

### 2. remindTasksPastDue

**Functionality**: Displays tasks that are past their due date and not completed.

**Details**: Compares the current date with the due date of each task. If a task is past due and not completed, it is displayed.

### 3. sortTasksByDueDate

**Functionality**: Sorts tasks by due date (earliest first) and displays them.

**Details**: Tasks are sorted based on their due date using a lambda function.

### 4. filterTasksByCategory

**Functionality**: Filters and displays tasks based on user-selected category.

**Details**: Prompts the user to select a category and displays tasks that belong to that category.

### 5. markTaskAsCompleted

**Functionality**: Marks a specific task as completed.

**Details**: Prompts the user to enter the task number and marks the corresponding task as completed.

### 6. deleteTask

**Functionality**: Deletes a specific task.

**Details**: Prompts the user to enter the task number and deletes the corresponding task from the list.

### 7. addTask

**Functionality**: Adds a new task to the task list.

**Details**: Prompts the user to enter task description, select a category, enter priority, and automatically sets the current date as the due date.

### 8. displayMenu

**Functionality**: Displays the menu and handles user input.

**Details**: Provides options to the user for different functionalities and calls the appropriate function based on user input.


