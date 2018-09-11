/*
row 0 1 2
col0	O O O
col1	O O O
col2	O O O
*/

#include <iostream>
using namespace std;

int N;			// Array Size(Col, Row)
int maxValue;	// what should be found out
int **matrix;	// N * N matrix

typedef struct area
{
    // (row1, col1) ~ (row2, col2)
    int col1;
    int col2;
    int row1;
    int row2;

    area(int col1, int col2, int row1, int row2)
    {
        this->col1 = col1;
        this->col2 = col2;
        this->row1 = row1;
        this->row2 = row2;
    }
} area;

// In the specific area, sum of all elements
int sumOfArea(area& ar)
{
    int sum = 0;

    for (int i = ar.col1; i <= ar.col2; i++)
        for (int j = ar.row1; j <= ar.row2; j++)
            sum += matrix[i][j];

    return sum;
}

// Max value between two areas
area max(area ar1, area ar2)
{
    if (sumOfArea(ar1) > sumOfArea(ar2))
        return ar1;
    else
        return ar2;
}

// Recursively find max value
void findMax(area& maxArea, area ar1)
{
    maxArea = max(maxArea, ar1);

    if (ar1.col1 + 1 <= ar1.col2 && ar1.row1 <= ar1.row2)
        findMax(maxArea, area(ar1.col1 + 1, ar1.col2, ar1.row1, ar1.row2));

    if (ar1.col1 <= ar1.col2 - 1 && ar1.row1 <= ar1.row2)
        findMax(maxArea, area(ar1.col1, ar1.col2 - 1, ar1.row1, ar1.row2));

    if (ar1.col1 <= ar1.col2 && ar1.row1 + 1 <= ar1.row2)
        findMax(maxArea, area(ar1.col1, ar1.col2, ar1.row1 + 1, ar1.row2));

    if (ar1.col1 <= ar1.col2 && ar1.row1 <= ar1.row2 - 1)
        findMax(maxArea, area(ar1.col1, ar1.col2, ar1.row1, ar1.row2 - 1));
}

int main()
{
    cout << "Input N : ";
    cin >> N;					// Input the first line

    matrix = new int*[N];

    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];

        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];	// Input the second line ~
    }

    area maxArea(0, N - 1, 0, N - 1);
    area ar(0, N - 1, 0, N - 1);

    findMax(maxArea, ar);

    cout << "Max value = " << sumOfArea(maxArea) << ", ";
    cout << "Position = ";
    cout << maxArea.row1 << "-" << maxArea.row2 << ", ";
    cout << maxArea.col1 << "-" << maxArea.col2 << endl;

    return 0;
}