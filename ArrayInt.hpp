//
// Created by siusl on 10/7/2024.
//

#ifndef ARRAYINT_ARRAYINT_HPP
#define ARRAYINT_ARRAYINT_HPP
//
//  ArrayInt.hpp
//  ArrayInt
//
//  Created by Jim Bailey on 3/31/2021.
//  This work by Jim Bailey is licensed under a Creative
//  Commons Attribution 4.0 International License.
//

#ifndef ArrayInt_hpp
#define ArrayInt_hpp
#include <string>
#include <stdexcept>

class ArrayInt {
private:
    const static int SIZE = 10;
    int size;
    int lastIndex;
    int * theArray;
    int helperLargest(); //helper function to find the index of the largest value
public:
    // constructor and destructor
    ArrayInt(int size = SIZE);
    ~ArrayInt();

    // return the array size
    int getSize() { return size; }

    // resize the array to s, if s is bigger than the current array size
    void resize(int s);

    // add item at next location in array
    void append(int value);

    // get last item in array
    int getLast();

    // delete item  at last location
    void deleteLast();

    // list elements from 0 to last location
    std::string listElements();

    // insert item into array at index, moving other items as needed
    void insertAt(int index, int value);
    // remove item at index from array, moving other items as needed
    int removeAt(int index);

    // search for a value
    bool find(int value);
    // remove a value if found
    bool findRemove(int index);

    // return largest value
    int findLargest();
    // remove largest value
    void removeLargest();

    // get item at index in the array
    int getAt(int index);
    // store value at index location of array, and don't move other items
    void setAt(int index, int value);

    // use append,findLargest,findRemove to arrange values in descending order
    void solveThink(int *values, int numValues);
};

#endif /* ArrayInt_hpp */
#endif //ARRAYINT_ARRAYINT_HPP
