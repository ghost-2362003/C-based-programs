#include <stdio.h>

void displayandcount(char String[], int len, int seglen);
void arrange(char String[], int len, int seglen);

void main()
{
    char string[1000];
    int seglen, len = 0, i = 0;

    printf("enter the string: ");
    scanf("%s", &string);
    printf("enter the segment length: ");
    scanf("%d", &seglen);

    while (string[i] == 48 || string[i] == 49)
    {
        len++;
        i++;
    }

    if ((int)len % seglen == 0)
        displayandcount(string, len, seglen);

    else if (len < seglen)
        printf("not possible\n");

    else
        arrange(string, len, seglen);
}

void displayandcount(char String[], int len, int seglen)
{
    printf("printing segments\n");
    for (int i = 0; i < (int)len / seglen; i++)
    {
        int count = 0;
        printf("segment %d: ", i + 1);

        for (int j = 0; j < seglen; j++)
        {
            printf("%c", String[seglen * i + j]);
            if (String[seglen * i + j] == 49)
                count++;
        }

        printf("\t\tnumber of 1's: %d\n", count);
    }
}

void arrange(char String[], int len, int seglen)
{
    int segnum = (int)len / seglen + 1;
    int zeroprepend = segnum * seglen - len;

    int j = len - 1;
    for (int i = len + zeroprepend - 1; i >= zeroprepend; i--)
    {
        String[i] = String[j];
        j--;
    }

    for (int i = 0; i < zeroprepend; i++)
        String[i] = '0';

    displayandcount(String, len + zeroprepend, seglen);
}