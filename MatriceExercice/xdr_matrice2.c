#include "include.h"
bool_t xdr_matrice2(XDR *xdrs, matrice2 *m) {
  bool_t res = 1;
  if (xdr_int(xdrs, &m->s) == 0) {
    res = 0;
  }
  if (xdr_int(xdrs, &m->mul) == 0) {
    res = 0;
  }
  
  //Force XDR to allocate memory while decoding
  if((xdrs->x_op == XDR_DECODE) && (m->x != NULL)) {
    free(m->x);
    m->x = NULL;
  }
  if((xdrs->x_op == XDR_DECODE) && (m->y != NULL)) {
    free(m->y);
    m->y = NULL;
  }
  // if(xdrs->x_op != XDR_DECODE) {
  //   printf("%d\n", m->x[0]);
  // }
  uint si = m->s*m->s;
  if (xdr_array(xdrs, (char **)&m->x, &si, (m->s*m->s), sizeof(int), (xdrproc_t)xdr_int) == 0) {
    res = 0;
  }
  if (xdr_array(xdrs, (char **)&m->y, &si, (m->s*m->s), sizeof(int), (xdrproc_t)xdr_int) == 0) {
    res = 0;
  }
  return res;
}
