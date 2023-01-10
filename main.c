#include<stdio.h>
#include<stdlib.h>
#include <math.h>

// Schnittstellen zu (eigenen) Unterfunktionen
#include"newdata.h"   // Definition Datentyp "Laufzeitdaten" (Aufgabe 4.1)
#include"config.h"    // Einlesen der Konfigurationsdatei (Aufgabe 4.2): einlesen()
#include"gfx.h"       // Grafische Darstellung (Aufgabe 4.4): init_pic(), ausdruck()
#include"engine.h"    // Berechnung der Animationsschritte (Aufgabe 4.3): calculate_next_pic()
#include "ui.h"       // Nutzereingaben (Aufgabe 4.5): pause()


//eventuell wieder erstzen mit void main(void)
int main(int argc, char *argv[])  {

    // Konfigurationsdatei einlesen (in config.c, Aufgabe: 4.2)
    // Rueckgabe der Struktur "daten" mit den noetigen Informationen
    // Rueckgabe des Animationspuffers mit Raendern

	
	// initialisiere und befülle Daten aus der vorgegebenen Settings-Datei
	Laufzeitdaten daten = einlesen("settings-1.txt");


	// Identifiziert Pausenbetrieb.
    int p = 0;	// 0 = Normalbetrieb; 1 = Pausenbetrieb

    /* Kann das weg?
    printf("Eingelesene Daten: \n");
    printf("daten.X (Spalten): %d\n", daten.X);
    printf("daten.Y (Zeilen): %d\n", daten.Y);
    printf("daten.schritt: %d\n", daten.schritt);
    printf("daten.gesamtschritte: %d\n", daten.gesamtschritte);
    printf("daten.delay: %f\n", daten.delay);
    printf("daten.p: %d\n", daten.p);
    */

    // Leinwand initialisieren (in gfx.c, Aufgabe 4.4):
    init_pic(daten);


    // Schleife:
    while(1)
    {
    	// eigentlich soll daten.p verwendet werden um den Betriebsmodus zu erfassen, aber da kommt es zu komischen Werten nach der Berechnung ...
    	//daten.p = userinput(daten.delay, daten.p);


    	//Nimmt Benutzereingaben entgegen und verzögert die bildausgabe um das entsprechende delay in der settings.txt
    	// Schleifenabbruch bei:
		// - Taste q --> Funktion in ui.c
		// - Gesamtschritte erreicht
		// - Pausieren --> Funktion in ui.c
		// Pause zwischen einzelnen Bildern

    	p = userinput(daten.delay, p);

    	if(daten.schritt < daten.gesamtschritte){


			// Naechsten Animationsschritt berechnen (4.3, in engine.c):
			daten = calculate_next_pic(daten);

			//Visualisierung - 1. bis N = daten.gesamtschritte -ter Berechnungsschritt in der Konsole
			/*
			printf("Schritt %d\n",daten.schritt);
			for (int i=0; i<=(daten.Y+1); i++) {
						for (int j=0; j<=(daten.X+1); j++) {
							printf("%c", daten.puffer[j+i*(daten.X+2)]);
						}
						printf("\n");
				};

			printf("\n");
			printf("\n");
			*/

			// Bild darstellen (3.4, in gfx.c):
			draw_pic(daten);

		}


    }
    //Puffer deallokieren
    free(daten.puffer);
    return 0;
};
