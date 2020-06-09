#ifndef CCHEADER_H_INCLUDED
#define CCHEADER_H_INCLUDED


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

int menu();
void cityInput();
void city_struct_to_csv();
cityTemp* user_input_to_city_Struct();




#endif // CCHEADER_H_INCLUDED
