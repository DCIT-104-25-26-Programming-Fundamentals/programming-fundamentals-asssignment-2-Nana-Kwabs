// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;    
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE
][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE
][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    
    cout << "Part A: Transpose a Matrix" << endl;
    cout << "Enter number of rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter number of columns for matrix A: ";
    cin >> colsA;
    readMatrix(matrixA, rowsA, colsA);
    
    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrixA, transposed, rowsA, colsA);
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrixA, rowsA, colsA);
    
    cout << "Transposed Matrix:" << endl;
    printMatrix(transposed, colsA, rowsA);

    
    cout << "\nPart B: Add Two Matrices" << endl;
    cout << "Enter number of rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for matrix B: ";
    cin >> colsB;

    if (rowsA != rowsB || colsA != colsB) {
        cout << "Error: Matrices must be of the same size to add." << endl;
        return 1;
    }

    readMatrix(matrixB, rowsB, colsB);
    
    addMatrices(matrixA, matrixB, result, rowsA, colsA);
    
    cout << "Resultant Matrix after Addition:" << endl;
    printMatrix(result, rowsA, colsA);
    cout  << "\nPart C: Multiply Two Matrices" << endl;
    cout << "Enter number of rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for matrix B: ";
    cin >> colsB;
    if (colsA != rowsB) {
        cout << "Error: Number of columns in matrix A must equal number of rows in matrix B for multiplication." << endl;
        return 1;
    }   

    readMatrix(matrixB, rowsB, colsB);

    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);
    cout << "Resultant Matrix after Multiplication:" << endl;
    printMatrix(result, rowsA, colsB);

    return 0;
}