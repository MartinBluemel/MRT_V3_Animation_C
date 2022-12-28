#include"engine.h"
// für fopen, getline, fscanf, fclose:
#include<stdio.h>

// für strncmp und memset:
#include<string.h>

// für malloc, calloc und atoi:
#include<stdlib.h>

#include"newdata.h"// für Dantentyp-Laufzeitdaten:


// Engine Quellcode

//Funktion um den nächsten Schrtitt zu berechnen

struct Laufzeitdaten calculate_next_pic(struct Laufzeitdaten caldata){
	//Rückgabevariable vom Typ Laufzeitdaten
	struct Laufzeitdaten nextdata;
	nextdata.X = caldata.X;
	nextdata.Y = caldata.Y;
	nextdata.schritt = caldata.schritt;
	nextdata.gesamtschritte = caldata.gesamtschritte;
	nextdata.delay = caldata.delay;
	nextdata.puffer = caldata.puffer;

	//Berechnungsvariable
	struct Laufzeitdaten betdata;
	betdata.X = caldata.X+2;
	betdata.Y = caldata.Y+2;
	betdata.schritt = caldata.schritt;
	betdata.gesamtschritte = caldata.gesamtschritte;
	betdata.delay = caldata.delay;
	betdata.puffer = malloc(((betdata.X+2)*(betdata.Y+2))*sizeof(char));

	//Puffer nochmal um einen Rand '.' erweitern
	for (int i=0; i<=(betdata.Y+1); i++) {
		        for (int j=0; j<=(betdata.X+1); j++) {
		        	betdata.puffer[j+i*(betdata.X+2)] = '.';
		        }

		    };

	/*Visualisierung
	for (int i=0; i<=(betdata.Y+1); i++) {
			        for (int j=0; j<=(betdata.X+1); j++) {
			            printf("%c", betdata.puffer[j+i*(betdata.X+2)]);
			        }
			        printf("\n");
			    };

	 printf("\n");
	 printf("\n");
	 //*/

	 //übergebenen Puffer in erweiterten einfügen
	 for (int i=0; i<=(nextdata.Y+1); i++) {
		        for (int j=0; j<=(nextdata.X+1); j++) {
		        	betdata.puffer[(j+1)+(i+1)*(betdata.X+2)] = nextdata.puffer[j+i*(caldata.X+2)];
		        }

		    };

	 /*Visualisierung
	 for (int i=0; i<=(betdata.Y+1); i++) {
	 			        for (int j=0; j<=(betdata.X+1); j++) {
	 			            printf("%c", betdata.puffer[j+i*(betdata.X+2)]);
	 			        }
	 			        printf("\n");
	 			    };

	 printf("\n");
	 printf("\n");
	 */

	//*Berechnung
	int k = 0;

	for (int i=1; i<=(betdata.Y); i++) {
		        for (int j=1; j<=(betdata.X); j++) {
		        	k = 0;
		        	//wenn Pixel leer
		        	if(betdata.puffer[j+i*(betdata.X+2)]=='.'){

		        		//Analyse der umliegenden Felder
		        		//Ecke oben links
		        		if(betdata.puffer[(j+i*(betdata.X+2))-(betdata.X+3)]=='x'){
		        			k= k+1;
		        		}
		        		//oben Mitte
		        		if(betdata.puffer[(j+i*(betdata.X+2))-(betdata.X+2)]=='x'){
		        			k= k+1;
		        		}
		        		//Ecke oben rechts
		        		if(betdata.puffer[(j+i*(betdata.X+2))-(betdata.X+1)]=='x'){
		        			k= k+1;
		        		}
		        		//Mitte links
		        		if(betdata.puffer[(j+i*(betdata.X+2))-1]=='x'){
		        			k= k+1;
		        		}
		        		//Mitte rechts
		        		if(betdata.puffer[(j+i*(betdata.X+2))+1]=='x'){
		        			k= k+1;
		        		}
		        		//Ecke unten links
		        		if(betdata.puffer[(j+i*(betdata.X+2))+(betdata.X+2)-1]=='x'){
		        			k= k+1;
		        		}
		        		//unten Mitte
		        		if(betdata.puffer[(j+i*(betdata.X+2))+(betdata.X+2)]=='x'){
		        			k= k+1;
		        		}
		        		//Ecke unten rechts
		        		if(betdata.puffer[(j+i*(betdata.X+2))+(betdata.X+2)+1]=='x'){
		        			k= k+1;
		        		}
		        		//Analyseende


		        		//freier Pixel mit exakt 3 belegten Nachbarpixeln wird zu belegten Pixel
		        		if (k == 3){
		        			nextdata.puffer[(j-1)+(i-1)*(caldata.X+2)] = 'x';
		        			k = 0;
		        		}
		        	}
		        	//alle Zeichen die kein Punkt sind werden als x gesehen
		        	else {
		        		///*
		        		//Analyse der umliegenden Felder
		        		//Ecke oben links
		        		if(betdata.puffer[(j+i*(betdata.X+2))-(betdata.X+2)-1]=='x'){
		        			k= k+1;
		        		}
		        		//oben Mitte
		        		if(betdata.puffer[(j+i*(betdata.X+2))-(betdata.X+2)]=='x'){
		        			k= k+1;
		        		}
		        		//Ecke oben rechts
		        		if(betdata.puffer[(j+i*(betdata.X+2))-(betdata.X+2)+1]=='x'){
		        			k= k+1;
		        		}
		        		//Mitte links
		        		if(betdata.puffer[(j+i*(betdata.X+2))-1]=='x'){
		        			k= k+1;
		        		}
		        		//Mitte rechts
		        		if(betdata.puffer[(j+i*(betdata.X+2))+1]=='x'){
		        			k= k+1;
		        		}
		        		//Ecke unten links
		        		if(betdata.puffer[(j+i*(betdata.X+2))+(betdata.X+2)-1]=='x'){
		        			k= k+1;
		        		}
		        		//unten Mitte
		        		if(betdata.puffer[(j+i*(betdata.X+2))+(betdata.X+2)]=='x'){
		        			k= k+1;
		        		}
		        		//Ecke unten rechts
		        		if(betdata.puffer[(j+i*(betdata.X+2))+(betdata.X+2)+1]=='x'){
		        			k= k+1;
		        		}
		        		//Analyseende*/


		        		//belegter Pixel mit zwei oder drei belegten Nachbarpixeln bleibt belegt
		        		if (k == 2 || k == 3){
		        			nextdata.puffer[(j-1)+(i-1)*(caldata.X+2)] = 'x';
		        			k = 0;
		        		}
		        		//belegter Pixel mit mehr als drei belegten Nachbarpixeln wird frei
		        		//belegter Pixel mit weniger als zwei belegten Nachbarpixeln wird frei
		        		else{
		        			nextdata.puffer[(j-1)+(i-1)*(caldata.X+2)] = '.';
		        			k = 0;
		        		}

		        	}

		       }

		  };



	//Visualisierung
	for (int i=0; i<=(nextdata.Y+1); i++) {
	        for (int j=0; j<=(nextdata.X+1); j++) {
	            printf("%c", nextdata.puffer[j+i*(nextdata.X+2)]);
	        }
	        printf("\n");
	};

	return nextdata;//später nextdata
}

