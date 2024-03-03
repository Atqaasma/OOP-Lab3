#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task*> tasks;

public:
    void addTask(const string& desc) {
        tasks.push_back(new Task(desc));
    }

    void listTasks() const {
        if (tasks.empty()) {
            cout << "No tasks added yet." << endl;
            return;
        }
        int taskId = 1; // Start counting tasks from 1 for user-friendliness
        for (const auto &task : tasks) {
            cout << taskId++ << ". " << task->description << (task->completed ? " (completed)" : " (pending)") << endl;
        }
    }

    void markTaskCompleted(int taskId) {
        if (taskId <= 0 || taskId > tasks.size()) {
            cout << "Invalid task ID." << endl;
            return;
        }
        // Adjust for 0-based index
        tasks[taskId - 1]->completed = true;
        cout << "Task " << taskId << " marked as completed." << endl;
    }

    ~ToDoList() {
        for (auto &task : tasks) delete task;
    }
};

int main() {
    ToDoList myList;
    myList.addTask("Finish Lab 3");
    myList.addTask("Linear Algebra Assignment");
    myList.addTask("ECS and ISL quiz preparation");

    // Implement listing and marking tasks as completed
    cout << "Current Tasks: " << endl;
    myList.listTasks();

    // Simulate marking a task as completed
    cout << "\nMarking task 2 as completed." << endl;
    myList.markTaskCompleted(2);

    cout << "\nUpdated Tasks: " << endl;
    myList.listTasks();

    return 0;
}
