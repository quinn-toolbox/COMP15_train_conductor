/*
 * Quinn Pham
 * Station.h
 * COMP15
 * Spring 2018
 *
 * Interface for the Station class for homework 2
 * A Station object contains properties of a station (name, accessibility)
 * Also contains relevant functions such as comparing two stations, printing
 * a station, getting the name and accessibility
 */

#include <fstream>
#include <string>
using namespace std;

#ifndef STATION_H_
#define STATION_H_

class Station
{
public:
    Station();                      //Constructor 
                                    //Creates a station with name "NoName" 
                                    //and accessibility "False"
    Station(string, bool);          //constructor that also sets the station 
                                    //name and accessibility

    void print(ostream &);          //Prints the information on the station
    bool is_equal(Station);         //Returns true if both stations have the 
                                    //same name and accessibility
    bool getAccess() {              //Getter for access
        return access;
    };
    string getName(){               //Getter for name
        return name;
    }


private:
    string name;
    bool access;
};

struct NodeType
{
    Station info;
    NodeType *next;
};

#endif
