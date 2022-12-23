#include<stdio.h>
#include<stdlib.h>

// Schnittstellen zu (eigenen) Unterfunktionen
#include"newdata.h"   // Definition Datentyp "Laufzeitdaten" (Aufgabe 4.1)
#include"config.h"    // Einlesen der Konfigurationsdatei (Aufgabe 4.2): einlesen()
#include"gfx.h"       // Grafische Darstellung (Aufgabe 4.4): init_pic(), ausdruck()
#include"engine.h"    // Berechnung der Animationsschritte (Aufgabe 4.3): calculate_next_pic()
#include"ui.h"        // Nutzereingaben (Aufgabe 4.5): pause()


void main(void)  {

    // Konfigurationsdatei einlesen (in config.c, Aufgabe: 4.2)
    // Rueckgabe der Struktur "daten" mit den noetigen Informationen
    // Rueckgabe des Animationspuffers mit Raendern

	/*struct Laufzeitdaten {
      int X, Y, schritt, gesamtschritte; // X: Spalte, Y: Zeile
      float delay; // Pause zwischen den Schritten
      char* puffer;
    */

    };

    struct Laufzeitdaten daten;
    
    daten = einlesen(); 

    // print: daten.X = 100
    // print: daten.delay = 0.1


    // Leinwand initialisieren (in gfx.c, Aufgabe 4.4):
    // init_pic(daten);

    // Schleife:
        // Naechsten Animationsschritt berechnen (3.3, in engine.c):
        calculate_next_pic(daten);

        // Bild darstellen (3.4, in gfx.c):
        // 

        // Schleifenabbruch bei:
        // - Taste q --> Funktion in ui.c
        // - Gesamtschritte erreicht
        // - Pausieren --> Funktion in ui.c

        // Pause zwischen einzelnen Bildern

    // }

    // Puffer deallokieren
    free(daten.puffer);
};


// Wie genau soll Animation am Ende aussehen? Farbpunkte? (vllt mal Dustin fragen)

// 1) Einlesen:
// 2) Ausgabe: Leinwand initialisieren, Ausgabe programmieren // Theo
// 3) Nächesten Schritt berechnen // Martin
// 4) Schleife in Hauptprogramm die nächsten Schritt berechnet, Bild darstellt und die Befehle von
//    ui.c (4.5) bearbeitet // 
