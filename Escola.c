#include <stdio.h>
#include <time.h>

#include "Escola.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

void listarAniversariantes(Aluno** inicioAluno, Professor** inicioProfessor);

int menuGeral(){
	int opcao;

	printf("#### Digite a opção: ####\n");
	printf("0 - Sair\n");
	printf("1 - Gerenciar Aluno\n");
	printf("2 - Gerenciar Professor\n");
	printf("3 - Gerenciar Disciplina\n");
	printf("4 - Listar Aniversariantes do Mês\n");

	scanf("%d",&opcao);

	return opcao;
}

void finalizarEscola(Aluno* inicioAluno, Professor* inicioProfessor, Disciplina* inicioDisciplina){
	liberarListaAluno(inicioAluno); 
	liberarListaProfessor(inicioProfessor);
	liberarListaDisciplina(inicioDisciplina);
}



int main(){
	Aluno aluno; 
	Aluno* inicioListaAluno = NULL; 

	Disciplina disciplina; 
	Disciplina* inicioListaDisciplina = NULL;

	Professor professor; 
	Professor* inicioListaProfessor = NULL;

	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
	    opcao = menuGeral();
	    
	    switch(opcao){
	      case 0:{
	        printf("Finalizando Escola\n");
	        finalizarEscola(inicioListaAluno, inicioListaProfessor, inicioListaDisciplina);
	        sair = TRUE;
	        break;
	      }
	      case 1: {
	      	mainAluno(&inicioListaAluno);
	      	break;
	      }
	      case 2: {
	      	mainProfessor(&inicioListaProfessor);
	      	break;
	      }
		  case 3: {
			mainDisciplina(&inicioListaDisciplina, &inicioListaProfessor, &inicioListaAluno);
	      	break;
		  }
		  case 4: {
			listarAniversariantes(&inicioListaAluno, &inicioListaProfessor);
			break;
		  }
		  default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}
}

void listarAniversariantes(Aluno** inicioAluno, Professor** inicioProfessor){
	time_t t = time(NULL);
    struct tm dataAtual = *localtime(&t);

    int mesAtual = dataAtual.tm_mon + 1;

	Aluno* atualAluno = *inicioAluno;
	Professor* atualProfessor = *inicioProfessor;
	int achou = FALSE;
	if(*inicioAluno == NULL && *inicioProfessor == NULL){
        printf("Listas Vazias\n");
	}else{
		printf("\n### Aniversariantes do Mês ####\n");
		while(atualAluno != NULL){
			if(atualAluno->data_nascimento.mes == mesAtual){
				achou = TRUE;
				
				printf("-----\n");
				printf("Aluno: %s\n", atualAluno->nome);
				printf("Matrícula: %d\n", atualAluno->matricula);
				printf("Data Nascimento: %s\n", atualAluno->data_nascimento.dataCompleta);
			}
			atualAluno = atualAluno->prox;
		}

		while(atualProfessor != NULL){
			if(atualProfessor->data_nascimento.mes == mesAtual){
				achou = TRUE;
				
				printf("-----\n");
				printf("Professor: %s\n", atualProfessor->nome);
				printf("Matrícula: %d\n", atualProfessor->matricula);
				printf("Data Nascimento: %s\n", atualProfessor->data_nascimento.dataCompleta);
			}
			atualProfessor = atualProfessor->prox;
		}

		if(!achou){
			printf("Nenhum professor ou aluno é aniversariante esse mês.\n");
		}
		printf("-----\n\n");
	}
}