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

			if(todoBulmaDurumu==1 && karakter!='\n')  //TODO kelimesini bulduktan sonra sat�r sonuna kadar yazd�r�r.
			 fprintf(file2, "%c",karakter);
			
			if(sayac==0 && karakter=='T' )     // TODO i�in  ilk T ye bakar varsa sayac artar  A�AMA :T  SAYA�:1
				sayac++; 
			else if(sayac==1 && karakter=='O') //TODO i�in ikinci deger i�in O ya bakar ve sayac� kontrol eder.Varsa Sayac artar  A�AMA:TO    SAYA�:2
				sayac++; 
			else if(sayac==2 &&  karakter=='D') //TODO i�in ���nc� deger i�in D ya bakar ve sayac� kontrol eder.Varsa Sayac artar  A�AMA:TOD    SAYA�:3
				sayac++; 
		    else if(sayac==3 && karakter=='O') //TODO i�in d�rd�nc� deger i�in O ya bakar ve sayac� kontrol eder.Varsa Sayac artar  A�AMA:TODO    SAYA�:2
				sayac++;
			else                               //Bunlardan biri saglam�yor ise TODO bulunamaz.Sayac 0 olur.S�ras�yla T,O,D ve O yu kontrol etmelidir.
		          sayac=0;

			if(sayac==4){  //TODO bulundu sayac 4 oldugu i�in todoBulmaDurumu durumu aktif oldu
			 todoBulmaDurumu=1;  
			}
			if(karakter=='\n'){  // Sat�r sonuna gelince
				if(todoBulmaDurumu==1){ //todoBulmaDurumu aktif ise yazd�g� dosyada alt alta olmas� i�in bir sat�r sonu koydu
				     fprintf(file2,"\n"); 
				}
			 	todoBulmaDurumu=0; //Sat�r sonu oldugundan dolay�  todoBulmaDurumu pasif oldu
			}
		}
	}
	 
	fclose(file);
}
