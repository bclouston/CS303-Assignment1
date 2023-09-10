//
//  main.cpp
//  Homework1
//
//  Created by Brendan Clouston on 9/7/23.
//

#include "Header.h"

int findIndex(int arr[], int size) {
    string input;
    int n;
    while (true) {      //loops until a valid index location is given
        try {
            cout << "Please enter a value to search for inside the array : ";
            getline(cin, input);
            stringstream ss(input);
            ss >> n;
            //check if input is an integer
            if (ss.fail()) {
                //clear ss error and ignore invalid entry
                ss.clear();
                ss.ignore(numeric_limits<streamsize>::max());
                throw runtime_error("Invalid input, please enter an integer");
            }
            //search array for value provided by user
            for (int i = 0; i < size; i++) {
                if (n == arr[i]) {
                    cout << "The value " << n << " was found at index location: " << i << endl << endl;
                    return i;
                }
            }
            //return -1 if value is not found
            cout << "Value was not found." << endl;
            return -1;
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
        }
    }
    return -1;
}

void modifyArr(int arr[], int size) {
    string input;
    int oldVal, newVal, index;
    while (true) {
        try {
            cout << "Please enter an index location to modify an integer in the array: ";
            getline(cin, input);
            stringstream ss(input);
            ss >> index;
            cout << endl;
            //check if input is an integer
            if (ss.fail()) {
                //clear stringstream and ignore invalid entry
                ss.clear();
                ss.ignore(numeric_limits<streamsize>::max());
                throw runtime_error("Invalid input, please enter an integer");
            }
            //check if input is within bounds of arr[]
            if (index > (size - 1) || index < 0) {
                throw runtime_error("Invalid input, outside of array bounds. Pleaee try again.");
            }
            cout << "Please enter the new value for index location " << index << " : ";
            getline(cin, input);
            stringstream ss1(input);
            ss1 >> newVal;
            if (ss1.fail()) {
                //clear stringstream and ignore invalid entry
                ss1.clear();
                ss1.ignore(numeric_limits<streamsize>::max());
                throw runtime_error("Invalid input, please enter an integer");
            }
            oldVal = arr[index];
            arr[index] = newVal;
            cout << endl << "You have succesfully replaced index locations previous value of " << oldVal << " to " << newVal << "." << endl << endl;
            return;
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
        }
    }
}

int addElement(int arr[], int& size) {
    string input;
    int newVal;
    while (true) {
        try {
            cout << "Please enter an integer to add to the array : ";
            getline(cin, input);
            stringstream ss(input);
            ss >> newVal;
            //check in input is an integer
            if (ss.fail()) {
                //clear stringstream and ignore invalid entry
                ss.clear();
                ss.ignore(numeric_limits<streamsize>::max());
                throw runtime_error("Invalid input, please enter an integer.");
            }
            int* newArr = new int[size + 1];
            //copy contents(size * sizeof(int) bytes) from arr[] memory block into newArr[]
            memcpy(newArr, arr, size * sizeof(int));
            //update array size in main()
            size = size + 1;
            arr = newArr;
            return newVal;
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
        }
    }
}

void delElement(int arr[], int size) {
    string input;
    int index;
    while (true) {      //loops until a valid index location is given
        try {
            cout << "Please enter an index location that should be replaced by a 0 : ";
            getline(cin, input);
            stringstream ss(input);
            ss >> index;
            //check if input is an integer
            if (ss.fail()) {
                //clear stringstream and ignore invalid entry
                ss.clear();
                ss.ignore(numeric_limits<streamsize>::max());
                throw runtime_error("Invalid input, please enter an integer");
            }
            //check if input is within bounds of arr[]
            if (index > (size - 1) || index < 0) {
                throw runtime_error("Invalid input, outside of array bounds. Pleaee try again.");
            }
            arr[index] = 0;
            return;
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl << endl;
        }
    }
}

int menu() {
    int n;
    string input;
    while (true) {
        try {
            cout << "MENU:" << endl;
            cout << "1: Check if and where a certain integer exists in the array" << endl;
            cout << "2: Modify the integer value of an index location" << endl;
            cout << "3: Add an integer to the end of the array" << endl;
            cout << "4: Replace the integer at an index location to 0" << endl;
            cout << "5: Print array" << endl;
            cout << "6: Exit" << endl << endl;
            cout << "Please enter 1-6 to choose an option: ";
            getline(cin, input);
            stringstream ss(input);
            ss >> n;
            //throw error if user does not choose valid option or stringstream fails
            if (n < 1 || n > 6 || ss.fail()) {
                //clear stringstream and ignore invalid entry
                ss.clear();
                ss.ignore(numeric_limits<streamsize>::max());
                throw runtime_error("Invalid input, please try again.");
            }
            cout << endl;
            return n;
        }
        catch (runtime_error& excpt){
            cout << excpt.what() << endl << endl;
        }
    }
}

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        //check if last element in array
        if (i == (size - 1)) { cout << arr[i] << "]" << endl << endl; }
        else { cout << arr[i] << ", "; }
    }
}

int main() {
    fstream fin;
    int temp, menuChoice, size = 0;
    string line;
    fin.open("input.txt");
    //determine the size of array to declare
    while (fin >> temp) {
        size++;
    }
    //declare array to store all the integers from file
    int array[size];
    fin.close();
    fin.open("input.txt");
    size = 0;
    //copy file contents into array
    while (fin >> temp) {
        array[size] = temp;
        size++;
    }
    
    while (true) {
        menuChoice = menu();
        if (menuChoice == 1) {
            findIndex(array, size);
        }
        else if (menuChoice == 2) {
            modifyArr(array, size);
        }
        else if (menuChoice == 3) {
            int newVal = addElement(array, size);
            //add new value to end of array, I could not get it to update inside the function
            array[size - 1] = newVal;
        }
        else if (menuChoice == 4) {
            delElement(array, size);
        }
        else if (menuChoice == 5) {
            printArray(array, size);
        }
        else if (menuChoice == 6) {
            return 0;
        }
    }
    return 0;
}
