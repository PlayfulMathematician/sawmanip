#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// saw struct definition
typedef struct {
    double x;
    double rx; // root x
    double dx;
    char dir;
    double leftedge;
    double rightedge;

} Saw;

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
        printf("Saw_init: Invalid direction '%c'\n", dir);
        return;
    }
    saw->leftedge = 60.0 * leftedge - 30.0;
    saw->rightedge = 60.0 * rightedge - 30.0;
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
// whenever the player dies, reset the saw position
// i will not use this yet.
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

int main() 
{
   double minspeed = 10000.0;
   int e = 100000;
    while (1) {
        // set clock 
        Saw saw;
        // initialize saw
        srand(time(NULL)); // seed random number generator
        int pos;
        if (rand() % 2 == 0) 
        {
            pos = 1000;
        } 
        else 
        {
            pos = 0;   
        }
        Saw_init(&saw, 2, 1, 3, 'l');
        int lasti = 0;
        for (int i = 0; i < 100000000; i++) 
        {
            Saw_update(&saw);
            if (i - lasti > 30) 
            {
               int rng = rand();
               if (rng % 4 == 2)
               {
                Saw_on_death(&saw, pos); // reset saw position
                lasti = i; // reset lasti
               }
               
            }
           
            if (fabs(saw.dx) <= fabs(minspeed)) // if new min speed  
            {   
                if ( fabs(saw.dx) < fabs(minspeed) || (fabs(saw.dx) == fabs(minspeed))) 
                {   
                    if (fabs(minspeed) == fabs(saw.dx))
                    {
                        if (e > i)
                        {
                            e = i;
                        }
                    }
                    else{
                        minspeed = saw.dx; 
                        e = i; // set new min speed
                    }
                    
                }
            }
        }
        printf("%.20f\n", fabs(minspeed));
        printf("e: %d\n", e);
    }
}
