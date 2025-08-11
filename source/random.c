/*
Random Number Generation!
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
#include <stdint.h>
#include <time.h>
#include "../include/random.h"
#include <stdint.h>
#include <time.h>

int64_t seed_rng() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (int64_t)ts.tv_sec ^ ((int64_t)ts.tv_nsec << 32);
}

void rng_func(int64_t *random) {
    *random ^= *random << 13;
    *random ^= *random >> 17;
    *random ^= *random << 5;
}
