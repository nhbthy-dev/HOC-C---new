#ifndef FRACTION_UTILS_H
#define FRACTION_UTILS_H

void reduce_fraction(int& numerator, int& denominator);
int compare_fractions(int n1, int d1, int n2, int d2);
void add_fractions(int n1, int d1,
                   int n2, int d2,
                   int& numerator, int& denominator);

#endif