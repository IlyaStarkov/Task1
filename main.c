#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define LENGTH 10

typedef struct
{
    int *_binary_number;
    int length;
}NumberRecord;

NumberRecord decimalToBinaryConversion(int number_10);
NumberRecord *manyBinaryNumbers(int *many_decimal_numbers);
int numberReading();
int transf(char *Array);
void arrayOutput(NumberRecord* Array);

int main()
{
    setlocale(LC_ALL, "Rus");
    int SIZE, decimal_number, acc, c;
    printf("Введите количесто элементов множества:\n");
    SIZE = numberReading();
    printf("\n");
    int* many_decimal_numbers = (int*)malloc(SIZE * sizeof(int));
    for(int i = 0; i < SIZE; i++)
    {
        many_decimal_numbers[i] = numberReading();
    }
    NumberRecord *many_of_Bin = manyBinaryNumbers(many_decimal_numbers);
    arrayOutput(many_of_Bin);
    system("pause");
    return 0;
}

NumberRecord decimalToBinaryConversion(int number_10)
{
    int decimal_number, acc;
    for (int i = 0;; i++)
	{
		if (number_10 < pow(2, i))
		{
			acc = i;
			break;
		}

	}
	int *binary_number = (int*)malloc(acc * sizeof(int));
	int minuend = number_10;
    int var = acc - 1;
    for(int i = var; i >= 0; i--)
    {
        if((minuend - pow(2, i)) >= 0)
        {
            binary_number[var - i] = 1;
            minuend -= pow(2, i);
        }
        else
        {
            binary_number[var - i] = 0;
        }
    }

    NumberRecord value;
    value.length = acc;
    value._binary_number = binary_number;
    return value;
}

NumberRecord *manyBinaryNumbers(int *many_decimal_numbers)
{
    int acc = 0;
    NumberRecord bNamb;
    for(int i = 0; many_decimal_numbers[i] != '\0'; i++)
    {
        acc++;
    }
    NumberRecord *Array = (NumberRecord*)malloc(acc * sizeof(NumberRecord));
    for(int i = 0; i < acc; i++)
    {
        bNamb = decimalToBinaryConversion(many_decimal_numbers[i]);
        Array[i].length = bNamb.length;
        Array[i]._binary_number = bNamb._binary_number;
    }
    return Array;

}

int numberReading()
{
    int c, acc;
    char Array[LENGTH];
    acc = 0;
    for(int j = 0; j < LENGTH && (c = getchar()) != EOF && c != '\n'; j++)
    {
        acc++;
        Array[j] = c;
    }
    char* NAMB = (char*)malloc(acc * sizeof(char));
    for(int j = 0; j < acc ; j++)
    {
        NAMB[j] = Array[j];
    }
    return transf(NAMB);
}

int transf(char *Array)
{
    int wholePart = 0;
    int arr[100];
    int i = 0;
    int acc = 0;
    while (Array[i] != '\0')
    {
        arr[i] = Array[i] - '0';
        i++;
    }
    acc = i - 1;
    for (int a = 0; a < i; a++, acc--)
    {
        wholePart += arr[a] * pow(10, acc);
    }
    if(i == 9)
    {
        return wholePart + 2;
    }
    if(i == 8 || i == 6 || i == 5 || i == 3)
    {
        return wholePart + 1;
    }
    return wholePart;
}

void arrayOutput(NumberRecord* Array)
{
    printf("\n");
    for(int j = 0; Array[j].length != '\0'; j++)
    {
        for(int i = 0; i < Array[j].length; i++)
        {
            printf("%d", Array[j]._binary_number[i]);
        }
        printf("\n");
    }
}
