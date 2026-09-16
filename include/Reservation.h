#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

using namespace std;

class Reservation
{
private:
    string reservationID;
    string studentID;
    string resourceID;
    string date;
    string time;

public:
    Reservation(string rID, string sID, string resID,
                string d, string t);

    string getReservationID() const;
    string getStudentID() const;
    string getResourceID() const;
    string getDate() const;
    string getTime() const;

    void display() const;
};

#endif