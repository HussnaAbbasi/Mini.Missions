#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoApp {
public:
    struct Task {
        string description;
        bool completed;
    };

    void addTask() {
        string taskDescription;
        cout << "Enter task description: ";
        cin.ignore();  // To ignore any leftover newline character
        getline(cin, taskDescription);

        Task task = {taskDescription, false};
        tasks.push_back(task);
        cout << "Task '" << taskDescription << "' added successfully!" << endl;
    }

    void markCompleted() {
        if (tasks.empty()) {
            cout << "No tasks available!" << endl;
            return;
        }

        viewTasks();
        int taskNumber;
        cout << "Enter the task number you want to mark as completed: ";
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task '" << tasks[taskNumber - 1].description << "' marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }

        cout << "Current Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " [Completed]";
            }
            cout << endl;
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    TodoApp app;
    int choice;

    while (true) {
        cout << "\nTo-Do List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                app.addTask();
                break;
            case 2:
                app.markCompleted();
                break;
            case 3:
                app.viewTasks();
                break;
            case 4:
                cout << "Exiting application. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

