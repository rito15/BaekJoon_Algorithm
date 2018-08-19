/*
    M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�
    ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1��M��N��1,000,000)

���
    �� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.

*/

#include <iostream>
using namespace std;

int main()
{
    int M; // ����
    int N; // ����
    int *numbers; // 1~N ������ �ڿ����� �ϳ��� ���� ���� �迭

    cin >> M >> N;  // �Է�

    numbers = new int[N + 1];

    for(int i = 0; i <= N; i++)   // numbers[x]���� �ڿ��� x�� ��´�.
        numbers[i] = i;

    for(int i = 2; i <= N; i++)
    {
        if(M <= i && i <= N && numbers[i] != 0)
            cout << numbers[i] << endl;    // ���

        for(int j = i*2; j <= N; j += i)   // �� ������ ����� ��� 0���� �ʱ�ȭ
        {
            if(numbers[j] != 0)
                numbers[j] = 0;
        }
    }

    return 0;
}