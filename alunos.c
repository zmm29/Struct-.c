#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#define MAX 100
typedef struct aluno{
	char nome[50];
	int matricula;
	int prova1;
	int prova2;
	int prova3;
}taluno;
int qtd=0; 
int addaluno(taluno a[]){
	if(qtd==MAX) 
	  return 0;
	printf("Dados do aluno\n");
	printf("Nome:");
	fflush(stdin); 
	gets(a[qtd].nome);
	printf("Matrícula:");
	scanf("%d", &a[qtd].matricula);
	printf("Nota Primeira Prova");
	scanf("%d",&a[qtd].prova1);
	printf("Nota Segunda Prova");
	scanf("%d",&a[qtd].prova2);
	printf("Nota Terceira Prova");
	scanf("%d",&a[qtd].prova3);
	qtd++;
	return 1;  
}

void salvarAluno(taluno a[]){
	int i;
	FILE *arq;
	arq = fopen("3alunos.txt","w"); 
	fprintf(arq,"%d\n",qtd); 
	for(i=0;i<qtd;i++){
		fprintf(arq,"%s\n",a[i].nome);
		fprintf(arq,"%d\n",a[i].matricula);
		fprintf(arq,"%d\n",a[i].prova1);
		fprintf(arq,"%d\n",a[i].prova2);
		fprintf(arq,"%d\n",a[i].prova3);
	}
	printf("Dados salvos com sucesso :)\n");
	fclose(arq);
}
void buscaNome(taluno a[], char nomeBusca[50]){
	int i, existe=0;
	char aux[50];	
	for(i=0;i<qtd;i++){
		strcpy(aux,a[i].nome); 
	 if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){ 
		printf("%s\n",a[i].nome);
		printf("%d\n",a[i].matricula);
		printf("%d\n",a[i].prova1);
		printf("%d\n",a[i].prova2);
		printf("%d\n",a[i].prova3);
		printf("---------------------------------------------------\n");
		existe = 1;
	  }
	}
	if(!existe) 
	   printf("Aluno nao encontrado :(\n");   
}
void buscaMatri(taluno a[], int matriBusca){
	int i, existe=0;	
	for(i=0;i<qtd;i++){
	 if(a[i].matricula == matriBusca){ 
		printf("%s\n",a[i].nome);
		printf("%d\n",a[i].matricula);
		printf("%d\n",a[i].prova1);
		printf("%d\n",a[i].prova2);
		printf("%d\n",a[i].prova3);
		printf("---------------------------------------\n");
		existe = 1;
	  }
	}
	if(!existe) 
	   printf("Aluno nao encontrado :(\n");   
}
void maiorMed(taluno a[]){
	int i, existe=0, x=0;	
	float med, maior=0;
	for(i=0;i<qtd;i++){
		med = (a[i].prova1 + a[i].prova2 + a[i].prova3) / 3;
	 if(med > maior){ 
		maior= med;
		x = i;
		printf("---------------------------------------\n");
	  }
	} 
	    printf("%s\n",a[x].nome);
		printf("%d\n",a[x].matricula);
		printf("%d\n",a[x].prova1);
		printf("%d\n",a[x].prova2);
		printf("%d\n",a[x].prova3); 
}
//------------------------------------------
void aprovaAluno(taluno a[]){
	int i;	
	for(i=0;i<qtd;i++){
	 if((a[i].prova1 + a[i].prova2 + a[i].prova3) >= 6){ 
		printf("o aluno %d foi aprovado\n",i);
		printf("---------------------------------------\n");
	  }
	  else
	  	printf("o aluno %d foi reprovado\n",i);
	} 
}
void carregaAlunos(taluno a[]){
	FILE *arq;
	int i;
	arq = fopen("alunos.txt","r"); 
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}
	fscanf(arq,"%d",&qtd);
	printf("Carregando dados");
	for(i=0;i<qtd;i++){
		fscanf(arq,"%s",&a[i].nome);
		fscanf(arq,"%s",&a[i].matricula);
		fscanf(arq,"%d",&a[i].prova1);
		fscanf(arq,"%d",&a[i].prova2);
		fscanf(arq,"%d",&a[i].prova3);
	}
	fclose(arq); 
}
int menu(){
	int op;
	printf("Sistema de Cadastro de alunos \n");
	printf("1- Adicionar Alunos\n");
	printf("2- Salvar \n");
	printf("3- Buscar nome\n");
	printf("4- Buscar pelo numero matrícula\n");
	printf("5- Aluno com maior média das 3 provas \n");
	printf("6- Alunos aprovados e reprovados \n");
	printf("7- Carregar Alunos do arquivo \n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
int main(){
	taluno a[MAX];
	char busca[50];
	int buscamatri;
	int op;
	carregaAlunos(a);
	do{
		op = menu();
		switch(op){
			case 1: if(addaluno(a)==1)
			 			printf("Aluno adicionado com sucesso :)\n");
			 		else
					 	printf("Limite de alunos cadastrados atingido. (\n");
				break;
			case 2: salvarAluno(a);
				break;
			case 3: printf("Nome do aluno para busca:");
					fflush(stdin); gets(busca);
					buscaNome(a,busca);
				break;
			case 4: printf("Numero de matricula :");
					scanf("%d", &buscamatri);
					buscaMatri(a, buscamatri);
				break;
			case 5: maiorMed(a);
				break;	
			case 6: aprovaAluno(a);
				break;		
			case 7: carregaAlunos(a);
				break;		
			case 0: salvarAluno(a);
					printf("Saindo... \n");
				break;
			default: printf("Opcao invalida\n");			 	
		}
		getch();
		system("cls");
	}while(op!=0);	

	return 0;
}



