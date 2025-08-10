#ifndef SAW_H
#define SAW_H

typedef struct {
    double x;
    double rx;
    double dx;
    char dir;
    double leftedge;
    double rightedge;
} Saw;

void Saw_init(Saw* saw, int idx, double leftedge, double rightedge, char dir);
void Saw_update(Saw* saw);
void Saw_on_death(Saw* saw, double px);

#endif // SAW_H
