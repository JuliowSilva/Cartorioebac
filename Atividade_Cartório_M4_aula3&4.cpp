#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro()// função responsável por cadastrar usuários no sistema
{
	//início criação de variaveis (String)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis (String)
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usário
	scanf("%s", cpf); // salvar o valor da variavel (Variavel = string)
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string 

	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" singnifica atualizar o arquivo
	fprintf(file,","); // salvar a informação "," no arquivo (Serve para separar as variaveis com ",")
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", nome); // salvar o valor da variavel (Variavel = string)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,nome); // salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); // salvar o valor da variavel (Variavel = string)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,sobrenome); // Salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,","); // salvar a informação "," no arquivo (Serve para separar as variaveis com ",")
	fclose(file); // fechar o arquivo
	
	printf("Dite o cargo a ser cadastrado: "); // coletando informação do usuario 
	scanf("%s", cargo); // salvar o valor da variavel (Variavel = string)
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,cargo); // Salvar o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,","); // salvar a informação "," no arquivo (Serve para separar as variaveis com ",")
	fclose(file); // fechar o arquivo
	
	 system("pause"); // Pausar a aplicação para o usuario ter tempo de avaliar como seguir
}

int consulta() // função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");// definindo linguagem
	
	char cpf [40]; // definindo variavel
	char conteudo[200]; // definindo variavel
	
	printf("Digite o CPF a ser consultado: "); // coletando informação do usuario
	scanf("%s",cpf); //salvar o valor da variavel (Variavel = string) 
	
	FILE *file; // criando o arquivo
	file = fopen(cpf,"r"); // abre o arquivo e o "r" significa "read" ou "ler o arquivo"
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n"); // informação para o usuario
	}
	
	while(fgets(conteudo,200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("Usuário não encontrado. \n");
		system("pause");
		fclose(file);
	}
		
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso. \n");
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
	int opcao=0; // definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system ("cls"); // responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");// definindo linguagem
	
		printf(">>>>>> Cartório da EBAC <<<<<<\n\n");// inicio do menu
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");// final do menu
		// remover e incluir novamente depois > printf("Esse Software é de livre uso dos alunos\n");
	
		scanf("%d", &opcao);// armazenando a escolha do usuario
	
		system("cls"); // cls serve para limpar a tela
		
		switch(opcao) // inicio da selecção do menu
		{
			case 1: // atentar de sempre usar o dois pontos e o break no final
			registro(); // chamada de funções
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
					
			default:
			printf("Essa opção não esta disponivel\n");
			system("pause"); 
			break;
		
		}
	}
}
