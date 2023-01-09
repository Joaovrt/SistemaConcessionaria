/*
Grupo - 04

210032 - Fernando Silva Martins;
210124 - João Victor Rosa Tagliarini;
210442 - Lucas Ribeiro Bonfílio de Lemos.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Structs e unions
typedef struct endereco {
 char logradouro[80]; 
 char bairro[15]; 
 char CEP[10]; 
 char cidade[15]; 
 char estado[3]; 
 char fone[12]; 
 char email[40]; 
}endereco; 
 
typedef struct infocarro {
 char sigla; 
 int regcarro; 
}infocarro; 
 
typedef union dadoscarro { 
 char sigla; 
 infocarro reservado; 
}dadoscarro; 
 
typedef struct loja {
 int regloja;
 char nome[30]; 
 char CNPJ[19]; 
 endereco end; 
 int sold; 
 int reserved; 
 dadoscarro  tabela[3]; 
}loja;

typedef struct infoloja {
 char sigla; 
 char CNPJ[19]; 
}infoloja; 
 
typedef union dadosloja {
 char sigla; 
 infoloja reserva; 
}dadosloja; 
 
typedef struct montadora {
 int regcarro; 
 char modelo[20]; 
 char cor[10]; 
 float  valor; 
 union dadosloja status; 
}montadora;

typedef struct data {
 int dia;  
 int mes;  
 int ano;  
}data; 
 
typedef struct historicoVendas {
 int reghist; 
 int regcarro; 
 char modelo[20]; 
 char cor[10]; 
 float valor;  
 int regloja; 
 char nome[30]; 
 char cnpj[19]; 
 data dataVenda; 
}historicoVendas; 

//Protótipo das funções
void alocacarro(montadora **p, int tam);
void alocahist(historicoVendas **p, int tam);
void alocaloja(loja **p, int tam);
void alteracarro(montadora *pc);
void alteraloja(loja *pl, montadora *pc, historicoVendas *ph);
int  bissexto(int ano);
int  buscalivres(montadora *p, int q);
int  buscaloja(loja *p, int q, char *pcnpj);
void buscalojahist(historicoVendas *p, int q, char *pcnpj);
int  buscamodelo(montadora *p, int q, char *m);
int  buscamodelohist(historicoVendas *p, int q, char *m);
int  buscaregistro(montadora *p, int q, int reg, char letra);
int  buscareservados(montadora *p, int q);
int  buscatabela(loja *pl, montadora *pc);
int  buscavago(montadora *p, int q);
void consultahistcnpj(loja *pl, historicoVendas *ph);
void consultahistmodelo(montadora *pc, historicoVendas *ph);
void consultaloja(loja *p);
void consultamodelo(montadora *p);
void consultastatus(montadora *p);
void consultatotal(montadora *p);
void encerrareserva(loja *pl, montadora *pc, historicoVendas *ph);
void gravacarro(montadora *p, char *abertura, int i);
void gravahist(historicoVendas *p, char *abertura, int i);
void gravaloja(loja *p, char *abertura, int i);
void mostralivres(montadora *p);
void mudacnpj(historicoVendas *ph, int qh, montadora *pc, int qc, char *antigo, char *novo);
void mudanome(historicoVendas *ph, int qh, char *antigo, char *novo);
void recebecarro(montadora *p);
void recebehist(historicoVendas *ph, montadora *pc, loja *pl, int d, int m, int a);
void recebeloja(loja *p);
void reserva(loja *pl, montadora *pc);
int  verificacarro();
int  verificadata(int dia, int mes, int ano);
int  verificahist();
int  verificaloja();
int  verificareserva(loja *p);

//main
main()
{
	setlocale(LC_ALL,"Portuguese");
	loja *ploja=NULL;
	montadora *pcarro=NULL;
	historicoVendas *phist=NULL;
	int op,op2,op3,op4,qloja,qcarro,qhist;
	alocaloja(&ploja,1);
	alocacarro(&pcarro,1);
	alocahist(&phist,1);
	do
	{
		qloja=verificaloja();
		qcarro=verificacarro();
		qhist=verificahist();
		system("cls");
		printf("\n    Estoque da Montadora\n\n[1] Cadastro Concessionária\n[2] Altera dados Concessionária\n[3] Consulta Concessionária\n[4] Cadastro Carro\n[5] Altera dados Carro\n[6] Consulta Carro\n[7] Iniciar Reserva\n[8] Finalizar Reserva\n[9] Histórico de Vendas\n[10] Fechar\n\nDigite sua opção: ");
    	scanf("%i",&op);
    	fflush(stdin);
    	switch(op)
    	{
    		case 1:	if(qloja==5)
    					printf("\nLimite máximo de cadastros atingido");
					else
						recebeloja(ploja);
			 	    printf("\n\n");
    				system("pause");
    				break;
    				
    		case 2: if(qloja==0)
    					printf("\nNenhuma concessionária cadastrada");
    				else
    					alteraloja(ploja,pcarro,phist);
    				printf("\n\n");
    				system("pause");
    				break;
    				
    		case 3:	if(qloja==0)
    					printf("\nNenhuma concessionária cadastrada");
    				else
    					consultaloja(ploja);
    				printf("\n\n");
    				system("pause");
    				break;
    				
    		case 4:	if(qcarro==50)
    					printf("\nLimite máximo de cadastros atingido");
					else
						recebecarro(pcarro);
    				printf("\n\n");
    				system("pause");
    				break;
    				
    		case 5: if(qcarro==0)
    					printf("\nNenhum carro cadastrado");
    				else
    					alteracarro(pcarro);
					printf("\n\n");
    				system("pause");
    				break;
    				
    		case 6: if(qcarro==0)
    					printf("\nNenhum carro cadastrado");
    				else
    				{
    					system("cls");
    					printf("\n[1] Consulta Total\n[2] Consulta por Status\n[3] Consulta por Modelo\n[4] Voltar\n\nDigite sua opção: ");
    					scanf("%i",&op2);
    					fflush(stdin);
    					switch(op2)
    					{
    						case 1: consultatotal(pcarro);
									break;
									
							case 2:	consultastatus(pcarro);
									break;
									
							case 3:	consultamodelo(pcarro);
							case 4:	
									break;
									
							default:printf("\nOpção Inválida");
									break;	
    					}
    				}
    				printf("\n\n");
    				system("pause");
    				break;
    		
    		case 7:	if(qloja==0)
    					printf("\nNenhuma concessionária cadastrada");
    				else if(qcarro==0)
    					printf("\nNenhum carro cadastrado");
    				else
    				{
    					system("cls");
    					printf("\n[1] Reserva carro\n[2] Consulta Carros Livres\n[3] Voltar\n\nDigite sua opção: ");
    					scanf("%i",&op3);
    					fflush(stdin);
    					switch(op3)
    					{
    						case 1: reserva(ploja,pcarro);
									break;
									
							case 2:	mostralivres(pcarro);
							case 3:	
									break;
									
							default:printf("\nOpção Inválida");
									break;
    					}
    		    	}
    				printf("\n\n");
    				system("pause");
    				break;
    				
    		case 8:	if(verificareserva(ploja)==-1)
    					printf("\nNenhuma reserva efetuada");
    				else
    					encerrareserva(ploja,pcarro,phist);
    				printf("\n\n");
    				system("pause");
    				break;
    				
    		case 9:	if(qhist==0)
    					printf("\nNenhuma venda efetuada");
    				else
    				{
    					system("cls");
    					printf("\n[1] Consulta por CNPJ da Concessionária\n[2] Consulta Carros por Modelo\n[3] Voltar\n\nDigite sua opção: ");
    					scanf("%i",&op4);
    					fflush(stdin);
    					switch(op4)
    					{
    						case 1: consultahistcnpj(ploja,phist);
									break;
									
							case 2:	consultahistmodelo(pcarro,phist);
							case 3:	
									break;
									
							default:printf("\nOpção Inválida");
									break;
    					}
    		    	}
    				printf("\n\n");
    				system("pause");
    				break;
    				
    		case 10:printf("\nObrigado por usar o sistema");
    				break;
    				
    		default:printf("\nOpção Inválida\n\n");
    				system("pause");
    				break;
    		
    	}
	} while(op!=10);
	printf("\n\n");
	system("pause");
}

//Definição das funções
void alocacarro(montadora **p, int tam)
{
	if((*p=(montadora *)realloc(*p,tam*sizeof(montadora)))==NULL)
	{
		printf("\nErro de alocação de memória");
		system("pause");
		exit(1);
	}		
}

void alocahist(historicoVendas **p, int tam)
{
	if((*p=(historicoVendas *)realloc(*p,tam*sizeof(historicoVendas)))==NULL)
	{
		printf("\nErro de alocação de memória");
		system("pause");
		exit(1);
	}	
}

void alocaloja(loja **p, int tam)
{
	if((*p=(loja *)realloc(*p,tam*sizeof(loja)))==NULL)
	{
		printf("\nErro de alocação de memória");
		system("pause");
		exit(1);
	}	
}

void alteracarro(montadora *pc)
{
	int qc,qregistro1,qregistro2; 
	char r,op;
	qc=verificacarro();
	system("cls");
	printf("\nDigite o registro do carro: ");
    scanf("%i",&r);
	fflush(stdin);
	qregistro1=buscaregistro(pc,qc,r,'R');
	if(qregistro1!=-1) //se encontrou o registro como reservado
	{
		printf("\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c - %s\n",pc->modelo,pc->cor,pc->valor,pc->status.reserva.sigla,pc->status.reserva.CNPJ);
		printf("\nDeseja alterar o [M]odelo, a [C]or ou o [V]alor?: ");
		scanf("%c",&op);
		fflush(stdin);
		if(op=='m'||op=='M')
    	{
	    	printf("\nNovo Modelo: ");
	    	gets(pc->modelo);
	    	fflush(stdin);
	    	gravacarro(pc,"rb+",qregistro1);
	    	printf("\nModelo atualizado com sucesso");
	    }
	    else if(op=='c'||op=='c')
	    {
	    	printf("\nNova Cor: ");
	    	gets(pc->cor);
	    	fflush(stdin);
	    	gravacarro(pc,"rb+",qregistro1);
	    	printf("\nCor atualizada com sucesso");
	    }
	    else if(op=='v'||op=='V')
	    {
	    	printf("\nNovo Valor: ");
	    	scanf("%f",&pc->valor);
	    	fflush(stdin);
	    	gravacarro(pc,"rb+",qregistro1);
	    	printf("\nValor atualizado com sucesso");
	    }
	    else
	    	printf("\nOpção inválida");
	}
	qregistro2=buscaregistro(pc,qc,r,'L');
	if(qregistro1==-1 && qregistro2!=-1) //se encontrou o registro como livre
	{
		printf("\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c\n",pc->modelo,pc->cor,pc->valor,pc->status.sigla);
		printf("\nDeseja alterar o [M]odelo, a [C]or ou o [V]alor?: ");
		scanf("%c",&op);
		fflush(stdin);
		if(op=='m'||op=='M')
    	{
	    	printf("\nNovo Modelo: ");
	    	gets(pc->modelo);
	    	fflush(stdin);
	    	gravacarro(pc,"rb+",qregistro2);
	    	printf("\nModelo atualizado com sucesso");
	    }
	    else if(op=='c'||op=='c')
	    {
	    	printf("\nNova Cor: ");
	    	gets(pc->cor);
	    	fflush(stdin);
	    	gravacarro(pc,"rb+",qregistro2);
	    	printf("\nCor atualizada com sucesso");
	    }
	    else if(op=='v'||op=='V')
	    {
	    	printf("\nNovo Valor: ");
	    	scanf("%f",&pc->valor);
	    	fflush(stdin);
	    	gravacarro(pc,"rb+",qregistro2);
	    	printf("\nValor atualizado com sucesso");
	    }
	    else
	    	printf("\nOpção inválida");
	}
	else if(qregistro1==-1 && qregistro2==-1) //se não encontrou o registro de nenhuma forma
		printf("\nRegistro não encontrado");
}

void alteraloja(loja *pl, montadora *pc, historicoVendas *ph)
{
	
	int ql,qh,pos,qc; 
	char cnpj[19],antigoc[19],novoc[19],antigon[30],novon[30],op;
	ql=verificaloja();
	qh=verificahist();
	qc=verificacarro();
	system("cls");
	printf("\nDigite o CNPJ da concessionária - formato (xx.xxx.xxx/xxxx-xx): ");
    gets(cnpj);
    fflush(stdin);
    pos=buscaloja(pl, ql, cnpj);
    if (pos==-1)
    	printf("\nCNPJ não encontrado");
    else
    {
    	printf("\nRegistro Loja: %i\nNome: %s\nRua e número: %s\nBairro: %s\nCEP: %s\nCidade: %s\nEstado: %s\nTelefone: %s\nEmail: %s\nCarros vendidos: %i\nCarros reservados: %i",pl->regloja,pl->nome,pl->end.logradouro,pl->end.bairro,pl->end.CEP,pl->end.cidade,pl->end.estado,pl->end.fone,pl->end.email,pl->sold,pl->reserved);
    	if(pl->tabela[0].reservado.sigla=='R')
			printf("\nTabela 0: %c - %i",pl->tabela[0].reservado.sigla,pl->tabela[0].reservado.regcarro);
		if(pl->tabela[1].reservado.sigla=='R')
			printf("\nTabela 1: %c - %i",pl->tabela[1].reservado.sigla,pl->tabela[1].reservado.regcarro);
		if(pl->tabela[2].reservado.sigla=='R')
			printf("\nTabela 2: %c - %i",pl->tabela[2].reservado.sigla,pl->tabela[2].reservado.regcarro);
    	printf("\n\nDeseja alterar o [N]ome, o [C]NPJ ou os [D]ois?: ");
	    scanf("%c",&op);
	    fflush(stdin);
	    if(op=='n'||op=='N'||op=='d'||op=='D')
	    {
	    	strcpy(antigon,pl->nome); //copia o nome da concessionária para string antigon
			printf("\nNovo Nome: ");
	    	gets(novon);
	    	fflush(stdin);
	    	strcpy(pl->nome,novon); //copia a string novon para o nome da concessionária
	    	gravaloja(pl,"rb+",pos);
	    	mudanome(ph,qh,antigon,novon);
	    	printf("\nNome atualizado com sucesso\n");
	    }
	    if(op=='c'||op=='c'||op=='d'||op=='D')
	    {
	    	strcpy(antigoc,pl->CNPJ); //copia o CNPJ da concessionária para string antigoc
			printf("\nNovo CNPJ - formato (xx.xxx.xxx/xxxx-xx): ");
	    	gets(novoc);
	    	fflush(stdin);
	    	strcpy(pl->CNPJ,novoc); //copia a string novoc para o CNPJ da concessionária
	    	gravaloja(pl,"rb+",pos);
	    	mudacnpj(ph,qh,pc,qc,antigoc,novoc);
	    	printf("\nCNPJ atualizado com sucesso");
	    }
	    else if(op!='n'&& op!='N')
			printf("\nOpção inválida");
	}
}

int bissexto(int ano) //verifica se o ano é bissexto
{
	if(ano%4==0) //divisível por quatro
	{
		if(ano%100==0) //divisível por cem
		{
			if(ano%400==0) //divisível por 400
				return 1; //é bissexto
			else
				return 0; //não é bissexto			
		}
		else
			return 1; //é bissexto
	}
	else
		return 0; //não é bissexto
}

int buscalivres(montadora *p, int q)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("carro.bin","rb"))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
		{
			for(i=0;i<q;i++)
			{
				fseek(fptr,i*sizeof(montadora),0);
				fread(p,sizeof(montadora),1,fptr);
				if(p->status.sigla=='L' && strcmp(p->modelo,"vago")!=0) //se é livre e não é vago
				{
					printf("\nRegistro: %i\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c\n",p->regcarro,p->modelo,p->cor,p->valor,p->status.sigla);
					achou=i;
				}
			}
			fclose(fptr);
		}
	return achou;
}

int buscaloja(loja *p, int q, char *pcnpj)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("concessionaria.bin","rb"))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
		{
			for(i=0;i<q;i++)
			{
				fseek(fptr,i*sizeof(loja),0);
				fread(p,sizeof(loja),1,fptr);
				if(strcmp(pcnpj,p->CNPJ)==0) //se o cnpj confere
				{
					achou=i;
					i=q;
				}
			}
			fclose(fptr);
		}
	return achou;	
}

void buscalojahist(historicoVendas *p, int q, char *pcnpj)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("historico.bin","rb"))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
	{
		for(i=0;i<q;i++)
		{
			fseek(fptr,i*sizeof(historicoVendas),0);
			fread(p,sizeof(historicoVendas),1,fptr);
			if(strcmp(pcnpj,p->cnpj)==0) //se o CNPJ confere
			{
				printf("\nRegistro Histórico: %i\nRegistro Carro: %i\nModelo: %s\nCor: %s\nValor %.2f\nRegistro Loja: %i\nNome: %s\nCNPJ: %s\nData de Venda: %i/%i/%i\n",p->reghist,p->regcarro,p->modelo,p->cor,p->valor,p->regloja,p->nome,p->cnpj,p->dataVenda.dia,p->dataVenda.mes,p->dataVenda.ano);
				achou=i;
			}
		}
		fclose(fptr);
		if(achou==-1)
			printf("\nConcessionária sem carros vendidos");
	}	
}

int buscamodelo(montadora *p, int q, char *m)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("carro.bin","rb"))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
		{
			for(i=0;i<q;i++)
			{
				fseek(fptr,i*sizeof(montadora),0);
				fread(p,sizeof(montadora),1,fptr);
				if(strcmp(m,p->modelo)==0 && strcmp(p->modelo,"vago")!=0) //se o modelo confere e não é vago
				{
					
					printf("\nRegistro: %i\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c",p->regcarro,p->modelo,p->cor,p->valor,p->status.sigla);
					if(p->status.sigla=='R')
		    			printf(" - %s\n",p->status.reserva.CNPJ); //se é resevado mostra o CNPJ também
		    		else
		    			printf("\n");
					achou=i;
				}
			}
			fclose(fptr);
		}
	return achou;
}

int buscamodelohist(historicoVendas *p, int q, char *m)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("historico.bin","rb"))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
	{
		for(i=0;i<q;i++)
		{
			fseek(fptr,i*sizeof(historicoVendas),0);
			fread(p,sizeof(historicoVendas),1,fptr);
			if(strcmp(m,p->modelo)==0) //se o modelo confere
			{
				printf("\nRegistro Histórico: %i\nRegistro Carro: %i\nModelo: %s\nCor: %s\nValor %.2f\nRegistro Loja: %i\nNome: %s\nCNPJ: %s\nData de Venda: %i/%i/%i\n",p->reghist,p->regcarro,p->modelo,p->cor,p->valor,p->regloja,p->nome,p->cnpj,p->dataVenda.dia,p->dataVenda.mes,p->dataVenda.ano);
				achou=i;
			}
		}
		fclose(fptr);
	}
	return achou;	
}

int buscaregistro(montadora *p, int q, int reg, char letra)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("carro.bin","rb"))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
		{
			for(i=0;i<q;i++)
			{
				fseek(fptr,i*sizeof(montadora),0);
				fread(p,sizeof(montadora),1,fptr);
				if(p->regcarro==reg && p->status.sigla==letra && strcmp(p->modelo,"vago")!=0) //se o modelo confere, se sigla R ou L bate com o estipulado pelo usuário e não é vago 
				{
					achou=i;
					i=q;
				}
			}
			fclose(fptr);
		}
	return achou;	
}

int buscareservados(montadora *p, int q)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("carro.bin","rb"))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
		{
			for(i=0;i<q;i++)
			{
				fseek(fptr,i*sizeof(montadora),0);
				fread(p,sizeof(montadora),1,fptr);
				if(p->status.reserva.sigla=='R') //se é reservado
				{
					printf("\nRegistro: %i\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c - %s\n",p->regcarro,p->modelo,p->cor,p->valor,p->status.reserva.sigla,p->status.reserva.CNPJ);
					achou=i;
				}
			}
			fclose(fptr);
		}
	return achou;
}

int buscatabela(loja *pl, montadora *pc)
{
	int i;
	for(i=0;i<3;i++)
		if(pl->tabela[i].reservado.regcarro==pc->regcarro) //se o registro da tabela bate com o do carro
			return i; //retorna o número da tabela
}

int buscavago(montadora *p, int q)
{
	FILE *fptr=NULL;
	int i,achou=-1;
	if((fptr=fopen("carro.bin","rb"))==NULL);
	else
	{
	   	for(i=0;i<q;i++)
		{
			fseek(fptr,i*sizeof(montadora),0);
			fread(p,sizeof(montadora),1,fptr);
			if(strcmp(p->modelo,"vago")==0) //se é vago
		    {
		        achou=i;
		        i=q; 
	 		}
		}
		fclose(fptr);
	}
	return achou;
}

void consultahistcnpj(loja *pl, historicoVendas *ph)
{
	int ql,qh,pos; 
	char cnpj[19];
	ql=verificaloja();
	qh=verificahist();
	system("cls");
	printf("\nDigite o CNPJ da concessionária - formato (xx.xxx.xxx/xxxx-xx): ");
    gets(cnpj);
    fflush(stdin);
    pos=buscaloja(pl, ql, cnpj);
    if (pos==-1)
    	printf("\nCNPJ não encontrado");
    else
    	buscalojahist(ph,qh,cnpj);
}

void consultahistmodelo(montadora *pc, historicoVendas *ph)
{
	int pos,qc,qh;
	char modelo[20];
	qc=verificacarro();
	qh=verificahist();
	system("cls");
	printf("\nDigite o modelo procurado: ");
    gets(modelo);
    fflush(stdin);
    pos=buscamodelohist(ph,qh,modelo);
	if (pos==-1)
    	printf("\nModelo não encontrado");
}

void consultaloja(loja *p)
{
	int pos,q;
	char cnpj[19];
	q=verificaloja();
	system("cls");
	printf("\nDigite o CNPJ da concessionária - formato (xx.xxx.xxx/xxxx-xx): ");
    gets(cnpj);
    fflush(stdin);
    pos=buscaloja(p, q, cnpj);
    if (pos==-1)
    	printf("\nCNPJ não encontrado");
    else
    {
    	system("cls");
		printf("\nNome: %s\nCarros vendidos: %i\nCarros reservados: %i",p->nome,p->sold,p->reserved);
		if(p->tabela[0].reservado.sigla=='R')
			printf("\nTabela 0: %c - %i",p->tabela[0].reservado.sigla,p->tabela[0].reservado.regcarro);
		if(p->tabela[1].reservado.sigla=='R')
			printf("\nTabela 1: %c - %i",p->tabela[1].reservado.sigla,p->tabela[1].reservado.regcarro);
		if(p->tabela[2].reservado.sigla=='R')
			printf("\nTabela 2: %c - %i",p->tabela[2].reservado.sigla,p->tabela[2].reservado.regcarro);
    } 
}

void consultamodelo(montadora *p)
{
	int pos,q;
	char modelo[20];
	q=verificacarro();
	system("cls");
	printf("\nDigite o modelo procurado: ");
    gets(modelo);
    fflush(stdin);
    pos=buscamodelo(p,q,modelo);
	if (pos==-1)
    	printf("\nModelo não encontrado");	
}

void consultastatus(montadora *p)
{
	char op,q;
	q=verificacarro();
	int qlivres=0,qreservados=0;
	system("cls");	
	printf("\nDigite o status dos carros procurados, [L]ivre ou [R]eservado: ");
	scanf("%c",&op);
	fflush(stdin);
	if(op=='l' || op=='L')
		qlivres=buscalivres(p,q);
	else if(op=='r' || op=='R')
		qreservados=buscareservados(p,q);
	else
		printf("\nOpção inválida");
	if(qlivres==-1)
		printf("\nCarros livres não encontrados");
	if(qreservados==-1)
		printf("\nCarros reservados não encontrados");	
}

void consultatotal(montadora *p)
{
	int i,q;
	FILE *fptr=NULL;
	q=verificacarro();
	system("cls");
	if((fptr=fopen("carro.bin","rb"))==NULL)
	  printf("\nErro ao abrir o arquivo");
	else
	{
	  	for(i=0;i<q;i++)
	  		{
			  	fseek(fptr,i*sizeof(montadora),0);
			  	fread(p,sizeof(montadora),1,fptr);
			  	if(strcmp(p->modelo,"vago")!=0) //se não é vago
			  	{
				  	printf("\nRegistro: %i\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c",p->regcarro,p->modelo,p->cor,p->valor,p->status.sigla);
		    		if(p->status.sigla=='R')
		    			printf(" - %s\n",p->status.reserva.CNPJ); //se for reservado mostra o CNPJ
		    		else
		    			printf("\n");
	         	}
			}
	    fclose(fptr);
	}	
}

void encerrareserva(loja *pl, montadora *pc, historicoVendas *ph)
{
	int pos,r,qregistro1,qregistro2,d,m,a,ql,qc;
	char op;
	ql=verificaloja();
	qc=verificacarro();
	system("cls");
	printf("\nDigite o registro do carro a ser comprado ou liberado: ");
    scanf("%i",&r);
	fflush(stdin);
	qregistro1=buscaregistro(pc,qc,r,'R');
	if(qregistro1!=-1)
	{
		printf("\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c - %s\n",pc->modelo,pc->cor,pc->valor,pc->status.reserva.sigla,pc->status.reserva.CNPJ);
		printf("\nO carro será [C]omprado ou [L]iberado?: ");
    	scanf("%c",&op);
		fflush(stdin);
		if(op=='c'||op=='c')
		{	
			printf("\nDia da compra: ");
			scanf("%i",&d);
			fflush(stdin);
			printf("\nMês da compra: ");
			scanf("%i",&m);
			fflush(stdin);
			printf("\nAno da compra: ");
			scanf("%i",&a);
			fflush(stdin);
			if(verificadata(d, m, a)==-1)
				printf("\nData inválida");
			else
			{
				pos=buscaloja(pl, ql, pc->status.reserva.CNPJ);
				pl->tabela[buscatabela(pl,pc)].sigla='L';
				(pl->reserved)--;
				(pl->sold)++;
				gravaloja(pl,"rb+",pos);
				recebehist(ph,pc,pl,d,m,a);
				strcpy(pc->modelo,"vago");
				strcpy(pc->cor,"vago");
				pc->valor=0;
				pc->status.sigla='L';
				gravacarro(pc,"rb+",qregistro1);
				printf("\nCarro comprado com sucesso");
			}
		}
		else if(op=='l'||op=='L')
		{
			pos = buscaloja (pl, ql, pc->status.reserva.CNPJ);
			pl->tabela[buscatabela(pl,pc)].sigla='L';
			(pl->reserved)--;
			gravaloja(pl,"rb+",pos);
			pc->status.sigla='L';
			gravacarro(pc,"rb+",qregistro1);
			printf("\nCarro liberado com sucesso");
			
		}
		else
			printf("\nOpção inválida");
	}
	qregistro2=buscaregistro(pc,qc,r,'L');
	if(qregistro1==-1 && qregistro2!=-1)
	{
		printf("\nCarro não reservado");
		printf("\nModelo: %s\nCor: %s\nValor R$: %.2f\nStatus: %c\n",pc->modelo,pc->cor,pc->valor,pc->status.sigla);
		
	}
	else if(qregistro1==-1 && qregistro2==-1)
		printf("\nRegistro não encontrado");
}

void gravacarro(montadora *p, char *abertura, int i)
{
	FILE *fptr=NULL;
	if((fptr=fopen("carro.bin",abertura))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
	{
		if(strcmp(abertura,"rb+")==0) //se a abertura for com o tipo "rb+"
			fseek(fptr,i*sizeof(montadora),0);
		fwrite(p,sizeof(montadora),1,fptr);
	}
	fclose(fptr);
}

void gravahist(historicoVendas *p, char *abertura, int i)
{
	FILE *fptr=NULL;
	if((fptr=fopen("historico.bin",abertura))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
	{
		if(strcmp(abertura,"rb+")==0) //se a abertura for com o tipo "rb+"
			fseek(fptr,i*sizeof(historicoVendas),0);
		fwrite(p,sizeof(historicoVendas),1,fptr);
	}
	fclose(fptr);
}

void gravaloja(loja *p, char *abertura, int i)
{
	FILE *fptr=NULL;
	if((fptr=fopen("concessionaria.bin",abertura))==NULL)
		printf("\nErro ao abrir o arquivo");
	else
	{
		if(strcmp(abertura,"rb+")==0) //se a abertura for com o tipo "rb+"
			fseek(fptr,i*sizeof(loja),0);
		fwrite(p,sizeof(loja),1,fptr);
    }
	fclose(fptr);
}

void mostralivres(montadora *p)
{
	int qlivres,q;
	q=verificacarro();
	system("cls");
	qlivres = buscalivres(p,q);
	if(qlivres==-1)
		printf("\nCarros livres não encontrados");
}

void mudacnpj(historicoVendas *ph, int qh,montadora *pc, int qc, char *antigo, char *novo)
{
	
	FILE *fptrh=NULL, *fptrc=NULL;
	int i;
	if(qh!=0) //se existe o histórico
	{
		if((fptrh=fopen("historico.bin","rb"))==NULL)
			printf("\nErro ao abrir o arquivo\n");
		else
		{
			for(i=0;i<qh;i++)
			{
				fseek(fptrh,i*sizeof(historicoVendas),0);
				fread(ph,sizeof(historicoVendas),1,fptrh);
				if(strcmp(antigo,ph->cnpj)==0) //se o CNPJ antigo confere
				{
					strcpy(ph->cnpj,novo); //copia o novo CNPJ
					gravahist(ph,"rb+",i);
				}
			}
			fclose(fptrh);
		}
	}
	if(qc!=0) //se existem carros
	{
		if((fptrc=fopen("carro.bin","rb"))==NULL)
			printf("\nErro ao abrir o arquivo\n");
		else
		{
			for(i=0;i<qc;i++)
			{
				fseek(fptrc,i*sizeof(montadora),0);
				fread(pc,sizeof(montadora),1,fptrc);
				if(strcmp(antigo,pc->status.reserva.CNPJ)==0) //se o CNPJ antigo confere
				{
					strcpy(pc->status.reserva.CNPJ,novo); //copia o novo CNPJ
					gravacarro(pc,"rb+",i);
				}
			}
			fclose(fptrc);
		}
	}
}

void mudanome(historicoVendas *ph, int qh,char *antigo, char *novo)
{
	FILE *fptrh=NULL;
	int i;
	if(qh!=0)
	{
		if((fptrh=fopen("historico.bin","rb"))==NULL)
			printf("\nErro ao abrir o arquivo");
		else
		{
			for(i=0;i<qh;i++)
			{
				fseek(fptrh,i*sizeof(historicoVendas),0);
				fread(ph,sizeof(historicoVendas),1,fptrh);
				if(strcmp(antigo,ph->nome)==0) //se o nome antigo confere
				{
					strcpy(ph->nome,novo); //copia o novo nome
					gravahist(ph,"rb+",i);
				}
			}
			fclose(fptrh);
		}
	}	
}

void recebecarro(montadora *p)
{
	int ind,q;
	q=verificacarro();
	system("cls");
	ind=buscavago(p,q);
	if(ind!=-1) //se tem carro vago
  		q=ind; //pega o registro do vago
	p->regcarro=q+1;
	printf("\nRegistro do carro: %i\n",p->regcarro);
	printf("\nModelo: ");
	gets(p->modelo);
	fflush(stdin);
	printf("\nCor: ");
	gets(p->cor);
	fflush(stdin);
	printf("\nValor R$: ");
	scanf("%f",&(p->valor));
	fflush(stdin);
	p->status.sigla='L';
	if(ind==-1) //se não tem vago, adiciona
  		gravacarro(p,"ab",1);
	else //se tem, atualiza em cima
  		gravacarro(p,"rb+",ind);
}

void recebehist(historicoVendas *ph,montadora *pc, loja *pl, int d, int m, int a)
{
	int qh;
	qh=verificahist();
	ph->reghist=qh+1;
	ph->regcarro=pc->regcarro;
	strcpy(ph->modelo,pc->modelo);
	strcpy(ph->cor,pc->cor);
	ph->valor=pc->valor;
	ph->regloja=pl->regloja;
	strcpy(ph->nome,pl->nome);
	strcpy(ph->cnpj,pl->CNPJ);
	ph->dataVenda.dia=d;
	ph->dataVenda.mes=m;
	ph->dataVenda.ano=a;
	gravahist(ph,"ab",1);
}

void recebeloja(loja *p)
{
	int q;
	q=verificaloja();
	system("cls");
	p->regloja=q+1;
	printf("\nRegistro da loja: %i\n",p->regloja);
	printf("\nNome: ");
	gets(p->nome);
	fflush(stdin);
	printf("\nCNPJ - formato (xx.xxx.xxx/xxxx-xx): ");
	gets(p->CNPJ);
	fflush(stdin);
	printf("\nRua e número: ");
	gets(p->end.logradouro);
	fflush(stdin);
	printf("\nBairro: ");
	gets(p->end.bairro);
	fflush(stdin);
	printf("\nCEP - formato (xxxxx-xx): ");
	gets(p->end.CEP);
	fflush(stdin);
	printf("\nCidade: ");
	gets(p->end.cidade);
	fflush(stdin);
	printf("\nEstado (sigla): ");
	gets(p->end.estado);
	fflush(stdin);
	printf("\nTelefone - formato [(xx) xxxxx-xxxx]: ");
	gets(p->end.fone);
	fflush(stdin);
	printf("\nEmail: ");
	gets(p->end.email);
	fflush(stdin);
	p->sold=0;
	p->reserved=0;
	p->tabela[0].sigla='L';
	p->tabela[1].sigla='L';
	p->tabela[2].sigla='L';
	gravaloja(p,"ab",1);
}

void reserva(loja *pl, montadora *pc)
{
	int pos,r,qregistro,i,ql,qc;
	char cnpj[19];
	ql=verificaloja();
	qc=verificacarro();
	system("cls");
	printf("\nDigite o CNPJ da concessionária - formato (xx.xxx.xxx/xxxx-xx): ");
    gets(cnpj);
    fflush(stdin);
    pos=buscaloja(pl, ql, cnpj);
    if (pos==-1)
    	printf("\nCNPJ não encontrado");
    else
    {
    	if(pl->reserved==3)
    		printf("\nMáxima de reservas atingido");
    	else
    	{
    		printf("\nDigite o registro do carro a ser reservado: ");
    		scanf("%i",&r);
			fflush(stdin);
			qregistro=buscaregistro(pc,qc,r,'L');
			if(qregistro==-1)
				printf("\nRegistro não encontrado/carro já reservado");
			else
			{
				pc->status.reserva.sigla='R';
				strcpy(pc->status.reserva.CNPJ,cnpj);
				(pl->reserved)++;
				for(i=0;i<3;i++)
					if(pl->tabela[i].sigla=='L') //verifica qual tabela está livre
					{
						pl->tabela[i].reservado.sigla='R';
						pl->tabela[i].reservado.regcarro=r;
						i=3;
				    }
				gravaloja(pl,"rb+",pos);
				gravacarro(pc,"rb+",qregistro);
    			printf("\nReserva realizada com sucesso");
    		}
		}
	}
}

int verificacarro() //verifica quantidade de carros
{
	FILE *fptr=NULL;
	long int cont=0;
	if((fptr=fopen("carro.bin","rb"))==NULL)
		return cont;
	else
		{
		  	fseek(fptr,0,2);
		  	cont=ftell(fptr)/sizeof(montadora);
		  	fclose(fptr);
		  	return cont;
    	}
}

int verificadata(int dia, int mes, int ano)
{
	if (mes>=1 && mes<=12) //se mês está entre 1 e 12
	{
		if((mes==4 || mes==6 || mes==9 || mes==11) && (dia>=1 && dia<=30)) //se for um dos meses que tem trinta dias e o dia está entre 1 e 30
			return 0; //válido
		else if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia>=1 && dia<=31)) //se for um dos meses que tem trinta e um dias e o dia está entre 1 e 31
			return 0; //válido
		else if (mes==2 && bissexto(ano)==1 && dia>=1 && dia<=29) //se for em fevereiro, ano bissexto e dia entre 1 e 29
			return 0; //válido
		else if (mes==2 && bissexto(ano)==0 && dia>=1 && dia<=28) //se for em fevereiro, ano não bissexto e dia entre 1 e 28
			return 0; //válido
		else
			return -1; //inválido
	}
	else
		return -1; //inválido
}

int verificahist() //verifica quantidade de registros do histórico
{
	FILE *fptr=NULL;
	long int cont=0;
	if((fptr=fopen("historico.bin","rb"))==NULL)
		return cont;
	else
		{
		  	fseek(fptr,0,2);
		  	cont=ftell(fptr)/sizeof(historicoVendas);
		  	fclose(fptr);
		  	return cont;
    	}
}

int verificaloja() //verifica quantidade de concessionárias
{
	FILE *fptr=NULL;
	long int cont=0;
	if((fptr=fopen("concessionaria.bin","rb"))==NULL)
		return cont;
	else
		{
		  	fseek(fptr,0,2);
		  	cont=ftell(fptr)/sizeof(loja);
		  	fclose(fptr);
		  	return cont;
    	}
}

int verificareserva(loja *p) //verifica se há alguma reserva em alguma concessionária
{
	FILE *fptr=NULL;
	int i,achou=-1,q;
	q=verificacarro();
	if((fptr=fopen("concessionaria.bin","rb"))==NULL);
	else
		{
			for(i=0;i<q;i++)
			{
				fseek(fptr,i*sizeof(loja),0);
				fread(p,sizeof(loja),1,fptr);
				if(p->reserved!=0)
				{
					achou=i;
					i=q;
				}
			}
			fclose(fptr);
		}
	return achou;	
}
