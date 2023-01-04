#ifndef CONFIG_HH
#define CONFIG_HH

// Config Schnittstelle

//#include"config.c"
#include"newdata.h"
// Config und Dateiarbeit Funktionen

struct Laufzeitdaten einlesen();

// wird in config.c zum Einlesen verwendet
struct eingelesenerpuffer {
    char* ptrzs;
    int hoehezs, breitezs;
}eingelesenerpuffer;


#endif //CONFIG_HH
