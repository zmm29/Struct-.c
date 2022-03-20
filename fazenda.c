#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100
typedef struct gado{
	int codigoGado;
	int leite;
	float alimento;
	int mesNascimento;
	int anoNascimento;
	int abate;
}tgado;

int qtd=0;

int addGado(tgado b[]){
	if(qtd==MAX)
	  return 0;
	printf("Dados do animal: \n");
	printf("Codigo:");
	scanf("%d", &b[qtd].codigoGado);
	printf("Quantidade de leite produzida na semana:");
	scanf("%d", &b[qtd].leite);
	printf("Quantidade de alimento consumido por semana:");
	scanf("%f",&b[qtd].alimento);
	printf("Mês de nascimento");
	scanf("%d",&b[qtd].mesNascimento);
	printf("Ano de nascimento");
	scanf("%d",&b[qtd].anoNascimento);
	if((2022 - b[qtd].anoNascimento) > 5 ||b[qtd].leite < 40 )
	    b[qtd].abate = 1;
	
	qtd++;
	return 1;  
}
int leiteSemana(tgado b[]){
	int totalLeite=0,i;
	for(i=0;i<qtd;i++){
		totalLeite =  totalLeite + b[i].leite;
	}
	printf("A quantidade total de leite produzida na semana é %d", totalLeite);
}
int alimSemana(tgado b[]){
	float totalAlim=0;
	int i;
	for(i=0;i<qtd;i++){
		totalAlim=  totalAlim + b[i].alimento;
	}
	printf("A quantidade total alimentos consumidos na semana é %.2f", totalAlim);
}
int listaAbate(tgado b[]){
	int x;
	for(x=0;x<qtd;x++){
		if(b[x].abate == 1){
		printf("%d\n",b[x].codigoGado);
		printf("%d\n",b[x].leite);
		printf("%.2f\n",b[x].alimento);
		printf("%d\n",b[x].mesNascimento);
		printf("%d\n",b[x].anoNascimento);
		printf("%d\n",b[x].abate);
		}
	}
}

void salvarGado(tgado b[]){
	int i;
	FILE *arq;
	arq = fopen("6gado.txt","w"); 
	fprintf(arq,"%d\n",qtd); 
	for(i=0;i<qtd;i++){
		fprintf(arq,"%d\n",b[i].codigoGado);
		fprintf(arq,"%d\n",b[i].leite);
		fprintf(arq,"%.2f\n",b[i].alimento);
		fprintf(arq,"%d\n",b[i].mesNascimento);
		fprintf(arq,"%d\n",b[i].anoNascimento);
		fprintf(arq,"%d\n",b[i].abate);
	}
	printf("Dados salvos com sucesso :)\n");
	fclose(arq);
}

void carregaGado(tgado b[]){
	FILE *arq;
	int x;
	arq = fopen("fazenda.txt","r"); 
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}
	fscanf(arq,"%d",&qtd);
	printf("Carregando dados");
	for(x=0;x<qtd;x++){
		scanf("%d\n",b[x].codigoGado);
		scanf("%d\n",b[x].leite);
		scanf("%.2f\n",b[x].alimento);
		scanf("%d\n",b[x].mesNascimento);
		scanf("%d\n",b[x].anoNascimento);
		scanf("%d\n",b[x].abate);
	}
	fclose(arq);
	system("cls"); 
}

int menu(){
	int op;
	printf("Sistema de Cadastro de Gado \n");
	printf("1- Adiciona Gado\n");
	printf("2- Total de leite produzido na semana\n");
	printf("3- Total de alimentos consumidos na semana\n");
	printf("4- Lista de animais para abate\n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
int main(){
	tgado b[MAX];
	char busca[40];
	int buscaranking;
	int op;
	carregaGado(b);
	do{
		op = menu();
		switch(op){
			case 1: if(addGado(b)==1)
			 			printf("Dados Inseridos :)\n");
			 		else
					 	printf("Limite de Gado atingido :(\n");
				break;
			case 2: leiteSemana(b);
				break;
			case 3: alimSemana(b);
				break;
			case 4: listaAbate(b);
				break;
			case 0: salvarGado(b);
					printf("Saindo... \n");
				break;
			default: printf("Opcao invalida\n");			 	
		}
		getch(); 
		system("cls");
	}while(op!=0);	

	return 0;
}
