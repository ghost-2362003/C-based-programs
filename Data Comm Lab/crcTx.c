#include<stdio.h>
#include<string.h>

void xor(char dividend[], char divisor[]){
    int len = strlen(divisor);
    for(int i = 0; i<len; i++){
        dividend[i] = (dividend[i] == divisor[i])?'0':'1';
    }
}

void ComputeCRC(char data[], char polynomial[], char crc[]){
    int datalen = strlen(data);
    int polylen = strlen(polynomial);
    char temp[datalen+1];
    strcpy(temp, data);

    for(int i = 0; i<=datalen-polylen; i++){
        xor(temp+i, polynomial);
        while(i<datalen && temp[i] != '1'){
            i++;
        }
    }

    strcpy(crc, temp + datalen - polylen + 1);
}

int main(){
    char data[100], polynomial[20], crc[20], appendedData[120];

    printf("\nenter the data: ");
    scanf("%s", data);

    printf("\nenter the divisor: ");
    scanf("%s", polynomial);

    int datalen = strlen(data);
    int polylen = strlen(polynomial);
    strcpy(appendedData, data);
    for(int i = 0; i<polylen-1; i++){
        strcat(appendedData, "0");
    }

    ComputeCRC(appendedData, polynomial, crc);

    printf("\nCRC: %s", crc);
    strcat(data, crc);
    printf("\nTransmitted data: %s\n", data);

    return 0;
}
