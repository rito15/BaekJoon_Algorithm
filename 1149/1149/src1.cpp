/*

RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 
또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 

집 i의 이웃은 집 i-1과 집 i+1이다. 처음 집과 마지막 집은 이웃이 아니다.

각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때, 
모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.


입력

첫째 줄에 집의 수 N이 주어진다. N은 1,000보다 작거나 같다. 
둘째 줄부터 N개의 줄에 각 집을 빨강으로 칠할 때, 초록으로 칠할 때, 파랑으로 칠할 때 드는 비용이 주어진다. 
비용은 1,000보다 작거나 같은 자연수이다.

출력

첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다.

*/

#define MIN_3(a,b,c) ((a) < (c) ? ((a) < (b) ? (a) : (b)) : ((b) < (c) ? (b) : (c)))
#define MIN_2(a,b) ( (a) < (b) ? (a) : (b) )

#include <iostream>
using namespace std;

int minIndex(int i0, int i1, int value0, int value1) // 2개의 값 중 최솟값의 인덱스를 리턴
{
    if(value0 < value1) return i0;
    else return i1;
}

int main()
{
    int N; // 집의 수( <= 1000)
    int **cost; // 페인트칠 비용([0] = R, [1] = G, [2] = B
    int **sum; // 현재 해당 위치의 cost와 바로 직전 두 개(현재 위치의 색상과 다른 두 개)의 누적값 중 min값 을 더해 누적한 비용

    cin >> N; // 첫째 줄 입력 (집의 수)

    cost = new int*[N + 1];        // 동적 할당 ( 3 * (N+1) 배열)
    sum = new int*[N + 1];
    for(int i = 0; i < N + 1; i++)
    {
        cost[i] = new int[3];
        sum[i] = new int[3];
    }

    for(int i = 0; i < 3; i++)  // 0번지는 0으로 초기화 (이전 값을 누적하므로, 1번지의 sum이 1번지의 cost와 같도록 하기 위해 필요)
    {
        cost[0][i] = 0;
        sum[0][i] = 0;
    }

    for(int i = 3; i < (N+1)*3; i++)    // 둘째 줄부터 비용 입력
        cin >> cost[i/3][i%3];

    for(int i = 1; i < N + 1; i++)
    {
        for (int j = 0; j < 3; j++)
            sum[i][j] = MIN_2(sum[i - 1][(j + 1) % 3], sum[i - 1][(j + 2) % 3]) + cost[i][j];

        /*  
            N번째 집을 칠할 때 N-1번째 집의 색상을 고려하여 나머지 두 색상 중 비용이 적은 것을 선택하는 것이 아니라,
            나머지 두 색상 중 하나를 선택하되 "지금까지의 누적 비용이 더 적은" 색상을 선택하는 DP 방식

            ** 정확히 서술하자면, N번째의 sum에서는, 일단 해당 색상(j)의 cost를 선택했으며
               결과론적으로, 적은 비용의 경로를 택한다면 이전 색상은 나머지 두 개 중 어떤 것이었을지 선택하는 방식

               예를 들면, sum[3][j = 0~2]가 각각 RGR, GRG, BRB라고 할 때, sum[4][0]을 결정할 때
               일단 cost[4][0]을 선택하기로 결정한 상태에서 sum[3][j = 1~2], 즉 GRG, BRB 중 하나를 선택하여 값을 더하고
               GRGR 또는 BRBR을 완성하여 결과론적으로 쌓아가는 형태
        */
    }

    cout << MIN_3(sum[N][0], sum[N][1], sum[N][2]);

    return 0;
}