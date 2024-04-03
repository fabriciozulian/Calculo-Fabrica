/*Em uma fabrica trabalham homens e mulheres divididos em tres classe:
trabalhadores que fazem ate 30 pecas por mes classe 1 RECEBE salario minimo.
trabalhadores que fazem de 31 a 35 pecas por mes classe 2 RECEBE salario minimo mais 3% do salario minimo por peca produzida a partir de 30.
trabalhadores que fazem acima de 35 pecas por mes classe 3 RECEBE salario minimo mais 5% do salario minimo por peca acima de 35.
faca um programa que recebe o numero de operarios o numero de pecas produzidas no mes, o sexo e calcule:
***numero do operario e seu salario.
***total da folha do pagamento da fabrica.
***total de pecas fabricadas no mes.
***media de pecas fabricadas por homem.
***media de pecas fabricadas por mulheres.
***registro do operario/sexo/ do maior salario*/



#include <stdio.h>
#include <ctype.h>
struct funcionario
{
    int rg;
    float salario;
    char sexo;
    int classe;
    float pecas;
};

int main()
{
    int ttfuncionarios=0, rgmaior=0, totalfuncionario=0;
    float ttpecas=0, maiorsalario=0, totalsalario=0, ttm=0, ttf=0,mediaf=0, mediam=0;
    char sexomaior;
    int hm=0, hf=0;
    void BEMVINDO()
    {
        printf("************************\n");
        printf("BEM VINDO AO FABRISYSTEM\n");
        printf("************************\n");
    }


    BEMVINDO();
    printf("\n\ndigite a quantidade de funcionarios: ");
    scanf("%i", &ttfuncionarios);
    totalfuncionario = ttfuncionarios;



    struct funcionario fun[ttfuncionarios];

    void coleta()
    {
        for(int i=0; i<ttfuncionarios; i++)
        {
            printf("\n\n\nDigite o numero de registro do funcionario: ");
            scanf("%i", &fun[i].rg);
            printf("Digite o sexo do funcionario M / F : ");
            fflush(stdin);
            scanf("%c", &fun[i].sexo);
            printf("Digite a producao do funcionario: ");
            scanf("%f", &fun[i].pecas);
            if(fun[i].pecas<30)
            {
                fun[i].classe = 1;
            }
            if(fun[i].pecas >= 30 && fun[i].pecas<36)
            {
                fun[i].classe = 2;
            }
            if(fun[i].pecas >= 35)
            {
                fun[i].classe = 3;
            }
            printf("Classe do funcionario RG:%i = %i", fun[i].rg,fun[i].classe);
            if(fun[i].classe==1)
            {
                fun[i].salario = 1412;
            }
            if(fun[i].classe==2)
            {
                fun[i].salario = 1412 +((fun[i].pecas - 30)*((1412/100)*3));
            }
            if(fun[i].classe==3)
            {
                fun[i].salario = 1412 +((fun[i].pecas - 35)*((1412/100)*5));
            }
            printf("\nSalario do funcionario RG:%i = %.2f", fun[i].rg, fun[i].salario);
            totalsalario = totalsalario + fun[i].salario;
            ttpecas = ttpecas + fun[i].pecas;
            fflush(stdin);
            if(fun[i].salario > maiorsalario)
            {
                maiorsalario = fun[i].salario;
                sexomaior = fun[i].sexo;
                rgmaior = fun[i].rg;

            }
        }
    }
    void resultado ()
    {
        printf("\nTotal de funcionarios %i", totalfuncionario);
        for(int j = 0; j<totalfuncionario; j++)
        {
            printf("\n\nRegistro: %i", fun[j].rg);
            printf("\nSexo: %c", fun[j].sexo);
            printf("\nClasse: %i", fun[j].classe);
            printf("\nPecas: %.2f", fun[j].pecas);
            printf("\nSalario %.2f", fun[j].salario);
            if(fun[j].sexo == 'M'||fun[j].sexo == 'm')
            {
                ttm = ttm + fun[j].pecas;
                hm++;
            }
            fflush(stdin);
            if(fun[j].sexo == 'F'|| fun[j].sexo == 'f')
            {
                ttf = ttf + fun[j].pecas;
                hf++;
            }
        }
        mediam = ttm/hm;
        mediaf = ttf/hf;
        if(hm==0)
        {
            mediam = 0;
        }
        if(hf==0)
        {
            mediaf = 0;
        }
        printf("\n\nTotal folha de pagamento: %.2f", totalsalario);
        printf("\nPecas fabricadas no mes: %.2f", ttpecas);
        printf("\nMedia de pecas fabricadas por homens: %.2f", mediam);
        printf("\nMedia de pecas fabricadas por mulheres: %.2f", mediaf);
        printf("\n\n\nRegistro do funcionario com maior salario: %i", rgmaior);
        printf("\nSexo do funcionario: %c", sexomaior);
        printf("\nSalario: %.2f\n\n", maiorsalario);

    }
    coleta();
    resultado();
    return 0 ;
}
