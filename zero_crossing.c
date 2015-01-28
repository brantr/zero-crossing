#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_roots.h>
#include <gsl/gsl_math.h>
#include "zero_crossing.h"

/* \fn double zero_crossing(double (*model)(double, void *), void *params, double *x_lo, double *x_hi)
 * \brief Find a zero crossing of the supplied model. */
double zero_crossing(double (*model)(double, void *), void *params, double *x_lo, double *x_hi)
{
	int status;
	int iter=0;
	int max_iter = 100;

	double x;	//root

	const gsl_root_fsolver_type *T;
	gsl_root_fsolver *s;

	gsl_function F;

	F.function = model;
	F.params   = params;

	T = gsl_root_fsolver_brent;
	s = gsl_root_fsolver_alloc(T);

	gsl_root_fsolver_set(s,&F, *x_lo, *x_hi);

	do{
		iter++;
		status = gsl_root_fsolver_iterate(s);
		x      = gsl_root_fsolver_root(s);

		*x_lo   = gsl_root_fsolver_x_lower(s);
		*x_hi   = gsl_root_fsolver_x_upper(s);

		status = gsl_root_test_interval(*x_lo, *x_hi,0,0.001);

		//printf("iter %d x_lo %e x %e x_hi %e\n",iter,*x_lo,x,*x_hi);
		
	}while((status==GSL_CONTINUE)&&(iter<max_iter));


	gsl_root_fsolver_free(s);

	return x;
}
