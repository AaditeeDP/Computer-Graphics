#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main()
{
    float x,y,x1,y1,x2,y2,dx,dy,steps;
    int gd=DETECT,gm;
    int i;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cout<<"Enter the first point";
    cin>>x1>>y1;
    cout<<"enter the second point";
    cin>>x2>>y2;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if (dx>dy)
        steps = dx;
    else
        steps = dy;
    x= x1;
    y = y2;
    while(i<=steps)
    {
        putpixel(x,y,5);
        x = x + dx;
        y = y + dy;
        i++;
        delay(100);
    }
    closegraph();
}