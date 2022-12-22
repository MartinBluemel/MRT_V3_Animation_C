#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
    const char* filename = "settings-2.txt";

    FILE* input_file = fopen(filename, "r");
    // Oeffnet Datei "filename" (muss Pointer sein), r: reading
    // fopen gibt einen Pointer des Types FILE zurück

    // Fehler-Anzeige bei Oeffnen
    if (!input_file) {  // !ptr: true wenn ptr Nullpointer ist
        perror("fopen"); // prints a descriptive error message
        exit(EXIT_FAILURE);
    }

    char str1[10], str3[10], str4[10], str5[10]; // variable[string_lenght]
    int str2;

    printf("Versuch 3:\n");

    fscanf(input_file, "%s %d\n", str1, &str2); // Warum &str2 und nicht str2??

    printf("%s\n", str1);
    str2=str2+3;
    printf("%d\n", str2);

    fscanf(input_file, "%s %s\n", str3, str4);
    printf("%s\n", str3);
    printf("%s\n", str4);
}
