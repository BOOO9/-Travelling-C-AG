
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





void user_input_to_city_Struct()
{


    cityTemp temp_city;

    printf("Geben Sie eine Stadt ein: ");
    fgets(temp_city.city, 50, stdin);

    temp_city.city[strlen(temp_city.city) - 1] = '\0';

    printf("In welchem Land liegt %s: ", temp_city.city);
    fgets(temp_city.country, 50, stdin);

    temp_city.country[strlen(temp_city.country) - 1] = '\0';

    printf("An welchen Laengengrad liegt %s: ", temp_city.city);
    scanf("%f", &temp_city.lat);

    printf("An welchem Breitengrad liegt %s: ", temp_city.city);
    scanf("%f", &temp_city.lat);

    printf("Wie viele Menschen leben in %s: ", temp_city.city);
    scanf("%d", &temp_city.population);

    printf("Was ist der ascii Code von %s: ", temp_city.city);
    fgets(temp_city.city_ascii, 50, stdin);

    temp_city.city_ascii[strlen(temp_city.city_ascii) - 1] = '\0';

    printf("Was ist der ISO2 Code von %s: ", temp_city.city);
    fgets(temp_city.iso2, 3, stdin);

    temp_city.iso2[strlen(temp_city.iso2) - 1] = '\0';

    printf("Was ist der ISO3 Code von %s: ", temp_city.city);
    fgets(temp_city.iso3, 4, stdin);

    temp_city.iso3[strlen(temp_city.iso3) - 1] = '\0';

    printf("Was ist der Admin Name von %s: ", temp_city.city);
    fgets(temp_city.admin_name, 50, stdin);

    temp_city.admin_name[strlen(temp_city.admin_name) - 1] = '\0';

    printf("Capital von %s: ", temp_city.city);
    fgets(temp_city.capital, 50, stdin);

    temp_city.capital[strlen(temp_city.capital) - 1] = '\0';

    printf("Was ist die ID von %s: ", temp_city.city);
    scanf("%d", &temp_city.id);


    printf("\n\n");
    printf("city: %s\n",temp_city.city);
    printf("cityAscii: %s\n",temp_city.city_ascii);
    printf("lat: %f\n",temp_city.lat);
    printf("lng: %f\n",temp_city.lng);
    printf("country: %s\n",temp_city.country);
    printf("iso2: %s\n",temp_city.iso2);
    printf("iso3: %s\n",temp_city.iso3);
    printf("adminName: %s\n",temp_city.admin_name);
    printf("capital: %s\n",temp_city.capital);
    printf("population: %ld\n",temp_city.population);
    printf("id: %ld\n",temp_city.id);


}




void city_struct_to_csv()
{



    cityTemp temp_city;

    char word1[25] = "motherfuckingtest4\n";        //city,"city_ascii","lat","lng","country","iso2","iso3","admin_name","capital","population","id"

    char word2[25];

    //fgets(word2, 25, stdin);

    char filename[20]="test.csv";                   //"worldcities.csv";

    FILE *myfile;

    myfile = fopen(filename,"a");

    if (myfile == NULL)
    {
        printf("Datei nicht gefunden");
        exit(-1);
    }

    fputs(word1, myfile);

    fclose(myfile);


}
*/


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

