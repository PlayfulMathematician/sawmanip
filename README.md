# Saw Manip

Hi, welcome to my saw manipulator project. This is a project that simulates saws in Appel, the scratch game by griffpatch. It tries random saw manipulations to find the smallest saw speed. The goal is 0 speed. But the minimum is around 5 * 10^-13. It is written in C.  If you find a new min make a pull request.
This is licensed under the GNU General Public License v3.0. I will update this later.
```
Seed is 18359475303061273792
Dir r
Position: 0
Delay: 24
0.00000000000050270899
Order of magnitude: 13
Year: 0
Months: 11
Days: 17
Hours: 11
Minutes: 3
Seconds: 20.57
```

# How to build
Open this open and cd into it. Now use make a build directory and cd into it then do 
``cmake ..``
then do 
``cmake --build .``
This will build it and you will have a file that you can execute. 

# Directory Structure
There are 4 relevant files. 
main.c - The program that handles all the top level saw stuff.
saw.c - The program that has the saw struct and all relevant saw logic.
random.c - The RNG Program (this needs to exist so this code can run the same on all computers given the same seed)
utils.c - The program for utils
