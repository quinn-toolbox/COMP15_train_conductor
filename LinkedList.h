/*
 * Quinn Pham
 * LinkedList.h
 * COMP15
 * Spring 2018
 *
 * Interface for the LinkedList class for homework 2
 * Each element in the linked list contains a station (and a pointer to next)
 * Also contains relevant functions such as inserting and removing, making
 * the linked list empty, getting the length and current position, etc.
 */

#include "Station.h"
#include <fstream>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class LinkedList
{
public:
    LinkedList();                                   // Default constructor
    ~LinkedList();                                  // Default constructor
    LinkedList & operator = (const LinkedList &);   // Assignment Operator
    LinkedList(const LinkedList &);                 // copy constructor. 
                                                    // It creates a new list that is 
                                                    // identical to the one given


    void insert_station(Station);                   // Inserts a station into the list
    void remove_station(Station);                   // Removes a station from the list
    void make_empty();                              // Empties the list
    void reset_curr_pos();
    Station get_next_station();                     // Gives a new station

    
    int get_length() const;                         // Returns the length of the list
    void print(ostream &);                          // Print the list of stations 


private:
    int length;
    NodeType *head;
    NodeType *curr_pos;
};

#endif
