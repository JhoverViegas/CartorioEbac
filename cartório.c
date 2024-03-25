#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de esaço de memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca resposável por cuidar da string

int registro() // função responsavel por cadastrar os usuários no sistema.
{  //inicío criação da variável/string
	char arquivo[40]; 
	char cpf[40]; 
	char nome [40]; 
	char sobrenome[40]; 
	char cargo[40]; 
	//final criação da variável/string
	printf("Digite o CPF a ser cadastrado:"); //coletando informção do usuário.
	scanf ("%s",cpf); // %s  refere-se a string/Salva dentro de uma string.
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores da string.
	
	FILE *file; //cria o arquivo
	file=fopen(arquivo,"w"); //cria o arquivo e o w signifa escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualizar a informação
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	file = fopen(arquivo,"a");
	fprintf(file,nome); 
	fclose(file);
	
	file = fopen(arquivo, "a"); // "a" atualizar a informação
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); // "a" atualizar a informação
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
		
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
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
		
		printf("Digite o CPF do usuário a ser deletado:");
		scanf("%s,",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file== NULL)
		{
			printf("O usuário foi deletado com sucesso!. \n");
			system("pause");
		}
}

int main()
{
	


	
	int opcao=0; // Definindo variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	
	{
	
	
		setlocale(LC_ALL, "portuguese"); // Definindo linguagem.
		system("cls");
		
		printf("\t Cartório da EBAC \n\n"); //inicio do menu.
		printf("Escolha a opção desejada do menu: \n\n");
		printf ("\t1 - Registrar nome\n");
		printf ("\t2 - Consultar nome\n");
		printf ("\t3 - Deletar nome\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf ("Opção:"); // fim do menu.
		
		scanf("%d",&opcao); //armazenano a escolha do usuário.
		
		system("cls"); // responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção de menu
		{
			case 1:
			registro(); //chamada da função
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
			printf("Essa opcao não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
	}  
	
}
