// Puffer Einlesen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {

    const char* filename = "Animationsvorlage.txt";

    char str1[20];

    FILE* input_file = fopen(filename, "r");
    // Oeffnet Datei "filename" (muss Pointer sein), r: reading
    // fopen gibt einen Pointer des Types FILE zurück

    // Fehler-Anzeige bei Oeffnen
    if (!input_file) {  // !ptr: true wenn ptr Nullpointer ist
        perror("fopen"); // prints a descriptive error message
        exit(EXIT_FAILURE);
    }

    // Speicherplatz allokieren
    char *puffer;
    int x=10, y=1;

    puffer=(char*) malloc((x*y)*sizeof(char)); 
    // malloc (memory allocation) liefert pointer auf speicher; dieser ist puffer

    fscanf(input_file, "%s\n", puffer);
    printf("%s\n", puffer);

    fscanf(input_file, "%s\n", puffer);
    printf("%s\n", puffer);

}


    for (int i = 0; i<=(y-1); i++) {
        fscanf(input_file, "%s\n", str1);
        for (int j=1; j<=x; j++) { //
            puffer[i*x+j]=str1[j+1];
        };
        printf("%s\n", puffer);
    };
