#include <stdio.h>
#include <stdlib.h>

struct ogrenci{
	char ad[20];
	int vize;
	int final;
	float ort;
	char *harf;
	char *durumu;
	
};

void dosyaYaz(char *girdi);
void hesapla(char*girdi,char *cikti);

int main(){
	char *girdiler = "input.txt";
    char *ciktilar = "output.txt";

    dosyaYaz(girdiler);
    hesapla(girdiler,ciktilar);
    return 0;
	
}
void dosyaYaz(char *girdi)

{
	int i,boyut;
	struct ogrenci ogr[boyut];
	FILE *dosya;
	if((dosya=fopen(girdi,"w"))==NULL){
		printf("Dosya acilamadi..");
	}
	else{
		printf("Ogrenci sayisini giriniz :"); scanf("%d",&boyut);
		fprintf(dosya,"%d\n",boyut);
		for(i=0; i<boyut; i++){
			printf("Ogrenci adi: ");  scanf("%s",&ogr[i].ad);
			printf("Vize : ");  scanf("%d",&ogr[i].vize);
			printf("Final :");  scanf("%d",&ogr[i].final);
			fprintf(dosya,"%s %d %d\n",ogr[i].ad,ogr[i].vize,ogr[i].final);
		}
	}
	fclose(dosya);
	
}
void hesapla(char*girdi,char *cikti) {
	int i,boyut;
	
	FILE *dosya;
	dosya=fopen(girdi,"r");
	fscanf(dosya,"%d",&boyut);
	struct ogrenci ogr[boyut];
	for(i=0; i<boyut; i++){
		fscanf(dosya,"%s %d %d",ogr[i].ad,&ogr[i].vize,&ogr[i].final);
	}
	fclose(dosya);
	for(i=0; i<boyut; i++){
		ogr[i].ort=ogr[i].vize*0.4+ogr[i].final*0.6;
		
	    if(ogr[i].ort>45 && ogr[i].ort<55)
			ogr[i].harf="DC";
		else if(ogr[i].ort>55 && ogr[i].ort<60)
			ogr[i].harf="CC";
		else if(ogr[i].ort>60 && ogr[i].ort<70)
		    ogr[i].harf="CB";
		else if(ogr[i].ort>70 && ogr[i].ort<75)
           ogr[i].harf="BB";
        else if(ogr[i].ort>75 && ogr[i].ort<85)
           ogr[i].harf="BA";
    	else if(ogr[i].ort>85)
           ogr[i].harf="AA";
        else 
           ogr[i].harf="FF";
           
           if(ogr[i].harf=="FF")
           ogr[i].durumu="kaldi";
           else
           ogr[i].durumu="gecti";
        
	}
	
	dosya=fopen(cikti,"w");
	for(i=0; i<boyut; i++){
		fprintf(dosya,"\n%s %d %d %.1f %s %s\n",ogr[i].ad,ogr[i].vize,ogr[i].final,ogr[i].ort,ogr[i].harf,ogr[i].durumu);
	}
	
	
  fclose(dosya);
	
}









