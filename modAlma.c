#include<stdio.h>

int main(){
	
	int sayi,i;
    printf("Lutfen 9 basamakli sayi giriniz:");
	scanf("%d",&sayi);
    int sayi1=sayi;
	int k,toplam=0;
	
	for(i=2; i<=10;i +=2)
	if(sayi>0)	
    {
		k=sayi% 10; //Bu döngüde sayimizin basamak degerlerini carpýp,
	    k=k*i;     //toplayarak toplam degeri hesapladýk..
		toplam +=k; //toplam degeri sürekli toplayarak toplama atadýk...
		sayi = sayi / 10;
	}
	
	printf("Toplam= %d\n",toplam); // Toplam sonuc (10*rakam1+9*rakam2+......+2*rakam9)
	toplam=toplam%11;
	printf("Kalan= %d\n",toplam); // Toplam sonucun 11 ile bölümünden kalan
	toplam=11-toplam;
	printf("Eklenecek sayi= %d\n",toplam); // Toplam sonucun 11 ile bölünebilmesi icin gereken sayi
	
	
    if(toplam==10 || toplam==11)
      printf("Bu sayi uygun degil.");
    else
    
    printf("Sayinin son hali= %d%d",sayi1,toplam); // 9 basamakli sayiyla birlikte eklenmiþ sayi 

   
}
