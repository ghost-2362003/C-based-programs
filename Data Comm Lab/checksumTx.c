#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char data[100], data1[100];
    int i, j=0, k, c, sl, dl, sum[100];

    printf("enter the datastream: ");
    scanf("%s", data);
    dl = strlen(data);

    while (1){
        printf("\nenter the segment length: ");
        scanf("%d", &sl);

        for(i = 1; i<=sl/2; i++)
            if(pow(2, i) == sl){
                j = 1;
                break;
            }

        if(j == 1)
            break;
        else
            printf("segment length should be power of 2");
    }

    if(dl%sl != 0){
        int temp = sl - dl%sl;
        for(j = 0; j<temp; j++)
            data1[i] = '0';

        strcat(data1, data);
        strcpy(data, data1);
        dl = dl + temp;
    }

    for(i = 0; i<sl; i++)
        sum[i] = 0;

    for(i = dl; i>0; i = i-sl){
        c = 0;
        k = sl-1;
        //compute the sum of sl number of bits of data with the sum array each time
        for(j = i-1; j>=i-sl; j--){
            int temp = sum[k] + (data[j]-48) + c;
            sum[k] = temp%2;
            c = temp/2;
            k--;
        }

        //if carry remains then add it to the sum
        if(c == 1)
            for(j = sl-1; j>=0; j--){
                int temp = sum[j] + c;
                sum[j] = temp%2;
                c = temp/2;
            }
    }

    printf("\nchecksum: ");
    for(i = 0; i<sl; i++){
        if(sum[i] == 0)
            sum[i] = 1;
        else
            sum[i] = 0;

        data[dl+i] = sum[i] + 48;
        printf("%d", sum[i]);
    }

    data[dl + i] = '\0';
    printf("\ntransmitter codeword is: %s\n", data);
}
