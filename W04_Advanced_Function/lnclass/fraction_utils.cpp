#include <iostream>
#include "fraction_utils.h"
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void reduce_fraction(int& numerator, int& denominator) {
    if (numerator == 0) {
        denominator = 1;
        return;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int g = gcd(numerator, denominator);
    numerator = numerator / g;
    denominator = denominator / g;
}
int compare_fractions(int n1, int d1, int n2, int d2) {
    if (d1 < 0) {
        n1 = -n1;
        d1 = -d1;
    }
    if (d2 < 0) {
        n2 = -n2;
        d2 = -d2;
    }
    int x = n1 * d2;
    int y = n2 * d1;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
void add_fractions(int n1, int d1,
                   int n2, int d2,
                   int& numerator, int& denominator) {
    numerator = n1 * d2 + n2 * d1;
    denominator = d1 * d2;
    reduce_fraction(numerator, denominator);
}