#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmp_and_prt(char *src, char *t)
{
    int m = strlen(src);
    int n = strlen(t);
    if (m < n)
    {
        return;
    }
    for (int i = 0; i < m - n; i++)
    {
        if (src[i] == t[0])
        {
            int found = 1;
            for (int j = 0; j < n; j++)
            {
                if (src[i + j] != t[j])
                {
                    found = 0;
                    break;
                }
            }
            if (found == 1)
            {
                printf("%s", src);
                return;
            }
        }
    }
}

int main(int argc, char *args[])
{
    if (argc < 2)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    char *word = args[1];
    char *line = NULL;
    size_t linecap = 0;
    if (argc == 2)
    {
        while (getline(&line, &linecap, stdin) > 0)
        {
            cmp_and_prt(line, word);
        }
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            FILE *file = fopen(args[i], "r");
            if (file == NULL)
            {
                printf("wgrep: cannot open file\n");
                exit(1);
            }

            while (getline(&line, &linecap, file) > 0)
            {
                cmp_and_prt(line, word);
            }
            fclose(file);
        }
    }

    return 0;
}