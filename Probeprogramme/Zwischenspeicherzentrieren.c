#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

int main() {

    // Spalten, Zeile
    int x=11, y=7; 
    int breite_puffer=5, hoehe_puffer=3;

    char zwischenspeicher[16] = "0123456789abcde";

    printf("%s\n", zwischenspeicher);

    // Speicher für Ausgabe allokieren
    char *ausgabe=(char*)malloc(((x+2)*(y+2))*sizeof(char));

    // Anpassung von Zwischenspeicher auf Ausgabe: Zahl zum Subtrahieren
    int abzug=(x+2)*((y-hoehe_puffer)/2+1)+(x-breite_puffer)/2+1;

    // Zwischenspeicher mittig in Ausgabe platzieren
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {

            // Punkt Außerhalb des Puffers
            if(j<=(x-breite_puffer)/2 || j>(x+breite_puffer)/2 || i<=(y-hoehe_puffer)/2 || i>(y+hoehe_puffer)/2) {
                ausgabe[j+i*(x+2)]='.';
            }

            else {
                ausgabe[j+i*(x+2)]=zwischenspeicher[j+i*(x+2)-abzug];
            }
        
        printf("%c", ausgabe[j+i*(x+2)]);
        }
        printf("\n");
    }

    return 0;
}
