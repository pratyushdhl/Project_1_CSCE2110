# Project_1_CSCE2110
This is the Git repository for the 1st project of Data Structure and Algorithm. The project is a system of Campus Resource Reservation.

## Team Members & Responsibilities

* **Ethan Rhodes**: Implemented custom Data Structures (`LinkedList`, `WaitingQueue`, `UndoStack`), managed waitlist FIFO queues, and handled cancellation history logic.
* **Pratyush Dahal**: Developed `ResourceManager` and `ReservationManager` classes, implemented file I/O operations for dataset parsing, and created the CLI menu interface with robust input validation.
* **Cesar Garcia**: Authored the Time and Space Complexity Analysis report, configured repository build ignore rules (`.gitignore`), and structured project documentation.

## Data Structures Used
* **`std::vector<Resource>`**: Stores resource inventory for fast traversal and sorting algorithms.
* **Singly Linked List**: Stores active reservations dynamically with efficient dynamic insertions/deletions.
* **Queue (FIFO)**: Tracks student waiting lists when resources are currently unavailable.
* **Stack (LIFO)**: Maintains cancellation history to support undo functionality.


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
