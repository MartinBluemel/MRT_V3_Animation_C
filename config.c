// *
// * Praktikumsversuch: Einführung in die Sprache C
// * Konfigurationsdatei-Modul
// *

// Schnittstelle zu Main
#include"config.h"

// für strcmp:
#include<string.h>

// für fopen, getline, fscanf, fclose:
#include<stdio.h>

// für strncmp und memset:
#include<string.h>

// für malloc, calloc und atoi:
#include<stdlib.h>

// für Dantentyp-Laufzeitdaten:
#include"newdata.h"

// Fur was nochmal? --> CHECKEN!!
#include <sys/stat.h>
	 
// Config und Dateiarbeit Funktionen

struct Laufzeitdaten einlesen(); // Vorabdeklaration
struct Laufzeitdaten nummerneinlesen();
struct eingelesenerpuffer puffereinlesen();
char* zentrieren();


// Einlese-Funktion welche später im Main aufgerufen wird:
struct Laufzeitdaten einlesen(const char* filename) {
    struct Laufzeitdaten data;

    // 0) Datei öffnen
    FILE* input_file = fopen(filename, "r");

    // Fehler-Anzeige bei Oeffnen
    if (!input_file) {  // !ptr: true wenn ptr Nullpointer ist
        perror("fopen"); // prints a descriptive error message
        exit(EXIT_FAILURE);
    }

    // 1) Nummern aus Datai einlesen
    data=nummerneinlesen(input_file);

    // 2) Animationspuffer in Zwischenspeicher einlesen
    struct eingelesenerpuffer zwischenspeicher=puffereinlesen(data.X, data.Y, input_file); 

    fclose(input_file);

    // 3) Meldung falls Puffer nicht zentrierbar ist:
    if(data.X%2!=zwischenspeicher.breitezs%2 || data.Y%2!=zwischenspeicher.hoehezs%2) {
        printf("Das Bild ist nicht zentrierbar!\n");
    };

    // 4) Zwischenspeicher zentrieren:
    data.puffer=zentrieren(zwischenspeicher, data.X, data.Y);

    return data;
};

struct Laufzeitdaten nummerneinlesen(FILE* fileptr) {

    struct Laufzeitdaten data;

    char str1[20]; // variable[string_lenght]

    while(1) {
        // fscanf(fileptr, "%s %f\n", str1, &number); // Warum &str2 und nicht str2??
        fscanf(fileptr, "%s", str1);

        if(strcmp(&str1, "Zeilen:")==0) {
            fscanf(fileptr, "%d", &data.Y);
        }

        else if(strcmp(&str1, "Spalten:")==0) {
            fscanf(fileptr, "%d", &data.X);
        }

        else if(strcmp(&str1, "Schritt:")==0) {
            fscanf(fileptr, "%d", &data.schritt);
        }

        else if(strcmp(&str1, "Schritte:")==0) {
            fscanf(fileptr, "%d", &data.gesamtschritte);
        }

        else if(strcmp(&str1, "Pause:")==0) {
            fscanf(fileptr, "%f %s", &data.delay, str1);
        }

        if(strcmp(&str1, "Animations-Puffer:")==0) {
            break;
        }
    }

    return data;
}

struct eingelesenerpuffer puffereinlesen(int X, int Y, FILE* fileptr) { // ACHTUNG: Wenn Punkt an erster Stelle ist wird erste Zeile falsch eingelesen?????

    struct eingelesenerpuffer zs;

    // 2.1 Erste Zeile abspeichern:
    char *einlesespeicher;
    einlesespeicher=(char*)malloc(X*sizeof(char)); // maximal möglich ist Anzahl der Spalten x

    fscanf(fileptr, "%s\n", einlesespeicher);

    // 2.2 Zeilenlänge ermitteln: 
    zs.breitezs = strlen(einlesespeicher);

    // 2.3 Mit Pufferbreite und Anzahl der Zeilen Zwischenspeicher allokieren:
    zs.ptrzs=(char*)malloc((zs.breitezs*Y)*sizeof(char));

    // 2.4 In Zwischenspeicher nun die erste Zeile abspeichern:
    for(int i=0; i<=zs.breitezs; i++) {
        zs.ptrzs[i]=einlesespeicher[i];
    }

    // 2.5 Restliche Zeilen einlesen und in Zwischenspeicher abspeichern:

    int i=0;

    while (fscanf(fileptr, "%s\n", einlesespeicher)!=EOF) {
        i=i+1;

        // Einlesespeicher passend in Zwischenspeicher ablegen:
        for(int j=0; j<zs.breitezs; j++) {
            zs.ptrzs[j+(zs.breitezs*i)]=einlesespeicher[j];
        };
    }

    zs.hoehezs = i+1;

    // 2.6 Einlesespeicher deallokieren
    // free(einlesespeicher);

    return zs;
}

char* zentrieren(struct eingelesenerpuffer zs, int X, int Y) {
    
    // Rand berücksichtigen:
    X=X+2;
    Y=Y+2;

    // Meldung falls das Bild nicht zentriert werden kann:

    // Speicher für Puffer allokieren:
    char *ausgabe=(char*)malloc(((X)*(Y))*sizeof(char));

    // Index des Zwischenspeichers:
    int index_zwischenspeicher=0;

    // Zwischenspeicher mittig in Ausgabe platzieren
    for (int i=0; i<Y; i++) {
        for (int j=0; j<X; j++) {

            // Punkt Außerhalb des Puffers
            if(j<(X-zs.breitezs)/2 || j>=(X+zs.breitezs)/2 || i<(Y-zs.hoehezs)/2 || i>=(Y+zs.hoehezs)/2) {
                ausgabe[j+i*X]='.';
            }

            else {
                // printf("%d %d\n", j+i*(x), index_zwischenspeicher);
                ausgabe[j+i*X]=zs.ptrzs[index_zwischenspeicher];
                index_zwischenspeicher=index_zwischenspeicher+1;
            }
        
        // printf("%c", ausgabe[j+i*X]);
        }
        // printf("\n");
    }

    return ausgabe;
}

