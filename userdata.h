#ifndef USERDATA_H_INCLUDED
#define USERDATA_H_INCLUDED
#define MAX_CHAR 21

typedef struct {
  char nome[MAX_CHAR];
  char pass[MAX_CHAR];
  int pontos;
  int pontosvspc;
  int jogadas;
  int jogadaspc;
} USERS;


int userdatalogin();
int userdatamenu(USERS p1);
void altnom(USERS p1);

#endif // USERDATA_H_INCLUDED
