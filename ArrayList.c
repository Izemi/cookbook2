/*
 * File Name: ArrayList.c
 * Author: Ozan Erat
 * Date: 2/6/2025
 * Version: 1.0.
 * Description: 
 *   Implementation of ArrayList for the Cookbook2 lab
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Meal.h"
#include "ArrayList.h"

/* Internal helper function declarations.
   These are not declared in the header to keep them private. */
void expand_meallist(MealList *list);
void shrink_meallist(MealList *list);

#define INITIAL_CAPACITY 2  // Initial dynamic array capacity

// Internal definition of MealList structure (opaque)
struct mealList_instance_t {
    int length;
    int capacity;
    Meal **meals;  // Array of pointers to Meal structs
};

// Create and initialize a new MealList with dynamic array of pointers
MealList* meallist_create() {

    // Allocate memory on heap for a MealList and use pointer named 'list'.
    MealList *list = malloc(sizeof(MealList));
    if (list == NULL) {
        fprintf(stderr, "Failed to allocate memory for MealList\n");
        exit(EXIT_FAILURE);
    }

    list->length = 0;
    list->capacity = INITIAL_CAPACITY;

    // Allocate memory on heap for meals array of pointers to Meal structs.  
    list->meals = malloc(list->capacity * sizeof(Meal *));
    if (list->meals == NULL) {
        fprintf(stderr, "Failed to allocate memory for meals array\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    
    return list;
}


// Function to insert a meal at the end of the list with dynamic expansion
void meallist_insert_meal(MealList *list, Meal *m) {
  
    // Check if the list is full and expand if needed
    if (list->length >= list->capacity) {
        expand_meallist(list);
    }

    // Insert the meal at the end of the list, store pointer to Meal struct
    list->meals[list->length] = m;
    list->length++;
}

// Expand the MealList capacity by doubling it
void expand_meallist(MealList *list) {
    printf("\nExpanding capacity from %d to %d\n\n", list->capacity, list->capacity * 2);
    list->capacity *= 2;

   // Reallocate memory for the expanded array of pointers
   Meal **temp = realloc(list->meals, list->capacity * sizeof(Meal *));
   if (temp == NULL) {
       fprintf(stderr, "Failed to expand MealList\n");
       exit(EXIT_FAILURE);
   }
   list->meals = temp;
}

// Free the memory used by MealList
void meallist_destroy(MealList *list) {
    for (int i = 0; i < list->length; i++) {
        // Destroy each meal in the list
        meal_destroy(list->meals[i]);
    }
    // Free the array of pointers
    free(list->meals);
    // Free the MealList itself
    free(list);
}


// OPTIONAL:
// Complete the function below to remove a meal from the list and shrink if needed

void meallist_remove_meal(MealList *list, int index) {
    if (index < 0 || index >= list->length) {
        fprintf(stderr, "Invalid index for removal: %d\n", index);
        return;
    }
    // Destroy the meal at the given index
    meal_destroy(list->meals[index]);

    // Shift remaining meals to fill the gap
    for (int i = index; i < list->length - 1; i++) {
        list->meals[i] = list->meals[i + 1];
    }
    list->length--;

    // Shrink the list if necessary (optional)
    if (list->length > 0 && list->length <= list->capacity / 4) {
        shrink_meallist(list);
    }
}

// OPTIONAL:
// Shrink the MealList capacity by halving it. Use realloc for resizing.
void shrink_meallist(MealList *list) {
    int new_capacity = list->capacity / 2;
    if (new_capacity < INITIAL_CAPACITY) {
        new_capacity = INITIAL_CAPACITY;
    }
    if (new_capacity < list->capacity) {
        Meal **temp = realloc(list->meals, new_capacity * sizeof(Meal *));
        if (temp == NULL) {
            fprintf(stderr, "Failed to shrink MealList\n");
            return;  // Not fatal; keep the current capacity
        }
        list->meals = temp;
        list->capacity = new_capacity;
        printf("\nShrinking capacity to %d\n\n", new_capacity);
    }
}

// Function to print all meals in the list
void meallist_print(const MealList *list) {
    for (int i = 0; i < list->length; i++) {
        meal_print(list->meals[i]);
    }
}
