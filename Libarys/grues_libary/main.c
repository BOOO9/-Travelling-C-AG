#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void printShortesRoute(cntryTemp list[101], int entries)
{
    printf("Kuerzeste Route:");
    for(int i = 0; i <= entries+1; i++)
    {
        printf("  =>  ");
        printf("%s", list[i].city);
    }
}




void nearestNeighbor(cntryTemp list[20], cntryTemp listShort[20], int entries)
{
    float distance = 1000;
    float shortestDistance = 1000;
    int nextInList = 0;
    float xCoordinate = 0;
    float yCoordinate = 0;
    float totalDistance = 0;


    strcpy(listShort[0].city, "Vienna");
    strcpy(listShort[0].city_ascii, "Vienna");
    listShort[0].lat = 48.2;
    listShort[0].lng = 16.3666;
    strcpy(listShort[0].country, "Austria");
    strcpy(listShort[0].iso2, "AT");
    strcpy(listShort[0].iso3, "AUT");
    strcpy(listShort[0].admin_name, "Wien");
    strcpy(listShort[0].capital, "primary");
    listShort[0].population = 2400000;
    listShort[0].id = 1040261752;



    for(int i = 0; i < entries; i++)
    {
        for(int j = 0; j < entries; j++)
        {
            if(list[j].id > 0)
            {
                xCoordinate = 111.3 * (list[j].lat - listShort[i].lat);
                yCoordinate = 71.5 * (list[j].lng - listShort[i].lng);

                distance = sqrt(pow(xCoordinate, 2.0) + pow(yCoordinate, 2.0));

                //printf("Abstand %s - %s = %f\n", listShort[i].city, list[j].city, distance);

                if(distance != 0 && distance < shortestDistance)
                {
                    shortestDistance = distance;
                    nextInList = j;
                    totalDistance += shortestDistance;
                }
            }
        }

        strcpy(listShort[i+1].city, list[nextInList].city);
        listShort[i+1].lat = list[nextInList].lat;
        listShort[i+1].lng = list[nextInList].lng;
        strcpy(listShort[i+1].country, list[nextInList].country);
        strcpy(listShort[i+1].iso2, list[nextInList].iso2);
        strcpy(listShort[i+1].iso3, list[nextInList].iso3);
        strcpy(listShort[i+1].admin_name, list[nextInList].admin_name);
        strcpy(listShort[i+1].capital, list[nextInList].capital);
        listShort[i+1].population = list[nextInList].population;
        listShort[i+1].population = list[nextInList].population;

        list[nextInList].id = -1;

        shortestDistance = 1000;
    }

    strcpy(listShort[nextInList+2].city, listShort[0].city);
    listShort[nextInList+2].lat = listShort[0].lat;
    listShort[nextInList+2].lng = listShort[0].lng;
    strcpy(listShort[nextInList+2].country, listShort[0].country);
    strcpy(listShort[nextInList+2].iso2, list[0].iso2);
    strcpy(listShort[nextInList+2].iso3, list[0].iso3);
    strcpy(listShort[nextInList+2].admin_name, list[0].admin_name);
    strcpy(listShort[nextInList+2].capital, list[0].capital);
    listShort[nextInList+2].population = list[0].population;
    listShort[nextInList+2].population = list[0].population;


    //printf("\nTotal distance = %f\n\n", totalDistance);
}
