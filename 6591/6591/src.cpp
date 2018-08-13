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

int main()
{
    int n = 1, r = 1;
    long result;
    vector<long> res;   // long�� �ƴ϶� int�� ���ϱ� Ʋ����

    while (true)
    {
        cin >> n >> r;
        if ((n == 0) && (r == 0)) break;

        if (n - r < r) r = n - r;    // ��� �ð� ������ ���� ���( n-r�� r���� ������ r�� n-r �ʱ�ȭ )

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