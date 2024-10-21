
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
#include <string>

const std::string EXCEPTION_MSG = "Array is empty!";

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
}

// get value at last location
// throw exception if empty
int ArrayInt::getLast() {
    if (this->lastIndex <= 0) {
        throw std::out_of_range(EXCEPTION_MSG);
    }
    return this->theArray[this->lastIndex - 1];//getter

}


// remove value at last location
// does nothing if empty
void ArrayInt::deleteLast() {
    if (this->lastIndex <= 0) {
        throw std::out_of_range(EXCEPTION_MSG);
    }
    this->lastIndex--; //directly manipulates the value in memory
}


// list the elements from 0 to lastIndex
std::string ArrayInt::listElements() {
    std::stringstream buf;
    if (lastIndex <= 0) {
        throw std::out_of_range("Attempt to write at invalid location");
    } else {//else does not need a condition, catch all

        for (int i = 0; i < this->lastIndex - 1; i++) {
            buf << this->theArray[i] << ", ";
        }
        buf << this->theArray[lastIndex - 1];


    }


    return buf.str();//converts buf to string
    //***END TUTORING wED 10/8***

}


// insert into array at specified location
void ArrayInt::insertAt(int index, int value) {
    if ((index < 0) or (index > this->lastIndex) or (index > this->size)) {
        throw std::out_of_range("Attempt to write at invalid location.");
    } else {
        if (this->lastIndex >= this->size) {//stop when array is full
            resize(2 * this->size);//when array is full, double size of array
        }
        if (lastIndex > 0) {
            for (int i = lastIndex; i > index; i--) {//for loop is shifting
                this->theArray[i] = this->theArray[i - 1];
            }
            theArray[index] = value;//inserts value to passed in index
            lastIndex += 1;
        } else {
            this->theArray[lastIndex] = value;
        }

    }
}

// remove an item and compress the array
int ArrayInt::removeAt(int index) {
    if ((index < 0) or (index > this->lastIndex) or (index > this->size) or (this->lastIndex <= 0)) {
        throw std::out_of_range("Attempt to read from empty array.");
    } else {
        int value = theArray[index];

        for (int i = index; i < lastIndex - 1; i++) {
            theArray[i] = theArray[i + 1];
        }
        lastIndex -= 1;
        return value;

    }
}

// find a value if present
bool ArrayInt::find(int value) {
    bool found = false;
    for (int i = 0; i < lastIndex && !found; i++)
        if (theArray[i] == value)
            found = true;
    return found;
}

// remove a value if found
bool ArrayInt::findRemove(int value) {
    bool found = false;
    for (int i = 0; i < lastIndex && !found; i++) {
        if (theArray[i] == value) {
            found = true;

            removeAt(i);

        }
    }
    return found;
}

// find and return the largest value
int ArrayInt::findLargest() {
    if (lastIndex > 0) {
        int largest = theArray[0];

        for (int i = 1; i < lastIndex; i++) {
            if (theArray[i] > largest) {
                largest = theArray[i];
            }

        }
        return largest;//last line returning variable for ex declared first usually
    } else {
        throw std::out_of_range("Attempt to read from empty array.");
    }
}

// remove largest value
void ArrayInt::removeLargest() {
    int largest = 0;//set index //variables declared first
    if (lastIndex > 0) {
        for (int i = 1; i < lastIndex; i++) {
            if (theArray[i] > theArray[largest]) {//value vs value
                largest = i;//the index where largest value is stored
            }
        }

    } else {
        throw std::out_of_range("Attempt to remove from empty array.");
    }
    removeAt(largest);
}

// index into array to get a value
int ArrayInt::getAt(int index) {
    int value;
    if ((index < 0) or (index >= size)) {
        throw std::out_of_range("Attempt to read at invalid location.");
    } else {

    }
    return 7;
}

// index into array to set a value
void ArrayInt::setAt(int index, int value) {
    if ((index < 0) or (index >= size)) {
        throw std::out_of_range("Attempt to store at invalid location.");
    } else {

    }
}

//        return;


// use append, findLargest, and findRemove to arrange values in descending order
void ArrayInt::solveThink(int *values, int numValues) {
    return;
}