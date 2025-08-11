#include "utils.h"
#include <stdlib.h>
#include <time.h>

int random_in_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

int lerp_step(float a, float b, float dt) {
    float ret = a + (b - a) * dt;
    return ret; 
}
