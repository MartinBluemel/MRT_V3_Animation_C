/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Berechnungs-Modul
 */

#include"engine.h"

#include<stdio.h>
#include<string.h>// für strncmp und memset:
#include<stdlib.h>// für malloc, calloc und atoi:
#include"newdata.h"// für Dantentyp-Laufzeitdaten:


// Engine Quellcode

//Funktion um den nächsten Schrtitt zu berechnen
struct Laufzeitdaten calculate_next_pic(struct Laufzeitdaten caldata){

	printf("%c", caldata.puffer[0]);
	int screencounter = (caldata.Y+2)*(2+caldata.X);//Variabele zum Puffer durchgehen

	for(int i=0; i<screencounter; i++){
		for(int j=0; j<caldata.X; j++){

		}



	}




	return caldata;
}
