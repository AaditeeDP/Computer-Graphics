#include<ctype.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

void mul(int mat[3][3],int vertex[10][3],int n);
void shear(int vertex[10][3],int n);
void init(int vertex[10][3],int n);

int main()
{
  int i, x,y;
  int vertex[4][3],n;
   cout<<"Shearing Transformation";
  cout<<"Enter the number of vertices: \n1.point\n2.line\n3.triangle\n4.Rectangle/Square\n";
  cin>>n;
  for(i=0;i<n;i++)
     {
	    cout<<"Enter the co-odinates in (x,y) form: ";
	    cin>>x>>y;
	    vertex[i][0]=x;
	    vertex[i][1]=y;
	    vertex[i][2]=1;
     }
	shear(vertex, n);
	return 0;
}
void mul(int mat[3][3],int vertex[10][3],int n)
{
  int i,j,k;
 int res[10][3];
  for(i=0;i<n;i++)
   {
     for(j=0;j<3;j++)
      { 
	     res[i][j]=0;
         for(k=0;k<3;k++)
	      {
	         res[i][j] = res[i][j] + vertex[i][k]*mat[k][j];
	       }
     }
   }
   setcolor(15);
   for(i=0;i<n-1;i++)
    {
       line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1]);
       delay(1000);
     }
     line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1]);
       delay(1000);
}

void shear(int vertex[10][3],int n)
{
   int opt;
   
   int shear_array[3][3];
   cout<<"\n1.x-shear\n2.y-shear\n3. y shear ref\n4. x shear ref\n Enter the shearing you wish to perform:\n";
   cin>>opt;

   switch(opt)
   {
    case 1: int xsh;  
                         cout<<"Enter the x shear : \n";
	        cin>>xsh;
	     shear_array[0][0]=1;
	     shear_array[1][0]=xsh;
	     shear_array[2][0]=0;
	     shear_array[0][1]=0;
	     shear_array[1][1]=1;
	     shear_array[2][1]=0;
	     shear_array[0][2]=0;
	     shear_array[1][2]=0;
	     shear_array[2][2]=1;

	     init(vertex,n);
	     mul(shear_array,vertex,n);
	      break;

	case 2:int ysh;
	       cout<<"Enter the y shear : \n";
	        cin>>ysh;
	   
	    shear_array[0][0]=1;
	    shear_array[1][0]=0;
	    shear_array[2][0]=0;
	    shear_array[0][1]=ysh;
	    shear_array[1][1]=1;
	    shear_array[2][1]=0;
	    shear_array[0][2]=0;
	    shear_array[1][2]=0;
	    shear_array[2][2]=1;
	    init(vertex,n);
	    mul(shear_array,vertex,n);
	     break;

              case 3: int  refy;
	       cout<<"Enter the x shear : \n";
	        cin>>xsh;
	       cout<<"Enter the y ref : \n";
	        cin>>refy;
	 shear_array[0][0]=1;
	 shear_array[1][0]=xsh;
	 shear_array[2][0]=-1*(xsh * refy);
	 shear_array[0][1]=0;
	 shear_array[1][1]=1;
	 shear_array[2][1]=0;
	 shear_array[0][2]=0;
	 shear_array[1][2]=0;
	 shear_array[2][2]=1;
                  init(vertex,n);
	mul(shear_array,vertex,n);
	 break;

              case 4: int refx;
	cout<<"Enter the y shear : \n";
	        cin>>ysh;
	       cout<<"Enter the x ref : \n";
	        cin>>refx;
	 shear_array[0][0]=1;
	 shear_array[1][0]=0;
	 shear_array[2][0]=0;
	 shear_array[0][1]=ysh;
	 shear_array[1][1]=1;
	 shear_array[2][1]=-1*(ysh * refx);
	 shear_array[0][2]=0;
	 shear_array[1][2]=0;
	 shear_array[2][2]=-1;
                  init(vertex,n);
	mul(shear_array,vertex,n);
	 break;
 
     }
 }
void init(int vertex[10][3],int n)
{
   int gd=DETECT,gm,i;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   
   setcolor(15);                 
   line(0,240,640,240);      
   line(320,0,320,480);       

   setcolor(15);

   for(i=0;i<n-1;i++)
    {
       line(320+vertex[i][0],240-vertex[i][1],320+vertex[i+1][0],240-vertex[i+1][1]);
       delay(1000);
     }
     line(320+vertex[n-1][0],240-vertex[n-1][1],320+vertex[0][0],240-vertex[0][1]);
      delay(1000);

}