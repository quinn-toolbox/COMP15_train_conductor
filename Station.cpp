/*
 * Quinn Pham
 * Station.h
 * COMP15
 * Spring 2018
 *
 * Implementation of the Station class for homework 2
 * Contains functions relating to a station, including a customized
 * constructor, a destructor, print, checking whether two stations are equal.
 */

#include "Station.h"

// Constructor
Station::Station()
{
	name = "NoName";
    access = false;
}

// Parameterized Constructor
Station::Station(string input_name, bool input_access)
{
    name = input_name;
    access = input_access;
}

/* 
 * Function: is_equal
 * Input: a station
 * Returns: a boolean value
 * Does: checks whether the input is equal to the current station
 */
bool Station::is_equal(Station s)
{
    if (name == s.getName()) {
    	if (access == s.getAccess()) {
    		return true;
    	}
    	return false;
    }
    return false;
}

/* 
 * Function: print
 * Input: a reference to the ostream
 * Returns: nothing
 * Does: prints properties of the station to the ostream
 */
void Station::print(ostream &outfile)
{
    outfile << name << " ";
    if (access == true) {
    	outfile << "A";
    }
    else if (access == false) {
    	outfile << "U";
    }
}


