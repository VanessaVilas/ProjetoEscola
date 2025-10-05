#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Disciplina.h"

int inserirDisciplina(Disciplina** inicio);
int excluirDisciplina(Disciplina** inicio);
void listarDisciplinas(Disciplina** inicio);
int menuDisciplina();

int menuDisciplina(){
	int opcao;

	printf("#### Módulo de Disciplina ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Disciplina\n");
	printf("2 - Excluir Disciplina\n");
	printf("3 - Listar Disciplina\n");
	scanf("%d",&opcao);

	return opcao;
}

void mainDisciplina(Disciplina** inicioListaDisciplina){
	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
    
	    opcao = menuDisciplina();
	    
	    switch(opcao){
	      case 0:{
	        sair = TRUE;
	        break;
	      }
	      case 1: {
	      	retorno = inserirDisciplina(inicioListaDisciplina);

	      	if (retorno == SUCESSO_CADASTRO){ 
	      		printf("Disciplina cadastrada com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case ERRO_CADASTRO_SEMESTRE:{
	      				printf("Matrícula Inválida. Deve ser maior que 0.\n");
	      				break;
	      			}
                    case ERRO_CADASTRO_PROFESSOR:{
	      				printf("Sexo Inválido. Digite 'm' ou 'M' para Masculino ou 'f' ou 'F' para Feminino.\n");
	      				break;
	      			}
                    default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
	      case 2: {
	      	retorno = excluirDisciplina(inicioListaDisciplina);
	      	if (retorno == SUCESSO_EXCLUSAO){ 
	      		printf("Disciplina excluida com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrada a Disciplina com o código digitado.\n");
	      				break;
	      			}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
	      case 3: {
	      	listarDisciplinas(inicioListaDisciplina);
	      	break;	
	      }
          default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}
}

void inserirDisciplinaNaLista(Disciplina** inicio, Disciplina* novaDisciplina){
    Disciplina *atual;
    
    if (*inicio == NULL)
        *inicio = novaDisciplina;
    else{
        atual = *inicio;

        while(atual->prox != NULL)
            atual = atual->prox;
        
        atual->prox = novaDisciplina;
    }
    
    novaDisciplina->prox = NULL;
}

int inserirDisciplina(Disciplina** inicio){
    int retorno = SUCESSO_CADASTRO;

    Disciplina* novaDisciplina = (Disciplina *)malloc(sizeof(Disciplina));
    
    printf("\n### Cadastro de Disciplina ###\n");
    getchar();

	printf("Digite o nome: ");
    fgets(novaDisciplina->nome, 50, stdin);
    size_t ln = strlen(novaDisciplina->nome) - 1;
    if (novaDisciplina->nome[ln] == '\n')
        novaDisciplina->nome[ln] = '\0';
    
    printf("Digite o código: ");
    fgets(novaDisciplina->codigo, 7, stdin);
    
    size_t ln = strlen(novaDisciplina->codigo) - 1;
    if (novaDisciplina->codigo[ln] == '\n')
        novaDisciplina->codigo[ln] = '\0';

    printf("Digite o semestre: ");
    scanf("%d", &novaDisciplina->semestre);

    if (novaDisciplina->semestre <= 0){
        retorno = ERRO_CADASTRO_SEMESTRE;
    }else{
        printf("Digite o nome do professor: ");
        fgets(novaDisciplina->professor, 50, stdin); 
    }

    if (retorno == SUCESSO_CADASTRO){
    	inserirDisciplinaNaLista(inicio, novaDisciplina);
    	return SUCESSO_CADASTRO;
    }else{
    	free(novaDisciplina);
    	return retorno;
    }
}