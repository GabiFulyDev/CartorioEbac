#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de Aloca��o de espa�o em mem�ria
#include <locale.h> //bibliotecas de aloca��es de texto por regi�o
#include <string.h> //bibliotecas resposns�veis cuidar das stringers

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	// inicio cria��o de vari�veis
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    
    printf("Digite o cpf a ser cadastrado: "); //coletando informa��o do usu�rio
    scanf("%s",cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //respons�vel por copiar valores da string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo novo e o "w" fun��o escrever
    fprintf(file,cpf); // salvo o valor da v�riavel
    fclose(file); // fecho o arquivo
    
    file = fopen(arquivo,"a"); //abrindo o arquivo e o "a" fun��o atualizando
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
		printf("N�o foi poss�vel localizar abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
	    fclose(file);
	    system("pause");

}

int deletar() // fun��o deletar registro criado no banco de dados
{  
	char cpf[40]; //fun��o respons�vel por criar a vari�vel "cpf"
	
	printf("Digite o cpf do usu�rio a ser deletado: "); //local onde o usu�rio ira digitar o cpf a ser armazenado para ser deletado
	scanf("%s",cpf); // fun��o de armazenar na vari�vel "cpf" que ser� deletado pelo usu�rio
	
	
	FILE *file; //procurando na biblioteca um arquivo
	file = fopen (cpf, "r"); //abrindo arquivo e o "r" tem fun��o leitura
	fclose(file); //fechar arquivo
	
	if(file == NULL) //se os dados digitados forem nulo ou seja n�o existirem
    {
    	printf("\nO usu�rio n�o se encontra no sistema!\n\n"); //informe ao usu�rio que dado n�o se encontra no sistema
    	system("pause"); //fun��o respons�vel por manter ultima mensagem da tela at� que se pressione uma tecla 
	 } 
	 else //se os dados forem encontrados em busca no arquivo
	 {
	 	remove(cpf); //deletar� o arquivo encontrado igual na vari�vel/string
	 	printf("\nUsu�rio deletado com sucesso!\n\n"); //informar� ao usu�rio que foi realizado o comando de deletar
	 	system("pause"); ////fun��o respons�vel por manter ultima mensagem da tela at� que se pressione uma tecla
	 }

}

int main() //fun��o menu 
{
	int opcao=0; //Definindo as vari�veis
	int laco=1; //fun��o repeti��o
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); //respons�vel por deletar a tela
	 
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	   printf("### Cart�rio do EBAC ###\n\n"); // Inicio do menu
	   printf("Escolha a op��o desejada no menu: \n\n"); //usu�rio ver� mensagem de escolha de a��o
	   printf("\t1 - Registrar nomes\n"); //usu�rio pode escolher por cadastrar um nome ao banco de nomes
	   printf("\t2 - Consultar nomes\n"); //usu�rio pode escolher ver os nomes cadastrados e ver os dados coletados sobre cada um deles
 	   printf("\t3 - Deletar Nomes\n\n"); //usu�rio pode escolher deletar algum nome da lista do banco de dados
	   printf("Qual op��o voc� deseja: "); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	    system("cls"); //respons�vel por deletar a tela
	
	    switch(opcao) //inicio da sele��o de menus
	   
	    {
	    	
		   case 1: 
	       registro(); //chamada de fun��es
		   break;
		
		   case 2:
		   consulta();
	       break;
	    
	       case 3:
	       deletar();
		   break;
		   
		
		   default:
		   printf("\n Est� op��o n�o est� dispon�vel!\n");
		   system("pause");
		   break;
		
	   
         } // Fim da sele��o
    }
}
		
	
