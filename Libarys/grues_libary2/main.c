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

}cityTemp;


void printShortesRoute(cityTemp citys_sorted[101], int entries)
{
    printf("Kuerzeste Route:");

    for(int i = 0; i < entries+2; i++)
    {
        printf("  =>  ");
        printf("%s", citys_sorted[i].city);
    }
}



void nearestNeighbor(cityTemp citys[100], cityTemp citys_sorted[100], int entries)
{




    float distance = 1000;
    float shortestDistance = 1000;
    int nextInList = 0;
    float xCoordinate = 0;
    float yCoordinate = 0;
    float totalDistance = 0;


    strcpy(citys_sorted[0].city, "ZentraleWien");
    strcpy(citys_sorted[0].city_ascii, "Vienna");
    citys_sorted[0].lat = 48.2;
    citys_sorted[0].lng = 16.3666;
    strcpy(citys_sorted[0].country, "Austria");
    strcpy(citys_sorted[0].iso2, "AT");
    strcpy(citys_sorted[0].iso3, "AUT");
    strcpy(citys_sorted[0].admin_name, "Wien");
    strcpy(citys_sorted[0].capital, "primary");
    citys_sorted[0].population = 2400000;
    citys_sorted[0].id = 1040261752;




    for(int i = 0; i < entries; i++)
    {
        for(int j = 1; j < entries+1; j++)
        {


            if(citys[j].id > 0)
            {
                if(citys[j].id == 1040261752) citys[j].lat = 48.3;

                xCoordinate = 111.3 * (citys[j].lat - citys_sorted[i].lat);
                yCoordinate = 71.5 * (citys[j].lng - citys_sorted[i].lng);

                distance = sqrt(pow(xCoordinate, 2.0) + pow(yCoordinate, 2.0));

                //printf("Abstand %s - %s = %f\n", citys_sorted[i].city, citys[j].city, distance);

                if(distance > 0 && distance < shortestDistance)
                {
                    shortestDistance = distance;
                    nextInList = j;
                    totalDistance += shortestDistance;
                }
            }
        }

        strcpy(citys_sorted[i+1].city, citys[nextInList].city);
        citys_sorted[i+1].lat = citys[nextInList].lat;
        citys_sorted[i+1].lng = citys[nextInList].lng;
        strcpy(citys_sorted[i+1].country, citys[nextInList].country);
        strcpy(citys_sorted[i+1].iso2, citys[nextInList].iso2);
        strcpy(citys_sorted[i+1].iso3, citys[nextInList].iso3);
        strcpy(citys_sorted[i+1].admin_name, citys[nextInList].admin_name);
        strcpy(citys_sorted[i+1].capital, citys[nextInList].capital);
        citys_sorted[i+1].population = citys[nextInList].population;
        citys_sorted[i+1].population = citys[nextInList].population;

        citys[nextInList].id = 0;

        shortestDistance = 10000;
    }

    strcpy(citys_sorted[nextInList+1].city, citys_sorted[0].city);
    citys_sorted[nextInList+1].lat = citys_sorted[0].lat;
    citys_sorted[nextInList+1].lng = citys_sorted[0].lng;
    strcpy(citys_sorted[nextInList+1].country, citys_sorted[0].country);
    strcpy(citys_sorted[nextInList+1].iso2, citys[0].iso2);
    strcpy(citys_sorted[nextInList+1].iso3, citys[0].iso3);
    strcpy(citys_sorted[nextInList+1].admin_name, citys[0].admin_name);
    strcpy(citys_sorted[nextInList+1].capital, citys[0].capital);
    citys_sorted[nextInList+1].population = citys[0].population;
    citys_sorted[nextInList+1].population = citys[0].population;


    //printf("\nTotal distance = %f\n\n", totalDistance);


}

