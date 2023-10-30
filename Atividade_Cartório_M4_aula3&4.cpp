#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro()// fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio cria��o de variaveis (String)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis (String)
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do us�rio
	scanf("%s", cpf); // salvar o valor da variavel (Variavel = string)
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string 

	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" singnifica atualizar o arquivo
	fprintf(file,","); // salvar a informa��o "," no arquivo (Serve para separar as variaveis com ",")
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", nome); // salvar o valor da variavel (Variavel = string)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,nome); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); // salvar o valor da variavel (Variavel = string)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,sobrenome); // Salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,","); // salvar a informa��o "," no arquivo (Serve para separar as variaveis com ",")
	fclose(file); // fechar o arquivo
	
	printf("Dite o cargo a ser cadastrado: "); // coletando informa��o do usuario 
	scanf("%s", cargo); // salvar o valor da variavel (Variavel = string)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,cargo); // Salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,","); // salvar a informa��o "," no arquivo (Serve para separar as variaveis com ",")
	fclose(file); // fechar o arquivo
	
	 system("pause"); // Pausar a aplica��o para o usuario ter tempo de avaliar como seguir
}

int consulta() // fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");// definindo linguagem
	
	char cpf [40]; // definindo variavel
	char conteudo[200]; // definindo variavel
	
	printf("Digite o CPF a ser consultado: "); // coletando informa��o do usuario
	scanf("%s",cpf); //salvar o valor da variavel (Variavel = string) 
	
	FILE *file; // criando o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa "read" ou "ler o arquivo"
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado.\n"); // informa��o para o usuario
	}
	
	while(fgets(conteudo,200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado. \n");
		system("pause");
		fclose(file);
	}
		
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso. \n");
		system("pause");	
	}
	
	fclose(file);
}


int teste()
{
	printf("Funcionou");
	system("pause");
}


int main ()
{
	int opcao=0; // definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system ("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");// definindo linguagem
	
		printf(">>>>>> Cart�rio da EBAC <<<<<<\n\n");// inicio do menu
		printf("escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");// final do menu
		// remover e incluir novamente depois > printf("Esse Software � de livre uso dos alunos\n");
	
		scanf("%d", &opcao);// armazenando a escolha do usuario
	
		system("cls"); // cls serve para limpar a tela
		
		switch(opcao) // inicio da selec��o do menu
		{
			case 1: // atentar de sempre usar o dois pontos e o break no final
			registro(); // chamada de fun��es
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
					
			default:
			printf("Essa op��o n�o esta disponivel\n");
			system("pause"); 
			break;
		
		}
	}
}
