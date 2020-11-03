#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
int x[20],y[20];
int px,py,i,n;
void main()
{
int gd=DETECT,gm;
int choice;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
int n;
cout<<"_________________________BEZIER CURVE_________________________";
cout<<"Enter no.of control points\n (Minimum 3 and maximum 4)\n";
cin>>n;
if(n==4){
cout<<"Enter four control points of bezier curve:";
for(i=0;i<4;i++){
 cin>>x[i]>>y[i];
 if(i==0 || i==3)
 putpixel(x[i],y[i],WHITE);
 if(i==1 || i==2)
 putpixel(x[i],y[i],WHITE);
 }
double t;
for(t=0.0;t<=1.0;t+=0.001){
px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
putpixel(px,py,WHITE);
delay(2);
}
}
if(n==3){
cout<<"Enter three control points of bezier curve:";
for(i=0;i<3;i++){
 cin>>x[i]>>y[i];
 if(i==0 || i==2)
 putpixel(x[i],y[i],WHITE);
 if(i==1)
 putpixel(x[i],y[i],WHITE);
 }
double t;
for(t=0.0;t<=1.0;t+=0.001){
px=(1-t)*(1-t)*x[0]+2*t*(1-t)*x[1]+t*t*x[2];
py=(1-t)*(1-t)*y[0]+2*t*(1-t)*y[1]+t*t*y[2];
putpixel(px,py,WHITE);
delay(2);
}

}
delay(1000);
getch();
}
