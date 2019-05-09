#include <stdio.h>
#include <stdlib.h>

int main (int argc,char *argv[])
{
	int i=0;
    char ch;
    
    FILE *fp;
    FILE *fp2;

    fp = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    
    if(fp!=NULL){
    
    while(ch!=EOF)
	{
		char b[10];
		ch=fgetc(fp);
		int j=0;
		if(ch=='F' || ch == 'f' ){
			
		j++;
		ch=fgetc(fp);

        if(ch=='O' || ch == 'o' ){

        j++;
        ch=fgetc(fp);

        if(ch=='R' || ch == 'r' ){

        j++;
        ch=fgetc(fp);

        if(ch=='(' ){

        j++;
    }}}}

    if(j<4){
    for(i=0;i<j;i++)
      fputc(ch,fp2);
   }
    else{
    while(1){
    ch=fgetc(fp);        
	  fputc(ch,fp2);
        if(ch==';')
           break;
   }
    fprintf(fp2,"\nwhile(");          
    while(1){                           
    ch=fgetc(fp);                     
        if(ch==';')
           break;
    fputc(ch,fp2);
   }

    fputc(')',fp2);                  
    j=0;

	while(1){
    	ch=fgetc(fp);              
		b[j]=ch;
        j++;

        break;
   }
  
   
    while(ch!='}'){                           
    ch=fgetc(fp);
    
    if(ch=='+') continue;
    if(ch==')') continue;
       
    if(ch=='}') break;   
    
	fputc(ch,fp2);

   }
   
	for(i=0;i<j;i++){
		fprintf(fp2,"  %c",b[i]);
		
	}
		
	fprintf(fp2, "++;\n}");

	}
   }
}

	else
	  printf("Dosya bulunamadi.");

    fclose(fp);
    fclose(fp2);
    return 0;
}

