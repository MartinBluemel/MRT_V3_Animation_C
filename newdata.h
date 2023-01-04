#ifndef NEWDATA_HH
#define NEWDATA_HH

// Newdata Schnittstelle

 typedef struct Laufzeitdaten {
    int X, Y, schritt, gesamtschritte, p; // X: Spalte, Y: Zeile
    float delay; // Pause zwischen den Schritten
    char* puffer;
}Laufzeitdaten;


// Darstellung des Puffers (Zahlen sind Elemente des Puffers):
//   __|-------X-------|_
// _|01 02 03 04 05 06 07
// | 08 09 10 11 12 13 14
// Y 15 16 17 18 19 20 21
// _ 22 23 24 25 26 27 28
//   29 30 31 32 33 34 35

#endif //NEWDATA_HH
