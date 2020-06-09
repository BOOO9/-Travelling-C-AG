#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

}cityTemp;

cityTemp citys[100];
cityTemp citys_sorted[100];



int main()
{
    int running = 1;
    int cntr = 0;

    while (running == 1)                            //Menü Schleife
    {
        cntr = 0;

        int choice = menu();                        //menu() gibt Zahl von 0-3 zurück

        if (choice == 1)
        {

            cityInput(&cntr, citys);                // liest Städte in das citys[] Array ein und füllt das Array mit den Daten aus der CSV

                for(int i = 1; i < cntr+1; i++)                             // test ob die Daten eingelesen werden
                {

                    printf("\n\ncity: %s\n",citys[i].city);
                    printf("cityAscii: %s\n",citys[i].city_ascii);
                    printf("lat: %f\n",citys[i].lat);
                    printf("lng: %f\n",citys[i].lng);
                    printf("country: %s\n",citys[i].country);
                    printf("iso2: %s\n",citys[i].iso2);
                    printf("iso3: %s\n",citys[i].iso3);
                    printf("adminName: %s\n",citys[i].admin_name);
                    printf("capital: %s\n",citys[i].capital);
                    printf("population: %ld\n",citys[i].population);
                    printf("id: %ld\n\n",citys[i].id);
                    printf("---------------------------------------------");

                }



            //system("cls");
        }
        else if (choice == 2)
        {


            cityInput(&cntr, citys);
            printf("\n\n\n\n-------------------------------\n\n\n");


            printf("\n\ncntr %d\n\n", cntr);


            nearestNeighbor(citys, citys_sorted, cntr);

            printShortesRoute(citys_sorted, cntr);


            for(int i = 1; i < cntr+1; i++)                             // test ob die Daten eingelesen werden
                {

                    printf("\n\ncity: %s\n",citys_sorted[i].city);

                    printf("---------------------------------------------");

                }

            printf("\n\n");


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

