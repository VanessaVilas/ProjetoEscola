typedef struct dados_professor{
  
  int matricula;
  char nome[50];
  char sexo;
  Data data_nascimento;
  char cpf[15];
  struct dados_professor *prox;

} Professor;

void mainProfessor(Professor** inicio, Disciplina** inicioDisciplina);
void liberarListaProfessor(Professor* inicio);
int compararDatas(Data* data1, Data* data2);