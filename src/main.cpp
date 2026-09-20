#include <iostream>
#include <string>
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
	
		switch (choice)
        {
            // Handle choices: View Resources (1)
            case 1:
            {
                resourceManager.displayResources();
                break;
            }

            // Handle choices: Create Reservation (2)
            case 2:
            {
                string reservationID, studentID, studentName, resourceID, date;
                cout << "Reservation ID: ";
                cin >> reservationID;
                cout << "Student ID: ";
                cin >> studentID;
                cout << "Student Name: ";
                cin.ignore();
                getline(cin, studentName);
                cout << "Resource ID: ";
                cin >> resourceID;
                cout << "Date (MM/DD/YYYY): ";
                cin >> date;
                reservationManager.createReservation(reservationID, studentID, studentName, resourceID, date);
                break;
            }

            // Handle choices: Cancel Reservation (3)
            case 3:
            {
                string reservationID;
                cout << "Enter reservation ID to cancel: ";
                cin >> reservationID;
                reservationManager.cancelReservation(reservationID);
                break;
            }

            // Handle choices: View Waiting Lists (4)
            case 4:
            {
                reservationManager.displayWaitingList();
                break;
            }

            // Handle choices: Undo Cancellation (5)
            case 5:
            {
                reservationManager.undoCancellation();
                break;
            }

            // Handle choices: Search Reservations (6)
            case 6:
            {
                string reservationID;
                cout << "Search by Reservation ID: ";
                cin >> reservationID;
				Reservation* res = reservationManager.searchReservationByID(reservationID);
				if (res != nullptr) {
					(*res).display();
				}
                break;
            }

            // Handle choices: Sort Resources (7)
            case 7:
            {
                resourceManager.sortResourcesByName();
                resourceManager.displayResources();
                break;
            }

            // Handle choices: Generate Report (8)
            case 8:
            {
                reservationManager.generateReport();
                break;
            }

            // Handle choices: Exit (9)
            case 9:
            {
                active = false;
                cout << "Exiting the system..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid menu choice." << endl;
                break;
            }
        }
  }
  
  return 0;
}
