#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Professor.h"

int inserirProfessor(Professor** inicioProfessor);
int atualizarProfessor(Professor** inicioProfessor);
int excluirProfessor(Professor** inicioProfessor);
void listarProfessor(Professor** inicioProfessor);
int menuProfessor();

int geraMatriculaProfessor(){
	static int num = 0;
	num++;
	return num;
}

int menuProfessor(){
	int opcao;

	printf("#### Módulo de Professor ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Professor\n");
	printf("2 - Atualizar Professor\n");
	printf("3 - Excluir Professor\n");
	printf("4 - Listar Professor\n");
	scanf("%d",&opcao);

	return opcao;
}

void mainProfessor(Professor** inicioListaProfessor){
	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
	    opcao = menuProfessor();
	    
	    switch(opcao){
	      case 0:{
	        sair = TRUE;
	        break;
	      }
	      case 1:{
	      	retorno = inserirProfessor(inicioListaProfessor);

	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Professor cadastrado com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case ERRO_CADASTRO_SEXO:{
	      				printf("Sexo Inválido. Digite 'm' ou 'M' para Masculino ou 'f' ou 'F' para Feminino.\n");
	      				break;
	      			}
	      			case ERRO_DATA_INVALIDA:{
	      				printf("Data Inválida.\n");
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
			retorno = atualizarProfessor(inicioListaProfessor);
	      	if(retorno == SUCESSO_ATUALIZACAO){ 
	      		printf("Professor atualizado com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
					case ERRO_CADASTRO_SEXO:{
	      				printf("Sexo Inválido. Digite 'm' ou 'M' para Masculino ou 'f' ou 'F' para Feminino.\n");
	      				break;
	      			}
	      			case ERRO_DATA_INVALIDA:{
	      				printf("Data Inválida.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrado o professor com a matrícula digitado.\n");
	      				break;
	      			}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
		  }
	      case 3:{
	      	retorno = excluirProfessor(inicioListaProfessor);
	      	if(retorno == SUCESSO_EXCLUSAO){ 
	      		printf("Professor excluido com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
					case NAO_ENCONTRADO:{
	      				printf("Não foi encontrado o professor com a matricula digitada.\n");
	      				break;
	      			}
					default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
	      case 4:{
	      	listarProfessor(inicioListaProfessor);
	      	break;	
	      }
		  default:{
	      	printf("Opcao inválida\n");
	      }
	  	}
	}
}

void inserirProfessorNaLista(Professor** inicioProfessor, Professor* novoProfessor){
    Professor *atual;
    
    if(*inicioProfessor == NULL)
        *inicioProfessor = novoProfessor;
    else{
        atual = *inicioProfessor;

        while(atual->prox != NULL)
            atual = atual->prox;
        
        atual->prox = novoProfessor;
    }
    
    novoProfessor->prox = NULL;
}

int inserirProfessor(Professor** inicioProfessor){
    int retorno = SUCESSO_CADASTRO;

    Professor* novoProfessor = (Professor *)malloc(sizeof(Professor));
    
    printf("\n### Cadastro de Professor ###\n");
    getchar();

	printf("Digite o nome: ");
    fgets(novoProfessor->nome, 50, stdin);
    size_t ln = strlen(novoProfessor->nome) - 1;
    if(novoProfessor->nome[ln] == '\n')
        novoProfessor->nome[ln] = '\0';
    
    printf("Digite o sexo: ");
    scanf("%c", &novoProfessor->sexo);
    
    novoProfessor->sexo = toupper(novoProfessor->sexo);
    if(novoProfessor->sexo != 'M' && novoProfessor->sexo != 'F') {
        retorno = ERRO_CADASTRO_SEXO;
    }else{
	    char data[11];
	    printf("Digite a data de nascimento: ");
	    scanf("%s", novoProfessor->data_nascimento.dataCompleta);
	    getchar();

	    int dataValida = validar_data(novoProfessor->data_nascimento.dataCompleta);
	    if(dataValida == FALSE){
	        retorno = ERRO_DATA_INVALIDA;
	    }else{
		    printf("Digite o CPF: ");
		    fgets(novoProfessor->cpf, 15, stdin); 
		    ln = strlen(novoProfessor->cpf) - 1; 
		    if(novoProfessor->cpf[ln] == '\n')
		        novoProfessor->cpf[ln] = '\0';
	    }
    }

    if(retorno == SUCESSO_CADASTRO){
    	novoProfessor->matricula = geraMatriculaProfessor();
    	inserirProfessorNaLista(inicioProfessor, novoProfessor);
    	return SUCESSO_CADASTRO;
    }else{
    	free(novoProfessor);
    	return retorno;
    }
}

int atualizarProfessorNaLista(Professor** inicioProfessor, int matricula){
	if(*inicioProfessor == NULL)
		return LISTA_VAZIA;

	Professor* atual = *inicioProfessor;
	int achou = FALSE;

	while(atual != NULL){
		if(atual->matricula == matricula){
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
		
		printf("Digite o sexo: ");
		scanf("%c", &atual->sexo);
		
		atual->sexo = toupper(atual->sexo);
		if(atual->sexo != 'M' && atual->sexo != 'F') {
			retorno = ERRO_CADASTRO_SEXO;
		}else{
			char data[11];
			printf("Digite a data de nascimento: ");
			scanf("%s", atual->data_nascimento.dataCompleta);
			getchar();

			int dataValida = validar_data(atual->data_nascimento.dataCompleta);
			if(dataValida == FALSE){
				retorno = ERRO_DATA_INVALIDA;
			}else{
				printf("Digite o CPF: ");
				fgets(atual->cpf, 15, stdin); 
				ln = strlen(atual->cpf) - 1; 
				if(atual->cpf[ln] == '\n')
					atual->cpf[ln] = '\0';
			}
		}

		return retorno;
	}else
		return NAO_ENCONTRADO;
}

int atualizarProfessor(Professor** inicioProfessor){
	int matricula;
	printf("Digite a matrícula: ");    
    scanf("%d", &matricula);
    getchar();

	return atualizarProfessorNaLista(inicioProfessor, matricula);
}

int excluirProfessorNaLista(Professor** inicioProfessor, int matricula){
	if(*inicioProfessor == NULL)
		return LISTA_VAZIA;

	Professor* anterior = *inicioProfessor;
	Professor* atual = *inicioProfessor;
	Professor* proximo = atual->prox;
	int achou = FALSE;

	while(atual != NULL){
		if(atual->matricula == matricula){
			achou = TRUE;
			break;
		}
		anterior = atual;
		atual = proximo;
		if(atual != NULL)
			proximo = atual->prox;
	}

	if(achou){
		if(atual == *inicioProfessor)
			*inicioProfessor = proximo;
		else
			anterior->prox = atual->prox;
		free(atual);
		return SUCESSO_EXCLUSAO;
	}else
		return NAO_ENCONTRADO;
}

int excluirProfessor(Professor** inicioProfessor){
	int matricula;
	printf("Digite a matrícula: ");    
    scanf("%d", &matricula);
    getchar();

	return excluirProfessorNaLista(inicioProfessor, matricula);
}

void listarProfessor(Professor** inicioProfessor){
    int i;
    Professor* professorAtual = *inicioProfessor;
    if(*inicioProfessor == NULL){
        printf("Lista Vazia\n");
    }else{
    	printf("\n### Professores Cadastrados ####\n");
        do{
            printf("-----\n");
            printf("Matrícula: %d\n", professorAtual->matricula);
            printf("Nome: %s\n", professorAtual->nome);
            printf("Sexo: %c\n", professorAtual->sexo);
            printf("Data Nascimento: %s\n", professorAtual->data_nascimento.dataCompleta);
            printf("CPF: %s\n", professorAtual->cpf);
            
            professorAtual = professorAtual->prox;
        }while (professorAtual != NULL);
    }    
    printf("-----\n\n");
}

void liberarListaProfessor(Professor* inicioProfessor){
	Professor* atual = inicioProfessor;
	Professor* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}