#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int int_0025 = 0;
    int int_0010 = 0;
    int int_0005 = 0;
    int int_0001 = 0;
    float floatMoney = 0;
    int intMoney = 0;
    int intTotalCurrency = 0;

    // Entrada, valor do troco.
    do
    {
        floatMoney = get_float("Entre com o valor do troco (De R$ 0,01 à R$ 1.000,00): ");
        intMoney = floatMoney * 1000;
    }
    while (floatMoney < 0 || floatMoney > 1000);

    // Loop contador
    while (intMoney > 0)
    {
        if (intMoney >= 250)
        {
            int_0025++;
            intMoney -= 250;
        }
        else if (intMoney >= 100)
        {
            int_0010++;
            intMoney -= 100;
        }
        else if (intMoney >= 50)
        {
            int_0005++;
            intMoney -= 50;
        }
        else if (intMoney >= 10)
        {
            int_0001++;
            intMoney -= 10;
        }
    }

    intTotalCurrency = int_0025 + int_0010 + int_0005 + int_0001;

    // Informa o resultado
    printf("\n");
    printf("Você precisa de: \n %i de R$ 0,01 \n %i de R$ 0,05 \n %i de R$ 0,10 \n %i de R$ 0,25\n", int_0001, int_0005, int_0010,
           int_0025);
    printf("Quantidade de moedas para o troco: %i", intTotalCurrency);
    printf("\n");
}