#include"engine.h"
// für fopen, getline, fscanf, fclose:
#include<stdio.h>

// für strncmp und memset:
#include<string.h>

// für malloc, calloc und atoi:
#include<stdlib.h>

#include"newdata.h"// für Dantentyp-Laufzeitdaten:

int funadd(int x, int y);
// Engine Quellcode

int funadd(int x, int y){
	int a;
	a = x + y;
	return a;
}

//Funktion um den nächsten Schrtitt zu berechnen
/*
extern struct Laufzeitdaten calculate_next_pic(struct Laufzeitdaten caldata){
	//printf("%c", caldata.puffer[0]);
	//int screencounter;
	//screencounter = (caldata.Y+2)*(2+caldata.X);//Variabele zum Puffer durchgehen



	return caldata;
}
//*/
