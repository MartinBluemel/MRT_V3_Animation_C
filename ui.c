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
	int d = floor(delay * 1000);
	user_input_t test;

	if(pp == 0){
		test = grafik_user_input(d);
		switch(test){

			case Beenden: exit(0);

			case Pause:{
					printf("Pause Start\n");
					pp = 1; //pause
					break;
			}
		}
	}

	if(pp == 1){
		while(pp==1){
			//printf("Pause hält an\n");
			test = grafik_user_input(d);
				switch(test){
					case Beenden: exit(0);

					case Pause:{
						printf("Pause Stop\n");
						pp = 0; //pause
						break;
					}
					case Schritt:
						//printf("Nächster Schritt\n");
						return pp;
						break;
				}
			}
		}
	return pp;
}
