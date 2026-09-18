#include <iostream>
#include "../include/ReservationManager.h"
using namespace std;

int main() {

	bool active = true;
	int choice;

	// Managers
	ResourceManager resourceManager;
	resourceManager.loadResources("../data/resources.txt");
	ReservationManager reservationManager(&resourceManager);
	
	// Unique ID
	int currentID = 0;

	while (active) {

		// User input prompt
		cout << "===== Campus Resource Reservation System =====" << endl;
		cout << "\n1. View Resources" << endl;
		cout << "2. Create Reservation" << endl;
		cout << "3. Cancel Reservation" << endl;
		cout << "4. View Waiting Lists" << endl;
		cout << "5. Undo Cancellation" << endl;
		cout << "6. Search Reservations" << endl;
		cout << "7. Sort Resources" << endl;
		cout << "8. Generate Report" << endl;
		cout << "9. Exit" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
    
		// Correct invalid choices
		while (choice < 1 || choice > 9) {
			cout << "Invalid choice, please enter 1-9: ";
			cin >> choice;
		}
	
		// Handle choices: View Resources (1)
		if (choice == 1) {
			resourceManager.displayResourceAvailability();
		}
		
		// Handle choices: Create Reservation (2)
		if (choice == 2) {
			string reservationID, studentID, resourceID, date, time;
			reservationID = to_string(currentID);
			currentID++;
			cout << "Student ID: ";
			cin >> studentID;
			cout << "Resource ID: ";
			cin >> resourceID;
			cout << "Date: ";
			cin >> date;
			cout << "Time: ";
			cin >> time;
		
			reservationManager.createReservation(
				reservationID, studentID, resourceID, date, time
			);
		}
		
		// Handle choices: Cancel Reservation (3)
		if (choice == 3) {
			
		}
		
		// Handle choices: View Waiting Lists (4)
		if (choice == 4) {
			
		}
		
		// Handle choices: Undo Cancellation (5)
		if (choice == 5) {
			
		}
		
		// Handle choices: Search Reservations (6)
		if (choice == 6) {
			
		}
		
		// Handle choices: Sort Resources (7)
		if (choice == 7) {
			
		}
		
		// Handle choices: Generate Report (8)
		if (choice == 8) {
			
		}
		
		// Handle choices: Exit (9)
		if (choice == 9) {
			active = false;
		}
	
  }
  
  return 0;
}
