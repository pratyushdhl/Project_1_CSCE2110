#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "Reservation.h"
#include "ResourceManager.h"

using namespace std;

class ReservationNode
{
    public:
        Reservation reservation;
        ReservationNode* next;

        ReservationNode(Reservation r);
};

class ReservationManager
{
private:
    ReservationNode* head;
    ResourceManager* resourceManager;

public:
    ReservationManager(ResourceManager* manager);

    bool validateReservation(
        const string& studentID,
        const string& resourceID,
        const string& date,
        const string& time
    );

    bool createReservation(
        const string& reservationID,
        const string& studentID,
        const string& resourceID,
        const string& date,
        const string& time
    );

    bool cancelReservation(const string& reservationID);

    void displayActiveReservations() const;
};

#endif