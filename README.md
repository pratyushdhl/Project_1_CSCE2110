# Project_1_CSCE2110
This is the Git repository for the 1st project of Data Structure and Algorithm. The project is a system of Campus Resource Reservation.

## Team Members & Responsibilities

* **Ethan Rhodes**: Configured custom Data Structures (`LinkedList`, `WaitingQueue`, `UndoStack`), managed waitlist queues, and was able to handle cancellation history logistics.
* **Pratyush Dahal**: Developed `ResourceManager` and `ReservationManager` configuration, implemented file I/O operations for the dataset parsing, and was able to create the CLI menu interface with accurate input reception.
* **Cesar Garcia**: Transcriped ReadME.md report, configured repository build (`.gitignore`), and structured project documentation.

## Data Structures Used
* **`std::vector<Resource>`**: Able to stores resource inventory for traversal as-well as sorting algorithms.
* **Singly Linked List**: Able to store active reservations with efficient insertions/deletions.
* **Queue (FIFO)**: Able to track student's waitlists awhile resources are currently unavailable.
* **Stack (LIFO)**: Able to maintain cancellation history in order to support undo functionality.


## File & Folder Organization
```text
Project1/
├── data/
│   ├── resources.txt         # Pipe-delimited resource data
│   └── reservations.txt      # Pipe-delimited reservation data
├── include/                  # Header files (.h)
│   ├── Resource.h
│   ├── ResourceManager.h
│   ├── Reservation.h
│   └── ReservationManager.h
├── src/                      # Source files (.cpp)
│   ├── main.cpp
│   ├── Resource.cpp
│   ├── ResourceManager.cpp
│   ├── Reservation.cpp
│   └── ReservationManager.cpp
├── .gitignore                # Build artifact & OS ignore rules
└── README.md                 # Project documentation
