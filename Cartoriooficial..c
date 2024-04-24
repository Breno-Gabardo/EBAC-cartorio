#include <stdio.h> //biblioteca de comunicação com o usuário
#include<stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca respónsavel por cuidar das string


int registro()//Função responsavel por cadastrar os usúarios no sistema
{
  //inicio criação de variáveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo [40];
  //final da criação de variáveis/string
  
  system("cls");
  
  printf("Digite o CPF a ser cadastrado:\n");//coletando informação do usuário
  scanf("%s",cpf);//%s refer-se ao string
  
  strcpy(arquivo,cpf); //Responsavel por copiar os valores dos string
   
  FILE *file;                // cria o arquivo
  file = fopen(arquivo,"w"); // cria o arquivo e o "w" = escrever
  fprintf(file,"\nCPF:");
  fprintf(file,cpf);         // salvo o valor da variavel
  fclose(file);              // fecha o arquivo
  
  file = fopen(arquivo, "a");
  fclose(file);
  
  
  
  printf("Digite o nome a ser cadastrado:\n ");
  scanf("%s",nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,"\nNOME:");
  fprintf(file,nome);
  fclose(file);
  
  
  
  printf("Digite o sobrenome a ser cadastrado:\n ");
  scanf("%s",sobrenome);
  
  file = fopen(arquivo, "a");
  fprintf(file,"\nSOBRENOME:");
  fprintf(file,sobrenome);
  fclose(file);
  
  
  
  printf("Digite o cargo a ser cadastrado:\n ");
  scanf("%s",cargo);
 
  file = fopen(arquivo, "a");
  fprintf(file,"\nCARGO:");
  fprintf(file,cargo);
  fprintf(file, "\n");
  fclose(file);
  
  system("pause");


}



int consulta()
{
setlocale(LC_ALL, "Portuguese");//definido a linguagem
 
char cpf[40];
char conteudo[200];

printf("Digite o CPF a ser consultado: ");
scanf("%s",cpf);

FILE *file;
file= fopen(cpf,"r");

if(file == NULL)
{
	 printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}

printf("\nEssas são as informações do usuário ");

while(fgets(conteudo, 200, file) != NULL)

{
	printf("%s", conteudo);
	printf("\n");
}

fclose(file);
system("pause");

}


int deletar()
{
  char cpf[40];
  
  printf("Digite o CPF a ser deletado: ");
  scanf("%s",cpf);
  
  remove(cpf);
  
  FILE *file;
  file = fopen(cpf,"r");
  
  if(file == NULL)
  {
  	printf("O usuário não se encontra no sistema!.\n");
  	system("pause");
  }
  
}


int main()
{
	
int opcao=0;//Defininfo variáveis
int laco=1;
char senhadigitada[10]="a";
int comparacao;   
    
printf("### Cartório da EBAC ###\n\n");
printf("Login de administrador!\n\nDigite a sua senha:");
scanf("%s", senhadigitada);

comparacao = strcmp(senhadigitada, "admin");
    
 if(comparacao == 0)
 {
  system ("cls");
  for(laco=1;laco=1;)
  {
	
   setlocale(LC_ALL, "Portuguese");//definido a linguagem

   printf("###Cartório da EBAC###\n\n");//inicio do menu
   printf("escolha a opção desejada do menu \n\n");
   printf("\t1-Registrar nomes\n");
   printf("\t2-Consultar nomes\n");
   printf("\t3-Deletar nomes\n\n");
   printf("\t4-Sair do sistema\n\n");
   printf("Opção:");//fim do usuário

   scanf("%d",&opcao);//armazenando o escolha do usuário

   system("cls");// responsavel por limbar a tela

   switch(opcao)//inicio da seleção do menu
    {
    case 1:	
    registro();//chamada de função
    break;
  
    case 2:
    consulta();
    break;
  
    case 3:
    deletar();
    break;
  
    case 4:
    printf("Obrigado por utilizar o sistema\n");
    return 0;
    break;
  
  
    default:
    printf("Essa opção não está disponivel\n"); 
    system("pause");
    break;
    }//fim da seleção
   }
  }
 
else
 printf("Senha incorreta!");
}

