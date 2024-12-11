#include  <stdio.h> //biblioteca  de comunicação com  o usuario
#include <stdlib.h> //biblioteca para alocação de espaços de memoria 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings



int registro()
{
	//inicio criacao de variaveis/string
	char arquivo[40];
    char cpf[40];  
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final criacao de variaveis/string
    
    printf("Digite o CPF a ser cadastrado:"); //coletando info do usuario
    scanf("%s", cpf); // %s para armazenar dentro de uma string  
    
    strcpy(arquivo, cpf); // Responsável por copiar valores das strings no caso cpf para arquivo.
    FILE *file; // cria o arquivo
    
    
	file = fopen(arquivo, "w"); // cria o arquivo. "W" vem de write que vai escrever no arquivo.
	fprintf(file,"\nCPF:");
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	
	file = fopen(arquivo, "a");// "A"  vem de ADD c adicionar a informacao 
	fprintf(file,"\nNOME:");
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: ");
	getchar(); // Limpa o caractere de nova linha pendente no buffer
  	fgets(nome, sizeof(nome), stdin); // Lê uma linha inteira, incluindo espaços em branco
 	nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha do final do nome
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSOBRENOME:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(sobrenome, sizeof(sobrenome), stdin);
	sobrenome[strcspn(sobrenome, "\n")] = '\0'; // Remove a nova linha do final do sobrenome

	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCARGO:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);	
	
    system("pause");
    
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    char  cpf[40];
    char conteudo[200];
    char *token;
    
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); // "R" vem de Read , usado para pedir que o sistema leia o arquivo que esta sendo pedido , nesse caso cpf.
    
    if(file == NULL) //validacao do que foi digitado pelo usuario
    {
        printf("CPF não localizado.\n");
    }
    
    	printf("\nEssas sao as informacoes do usuario:\n");
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("%s", conteudo);    	
	} 
	
	fclose(file);
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char  cpf[40];
    
    printf("Digite o cpf a ser deletado:");
    scanf("%s",cpf);
    
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao existe!\n");
		system ("pause");
		
	}	
	
	
    
}

int main ()
{
	int opcao=0; //Definindo Variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");

	

	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");// Inicio das Opçoes do menu
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");  
		printf("\t4 - Sair do Sistema\n");
		printf("Opcao: ");       //fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuario
	
		system("cls");     //Limpando menu principal. 
		
		switch(opcao)    // Inicio da selecao 
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
				
			case 4:
				printf("Obrigado por Utilizar o sistema! \n");	
				return 0;
				break;
				
			default:
				printf("Essa Opção não é valida.\n\n");
				system("pause");
				break;
				
				
		}  // Final da selecao.
	
	}
	
	printf("Software Livre para alunos\n"); // Direitos autorais.
} // linha final do codigo.
