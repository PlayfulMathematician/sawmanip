#include<stdio.h>
#include "utils.h"
void modpair(int* base, int mod, int* remainder) {
    *remainder = *base % mod;
    *base = (*base - *remainder) / mod;
}                                                                                                           // m
void frame_to_time(int frames) {
    int decimal_seconds;
    int seconds;
    int minutes;
    int hours;
    int days;
    modpair(&frames, 30, &decimal_seconds);
    modpair(&frames, 60, &seconds);
    modpair(&frames, 60, &minutes);
    modpair(&frames, 24, &hours);
    modpair(&frames, 30, &days);
    float seconds_tot = (float)decimal_seconds/(float)30 + (float)seconds; // over casting
    printf("Months: %d\nDays: %d\nHours: %d\nMinutes: %d\nSeconds: %.2f\n", frames, days, hours, minutes, seconds_tot);

}