#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *args[])
{
    if (argc < 2)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    char *line = NULL;
    size_t linecap = 0;
    char pre = '.';
    int cnt = 0;
    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(args[i], "r");
        if (file == NULL)
        {
            printf("wzip: cannot open file\n");
            exit(1);
        }
        while (getline(&line, &linecap, file) > 0)
        {
            for (int i = 0; i < strlen(line); i++)
            {
                if (pre == '.')
                {
                    pre = line[i];
                }
                else if (pre != line[i])
                {
                    fwrite(&cnt, 4, 1, stdout);
                    printf("%c", pre);
                    pre = line[i];
                    cnt = 0;
                }
                cnt = cnt + 1;
            }
        }
        fclose(file);
    }
    fwrite(&cnt, 4, 1, stdout);
    printf("%c", pre);

    return 0;
}