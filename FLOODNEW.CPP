#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<ctype.h>
#include<dos.h>

void floodfill(int x, int y, int a,int b)
	{
		if(getpixel(x,y) == b)
			{
				putpixel(x,y,a);
				floodfill(x+1,y,a,b);
				delay(10);
				floodfill(x-1,y,a,b);
				delay(10);
				floodfill(x,y+1,a,b);
				delay(10);
				floodfill(x,y-1,a,b);
				delay(10);
			}
	}

int main()
{
	int gd = DETECT, gm;
	int x1,y1,r;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	cout<<"Flood fill algorithm is being implemented\n";
	cout<<"enter the value of center of circle\n";
	cin>>x1>>y1;
	cout<<"Enter the radius of the circle\n";
	cin>>r;
	circle(x1,y1,r);
	floodfill(x1,y1,0,12);
	closegraph();
	getch();
	return 0;
}