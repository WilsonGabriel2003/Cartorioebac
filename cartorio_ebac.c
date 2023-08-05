#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings


int registro()   //Função responsavel por cadastrar os usuarios
{
	//inicio crriação de variaveis/strings
	char arquivo[40];                                      
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int menu = 0;
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" é para escrever
	fprintf(file,"CPF: ");
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); //editar o arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	
	system("pause");
	
}


int consulta()       //Função responsavel por consultar os usuarios
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)   //caso um cpf não existente seja digitado
	{
		printf("Usuário não localizado!\n");
	}
	else
		printf("Essas são as informações do usuário:\n\n");   //quando um usuario é detectado
	

	while(fgets(conteudo, 200, file) != NULL)     //usar a variavel conteudo
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}


int deletar()      //Função responsavel por deletar os usuarios
{
	char cpf[40];
	int del = 0;
	
	
	printf("Digite o cpf do usuário que deseja deletar: ");
	scanf("%s", cpf);
	system("cls");
	
	FILE *file;                //procurar o usuario no sistema
	file = fopen(cpf,"r");
	fclose(file);
		 
	if(file == NULL)
	{  
	  	printf("Usuário não encontrado no sistema!\n");	 //para quando não achar o usuario
	} 
	
	if(file != NULL)                                     //quando o usuário estiver no sistema
	{
		printf("Deseja mesmo deletar este usuário?\n\n");
		printf("Pressione '1' para sim.\t\tPressione '2' para não\n\n");
		printf("Opção: ");
		scanf("%d", &del);
		system("cls");
		
		switch(del)                                    //confirmação do usuário
		{
			case 1:
			remove(cpf);
			printf("Usuário deletado com sucesso\n");
			break;
			
			case 2:
			printf("O usuário continua no banco de dados\n");
			break;	
			
			default:
				printf("Opção inválida.");
		}
 	}
	
	system("pause");

}

int main()        //função com o menu
{	

	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Título
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Esse Software é de livre uso dos alunos.\n\n");
		printf("Selecione um dos menus acima: "); //fim do menu
		
	
		scanf("%d", &opcao);
	
		system("cls");      //Serve para deletar os nomes
		
		switch(opcao)       //chamadas de funções
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
		
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
		}
	}
}
