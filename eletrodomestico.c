#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
	char nome[30];
	float potencia, horas;
}tEletro;
int qtd=0;

void add(tEletro e[]){
	if(qtd==MAX){
		printf("Sistema lotado \n");
	}
	printf("Nome do Eletro: ");
	fflush(stdin);
	gets(e[qtd].nome);
	printf("Potencia: ");
	scanf("%f", &e[qtd].potencia);
	printf("Tempo medio ativo por dia em horas: ");
	scanf("%f",&e[qtd].horas);
	qtd++;
	printf("ADICIONADO COM SUCESSO\n");
}
void listar(tEletro e[]){
	int i;
	for(i=0; i<qtd; i++){
		printf("Eletro %d \n",i+1);
		printf("Nome: %s\n", e[i].nome);
		printf("Potencia: %.2f KW\n",e[i].potencia);
		printf("Tempo medio ativo por dia: %.2f Hrs\n",e[i].horas);
	}
}

void buscaEletro(tEletro e[], char buscaNome[]){
	int i, encontrou=0;
	for(i=0;i<qtd;i++){
		if(strcmp(strupr(e[i].nome), strupr(buscaNome) )==0){
		printf ("\n Eletro %d \n",i+1);
		printf("Nome:%s\nPotencia:%f KW\nTempo medio ativo por dia:%.2f Hrs\n",
		e[i].nome, e[i].potencia, e[i].horas);
		printf("*******************************\n");
		encontrou=1;
		break;
		}
	}
	if (!encontrou)
printf("Eletro não encontrado");
}



void consumoTotal(tEletro e[] , float valorKWh){
	int i;
	float consumoDiarioKW = 0;
	for(i=0; i<qtd; i++){
		consumoDiarioKW += e[i].potencia*e[i].horas;
	}
	printf("\nConsumo diario em KW: %.2lf\nConsumo Diario em R$: %.2lf\n", consumoDiarioKW, consumoDiarioKW * valorKWh);
	printf("\nConsumo diario em KW: %.2lf\nConsumo Diario em R$: %.2lf\n", consumoDiarioKW*30, (consumoDiarioKW * 30) * valorKWh);
}

int menu(){
	int op;
	printf("*****CADASTRO DE ELETRODOMESTICOS*****\n");
	printf("1-Cadastrar\n");
	printf("2-Mostrar eletros cadastrados\n");
	printf("3-Buscar eletro pelo nome\n");
	printf("4-Consumo\n");
	printf("0-Sair\n");
	scanf("%d",&op);
	return op;
}

int main(){
	int op;
	tEletro e[MAX];
	char buscaNome[30];
	float valorKWh;
	do{
		op=menu();
		switch(op){
			case 1: add(e);
			break;
			case 2: listar(e);
			break;
			case 3: printf("Nome do eletro para busca:");
			fflush(stdin); gets(buscaNome);
			buscaEletro(e, buscaNome);
			break;
			case 4: printf("Qual o valor para busca:");
				scanf("%f", &valorKWh);
			break; 	
				consumoTotal(e, valorKWh);
				case 0:
					printf("SAINDO...\n");
					break;
		}
		getch();
		system("cls");
	}while(op!=0);
	return 0;
}
