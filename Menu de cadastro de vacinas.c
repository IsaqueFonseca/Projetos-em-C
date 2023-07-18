#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct cadastro
{
  char nome[50];
  char cpf[15];
  char vacina[20];
  char data[10];
  char lote[9];
};

int main()
{
  struct cadastro busca[10];
  int i, a, k, q, pessoas, ciclo, achou;
  char j[15];
  
  do
  {
    ciclo = 1;
    system("cls");
    printf("1 - Cadastrar Vacina\n");
    printf("2 - Listar Aplicações\n");
    printf("3 - Consultar por CPF\n");
    printf("4 - Sair\n");
    printf("Digite a opção desejada:\n");
    scanf("%d", &i);
    fflush(stdin);
    
    if (i == 1)
    {
      system("cls");
      printf("Quantas pessoas você deseja cadastrar?\n");
      scanf("%d", &pessoas);
      fflush(stdin);
      
      for (a = 0; a < pessoas; a++)
      {
        system("cls");
        printf("Digite o nome do usuário:\n");
        gets(busca[a].nome);
        fflush(stdin);
        printf("Digite o CPF:\n");
        gets(busca[a].cpf);
        fflush(stdin);
        printf("Digite a vacina aplicada:\n");
        gets(busca[a].vacina);
        fflush(stdin);
        printf("Digite a data de aplicação:\n");
        gets(busca[a].data);
        fflush(stdin);
        printf("Digite o número do lote:\n");
        gets(busca[a].lote);
        fflush(stdin);
        system("pause");
      }
    }          
    else if (i == 2)
    {
      system("cls");
      for (a = 0; a < pessoas; a++)
      {
        printf("=======================\n");
        printf("Código: %d\n", a);
        printf("Nome: %s\n", busca[a].nome);
        printf("CPF: %s\n", busca[a].cpf);
        printf("Vacina: %s\n", busca[a].vacina);
        printf("Data: %s\n", busca[a].data);
        printf("Número do Lote: %s\n", busca[a].lote);
        printf("=======================\n");
        system("pause");
      } 
    }
    else if (i == 3)
    {
      achou = 1;
      system("cls");
      printf("Digite o CPF que deseja buscar:\n");
      gets(j);
      fflush(stdin);
      k = 1;
      
      for (a = 0; a < pessoas; a++)
      {
        for (q = 0; q < 15 && k == 1; q++)
        {
          if (busca[a].cpf[q] == j[q])
          {
            k = 1;
          }
          else
          {
            k = 2;
          }
        }
        
        if (k == 1 && q == 15)  
        {  
          printf("=======================\n");
          printf("Código: %d\n", a);
          printf("Nome: %s\n", busca[a].nome);
          printf("CPF: %s\n", busca[a].cpf);
          printf("Vacina: %s\n", busca[a].vacina);
          printf("Data: %s\n", busca[a].data);
          printf("Número do Lote: %s\n", busca[a].lote);
          printf("=======================\n"); 
          achou = 2;   
          system("pause");
        }
        
        if (a == pessoas && k == 1 && achou == 1)
        {
          printf("CPF não encontrado\n");
          system("pause");
        }
        k = 1;
      }
    }
    else if (i == 4)
    {
      ciclo = 2;
    }
  } while (ciclo == 1);
  
  return 0;
}

