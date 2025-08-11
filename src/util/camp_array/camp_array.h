#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// #define CAMP_ARRAY_PRINT_HEX
#define CAMP_ARRAY_PRINT_DEC
#define CAMP_ARRAY_PRINT_BIN

typedef struct {
    void* data;
    size_t size;
    size_t capacity;

    size_t type_size;
} CampArray;

CampArray* camp_array_new(size_t type_size);

// dump the array with possible print options defined in config.h
void camp_array_dump(CampArray* array);

// append something
void camp_array_append(CampArray* array, void* item);

// insert something
void camp_array_insert(CampArray* array, size_t index, void* item);

// get something
void* camp_array_get(CampArray* array, size_t index);

// set something (you get the idea)
void camp_array_set(CampArray* array, size_t index, void* item);

// remove an element and push every element past that "one space left"
void camp_array_remove(CampArray* array, size_t index);

// returns the size
size_t camp_array_get_size(CampArray* array);

// true if size == 0
bool camp_array_is_empty(CampArray* array);

// memsets every element to 0
void camp_array_clear(CampArray* array);

// equivalent of calling camp_array_new but only malloc'ing the data not the whole struct
void camp_array_reset(CampArray* array);

// free the array and the data ptr
void camp_array_destroy(CampArray* array);
