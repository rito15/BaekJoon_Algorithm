/*
    n���� ���� �߿��� k���� ���� ���� �����ϴ� ����� ���� �� ���� �ϱ�?


�Է�
    �Է��� �ϳ� �Ǵ� �� �̻��� �׽�Ʈ ���̽��� �̷���� �ִ�.

    �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, 2^31-1 �� ���� �ʴ� �� �ڿ��� n(n �� 1)�� k(0 �� k ��n)�� �̷���� �ִ�.

    �Է��� ������ �ٿ��� 0�� �� �� �־�����.


���
    �� �׽�Ʈ ���̽��� ���ؼ�, ������ ����Ѵ�. �׻� ������ 2^31���� ���� ��츸 �Է����� �־�����.

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