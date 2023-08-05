#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings


int registro()   //Fun��o responsavel por cadastrar os usuarios
{
	//inicio crria��o de variaveis/strings
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
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" � para escrever
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


int consulta()       //Fun��o responsavel por consultar os usuarios
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)   //caso um cpf n�o existente seja digitado
	{
		printf("Usu�rio n�o localizado!\n");
	}
	else
		printf("Essas s�o as informa��es do usu�rio:\n\n");   //quando um usuario � detectado
	

	while(fgets(conteudo, 200, file) != NULL)     //usar a variavel conteudo
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}


int deletar()      //Fun��o responsavel por deletar os usuarios
{
	char cpf[40];
	int del = 0;
	
	
	printf("Digite o cpf do usu�rio que deseja deletar: ");
	scanf("%s", cpf);
	system("cls");
	
	FILE *file;                //procurar o usuario no sistema
	file = fopen(cpf,"r");
	fclose(file);
		 
	if(file == NULL)
	{  
	  	printf("Usu�rio n�o encontrado no sistema!\n");	 //para quando n�o achar o usuario
	} 
	
	if(file != NULL)                                     //quando o usu�rio estiver no sistema
	{
		printf("Deseja mesmo deletar este usu�rio?\n\n");
		printf("Pressione '1' para sim.\t\tPressione '2' para n�o\n\n");
		printf("Op��o: ");
		scanf("%d", &del);
		system("cls");
		
		switch(del)                                    //confirma��o do usu�rio
		{
			case 1:
			remove(cpf);
			printf("Usu�rio deletado com sucesso\n");
			break;
			
			case 2:
			printf("O usu�rio continua no banco de dados\n");
			break;	
			
			default:
				printf("Op��o inv�lida.");
		}
 	}
	
	system("pause");

}

int main()        //fun��o com o menu
{	

	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //T�tulo
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Esse Software � de livre uso dos alunos.\n\n");
		printf("Selecione um dos menus acima: "); //fim do menu
		
	
		scanf("%d", &opcao);
	
		system("cls");      //Serve para deletar os nomes
		
		switch(opcao)       //chamadas de fun��es
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
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
		}
	}
}
