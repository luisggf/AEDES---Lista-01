#include "circle.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


circle *create_circ(float x, float y, float r)
{
    circle *new = malloc(1 * sizeof(circle));
    new->x = x;
    new->y = y;
    new->r = r;
    return new;
}

void free_circ(circle *c)
{
    free(c);
}

float calc_area(circle *c)
{
    return Pi * pow(c->r, 2);
}

int circ_concentric(circle *c, circle *c1)
{
    if (c->x == c1->x && c->y == c1->y)
        return 1;
    else
        return 0;
}

int greater_radius(circle *c, circle *c1)
{
    if (c->r >= c1->r)
        return 1; // first circle has greater radius
    else
        return 0;
}
