#include "utils.h"

int lerp_step(float a, float b, float dt) {
    float ret = a + (b - a) * dt;
    return ret; 
}
