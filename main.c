#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct zaznam {
   char  kategoria[50];
   char  znacka[50];
   char  predajca[100];
   int   cena;
   int   rok_vyroby;
   char  stav_vozidla[200];
   struct zaznam *dalsi;
}ZAZNAM;

ZAZNAM *n()
{

    FILE *f;
    char c[200];
    int i,z;
    ZAZNAM *z_akt,*z_prvy;
    z=0;
    f=fopen("auta.txt","r");
      if (f==NULL) printf("Zaznami neboli nacitane \n");

        if((z_prvy = (ZAZNAM *)malloc(sizeof(ZAZNAM)))== NULL){
        printf("Malo pamate \n");
        return;}

        fgets(c,100,f);
        z++;

        fgets(c,50,f);
        strcpy(z_prvy->kategoria,c);
        fgets(c,50,f);
        strcpy(z_prvy->znacka,c);
        fgets(c,100,f);
        strcpy(z_prvy->predajca,c);
        fgets(c,100,f);
        i=atoi(c);
        z_prvy->cena=i;
        fgets(c,100,f);
        i=atoi(c);
        z_prvy->rok_vyroby=i;
        fgets(c,200,f);
        strcpy(z_prvy->stav_vozidla,c);

        z_akt=z_prvy;

    while (feof(f) == 0)
    {
        if((z_akt->dalsi = (ZAZNAM *)malloc(sizeof(ZAZNAM)))== NULL){
        printf("Malo pamate \n");
        break;}

        z_akt=z_akt->dalsi;
        fgets(c,100,f);
        z++;


        fgets(c,50,f);
        strcpy(z_akt->kategoria,c);
        fgets(c,50,f);
        strcpy(z_akt->znacka,c);
        fgets(c,100,f);
        strcpy(z_akt->predajca,c);
        fgets(c,100,f);
        i=atoi(c);
        z_akt->cena=i;
        fgets(c,100,f);
        i=atoi(c);
        z_akt->rok_vyroby=i;
        fgets(c,200,f);
        strcpy(z_akt->stav_vozidla,c);




    }
    z_akt->dalsi=NULL;
    printf("Nacitalo sa %i zaznamov \n",z);
    fclose(f);
return z_prvy ;
}

int v(ZAZNAM *z_prvy)
 {
ZAZNAM *z_akt ;
int i;
z_akt= z_prvy;
if (z_prvy==NULL) return 0;
i=1;
    while (z_akt!=NULL)
    {

    printf("%i. \n",i);
    printf("Kategoria: %s \n",z_akt->kategoria);
    printf("Znacka: %s \n",z_akt->znacka);
    printf("Predajca: %s \n",z_akt->predajca);
    printf("Cena: %i \n",z_akt->cena);
    printf("Rok_vyroby: %i \n",z_akt->rok_vyroby);
    printf("Stav_vozidla: %s \n",z_akt->stav_vozidla);
    z_akt=z_akt->dalsi;
    i++;
    }

 return 0;
  }

int p(ZAZNAM *z_prvy)
{
ZAZNAM *z_akt = z_prvy;
ZAZNAM *z_novy;
int h,i,j;
char c[200];
scanf("%i",&h);
z_novy = (ZAZNAM *)malloc(sizeof(ZAZNAM));
i=1;
        while (z_akt!=NULL)
    {
      if (i==h-1) //stred + koniec

        {

        scanf("%s",&c);
        strcpy(z_novy->kategoria,c);
        scanf("%s",&c);
        strcpy(z_novy->znacka,c);
        scanf("%s",&c);
        strcpy(z_novy->predajca,c);
        scanf("%s",&c);
        j=atoi(c);
        z_novy->cena=j;
        scanf("%s",&c);
        j=atoi(c);
        z_novy->rok_vyroby=j;
        scanf("%s",&c);
        strcpy(z_novy->stav_vozidla,c);

        z_novy->dalsi = z_akt->dalsi;
        z_akt->dalsi=z_novy;
        return z_prvy;

        }

       if ((i==1)&&(h==1))//zaciatok
        {

        scanf("%s",&c);
        strcpy(z_novy->kategoria,c);
        scanf("%s",&c);
        strcpy(z_novy->znacka,c);
        scanf("%s",&c);
        strcpy(z_novy->predajca,c);
        scanf("%s",&c);
        j=atoi(c);
        z_novy->cena=j;
        scanf("%s",&c);
        j=atoi(c);
        z_novy->rok_vyroby=j;
        scanf("%s",&c);
        strcpy(z_novy->stav_vozidla,c);

        z_novy->dalsi = z_prvy;
        return z_novy;
        }
i++;
z_akt=z_akt->dalsi;
    }


  }


 int z(ZAZNAM *z_prvy)
{
ZAZNAM *z_akt = z_prvy;;
ZAZNAM *z_pom;
int i,p;
char x[50];
scanf("%s",&x);
z_pom = (ZAZNAM *)malloc(sizeof(ZAZNAM));
i=1;
p=0;


  }


int h(ZAZNAM *z_prvy)
 {
ZAZNAM *z_akt ;
int i,j,p;
z_akt= z_prvy;
if (z_prvy==NULL) return 0;
i=1;
p=0;
scanf("%i",&j);
    while (z_akt!=NULL)
    {

    if (z_akt->cena<=j)
    {
    printf("%i. \n",i);
    printf("Kategoria: %s \n",z_akt->kategoria);
    printf("Znacka: %s \n",z_akt->znacka);
    printf("Predajca: %s \n",z_akt->predajca);
    printf("Cena: %i \n",z_akt->cena);
    printf("Rok_vyroby: %i \n",z_akt->rok_vyroby);
    printf("Stav_vozidla: %s \n",z_akt->stav_vozidla);
    p=1;
    }
    z_akt=z_akt->dalsi;
    i++;
    }
    if (p==0)  printf("su len drahsie auta \n");
 return 0;
  }


int a(ZAZNAM *z_prvy)
 {
ZAZNAM *z_akt ;
int i,j,p;
char c[200],x[50];
z_akt= z_prvy;
if (z_prvy==NULL) return 0;
p=0;
scanf("%s",&x);

scanf("%i",&i);

    while (z_akt!=NULL)
    {

    if ((z_akt->cena==i)&&(strcmp(z_akt->znacka,x)))
    {
        scanf("%s",&c);
        strcpy(z_akt->kategoria,c);
        scanf("%s",&c);
        strcpy(z_akt->znacka,c);
        scanf("%s",&c);
        strcpy(z_akt->predajca,c);
        scanf("%s",&c);
        j=atoi(c);
        z_akt->cena=j;
        scanf("%s",&c);
        j=atoi(c);
        z_akt->rok_vyroby=j;
        scanf("%s",&c);
        strcpy(z_akt->stav_vozidla,c);
        p++;
    }

    z_akt=z_akt->dalsi;
    }
    printf("obnovilo sa %i zoznamov \n",p);
 return 0;
  }



int main()
{
char uloha;
ZAZNAM *z_f;
z_f = (ZAZNAM *)malloc(sizeof(ZAZNAM));
do
{

scanf("%c",&uloha);


switch (uloha) {
   case 'n' : z_f=n(); break;
   case 'v' : v(z_f); break;
   case 'p' : z_f=p(z_f); break;
   case 'z' : z_f=z(z_f); break;
   case 'h' : h(z_f); break;
   case 'a' : a(z_f); break;
   default : break;
}

}
while (uloha!='k');

return 0;
}
