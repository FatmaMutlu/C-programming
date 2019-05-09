#include <stdio.h> 

void main (int argc,char *argv[])
{
	char *dosyaAdi,*todoListFile; 
	dosyaAdi=argv[1]; 
	todoListFile=argv[2]; 
	
	FILE *file,*file2; 
	char karakter;
	int sayac=0;
	int todoBulmaDurumu=0;

	 file2=fopen(todoListFile,"w");
     file=fopen(dosyaAdi,"r");
     
	if(file!=NULL){
		while(!feof(file)) 
		{
			fscanf(file,"%c",&karakter); 

			if(todoBulmaDurumu==1 && karakter!='\n')  //TODO kelimesini bulduktan sonra satýr sonuna kadar yazdýrýr.
			 fprintf(file2, "%c",karakter);
			
			if(sayac==0 && karakter=='T' )     // TODO için  ilk T ye bakar varsa sayac artar  AÞAMA :T  SAYAÇ:1
				sayac++; 
			else if(sayac==1 && karakter=='O') //TODO için ikinci deger için O ya bakar ve sayacý kontrol eder.Varsa Sayac artar  AÞAMA:TO    SAYAÇ:2
				sayac++; 
			else if(sayac==2 &&  karakter=='D') //TODO için üçüncü deger için D ya bakar ve sayacý kontrol eder.Varsa Sayac artar  AÞAMA:TOD    SAYAÇ:3
				sayac++; 
		    else if(sayac==3 && karakter=='O') //TODO için dördüncü deger için O ya bakar ve sayacý kontrol eder.Varsa Sayac artar  AÞAMA:TODO    SAYAÇ:2
				sayac++;
			else                               //Bunlardan biri saglamýyor ise TODO bulunamaz.Sayac 0 olur.Sýrasýyla T,O,D ve O yu kontrol etmelidir.
		          sayac=0;

			if(sayac==4){  //TODO bulundu sayac 4 oldugu için todoBulmaDurumu durumu aktif oldu
			 todoBulmaDurumu=1;  
			}
			if(karakter=='\n'){  // Satýr sonuna gelince
				if(todoBulmaDurumu==1){ //todoBulmaDurumu aktif ise yazdýgý dosyada alt alta olmasý için bir satýr sonu koydu
				     fprintf(file2,"\n"); 
				}
			 	todoBulmaDurumu=0; //Satýr sonu oldugundan dolayý  todoBulmaDurumu pasif oldu
			}
		}
	}
	 
	fclose(file);
}
