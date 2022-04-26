// Channing Babb
// The purpose of this program is to have a lottery game

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

// constants
const int MAX_STUDENTS = 50;
const double INITIAL_PRICE = 2.00;

// structures
struct StudentInformation {
  int studentId;
  string lastNameFirstName;
  int numbers[7];
  int matches;
  double prize;
};

// function prototypes
void getFileData(StudentInformation reports[], int &);
void enterNumbers(int[]);
void resultsReport(StudentInformation reports[], int);

int main()
{
  StudentInformation reports[MAX_STUDENTS];
  int chosenNumbers[7];
  int number_of_students;
  
  getFileData(reports, number_of_students);
  enterNumbers(chosenNumbers);
  resultsReport(reports, number_of_students);
}

// this will get data from either file and put it into the results report array
void getFileData(StudentInformation reports[], int & number_of_students) {
  ifstream File;
  File.open("guesses1.txt");
  string data;
  int i = 0;
  // the first output is the studentId
  // the second & third output is the name
  if(!File) {
       cout << "\n\n**** ERROR OPENING FILE. ******\n" << endl;
  } else {
    while (!File.eof()) {
    	File >> reports[i].studentId; //student id
    	getline(File, reports[i].lastNameFirstName);  //lastname & firstname
      // loop through each number, put into numbers array
      for (int k = 0; k < 7; k++) {
        File >> reports[i].numbers[k];
      }
      i++; //increment
      number_of_students = i;
     }
  }
  File.close();
}

// get user-inputted numbers
void enterNumbers(int chosenNumbers[]) {
  cout << "Enter the 7 different, random numbers between 1 and 50 that were selected\n";
  
  // I am far too lazy to put inputs for all 7 numbers so I will just be making a loop.
  for (int i = 0; i < 7; i++) { 
    cout << "\nNumber " << i+1 << ": ";
    cin >> chosenNumbers[i];
  }
}

// results report
void resultsReport(StudentInformation reports[], int number_of_students) {
  cout << "* * * * * * * * * Results Report * * * * * * * * *\n";
  cout << setw(10)  << "Student ID";
  cout << setw(20) << "Student Name";
  cout << setw(25) << "Chosen Numbers";
  cout << setw(15) << "Matches";
  cout << setw(15) << "Prize $\n";
  cout << "__________________________________________________________________________________________\n";
  for (int i = 0; i < number_of_students-1; i++) {
    cout << left << setw(15)  << reports[i].studentId;
    cout << left << setw(20) << reports[i].lastNameFirstName;
    // cout << left << setw(30) << reports[i].numbers;
    for (int k = 0; k < 7; k++) {
      cout << left << setw(3) << reports[i].numbers[k];
      if (k == 7) {
        cout << setw(17) << "";
      }
    }
    cout << left << setw(20)  << 2;
    cout << left << setw(20) << "$" << 55 << "\n";
  }
}