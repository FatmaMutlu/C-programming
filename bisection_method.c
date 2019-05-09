#include <stdio.h>
#include<math.h> 

float fonk(float A,float B,float C,float x);
int main()
{   
    float A,B,C,deger;
	printf("Denklemin katsayilarini girin A,B,C:\n");
	scanf("%f %f %f",&A,&B,&C);
	printf("%.1fA%.1fB%.1fC \n",A,B,C);
	float a,b,c,f1,f2,f3;
	printf("Aralik girin [a,b] :\n");
	scanf("%f %f",&a,&b);
	printf("[%.1f,%.1f] \n",a,b); 
	printf("Hata degerini girin :");
	scanf("%f",&deger);
	
	int sayac=1;
	do
	  {
		 c=(a+b)/2;
		  f1=fonk(A,B,C,a); 
		  f2=fonk(A,B,C,b);
		  f3=fonk(A,B,C,c);
		  printf("\n%d a=%f b=%f c=%f f(a)=%lf f(b)=%lf f(c)=%lf \n",sayac,a,b,c,f1,f2,f3);

		if(f1*f3<0)
		{
		    b=c;
	        }
		else
		{
		    a=c;
		}
	 
	   sayac++;
	  }while(fabs(a-b)>deger);

}
float fonk(float A,float B,float C,float y)
{
	
	return  (A*(y*y*y)+B*(y)+C);
}


