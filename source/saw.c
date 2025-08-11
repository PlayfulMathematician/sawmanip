/*
Saw Simulation!
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
#include <math.h>
#include "../include/saw.h"

#include <stdlib.h>

void Saw_init(Saw* saw,  int idx,  double leftedge,  double rightedge, char dir)
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
        exit(1);
    }
    saw->leftedge = 60.0 * leftedge + 30.0;
    saw->rightedge = 60.0 * rightedge + 30.0;
    saw->dir = dir;
}

void Saw_update(Saw* saw)
{
    char opposite_dir;
    double dirx;
    if (saw->dir == 'l')
    {
        dirx = -1.0;
        opposite_dir = 'r';
    }
    else if (saw->dir == 'r')
    {
        opposite_dir = 'l';
        dirx = 1.0;
    }
    else
    {
        exit(1);
    }
    saw->dx = (4*dirx - saw->dx) * 0.05 + saw->dx;
    if (saw->x + dirx*57 < saw->leftedge || saw->x + dirx*57 > saw->rightedge)
    {
        saw->dir = opposite_dir;
    }
    saw->x += saw->dx;
}

void Saw_on_death(Saw* saw, double px)
{
    saw->x = saw->rx;
    saw->dx = fabs(saw->dx);
    if (px < saw->x)
    {
        saw->dir = 'l';
        saw->dx = -saw->dx;
    }
    else
    {
        saw->dir = 'r';
    }
}