#include "../include/ReservationManager.h"

using namespace std;

// ReservationNode Constructor

ReservationNode::ReservationNode(Reservation r) {
	this->reservation = reservation;
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
	
	ReservationNode* newNode = new ReservationNode(*res);
		
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
	
}

// Remove reservation by ID

bool ReservationManager::cancelReservation(const string& reservationID) {
	
	// Traverse linearly until found or end
	ReservationNode* curr = head;
	ReservationNode* prev = nullptr;
	
	while (curr != nullptr) {
		if (curr->reservation.getReservationID() == reservationID) {
			// Clone reservation and add to cancel stack
			Reservation res = curr->reservation;
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

// Undo removal

bool ReservationManager::undoCancellation() {
	
	// Create node
	Reservation res = cancellations.top();
	ReservationNode* newNode = new ReservationNode(*res);
		
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
	
}

// Prints
void ReservationManager::displayWaitingList() const {
	
	cout << "\n===== Waiting List =====" << endl;
	
	
}

void ReservationManager::displayActiveReservations() const {
	
	// Traverse linearly until end
	ReservationNode* curr = head;
	
	while (curr != nullptr) {
		curr->reservation.display();
		curr = curr->next;
	}
	
}