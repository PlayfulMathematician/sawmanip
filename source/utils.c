/*
Utils Lol!
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

#include<stdio.h>
#include "utils.h"
void modpair(int* base, int mod, int* remainder) {
    *remainder = *base % mod;
    *base = (*base - *remainder) / mod;
}                                                                                                           // m
void frame_to_time(int frames) {
    int decimal_seconds, seconds, minutes, hours, days, months;
    modpair(&frames, 30, &decimal_seconds);
    modpair(&frames, 60, &seconds);
    modpair(&frames, 60, &minutes);
    modpair(&frames, 24, &hours);
    modpair(&frames, 30, &days);
    modpair(&frames, 12, &months);
    float seconds_tot = (float)decimal_seconds/(float)30 + (float)seconds;
    printf("Year: %d\nMonths: %d\nDays: %d\nHours: %d\nMinutes: %d\nSeconds: %.3f\n", frames, months, days, hours, minutes, seconds_tot);
} //m —