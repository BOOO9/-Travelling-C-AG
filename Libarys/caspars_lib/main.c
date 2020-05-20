
// Caspars Libary und Funktionen

#include <stdio.h>
#include <string.h>


typedef struct
{
    char city[50];
    char city_ascii[50];
    float lat;
    float lng;
    char country[50];
    char iso2 [3];
    char iso3 [4];
    char admin_name[50];
    char capital[50];
    long population;
    long id;

}cntryTemp;

int menu()
{
    int choice = 0;

    printf("* * * * * * * * * * * * * * * * * * *\n");
    printf("*                                   *\n");
    printf("*  Willkommen zu Travelling C-AG!   *\n");
    printf("*                                   *\n");
    printf("* * * * * * * * * * * * * * * * * * *\n\n");


    printf("Wenn Sie Staedte nach ihrem Namen sortieren wollen..............1\n");
    printf("Wenn Sie die kuerzeste Route zwischen Staedte wissen wollen.....2\n");
    printf("Wenn Sie eine neuen Stadt zur Datenbank hinzufuegen wollen......3\n");
    printf("Wenn Sie das Programm beeden wollen.............................0\n\n");
    scanf("%1d", &choice);



    return choice;
}


void cntryEingabe(int *cntr_ptr, cntryTemp *cntry)
{

    int cntr = *cntr_ptr;

    printf("Geben sie eine Stadt ein: ");

    fgets(cntry[cntr].city, 50, stdin);               // fegts damit auch Abstände eingelesen werden


    if ( (strlen(cntry[cntr].city)) > 0 && cntry[cntr].city[strlen(cntry[cntr].city) - 1] == '\n')          // löscht den Zeilenumbruch am Ende des Strings (falls vorhanden)
    {
        cntry[cntr].city[strlen(cntry[cntr].city) - 1] = '\0';
    }

    cntr++;

    printf("Geben sie noch eine Stadt ein: ");

    fgets(cntry[cntr].city, 50, stdin);


    if ( (strlen(cntry[cntr].city)) > 0 && cntry[cntr].city[strlen(cntry[cntr].city) - 1] == '\n')
    {
        cntry[cntr].city[strlen(cntry[cntr].city) - 1] = '\0';
    }

    cntr++;


    // fragt solange Städte ab bis 0 eingegeben wird oder der counter 100 ereicht
    for(int i = 0; i < 101; i++)
    {

        printf("Geben sie noch eine Stadt ein (oder '0' wenn Sie fertig sind):");
        fgets(cntry[cntr].city, 50, stdin);

        if ( (strlen(cntry[cntr].city)) > 0 && cntry[cntr].city[strlen(cntry[cntr].city) - 1] == '\n')
        {
            cntry[cntr].city[strlen(cntry[cntr].city) - 1] = '\0';
        }

        if(cntry[cntr].city[0] != '0')
        {
            cntr++;
            continue;
        }

        else if(cntry[cntr].city[0] == '0') break;

    }

    *cntr_ptr = cntr;

}
