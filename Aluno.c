#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Aluno.h"
#include "Disciplina.h"
#include "Professor.h"

int inserirAluno(Aluno** inicioAluno);
int atualizarAluno(Aluno** inicioAluno);
int excluirAluno(Aluno** inicioAluno, Disciplina** inicioDisciplina);
void listarAlunos(Aluno** inicioAluno, int opcao);
int menuAluno();
void listarAlunoOrdenado(Aluno** inicioAluno);
void listarAlunoPorSexo(Aluno** inicioAluno);
void listarAlunoPorData(Aluno** inicioAluno);

int geraMatriculaAluno(){
	static int num = 0;
	num++;
	return num;
}

int menuListarAluno(){
	int opcao;
int validarCadastroAluno(Aluno* aluno){
	int retorno = SUCESSO_CADASTRO;
	
	printf("Digite o nome: ");
    fgets(aluno->nome, 50, stdin);
    size_t ln = strlen(aluno->nome) - 1;
    if(aluno->nome[ln] == '\n')
        aluno->nome[ln] = '\0';
    
    printf("Digite o sexo: ");
    scanf("%c", &aluno->sexo);
    
    aluno->sexo = toupper(aluno->sexo);
    if(aluno->sexo != 'M' && aluno->sexo != 'F') {
        retorno = ERRO_CADASTRO_SEXO;
    }else{
	    printf("Digite a data de nascimento: ");
	    scanf("%s", aluno->data_nascimento.dataCompleta);
	    getchar();

	printf("#### Listagem ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o módulo de aluno\n");
	printf("1 - Listar Alunos\n");
	printf("2 - Listar Alunos por Sexo\n");
	printf("3 - Listar Alunos Ordenados por Nome\n");
	printf("4 - Listar Alunos Ordenados por Data de Nascimento\n");
	printf("5 - Listar Alunos Matriculados em Menos de 3 Disciplinas\n");
	scanf("%d",&opcao);

	return opcao;
}

void mainListarAluno(Aluno** inicioListaAluno){
	int opcao;
	int sair = FALSE;

	while (!sair){
		opcao = menuListarAluno();
		
		switch(opcao){
			case 0:{
			sair = TRUE;
			break;
			}
			case 1:{
				listarAlunos(inicioListaAluno, opcao);
				break;
			}
			case 5:{
				listarAlunos(inicioListaAluno, opcao);
				break;
			}
			default:{
				printf("opcao inválida\n");
			}
		}
	}
}

int menuAluno(){
	int opcao;

	printf("#### Módulo de Aluno ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Aluno\n");
	printf("2 - Atualizar Aluno\n");
	printf("3 - Excluir Aluno\n");
	printf("4 - Listar Alunos\n");
	scanf("%d",&opcao);

	return opcao;
}

void mainAluno(Aluno** inicioListaAluno, Disciplina** inicioListaDisciplina){
	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
	    opcao = menuAluno();
	    
	    switch(opcao){
	      case 0:{
	        sair = TRUE;
	        break;
	      }
	      case 1:{
	      	retorno = inserirAluno(inicioListaAluno);

	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Aluno cadastrado com sucesso\n");
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
			retorno = atualizarAluno(inicioListaAluno);
	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Aluno atualizado com sucesso\n");
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
	      				printf("Não foi encontrado o aluno com a matrícula digitado.\n");
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
	      	retorno = excluirAluno(inicioListaAluno, inicioListaDisciplina);
	      	if(retorno == SUCESSO_EXCLUSAO){ 
	      		printf("Aluno excluido com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
					case NAO_ENCONTRADO:{
	      				printf("Não foi encontrado o aluno com a matrícula digitada.\n");
	      				break;
	      			}
					default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
<<<<<<< HEAD
	       case 4: {
				int opcaoLista;
=======
	      case 4:{
	      	mainListarAluno(inicioListaAluno);
			break;
	      }
		  default:{
	      	printf("opcao inválida\n");
	      }
		  		int opcaoLista;
>>>>>>> 00935aef4a980a87c076409236b9b5ba457fd1e4
				int sairLista = FALSE;
				while (!sairLista) {
					printf("#### Listagem ####\n");
					printf("#### Digite a opção: ####\n");
					printf("0 - Voltar para o módulo de Aluno\n");
					printf("1 - Listar todos os Alunos\n");
					printf("2 - Listar Alunos por Sexo\n");
					printf("3 - Listar Alunos em Ordem Alfabética\n");
					printf("4 - Listar Alunos por Data de Nascimento\n");
					scanf("%d", &opcaoLista);
					getchar();

					switch (opcaoLista) {
						case 0:{
							sairLista = TRUE;
							break;
						}
						case 1:{
							listarAlunos(inicioListaAluno);
							break;
						}
						case 2:{
							listarAlunoPorSexo(inicioListaAluno);
							break;
						}
						case 3:{
							listarAlunoOrdenado(inicioListaAluno);
							break;
						}
						case 4:{
							listarAlunoPorData(inicioListaAluno);
							break;
						}
						default:{
							printf("Opção inválida!\n");
						}
					}
				}
		 	 } 
			 break;
			default:{
			printf("Opcao inválida\n");
			}
		}
	}
}

int validarCadastroAluno(Aluno* aluno){
	int retorno = SUCESSO_CADASTRO;
	
	printf("Digite o nome: ");
    fgets(aluno->nome, 50, stdin);
    size_t ln = strlen(aluno->nome) - 1;
    if(aluno->nome[ln] == '\n')
        aluno->nome[ln] = '\0';
    
    printf("Digite o sexo: ");
    scanf("%c", &aluno->sexo);
    
    aluno->sexo = toupper(aluno->sexo);
    if(aluno->sexo != 'M' && aluno->sexo != 'F') {
        retorno = ERRO_CADASTRO_SEXO;
    }else{
	    char data[11];
	    printf("Digite a data de nascimento: ");
	    scanf("%s", aluno->data_nascimento.dataCompleta);
	    getchar();

	    int dataValida = validar_data(aluno->data_nascimento.dataCompleta, &aluno->data_nascimento);
	    if(dataValida == FALSE){
	        retorno = ERRO_DATA_INVALIDA;
	    }else{
		    printf("Digite o CPF: ");
		    fgets(aluno->cpf, 15, stdin); 
		    ln = strlen(aluno->cpf) - 1; 
		    if(aluno->cpf[ln] == '\n')
		        aluno->cpf[ln] = '\0';
	    }
    }
	return retorno;
}

void inserirAlunoNaLista(Aluno** inicioAluno, Aluno* novoAluno){
    Aluno *atual;
    
    if(*inicioAluno == NULL)
        *inicioAluno = novoAluno;
    else{
        atual = *inicioAluno;

        while(atual->prox != NULL)
            atual = atual->prox;
        
        atual->prox = novoAluno;
    }
    
    novoAluno->prox = NULL;
}

int inserirAluno(Aluno** inicioAluno){
    Aluno* novoAluno = (Aluno *)malloc(sizeof(Aluno));
    
    printf("\n### Cadastro de Aluno ###\n");
    getchar();
	
	int retorno = validarCadastroAluno(novoAluno);
	
    if(retorno == SUCESSO_CADASTRO){
    	novoAluno->matricula = geraMatriculaAluno();
    	inserirAlunoNaLista(inicioAluno, novoAluno);
    	return SUCESSO_CADASTRO;
    }else{
    	free(novoAluno);
    	return retorno;
    }
}

int atualizarAlunoNaLista(Aluno** inicioAluno, int matricula){
	if(*inicioAluno == NULL)
		return LISTA_VAZIA;

	Aluno* atual = *inicioAluno;
	int achou = FALSE;

	while(atual != NULL){
		if(atual->matricula == matricula){
			achou = TRUE;
			break;
		}
		atual = atual->prox;
	}

	if(achou){
		printf("\n### Atualização de Aluno ###\n");

		Aluno tmp;

		int retorno = validarCadastroAluno(&tmp);	

		if(retorno == SUCESSO_CADASTRO){
			strcpy(atual->nome, tmp.nome);
        	atual->sexo = tmp.sexo;
        	strcpy(atual->data_nascimento.dataCompleta, tmp.data_nascimento.dataCompleta);
        	strcpy(atual->cpf, tmp.cpf);
		}

		return retorno;
	}else
		return NAO_ENCONTRADO;
}

int atualizarAluno(Aluno** inicioAluno){
	int matricula;
	printf("Digite a matrícula: ");    
    scanf("%d", &matricula);
    getchar();

	return atualizarAlunoNaLista(inicioAluno, matricula);
}

void desmatricularAluno(Disciplina* inicioDisciplina, int matricula){
    Disciplina* DisciplinaAtual = inicioDisciplina;

    while (DisciplinaAtual != NULL) {
        for (int i = 0; i < DisciplinaAtual->qtdAlunos; i++) {
            if (DisciplinaAtual->matriculaAluno[i] == matricula) {
                for (int j = i; j < DisciplinaAtual->qtdAlunos - 1; j++) {
                    DisciplinaAtual->matriculaAluno[j] = DisciplinaAtual->matriculaAluno[j + 1];
                }

                DisciplinaAtual->qtdAlunos--;
            }
        }

        DisciplinaAtual = DisciplinaAtual->prox;
    }
}

int excluirAlunoNaLista(Aluno** inicioAluno, Disciplina** inicioDisciplina, int matricula){
	if(*inicioAluno == NULL)
		return LISTA_VAZIA;

	Aluno* anterior = *inicioAluno;
	Aluno* atual = *inicioAluno;
	Aluno* proximo = atual->prox;
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
		if(atual == *inicioAluno)
			*inicioAluno = proximo;
		else
			anterior->prox = atual->prox;
		free(atual);

		desmatricularAluno(*inicioDisciplina, matricula);

		return SUCESSO_EXCLUSAO;
	}else
		return NAO_ENCONTRADO;
}

int excluirAluno(Aluno** inicioAluno, Disciplina** inicioDisciplina){
	int matricula;
	printf("Digite a matrícula: ");    
    scanf("%d", &matricula);
    getchar();

	return excluirAlunoNaLista(inicioAluno, inicioDisciplina, matricula);
}

void listarAlunos(Aluno** inicioAluno, int opcao){
    Aluno* alunoAtual = *inicioAluno;
    if(*inicioAluno == NULL){
        printf("Lista Vazia\n");
    }else if(opcao == 1 || (opcao == 5 && alunoAtual->qtdDisciplinas < 3)){
    	printf("\n### Alunos Cadastrados ####\n");
        do{
            printf("-----\n");
            printf("Matrícula: %d\n", alunoAtual->matricula);
            printf("Nome: %s\n", alunoAtual->nome);
            printf("Sexo: %c\n", alunoAtual->sexo);
            printf("Data Nascimento: %s\n", alunoAtual->data_nascimento.dataCompleta);
            printf("CPF: %s\n", alunoAtual->cpf);
            
            alunoAtual = alunoAtual->prox;
        }while (alunoAtual != NULL);
		printf("-----\n\n");
    }else if(opcao == 5){
		printf("Nenhum aluno está matriculado em menos de 3 disciplinas.\n");
	}
}

void liberarListaAluno(Aluno* inicioAluno){
	Aluno* atual = inicioAluno;
	Aluno* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}

void listarAlunoPorSexo(Aluno** inicioAluno) {
	
    if (*inicioAluno == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    char sexoFiltro;
    printf("Digite o sexo para filtrar (M/F): ");
    scanf(" %c", &sexoFiltro);
    sexoFiltro = toupper(sexoFiltro);

    if (sexoFiltro != 'M' && sexoFiltro != 'F') {
        printf("Sexo inválido! Digite 'M' ou 'F'.\n");
        return;
    }


    int contador = 0;
    Aluno* atual = *inicioAluno;
		while (atual != NULL) {
			if (atual->sexo == sexoFiltro)
				contador++;
			atual = atual->prox;
		}

			if (contador == 0) {
				printf("Nenhum aluno encontrado para o sexo informado.\n");
				return;
			}


    Aluno** vetor = (Aluno**) malloc(contador * sizeof(Aluno*));
    atual = *inicioAluno;
    int i = 0;
		while (atual != NULL) {
			if (atual->sexo == sexoFiltro) {
				vetor[i] = atual;
				i++;
			}
			atual = atual->prox;
		}


			for (int x = 0; x < contador - 1; x++) {
				for (int y = x + 1; y < contador; y++) {
					if (strcasecmp(vetor[x]->nome, vetor[y]->nome) > 0) {
						Aluno* temp = vetor[x];
						vetor[x] = vetor[y];
						vetor[y] = temp;
					}
				}
			}

    printf("\n### Alunos Cadastrados do Sexo %s (Ordem Alfabética) ###\n",
           sexoFiltro == 'M' ? "Masculino" : "Feminino");

			for (int j = 0; j < contador; j++) {
				printf("-----\n");
				printf("Matrícula: %d\n", vetor[j]->matricula);
				printf("Nome: %s\n", vetor[j]->nome);
				printf("Sexo: %c\n", vetor[j]->sexo);
				printf("Data Nascimento: %s\n", vetor[j]->data_nascimento.dataCompleta);
				printf("CPF: %s\n", vetor[j]->cpf);
			}

    printf("-----\n\n");

free(vetor);
}

void listarAlunoOrdenado(Aluno** inicioAluno) {
    if (*inicioAluno == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    int contador = 0;
    Aluno* atual = *inicioAluno;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }


    Aluno** vetor = (Aluno**) malloc(contador * sizeof(Aluno*));
    atual = *inicioAluno;
    int i = 0;
    while (atual != NULL) {
        vetor[i] = atual;
        i++;
        atual = atual->prox;
    }

    for (int x = 0; x < contador - 1; x++) {
        for (int y = x + 1; y < contador; y++) {
            if (strcasecmp(vetor[x]->nome, vetor[y]->nome) > 0) {
                Aluno* temp = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = temp;
            }
        }
    }

    printf("\n### Alunos Cadastrados (Ordem Alfabética) ###\n");
    for (int j = 0; j < contador; j++) {
		printf("-----\n");
        printf("Matrícula: %d\n", vetor[j]->matricula);
        printf("Nome: %s\n", vetor[j]->nome);
        printf("Sexo: %c\n", vetor[j]->sexo);
        printf("Data Nascimento: %s\n", vetor[j]->data_nascimento.dataCompleta);
        printf("CPF: %s\n", vetor[j]->cpf);
    }
	printf("-----\n\n");

    free(vetor);
}

void listarAlunoPorData(Aluno** inicioAluno){
	if (*inicioAluno == NULL) {
		printf("Lista Vazia\n");
		return;
	}

	int contador = 0;
	Aluno* atual = *inicioAluno;
	while (atual != NULL) {
		contador++;
		atual = atual->prox;
	}
	Aluno** vetor = (Aluno**) malloc(contador * sizeof(Aluno*));
	atual = *inicioAluno;
	int i = 0;
	while (atual != NULL) {
		vetor[i] = atual;
		i++;
		atual = atual->prox;
	}
	for (int x = 0; x < contador - 1; x++) {
		for (int y = x + 1; y < contador; y++) {
			if (compararDatas(&vetor[x]->data_nascimento, &vetor[y]->data_nascimento) > 0) {
				Aluno* temp = vetor[x];
				vetor[x] = vetor[y];
				vetor[y] = temp;
			}
		}
	}
		printf("\n### Alunos Cadastrados (Ordem por Data de Nascimento) ###\n");
			for (int j = 0; j < contador; j++) {
				printf("-----\n");
				printf("Matrícula: %d\n", vetor[j]->matricula);
				printf("Nome: %s\n", vetor[j]->nome);
				printf("Sexo: %c\n", vetor[j]->sexo);
				printf("Data Nascimento: %s\n", vetor[j]->data_nascimento.dataCompleta);
				printf("CPF: %s\n", vetor[j]->cpf);
			}
		printf("-----\n\n");
		
free(vetor);
}



