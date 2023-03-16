#include <stdio.h>
typedef struct person{
    int id;
    char first_name[32];
    char last_name[32];
} person_t;
int main()
{
   FILE* wfp;
   wfp = fopen("person.bin","w+");
   person_t p[5]={
       {1,"IU","Lee"},
       {1,"IUU","Lee"},
       {1,"IUUU","Lee"},
       {1,"IUUUU","Lee"},
       {1,"IUUUUU","Lee"},
   };
   for(int i=0;i<5;i++){
       fwrite(p+i,sizeof(person_t),1,wfp);
   }
   fclose(wfp);
   
   FILE* rfp=fopen("person.bin","r");
   person_t tmp;
   int i=0;
   while(fread(&tmp,sizeof(person_t),1,rfp)){
       printf("[%d] %d: %s %s\n", i ,tmp.id,tmp.first_name,tmp.last_name);
       i++;
   }
   fclose(rfp);
}
