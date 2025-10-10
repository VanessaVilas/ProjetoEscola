typedef struct dados_disciplina{
    
  char nome[50];
  int codigo;
  int semestre;
  char professor[50];
  char aluno[100][50];
  int matriculaAluno[100];
  int qtdAlunos;
  struct dados_disciplina *prox;
    
} Disciplina;

void mainDisciplina(Disciplina** inicio, Professor** inicioProfessor, Aluno** inicioaAluno);
void liberarListaDisciplina(Disciplina* inicio);