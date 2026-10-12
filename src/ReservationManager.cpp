#include "../include/ReservationManager.h"
#include <iostream>

using namespace std;

// ReservationNode Constructor

ReservationNode::ReservationNode(Reservation* r) {
	this->reservation = r;
	next = nullptr;
}

// ReservationManager Constructor

ReservationManager::ReservationManager(ResourceManager* manager) {
	this->resourceManager = manager;
	head = nullptr;
	tail = head;
}

//

bool ReservationManager::validateReservation(
        const string& studentID,
        const string& resourceID,
        const string& date,
        const string& time
    ) {
		
	
	
}

// Add reservation node to tail of linked list

bool ReservationManager::createReservation(
        const string& reservationID,
        const string& studentID,
        const string& resourceID,
        const string& date,
        const string& time
    ) {
		
	// Create reservation and node	
	Reservation* res = new Reservation(
		reservationID,
        studentID,
        resourceID,
        date,
        time
	);
	
	// Check if resource available
	Resource* reso = resourceManager->getResource(resourceID);
	if (reso != nullptr) {
		if (!reso->isAvailable()) {
			// Waitlist
			waitlist.push(res);
			cout << "Resource unavailable. Adding to waitlist." << endl;
			return true;
		}
		else {
			reso->setAvailability(false);
			
			// Create
			ReservationNode* newNode = new ReservationNode(res);
	
			// Empty list case
			if (head == nullptr) {
				head = newNode;
				tail = head;
			}
			
			// Append item after tail and move tail
			else {
				tail->next = newNode;
				tail = newNode;
			}
			cout << "Reservation created successfully." << endl;
			return true;
		}
	}
	else {
		// Resource doesn't exist
		cout << "Resource ID doesn't correspond to a valid resource." << endl;
		return false;
	}
	
	
	
}

// Search reservation by ID

Reservation* ReservationManager::searchReservationByID(const string& reservationID) {
	
	// Traverse linearly until found or end
	ReservationNode* curr = head;
	
	while (curr != nullptr) {
		if (curr->reservation->getReservationID() == reservationID) {
			//
			return (curr->reservation);
		}
		curr = curr->next;
	}
	// Not found
	return nullptr;
	
}

// Remove reservation by ID

bool ReservationManager::cancelReservation(const string& reservationID) {
	
	// Traverse linearly until found or end
	ReservationNode* curr = head;
	ReservationNode* prev = nullptr;
	
	while (curr != nullptr) {
		if (curr->reservation->getReservationID() == reservationID) {
			
			// Add res to cancel stack
			Reservation* res = curr->reservation;
			cancellations.push(res);
			
			// Remove node from linked list and deallocate
			if (prev == nullptr) {
				head = curr->next;
			}
			else {
				prev->next = curr->next;
			}
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr->next;
	}
	// Not found
	return false;
	
}

// Undo removal, return restored reservation

Reservation* ReservationManager::undoCancellation() {
	
	// Ensure a cancellation exists to undo
	if (!cancellations.empty()) {
		// Create node
		Reservation* res = cancellations.top();
		ReservationNode* newNode = new ReservationNode(res);
			
		// Empty list case
		if (head == nullptr) {
			head = newNode;
			tail = head;
		}
		
		// Append item after tail and move tail
		else {
			tail->next = newNode;
			tail = newNode;
		}
		
		// Remove from cancellation stack
		cancellations.pop();
		return res;
	}
	return nullptr;
	
}

// Prints
void ReservationManager::displayWaitingList() const {
	
	cout << "\n===== Waiting List =====" << endl;
	queue<Reservation*> wlCopy = waitlist;
	for (int i = 0; i <= wlCopy.size(); i++) {
		cout << i << endl;
		wlCopy.front()->display();
		wlCopy.pop();
	}
	
}

void ReservationManager::displayActiveReservations() const {
	
	// Traverse linearly until end
	ReservationNode* curr = head;
	
	while (curr != nullptr) {
		curr->reservation->display();
		curr = curr->next;
	}
	
}

void ReservationManager::generateReport() const {
	
	cout << "===== System Report =====" << endl;
	cout << "\n-Active Reservations-\n" << endl;
	displayActiveReservations();
	cout << "\n-Resource Utilization-\n" << endl;
	resourceManager->displayResourceUtilization();
	cout << "\n-Waiting list status-\n" << endl;
	cout << "# in queue: " << waitlist.size() << endl;
	cout << endl;
	
}