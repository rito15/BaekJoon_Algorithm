/*
    
입력
    첫째 줄에 미로의 크기를 나타내는 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)이 주어진다. 
    
    다음 N개의 줄에는 미로의 상태를 나타내는 숫자 0과 1이 주어진다. 0은 빈 방을 의미하고, 1을 벽을 의미한다.

    (1, 1)과 (N, M)은 항상 뚫려있다.

출력
    첫째 줄에 알고스팟 운영진이 (N, M)으로 이동하기 위해 벽을 최소 몇 개 부수어야 하는지 출력한다.

*/

#include <iostream>
#include <string>
using namespace std;

int M, N; // M : 가로 크기, N : 세로크기
int **map, **accum; // map : 0, 1로 표시된 전체 맵, accum : 누적값 저장하기 위한 맵

// 이동 불가능하면 true 리턴
bool cannotMove(int n, int m)
{
    if(n < 0 || m < 0) return true;
    if(n >= N || m >= M) return true;

    return false;
}

// (n_, m_) : 이전 좌표,  (n, m) : 현재 좌표, value : 현재까지의 누적값
void yeahhhh(int n_, int m_, int n, int m, int value)
{

    if(map[n][m] > 0)
    {
        value++;
        accum[n][m]++;
    }

    if(accum[n][m] > value) // 자기가 가진 누적 값이 누적 맵의 값보다 작은 경우
        accum[n][m] = value;
    else if(accum[n][m] <= value) // 누적 맵의 값보다 더 큰 값을 갖고 있는 경우
        return;

    if (n == N - 1 && m == M - 1) return;    // 도착지점 도달 시 종료

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

    if (!cannotMove(n + 1, m) && n_ != n + 1)   yeahhhh(n, m, n + 1, m, value);   // 남
    if (!cannotMove(n, m + 1) && m_ != m + 1)   yeahhhh(n, m, n, m + 1, value);   // 동
    if (!cannotMove(n - 1, m) && n_ != n - 1)   yeahhhh(n, m, n - 1, m, value);   // 북
    if (!cannotMove(n, m - 1) && m_ != m - 1)   yeahhhh(n, m, n, m - 1, value);   // 서
}

int main()
{
    string line; // 한 줄의 맵 입력(0과1로 이루어짐)

    cin >> M >> N;  // 입력부

    map = new int*[N];
    accum = new int*[N];

    for(int i = 0; i < N; i++)
    {
        map[i] = new int[M];
        accum[i] = new int[M];

        cin >> line;    // 맵 한 줄 입력

        for(int j = 0; j < M; j++)
        {
            map[i][j] = line[j] - '0';  // 맵 한 줄 저장
            accum[i][j] = 9999;            // 누적 맵 초기화
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