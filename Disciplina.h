typedef struct dados_disciplina{
    
  char nome[50];
  char codigo[7];
  int semestre;
  char professor[50];
  struct dados_aluno *prox;
    
} Disciplina;

void mainDisciplina(Disciplina** inicio);
void liberarListaDisciplina(Disciplina* inicio);