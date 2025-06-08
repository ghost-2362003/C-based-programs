#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int data1[100], i, j, k = 0, r, dataLen, temp, c;
    char data[100];

    printf("enter the data bits: ");
    scanf("%s", data);
    dataLen = strlen(data);

    // calculate the number of parity bits
    while (1)
    {
        r = pow(2, k);
        if (r >= dataLen + k + 1)
        {
            break;
        }
        k++;
    }

    r = k;
    k = 0;

    // place the parity bits in the data array
    for (i = 0; i < r; i++)
    {
        temp = pow(2, i);
        data1[temp] = 999;
    }

    // fill the remaining places with the datastream bits
    for (i = dataLen + r; i >= 1; i--)
    {
        if (data1[i] != 999)
        {
            data1[i] = data[k] - '0';
            k++;
        }
    }

    // calculate the parity bits
    for (i = 0; i < r; i++)
    {
        c = 0;
        temp = pow(2, i);

        for (j = temp; j <= dataLen + r; j = temp + k)
        {
            for (k = j; k < j + temp; k++)
            {
                if (k <= dataLen + r)
                {
                    if (data1[k] != 999)
                    {
                        c += data1[k];
                    }
                }
            }
        }

        data1[temp] = c % 2;
    }

    printf("\n the codeword is: \n");

    j = 0;
    for (i = dataLen + r; i >= 0; i--)
    {
        printf("%d", data1[i]);
    }

    return 0;
}