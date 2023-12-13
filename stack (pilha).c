#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	char nome[50];
	Data data;
}Pessoa;

typedef struct no{
	Pessoa p;
	struct no *proximo;
}No;

Pessoa ler_pessoa()
{
	Pessoa p;
	printf("Digite o nome da pessoa: ");
	fgets(p.nome,50,stdin);
	printf("Digite a data de nascimento DD MM AAAA: ");
	scanf("%d %d %d", &p.data.dia,&p.data.mes,&p.data.ano);
	return p;	
}

void imprimir_pessoa(Pessoa p)
{
	printf("Nome: %s\nData: %2d/%2d/%2d", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

No* empilhar(No *topo)
{
	No *novo = malloc(sizeof(No));
	
	system("cls");
	if(novo)
	{
		novo->p = ler_pessoa();
		novo->proximo = topo;
		
		return novo;
	}
	else
	{
		printf("Nao foi possivel alocar memoria");
	}
	return NULL;
}

No* desempilhar(No **topo)
{
	if(*topo)
	{
		No *remover = *topo;
		*topo = remover->proximo;
		return remover;
	}
	else
	{
		printf("Pilha vazia!");
	}
}

void imprimir_pilha(No *topo)
{
	system("cls");
	
	while(topo)
	{
		imprimir_pessoa(topo->p);
		topo = topo->proximo;
	}
	
	printf("\n\n");
	system("pause");
}

int main(void)
{
	No *topo = NULL, *remover;
	int opcao;
	
	system("cls");
	do
	{
		printf("[0] - Sair\t[1] - Empilhar\t[2] - Desempilhar\t[3] - Imprimir\n\n");
		printf("Digite a opcao desejada: ");
		scanf("%d", &opcao);
		getchar();
		
		switch(opcao)
		{
			case 0:
				return 0;
			break;
			
			case 1:
				topo = empilhar(topo);
			break;
			
			case 2:
				remover = desempilhar(&topo);
				if(remover)
				{
					printf("\n\n\n");
					printf("Pessoa removida:");
					imprimir_pessoa(remover->p);
					printf("\n\n\n");
				}
				else
				{
					printf("filha vazia");
				}
				
			break;
			
			case 3:
				imprimir_pilha(topo);
			break;
		}
	}while(opcao != 0);
}
