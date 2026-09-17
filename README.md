# Project_1_CSCE2110
This is the Git repository for the 1st project of Data Structure and Algorithm. The project is a system of Campus Resource Reservation.

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
