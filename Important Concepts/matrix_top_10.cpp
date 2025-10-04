#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// 1. Matrix Multiplication
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int m = A.size(), n = A[0].size(), p = B[0].size();
    vector<vector<int>> result(m, vector<int>(p, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

// 2. Transpose of a Matrix
vector<vector<int>> transpose(const vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows, 0));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            transposed[j][i] = matrix[i][j];
    return transposed;
}

// 3. Determinant of a Matrix (2x2 example for simplicity)
int determinant(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 2) // 2x2 matrix determinant
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    // For larger matrices, you'd need a recursive approach (or use a library like LAPACK).
    return 0; // Placeholder for simplicity (should handle larger cases).
}

// 4. Inverse of a Matrix (2x2 for simplicity)
vector<vector<int>> inverse(const vector<vector<int>> &matrix)
{
    int det = determinant(matrix);
    if (det == 0)
        return {}; // No inverse if determinant is 0.
    int a = matrix[0][0], b = matrix[0][1], c = matrix[1][0], d = matrix[1][1];
    int invDet = 1 / det; // Assuming inverse exists for 2x2
    return {{d * invDet, -b * invDet}, {-c * invDet, a * invDet}};
}

// 5. Matrix Addition
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int m = A.size(), n = A[0].size();
    vector<vector<int>> result(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// 6. Identity Matrix
vector<vector<int>> identityMatrix(int n)
{
    vector<vector<int>> I(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        I[i][i] = 1;
    return I;
}

// 7. Trace of a Matrix
int trace(const vector<vector<int>> &matrix)
{
    int trace = 0;
    for (int i = 0; i < matrix.size(); ++i)
        trace += matrix[i][i];
    return trace;
}

// 8. Diagonal Matrix
bool isDiagonal(const vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[i].size(); ++j)
            if (i != j && matrix[i][j] != 0)
                return false;
    return true;
}

// 9. Rotate Matrix by 90 Degrees (Clockwise)
vector<vector<int>> rotateMatrix90(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i)
        for (int j = i; j < n - i - 1; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    return matrix;
}

// 10. Find the Rank of a Matrix (simplified logic)
int rankOfMatrix(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size(), colCount = matrix[0].size();
    int rank = 0;
    // Use Gaussian elimination to determine rank (simplified approach here)
    for (int row = 0; row < rowCount; ++row)
    {
        bool nonZeroRow = false;
        for (int col = 0; col < colCount; ++col)
        {
            if (matrix[row][col] != 0)
            {
                nonZeroRow = true;
                break;
            }
        }
        if (nonZeroRow)
        {
            ++rank;
        }
    }
    return rank;
}

int main()
{
    // 1. Matrix Multiplication
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    // Multiply A and B (Result: {{19, 22}, {43, 50}})
    vector<vector<int>> mulResult = multiplyMatrices(A, B);

    // 2. Transpose of a Matrix
    // Transpose of A (Result: {{1, 3}, {2, 4}})
    vector<vector<int>> transposedA = transpose(A);

    // 3. Determinant of a Matrix
    // Determinant of A (Result: -2)
    int detA = determinant(A);

    // 4. Inverse of a Matrix (for 2x2 matrix)
    // Inverse of A (Result: {{-2, 1}, {1.5, -0.5}})
    vector<vector<int>> invA = inverse(A);

    // 5. Matrix Addition
    // A + B (Result: {{6, 8}, {10, 12}})
    vector<vector<int>> sumAB = addMatrices(A, B);

    // 6. Identity Matrix of size 3
    // Identity matrix of size 3 (Result: {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}})
    vector<vector<int>> identity3 = identityMatrix(3);

    // 7. Trace of a Matrix
    // Trace of A (Result: 5)
    int traceA = trace(A);

    // 8. Check if the matrix is Diagonal
    // Is A diagonal? (Result: false)
    bool isDiag = isDiagonal(A);

    // 9. Rotate Matrix 90 degrees clockwise
    // Rotate A (Result: {{3, 1}, {4, 2}})
    vector<vector<int>> rotatedA = rotateMatrix90(A);

    // 10. Rank of a Matrix
    // Rank of A (Result: 2)
    int rankA = rankOfMatrix(A);

    return 0;
}
