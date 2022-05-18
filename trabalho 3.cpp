#include<stdio.h>
#include<iostream>
#include<string.h>
#include <locale.h>
#include <stdlib.h>

using namespace std;

void merge(int v[], int s, int m, int e) {
    int tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (v[i] < v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    for (; i <= m; i++, k++) {
        tmp[k] = v[i];
    }
    for (; j <= e; j++, k++) {
        tmp[k] = v[j];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}



void mergeSort(int v[], int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);

        // Aqui é a lógica da conquista
            merge(v, s, m, e);
    }
}

//-------------------Agora vamos para o quickSort----------------------------------------
void troca(int v[], int a,int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}



int particiona(int v[],int s, int e)
{
    int pivot = v[s];
    int i=s;
    for(int j=s+1; j<=e; j++)
    {
        if(v[j]<=pivot)
        {
            i++;
            troca(v,i,j);
        }
    }
    troca(v,s,i);
    return i;

}




int quickSort(int v[], int s, int e)
{
    if (s<e)
    {
        int p = particiona(v,s,e);
        quickSort(v,s,p-1);
        quickSort(v,p+1,e);
    }
}

void imprimeVetor(int v[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\n",i,v[i]);

    }
    printf("\n");
    system("pause");
}



int buscaSequencial(int v[],int n, int x){


    for (int i=0; i<n;i++){

        if (v[i]==x){

            return i;
        }
    }
    return -1;
}

int buscaBinaria(int v[], int n, int x){
    int s=0, e=n-1;
        while (s<=e){
            int m= (s+e)/2;
            if(x==v[m]){
                return m;
            }else if(x>v[m]){
            s = m+1;
            }else if(x<v[m]){
            e= m-1;
            }
        }
return -1;
}







