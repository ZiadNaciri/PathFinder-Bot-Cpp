#include "figure.h"
#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

// Using macros to convert degree to radian
// and call sin() and cos() as these functions
// take input in radians
#define SIN(x) sin(x * 3.14159265358979323846/180)
#define COS(x) cos(x * 3.14159265358979323846/180)

int figure::rotate1(int x,int y, int xc,int yc, float angle)
{

        float i0=x;
        float i1=y;
        // Shifting the pivot point to the origin
        // and the given points accordingly
        int x_shifted = i0 - xc;
        int y_shifted = i1 - yc;
        // Calculating the rotated point co-ordinates
        // and shifting it back
        i0= (x_shifted*COS(angle)- y_shifted*SIN(angle));
        i1 = (x_shifted*SIN(angle)+ y_shifted*COS(angle));
        i0=i0+xc;
        i1=i1+yc;
        x=rint(i0);
        y=rint(i1);

    return x;
}
