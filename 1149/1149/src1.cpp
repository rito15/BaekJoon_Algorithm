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

#define MIN(a,b,c) ((a) < (c) ? ((a) < (b) ? (a) : (b)) : ((b) < (c) ? (b) : (c)))

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
    int **costs; // 페인트칠 비용([0] = R, [1] = G, [2] = B
    int rgb; // 이전 인덱스에서 R, G, B 중 최솟값을 가졌던 RGB 기억(0, 1, 2 중 하나)
    int sum[3]; // 전체 비용의 합(첫째 집을 R, G, B 중 작은 두 개로 각각 칠했을 때의 합 구하기)

    cin >> N; // 첫째 줄 입력 (집의 수)

    costs = new int*[N];        // 동적 할당 ( 3 * N 배열)
    for(int i = 0; i < N; i++)
        costs[i] = new int[3];

    for(int i = 0; i < N*3; i++)    // 둘째 줄부터 비용 입력
        cin >> costs[i/3][i%3];

    for(int i = 0; i < 3; i++)
    {
        sum[i] = 0; // 초기화

        rgb = i;
        sum[i] += costs[0][rgb];

        for(int j = 1; j < N; j++)  // index = 1부터 N-1 까지 탐색
        {
            rgb = minIndex((rgb + 1) % 3, (rgb + 2) % 3, costs[j][(rgb + 1) % 3], costs[j][(rgb + 2) % 3]); // 이전 이웃에 칠해진 색상 제외, 2개 중 최소 색상
            sum[i] += costs[j][rgb];
        }
    }

    cout << MIN(sum[0], sum[1], sum[2]);

    return 0;
}