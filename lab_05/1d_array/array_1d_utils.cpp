#include <iostream>
#include <cmath>
#include <array_1d_utils.h>
#include <format_utils.h>
long long compute_array (int arr[],int n, char op ) {
    long long result;
    if (op == '+') result = 0;
    if (op == '*') result = 1;
    for (int i = 0 ; i<n ; i++) {
        if (op == '+') {
            result+=arr[i];
        }
        if (op == '*') {
            result*=arr[i];
        }
    }
    return result;
}
float compute_mean(int arr[], int n) {
    float result = 0 ;
    for (int i = 0 ; i<n ; i++) {
        result+=arr[i];
    }
    result/=2.0;
    return round_to_decimal(result,2);
}
float compute_median(int arr[], int n) {
    sort_ascending (arr,n);
    float res = 0;
    if (n%2!=0) res = arr[n/2] / 2.0;
    else res = (arr [(n/2)-1] + arr [n/2])/2.0;
    return round_to_decimal(res,2);
}
int get_max_min(int arr[], int n, bool max ) {
    int value = arr[0];
    for (int i = 0 ; i<n ; i++) {
        if (max) {
            if (arr[i]>value) value = arr[i];
        }
        else {
            if (arr[i]<value) value = arr[i];
        }
    }
    return value;

}
void sort_ascending(int arr[], int n) {
    for (int i = 0; i<n-1; i++) {
        int minIndex = i;
        for (int j=i+1; j<n;j++) {
            if (arr[j]<arr[minIndex]) minIndex =i;
        }
        int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
    }
}
void sort_descending(int arr[], int n) {
    for (int i = 0; i<n-1; i++) {
        int maxIndex = i;
        for (int j=i+1; j<n;j++) {
            if (arr[j]>arr[maxIndex]) maxIndex =i;
        }
        int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
    }
}