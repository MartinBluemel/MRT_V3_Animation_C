#include<string.h>
#include<stdio.h>

int main() {
    char str1[10]="Wort", str2[10]="Wort";
    int res;

    res = strcmp(&str1, "Wort");
    printf("%d\n", res);

    if(res==0) {
        printf("res ist null, Versuch");
    }

    // res=0 wenn Zeichenketten identisch sind

}