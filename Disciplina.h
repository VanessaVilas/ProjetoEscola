typedef struct dados_disciplina{
    
  char nome[50];
  int codigo;
  int semestre;
  char professor[50];
  struct dados_disciplina *prox;
    
} Disciplina;

void mainDisciplina(Disciplina** inicio, Professor** inicioProfessor);
void liberarListaDisciplina(Disciplina* inicio);