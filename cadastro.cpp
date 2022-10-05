#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <locale.h> 
#include <string.h> 
#include <ctype.h>

struct tcadastro{
	char nome[50];
	int cpf;
};
struct tcadastro cadastro[50];

int main(){
	int escolha, cont=-1, contComparador=0;
	char soun, aux[50];
	FILE *arq;
	setlocale(LC_ALL, "portuguese");
	
	while(1){
	arq =fopen ("Cadastro.txt","r");
	if(arq == NULL){
		printf("\nERRO, arquivo não encontrado!\n");
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
					
					printf("\nDigite o seu cpf:");
					scanf("%d", &cadastro[cont].cpf);
					
					printf("\nDeseja conitnuar?S/N");
					soun=toupper(getch());
					if(soun == 'N')
						break;
				}
				
		break;}
		case 2:{
				system("cls");
				printf("::::::::::Listas de Pessoas::::::::::");
				
				while(contComparador < cont){
					
					if(strcmp(cadastro[contComparador].nome,cadastro[contComparador++].nome)>0){
						strcpy(aux,cadastro[contComparador].nome);
						strcpy(cadastro[contComparador].nome,cadastro[contComparador++].nome);
						strcpy(cadastro[contComparador++].nome,aux);
					}
					
					else
						contComparador++;
				}
				

				for(int i=0;i<=cont;i++){
					printf("\nNome:%s", cadastro[i].nome);
					printf("\nCpf:%d", cadastro[i].cpf);
					if(i > 10){
						printf("\nReserva");
					}
				}
				getch();
		break;}
		case 3:{
				
		break;}
		case 0:{
			return 0;	
		break;}
	}
	
	}
	return 0;
}
