#include <stdio.h>

int length(char *string);
char *padding(char *string, int seglen, int len);
char *segmentmaker(char *string, int len, int seglen, int param);
void displayandcount(char *string, int len, int seglen);
void checksum(char *str, int seglen, int len);

int main()
{
    char str[1000];
    int seglen, len = 0, i;

    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter the segment length: ");
    scanf("%d", &seglen);

    char *string = str;
    len = length(string);

    if (len % seglen != 0)
    {
        string = padding(string, seglen, len);
        len = length(string);
        // checksum(string, seglen, len);
    }

    else
    {
        //  checksum(string, seglen, len);
    }
}

int length(char *string)
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

char *padding(char *string, int seglen, int len)
{
    int segnum = (int)len / seglen + 1;
    int zeroprepend = segnum * seglen - len;

    int j = len - 1;
    for (int i = len + zeroprepend - 1; i >= zeroprepend; i--)
    {
        string[i] = string[j];
        j--;
    }

    for (int i = 0; i < zeroprepend; i++)
        string[i] = '0';

    displayandcount(string, len + zeroprepend, seglen);
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

char *segmentmaker(char *string, int len, int seglen, int param)
{
    /*char *segment = (char *)malloc(seglen * sizeof(char));
    for (int i = 0; i < seglen; i++)
    {
        segment[i] = string[param * seglen + i];
    }
    return segment;*/

    char *str;
    for (int i = 0; i < seglen; i++)
    {
        str[i] = string[param * seglen + i];
    }

    return str;
}

void checksum(char *str, int seglen, int len)
{
}