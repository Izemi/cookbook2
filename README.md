# Lab 2 : Cookbook2

## **Lab Description**
   Dynamic ArrayList Implementation with opaque structs

## **Objectives**
This lab aims to reinforce your understanding of dynamic memory management, data structures, and procedural programming in C. You will implement a dynamic `ArrayList` structure this time to store and manage a collection of `Meal` structures. The lab will require you to:

- Create and manage a dynamic array.
- Implement insertion, deletion, and resizing operations.
- Properly allocate and free memory to prevent leaks.
- Develop and execute unit tests for validation. We are providing some, but it is expected that you add more tests to `unittest.c`.

---

## **Files Overview**
The project consists of the following files:

- `ArrayList.c` / `ArrayList.h` – Implements a dynamic array to store `Meal` structures.
- `Meal.c` / `Meal.h` – Defines a `Meal` structure and associated operations.
- `cookbook.c` – The driver program that reads meal names from a file and stores them in the dynamic list.
- `unittest.c` – Provides unit tests for core functionalities.
- `meal_names.txt` – Contains a list of meal names for testing.
- `Makefile` – Automates the compilation process.

---

## **Tasks to Complete**
Follow the procedural order below to implement missing functionalities.You will also find them as `TODO` in the code. 

### **1. Implement the Dynamic ArrayList**
- **File:** `ArrayList.c`
- **Functions to complete:**
  1. **`meallist_create()`**: 
     - Allocate memory for a `MealList` struct.
     - Allocate an initial array of pointers for meals (size `INITIAL_CAPACITY`).
  2. **Analyze how a `meal`is created** 
     - This part has already been implemented. You are expected to analyze the memory allocation and pointer handling.    
  3. **`meallist_insert_meal(MealList *list, Meal *m)`**:
     - Check if the list is full; if so, expand it.
     - Insert the new meal at the end.
  4. **`expand_meallist(MealList *list)`**:
     - Reallocate memory for the expanded array.
  5. **`meallist_destroy(MealList *list)`**:
     - Free each `Meal` stored in the list.
     - Free the array of pointers.
     - Free the `MealList` struct itself.
     - If you're confused about the number of frees, ask for clarification/help. 

### **2. Run and Test Your Implementation**
- **Compile your code:**
   `make`
- **Execute it:**
   `make run` or `./cookbook`
- **Use Valgrind to check memory leaks and errors:**
   `make valgrind` or `valgrind ./cookbook`
- **Run unit tests to verify functionality.**
   `make test`
   `./unittest`

### **3. Submission**

- Submit all files to the Gradescope. We would like to see your progress. 

### **4. Optional Challenges: Implement Meal Removal**
- **File:** `ArrayList.c`
- **Functions to complete:**
  1. **`meallist_remove_meal(MealList *list, int index)`**:
     - Remove a meal from the list.
     - Shift remaining meals.
     - Shrink capacity if necessary (optional).
     - Make sure to uncomment necessary lines. (after line ~40) 
  2. **`shrink_meallist(MealList *list)`** (Optional):
     - Reduce the capacity when the list size decreases significantly.

### **Recommended Analysis**
   - Play with the `list->capacity *= 2;` 
      - Try += 1 instead of *=2
      - Search how you can do time analysis in C. 

### **Questions**
   - Why didn't we declare the functions expand and shrink in the interface `ArrayList.h`?