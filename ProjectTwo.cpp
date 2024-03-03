//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Andrea Carmen Sherry
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Print the course list
void printCourseList() {
    cout << "Here is a sample schedule:" << endl;
    cout << "CSCI100, Introduction to Computer Science" << endl;
    cout << "CSCI101, Introduction to Programming in C++" << endl;
    cout << "CSCI200, Data Structures" << endl;
    cout << "CSCI301, Advanced Programming in C++" << endl;
    cout << "CSCI300, Introduction to Algorithms" << endl;
    cout << "CSCI350, Operating Systems" << endl;
    cout << "CSCI400, Large Software Development" << endl;
    cout << "MATH201, Discrete Mathematics" << endl;
}

// Print the prerequisites for a given course
void printPrerequisites(const string& course) {
	//Store prerequisites for a given course
    map<string, vector<string>> prerequisites = {
    		{"CSCI100", {}},
    		        {"CSCI101", {"CSCI100"}},
    		        {"CSCI200", {"CSCI100", "CSCI101"}},
    		        {"CSCI301", {"CSCI100", "CSCI101"}},
    		        {"CSCI300", {"MATH201", "CSCI200"}},
    		        {"CSCI350", {"CSCI100", "CSCI101", "CSCI200", "MATH201", "CSCI300"}},
    		        {"CSCI400", {"CSCI301", "CSCI350"}},
    		        {"MATH201", {}}
    };
    //Find course in map
    auto it = prerequisites.find(course);
    if (it != prerequisites.end()) { //See if course was found
        cout << "Prerequisites for " << course << ":" << endl;//Print course prerequisites
        for (const string& prereq : it->second) {
            cout << prereq << endl;
        }
    } else { //IF course not found in map THEN
        cout << course << " is not a valid option." << endl;
    }
}

int main() {
    int choice;
    string course;
    //Start menu
    cout << "Welcome to the course planner." << endl;
    //Loop
    do {
        cout << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Load Data Structure
                break;
            case 2: //Print available courses
                printCourseList();
                break;
            case 3: //Ask for course number to see prerequisites
                cout << "Enter the course number: ";
                cin >> course;
                printPrerequisites(course);
                break;
            case 9: //Exit
                cout << "Thank you for using the course planner!" << endl;
                break;
            default: //Error
                cout << choice << " is not a valid option." << endl;
                break;
        }
    } while (choice != 9);

    return 0;
}
