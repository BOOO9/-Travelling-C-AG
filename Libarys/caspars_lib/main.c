
// Caspars Libary und Funktionen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/Aheader.h"
#include "lib/Gheader.h"
#include "lib/CCheader.h"



// gibt ein pointer in den heap zurück in dem ein dynamisch allokierter Datensatz von Städten steht
// es muss ein pointer zu einem counter übergeben werden der die Anzahl der Städte mitzählt
cityTemp* user_input_to_city_Struct(int *cntr4new)
{


    int cntr = 0;

    int running = 1;
    char choice;

    cityTemp *temp_city = calloc(1, sizeof(cityTemp));

    while(running)
    {

        printf("Geben Sie eine Stadt ein: ");
        fgets(temp_city[cntr].city, 50, stdin);

        temp_city[cntr].city[strlen(temp_city[cntr].city) - 1] = '\0';    // nimmt das '\n' am ende vom String weg und macht ein \0 draus

        printf("In welchem Land liegt %s: ", temp_city[cntr].city);
        fgets(temp_city[cntr].country, 50, stdin);

        temp_city[cntr].country[strlen(temp_city[cntr].country) - 1] = '\0';

        printf("An welchen Breitengrad liegt %s: ", temp_city[cntr].city);
        scanf("%f", &temp_city[cntr].lat);

        printf("An welchem Laengengrad liegt %s: ", temp_city[cntr].city);
        scanf("%f", &temp_city[cntr].lng);

        printf("Wie viele Menschen leben in %s: ", temp_city[cntr].city);
        scanf("%d", &temp_city[cntr].population);

        getchar(); // da sonst die nächste Einlesefnkt nur '\n' liest

        printf("Was ist der ascii Code von %s: ", temp_city[cntr].city);
        fgets(temp_city[cntr].city_ascii, 50, stdin);

        temp_city[cntr].city_ascii[strlen(temp_city[cntr].city_ascii) - 1] = '\0';

        printf("Was ist der ISO2 Code von %s: ", temp_city[cntr].city);
        fgets(temp_city[cntr].iso2, 4, stdin);

        temp_city[cntr].iso2[strlen(temp_city[cntr].iso2) - 1] = '\0';

        printf("Was ist der ISO3 Code von %s: ", temp_city[cntr].city);
        fgets(temp_city[cntr].iso3, 5, stdin);

        temp_city[cntr].iso3[strlen(temp_city[cntr].iso3) - 1] = '\0';

        printf("Was ist der Admin Name von %s: ", temp_city[cntr].city);
        fgets(temp_city[cntr].admin_name, 50, stdin);

        temp_city[cntr].admin_name[strlen(temp_city[cntr].admin_name) - 1] = '\0';

        printf("Capital von %s: ", temp_city[cntr].city);
        fgets(temp_city[cntr].capital, 50, stdin);

        temp_city[cntr].capital[strlen(temp_city[cntr].capital) - 1] = '\0';

        printf("Was ist die ID von %s: ", temp_city[cntr].city);
        scanf("%d", &temp_city[cntr].id);


        printf("\n--------------------------\n\n");
        printf("city: %s\n",temp_city[cntr].city);
        printf("cityAscii: %s\n",temp_city[cntr].city_ascii);
        printf("lat: %f\n",temp_city[cntr].lat);
        printf("lng: %f\n",temp_city[cntr].lng);
        printf("country: %s\n",temp_city[cntr].country);
        printf("iso2: %s\n",temp_city[cntr].iso2);
        printf("iso3: %s\n",temp_city[cntr].iso3);
        printf("adminName: %s\n",temp_city[cntr].admin_name);
        printf("capital: %s\n",temp_city[cntr].capital);
        printf("population: %ld\n",temp_city[cntr].population);
        printf("id: %ld\n",temp_city[cntr].id);



        printf("\n\nWollen sie noch eine Stadt eingeben? (Y/N) ");
        scanf(" %c", &choice);
        getchar();

        if (choice == 'n' || choice == 'N') break;

        cntr++;

        temp_city = realloc(temp_city, sizeof(cityTemp)*(cntr+1));

        printf("\n\n");

    }

    *cntr4new = (cntr+1);

    return temp_city;

}



// bekommt einen Pointer zue einenm Datensatz von Städten den er dann in ein File schreibt
// der counter bestimmt wieviele Städte im Datensatz sind

void city_struct_to_csv(cityTemp *citys, int cntr)
{

    char filename[100] = "newfile.csv"; //"worldcities.csv";

    printf("\nWie heißt die .csv Datei in der Sie die Daten abspeichern wollen? (Sollte die Datei nicht existieren wird eine neue angelegt)\nDateiname: ");
    fgets(filename, 100, stdin);
    filename[strlen(filename) - 1] = '\0';          // nimmt das '\n' am ende vom String weg und macht ein \0 draus

    FILE *fileptr;

    fileptr = fopen(filename,"a");

    if (fileptr == NULL)
    {
        printf("Datei nicht gefunden");
        return;
    }

    for(int i = 0; i < cntr; i++)
    {

        //"city","city_ascii","lat","lng","country","iso2","iso3","admin_name","capital","population","id"

        fprintf(fileptr, "%s,", citys[i].city);
        fprintf(fileptr, "\"%s\",", citys[i].city_ascii);
        fprintf(fileptr, "\"%f\",", citys[i].lat);
        fprintf(fileptr, "\"%f\",", citys[i].lng);
        fprintf(fileptr, "\"%s\",", citys[i].country);
        fprintf(fileptr, "\"%s\",", citys[i].iso2);
        fprintf(fileptr, "\"%s\",", citys[i].iso3);
        fprintf(fileptr, "\"%s\",", citys[i].admin_name);
        fprintf(fileptr, "\"%s\",", citys[i].capital);
        fprintf(fileptr, "\"%ld\",", citys[i].population);
        fprintf(fileptr, "\"%ld\"", citys[i].id);


        fprintf(fileptr, "\n");

    }

    fclose(fileptr);

}



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


void cityInput(int *cntr_ptr, cityTemp *citys)
{
    char temp[50];
    int cntr = *cntr_ptr;
    citys = realloc(citys, (cntr+2)*sizeof(cityTemp));

    getchar();                                                  //damit fgets() nicht das vorangegangenen Leerzeichen einliest

    printf("Geben sie eine Stadt ein: ");
    fgets(temp, 50, stdin);                                     // fegts damit auch Abstände eingelesen werden
    temp[strlen(temp) - 1] = '\0';                              // löscht den Zeilenumbruch am Ende des Strings (falls vorhanden)
    cntr++;
    readcsv(citys, cntr, temp);                                 // holt sich die Daten aus der CSV Datei


    printf("Geben sie noch eine Stadt ein: ");
    fgets(temp, 50, stdin);
    temp[strlen(temp) - 1] = '\0';
    cntr++;
    readcsv(citys, cntr, temp);

    // fragt solange Städte ab bis 0 eingegeben wird oder der counter 100 ereicht
    while(temp[0] != '0')
    {

        printf("Geben sie noch eine Stadt ein (oder '0' wenn Sie fertig sind): ");
        fgets(temp, 50, stdin);
        temp[strlen(temp) - 1] = '\0';

        if(temp[0] != '0')
        {
            cntr++;

            citys = realloc(citys, (cntr+1)*sizeof(cityTemp));
            readcsv(citys, cntr, temp);

            continue;
        }

        else if(temp[0] == '0') break;

    }

    *cntr_ptr = cntr;

}

