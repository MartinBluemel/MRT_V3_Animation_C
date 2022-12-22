#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
    const char* filename = "settings-1.txt";

    FILE* input_file = fopen(filename, "r");
    // Oeffnet Datei "filename" (muss Pointer sein), r: reading
    // fopen gibt einen Pointer des Types FILE zurück

    // Fehler-Anzeige bei Oeffnen
    if (!input_file) {  // !ptr: true wenn ptr Nullpointer ist
        perror("fopen"); // prints a descriptive error message
        exit(EXIT_FAILURE);
    }

    char str1[10]; // variable[string_lenght]
    float number, pause;
    int X, Y, schritt, schritte;

    printf("Versuch 1:\n");

    while(1) {
        fscanf(input_file, "%s %f\n", str1, &number); // Warum &str2 und nicht str2??

        if(strcmp(&str1, "Zeilen:")==0) {
            X=number;
        }

        else if(strcmp(&str1, "Spalten:")==0) {
            Y=number;
        }

        else if(strcmp(&str1, "Schritt:")==0) {
            schritt=number;
        }

        else if(strcmp(&str1, "Schritte:")==0) {
            schritte=number;
        }

        else if(strcmp(&str1, "Pause:")==0) {
            pause=number;
            fscanf(input_file, "%s\n", str1); // noch das s einscannen damits kein
                                              // Kuddelmuddel gibt
        }

        if(strcmp(&str1, "Animations-Puffer:")==0) {
            break;
        }


    }

    printf("%d\n", X);
    printf("%d\n", Y);
    printf("%d\n", schritt);
    printf("%d\n", schritte);
    printf("%f\n", pause);
}