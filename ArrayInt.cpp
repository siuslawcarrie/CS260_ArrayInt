
//  ArrayInt.cpp
//  ArrayInt
//
//  Created by Jim Bailey on 4/1/18.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0
//  International License.
//

#include "ArrayInt.hpp"
#include <stdexcept>

// constructor, set up the array
ArrayInt::ArrayInt(int size) : size(size), lastIndex(0) {
    theArray = new int[size];
}

// destructor, delete the array and go away
ArrayInt::~ArrayInt() { delete[] theArray; }

// create new array of newSize and copy to it
void ArrayInt::resize(int newSize) {
    int *temp = new int[newSize];  // creates new array in a pointer called temp
    for (int i =0; i<size; i++) {
        temp[i] = this->theArray[i]; //copies all data from the Array into temp
    }
    delete[] this ->theArray;//delete old array
    this->theArray = temp; //copies pointers
    this ->size = newSize; //changes array size
    return;
}

// add value at next location
// resize array if full
void ArrayInt::append(int value) {
    return;
}

// get value at last location
// throw exception if empty
int ArrayInt::getLast() {
    return 7;
}

// remove value at last location
// does nothing if empty
void ArrayInt::deleteLast() {
    return;
}

// list the elements from 0 to lastIndex
std::string ArrayInt::listElements() {
    return "dummy string";
}

// insert into array at specified location
void ArrayInt::insertAt(int index, int value) {
    return;
}

// remove an item and compress the array
int ArrayInt::removeAt(int index) {
    return 7;
}

// find a value if present
bool ArrayInt::find(int value) {
    return false;
}

// remove a value if found
bool ArrayInt::findRemove(int value) {
    return false;
}

// find and return the largest value
int ArrayInt::findLargest() {
    return 7;
}

// remove largest value
void ArrayInt::removeLargest() {
    return;
}

// index into array to get a value
int ArrayInt::getAt(int index) {
    return 7;
}

// index into array to set a value
void ArrayInt::setAt(int index, int value) {
    return;
}

// use append, findLargest, and findRemove to arrange values in descending order
void ArrayInt::solveThink(int *values, int numValues) {
    return;
}