/*
    n개의 원소 중에서 k개를 순서 없이 선택하는 방법의 수는 몇 가지 일까?


입력
    입력은 하나 또는 그 이상의 테스트 케이스로 이루어져 있다.

    각 테스트 케이스는 한 줄로 이루어져 있으며, 2^31-1 을 넘지 않는 두 자연수 n(n ≥ 1)과 k(0 ≤ k ≤n)로 이루어져 있다.

    입력의 마지막 줄에는 0이 두 개 주어진다.


출력
    각 테스트 케이스에 대해서, 정답을 출력한다. 항상 정답이 2^31보다 작은 경우만 입력으로 주어진다.

*/

#include <iostream>
#include <vector>
using namespace std;

int combination(int n, int r)
{
    double a = (double)n, b = (double)r;
    double result = 1;

    double i, j;
    for (i = a, j = b; i > a - b; i--, j--)
        result = result * i / j;

    return (int)result;
}

int main()
{
    int x = 1, y = 1, z;   // x -> a, y -> b, z -> res
    vector<int> a, b, res;

    while ((x != 0) || (y != 0))
    {
        cin >> x >> y;
        if ((x == 0) && (y == 0)) break;

        a.push_back(x);
        b.push_back(y);

        res.push_back(combination(x, y));
    }

    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << endl;
}