#include <iostream>
#include <cmath>
#include "array_2d_utils.h"
#include "format_utils.h"
using namespace std;

// Hàm phụ: hoán đổi giá trị hai số nguyên
void swap_value(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort_ascending_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based) {
    if (row_based) {
        // Sắp xếp từng hàng
        for (int r = 0; r < rows; r++) {
            for (int i = 0; i < cols - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < cols; j++) {
                    if (arr[r][j] < arr[r][minIndex]) minIndex = j;
                }
                swap_value(arr[r][i], arr[r][minIndex]);
            }
        }
    } else {
        // Sắp xếp từng cột
        for (int c = 0; c < cols; c++) {
            for (int i = 0; i < rows - 1; i++) {
                int minIndex = i;
                for (int j = i + 1; j < rows; j++) {
                    if (arr[j][c] < arr[minIndex][c]) minIndex = j;
                }
                swap_value(arr[i][c], arr[minIndex][c]);
            }
        }
    }
}

void sort_descending_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based) {
    if (row_based) {
        for (int r = 0; r < rows; r++) {
            for (int i = 0; i < cols - 1; i++) {
                int maxIndex = i;
                for (int j = i + 1; j < cols; j++) {
                    if (arr[r][j] > arr[r][maxIndex]) maxIndex = j;
                }
                swap_value(arr[r][i], arr[r][maxIndex]);
            }
        }
    } else {
        for (int c = 0; c < cols; c++) {
            for (int i = 0; i < rows - 1; i++) {
                int maxIndex = i;
                for (int j = i + 1; j < rows; j++) {
                    if (arr[j][c] > arr[maxIndex][c]) maxIndex = j;
                }
                swap_value(arr[i][c], arr[maxIndex][c]);
            }
        }
    }
}

void swap_2d(int arr[][MAX_COLS], int rows, int cols,
             int first_index, int second_index, bool row_based) {
    if (row_based) {
        // Hoán vị hai hàng
        for (int j = 0; j < cols; j++) {
            swap_value(arr[first_index][j], arr[second_index][j]);
        }
    } else {
        // Hoán vị hai cột
        for (int i = 0; i < rows; i++) {
            swap_value(arr[i][first_index], arr[i][second_index]);
        }
    }
}

void transpose_2d(int arr[][MAX_COLS], int rows, int cols) {
    // Ma trận vuông: chỉ đổi phần tử phía trên đường chéo chính
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            swap_value(arr[i][j], arr[j][i]);
        }
    }
}

void reverse_2d(int arr[][MAX_COLS], int rows, int cols, bool row_based) {
    if (row_based) {
        // Đảo thứ tự các hàng
        for (int i = 0; i < rows / 2; i++) {
            for (int j = 0; j < cols; j++) {
                swap_value(arr[i][j], arr[rows - 1 - i][j]);
            }
        }
    } else {
        // Đảo thứ tự các cột
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols / 2; j++) {
                swap_value(arr[i][j], arr[i][cols - 1 - j]);
            }
        }
    }
}

void rotate_2d(int arr[][MAX_COLS], int rows, int cols, int n) {
    n = n % 4;   // xoay 4 lần là về lại ban đầu
    // Xoay phải 90° = chuyển vị, rồi đảo thứ tự các cột
    for (int k = 0; k < n; k++) {
        transpose_2d(arr, rows, cols);
        reverse_2d(arr, rows, cols, false);
    }
}