#include <stdio.h>
#include <string.h>

void generateSegmentsAndCount(char *data, int segLen, int dataLen);
void arrange(char *data, int segLen, int dataLen);

int main()
{
    char data[100];
    int segLen, dataLen;
    printf("Enter the data stream: ");
    scanf("%s", data);
    printf("Enter the segment length: ");
    scanf("%d", &segLen);

    dataLen = strlen(data);
    if (dataLen % segLen == 0)
    {
        generateSegmentsAndCount(data, segLen, dataLen);
    }
    else if (dataLen % segLen != 0)
    {
        arrange(data, segLen, dataLen);
    }
}

void arrange(char *data, int segLen, int dataLen)
{
    int temp = segLen - (dataLen % segLen);
    char tempdata[100];

    for (int i = 0; i < temp; i++)
    {
        tempdata[i] = '0';
    }

    tempdata[temp] = '\0'; // Null-terminate the string
    strcat(tempdata, data);
    strcpy(data, tempdata);

    generateSegmentsAndCount(data, segLen, strlen(data));
}

void generateSegmentsAndCount(char *data, int segLen, int dataLen)
{

    for (int i = 0; i < dataLen; i += segLen)
    {
        printf("Segment %d: ", i / segLen + 1);
        int count = 0;

        for (int j = i; j <= i + segLen - 1 && j < dataLen; j++)
        {
            printf("%c", data[j]);
            if (data[j] == '1')
            {
                count++;
            }
        }

        printf("\t\t 1's count: %d", count);
        printf("\n");
    }
}