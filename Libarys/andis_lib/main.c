#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void test_Fnct_Andi()
{
    printf("Hallo Welt \n LG Andi");
}
*/

/*
typedef struct dataElement
{
    char city[50];
    char cityAscii[50];
    float lat;
    float lng;
    char country[50];
    char iso2[3];
    char iso3[4];
    char adminName[50];
    char capital[50];
    long population;
    long id;
};
*/

void test_Fnct_Andi(struct cntryTemp searchCity[], int position, char cityName[])
{
    struct cntryTemp dataTemp;

    char puffer[200];
    char delimiter[]="\"";
    char *puffer_ptr;

    int dataEntry=0;
    char *compare=",";
    int emptyField=0;

    FILE* myfile;
    char filename[20]="worldcities.csv";


//    printf("Geben sie den Dateinamen inkl Endung an: ");
//    gets(filename);
//    printf("Geben sie den Namen der Stadt ein: ");
//    gets(cityName);

    myfile=fopen(filename,"r");
    if (myfile == NULL)
    {
        printf("Datei nicht gefunden");
        return -1;
    }
    else
    {
        fgets(puffer,200,myfile);
//        for(int i=0;i<6;i++)
        while(NULL!=fgets(puffer,200,myfile))
        {
//            fgets(puffer,200,myfile);
            puffer_ptr = strtok(puffer, delimiter);
            dataEntry=0;

            while(puffer_ptr != NULL)
            {
                emptyField=0;
                while (strcmp (puffer_ptr,compare) == 0)
                {
                    if(emptyField>0)
                    {
                        dataEntry++;
                    }
                    emptyField++;
                    puffer_ptr = strtok(NULL, delimiter);
                }
                switch(dataEntry)
                {
                    case 0: strcpy(dataTemp.city,puffer_ptr);
                    break;
                    case 1: strcpy(dataTemp.city_ascii,puffer_ptr);
                    break;
                    case 2: dataTemp.lat = atof(puffer_ptr);
                    break;
                    case 3: dataTemp.lng = atof(puffer_ptr);
                    break;
                    case 4: strcpy(dataTemp.country,puffer_ptr);
                    break;
                    case 5: strcpy(dataTemp.iso2,puffer_ptr);
                    break;
                    case 6: strcpy(dataTemp.iso3,puffer_ptr);
                    break;
                    case 7: strcpy(dataTemp.admin_name,puffer_ptr);
                    break;
                    case 8: strcpy(dataTemp.capital,puffer_ptr);
                    break;
                    case 9: dataTemp.population = atol(puffer_ptr);
                    break;
                    case 10: dataTemp.id = atol(puffer_ptr);
                    break;
                }
                if(dataEntry<10)
                {
                    dataEntry++;
                    puffer_ptr = strtok(NULL, delimiter);
                }
                else
                {
                    puffer_ptr = NULL;
                }
            }
            if(strcmp(dataTemp.city_ascii,cityName)==0)
            {
                searchCity[position]=dataTemp;
                printf("city: %s\n",searchCity[position].city);
                printf("cityAscii: %s\n",searchCity[position].city_ascii);
                printf("lat: %f\n",searchCity[position].lat);
                printf("lng: %f\n",searchCity[position].lng);
                printf("country: %s\n",searchCity[position].country);
                printf("iso2: %s\n",searchCity[position].iso2);
                printf("iso3: %s\n",searchCity[position].iso3);
                printf("adminName: %s\n",searchCity[position].admin_name);
                printf("capital: %s\n",searchCity[position].capital);
                printf("population: %ld\n",searchCity[position].population);
                printf("id: %ld\n",searchCity[position].id);
                break;
            }
        }
    }
    fclose(myfile);
    return;
}

/*
int main()
{
    struct dataElement searchCity[100];
    int position=0;
    char cityName[50]="New York";

    readcsv(searchCity, position, cityName);

    return 0;
}
*/
