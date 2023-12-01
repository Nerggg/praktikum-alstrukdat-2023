#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

int main(){
    POINT p1,p2,p3;
    int a, b, c, atasC, bawahC, atasB, bawahB;
    float x1, x2, x3, y1, y2, y3;

    BacaPOINT(&p1);
    BacaPOINT(&p2);
    BacaPOINT(&p3);

    x1 = Absis(p1); 
    y1 = Ordinat(p1);
    x2 = Absis(p2); 
    y2 = Ordinat(p2);
    x3 = Absis(p3); 
    y3 = Ordinat(p3);

    c = (((y3-y2)/(x3-x2))-((y2-y1)/(x2-x1)))/(x3-x1);
    b = ((y3-y2) - (x3-x2)*(x3+x2)*c)/(x3-x2);
    a = y1 - x1*b - (x1*x1)*c;

    printf("%d\n", a);
    return 0;
}
