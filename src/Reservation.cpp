#include "../include/Reservation.h"
#include <iostream>

using namespace std;

Reservation :: Reservation () {
	reservationID = "";
    studentID = "";
    resourceID = "";
    date = "";
    time = "";
}

Reservation :: Reservation (string rID, string sID, string resID, string d, string t)
{
    reservationID = rID;
    studentID = sID;
    resourceID = resID;
    date = d;
    time = t;
}

string Reservation :: getReservationID() const
{
    return reservationID;
}

string Reservation :: getStudentID() const
{
    return studentID;
}

string Reservation::getResourceID() const
{
    return resourceID;
}

string Reservation::getDate() const
{
    return date;
}

string Reservation::getTime() const
{
    return time;
}

void Reservation::display() const
{
    cout << "Reservation ID: " << reservationID << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Resource ID: " << resourceID << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
    cout << "------------------------" << endl;
}