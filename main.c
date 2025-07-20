#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    double x;
    double rx;
    double dx;
    char dir;
    double leftedge;
    double rightedge;

} Saw;

void Saw_init(Saw* saw,  int idx,  int leftedge,  int rightedge, char dir) 
{
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
        printf("Saw_init: Invalid direction '%c'\n", dir);
        return;
    }
    saw->leftedge = 60.0 * leftedge - 30.0;
    saw->rightedge = 60.0 * rightedge - 30.0;
    saw->dir = dir;
}

void Saw_update(Saw* saw) 
{
    if (saw->dir == 'l') 
    {
        saw->dx = (-4.0 - saw->dx) * 0.05 + saw->dx;
        if (saw->x - 57 < saw->leftedge || saw->x - 57 > saw->rightedge)
        {
            saw->dir = 'r';
        }
    } 
    else if (saw->dir == 'r') 
    {
       saw->dx = (4.0 - saw->dx) * 0.05 + saw->dx;
       if (saw->x + 57 > saw->rightedge || saw->x + 57 < saw->leftedge) 
       {
           saw->dir = 'l';
       }
    }
    saw->x += saw->dx;
}

int main() 
{
    Saw saw;
    Saw_init(&saw, 1, 1, 1, 'l');
    double minspeed = 10000.0;
    for (int i = 0; i < 100000000; i++) 
    {
        Saw_update(&saw);
        if (fabs(saw.dx) < fabs(minspeed)) 
        {
            minspeed = fabs(saw.dx);
            printf("saw.dx: %f\n", saw.dx);
        }
    }
    return 0;
}
