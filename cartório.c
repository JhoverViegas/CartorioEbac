#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de esa�o de mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respos�vel por cuidar da string

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema.
{  //inic�o cria��o da vari�vel/string
	char arquivo[40]; 
	char cpf[40]; 
	char nome [40]; 
	char sobrenome[40]; 
	char cargo[40]; 
	//final cria��o da vari�vel/string
	printf("Digite o CPF a ser cadastrado:"); //coletando inform��o do usu�rio.
	scanf ("%s",cpf); // %s  refere-se a string/Salva dentro de uma string.
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores da string.
	
	FILE *file; //cria o arquivo
	file=fopen(arquivo,"w"); //cria o arquivo e o w signifa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualizar a informa��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	file = fopen(arquivo,"a");
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" atualizar a informa��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); // "a" atualizar a informa��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system ("pause"); //
	
	}
int consulta ()
{

	setlocale(LC_ALL, "portuguese"); // definindo liguagem.
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");	
	}
		fclose(file);
		system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese"); // definindo liguagem.
	char cpf[40];
		
		printf("Digite o CPF do usu�rio a ser deletado:");
		scanf("%s,",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file== NULL)
		{
			printf("O usu�rio foi deletado com sucesso!. \n");
			system("pause");
		}
}

int main()
{
	


	
	int opcao=0; // Definindo vari�veis.
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t Cart�rio da EBAC \n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
		system ("cls");
		for(laco=1;laco=1;)
	
		{
	
	
	    	setlocale(LC_ALL, "portuguese"); // Definindo linguagem.
			system("cls");
		
			printf("\t Cart�rio da EBAC \n\n"); //inicio do menu.
			printf("Escolha a op��o desejada do menu: \n\n");
			printf ("\t1 - Registrar nome\n");
			printf ("\t2 - Consultar nome\n");
			printf ("\t3 - Deletar nome\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf ("Op��o:"); // fim do menu.
		
			scanf("%d",&opcao); //armazenano a escolha do usu�rio.
		
			system("cls"); // responsavel por limpar a tela
		
				switch(opcao) //inicio da sele��o de menu
			{
				case 1:
				registro(); //chamada da fun��o
				break;
				
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;     
			
				case 4:
				printf("Obrigado por utilizar o sistema!");	
				return 0;
				break;
			
				default:
				printf("Essa opcao n�o est� dispon�vel!\n");
				system("pause");
				break;
			} //fim da sele��o
		}  
	}
	else
		printf("Senha incorreta!");
}
