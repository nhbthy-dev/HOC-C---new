#include<iostream>
#include<cmath>
#include "array_2d_utils.h"
#include "format_utils.h"
void swamp (int& a, int& b) {
    int temp = a;
        a = b;
        b = temp;
}
void sort_ascending_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based ) {
    if (row_based) {
        for (int r=0; r<rows;r++) {
            for (int i = 0; i<cols-1; i++) {
                int mindex = i;
                for (int j=i+1; j<cols;j++) {
                    if (arr[r][j]<arr[r][mindex]) mindex = j;
                }
                swamp (arr[r][i],arr[r][mindex]);
            }
        }
    }
    else {
        for (int c=0; c<cols;c++) {
            for (int i = 0; i<rows-1; i++) {
                int mindex = i;
                for (int j=i+1; j<rows;j++) {
                    if (arr[j][c]<arr[mindex][c]) mindex = j;
                }
                swamp (arr[i][c],arr[mindex][c]);
            }
        }
    }
}
void sort_descending_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based ) {
    if (row_based) {
        for (int r=0; r<rows;r++) {
            for (int i = 0; i<cols-1; i++) {
                int maxdex = i;
                for (int j=i+1; j<cols;j++) {
                    if (arr[r][j]>arr[r][maxdex]) maxdex = j;
                }
                swamp (arr[r][i],arr[r][maxdex]);
            }
        }
    }
    else {
        for (int c=0; c<cols;c++) {
            for (int i = 0; i<rows-1; i++) {
                int maxdex = i;
                for (int j=i+1; j<rows;j++) {
                    if (arr[j][c]>arr[maxdex][c]) maxdex = j;
                }
                swamp (arr[i][c],arr[maxdex][c]);
            }
        }
    }
}
void swap_2d(int arr[][MAX_COLS], int rows, int cols,int first_index, int second_index, bool row_based ){
    if (row_based) {
        for (int j=0;j<cols;j++) {
            swamp (arr[first_index][j],arr[second_index][j]);
        }
    }
    else {
        for (int i=0;i<rows;i++) {
            swamp (arr[i][first_index],arr[i][second_index]);
        }
    }
}
void transpose_2d(int arr[][MAX_COLS], int rows, int cols) {
    for (int i=0 ;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            swamp (arr[i][j],arr[j][i]);
        }
    }
}
void rotate_2d(int arr[][MAX_COLS], int rows, int cols, int n) {
    n%=4;
    transpose_2d(arr,rows,cols);
    reverse_2d(arr,rows,cols,false);
}
void reverse_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based ){
    if (row_based) {
        for (int i=0; i<rows/2 ; i++) {
            for (int j=0 ; j<cols ; j++) {
                swamp (arr [i][j],arr[rows-i][j]);
            }
        }
    }
    else {
        for (int j= 0 ; j< cols/2;j++) {
            for (int i=0 ; i<rows ; i++) {
                swamp (arr [i][j],arr[i][cols-j]);
            }
        }
    }
}