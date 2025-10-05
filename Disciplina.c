#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Disciplina.h"

int inserirDisciplina(Disciplina** inicioDisciplina);
int atualizarDisciplina(Disciplina** inicioDisciplina);
int excluirDisciplina(Disciplina** inicioDisciplina);
void listarDisciplinas(Disciplina** inicioDisciplina);
int menuDisciplina();

int geraCodigo(){
	static int num = 0;
	num++;
	return num;
}

int menuDisciplina(){
	int opcao;

	printf("#### Módulo de Disciplina ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Disciplina\n");
	printf("2 - Atualizar Disciplina\n");
	printf("3 - Excluir Disciplina\n");
	printf("4 - Listar Disciplina\n");
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
	      case 1:{
	      	retorno = inserirDisciplina(inicioListaDisciplina);

	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Disciplina cadastrada com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case ERRO_CADASTRO_SEMESTRE:{
	      				printf("Semestre Inválido. Deve ser maior que 0.\n");
	      				break;
	      			}
                    case ERRO_CADASTRO_PROFESSOR:{
	      				printf("Professor não cadastrado.\n");
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
			retorno = atualizarDisciplina(inicioListaDisciplina);
	      	if(retorno == SUCESSO_ATUALIZACAO){ 
	      		printf("Disciplina atualizada com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
					case ERRO_CADASTRO_SEMESTRE:{
	      				printf("Semestre Inválido. Deve ser maior que 0.\n");
	      				break;
	      			}
                    case ERRO_CADASTRO_PROFESSOR:{
	      				printf("Professor não cadastrado.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrada a disciplina com o código digitado.\n");
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
	      	retorno = excluirDisciplina(inicioListaDisciplina);
	      	if(retorno == SUCESSO_EXCLUSAO){ 
	      		printf("Disciplina excluida com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrada a disciplina com o código digitado.\n");
	      				break;
	      			}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
	      case 4: {
	      	listarDisciplinas(inicioListaDisciplina);
	      	break;	
	      }
          default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}
}

void inserirDisciplinaNaLista(Disciplina** inicioDisciplina, Disciplina* novaDisciplina){
    Disciplina *atual;
    
    if(*inicioDisciplina == NULL)
        *inicioDisciplina = novaDisciplina;
    else{
        atual = *inicioDisciplina;

        while(atual->prox != NULL)
            atual = atual->prox;
        
        atual->prox = novaDisciplina;
    }
    
    novaDisciplina->prox = NULL;
}

int inserirDisciplina(Disciplina** inicioDisciplina){
    int retorno = SUCESSO_CADASTRO;

    Disciplina* novaDisciplina = (Disciplina *)malloc(sizeof(Disciplina));
    
    printf("\n### Cadastro de Disciplina ###\n");
    getchar();

	printf("Digite o nome: ");
    fgets(novaDisciplina->nome, 50, stdin);
    size_t ln = strlen(novaDisciplina->nome) - 1;
    if(novaDisciplina->nome[ln] == '\n')
        novaDisciplina->nome[ln] = '\0';

    printf("Digite o semestre: ");
    scanf("%d", &novaDisciplina->semestre);
	getchar();

    if(novaDisciplina->semestre <= 0){
        retorno = ERRO_CADASTRO_SEMESTRE;
    }else{
        printf("Digite o nome do professor: ");
        fgets(novaDisciplina->professor, 50, stdin); 
		size_t ln = strlen(novaDisciplina->professor) - 1;
    	if(novaDisciplina->professor[ln] == '\n')
        	novaDisciplina->professor[ln] = '\0';
    }

    if(retorno == SUCESSO_CADASTRO){
    	novaDisciplina->codigo = geraCodigo();
    	inserirDisciplinaNaLista(inicioDisciplina, novaDisciplina);
    	return SUCESSO_CADASTRO;
    }else{
    	free(novaDisciplina);
    	return retorno;
    }
}

int atualizarDisciplinaNaLista(Disciplina** inicioDisciplina, int codigo){
	if(*inicioDisciplina == NULL)
		return LISTA_VAZIA;

	Disciplina* atual = *inicioDisciplina;
	int achou = FALSE;

	while(atual != NULL){
		if(atual->codigo == codigo){
			achou = TRUE;
			break;
		}
		atual = atual->prox;
	}

	if(achou){
		int retorno = SUCESSO_ATUALIZACAO;

		printf("Digite o nome: ");
		fgets(atual->nome, 50, stdin);
		size_t ln = strlen(atual->nome) - 1;
		if(atual->nome[ln] == '\n')
			atual->nome[ln] = '\0';

		printf("Digite o semestre: ");
		scanf("%d", &atual->semestre);
		getchar();

		if(atual->semestre <= 0){
			retorno = ERRO_CADASTRO_SEMESTRE;
		}else{
			printf("Digite o nome do professor: ");
			fgets(atual->professor, 50, stdin); 
			size_t ln = strlen(atual->professor) - 1;
			if(atual->professor[ln] == '\n')
				atual->professor[ln] = '\0';
		}

		return retorno;
	}else
		return NAO_ENCONTRADO;
}

int atualizarDisciplina(Disciplina** inicioDisciplina){
	int codigo;
	printf("Digite o código: ");    
    scanf("%d", &codigo);
    getchar();

	return atualizarDisciplinaNaLista(inicioDisciplina, codigo);
}

int excluirDisciplinaNaLista(Disciplina** inicioDisciplina, int codigo){
	if(*inicioDisciplina == NULL)
		return LISTA_VAZIA;

	Disciplina* anterior = *inicioDisciplina;
	Disciplina* atual = *inicioDisciplina;
	Disciplina* proximo = atual->prox;
	int achou = FALSE;

	while(atual != NULL){
		if(atual->codigo == codigo){
			achou = TRUE;
			break;
		}
		anterior = atual;
		atual = proximo;
		if(atual != NULL)
			proximo = atual->prox;
	}

	if(achou){
		if(atual == *inicioDisciplina)
			*inicioDisciplina = proximo;
		else
			anterior->prox = atual->prox;
		free(atual);
		return SUCESSO_EXCLUSAO;
	}else
		return NAO_ENCONTRADO;
}

int excluirDisciplina(Disciplina** inicioDisciplina){
	int codigo;
	printf("Digite o código: ");    
    scanf("%d", &codigo);
    getchar();

	return excluirDisciplinaNaLista(inicioDisciplina, codigo);
}


void listarDisciplinas(Disciplina** inicioDisciplina){
    int i;
    Disciplina* DisciplinaAtual = *inicioDisciplina;
    if(*inicioDisciplina == NULL){
        printf("Lista Vazia\n");
    }else{
    	printf("\n### Disciplinas Cadastradas ####\n");
        do{
            printf("-----\n");
            printf("Código: %d\n", DisciplinaAtual->codigo);
            printf("Nome: %s\n", DisciplinaAtual->nome);
            printf("Semestre: %d\n", DisciplinaAtual->semestre);
            printf("Professor: %s\n", DisciplinaAtual->professor);
            
            DisciplinaAtual = DisciplinaAtual->prox;
        }while (DisciplinaAtual != NULL);
    }    
    printf("-----\n\n");
}

void liberarListaDisciplina(Disciplina* inicioDisciplina){
	Disciplina* atual = inicioDisciplina;
	Disciplina* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}