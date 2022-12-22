#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

const char* filename = "settings-2.txt";

int main(int argc, char *argv[])
{
    FILE *in_file = fopen(filename, "r");
    char str[3] = "HE";

    printf("Test1: \n");

    struct stat sb;
    stat(filename, &sb);

    char *file_contents = malloc(sb.st_size);

    while (fscanf(in_file, "%[^\n] ", file_contents) != EOF) {

        //char *file_contents = malloc(sb.st_size); // Aber nur in notwendiger Größe allokieren!
        printf("%s\n", file_contents);
        // str[] = &file_contents[3];

        //str[40]=file_contents;
        printf("%s\n", str);
    }

    fclose(in_file);
    exit(EXIT_SUCCESS);
}