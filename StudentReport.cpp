#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Define the studentType struct
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Function prototypes
void readStudentData(studentType students[], int size);
void assignGrades(studentType students[], int size);
int findHighestScore(const studentType students[], int size);
void printHighestScorers(const studentType students[], int size, int highestScore);
void printStudentReport(const studentType students[], int size);

int main() {
    const int NUM_STUDENTS = 20;
    studentType students[NUM_STUDENTS];
    
    // Function calls as required
    readStudentData(students, NUM_STUDENTS);
    assignGrades(students, NUM_STUDENTS);
    
    int highestScore = findHighestScore(students, NUM_STUDENTS);
    
    // Output results
    printStudentReport(students, NUM_STUDENTS);
    printHighestScorers(students, NUM_STUDENTS, highestScore);
    
    return 0;
}

// Function to read students' data into the array
void readStudentData(studentType students[], int size) {
    cout << "Enter data for " << size << " students:\n";
    for (int i = 0; i < size; i++) {
        cout << "Student " << (i + 1) << ":\n";
        cout << "First Name: ";
        cin >> students[i].studentFName;
        cout << "Last Name: ";
        cin >> students[i].studentLName;
        cout << "Test Score (0-100): ";
        cin >> students[i].testScore;
        
        // Validate test score
        while (students[i].testScore < 0 || students[i].testScore > 100) {
            cout << "Invalid score! Enter a score between 0 and 100: ";
            cin >> students[i].testScore;
        }
        cout << endl;
    }
}

// Function to assign the relevant grade to each student
void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore >= 90)
            students[i].grade = 'A';
        else if (students[i].testScore >= 80)
            students[i].grade = 'B';
        else if (students[i].testScore >= 70)
            students[i].grade = 'C';
        else if (students[i].testScore >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

// Function to find the highest test score
int findHighestScore(const studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest) {
            highest = students[i].testScore;
        }
    }
    return highest;
}

// Function to print the names of students having the highest test score
void printHighestScorers(const studentType students[], int size, int highestScore) {
    cout << "\nHIGHEST TEST SCORE: " << highestScore << endl;
    cout << "STUDENTS WITH HIGHEST SCORE:\n";
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << left << setw(25) << (students[i].studentLName + ", " + students[i].studentFName) << endl;
        }
    }
}

// Additional function to print all student data (not required but useful)
void printStudentReport(const studentType students[], int size) {
    cout << "\nSTUDENT REPORT";
    cout << "\n" << string(50, '-') << endl;
    cout << left << setw(25) << "NAME" << setw(15) << "TEST SCORE" << "GRADE" << endl;
    cout << string(50, '-') << endl;
    
    for (int i = 0; i < size; i++) {
        string fullName = students[i].studentLName + ", " + students[i].studentFName;
        cout << left << setw(25) << fullName 
             << setw(15) << students[i].testScore 
             << students[i].grade << endl;
    }
}