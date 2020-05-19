#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ersteZeile()
{
    char puffer[200];
    char delimiter[]="\"";
    char *puffer_ptr;
    int dataEntry=0;
    const char *compare=",";
    int emptyField=0;

    FILE* myfile;
    char filename[20];

    printf("Geben sie den Dateinamen inkl Endung an: ");
    scanf("%s", filename);
    myfile=fopen(filename,"r");
    if (myfile == NULL)
    {
        printf("Datei nicht gefunden");
        return -1;
    }
    else
    {
        fgets(puffer,200,myfile);
        for(int i=0;i<1;i++)
        {
            fgets(puffer,200,myfile);
            puffer_ptr = strtok(puffer, delimiter);
            dataEntry=0;

            while(puffer_ptr != NULL) {
                emptyField=0;
                while (strcmp (puffer_ptr,compare) == 0){
                    if(emptyField>0)
                    {
                        dataEntry++;
                    }
                    emptyField++;
                    puffer_ptr = strtok(NULL, delimiter);
                }
                switch(dataEntry)
                {
                    case 0: strcpy(city,puffer_ptr);
                    printf("city: %s\n",city);
                    break;
                    case 1: strcpy(cityAscii,puffer_ptr);
                    printf("cityAscii: %s\n",cityAscii);
                    break;
                    case 2: lat = atof(puffer_ptr);
                    printf("lat: %f\n",lat);
                    break;
                    case 3: lng = atof(puffer_ptr);
                    printf("lng: %f\n",lng);
                    break;
                    case 4: strcpy(country,puffer_ptr);
                    printf("country: %s\n",country);
                    break;
                    case 5: strcpy(iso2,puffer_ptr);
                    printf("iso2: %s\n",iso2);
                    break;
                    case 6: strcpy(iso3,puffer_ptr);
                    printf("iso3: %s\n",iso3);
                    break;
                    case 7: strcpy(adminName,puffer_ptr);
                    printf("adminName: %s\n",adminName);
                    break;
                    case 8: strcpy(capital,puffer_ptr);
                    printf("capital: %s\n",capital);
                    break;
                    case 9: population = atol(puffer_ptr);
                    printf("population: %ld\n",population);
                    break;
                    case 10: id = atol(puffer_ptr);
                    printf("id: %ld\n",id);
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
        }
    }
    fclose(myfile);

    return 0;
}
