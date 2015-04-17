#include "include.h"

int main (int argc, char **argv) {
  char *host = argv[1];
  enum clnt_stat stat;
  matrice2 res;
  matrice2 m;
  if (strcmp(argv[2], "+") == 0) {
    m.mul = 0;
  } else {
    m.mul = 1;
  }
  m.s = atoi(argv[3]);
  m.x = (int *)malloc(sizeof(int)*m.s*m.s);
  m.y = (int *)malloc(sizeof(int)*m.s*m.s);
  int i;
  srand(time(NULL));
  for (i = 0; i < m.s*m.s; i++) {
    m.x[i] = rand() % 200;
    m.y[i] = rand() % 200;
  }

  stat = callrpc(
    /* host */ host,
    /* prognum */ PROGNUM,
    /* versnum */ VERSNUM,
    /* procnum */ PROCNUM,
    /* encodage argument */ (xdrproc_t)xdr_matrice2,
    /* argument */ (char *)&m,
    /* decodage retour */ (xdrproc_t)xdr_matrice2,
    /* retour de la fonction distante */(char *)&res
  ); 

  if (stat != RPC_SUCCESS) { 
    fprintf(stderr, "Echec de l'appel distant\n");
    clnt_perrno(stat);
    fprintf(stderr, "\n");
  } else {
    int i;
    for (i = 0; i < m.s*m.s; i++) {
      printf("%d\t", m.x[i]);
      if ( (i % m.s) == m.s-1)
        printf("\n");
    }
    printf("\n");
    printf("\t_____________________________________________________\n\n");
    for (i = 0; i < m.s*m.s; i++) {
      printf("%d\t", m.y[i]);
      if ( (i % m.s) == m.s-1)
        printf("\n");
    }
    printf("\n");
    printf("\t_____________________________________________________\n\n");
    for (i = 0; i < res.s*res.s; i++) {
      printf("%d\t", res.x[i]);
      if ( (i % res.s) == m.s-1)
        printf("\n");
    }
  }
  return(0);
}
