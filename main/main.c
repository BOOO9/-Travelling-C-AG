#include <stdio.h>
#include <stdlib.h>
#include "lib/CCheader.h"



int main()
{
    int running = 1;


    while (running == 1)
    {
        int choice = menu();        //menu gibt Zahl von 0-3 zur�ck

        if (choice == 1)
        {
            //Eingabe von St�dtenamen
            //St�dte sortiert ausgeben
            system("cls");
        }
        else if (choice == 2)
        {
            //Eingabe von St�dtenamen
            //TSM-Problem

        }
        else if (choice == 3)
        {
            //Hinzuf�gen von St�dten

        }
        else if (choice == 0) running = 0;

        else running = 0;

    }


}
