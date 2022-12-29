/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Nutzerinteraktions-Modul
 */

#include "ui.h"

// für vorgegebene UI Funktionen: grafik_user_input()
#include"graphic.h"

// für die Funktion `exit`
#include <stdlib.h>
#include <time.h>


// Funktionen um Nutzerinteraktionen zu behandeln
int userinput(float delay, int p){

	int pp = p;
	//printf("Delay: %d\n",delay);



	time_t endwait;
	time_t start = time(NULL) * 1000;
	time_t mseconds = (floor(delay * 1000)); // end loop after this time has elapsed

	endwait = start + mseconds;

	while (start < endwait)
	{
		//printf("Pause: %d\n",pp);
		start = time(NULL) * 1000;

		if(pp == 0){
			switch(grafik_user_input(10)){
				case Beenden: exit(0);

				case Pause:{
						//printf("Pause start\n");
						pp = 1; //pause
						break;
				}
			}
		}

		if(pp == 1){
			//printf("Pause hält an\n");
			while(pp==1){
					switch(grafik_user_input(10)){
						case Beenden: exit(0);

						case Pause:{
								//printf("Pause stop\n");
								pp = 0; //pause
								break;
						}
						case Schritt:
							//printf("Schritt\n");
							return pp;
							break;
					}
				}
			}

	}

	return pp;
}
