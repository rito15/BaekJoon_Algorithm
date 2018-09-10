/*
    
�Է�
    ù° �ٿ� �̷��� ũ�⸦ ��Ÿ���� ���� ũ�� M, ���� ũ�� N (1 �� N, M �� 100)�� �־�����. 
    
    ���� N���� �ٿ��� �̷��� ���¸� ��Ÿ���� ���� 0�� 1�� �־�����. 0�� �� ���� �ǹ��ϰ�, 1�� ���� �ǹ��Ѵ�.

    (1, 1)�� (N, M)�� �׻� �շ��ִ�.

���
    ù° �ٿ� �˰��� ����� (N, M)���� �̵��ϱ� ���� ���� �ּ� �� �� �μ���� �ϴ��� ����Ѵ�.

*/

#include <iostream>
#include <string>
using namespace std;

int M, N; // M : ���� ũ��, N : ����ũ��
int **map, **accum; // map : 0, 1�� ǥ�õ� ��ü ��, accum : ������ �����ϱ� ���� ��

// �̵� �Ұ����ϸ� true ����
bool cannotMove(int n, int m)
{
    if(n < 0 || m < 0) return true;
    if(n >= N || m >= M) return true;

    return false;
}

// (n_, m_) : ���� ��ǥ,  (n, m) : ���� ��ǥ, value : ��������� ������
void yeahhhh(int n_, int m_, int n, int m, int value)
{

    if(map[n][m] > 0)
    {
        value++;
        accum[n][m]++;
    }

    if(accum[n][m] > value) // �ڱⰡ ���� ���� ���� ���� ���� ������ ���� ���
        accum[n][m] = value;
    else if(accum[n][m] <= value) // ���� ���� ������ �� ū ���� ���� �ִ� ���
        return;

    if (n == N - 1 && m == M - 1) return;    // �������� ���� �� ����

    /*
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(n == i && m == j)
                cout << "*";
            else
                cout << accum[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */

    if (!cannotMove(n + 1, m) && n_ != n + 1)   yeahhhh(n, m, n + 1, m, value);   // ��
    if (!cannotMove(n, m + 1) && m_ != m + 1)   yeahhhh(n, m, n, m + 1, value);   // ��
    if (!cannotMove(n - 1, m) && n_ != n - 1)   yeahhhh(n, m, n - 1, m, value);   // ��
    if (!cannotMove(n, m - 1) && m_ != m - 1)   yeahhhh(n, m, n, m - 1, value);   // ��
}

int main()
{
    string line; // �� ���� �� �Է�(0��1�� �̷����)

    cin >> M >> N;  // �Էº�

    map = new int*[N];
    accum = new int*[N];

    for(int i = 0; i < N; i++)
    {
        map[i] = new int[M];
        accum[i] = new int[M];

        cin >> line;    // �� �� �� �Է�

        for(int j = 0; j < M; j++)
        {
            map[i][j] = line[j] - '0';  // �� �� �� ����
            accum[i][j] = 9999;            // ���� �� �ʱ�ȭ
        }
    }

    yeahhhh(-1, -1, 0, 0, 0);
    
    /*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
                cout << accum[i][j];
        }
        cout << endl;
    }
    cout << endl;
    */

    cout << accum[N-1][M-1];

    return 0;
}