#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <locale.h> 
#include <string.h> 
#include <ctype.h>

struct tcadastro{
	char nome[50];
	int cpf, cadeira;
};
struct tcadastro cadastro[50];

void linha(){
	printf("\n------------------------------");
}

//int desistencia(int cpf, cont){
//	int i,j;
//	
//	for(i=0;i<=cont;i++){
//		if(auxN==cadastro[i].cpf){
//			
//		}
//	}
//	cont--;
//	return true;
//}

int main(){
	int escolha, cont=-1, contComparador=0,igual, auxN, auxC;
	char soun, auxS[50];
	FILE *arq;
	setlocale(LC_ALL, "portuguese");
	
	while(1){
	arq =fopen ("Cadastro.txt","r");
	if(arq == NULL){
		printf("\nERRO, arquivo n�o encontrado!\n");
		system("pause");
		return 0;
	}
	
	
	system("cls");
	printf("::::::::::Reserva Teatro::::::::::");
	printf("\n1-Cadastra\n2-Listar pessoas\n3-Desistencia\n0-Sair\n");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 1:{
				while(1){
					cont++;
					system("cls");
					printf("::::::::::Cadastro::::::::::");
					printf("\nDigite o seu nome:");
					scanf("%s", &cadastro[cont].nome);
					cadastro[cont].nome[0]=toupper(cadastro[cont].nome[0]);
					
					printf("\nDigite o seu cpf:");
					scanf("%d", &cadastro[cont].cpf);
					
					cadastro[cont].cadeira=cont+1;
					printf("\nDeseja conitnuar?S/N");
					soun=toupper(getch());
					if(soun == 'N')
						break;
				}
				
		break;}
		case 2:{
				system("cls");
				printf("::::::::::Listas de Pessoas::::::::::");
				//Passar para fun��o depois
				while(contComparador < cont){
					igual = strcmp(cadastro[contComparador].nome,cadastro[contComparador+1].nome);
					if(igual>0){
						strcpy(auxS,cadastro[contComparador].nome);
						auxN=cadastro[contComparador].cpf;
						auxC=cadastro[contComparador].cadeira;
						strcpy(cadastro[contComparador].nome,cadastro[contComparador+1].nome);
						cadastro[contComparador].cadeira=cadastro[contComparador+1].cadeira;
						strcpy(cadastro[contComparador+1].nome,auxS);
						cadastro[contComparador+1].cadeira=auxC;
						contComparador=0;
					}
					
					else
						contComparador++;
				}
				

				for(int i=0;i<=cont;i++){
					printf("\nNome:%s", cadastro[i].nome);
					printf("\nCpf:%d", cadastro[i].cpf);
					printf("\nCadeira:%d",cadastro[i].cadeira);
					if(cadastro[i].cadeira > 10){
						printf("\n--Reserva--");
					}
					linha();
				}
				getch();
		break;}
		case 3:{
				printf("::::::::::Desistencia::::::::::");
				printf("\nDigite o Cpf da Desistencia:");
				scanf("%d",auxN);
//				desistencia(auxN,cont);
		break;}
		case 0:{
			return 0;	
		break;}
	}
	
	}
	return 0;
}
