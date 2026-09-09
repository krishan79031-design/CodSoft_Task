#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

// Display all tasks
void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n========== TO-DO LIST ==========\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";

        if (tasks[i].completed)
            cout << "[Completed] ";
        else
            cout << "[Pending]   ";

        cout << tasks[i].description << endl;
    }

    cout << "================================\n";
}

// Add a new task
void addTask(vector<Task>& tasks) {
    string task;

    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);

    tasks.push_back({task, false});

    cout << "Task added successfully!\n";
}

// Mark a task as completed
void completeTask(vector<Task>& tasks) {
    int number;

    displayTasks(tasks);

    if (tasks.empty())
        return;

    cout << "Enter task number to mark as completed: ";
    cin >> number;

    if (number >= 1 && number <= tasks.size()) {
        tasks[number - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Delete a task
void deleteTask(vector<Task>& tasks) {
    int number;

    displayTasks(tasks);

    if (tasks.empty())
        return;

    cout << "Enter task number to delete: ";
    cin >> number;

    if (number >= 1 && number <= tasks.size()) {
        tasks.erase(tasks.begin() + number - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n========== TO-DO LIST ==========\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;

            case 2:
                displayTasks(tasks);
                break;

            case 3:
                completeTask(tasks);
                break;

            case 4:
                deleteTask(tasks);
                break;

            case 5:
                cout << "Exiting To-Do List...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}