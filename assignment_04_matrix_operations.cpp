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


#include <iostream>
#include <iomanip>
using namespace std;


// Function to display a matrix neatly
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


// PART A: Function to transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);
}


// PART B: Function to add two matrices
void addMatrices(int matrixA[10][10], int matrixB[10][10],
                 int rows, int cols)
{
    int result[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nMatrix Addition Result:" << endl;
    displayMatrix(result, rows, cols);
}


// PART C: Function to multiply two matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                      int rowsA, int colsA, int rowsB, int colsB)
{
    if (colsA != rowsB)
    {
        cout << "\nMatrix multiplication is not possible." << endl;
        return;
    }

    int result[10][10] = {0};

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nMatrix Multiplication Result:" << endl;
    displayMatrix(result, rowsA, colsB);
}


int main()
{
    int matrixA[10][10];
    int matrixB[10][10];

    int rows, cols;

    // Input matrix size
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;


    // Validate size
    if (rows > 10 || cols > 10 || rows <= 0 || cols <= 0)
    {
        cout << "Error: Matrix size must be between 1 and 10." << endl;
        return 0;
    }


    // Read Matrix A
    cout << "\nEnter elements of Matrix A:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixA[i][j];
        }
    }


    cout << "\nOriginal Matrix A:" << endl;
    displayMatrix(matrixA, rows, cols);


    // PART A
    transposeMatrix(matrixA, rows, cols);



    // Read Matrix B for addition
    cout << "\nEnter elements of Matrix B for addition:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }


    // PART B
    addMatrices(matrixA, matrixB, rows, cols);



    // PART C
    int rowsB, colsB;

    cout << "\nEnter number of rows for Matrix B (multiplication): ";
    cin >> rowsB;

    cout << "Enter number of columns for Matrix B (multiplication): ";
    cin >> colsB;


    if (rowsB > 10 || colsB > 10 || rowsB <= 0 || colsB <= 0)
    {
        cout << "Error: Matrix size must be between 1 and 10." << endl;
        return 0;
    }


    cout << "\nEnter elements of Matrix B for multiplication:" << endl;

    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrixB[i][j];
        }
    }


    multiplyMatrices(matrixA, matrixB, rows, cols, rowsB, colsB);


    return 0;
}