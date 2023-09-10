//
//  Header.h
//  Homework1
//
//  Created by Brendan Clouston on 9/7/23.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//search for index location of given value inside array
//PRE: recieves user input as integer value to search array
//POST: searches and returns index location of given value to user if found
int findIndex(int arr[], int size);

//changes an element inside of array
//PRE: recieves user input as integer for index location and new value
//POST: alters value at index location and returns both old and new values to user
void modifyArr(int arr[], int size);

//adds an element to end of array
//PRE: recieves user input as integer
//POST: creates new array of size + 1, copy old array into new, returns user input to main() to add to new arr
int addElement(int arr[], int& size);

//changes element at index location to 0
//PRE: recieves user input as integer index location within array bounds
//POST: alters array element at given index to 0
void delElement(int arr[], int size);

//prints menu and accepts user input for action choice
//PRE: recieves user input as integer between 1-6
//POST: returns users menu choice to main()
int menu();

//prints entire array to screen for testing/validation
void printArray(int arr[], int size);

#endif /* Header_h */
