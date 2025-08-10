//
// Created by playf on 8/4/2025.
//

#include <math.h>
#include "../include/saw.h"
void Saw_init(Saw* saw,  int idx,  double leftedge,  double rightedge, char dir)
{
    // initialize the saw

    saw->x = 60.0 * idx - 30.0;
    saw->rx = saw->x;
    if (dir == 'l')
    {
        saw->dx = -4.0;
    }
    else if (dir == 'r')
    {
        saw->dx = 4.0;
    }
    else
    {
        return;
    }
    saw->leftedge = 60.0 * leftedge + 30.0;
    saw->rightedge = 60.0 * rightedge + 30.0;
    saw->dir = dir;
}

void Saw_update(Saw* saw)
{
    // saw tick
    if (saw->dir == 'l')
    {
        saw->dx = (-4.0 - saw->dx) * 0.05 + saw->dx;
        if (saw->x - 57 < saw->leftedge || saw->x - 57 > saw->rightedge)
        {
            // change direction
            saw->dir = 'r';
        }
    }
    else if (saw->dir == 'r')
    {
        saw->dx = (4.0 - saw->dx) * 0.05 + saw->dx;
        if (saw->x + 57 > saw->rightedge || saw->x + 57 < saw->leftedge)
        {
            // change direction
            saw->dir = 'l';
        }
    }
    // update position
    saw->x += saw->dx;
}

void Saw_on_death(Saw* saw, double px)
{
    saw->x = saw->rx;
    if (px < saw->x)
    {
        saw->dir = 'l';
        saw->dx = -fabs(saw->dx);
    }
    else
    {
        saw->dir = 'r';
        saw->dx = fabs(saw->dx);
    }
}