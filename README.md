# Push_swap - @1337 / 42 Network

## 📊 Overview
Push_swap is a highly efficient algorithm project that involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. 

The goal is to sort a random list of integers using two stacks (**Stack A** and **Stack B**) and a specific set of operations.

## ⚙️ The Challenge
The project is not just about sorting; it's about **optimization**. 
- **3 numbers:** Must be sorted in 3 instructions or fewer.
- **5 numbers:** Must be sorted in 12 instructions or fewer.
- **100 numbers:** Must be sorted in less than 700 operations (for 5 points).
- **500 numbers:** Must be sorted in less than 5500 operations (for 5 points).

## 🛠️ Sorting Strategy
I implemented the **[Name of your Algo, e.g., Turk Algorithm / Radix / Mechanical]** which focuses on:
- **Pre-sorting** chunks of data into Stack B.
- **Calculating the cheapest move** to return elements to Stack A in the correct position.
- **Optimizing rotations** (using `rr` and `rrr`) to save instructions.

## 🚀 Usage
1. Compile:
   ```bash
   make
   ```
2. Run the program:
   ```bash
   ./push_swap 3 2 1 0
   ```
3. Visualize or Check (if using a checker):
   ```bash
   ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
   ```

---
Made by [Abdelhamid] at **1337 (42 Network)**.
