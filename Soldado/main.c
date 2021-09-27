#include <stdio.h>
#include <stdlib.h>
#include "hEx9.h"

void limpa(){
    setbuf(stdin, NULL);
}

int main(){
    Lista *a;
    char nome[25],soldelimi[25];
    int num,opcao,tam;
    a = cria_lista();
    srand(time(0));
    printf("Digite a quantidade de soldados: ");
    scanf("%d",&num);
    for(int i = 0; i < num ; i++){
        printf("Digite o nome do soldado: ");
        scanf("%s",nome);
        insere_final(&a, nome);
        limpa();
    }
    int f=1;
    if(num > 1){
        printf("\nSelecione o modo de inicio de contagem\n");
        printf(" 1- A partir do primeiro soldado\n");
        printf(" 2- A partir de um soldado sorteado aleatoriamente\n");
        printf(" 3- A partir de um soldado especifico\n");
        printf("Escolha: ");
    }
    srand(time(0));
    num = rand()%tamanho(&a);

    while(tamanho(&a) > 1){
        if(f==1){
            srand(time(0));
            scanf("%d",&opcao);
            if(opcao == 1){
                if(num == tamanho(&a) || num == 0){
                remove_inicio(&a,&soldelimi);
                printf("Numero sorteado : %d\n",num);
                printf("Soldado eliminado : %s\n",soldelimi);
                imprime(&a);
                printf("\n\n");
                }else if(num == tamanho(&a)-1){
                remove_fim(&a,&soldelimi);
                printf("Numero sorteado : %d\n",num);
                printf("Soldado eliminado : %s\n",soldelimi);               ///RETIRA UM SOLDADO
                imprime(&a);
                }else {
                remove_soldado(&a,num,&soldelimi);
                printf("Numero sorteado : %d\n",num);
                printf("Soldado eliminado : %s\n",soldelimi);
                imprime(&a);
                }
            }else if(opcao == 2){
                int alesold;
                srand(time(0));
                alesold = rand()%tamanho(&a);
                printf("\n");
                sorteiasoldado(&a,alesold,&soldelimi);
                printf("Numero sorteado para escolher o soldado: %d\n",alesold);
                printf("Soldado sorteado para comecar a contagem : %s\n",soldelimi);   ///SORTEIA O SOLDADO PARA COME�AR
                imprime(&a);
                printf("\n");
                if(num == tamanho(&a) || num == 0){
                remove_inicio(&a,&soldelimi);
                printf("Num sorteado : %d\n",num);
                printf("Soldado eliminado : %s\n",soldelimi);
                imprime(&a);
                }else if(num == tamanho(&a)-1){
                remove_fim(&a,&soldelimi);
                printf("Num sorteado : %d\n",num);                  ///RETIRA UM SOLDADO
                printf("Soldado eliminado : %s\n",soldelimi);
                imprime(&a);
                } else{
                remove_soldado(&a,num,&soldelimi);
                printf("Num sorteado : %d\n",num);
                printf("Soldado removido : %s\n",soldelimi);
                imprime(&a);
                printf("\n\n");
                }
            }else if(opcao == 3){
                int alesold;
                printf("Digite o nome do soldado que procura : ");
                scanf("%s",soldelimi);
                alesold = procura_soldado(&a,soldelimi);          ///COLOCA O SOLDADO COM O NOME DADO DA CABE�A DA LISTA
                printf("Numero do soldado : %d\n",alesold);
                sorteiasoldado(&a,alesold,&soldelimi);
                imprime(&a);
                if(num == tamanho(&a) || num == 0){
                remove_inicio(&a,&soldelimi);
                printf("Numero sorteado : %d\n",num);
                printf("Soldado eliminado : %s\n",soldelimi);
                imprime(&a);
                }else if(num == tamanho(&a)-1){
                remove_fim(&a,&soldelimi);
                printf("Numero sorteado : %d\n",num);
                printf("Soldado eliminado : %s\n",soldelimi);               ///RETIRA UM SOLDADO
                imprime(&a);
                }else {
                remove_soldado(&a,num,&soldelimi);
                printf("Numero sorteado : %d\n",num);
                printf("Soldado eliminado : %s\n",soldelimi);
                imprime(&a);
                printf("\n\n");
                }
            }
        f = 0;
        }else{
            srand(time(0));
            if(num == tamanho(&a) || num == 0){
            remove_inicio(&a,&soldelimi);
            printf("Num sorteado : %d\n",num);
            printf("Soldado eliminado : %s\n",soldelimi);
            imprime(&a);
            }else if(num == tamanho(&a)-1){
            remove_fim(&a,&soldelimi);
            printf("num sorteado : %d\n",num);
            printf("Soldado eliminado : %s\n",soldelimi);               ///RETIRA UM SOLDADO
            imprime(&a);
            } else{
            remove_soldado(&a,num,&soldelimi);
            printf("num sorteado : %d\n",num);
            printf("soldado removido : %s\n",soldelimi);
            imprime(&a);
            }
        }
    }
    printf("\n\n");
    printf("O sobrevivente foi : ");
    imprimesobrevivente(&a);
    return 0;
}
