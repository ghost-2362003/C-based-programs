#include <inttypes.h>
#include <stdio.h>
#include<string.h>
#include<math.h>

int main(){
    char data[100];
    int i, j, k, c, dl, sl, sum[100];
    printf("enter the recieved datastream: ");
    scanf("%s", data);
    dl = strlen(data);

    while(1){
        printf("enter the sequence length: ");
        scanf("%d", &sl);

        j = 0;
        for(i = 1; i<=sl; i++)
            if(pow(2, i) == sl){
                j= 1;
                break;
            }

        if(j == 1)
            break;
        else
            printf("\nsequence length should be power of 2");
    }

    for(i = 0; i<sl; i++)
        sum[i] = 0;

    for(i = dl; i>0; i = i - sl){
        c = 0;
        k = sl - 1;
        for(j = i-1; j>=i-sl; j--){
            int temp = sum[k] + (data[j] - 48) + c;
            sum[k] = temp%2;
            c = temp/2;
            k--;
        }

        if(c == 1)
            for(j = sl-1; j>=0; j--){
                int temp = sum[j] + c;
                sum[j] = temp%2;
                c = temp/2;
            }
    }

    j = 0;
    for(i = 0; i<sl; i++){
        if(sum[i] != 1){
            j++;
            break;
        }
    }

    if(j == 0){
        printf("\ndata recieved is ok\n");
        for(i = 0; i<dl-sl; i++)
            printf("%c", data[i]);

        printf("\n");
    }

    else {
        printf("\ndata corrupted\n");
    }
}
