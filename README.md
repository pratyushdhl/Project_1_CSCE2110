# Project_1_CSCE2110
This is the Git repository for the 1st project of Data Structure and Algorithm. The project is a system of Campus Resource Reservation.

## Time & Space Complexity Analysis

| Operation / Structure | Time Complexity | Space Complexity | Description / Reason |
| :--- | :--- | :--- | :--- |
| **Reservation Insertion** (`LinkedList`) | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Constant time head insertion without array shifts. |
| **Reservation Removal** (`LinkedList`) | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ | Linear traversal to locate target node ID, followed by pointer relinking. |
| **Waiting-List Enqueue/Dequeue** (`Queue`) | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Direct pointer ` and 'front` . |
| **Undo Cancellation** (`Stack`) | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Direct push/pop operations at top of stack. |

---

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
