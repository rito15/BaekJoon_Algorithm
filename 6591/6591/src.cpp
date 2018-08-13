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

int main()
{
    int n = 1, r = 1;
    long result;
    vector<long> res;   // long이 아니라 int를 쓰니까 틀린다

    while (true)
    {
        cin >> n >> r;
        if ((n == 0) && (r == 0)) break;

        if (n - r < r) r = n - r;    // 계산 시간 단축을 위해 사용( n-r이 r보다 작으면 r에 n-r 초기화 )

        result = 1;
        for (int i = 1; i <= r; i++, n--)
        {
            result *= n;
            result /= i;
        }

        res.push_back(result);
    }

    for (int i = 0; i < (int)res.size(); i++)
        cout << res[i] << endl;
}