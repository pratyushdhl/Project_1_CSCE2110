# Complexity Report

## Overview
This document is the complete analysis for the time and space complexity of key operations within the Campus Resource Reservation System. This structure utilizes dynamic data structures like Singly Linked Lists, Queue, Stack, and Vectors for the end goal of resource inventory management.

## 1. Linked Lists (Reservation Operations)

Reservation Insertion: $\mathcal{O}(1)$ 
  Explanation: When commiting the action of inserting an active reservation at head of tail of linked list; thus causing the operation to take constant time $\mathcal{O}(1)$. Traversing targeted list is mandatory when checking for duplicate IDs

Reservation Removal: $\mathcal{O}(N)$
  Explanation: List must be traversed in sequence when canceling a reservation. If 'Item not Found', $N$ nodes are visited.
