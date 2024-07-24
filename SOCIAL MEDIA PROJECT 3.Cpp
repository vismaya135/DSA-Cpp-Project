#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
using namespace std;


class Message {
public:
    string sender;
    string content; 


    Message() {}


    Message(string sender, string content) {
        this->sender = sender;
        this->content = content;
    }

    // Display the message in the format "sender: content"
    void displayMessage() const {
        cout << sender << ": " << content << endl;
    }

    // Edit the content of the message
    void editMessage(const string& newContent) {
        content = newContent;
    }
};

// SocialGroup Class
class SocialGroup {
private:
    string groupName; 
    vector<Message> messages;
    vector<string> members; 
    string host; 

public:
    
    SocialGroup() {}

    
    SocialGroup(string groupName, string host) {
        this->groupName = groupName;
        this->host = host;
    }

    // Add a new member to the group
    void addMember(const string& userName) {
        members.push_back(userName);
    }

    // Send a message to the group
    void sendMessage(const string& userName, const string& content) {
        messages.emplace_back(userName, content);
    }

    // Edit a message by its index
    void editMessage(int index, const string& newContent) {
        if (index >= 0 && index < messages.size()) {
            messages[index].editMessage(newContent);
        } else {
            cout << "Invalid message index" << endl;
        }
    }

    // Delete a message by its index
    void deleteMessage(int index) {
        if (index >= 0 && index < messages.size()) {
            messages.erase(messages.begin() + index);
        } else {
            cout << "Invalid message index" << endl;
        }
    }

    // Display all messages in the group
    void displayGroupMessages() const {
        cout << "Messages in group " << groupName << ":" << endl;
        for (const auto& msg : messages) {
            msg.displayMessage();
        }
    }

    // Get the host of the group
    string getHost() const {
        return host;
    }
};


class User {
public:
    string firstName; 
    string lastName; 
    int age; 
    string gender; 

    
    User() {}

    
    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};


map<string, User> mapUserName; 
map<string, set<string>> Friends; 

// Function to add a new user
void addUser(const string& userName, const User& user) {
    if (mapUserName.find(userName) == mapUserName.end()) {
        mapUserName[userName] = user;
    } else {
        cout << "Username already taken." << endl;
    }
}

// Function to make two users friends
void makeThemFriend(const string& userName1, const string& userName2) {
    Friends[userName1].insert(userName2);
    Friends[userName2].insert(userName1);
}

// Function to display all users
void displayAllUsers() {
    cout << "All Users:" << endl;
    for (const auto& user : mapUserName) {
        cout << "Username: " << user.first << ", Name: " << user.second.firstName << " " << user.second.lastName << endl;
    }
}

// Function to display all friendships
void displayAllFriendships() {
    cout << "All Friendships:" << endl;
    for (const auto& friendEntry : Friends) {
        cout << friendEntry.first << " -> ";
        for (const auto& friendName : friendEntry.second) {
            cout << friendName << " ";
        }
        cout << endl;
    }
}

int main() {
    // Create a social group with name "Goa Trip" and host "Alice"
    SocialGroup group1("Goa Trip", "Alice");

    int choice;
    while (true) {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Add User\n";
        cout << "2. Make Friend\n";
        cout << "3. Send Message\n";
        cout << "4. Edit Message\n";
        cout << "5. Delete Message\n";
        cout << "6. Display All Users\n";
        cout << "7. Display All Friendships\n";
        cout << "8. Display Group Messages\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Add a new user
            string userName, firstName, lastName, gender;
            int age;
            cout << "Enter username: ";
            cin >> userName;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;
            addUser(userName, User(firstName, lastName, age, gender));
            group1.addMember(userName);

        } else if (choice == 2) {
            // Make two users friends
            string userName1, userName2;
            cout << "Enter first username: ";
            cin >> userName1;
            cout << "Enter second username: ";
            cin >> userName2;
            makeThemFriend(userName1, userName2);

        } else if (choice == 3) {
            // Send a message to the group
            string userName, content;
            cout << "Enter username: ";
            cin >> userName;
            cin.ignore();
            cout << "Enter message: ";
            getline(cin, content);
            group1.sendMessage(userName, content);

        } else if (choice == 4) {
            // Edit a message (only if the user is the host)
            if (group1.getHost() == "Alice") {
                int index;
                string newContent;
                cout << "Enter message index to edit: ";
                cin >> index;
                cin.ignore();
                cout << "Enter new content: ";
                getline(cin, newContent);
                group1.editMessage(index, newContent);
            } else {
                cout << "Only the host can edit messages." << endl;
            }

        } else if (choice == 5) {
            // Delete a message (only if the user is the host)
            if (group1.getHost() == "Alice") {
                int index;
                cout << "Enter message index to delete: ";
                cin >> index;
                group1.deleteMessage(index);
            } else {
                cout << "Only the host can delete messages." << endl;
            }

        } else if (choice == 6) {
            // Display all users
            displayAllUsers();

        } else if (choice == 7) {
            // Display all friendships
            displayAllFriendships();

        } else if (choice == 8) {
            // Display all group messages
            group1.displayGroupMessages();

        } else if (choice == 9) {
            // Exit the application
            break;

        } else {
            // Handle invalid menu choices
            cout << "Unknown choice, please try again." << endl;
        }
    }

    return 0;
}