void menu(int *v){
    printf("SEJA BEM VINDO AO NOSSO PROGRAMA\n");
    printf("SIGA AS INSTRUÇÕES A SEGUIR PARA UTILIZAR O SOFTWARE\n\n\n");

    int d=1;
    int n=0;
    int busca,buscaVerifica;
    bool verifica = false;
    bool verificaOrdenacao = false;
    int i=0;
    char letra;
    int aux = 0;
    while (d!=0)
    {
        printf("DIGITE A OPÇÃO CORRESPONDENTE:\n");
        printf("DIGITE 1 PARA GERAR UM NOVO VETOR ALEATORIO\n");
        printf("DIGITE 2 PARA ORDENAR O VETOR\n");
        printf("DIGITE 3 PARA BUSCA SEQUENCIAL\n");
        printf("DIGITE 4 PARA BUSCA BINÁRIA\n");
        printf("DIGITE 5 PARA EXIBIR O VETOR\n");
        printf("DIGITE 0 PARA SAIR DO SISTEMA\n");
        cin >> d;

        switch(d)
        {

        case 1:
            system("cls");

            printf("DIGITE A QUANTIDADE DE VALORES DO NOVO VETOR\n\n");
            scanf("%d",&n);
            printf("VETOR GERADO COM SUCESSO\n\n");
            v = (int *) malloc(n * sizeof(int));
                for(i=0;i<n;i++){
                v[i]=rand();
                }
                verifica = true;
                verificaOrdenacao = false;
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            if (verifica == true){
            printf("PARA ORDENAR SEU VETOR, POR FAVOR DIGITE O MÉTODO DE ORDENAÇÃO DESEJADO:\n\n");
            fflush(stdin);
            printf("DIGITE 'Q' PARA O MÉTODO QUICKSORT E 'M' PARA O MÉTODO MERGESORT\n");
            scanf("%c", &letra);

            letra = toupper(letra);

            if (letra=='Q'){
            quickSort(v,0,n-1);
            printf("VETOR ORDENADO COM SUCESSO\n");
            verificaOrdenacao = true;
            fflush(stdin);
            }else if(letra=='M'){
            mergeSort(v,0,n-1);
            printf("VETOR ORDENADO COM SUCESSO\n");
            verificaOrdenacao = true;
            fflush(stdin);
            }else printf("ERRO - OPÇÃO INVÁLIDA\n");
            system("pause");
            fflush(stdin);
            system("cls");
            }else {
                printf("SELECIONE A OPÇÃO 1 PRIMEIRO NO MENU ANTERIOR E DEPOIS RETORNE A ESSA FUNÇÃO\n\n");
            system("pause");
            fflush(stdin);
            system("cls");
            }
            break;

        case 3:
            if (verifica==true){
            system("cls");
            busca = 0;
            printf("BEM VINDO A BUSCA SEQUENCIAL\n\nDIGITE O VALOR QUE DESEJA BUSCAR E DIREMOS SE O MESMO ESTÁ CONTIDO NO VETOR\n");
            scanf("%d",&busca);
            buscaVerifica=buscaSequencial(v,n,busca);
            if (buscaVerifica == -1)
            {
                printf("VALOR NÃO ESTÁ CONTIDO NO VETOR\n");
                fflush(stdin);
                printf("\n\nDESEJA VISUALIZAR O VETOR? 1 para SIM e 2 para NÃO\n\n\n");
                scanf("%d",&aux);
                    if(aux==1){
                        imprimeVetor(v,n);
                    }
            }else {
                printf("O VALOR '%d' ESTÁ NO VETOR E SE ENCONTRA NA POSIÇÃO '%d' DO MESMO\n\n",busca,buscaVerifica);
                fflush(stdin);
                printf("\n\nDESEJA VISUALIZAR O VETOR? 1 para SIM e 2 para NÃO\n\n\n");
                scanf("%d",&aux);
                    if(aux==1){
                        imprimeVetor(v,n);
                    }
            }
            system("cls");
            }else {
                printf("NÃO HÁ UM VETOR PARA REALIZARMOS A BUSCA SEQUENCIAL, POR FAVOR VOLTE AO MEU ANTERIOR E CRIE UM VETOR NA OPÇÃO 1\n");
                system("pause");
                system("cls");
            }
            break;

        case 0:
            system("cls");
            printf("Obrigado por utilizar nosso sistema\n\n\n\n\n");
            system("pause");
            system("cls");
            break;

        case 4:
          busca = 0;
          buscaVerifica = 0;
          if(verifica == true && verificaOrdenacao == true){
            printf("BEM VINDO A BUSCA BINÁRIA\n\nDIGITE O VALOR QUE DESEJA BUSCAR E DIREMOS SE O MESMO ESTÁ CONTIDO NO VETOR\n");
            scanf("%d",&busca);
            buscaVerifica=buscaBinaria(v,n,busca);
            if (buscaVerifica == -1)
            {
                printf("VALOR NÃO ESTÁ CONTIDO NO VETOR\n");
                fflush(stdin);
                printf("\n\nDESEJA VISUALIZAR O VETOR? 1 para SIM e 2 para NÃO\n\n\n");
                scanf("%d",&aux);
                    if(aux==1){
                        imprimeVetor(v,n);
                    }
                    system("cls");
            }else {
                printf("O VALOR '%d' ESTÁ NO VETOR E SE ENCONTRA NA POSIÇÃO '%d' DO MESMO\n\n",busca,buscaVerifica);
                fflush(stdin);
                printf("\n\nDESEJA VISUALIZAR O VETOR? 1 para SIM e 2 para NÃO\n\n\n");
                scanf("%d",&aux);
                    if(aux==1){
                        imprimeVetor(v,n);
                    }
            }
            system("cls");
          }else if(verifica==false){
              printf("NÃO HÁ UM VETOR PARA REALIZARMOS A BUSCA SEQUENCIAL, POR FAVOR VOLTE AO MEU ANTERIOR E CRIE UM VETOR NA OPÇÃO 1\n");
                system("pause");
                system("cls");
          }else {
              if(verifica==true && verificaOrdenacao==false){
                printf("SEU VETOR EXISTE PORÉM NÃO ESTÁ ORDENADO, VOLTE AO MENU ANTERIOR E ORDENE O MESMO\n");
                system("pause");
                system("cls");
          }
            break;

        case 5:
            printf("EXIBINDO VETOR...\n\n\n");
            imprimeVetor(v,n);
            system("cls");
            system("pause");
            break;


        default:
            system("cls");
            printf("OPERAÇÃO INVÁLIDA, TENTE NOVAMENTE ");
            system("pause");

        }
    }
    }
}




int main (void){
    setlocale(LC_ALL,"");
    int *v;
    menu(v);
}
