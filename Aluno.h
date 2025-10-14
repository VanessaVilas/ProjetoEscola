typedef struct dados_disciplina Disciplina;

typedef struct dados_aluno{
  
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[15];
  int codigoDisciplina[50];
  int qtdDisciplinas;
  struct dados_aluno *prox;

} Aluno;

void mainAluno(Aluno** inicio, Disciplina** inicioDisciplina);
void liberarListaAluno(Aluno* inicio);


