#include <iostream>
#include "ReservationManager.h"
using namespace std;

int main() {

  while true {

    int choice;
    
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
    while (choice < 1 || choice > 9) {
      cout << "Invalid choice, please enter 1-9: ";
      cin >> choice;
    }
  }
  
  return 0;
}
