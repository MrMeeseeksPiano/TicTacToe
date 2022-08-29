#ifndef TTT_FUNCTIONS_H
#define TTT_FUNCTIONS_H

#include <stdbool.h>
#include "measures.h"

extern Point rtrn_cdnts(int X, int Y);

extern bool grid_cntct(int X, int Y);

extern bool fig_eval(Point A);

extern Point rtrn_cntr(int X, int Y);

extern bool all_done(void);

extern void clear_all(void);

extern int swp_p(int A);

extern int victory(void);

#endif