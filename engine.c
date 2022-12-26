#include"engine.h"
// für fopen, getline, fscanf, fclose:
#include<stdio.h>

// für strncmp und memset:
#include<string.h>

// für malloc, calloc und atoi:
#include<stdlib.h>

#include"newdata.h"// für Dantentyp-Laufzeitdaten:

int funadd(int x, int y);
// Engine Quellcode



//hallo

int funadd(int x, int y){
	int a;
	a = x + y;
	return a;
}

//Funktion um den nächsten Schrtitt zu berechnen

extern struct Laufzeitdaten calculate_next_pic(struct Laufzeitdaten caldata){
	//Rückgabevariable vom Typ Laufzeitdaten
	struct Laufzeitdaten nextdata;

	//test
	printf("%c\n", caldata.puffer[0]);
	caldata.puffer[0] = 't';

	/*Berechnung
	int screencounter;
	int screencounter = (caldata.Y+2)*(2+caldata.X);//Variabele zum Puffer durchgehen

	for(int i=0; i<screencounter; i++){
		for(int j=0; j<caldata.X; j++){

		};



	};
	//*/

	/*Visualisierung
	int v1 = ((caldata.X+2)*(caldata.Y+2));
	int k = (caldata.X+2);
	int x = 0;
	for(int i=0; i<v1; i++){

		printf("%c", caldata.puffer[i]);
		x = x+1;

		while (x=k){
			printf("\n");
			x=0;
		}




	}

	//*/

	return caldata;//später nextdata
}

