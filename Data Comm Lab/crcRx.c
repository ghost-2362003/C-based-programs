#include<stdio.h>
#include<string.h>

void xor(char dividend[], char divisor[]){
    int len = strlen(divisor);
    for(int i = 0; i<len; i++){
        dividend[i] = (divisor[i] == dividend[i])?'0':'1';
    }
}

void checkError(char data[], char polynomial[], char crc[]){
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
    char receivedData[100], polynomial[20], remainder[20];

    printf("\nenter received data: ");
    scanf("%s", receivedData);

    printf("\nenter the divisor: ");
    scanf("%s", polynomial);
    checkError(receivedData, polynomial, remainder);

    int isError = 0;
    for(int i = 0; i<strlen(remainder); i++){
        if(remainder[i] != '0'){
            isError = 1;
            break;
        }
    }

    if(isError == 1){
        printf("\nreceived data corrupted\n");
    }
    else{
        printf("\nreceived data ok");
    }

    return 0;
}
