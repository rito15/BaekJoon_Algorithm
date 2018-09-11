/*
        col 0 1 2
    row0	O O O
    row1	O O O
    row2	O O O
*/

#include <iostream>
using namespace std;

int N;			// Array Size(Row, Col)
int maxValue;	// To be found out
int **matrix;	// N * N matrix

typedef struct area
{
    // (col1, row1) ~ (col2, row2)
    int row1;
    int row2;
    int col1;
    int col2;

    area(int row1, int row2, int col1, int col2)
    {
        this->row1 = row1;
        this->row2 = row2;
        this->col1 = col1;
        this->col2 = col2;
    }
} area;

// In the specific area, sum of all elements
int sumOfArea(area& ar)
{
    int sum = 0;

    for (int i = ar.row1; i <= ar.row2; i++)
        for (int j = ar.col1; j <= ar.col2; j++)
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

    if (ar1.row1 + 1 <= ar1.row2 && ar1.col1 <= ar1.col2)
        findMax(maxArea, area(ar1.row1 + 1, ar1.row2, ar1.col1, ar1.col2));

    if (ar1.row1 <= ar1.row2 - 1 && ar1.col1 <= ar1.col2)
        findMax(maxArea, area(ar1.row1, ar1.row2 - 1, ar1.col1, ar1.col2));

    if (ar1.row1 <= ar1.row2 && ar1.col1 + 1 <= ar1.col2)
        findMax(maxArea, area(ar1.row1, ar1.row2, ar1.col1 + 1, ar1.col2));

    if (ar1.row1 <= ar1.row2 && ar1.col1 <= ar1.col2 - 1)
        findMax(maxArea, area(ar1.row1, ar1.row2, ar1.col1, ar1.col2 - 1));
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
    cout << maxArea.col1 << "-" << maxArea.col2 << ", ";
    cout << maxArea.row1 << "-" << maxArea.row2 << endl;

    return 0;
}