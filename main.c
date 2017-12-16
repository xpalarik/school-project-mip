#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
    char  category[50];
    char  brand[50];
    char  dealer[100];
    int   price;
    int   year;
    char  type[200];
    struct record *next;
} RECORD;

RECORD *n();
int v(RECORD *r_first);
int p(RECORD *r_first);
int h(RECORD *r_first);
int a(RECORD *r_first);

int main()
{
    char uloha;
    RECORD *r_first;
    r_first = (RECORD *)malloc(sizeof(RECORD));
    do
    {
        scanf("%c",&uloha);
        switch (uloha)
        {
        case 'n' :
            r_first=n();
            break;
        case 'v' :
            v(r_first);
            break;
        case 'p' :
            r_first=p(r_first);
            break;
        case 'h' :
            h(r_first);
            break;
        case 'a' :
            a(r_first);
            break;
        default :
            break;
        }
    }
    while (uloha!='k');
    return 0;
}

RECORD *n()
{

    FILE *fcars;
    char line[200];
    int number,counter;
    RECORD *r_act,*r_first;
    counter=0;
    fcars=fopen("auta.txt","r");
    if (fcars==NULL) printf("No records loaded. \n");
    if((r_first = (RECORD *)malloc(sizeof(RECORD)))== NULL)
    {
        printf("Low memory. \n");
        return;
    }
    fgets(line,100,fcars);
    counter++;
    fgets(line,50,fcars);
    strcpy(r_first->category,line);
    fgets(line,50,fcars);
    strcpy(r_first->brand,line);
    fgets(line,100,fcars);
    strcpy(r_first->dealer,line);
    fgets(line,100,fcars);
    number=atoi(line);
    r_first->price=number;
    fgets(line,100,fcars);
    number=atoi(line);
    r_first->year=number;
    fgets(line,200,fcars);
    strcpy(r_first->type,line);
    r_act=r_first;
    while (feof(fcars) == 0)
    {
        if((r_act->next = (RECORD *)malloc(sizeof(RECORD)))== NULL)
        {
            printf("Low memory. \n");
            break;
        }
        r_act=r_act->next;
        fgets(line,100,fcars);
        counter++;
        fgets(line,50,fcars);
        strcpy(r_act->category,line);
        fgets(line,50,fcars);
        strcpy(r_act->brand,line);
        fgets(line,100,fcars);
        strcpy(r_act->dealer,line);
        fgets(line,100,fcars);
        number=atoi(line);
        r_act->price=number;
        fgets(line,100,fcars);
        number=atoi(line);
        r_act->year=number;
        fgets(line,200,fcars);
        strcpy(r_act->type,line);
    }
    r_act->next=NULL;
    printf("%i records loaded. \n",counter);
    fclose(fcars);
    return r_first ;
}

int v(RECORD *r_first)
{
    RECORD *r_act ;
    int counter;
    r_act= r_first;
    if (r_first==NULL) return 0;
    counter=1;
    while (r_act!=NULL)
    {
        printf("%i. \n",counter);
        printf("Category: %s \n",r_act->category);
        printf("Brand: %s \n",r_act->brand);
        printf("Dealer: %s \n",r_act->dealer);
        printf("Price: %i \n",r_act->price);
        printf("Year: %i \n",r_act->year);
        printf("Type: %s \n",r_act->type);
        r_act=r_act->next;
        counter++;
    }
    return 0;
}

int p(RECORD *r_first)
{
    RECORD *r_act = r_first;
    RECORD *r_new;
    int put_in,counter,number;
    char line[200];
    scanf("%i",&put_in);
    r_new = (RECORD *)malloc(sizeof(RECORD));
    counter=1;
    while (r_act!=NULL)
    {
        if (counter==put_in-1) //stred + koniec
        {
            scanf("%s",&line);
            strcpy(r_new->category,line);
            scanf("%s",&line);
            strcpy(r_new->brand,line);
            scanf("%s",&line);
            strcpy(r_new->dealer,line);
            scanf("%s",&line);
            number=atoi(line);
            r_new->price=number;
            scanf("%s",&line);
            number=atoi(line);
            r_new->year=number;
            scanf("%s",&line);
            strcpy(r_new->type,line);
            r_new->next = r_act->next;
            r_act->next=r_new;
            return r_first;
        }
        if ((counter==1)&&(put_in==1))//zaciatok
        {
            scanf("%s",&line);
            strcpy(r_new->category,line);
            scanf("%s",&line);
            strcpy(r_new->brand,line);
            scanf("%s",&line);
            strcpy(r_new->dealer,line);
            scanf("%s",&line);
            number=atoi(line);
            r_new->price=number;
            scanf("%s",&line);
            number=atoi(line);
            r_new->year=number;
            scanf("%s",&line);
            strcpy(r_new->type,line);
            r_new->next = r_first;
            return r_new;
        }
        counter++;
        r_act=r_act->next;
    }
}

int h(RECORD *r_first)
{
    RECORD *r_act ;
    int counter,search_price,switch_c;
    r_act= r_first;
    if (r_first==NULL) return 0;
    counter=1;
    switch_c=0;
    scanf("%i",&search_price);
    while (r_act!=NULL)
    {
        if (r_act->price<=search_price)
        {
            printf("%i. \n",counter);
            printf("Category: %s \n",r_act->category);
            printf("Brand: %s \n",r_act->brand);
            printf("Dealer: %s \n",r_act->dealer);
            printf("Price: %i \n",r_act->price);
            printf("Year: %i \n",r_act->year);
            printf("Type: %s \n",r_act->type);
            switch_c=1;
        }
        r_act=r_act->next;
        counter++;
    }
    if (switch_c==0)  printf("There are only more costly cars. \n");
    return 0;
}

int a(RECORD *r_first)
{
    RECORD *r_act ;
    int search_price,number,counter;
    char line[200],search_brand[50];
    r_act= r_first;
    if (r_first==NULL) return 0;
    counter=0;
    scanf("%s",&search_brand);
    scanf("%i",&search_price);
    while (r_act!=NULL)
    {
        if ((r_act->price==search_price)&&(strcmp(r_act->brand,search_brand)))
        {
            scanf("%s",&line);
            strcpy(r_act->category,line);
            scanf("%s",&line);
            strcpy(r_act->brand,line);
            scanf("%s",&line);
            strcpy(r_act->dealer,line);
            scanf("%s",&line);
            number=atoi(line);
            r_act->price=number;
            scanf("%s",&line);
            number=atoi(line);
            r_act->year=number;
            scanf("%s",&line);
            strcpy(r_act->type,line);
            counter++;
        }
        r_act=r_act->next;
    }
    printf("i% records updated. \n",counter);
    return 0;
}

