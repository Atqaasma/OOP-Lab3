#include <iostream>
#include <vector>
using namespace std;

class GradeManager {
private:
    vector<float> grades;

public:
    void addGrade(float grade) {
        grades.push_back(grade);
    }

    void displayGrades() {
        for (float grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
};

int main() {
    GradeManager gm;
    gm.addGrade(91.2);
    gm.addGrade(82.3);
    gm.addGrade(69.8);
    gm.addGrade(75.9);

    cout << "Student Grades: ";
    gm.displayGrades();

    return 0;
}
