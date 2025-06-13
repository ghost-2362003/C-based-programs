#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char data[100];
    int data1[100], data2[100];
    int dl, r, i = 0, j = 0, k = 0, z, c;
    printf("\n Enter the dataword: "); // taking input in string
    scanf("%s", data);
    dl = strlen(data); // length of the input string

    while (1) // finding number of parity bits
    {
        if (pow(2, i) >= dl + i + 1)
            break;
        i++;
    }

    r = i;
    printf("\n No of redundant bits: %d \n", r);

    for (i = 0; i < dl; i++)
    {
        data1[i] = data[i] - 48;
    }

    for (i = 0; i < r; i++)
    {
        z = pow(2, i);
        data2[z] = 999;
    }

    for (i = dl + r; i >= 1; i--)
    {
        if (data2[i] != 999)
        {
            data2[i] = data1[j];
            j++;
        }
    }

    for (i = 0; i < r; i++)
    {

        z = pow(2, i); // finding position of each parity bit
        c = 0;         // initializing counter c
        for (j = z; j <= dl + r; j = z + k)
        {
            for (k = j; k < z + j; k++)
            {
                if (k <= dl + r)
                {
                    if (data2[k] != 999)
                    {
                        c = c + data2[k];
                    }
                }
            }
        }

        data2[z] = c % 2; // parity bit value
    }

    printf("\n The codeword is: ");
    j = 0;

    for (i = dl + r; i >= 1; i--)
    {
        printf("%d", data2[i]);
    }

    return (0);
}