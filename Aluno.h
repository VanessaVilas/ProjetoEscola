typedef struct dados_aluno
{
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[15];
  struct dados_aluno *prox;
    
} Aluno;

void mainAluno(Aluno** inicio);
void liberarListaAluno(Aluno* inicio);


