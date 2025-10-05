#include <stdio.h>

#include "Escola.h"
#include "Aluno.h"
#include "Disciplina.h"

int menuGeral(){
	int opcao;

	printf("#### Digite a opção: ####\n");
	printf("0 - Sair\n");
	printf("1 - Gerenciar Aluno\n");
	printf("2 - Gerenciar Professor\n");
	printf("3 - Gerenciar Disciplina\n");

	scanf("%d",&opcao);

	return opcao;
}

void finalizarEscola(Aluno* inicioAluno, Disciplina* inicioDisciplina){
	liberarListaAluno(inicioAluno); 
	liberarListaDisciplina(inicioDisciplina);
}



int main(){
	Aluno aluno; 
	Aluno* inicioListaAluno = NULL; 

	Disciplina disciplina; 
	Disciplina* inicioListaDisciplina = NULL;

	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
	    opcao = menuGeral();
	    
	    switch(opcao){
	      case 0:{
	        printf("Finalizando Escola\n");
	        finalizarEscola(inicioListaAluno, inicioListaDisciplina);
	        sair = TRUE;
	        break;
	      }
	      case 1: {
	      	mainAluno(&inicioListaAluno);
	      	break;
	      }
	      case 2: {
	      	printf("listar os alunos\n");
	      	break;
	      }
		  case 3: {
			mainDisciplina(&inicioListaDisciplina);
	      	break;
		  }
		  default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}
}