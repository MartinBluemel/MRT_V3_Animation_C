#include<stdio.h>
#include<stdlib.h>

// Schnittstellen zu (eigenen) Unterfunktionen
#include"newdata.h"   // Definition Datentyp "Laufzeitdaten" (Aufgabe 4.1)
#include"config.h"    // Einlesen der Konfigurationsdatei (Aufgabe 4.2): einlesen()
#include"gfx.h"       // Grafische Darstellung (Aufgabe 4.4): init_pic(), ausdruck()
#include"engine.h"    // Berechnung der Animationsschritte (Aufgabe 4.3): calculate_next_pic()
#include "ui.h"        // Nutzereingaben (Aufgabe 4.5): pause()
#include <math.h>


//eventuell wieder erstzen mit void main(void)
int main(int argc, char *argv[])  {

    // Konfigurationsdatei einlesen (in config.c, Aufgabe: 4.2)
    // Rueckgabe der Struktur "daten" mit den noetigen Informationen
    // Rueckgabe des Animationspuffers mit Raendern

	/*struct Laufzeitdaten {
      int X, Y, schritt, gesamtschritte; // X: Spalte, Y: Zeile
      float delay; // Pause zwischen den Schritten
      char* puffer;
    */
	struct Laufzeitdaten daten = einlesen("settings-1.txt");

    daten.p = 0;
    int p = 0;

    printf("Eingelesene Daten: \n");
    printf("daten.X (Spalten): %d\n", daten.X);
    printf("daten.Y (Zeilen): %d\n", daten.Y);
    printf("daten.schritt: %d\n", daten.schritt);
    printf("daten.gesamtschritte: %d\n", daten.gesamtschritte);
    printf("daten.delay: %f\n", daten.delay);
    printf("daten.p: %d\n", daten.p);

    //Visualisierung
	for (int i=0; i<=(daten.Y+1); i++) {
		for (int j=0; j<=(daten.X+1); j++) {
			printf("%c", daten.puffer[j+i*(daten.X+2)]);
		}
		printf("\n");
	};


	//Platzhalter
	printf("\n");
	printf("\n");




    // Leinwand initialisieren (in gfx.c, Aufgabe 4.4):
    //init_pic(daten);
	grafik_init_window();

    // Schleife:
	int t = 1;
    while(t < 2000)
    {
    	t++;
    	//eigentlich soll daten.p verwendet werden aber da kommt es zu komischen werten nach der berechnung ...

    	//daten.p = userinput(daten.delay, p);
    	//printf("daten.d: %d\n",daten.p);

    	p = userinput(daten.delay, p);
    	//printf("d: %d\n",p);


    	if(daten.schritt < daten.gesamtschritte){


			// Naechsten Animationsschritt berechnen (3.3, in engine.c):
			//läuft, jetzt läufts
			daten = calculate_next_pic(daten);

			printf("Schritt %d\n",daten.schritt);
			for (int i=0; i<=(daten.Y+1); i++) {
						for (int j=0; j<=(daten.X+1); j++) {
							printf("%c", daten.puffer[j+i*(daten.X+2)]);
						}
						printf("\n");
				};

			printf("\n");
			printf("\n");

			// Bild darstellen (3.4, in gfx.c):
			//

			// Schleifenabbruch bei:
			// - Taste q --> Funktion in ui.c
			// - Gesamtschritte erreicht
			// - Pausieren --> Funktion in ui.c

			// Pause zwischen einzelnen Bildern


		}


    }
    // Puffer deallokieren
    free(daten.puffer);
    return 0;
};


// Wie genau soll Animation am Ende aussehen? Farbpunkte? (vllt mal Dustin fragen)

// 1) Einlesen:
// 2) Ausgabe: Leinwand initialisieren, Ausgabe programmieren // Theo
// 3) Nächesten Schritt berechnen // Martin
// 4) Schleife in Hauptprogramm die nächsten Schritt berechnet, Bild darstellt und die Befehle von
//    ui.c (4.5) bearbeitet // 
