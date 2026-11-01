#include <iostream>
#include <cmath>
#include "array_1d_utils.h"
#include "format_utils.h"
long long compute_array(int arr[], int n, char op ) {
    long long result;
    if (op == '*') result = 1;
    if (op == '+') result = 0;
    for (int i = 0; i<n ; i++) {
        if (op == '+') {
            result +=arr[i];
        }
        if (op == '*') {
            result*=arr[i];
        }
    }
    return result;
}
float compute_mean(int arr[], int n) {
    float result = 0;
    for (int i = 0; i<n; i++) {
        result+=arr[i];
    }
    result/=n;
    return round_to_decimal (result,2);
}
float compute_median(int arr[], int n) {
    int* tmp = new int[n];
    for (int i = 0; i<n; i++) tmp[i] = arr[i];
    sort_ascending(tmp, n);

    double trungvi;
    if (n%2!=0) trungvi=tmp[n/2];
    else trungvi = (tmp[n/2]+tmp[(n/2)-1])/2.0;         

    delete[] tmp;
    return round_to_decimal(trungvi,2);
    }
int get_max_min(int arr[], int n, bool max ) {
    int value = arr[0];
    if (max) {
        for (int i=0; i<n ; i++) {
            if (arr[i]>value) value = arr[i];
        }
    }
    else {
        for (int i = 0; i<n ; i++) {
            if (arr[i]<value) value = arr[i];
        }
    }
    return value;
}
void sort_ascending(int arr[], int n) {
    for (int i=0; i<n ; i++) {
        int minIndex = i;
        for (int j=i+1 ; j<n ; j++) {
            if (arr[j]<arr[minIndex]) minIndex = j;
        }
        int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
    }
}
void sort_descending(int arr[], int n) {
    for (int i=0; i<n ; i++) {
        int maxIndex = i;
        for (int j=i+1 ; j<n ; j++) {
            if (arr[j]>arr[maxIndex]) maxIndex = j;
        }
        int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
    }
}