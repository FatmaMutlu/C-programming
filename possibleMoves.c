#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main (){
 	int satir,sutun,rastSatir,rastSutun; 
		char tahta[8][8]={  {'X','X','X','X','X','X','X','X'}, 
							{'X','X','X','X','X','X','X','X'},
							{'X','X','X','X','X','X','X','X'},
							{'X','X','X','X','X','X','X','X'},
							{'X','X','X','X','X','X','X','X'},
							{'X','X','X','X','X','X','X','X'},
							{'X','X','X','X','X','X','X','X'},
							{'X','X','X','X','X','X','X','X'}
			    	 
				  };
				  
    	srand ( time(NULL) ); 
    	rastSatir=0+rand()%8; 
    	rastSutun=0+rand()%8;
    	printf("At %d,%d de \n",rastSatir,rastSutun);
    	tahta[rastSatir][rastSutun]='A';
	     
	    {
	     		if((rastSatir-2)>=0&&(rastSutun-1)>=0)
				 tahta[rastSatir-2][rastSutun-1]='1';
				if((rastSatir-1)>=0&&(rastSutun-2)>=0)	
				 tahta[rastSatir-1][rastSutun-2]='2';
				if((rastSatir-2)>=0&&(rastSutun+1)<=7)	
				 tahta[rastSatir-2][rastSutun+1]='3';
				if((rastSatir-1)>=0&&(rastSutun+2)<=7)	
				 tahta[rastSatir-1][rastSutun+2]='4';
				if((rastSatir+2)<=7&&(rastSutun-1)>=0)	
				 tahta[rastSatir+2][rastSutun-1]='5';
				if((rastSatir+1)<=7&&(rastSutun-2)>=0)	
				 tahta[rastSatir+1][rastSutun-2]='6';
				if((rastSatir+2)<=7&&(rastSutun+1)<=7)	
				 tahta[rastSatir+2][rastSutun+1]='7';
				if((rastSatir+1)<=7&&(rastSutun+2)<=7)	
				 tahta[rastSatir+1][rastSutun+2]='8';
			
	     }
    	
    	
	for(satir=0; satir<=7; satir++)
	{
		for(sutun=0; sutun<=7; sutun++)
		{
			printf("%c ",tahta[satir][sutun]);
		}
		printf("\n");
		 
    } 
 }




