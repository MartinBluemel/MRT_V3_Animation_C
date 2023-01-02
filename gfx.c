/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Grafikausgabe-Modul
 */

#include"gfx.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<time.h>

// für vorgegebene Grafik Funktionen grafik_paint_point() und andere:
#include"graphic.h"

// für Dantentyp-Laufzeitdaten:
#include"newdata.h"


/** innere Definitionen-
 * static -> alle Variablen nur in diesem Modul sichtbar!
 */


//SDL Ressourcen

// Funktionen zur Grafikausgabe



void init_pic(struct Laufzeitdaten daten)  {
	
	grafik_init_window();
	grafik_create_paint_area( 1, (daten.X + 1), 1, (daten.Y + 1), daten.X, daten.Y);
	printf("Test %d \n",daten.X);
	//Was ist x und y points???
	//grafik_lock_for_painting();
};

void draw_pic(struct Laufzeitdaten daten) {
	// Sperrt die Leinwand, muss angeblich so sein?
	grafik_lock_for_painting();

	// Schleife, die jeden einzelnen Punkt an grafik_paint_point gibt (graphic.c),
	// Schleife ist identisch zu der Testschleife aus main.c aufgebaut
	for (int i=0; i<=(daten.Y+1); i++) {
	        for (int j=0; j<=(daten.X+1); j++) {
	        	 printf("%c\n", daten.puffer[j+i*(daten.X+2)]);
	        	// if wert = x-> zeichnen, sonst weitergehen
	        	if (daten.puffer[j+i*(daten.X+2)] == '.') {
	        		grafik_paint_point ( j, i, Twine);
	        	}
	        
	        }
	        //printf("\n");
	   
	    };
	    
	/*for(int i=0;i<4;i++){
		printf("b\n");
		
		for(int j=0;j<3;j++){
	grafik_paint_point(i, j, Twine);}
	// zeigt die neu gemalte leinwand
	}*/
	
	grafik_unlock_and_show();

	char y = getchar;
	
};
