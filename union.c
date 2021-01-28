#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write (1, "\n", 1);
        return 0;
    }
    int c[255] = {0};
    int i = 0;
    char *s1 = argv[1];
    char *s2 = argv[2];
    while (s1[i] != '\0')
    {
        if (c[s1[i] - '0'] == 0)
        {
            write(1, &s1[i], 1);
            c[s1[i] - '0'] = 1;
        }
        i++;
    }
    i = 0;
    while (s2[i] != '\0')
    {
        if (c[s2[i]- '0'] == 0)
        {
            write(1, &s2[i], 1);
            c[s2[i]- '0'] = 1;
        }
        i++;
    }
    write(1, "\n", 1);
    return 0;
}