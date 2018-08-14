/*
    <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
    철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
    여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
    대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
    지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.


입력
    첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 
    그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
    첫 번째 줄에는 총 단지수를 출력하시오. 
    그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 지도의 크기
int **house; // N * N 사이즈의 집 배열
int **visited; // house와 같은 사이즈, 방문 여부 나타냄

int houses = 0; // 단지 내의 집 수

bool isVisited(int i, int j)    // 방문된 집이거나 집이 없는 곳이면 true 리턴
{
    if(i < 0 || j < 0) return true;
    if(i >= N || j >= N) return true;

    if(visited[i][j] == 0) return false;
    else return true;
}

void search(int i, int j)   // 재귀 방문
{
    if(!isVisited(i, j))
    {
        visited[i][j] = 1;
        houses++;
    }

    if (!isVisited(i - 1, j)) search(i - 1, j); // 북
    if (!isVisited(i + 1, j)) search(i + 1, j); // 남
    if (!isVisited(i, j - 1)) search(i, j - 1); // 서
    if (!isVisited(i, j + 1)) search(i, j + 1); // 동

}

int main()
{
    string line; // 입력받는 한 줄
    vector<int> complex; // 단지 내 집 수 기록

    cin >> N;       // 입력부

    house = new int*[N];
    visited = new int*[N];

    for(int i = 0; i < N; i++)
    {
        house[i] = new int[N];
        visited[i] = new int[N];
    }

    for(int i = 0; i < N; i++)
    {
        cin >> line;

        for(int j = 0; j < N; j++)
        {
            house[i][j] = line[j] - '0';

            if(house[i][j]) visited[i][j] = 0;
            else            visited[i][j] = -1;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            houses = 0;
            if (visited[i][j] == 0) // 방문하지 않은 곳만 탐색 시작
                search(i, j);

            if(houses > 0) 
                complex.push_back(houses);
        }
    }

    sort(complex.begin(), complex.end());   // 벡터 내 정렬

    cout << (int)complex.size() << endl;            // 결과 출력
    for(int i = 0; i < (int)complex.size(); i++)
        cout << complex[i] << endl;

    return 0;
}