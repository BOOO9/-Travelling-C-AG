#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib/CCheader.h"
#include "lib/Aheader.h"
#include "lib/Gheader.h"



int main()
{


    cityTemp *citys = malloc(sizeof(cityTemp));
    cityTemp *citys_sorted = malloc(sizeof(citys));


    int running = 1;
    int cntr = 0;
    int cntr4new = 0;

    while (running == 1)                            //Menü Schleife
    {
        cntr = 0;

        int choice = menu();                        //menu() gibt Zahl von 0-3 zurück; 1 = Städte nach Namen sortieren; 2 = Travelling SP; 3 = Städte zur CSV hinzufügen

        switch(choice)
        {

            case 1:
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

                break;

            }

            case 2:
            {


                cityInput(&cntr, citys);

                nearestNeighbor(citys, citys_sorted, cntr);

                printShortesRoute(citys_sorted, cntr);

                for(int i = 1; i < cntr+1; i++)                             // test ob die Daten eingelesen werden
                    {

                        printf("\n\ncity: %s\n",citys_sorted[i].city);

                        printf("---------------------------------------------");

                    }


                //Eingabe von Städtenamen
                //TSM-Problem

                break;
            }
            case 3:

            {



                break;
            }

            case 0:

                running = 0;
                break;


            default:

                printf("Error");

                running = 0;
                break;



        }



    }

    return 0;

}

