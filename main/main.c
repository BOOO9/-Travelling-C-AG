#include <stdio.h>
#include <stdlib.h>
//#include "lib/CCheader.h"

int menu();

typedef struct
{
    char city[25];
    char city_ascii[25];
    float lat;
    float lng;
    char country[25];
    char iso2 [2];
    char iso3 [3];
    char admin_name[25];
    char capital[25];
    long population;
    long id;

}cntryTemp;

cntryTemp cntry[50];

int main()
{
    int running = 1;


    while (running == 1)
    {
        int choice = menu();        //menu gibt Zahl von 0-3 zurück

        if (choice == 1)
        {
            //Eingabe von Städtenamen
            //Städte sortiert ausgeben
            system("cls");
        }
        else if (choice == 2)
        {
            //Eingabe von Städtenamen
            //TSM-Problem

        }
        else if (choice == 3)
        {
            //Hinzufügen von Städten

        }
        else if (choice == 0) running = 0;

        else running = 0;

    }


}
