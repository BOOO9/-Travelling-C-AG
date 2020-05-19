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

int main()
{


    menu();

    test_Fnct_Andi();

    printf("\n");

    test_Fnct_Grue();



    return 0;


}





/*
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

*/
