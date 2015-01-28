#ifndef ZERO_CROSSING_H
#define ZERO_CROSSING_H

/* \fn double zero_crossing(double (*model)(double, void *), void *params, double *x_lo, double *x_hi)
 * \brief Find a zero crossing of the supplied model. */
double zero_crossing(double (*model)(double, void *), void *params, double *x_lo, double *x_hi);

#endif //ZERO_CROSSING_H
