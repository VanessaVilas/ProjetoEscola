typedef struct dados_professor{
  
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[15];
  struct dados_professor *prox;

} Professor;

void mainProfessor(Professor** inicio);
void liberarListaProfessor(Professor* inicio);