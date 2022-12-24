/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Konfigurationsdatei-Modul
 */

#include"config.h"

// für fopen, getline, fscanf, fclose:
#include<stdio.h>

// für strncmp und memset:
#include<string.h>

// für malloc, calloc und atoi:
#include<stdlib.h>

// für Dantentyp-Laufzeitdaten:
#include"newdata.h"
	 
// Config und Dateiarbeit Funktionen
/*
struct Laufzeitdaten einlesen() {
    struct Laufzeitdaten probe;
    probe.X=4;
    probe.Y=4;
    probe.gesamtschritte=1; // damit Schleife nicht ewig läuft
    probe.puffer = malloc((probe.X*probe.Y) * sizeof(char));

    // Uebergangsweise befüllen von Puffer
    for (int i=0; i<probe.X*probe.Y; i++) {
        probe.puffer[i] = 'x';
    }
    return probe;
};
*/
