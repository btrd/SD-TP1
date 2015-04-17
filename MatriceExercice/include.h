#ifndef INCRPC
#define INCRPC  

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#define PROGNUM 0x20000100
#define VERSNUM 1
#define PROCNUM 1
typedef struct {
  int s; //size
  int *x;
  int *y;
  int mul; //add ou mul
  //matrice[2][n*n]
} matrice2;
bool_t xdr_matrice2(XDR *, matrice2 *);

#endif /* INCRPC */
