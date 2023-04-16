#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de Alocação de espaço em memória
#include <locale.h> //bibliotecas de alocações de texto por região
#include <string.h> //bibliotecas resposnsáveis cuidar das stringers

int registro() //função responsável por cadastrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	// inicio criação de variáveis
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o cpf a ser cadastrado: "); //coletando informação do usuário
    scanf("%s",cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsável por copiar valores da string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo novo e o "w" função escrever
    fprintf(file,cpf); // salvo o valor da váriavel
    fclose(file); // fecho o arquivo
    
    file = fopen(arquivo,"a"); //abrindo o arquivo e o "a" função atualizando
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	printf ("Digite o Cpf a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf("Não foi possível localizar abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nEssas são as informações do usuário: ");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
	    fclose(file);
	    system("pause");

}

int deletar() // função deletar registro criado no banco de dados
{  
	char cpf[40]; //função responsável por criar a variável "cpf"
	
	printf("Digite o cpf do usuário a ser deletado: "); //local onde o usuário ira digitar o cpf a ser armazenado para ser deletado
	scanf("%s",cpf); // função de armazenar na variável "cpf" que será deletado pelo usuário
	
	
	FILE *file; //procurando na biblioteca um arquivo
	file = fopen (cpf, "r"); //abrindo arquivo e o "r" tem função leitura
	fclose(file); //fechar arquivo
	
	if(file == NULL) //se os dados digitados forem nulo ou seja não existirem
    {
    	printf("\nO usuário não se encontra no sistema!\n\n"); //informe ao usuário que dado não se encontra no sistema
    	system("pause"); //função responsável por manter ultima mensagem da tela até que se pressione uma tecla 
	 } 
	 else //se os dados forem encontrados em busca no arquivo
	 {
	 	remove(cpf); //deletará o arquivo encontrado igual na variável/string
	 	printf("\nUsuário deletado com sucesso!\n\n"); //informará ao usuário que foi realizado o comando de deletar
	 	system("pause"); ////função responsável por manter ultima mensagem da tela até que se pressione uma tecla
	 }

}

int main() //função menu 
{
	int opcao=0; //Definindo as variáveis
	int laco=1; //função repetição
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); //responsável por deletar a tela
	 
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cartório do EBAC ###\n\n"); // Inicio do menu
	   printf("Escolha a opção desejada no menu: \n\n"); //usuário verá mensagem de escolha de ação
	   printf("\t1 - Registrar nomes\n"); //usuário pode escolher por cadastrar um nome ao banco de nomes
	   printf("\t2 - Consultar nomes\n"); //usuário pode escolher ver os nomes cadastrados e ver os dados coletados sobre cada um deles
 	   printf("\t3 - Deletar Nomes\n\n"); //usuário pode escolher deletar algum nome da lista do banco de dados
	   printf("Qual opção você deseja: "); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	    system("cls"); //responsável por deletar a tela
	
	    switch(opcao) //inicio da seleção de menus
	   
	    {
	    	
		   case 1: 
	       registro(); //chamada de funções
		   break;
		
		   case 2:
		   consulta();
	       break;
	    
	       case 3:
	       deletar();
		   break;
		   
		
		   default:
		   printf("\n Está opção não está disponível!\n");
		   system("pause");
		   break;
		
	   
         } // Fim da seleção
    }
}
		
	
