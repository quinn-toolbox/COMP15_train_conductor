/*
 * Quinn Pham
 * LinkedList.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for the LinkedList class for homework 2
 * Contains simple linked list functions such as inserting and removing, 
 * making the linked list empty, getting the length and current position,
 * getting next element, printing, etc.
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList()
{
    length = 0;
    head = NULL;
    curr_pos = NULL;
}

// Destructor
LinkedList::~LinkedList() 
{
    NodeType *to_del = NULL;
    NodeType *temp = head;
    
    while (temp != NULL) {
        to_del = temp;
        temp = temp->next;
        delete to_del;
    }
}        

// Assignment operator
LinkedList & LinkedList::operator = (const LinkedList &l)
{
    NodeType *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = l.length;
    curr_pos = NULL;
    if (l.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

/* 
 * Function: get_length
 * Input: nothing
 * Returns: the length
 * Does: returns the length of the linked list
 */
int LinkedList::get_length() const
{
    return length;
}

/* 
 * Function: insert_station
 * Input: a station
 * Returns: nothing
 * Does: adds a station to the beginning of the list, increase length by 1
 */
void LinkedList::insert_station(Station s)
{
    NodeType *station = new NodeType;
    station->info = s;
    station->next = head;

    head = station;
    length++;
}

/* 
 * Function: remove_station
 * Input: a station
 * Returns: nothing
 * Does: deletes the first instance of a station, decreases length by 1
 */
void LinkedList::remove_station(Station s)
{
    NodeType *temp = head;

    if (head->info.is_equal(s)) { // deleting first node
        if (curr_pos == head) {
            reset_curr_pos();
        }
        head = head->next;
        delete temp;
        length--;
        return;
    }

    temp = head->next;
    NodeType *prev = head;

    while (temp != NULL) {
        if (temp->info.is_equal(s)) {
            if (temp == curr_pos) {
                reset_curr_pos();
            }
            prev->next = temp->next;
            prev = temp->next;
            delete temp;
            length--;
            return;
        }
        prev = prev->next;
        temp = temp->next;
    }
}

/* 
 * Function: get_next_station
 * Input: nothing
 * Returns: a station
 * Does: gets the next station in the linked list
 * If end of the linked list, gets the first element the next time
 */
Station LinkedList::get_next_station()
{
    NodeType *temp = NULL;

    if (curr_pos == NULL) { // first execution/ after reset
        if (head != NULL) {
            curr_pos = head->next;
            return head->info; 
        }
        else if (head == NULL) {
            Station station;
            return station;
        }      
    }

    if (curr_pos->next == NULL) { // last element
        temp = curr_pos;
        curr_pos = NULL; // switch back to first
        return temp->info;
    }

    else { 
        temp = curr_pos;
        curr_pos = curr_pos->next;
        return temp->info;
    }
}

/* 
 * Function: reset_curr_pos
 * Input: nothing
 * Returns: nothing
 * Does: resets the current position to null
 */
void LinkedList::reset_curr_pos()
{
   curr_pos = NULL;
}

/* 
 * Function: make_empty
 * Input: nothing
 * Returns: nothing
 * Does: empties the linked list
 */
void LinkedList::make_empty()
{
    NodeType *to_del = NULL;
    NodeType *temp = head;
    
    while (temp != NULL) {
        to_del = temp;
        temp = temp->next;
        delete to_del;
    }

    length = 0;
    head = NULL;
    curr_pos = NULL;
}

/* 
 * Function: print
 * Input: a reference to the ostream
 * Returns: nothing
 * Does: prints the linked list to the ostream
 */
void LinkedList::print(ostream &out)
{
    if (head == NULL) {
        out << "List is empty!" << endl;
        return;
    }
    
    NodeType *to_print = head;
    int count = 1;

    while (to_print->next != NULL) {
        to_print->info.print(out);
        out << " ";
        out << length - count << " == ";
        to_print = to_print->next;
        count++;
    }

    to_print->info.print(out);
    out << " 0" << endl;
}



