#include <stdio.h>
#include <stdlib.h>
#include "lib/CCheader.h"
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

}cntryTemp;

cntryTemp cntry[100];

int cntr = 0;
int *cntr_ptr = &cntr;



int main()
{
    int running = 1;

    int position=1;
    char cityName[50] = "Ennadai";

    readcsv(cntry, position, cityName);

    printf("%f\n", cntry[1].lat);



/*
    while (running == 1)                            //Men� Schleife
    {
        int choice = menu();                        //menu() gibt Zahl von 0-3 zur�ck

        if (choice == 1)
        {

            cntryEingabe(cntr_ptr, cntry);          // liest St�dte in das cntry[] Array ein und erh�t f�r jede Stadt den Pointer um 1

            //St�dte sortiert ausgeben
            //system("cls");
        }
        else if (choice == 2)
        {
            //Eingabe von St�dtenamen
            //TSM-Problem

        }
        else if (choice == 3)
        {
            //Hinzuf�gen von St�dten

        }
        else if (choice == 0) running = 0;

        else running = 0;

    }
    */


}


