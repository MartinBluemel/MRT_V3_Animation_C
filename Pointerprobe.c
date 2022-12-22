#include<stdio.h>

int main() {

    int N = 5;
    int arr[] = { 1, 2, 3, 4, 5};
    int* ptr;
    ptr = arr; // ptr zeigt auf erstes Element von arr
    printf("%d\n", ptr[4]);

    // als nächstes: pointer und strings:
    // wie variablen neu ablegen auf die dann pointer zeigt?
    // wie diese variable verwenden?

    char name[5] = "WORD"; // immer einen char mehr damit \0 am Ende dran kann (wird automatisch gemacht)
    char versuch[4] = {'a','b','c'};
    printf("%s\n", name);  // s für string!
    printf("%s\n", versuch);

    char *string_literal = "This is a string"; // pointer auf erstes Zeichen

    char *pointer = name; // der Pointer zeigt jetzt auf name
    printf("%c\n", pointer[2]); // der Inhalt des Pointers wird verwendet und gedruckt
    // c für einzelnen char; druckt hier den dritten (weil 0=1") aus
    printf("%c\n", *(pointer+2)); // das gleiche wie zwei zeilen drüber
    printf("%c\n", *pointer);
    printf("String: %s\n", pointer); // String von pointer ausgeben


    pointer[2]='a'; // so kann mans beschreiben
    printf("%c\n", pointer[2]);
    printf("%s\n", name);

    pointer[2]=versuch[1]; // so kann mans beschreiben
    printf("%c\n", pointer[2]);
    printf("%s\n", name);
}

// & vor Variable gibt die Adresse der Variable an: ptr=&N
// wie kann man den Wert einer Variable bekommen, auf die der Pointer zeigt?
// Fortran: Pointer hatte doch auch n Wert?

// derefenzieren: vom Pointer zum Objekt kommen

// while(*ptr != '\0) {} : schleife die abbricht wenn *ptr=str fertig ist