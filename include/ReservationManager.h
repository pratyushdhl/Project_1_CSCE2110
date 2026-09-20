#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "../include/Reservation.h"
#include "../include/ResourceManager.h"
#include <queue>
#include <stack>

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
	ReservationNode* tail;
    ResourceManager* resourceManager;
	queue<Reservation> waitlist;
	stack<Reservation> cancellations;

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
	bool undoCancellation();

	void displayWaitingList() const;
    void displayActiveReservations() const;
};

#endif