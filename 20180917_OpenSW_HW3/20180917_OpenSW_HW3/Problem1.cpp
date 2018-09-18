#include <iostream>
using namespace std;

#define FOR(i, a) for(int i = 0; i < a; i++)

// return the index of max value in array
int indexOfMax(int* arr, int endIndex)
{
    int index = 0;
    int max = 0;

    for (int i = 0; i <= endIndex; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }

    return index;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble(int* arr, int a, int b)
{
    for (; a < b; a++)
        swap(arr[a], arr[a + 1]);
}

void printArr(int* arr)
{
    FOR(i, 5)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int T; // the number of test cases
    int N; // the size of array
    int* counts; // the number of repeat
    int maxIndex = 0; // the index of max value in array (for now)

    cout << "<Sample input>" << endl;

    cin >> T;

    counts = new int[T];

    FOR(j, T)	// round
    {
        counts[j] = 0;

        int* arr; // array

        cin >> N;
        arr = new int[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        //printArr(arr);

        maxIndex = N - 1;

        for (; maxIndex >= 0; maxIndex--)
        {
            //printArr(arr);

            int iMax = indexOfMax(arr, maxIndex);

            if (iMax != maxIndex)
            {
                bubble(arr, iMax, maxIndex);
                counts[j]++;
            }
        }

        delete[] arr;
    }

    cout << endl << "<Sample output>" << endl;

    FOR(i, T)
        cout << "Case #" << i + 1 << " : number of rounds = " << counts[i] << endl;

    return 0;
}