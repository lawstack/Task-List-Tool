#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Variables declaration
    int choice, taskNumber;
    vector<string> tasks; // Vector to store tasks
    string task, removedTask;
    bool running = true, menu = false;

    // Welcome message and initial menu display
    cout << "Welcome to Task List Tool!" << endl;
    cout << "\nMenu Options:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Quit" << endl;
    cout << "\nTask list system initialized and ready!" << endl;

    // Main loop to keep the program running until user quits
    while (running) {
        // Show menu again after the first input
        if (menu) {
            cout << "\nMenu Options:" << endl;
            cout << "1. Add Task" << endl;
            cout << "2. View Tasks" << endl;
            cout << "3. Remove Task" << endl;
            cout << "4. Quit" << endl;
            cout << endl;
        }

        // Ask for user input
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Clear newline character from input buffer

        // Option 1: Add task
        if (choice == 1) {
            cout << "Task to add: ";
            getline(cin, task); // Read full line including spaces
            tasks.push_back(task); // Add task to the vector
            cout << "Task \"" << tasks[tasks.size() - 1] << "\" added successfully!" << endl;
            cout << "Total tasks: " << tasks.size() << endl;
            menu = true;

        // Option 2: View all tasks
        } else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks available." << endl;
            } else {
                cout << "Your Tasks:" << endl;
                for (int i = 0; i < tasks.size(); i++) {
                    cout << (i + 1) << ". " << tasks[i] << endl; // Display each task with number
                }
                cout << "Total tasks: " << tasks.size() << endl;
            }
            menu = true;

        // Option 3: Remove a task by number
        } else if (choice == 3) {
            if (tasks.empty()) {
                cout << "No task to delete." << endl;
            } else {
                cout << "Number of task to remove: ";
                cin >> taskNumber;

                // Check if task number is valid
                if (taskNumber >= 1 && taskNumber <= tasks.size()) {
                    removedTask = tasks[taskNumber - 1]; // Get task to be removed
                    tasks.erase(tasks.begin() + (taskNumber - 1)); // Remove task from vector
                    cout << "Task \"" << removedTask << "\" removed successfully!" << endl;

                    // Show remaining tasks
                    cout << "Remaining Tasks:" << endl;
                    if (tasks.empty()) {
                        cout << "None" << endl;
                    } else {
                        for (int i = 0; i < tasks.size(); i++) {
                            cout << i + 1 << ". " << tasks[i] << endl;
                        }
                    }
                } else {
                    // Invalid task number error message
                    if (tasks.size() == 1) {
                        cout << "Error: Invalid task number. There's only one task." << endl;
                    } else {
                        cout << "Error: Invalid task number. Please enter a number between 1 and " << tasks.size() << "." << endl;
                    }
                }
                cout << "Total tasks: " << tasks.size() << endl;
                menu = true;
            }

        // Option 4: Quit the program
        } else if (choice == 4) {
            running = false;
            cout << "Thank you for using Task List Tool!";

        // Handle invalid menu choices
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

