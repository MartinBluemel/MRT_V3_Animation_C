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

    char str1[10], str2[20], str3[30], str4[40];

    fscanf(input_file, "%s %s %s %s", str1, str2, str3, str4);

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", str4);
}
