#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define inputFILE "result.txt"

int getNum();
void checkNum(int num);
FILE* openFile(void);

int GetNumber(void)
{
    int GetNum;
    GetNum = rand()% 101;
    return GetNum;
}

void checkNum(int num)
{
    if(num <= 2 || num >= 6){
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char *argv[])
{
     FILE *f = openFile();
    if(argc!=2) return -1;
    else{
    int num;
    num=atoi(argv[1]);
    sscanf(argv[1], "%d", &num);
    checkNum(num);

    int n = 0;
    int count = 0;
    int RandNumber, OperationNumber;
    int operation, number, sum;

    fprintf(f,"1756143\n");


    while (n < number){
        number = rand() % 100;
        sum = number;
        OperationNumber = rand()%4;
        fprintf(f,"%d", number);
        count = 0;
        while(count <= OperationNumber){
        RandNumber = rand() % 100;
        operation = rand() % 4;
            switch(operation){
            case 0:
                fprintf(f," + %d", RandNumber);
                sum += RandNumber;
                break;
            case 1:
                fprintf(f," - %d", RandNumber);
                sum -= RandNumber;
                break;
            case 2:
                fprintf(f," * %d", RandNumber);
                sum *= RandNumber;
                break;
            case 3:
                fprintf(f," / %d", RandNumber);
                sum /= RandNumber;
                break;
            default:
                exit(EXIT_FAILURE);
            }
            count++;
        }
        fprintf(f," = %d\n", sum);
        n++;
    }
    }
    fclose(f);
    return 0;
}


FILE* openFile(void)
{
    FILE *f = fopen(inputFILE,"w");

    if(f == NULL){
        printf("FILE not found!");
        exit(EXIT_FAILURE);
    }
    return f;
}

