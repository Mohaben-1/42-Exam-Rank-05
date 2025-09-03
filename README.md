# 🧠 42cursus - Exam Rank 05

This repository contains solutions for the 42cursus **Exam Rank 05**, which is composed of two levels of increasingly difficult coding exercises.

---

## 🧩 Level 1

### ✅ `polyset`
- **Goal**: Implement a polymorphic set structure built on top of existing bag implementations.  
- **Details**:
  - Extend the provided `array_bag` and `tree_bag` classes by creating `searchable_array_bag` and `searchable_tree_bag`.  
  - These inherit from their respective `bag` classes and the abstract `searchable_bag` class.  
  - Implement a `set` class that wraps a `searchable_bag` and ensures **set semantics** (no duplicates).  
- **Focus**:  
  - C++ polymorphism and inheritance.  
  - Abstract classes & dynamic dispatch.  
  - Orthodox Canonical Form (constructor, destructor, copy constructor, copy assignment).  


### ✅ `bigint`
- **Goal**: Implement an arbitrary precision integer class.
- **Features**:
  - Construction from integers and strings.
  - Operator overloading (`+`, `-`, `*`, `/`, `%`, comparisons).
  - Stream output (`<<`).
- **Key Concepts**: Memory management, operator overloading, efficient string-based arithmetic.

### ✅ `vect2`
- **Goal**: Implement a 2D vector class with basic operations.
- **Features**:
  - Constructors, copy/assignment, destructor.
  - Operator overloading for addition, subtraction, scalar operations, and indexing.
  - Stream output (`<<`).
- **Focus**: C++ class design, encapsulation, and operator overloading.

---

## ⚙️ Level 2

### ✅ `bsq` (Biggest Square)
- **Goal**: Parse a text-based map and find the largest square without obstacles.
- **Algorithm**: Dynamic Programming (`dp[i][j] = 1 + min(top, left, diag)`).
- **Output**: Map with the biggest square filled with the designated full character.
- **Key Concepts**: File parsing, validation, dynamic programming, edge case handling.

### ✅ `life` (Game of Life)
- **Goal**: Implement Conway’s Game of Life.
- **Rules**:
  - Any live cell with 2 or 3 neighbors survives.
  - Any dead cell with exactly 3 neighbors becomes alive.
  - Otherwise, the cell dies or remains empty.
- **Focus**: Simulation using grids, handling boundaries, iterative updates.

---

## 📌 Notes

- All projects are implemented in **C and C++**, depending on the subject.
- Each level has a strict time constraint, testing both algorithmic thinking and code clarity.
- Repository is organized by level and subject, each with its own directory and source files.

---

## 📚 Learnings

- Gained deeper mastery of **C++ class design** with constructors, destructors, and operator overloading.
- Mastery of C++ polymorphism, operator overloading, and canonical form.
- Experience handling big integers, sets, and vector classes from scratch.
- Confidence with dynamic programming and grid-based algorithms.
- Solid grasp of both object-oriented design and algorithmic problem-solving.
- Practiced **dynamic programming, and simulation algorithms**.
- Balanced **speed and correctness** under exam conditions.

---

## 🏁 Final Thoughts

Exam Rank 05 pushed me to combine **algorithmic problem solving** with **C++ object-oriented design**.  
It was a great bridge between system-level programming in C and higher-level abstractions in C++.
