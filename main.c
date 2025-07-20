/*
 <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2025 bringupyourpost

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
        srand(time(NULL)); 
        int pos;
        int changed = 0;
        char dir;
        if (rand() % 2 == 0) 
        {
            pos = 1000;
        } 
        else 
        {
            pos = 0;   
        }
        srand(time(NULL)); 
        if (rand() % 2 == 0 && 0 == 1) 
        {
            dir = 'l';
        } 
        else 
        {
            dir = 'r';
        }
        srand(time(NULL)); 

        int delay = 19 + rand() % 20; // random delay between 19 and 38
        srand(time(NULL)); 
        for (int i = 0; i < 1000; i++) {rand();} // random stuff
        int seed = rand();
        Saw saw;
        Saw_init(&saw, 2, 1, 3, dir);
        int lasti = 0;
        for (int i = 0; i < 1000000000; i++) 
        {
            Saw_update(&saw);
            if (i - lasti > delay) 
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
                    if (fabs(minspeed) == fabs(saw.dx))
                    {
                        if (e > i)
                        {
                            e = i;
                            changed = 1; 
                        }
                    }
                    else{
                        minspeed = saw.dx; 
                        e = i; 
                        changed = 1; 
                    }
                    
            }
            
        }
        if(changed) {
            printf("New minimum speed found: %d\n", seed);
            printf("Dir %c\n", dir );
            printf("Position: %d\n", pos);
            printf("Delay: %d\n", delay);

            printf("%.20f\n", fabs(minspeed));
            // get order of magnitude
            int order = 0;
            double msa = fabs(minspeed);
            while (msa <= 1.0)
            {
                msa = msa * 10.0;
                order++;            
            }
            printf("Order of magnitude: %d\n", order);
            printf("e: %d\n", e);
        }
    }
}
