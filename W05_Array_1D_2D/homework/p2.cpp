#include <iostream>
#include <cmath>
#include "array_2d_utils.h"
#include "format_utils.h"
using namespace std;
void input_2d(int arr[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i<rows ; i++) {
        for (int j = 0 ; j<cols ; j++) {
            cin>>arr[i][j];
        }
    }
}
void print_2d(int arr[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i<rows ; i++) {
        for (int j = 0 ; j<cols ; j++) {
            cout<<arr[i][j]<<" ";
        }
    }
}
bool check_exist(int arr[][MAX_COLS], int rows, int cols, int value) {
    for (int i = 0; i<rows ; i++) {
        for (int j = 0 ; j<cols ; j++) {
            if (arr[i][j]==value) return true;
        }
    }
    return false;
}
long long compute_2d(int arr[][MAX_COLS], int rows, int cols, char op) {
    long long result;
    if (op == '*') result = 1;
    if (op == '+') result = 0;
    for (int i = 0; i<rows ; i++) {
        for (int j = 0 ; j<cols ; j++) {
            if (op == '*') result*=arr[i][j];
            if (op == '+') result+=arr[i][j];
        }
    }
    return result;
}
float compute_mean_2d(int arr[][MAX_COLS], int rows, int cols) {
    float result = 0;
    for (int i = 0; i<rows ; i++) {
        for (int j = 0 ; j<cols ; j++) {
            result+=arr[i][j];
        }
    }
    result = result/(rows * cols);
    return round_to_decimal(result,2);
}

int get_max_min_2d(int arr[][MAX_COLS], int rows, int cols, bool max ) {
    int value = arr[0][0];
    for (int i = 0; i<rows ; i++) {
        for (int j = 0 ; j<cols ; j++) {
            if (max) {
                if (arr[i][j]>value) value = arr[i][j];
            }
            else {
                if (arr[i][j]<value) value = arr[i][j];
            }
        }
    }
    return value;
}