/*
    M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.


입력
    첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1≤M≤N≤1,000,000)

출력
    한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

*/

#include <iostream>
using namespace std;

// 1 - 미리 100만까지 소수를 모두 구해놓는 방식

int main()
{
    int M; // 하한
    int N; // 상한
    bool *numbers; 

    numbers = new bool[1000001];

    for(int i = 0; i <= 1000000; i++)
        numbers[i] = true;
    numbers[1] = false;

    for(int i = 2; i <= 1000000; i++)
    {
        for(int j = i*2; j <= 1000000; j += i)   // 에라토스테네스의 체
        {
            if(numbers[j] == true)
                numbers[j] = false;
        }
    }

    cin >> M >> N;  // 입력

    for(int i = M; i <= N; i++)
    {
        if (numbers[i] == true)
            printf("%d\n", i);    // 출력 -> cout은 시간초과 뜸 ㅗ
    }

    return 0;
}

/*  2 - 이것도 정답 : M, N을 모두 입력받은 뒤, N까지만 소수를 구하며 매 시행마다 즉각 소수를 출력하는 방식

int main()
{
    int M; // 하한
    int N; // 상한
    bool *numbers;

    cin >> M >> N;  // 입력

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