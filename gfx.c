/*
 * Praktikumsversuch: Einführung in die Sprache C
 * Grafikausgabe-Modul
 */

#include"gfx.h"

// für vorgegebene Grafik Funktionen grafik_paint_point() und andere:
// #include"graphic.h"

// für Dantentyp-Laufzeitdaten:
#include"newdata.h"

// Funktionen zur Grafikausgabe

#include<stdio.h>

void ausdruck(struct Laufzeitdaten daten) {

    for (int i=0; i<daten.Y; i++) {
        for (int j=0; j<daten.X; j++) {
            printf("%c ", daten.puffer[i*daten.Y+j]);
        }
        printf("\n");
    };
};
