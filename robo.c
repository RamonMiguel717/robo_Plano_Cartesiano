#include <stdio.h>
#include <stdlib.h>

typedef struct robo {
    int x;
    int y;
} robo;

int calculaPassos(int ciclo) {
    if (ciclo == 1) return 1;

    int passos = 1; 
    int diferenca = 1; 

    for (int i = 2; i <= ciclo; i++) {

        passos += diferenca;

        if (i % 2 == 0) {
            diferenca++;
        }
    }   
    
    return passos;
}

void localizacaoAtual(robo robo) {
    printf("Seu robo esta localizado em: (%d, %d)\n", robo.x, robo.y);
}

void moverRobo(robo *robo, int temp, int *passos) {
    robo->x= 0;
    robo->y= 0;

    for (int i= 1;i<= temp;i++) {
        int resto= i%4;

        if (resto== 1) {
            robo->x+= 1;
        } else if (resto== 2) {
            robo->y += 1;
        } else if (resto== 3) {
            robo->x= -robo->x;
        } else if (resto== 0) {
            robo->y= -robo->y;
        }
        *passos= calculaPassos(i);
        if (temp > 4)
{
   do
{
        robo->x++;
        robo->y++;
}
while (temp % 4 == 0);

}
    }

    system("cls");
    localizacaoAtual(*robo);
}

int main() {
    int ciclos;
    int temp= 0, i;
    int passos=0;
    robo meuRobo= {0, 0};  

    do {
        printf("Qual opcao desejas realizar?\n (1) Movimentar o Robo.\n (2) Descobrir a quantidade de passos realizados ate o momento.\n (3) Onde o robo esta localizado.\n (4) Quantos ciclos foram realizados ate agora.\n(0) Sair do programa.\n");
        scanf("%d", &i);

        switch (i) {
            case 1:
                printf("Digite a quantidade de ciclos: ");
                scanf("%d", &ciclos);
                temp += ciclos;
                moverRobo(&meuRobo, temp, &passos);
                break;

            case 2:
                printf("Foram realizados %d passos ate o momento\n", passos);
                break;

            case 3:
                localizacaoAtual(meuRobo);  
                break;

            case 4:
                printf("Total de ciclos realizados: %d\n", temp);
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (i != 0);

    return 0;
}
