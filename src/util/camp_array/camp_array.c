#include "camp_array.h"

static bool check_index(CampArray* array, size_t index);

CampArray* camp_array_new(size_t type_size) {
    CampArray* new_array = (CampArray*) malloc(sizeof(CampArray));
    
    assert(new_array != NULL);

    *new_array = (CampArray) {
        .type_size = type_size,
        .size = 0,
        .capacity = 0,
        .data = malloc(0)
    };

    return new_array;
}

void camp_array_dump(CampArray* array) {
    for (size_t i = 0; i < array->size; ++i) {
        printf("%zu | ", i);
        uint8_t* item = (uint8_t*) array->data + i * array->type_size;
        
        #ifdef CAMP_ARRAY_PRINT_HEX
        printf("Hex: ");
        for (size_t j = 0; j < array->type_size; ++j) {
            printf("%02X ", item[j]);
        }
        printf("| ");
        #endif /* ifdef CAMP_ARRAY_PRINT_HEX */
        
        #ifdef CAMP_ARRAY_PRINT_DEC
        printf("Dec: ");
        for (size_t j = 0; j < array->type_size; ++j) {
            printf("%u ", item[j]);
        }
        printf("| ");
        #endif /* ifdef CAMP_ARRAY_PRINT_DEC */

        #ifdef CAMP_ARRAY_PRINT_BIN
        printf("Bin: ");
        for (size_t j = 0; j < array->type_size; ++j) {
            for (int k = 7; k >= 0; --k) {
                printf("%d", (item[j] >> k) & 1);
            }
            printf(" ");
        } 
        printf("| ");
        #endif /* ifdef CAMP_ARRAY_PRINT_BIN */
        printf("\n");
    }
}

void camp_array_append(CampArray* array, void* item) {
    if (array->size >= array->capacity) {
        // realloc necessary 
        array->capacity = array->capacity + 1;
        array->data = realloc(array->data, array->capacity * array->type_size);
        if (array->data == NULL) {printf("ERROR: Realloc failed!\n");}
    }
    
    void* ptr_to_index = array->data + array->size * array->type_size;
    memcpy(ptr_to_index, item, array->type_size);

    array->size += 1;
}

void camp_array_insert(CampArray* array, size_t index, void* item) {
    if (check_index(array, index)) {return;}

    if (array->size >= array->capacity) {
        // realloc necessary 
        array->capacity = array->capacity + 1;
        array->data = realloc(array->data, array->capacity * array->type_size);
        if (array->data == NULL) {printf("ERROR: Realloc failed!\n");}
    }
    
    for (size_t i = array->size; i > index; --i) {
        // copy i-1 into i
        memcpy(array->data + i * array->type_size, array->data + (i - 1) * array->type_size, array->type_size);
    }
    
    memcpy(array->data + index * array->type_size, item, array->type_size);

    array->size += 1;

}

void* camp_array_get(CampArray* array, size_t index) {
    if (check_index(array, index)) {return NULL;}

    return array->data + index * array->type_size;
}

void camp_array_set(CampArray* array, size_t index, void* item) {
    if (check_index(array, index)) {return;}

    memcpy(array->data + index * array->type_size, item, array->type_size);
}

void camp_array_remove(CampArray* array, size_t index) {
    if (check_index(array, index)) {
        return;
    }

    size_t bytes_to_move = (array->size - 1 - index) * array->type_size;

    memmove(array->data + index * array->type_size, 
            array->data + (index + 1) * array->type_size,
            bytes_to_move);

    array->size --;
}

size_t camp_array_get_size(CampArray* array) {
    return array->size;
}

bool camp_array_is_empty(CampArray* array) {
    return (array->size == 0) ? true : false;
}

void camp_array_clear(CampArray* array) {
    for (size_t i = 0; i < array->size; ++i) {
        memset(array->data + i * array->type_size, 0, array->type_size);
    }
}

void camp_array_reset(CampArray* array) {
    *array = (CampArray) {
        .size = 0,
        .capacity = 0,
        .data = malloc(0)
    };
}

void camp_array_destroy(CampArray* array) {
    free(array->data);
    free(array);
}

static bool check_index(CampArray* array, size_t index) {
    if (index > array->size - 1) {
        printf("ERROR: failed because index was %zu but size was %zu\n", index, array->size);
        return true;
    }
    return false;
}
