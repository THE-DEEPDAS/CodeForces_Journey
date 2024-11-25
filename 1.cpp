#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int roll_no;
    string name;

public:
    // Constructor for Student
    Student(int r, const string &n) : roll_no(r), name(n) {}

    void showStudentDetails() const {
        cout << "Roll Number: " << roll_no << "\n";
        cout << "Name: " << name << "\n";
    }
};

class Test : virtual public Student {
protected:
    float test_marks;

public:
    // Constructor for Test
    Test(int r, const string &n, float t_marks) 
        : Student(r, n) {
            test_marks = t_marks;
        }

    void showTestMarks() const {
        cout << "Test Marks: " << test_marks << "/100\n";
    }
};

class Sports : virtual public Student {
protected:
    float sports_score;

public:
    // Constructor for Sports
    Sports(int r, const string &n, float s_score) 
        : Student(r, n) {
            sports_score = s_score;
        }

    void showSportsScore() const {
        cout << "Sports Score: " << sports_score << "/50\n";
    }
};

class Results : public Test, public Sports {
public:
    // Constructor for Results
    Results(int r, const string &n, float t_marks, float s_score) 
        : Student(r, n), Test(r, n, t_marks), Sports(r, n, s_score) {}

    void displayResult() {
        float total = test_marks + sports_score;
        showStudentDetails();
        showTestMarks();
        showSportsScore();
        cout << "Total Score: " << total << "/150\n";
    }
};

int main() {
    int roll_no;
    string name;
    float test_marks, sports_score;

    cout << "Enter roll number: ";
    cin >> roll_no;
    cin.ignore(); // To consume the newline left in the input buffer
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter test marks (out of 100): ";
    cin >> test_marks;
    cout << "Enter sports score (out of 50): ";
    cin >> sports_score;

    Results student(roll_no, name, test_marks, sports_score);
    cout << "\n--- Student Results ---\n";
    student.displayResult();

    return 0;
}
