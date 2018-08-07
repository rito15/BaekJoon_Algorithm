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

#include <iostream>
using namespace std;

int minIndex(int R, int G, int B) // 3개의 값 중 최솟값의 인덱스를 리턴
{
    if(R < G)
    {
        if(R < B) return 0;
        else return 2;
    }
    else
    {
        if(G < B) return 1;
        else return 2;
    }
}

int minIndex(int c0, int c1) // 2개의 값 중 최솟값의 인덱스를 리턴
{
    if(c0 < c1) return 0;
    else return 1;
}

int main()
{
    int N; // 집의 수( <= 1000)
    int **costs; // 페인트칠 비용([0] = R, [1] = G, [2] = B
    int rgb; // 이전 인덱스에서 R, G, B 중 최솟값을 가졌던 RGB 기억(0, 1, 2 중 하나)
    int sum[3]; // 전체 비용의 합(첫째 집을 R, G, B 중 작은 두 개로 각각 칠했을 때의 합 구하기)
    int case_[2]; // 첫 번째 집에서 R, G, B 중 작은 두 개의 경우 인덱스

    cin >> N; // 첫째 줄 입력 (집의 수)

    costs = new int*[N];        // 동적 할당 ( 3 * N 배열)
    for(int i = 0; i < N; i++)
        costs[i] = new int[3];

    for(int i = 0; i < N*3; i++)    // 둘째 줄부터 비용 입력
        cin >> costs[i/3][i%3];

    
    case_[0] = minIndex(costs[0][0], costs[0][1], costs[0][2]);
    case_[1] = ((case_[0] + 1) % 3) < ((case_[0] + 2) % 3) ? ((case_[0] + 1) % 3) : ((case_[0] + 2) % 3);

    
    for(int i = 0; i < 3; i++)
    {
        sum[i] = 0; // 초기화

        if((i != case_[0]) && (i != case_[1]))
            continue;

        rgb = i;
        sum[i] += costs[0][rgb];

        for(int j = 1; j < N; j++)  // index = 1부터 N-1 까지 탐색
        {
            rgb = minIndex(costs[j][(rgb + 1) % 3], costs[j][(rgb + 2) % 3]); // 이전 이웃에 칠해진 색상 제외, 2개 중 최소 색상
            sum[i] += costs[j][rgb];
        }
    }

    cout << sum[minIndex(sum[case_[0]], sum[case_[1]])];

    cout << endl << case_[0] << "|" << case_[1] << endl;

    return 0;
}