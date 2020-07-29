#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
void dda(int x1, int y1, int x2, int y2);

void dda(int x1,int y1, int x2, int y2)
{
  int i,dx,dy,steps;
  float x,y;
  float xinc,yinc;
  dx=(x2-x1);
  dy=(y2-y1);
  if ( abs(dx)>= abs(dy))
  steps=dx;
  else
  steps=dy;
  xinc=(float)dx/steps;
  yinc=(float)dy/steps;
  x=x1; 
  y=y1; 
  putpixel(x,y,WHITE); 
  for( i=1; i<steps; i++) 
  {
    if(i%4!=0)
    { 
    putpixel(x,y,WHITE);
    }
  x= x+ xinc; 
  y= y+yinc; 
  } 
}

void main()
{
  clrscr();
  int gd= DETECT, gm;
  int x1,y1,x2,y2;
  initgraph( &gd, &gm,"C:\\TURBOC3\\BGI");
  cleardevice();
  cout<<"\n dda line generating algorithm";
  cout<<"\n starting co-ordinates:";
  cin>>x1>>y1;
  cout<<"\n ending co-ordinates:";
  cin>>x2>>y2;
  dda(x1,y1,x2,y2);
  getch();
  closegraph();
}