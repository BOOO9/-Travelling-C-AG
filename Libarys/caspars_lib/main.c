
// Caspars Libary und Funktionen

#include <stdio.h>
#include <string.h>
#include "lib/Aheader.h"
#include "lib/Gheader.h"




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

}cityTemp;



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
    printf("\n\n");


    return choice;
}


void cityInput(int *cntr_ptr, cityTemp city[100])
{
    char temp[50];

    int cntr = *cntr_ptr;

    scanf("%c", &temp);                                             //damit fgets() nicht das vorangegangenen Leerzeichen einliest

    printf("Geben sie eine Stadt ein: ");

    fgets(temp, 50, stdin);                                         // fegts damit auch Abstände eingelesen werden

    if ( (strlen(temp)) > 0 && temp[strlen(temp) - 1] == '\n')      // löscht den Zeilenumbruch am Ende des Strings (falls vorhanden)
    {
        temp[strlen(temp) - 1] = '\0';
    }

    cntr++;
    readcsv(city, cntr, temp);                                     // holt sich die Daten aus der CSV Datei

    printf("Geben sie noch eine Stadt ein: ");

    fgets(temp, 50, stdin);


    if ( (strlen(temp)) > 0 && temp[strlen(temp) - 1] == '\n')
    {
        temp[strlen(temp) - 1] = '\0';
    }

    cntr++;
    readcsv(city, cntr, temp);

    // fragt solange Städte ab bis 0 eingegeben wird oder der counter 100 ereicht
    for(int i = 0; i < 101; i++)
    {

        printf("Geben sie noch eine Stadt ein (oder '0' wenn Sie fertig sind): ");
        fgets(temp, 50, stdin);

        if ( (strlen(temp)) > 0 && temp[strlen(temp) - 1] == '\n')
        {
            temp[strlen(temp) - 1] = '\0';
        }

        if(temp[0] != '0')
        {
            cntr++;
            readcsv(city, cntr, temp);
            continue;
        }

        else if(temp[0] == '0') break;

    }

    *cntr_ptr = cntr;

}

/*
int main()
{

    cityInput (&cntr, city);

    printf("%f", city[1].lat);



}

*/
