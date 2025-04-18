#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CheckParity(char *stream, int flag)
{
    int count;

    for (int i = 0; i < strlen(stream); i++)
        if (stream[i] == '1')
            count++;

    if ((count % 2 == 0 && flag == 1) || (count % 2 == 1 && flag == 0)) // given parity is correct
    {
        for (int i = 0; i < strlen(stream) - 1; i++)
            printf("%c", stream[i]);

        printf("\nACCEPTED\n");
    }

    else if ((count % 2 == 0 && flag == 0) || (count % 2 == 1 && flag == 1)) // given parity is incorrect
        printf("\nREJECTED\n");
}

int main()
{
    char *stream = (char *)malloc(100 * sizeof(char));
    int flag;

    printf("enter the data stream:");
    scanf("%s", stream);

    while (1)
    {
        printf("enter 1 for even parity and 0 for odd parity:");
        scanf("%d", &flag);

        if (flag == 1 || flag == 0)
            break;
        else
            printf("invalid input\n");
    }

    CheckParity(stream, flag);

    return 0;
}