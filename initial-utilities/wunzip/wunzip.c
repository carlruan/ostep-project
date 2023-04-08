#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *args[])
{
    if (argc < 2)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(args[i], "r");
        if (file == NULL)
        {
            printf("wzip: caqnnot open file\n");
            exit(1);
        }
        int cnt = 0;
        char c = '.';
        while (fread(&cnt, sizeof(int), 1, file) == 1)
        {
            fread(&c, sizeof(char), 1, file);
            for (int j = 0; j < cnt; j++)
            {
                printf("%c", c);
            }
        }
        fclose(file);
    }

    return 0;
}