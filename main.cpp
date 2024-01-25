#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

// ------------------------------------------------------------------------------------------------------------------------------ //
// -------- FUNCTIONS ----------------------------------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------------------------------------------------------ //
// -------- Menu Display -------------------------------------------------------------------------------------------------------- //

void displayMenu(){
    cout << "=============== MENU ==============="
         << "\nP - Print numbers" 
         << "\nA - Add a number" 
         << "\nM - Display mean of the numbers" 
         << "\nS - Display the smallest number"
         << "\nL - Display the largest number" 
         << "\nQ - Quit" 
         << endl;  
}

// -------- accepting input, changing it into lowercase, and turning it into a int that can be used in the switch case -------------------------- //
int getUserInput(){
    
    string userPick;
    cin >> userPick;
    transform(userPick.begin(), userPick.end(), userPick.begin(), ::tolower);

    if (userPick == "p") return 1;
    if (userPick == "a") return 2;
    if (userPick == "m") return 3;
    if (userPick == "s") return 4;
    if (userPick == "l") return 5;
    if (userPick == "q") return 6;
    
    cout << "Unknown selection, please try again." << endl;
    return 0;
}

// ---------- functions with the actions of every option --------------------------------------------------------------------- //
void printNumbers(const vector<int>& v){
    if (v.empty()){
        cout << "[] - the list is empty" << endl;
    }
    else{
        cout << "[ ";
        for(auto num: v)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}

void addNumbers(vector<int>& v){
    int newNumber;
    cout << "Enter a number to be added to the list: " << endl;
    cin >> newNumber;
    v.push_back(newNumber);
    cout << newNumber << " added" << endl;
}

void calculateMean(const vector<int>& v){
    if (v.empty()){
        cout << "Unable to calculate the mean - no data" << endl;
    }
    else{
        int sum = 0;
        for (auto num : v){
            sum += num;
        }
        double mean = static_cast<double>(sum) / v.size();
        cout << "The mean is " << mean << endl;
    }
}

void findSmallest(const vector<int>& v){
    if (v.empty()){
        cout << "Unable to determine the smallest number - list is empty" << endl;
    }
    else{
        int smallest = v[0];
        for (auto num : v){
            if (num < smallest){
                smallest = num;
            }
        }
        cout << "The smallest number is " << smallest << endl;
    }
}

void findLargest(const vector<int>& v){
    if (v.empty()){
        cout << "Unable to determine the largest number - list is empty" << endl;
    }
    else{
        int largest = v[0];
        for (auto num : v){
            if (num > largest){
                largest = num;
            }
        }
        cout << "The largest number is " << largest << endl;
    }
}

bool running {true}; // if this variable is true, he program will run, if false it means the user picked the quit option

void quit(){
    cout <<"Bye" << endl;
    running = false;
}

// ------------------------------------------------------------------------------------------------------------------------------ //
// -------- MAIN ---------------------------------------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------------------------------------------------------ //

int main() {
    int pick {0}; // initializes a variable that saves a number that represents the user input
    vector<int> numbers {}; // this is the vector that saves the numbers added during the program
    
    // --------------------------------------------------------------------------------- //
    // ------- program logic ----------------------------------------------------------- //
    // --------------------------------------------------------------------------------- //
    
    while (running){
    // ------- displaying menu --------------------------------------------------------- //
        displayMenu();
        
    // ------- forcing user to pick a valid option ------------------------------------- //
        while (pick == 0){ 
            pick = getUserInput();
        }
    
    // -------- switch case with all the cases that the valid inputs present ----------- //
        switch (pick){
        case 1: // shows all numbers in the vector
            printNumbers(numbers);
            break;
            
        case 2: // add a number to the vector
            addNumbers(numbers);
            break;
            
        case 3: // calculates the mean out of all numbers in the vector
            calculateMean(numbers);
            break;
            
        case 4: // finds the smallest number in the vector
            findSmallest(numbers);
            break;
            
        case 5: // finds the largest number in the vector
            findLargest(numbers);
            break;
            
        case 6: // turns running into false, ending the first while loop and the program
            quit();
            break;
    }
    
    // -------- returning pick to 0, otherwise the second while won't run again
        pick = 0;
    }
    return 0;
}