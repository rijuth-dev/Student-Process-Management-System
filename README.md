# Student Process Management System

This repository contains a collection of C programs that simulate core Operating System concepts modeled around a university student registration and resource management system. It demonstrates CPU Scheduling, Concurrency & Synchronization, Deadlock Avoidance, and Memory Management.

## 📂 Project Modules

* **`a1.c` - Multi-level Queue CPU Scheduling (Round Robin):** Simulates a student registration desk where students are placed into priority queues based on their academic year (Seniors, Juniors, Sophomores) and processed using a Round Robin algorithm.
* **`a2.c` - Thread Synchronization (Mutex & Semaphores):** Simulates a concurrent course booking system where multiple student threads attempt to book limited seats in various courses without causing race conditions.
* **`a3.c` - Deadlock Avoidance (Banker's Algorithm):** Simulates a resource allocation system (LabKeys, Projectors, Textbooks, Laptops) to ensure the system remains in a "Safe State" and avoids deadlocks when students request resources.
* **`a4.c` - Memory Management (LRU Page Replacement):** Simulates loading student registration records into limited memory frames using the Least Recently Used (LRU) page replacement algorithm.

---

## ⚙️ Dependencies

To compile and run these programs, you will need:
* A C compiler (e.g., `gcc` or `clang`)
* A POSIX-compliant operating system (Linux/macOS) or Windows with MinGW/WSL
* The POSIX Threads library (`pthread`) is required specifically for `a2.c`.

---

## 🚀 Setup Instructions

1. Clone the repository to your local machine:
   ```bash
   git clone [https://github.com/rijuth-dev/Student-Process-Management-System.git](https://github.com/rijuth-dev/Student-Process-Management-System.git)
   ```
2. Navigate into the project directory:
   ```bash
   cd Student-Process-Management-System
   ```

---

## 🛠️ Compilation and Execution Commands

Open your terminal and use the following commands to compile and run each module. 

**1. CPU Scheduling Simulation (`a1.c`)**
```bash
gcc a1.c -o a1
./a1
```

**2. Thread Synchronization (`a2.c`)**
*Note: This program requires the `-lpthread` flag to link the POSIX threads library.*
```bash
gcc a2.c -o a2 -lpthread
./a2
```

**3. Deadlock Avoidance (`a3.c`)**
```bash
gcc a3.c -o a3
./a3
```

**4. LRU Page Replacement (`a4.c`)**
```bash
gcc a4.c -o a4
./a4
```

---

## 📊 Sample Input and Output

### Module 1 (`a1.c`) - CPU Scheduling
**Input:** *(None required. Generates random burst times and priorities based on seed)*
**Sample Output Snippet:**
```text
================= REGISTRATION INPUT DATA =================
Student ID   | Year Level   | Reg Time Reqd  
-----------------------------------------------------------
ID: 1        | Year: 2      | Time: 5  units
ID: 2        | Year: 4      | Time: 8  units
...
>>> Starting Queue 1: SENIORS (Year 4) (Count: 6) <<<
[Time 000] Student ID 02 (Year 4) runs for 2 units
...
==================== FINAL STATISTICS =====================
Year 4 (Seniors)    - Avg Waiting Time:  12.50 units
Year 3 (Juniors)    - Avg Waiting Time:  14.20 units
Year 2 (Sophomores) - Avg Waiting Time:  10.10 units
===========================================================
```

### Module 2 (`a2.c`) - Thread Synchronization
**Input:** *(None required.)*
**Sample Output Snippet:**
```text
Student 2 trying to book Course 2
Student 2 successfully booked Course 2 | Remaining seats: 7
Student 3 trying to book Course 0
Student 3 successfully booked Course 0 | Remaining seats: 9
Student 4 trying to book Course 1
Student 4 successfully booked Course 1 | Remaining seats: 14
Student 1 trying to book Course 1
Student 1 successfully booked Course 1 | Remaining seats: 13
Student 5 trying to book Course 2
Student 5 successfully booked Course 2 | Remaining seats: 6
```

### Module 3 (`a3.c`) - Banker's Algorithm
**Input:** *(None required. Hardcoded resource matrices)*
**Sample Output Snippet:**
```text
Resources:
R1: LabKey  R2: Projector  R3: Textbook  R4: Laptop

Allocation Matrix:
Student 1 : 1 0 0 0 
...
System is SAFE
Safe Sequence:
Student2 -> Student3 -> Student4 -> Student1
```

### Module 4 (`a4.c`) - LRU Page Replacement
**Required Input:**
When prompted, provide the number of pages, frames, and the page reference sequence.
```text
20
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
```
**Sample Output Snippet:**
```text
Enter number of student registrations (page access): 20
Enter number of frames: 16
Enter registration order (page reference sequence):
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

--- LRU Page Replacement ---

Page 1 → FAULT (Loaded into Frame 0 )
Frames:    1   -    -    -    -    -    -    -    -    -    -    -    -    -    -    -  
...
Page 17 → FAULT (Loaded into Frame 0 by replacing page 1 )
...
Total Page Faults = 20
```

## 👨‍💻 Author

* Name: **Rijuth Kalyan**
* Role: **Tech Lead**
* Programme: **B.Tech Computer Science and Engineering**
* Institution: **NSS College of Engineering, Palakkad**
* Group: **Group 1**
* Student ID: **NSS24CS119**

