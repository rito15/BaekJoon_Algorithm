/*
    M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�
    ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1��M��N��1,000,000)

���
    �� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.

*/

#include <iostream>
using namespace std;

// 1 - �̸� 100������ �Ҽ��� ��� ���س��� ���

int main()
{
    int M; // ����
    int N; // ����
    bool *numbers; 

    numbers = new bool[1000001];

    for(int i = 0; i <= 1000000; i++)
        numbers[i] = true;
    numbers[1] = false;

    for(int i = 2; i <= 1000000; i++)
    {
        for(int j = i*2; j <= 1000000; j += i)   // �����佺�׳׽��� ü
        {
            if(numbers[j] == true)
                numbers[j] = false;
        }
    }

    cin >> M >> N;  // �Է�

    for(int i = M; i <= N; i++)
    {
        if (numbers[i] == true)
            printf("%d\n", i);    // ��� -> cout�� �ð��ʰ� �� ��
    }

    return 0;
}

/*  2 - �̰͵� ���� : M, N�� ��� �Է¹��� ��, N������ �Ҽ��� ���ϸ� �� ���ึ�� �ﰢ �Ҽ��� ����ϴ� ���

int main()
{
    int M; // ����
    int N; // ����
    bool *numbers;

    cin >> M >> N;  // �Է�

    numbers = new bool[N + 1];

    for (int i = 0; i <= N; i++)
        numbers[i] = true;
    numbers[1] = false;

    for (int i = 2; i <= N; i++)
    {
        if (M <= i && numbers[i])
            printf("%d\n", i);

        for (int j = i * 2; j <= N; j += i)
        {
            if (numbers[j])
                numbers[j] = false;
        }
    }

    return 0;
}
*/