#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
};

class StudentManager {
private:
    vector<Student*> records;

public:
    void addStudent() {
        int id;
        string name;
        float grade;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore(); // To consume the '\n' character left in the input buffer.
        getline(cin, name);
        cout << "Enter Grade: ";
        cin >> grade;

        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
        cout << "Student added successfully." << endl;
    }
    
    void updateGrade() {
        int id;
        float newGrade;
        cout << "Enter ID of the student to update grade: ";
        cin >> id;
        cout << "Enter new grade: ";
        cin >> newGrade;

        for (Student* student : records) {
            if (student->id == id) {
                student->grade = newGrade;
                cout << "Grade updated successfully." << endl;
                return;
            }
        }
        cout << "Student ID not found." << endl;
    }
    
    void displayRecords() {
        if (records.empty()) {
            cout << "No records to display." << endl;
            return;
        }
        for (Student* student : records) {
            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
        }
    }
    
    ~StudentManager() {
        for (Student* student : records) {
            delete student;
        }
    }
};

void displayMenu() {
    cout << "\nStudent Record Management System" << endl;
    cout << "1. Add Student Record" << endl;
    cout << "2. Update Student Grade" << endl;
    cout << "3. Display All Records" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    StudentManager sm;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                sm.addStudent();
                break;
            case 2:
                sm.updateGrade();
                break;
            case 3:
                sm.displayRecords();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
