#include "include.h"

matrice2 * multiply(matrice2 *m) {
  printf("MULTIPLY\n");
  printf("%d\n", m->s);
  printf("%d\n", m->x[30]);
  static matrice2 res;

  res.s = m->s;

  res.x = (int *)malloc(sizeof(int)*res.s*res.s);
  res.y = (int *)malloc(sizeof(int)*res.s*res.s);

  int i, j, k, sum;
  sum = 0;
  if (m->mul == 1) {
    for (i = 0; i < m->s; i++) {
      for (j = 0; j < m->s; j++) {
        for (k = 0; k < m->s; k++) {
          sum = sum + (m->x[i*m->s+k])*(m->y[k*m->s+j]);
        }
        res.x[i*m->s+j] = sum;
        sum = 0;
      }
    }
  } else {
    for (i = 0; i < m->s*m->s; i++) {
      res.x[i] = (m->x[i])+(m->y[i]);
    }
  }
  return &res;
}
int main (void) {
  bool_t stat;
  stat = registerrpc(
    /* prognum */ PROGNUM,
    /* versnum */ VERSNUM,
    /* procnum */ PROCNUM,
    /* pointeur sur fonction */ multiply,
    /* decodage arguments */ (xdrproc_t)xdr_matrice2,
    /* encodage retour de fonction */ (xdrproc_t)xdr_matrice2
  );
  if (stat != 0) {
    fprintf(stderr,"Echec de l'enregistrement\n");
    exit(1);
  }
  svc_run(); /* le serveur est en attente de clients eventuels */
  return(0); /* on y passe jamais ! */
}


