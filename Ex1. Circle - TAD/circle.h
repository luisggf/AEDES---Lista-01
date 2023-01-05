#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#define Pi 3.1415

#include <stdio.h>
#include <stdlib.h>

typedef struct CIRCLE_
{
    float x;
    float y;
    float r;
} circle;

circle *create_circ(float x, float y, float r);
void free_circ(circle *c);
float calc_area(circle *c);
int circ_concentric(circle *c, circle *c1);
int greater_radius(circle *c, circle *c1);




#endif // CIRCLE_H_INCLUDED
