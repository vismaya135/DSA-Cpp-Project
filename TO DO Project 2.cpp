#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip> 
#include <algorithm> 

using namespace std;

// Task Class to represent a task
class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate;
    string priority;

    // Constructor to initialize a task
    Task(string description, string category, string priority, string dueDate) {
        this->description = description;
        this->category = category;
        this->dueDate = dueDate;
        this->priority = priority;
        this->completed = false;
    }
};

// Global vectors to store tasks and categories
vector<Task> NotesAdded;
vector<string> categories = {"Work", "Personal", "Study", "Shopping", "Other"};

// Function to display tasks sorted by priority
void displayTasksByPriority() {
    if (NotesAdded.empty()) {
        cout << "No tasks added yet.\n";
        return;
    }

    // Sort tasks by priority (HIGH > MEDIUM > LOW)
    sort(NotesAdded.begin(), NotesAdded.end(), [](const Task& a, const Task& b) {
        if (a.priority == "HIGH" && b.priority != "HIGH") return true;
        if (a.priority == "MEDIUM" && b.priority == "LOW") return true;
        return false;
    });

    // Display sorted tasks
    cout << "\nTasks sorted by Priority:\n";
    cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "Due Date" << " " << "Status" << "\n";

    for (size_t i = 0; i < NotesAdded.size(); ++i) {
        cout << i + 1 << ". "
             << NotesAdded[i].description << " "
             << NotesAdded[i].category << " "
             << NotesAdded[i].priority << " "
             << NotesAdded[i].dueDate << " "
             << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
    }
}

// Function to remind tasks past due date
void remindTasksPastDue() {
    time_t now = time(nullptr);
    tm* currentTime = localtime(&now);

    cout << "\nTasks Past Due:\n";
    cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "Due Date" << "\n";

    for (const auto& task : NotesAdded) {
        // Parse due date string into tm structure for comparison
        tm dueDate;
        stringstream ss(task.dueDate);
        ss >> get_time(&dueDate, "%Y-%m-%d");

        if (mktime(&dueDate) < mktime(currentTime) && !task.completed) {
            cout << task.description << " "
                 << task.category << " "
                 << task.priority << " "
                 << task.dueDate << "\n";
        }
    }
}

// Function to sort tasks by due date
void sortTasksByDueDate() {
    if (NotesAdded.empty()) {
        cout << "No tasks added yet.\n";
        return;
    }

    // Sort tasks by due date (earliest first)
    sort(NotesAdded.begin(), NotesAdded.end(), [](const Task& a, const Task& b) {
        tm dueDateA, dueDateB;
        stringstream ssA(a.dueDate), ssB(b.dueDate);
        ssA >> get_time(&dueDateA, "%Y-%m-%d");
        ssB >> get_time(&dueDateB, "%Y-%m-%d");
        return mktime(&dueDateA) < mktime(&dueDateB);
    });

    // Display sorted tasks
    cout << "\nTasks sorted by Due Date:\n";
    cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "Due Date" << " " << "Status" << "\n";

    for (size_t i = 0; i < NotesAdded.size(); ++i) {
        cout << i + 1 << ". "
             << NotesAdded[i].description << " "
             << NotesAdded[i].category << " "
             << NotesAdded[i].priority << " "
             << NotesAdded[i].dueDate << " "
             << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
    }
}

// Function to filter tasks by category
void filterTasksByCategory() {
    int choice;
    cout << "\nFilter Tasks by Category:\n";
    cout << "1. Work\n";
    cout << "2. Personal\n";
    cout << "3. Study\n";
    cout << "4. Shopping\n";
    cout << "5. Other\n";
    cout << "Enter category choice (1-5): ";
    cin >> choice;

    if (choice >= 1 && choice <= 5) {
        string selectedCategory = categories[choice - 1];

        cout << "\nTasks in Category '" << selectedCategory << "':\n";
        cout << "   " << "Task" << " " << "Priority" << " " << "Due Date" << " " << "Status" << "\n";

        for (const auto& task : NotesAdded) {
            if (task.category == selectedCategory) {
                cout << task.description << " "
                     << task.priority << " "
                     << task.dueDate << " "
                     << (task.completed ? "Completed" : "Pending") << "\n";
            }
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

// Function to mark a task as completed
void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(NotesAdded.size())) {
        NotesAdded[taskNumber - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid Task Number.\n";
    }
}

// Function to delete a task
void deleteTask() {
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(NotesAdded.size())) {
        NotesAdded.erase(NotesAdded.begin() + taskNumber - 1);
        cout << "Task deleted.\n";
    } else {
        cout << "Invalid Task Number.\n";
    }
}

// Function to add a new task
void addTask() {
    string description, category, priority;

    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, description);

    auto now = time(nullptr);
    tm* current = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
    string dueDate(buffer);

    cout << "Choose a category:\n";
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << "\n";
    }
    int categoryChoice;
    cout << "Enter category choice (1-" << categories.size() << "): ";
    cin >> categoryChoice;

    if (categoryChoice >= 1 && categoryChoice <= static_cast<int>(categories.size())) {
        category = categories[categoryChoice - 1];
    } else {
        cout << "Invalid choice, defaulting to 'Other'.\n";
        category = "Other";
    }

    cout << "Enter priority (HIGH/LOW/MEDIUM): ";
    cin >> priority;

    Task task(description, category, priority, dueDate);
    NotesAdded.push_back(task);
    cout << "Task added successfully.\n";
}

// Function to display the menu and handle user input
void displayMenu() {
    int choice;

    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks by Priority\n"
             << "3. Remind Tasks Past Due\n"
             << "4. Sort Tasks by Due Date\n"
             << "5. Filter Tasks by Category\n"
             << "6. Mark Task as Completed\n"
             << "7. Delete Task\n"
             << "8. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasksByPriority();
                break;
            case 3:
                remindTasksPastDue();
                break;
            case 4:
                sortTasksByDueDate();
                break;
            case 5:
                filterTasksByCategory();
                break;
            case 6:
                markTaskAsCompleted();
                break;
            case 7:
                deleteTask();
                break;
            case 8:
                cout << "Goodbye! Please do the tasks on time.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }

    } while (choice != 8);
}

int main() {
    // Display the menu to the user
    displayMenu();
    return 0;
}
