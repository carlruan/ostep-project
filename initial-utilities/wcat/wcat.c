#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *args[])
{
    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(args[i], "r");
        if (file == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        int bytes = 4096;
        char buffer[bytes];
        while (fgets(buffer, bytes, file))
        {
            printf("%s", buffer);
        }
        if (fclose(file) != 0)
        {
            printf("close file error");
        }
    }

    return 0;
}