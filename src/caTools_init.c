#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .C calls */
extern void cumsum_exact(double *In, double *Out, const int *nIn);
extern void imwritegif(char** filename, int* Data, int *ColorMap,
		       int *param, char** comment);
extern void run_mad(double *In, double *Ctr, double *Out,
		    const int *nIn, const int *nWin);
extern void run_max(double *In, double *Out, const int *nIn,
		    const int *nWin);
extern void run_mean(double *In, double *Out, const int *nIn,
		     const int *nWin);
extern void run_mean_exact(double *In, double *Out, const int *nIn,
			   const int *nWin);
extern void run_mean_lite(double *In, double *Out, const int *nIn,
			  const int *nWin);
extern void run_min(double *In, double *Out, const int *nIn,
		    const int *nWin);
extern void run_quantile(double *In, double *Out,
			 const int *nIn, const int *nWin,
			 const double *Prob, const int *nProb,
			 const int *Type);
extern void run_sd(double *In, double *Ctr, double *Out,
		   const int *nIn, const int *nWin);
extern void sum_exact(double *In, double *Out, const int *nIn);

/* .Call calls */
extern SEXP imreadgif(SEXP, SEXP, SEXP);

static const R_CMethodDef CEntries[] = {
    {"cumsum_exact",   (DL_FUNC) &cumsum_exact,   3},
    {"imwritegif",     (DL_FUNC) &imwritegif,     5},
    {"run_mad",        (DL_FUNC) &run_mad,        5},
    {"run_max",        (DL_FUNC) &run_max,        4},
    {"run_mean",       (DL_FUNC) &run_mean,       4},
    {"run_mean_exact", (DL_FUNC) &run_mean_exact, 4},
    {"run_mean_lite",  (DL_FUNC) &run_mean_lite,  4},
    {"run_min",        (DL_FUNC) &run_min,        4},
    {"run_quantile",   (DL_FUNC) &run_quantile,   7},
    {"run_sd",         (DL_FUNC) &run_sd,         5},
    {"sum_exact",      (DL_FUNC) &sum_exact,      3},
    {NULL, NULL, 0}
};

static const R_CallMethodDef CallEntries[] = {
    {"imreadgif", (DL_FUNC) &imreadgif, 3},
    {NULL, NULL, 0}
};

void R_init_caTools(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
