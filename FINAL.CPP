#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>

void Boundary(int x,int y,int col1,int col2);
void Flood(int x,int y,float col1);

void Boundary(int x,int y,int col1,int col2)
{
	if(getpixel(x,y)!=col2 && getpixel(x,y)!=col1)
	{
		putpixel(x,y,col1);
		Boundary(x+1,y,col1,col2);
		Boundary(x,y+1,col1,col2);
		Boundary(x-1,y,col1,col2);
		Boundary(x,y-1,col1,col2);
	}
}
void Flood(int x,int y,int old,int n)
{
	if(getpixel(x,y) == old)
	{
		putpixel(x,y,n);
		Flood(x+1,y,old,n);
		Flood(x,y+1,old,n);
		Flood(x-1,y,old,n);
		Flood(x,y-1,old,n);
	}
}

int main()
{
	int x,y,option,r;
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"Enter center of the circle \n";
	cin>>x>>y;
	cout<<"Enter radius of circle\n";
	cin>>r;
	cout<<" enter the program to be implemented:\n1.Boundary Fill \n2.Flood Fill\n";
	cin>>option;
	
	circle(x,y,r);
    switch (option)
    {
    case 1 :
        Boundary(x,y,4,15);
        break;
    
    case 2 :
        Flood(x,y,0,15);
	delay(250);
        Flood(x,y,15,4);
	delay(250);
        break;
    }
	
	delay(500);
	closegraph();
	getch();
	return 0;
}
