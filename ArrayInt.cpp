
//  ArrayInt.cpp
//  ArrayInt
//
//  Created by Jim Bailey on 4/1/18.
//  This work by Jim Bailey is licensed under a Creative Commons Attribution 4.0
//  International License.
//

#include "ArrayInt.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>

// constructor, set up the array
ArrayInt::ArrayInt(int size) : size(size), lastIndex(0) {
    theArray = new int[size];
}

// destructor, delete the array and go away
ArrayInt::~ArrayInt() { delete[] theArray; }

// create new array of newSize and copy to it
void ArrayInt::resize(int newSize) {
    int *temp = new int[newSize];  // creates new array in a pointer called temp
    for (int i = 0; i < size; i++) {
        temp[i] = this->theArray[i]; //copies all data from the Array into temp
    }
    delete[] this->theArray;//delete old array
    this->theArray = temp; //copies pointers
    this->size = newSize; //changes array size
    return;
}

// add value at next location
// resize array if full
void ArrayInt::append(int value) {
    if (this->lastIndex >= this->size) {//stop when array is full
        resize(2 * this->size);//when array is full, double size of array
    }
    this->theArray[this->lastIndex] = value; //place value into each slot in array
    this->lastIndex++;
    return;
}

// get value at last location
// throw exception if empty
int ArrayInt::getLast() {
    if (this->lastIndex <= 0) {
        throw std::out_of_range("Array is empty!");
    }
    return this->theArray[this->lastIndex-1];//getter

}

// remove value at last location
// does nothing if empty
void ArrayInt::deleteLast() {
    if (lastIndex > 0) {
        this->lastIndex--; //directly manipulates the value in memory
    }
}


// list the elements from 0 to lastIndex
std::string ArrayInt::listElements() {
    std::stringstream buf;
    if (lastIndex <= 0) {
        throw std::out_of_range("Attempt to write at invalid location");
    } else {//else does not need a condition, catch all

        for (int i = 0; i < this->lastIndex; i++) {
            buf << this->theArray[i] << ", ";
        }
        buf << std::endl;

    }
    return buf.str();//converts buf to string
    //***END TUTORING wED 10/8***

}


// insert into array at specified location
void ArrayInt::insertAt(int index, int value) {
    if (lastIndex > 0) {
        for (int i = lastIndex; i < this->lastIndex; i--) {
            this->theArray[i] = this->theArray[i - 1];
            theArray[index] = value;
        }
        lastIndex += 1;

    }
}

// remove an item and compress the array
int ArrayInt::removeAt(int index) {
    int value = theArray[index];
    lastIndex-=1;
    for (int i = index; i < lastIndex - 1; i++){
        theArray[i] = theArray[i+1];
    }return value;

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