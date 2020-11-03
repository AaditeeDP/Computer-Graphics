#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
void makeellipse(int xc,int yc,int Rx,int Ry)
{
int x=0;
int y=Ry;
float p1=(Ry*Ry)-(Rx*Rx*Ry)+(0.25*Rx*Rx);
while((2*Ry*Ry*x) < (2*Rx*Rx*y))
{
putpixel(xc+x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc-x,yc+y,WHITE);
x=x+1;
if(p1<0)
{
y=y;
p1=p1+(2*Ry*Ry*x)+(Ry*Ry);
}
else
{
y=y-1;
p1=p1+(2*Ry*Ry*x)-(2*Rx*Rx*y)+(Ry*Ry);
}
}
Rx=Rx;
Ry=Ry;
float p2=(Ry*Ry*(x+0.5)(x+0.5))+(Rx*Rx(y-1)*(y-1))-Rx*Rx*Ry*Ry;
while(y>0)
{
putpixel(xc+x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc-x,yc+y,WHITE);
y=y-1;
if(p2>0)
{
x=x;
p2=p2-(2*Rx*Rx*y)+(Rx*Rx);
}
else
{
x=x+1;
p2=p2+(2*Ry*Ry*x)-(2*Rx*Rx*y)+(Rx*Rx);
}
}
}

void main()
{
clrscr();
int gd=DETECT,gm;
int xc,yc,Rx,Ry;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
cleardevice();
cout<<"Program to draw ellipse is being implementated ";
cout<<"\nEnter the values of center co-ordinates:";
cin>>xc>>yc;
cout<<"\nEnter the values of the Rx and Ry";
cin>>Rx>>Ry;
makeellipse(xc,yc,Rx,Ry);
getch();
closegraph();
}
