/*
    M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.


입력
    첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1≤M≤N≤1,000,000)

출력
    한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

*/

#include <iostream>
using namespace std;

int main()
{
    int M; // 하한
    int N; // 상한
    int *numbers; // 1~N 범위의 자연수를 하나씩 갖는 정수 배열

    cin >> M >> N;  // 입력

    numbers = new int[N + 1];

    for(int i = 0; i <= N; i++)   // numbers[x]에는 자연수 x를 담는다.
        numbers[i] = i;

    for(int i = 2; i <= N; i++)
    {
        if(M <= i && i <= N && numbers[i] != 0)
            cout << numbers[i] << endl;    // 출력

        for(int j = i*2; j <= N; j += i)   // 각 숫자의 배수는 모두 0으로 초기화
        {
            if(numbers[j] != 0)
                numbers[j] = 0;
        }
    }

    return 0;
}