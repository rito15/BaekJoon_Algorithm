/*
    효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 
    효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.

    1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 
       마신 후에는 원래 위치에 다시 놓아야 한다.

    2.연속으로 놓여 있는 3잔을 모두 마실 수는 없다.

    효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 
    1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 
    각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 
    효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 

    예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 
    첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.
*/

#define MAX(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))
#include <iostream>
using namespace std;

int main()
{
    int n;       // 잔의 개수 (입력 받음)
    int *wine;   // 포도주 배열
    int *sum;    // 포도주 누적(지금까지 마신거)
    bool *drink; // 해당 번호의 포도주를 마셨는지

    cin >> n;
    wine = new int[n + 1];
    sum = new int[n + 1];
    drink = new bool[n + 1];

    for(int i = 1; i <= n; i++)
        cin >> wine[i];

    sum[0] = wine[0] = 0; drink[0] = false; // 0번은 없는놈
    sum[1] = wine[1]; drink[1] = true;

    if(n > 1)
    {
        sum[2] = wine[1] + wine[2];
        drink[2] = true;

        for(int i = 3; i <= n; i++)
        {
            if(drink[i - 2] && drink[i - 1])        // [마심] [마심] [현재]
            {
                cout << "여기 -- " << i << endl << endl;
                if(sum[i - 1] > sum[i - 1] - wine[i - 2] + wine[i])   // [마심] [마심] [안마심] 이 [안마심] [마심] [마심] 보다 클경우
                {
                    if(sum[i - 1] > sum[i - 1] - wine[i - 1] + wine[i]) // [마심] [안마심] [마심] 보다도 클 경우
                    {
                        drink[i] = false;
                        sum[i]   = sum[i - 1];    // [마심] [마심] [안마심] 종결 *1
                        cout << "여기 -- (1)" << i << endl << endl;
                    }

                    else
                    {
                        drink[i]     = true;
                        drink[i - 1] = false;
                        sum[i]       = sum[i - 1] - wine[i - 1] + wine[i]; // [마심] [안마심] [마심] 종결 *2
                        cout << "여기 -- (2)" << i << endl << endl;
                    }
                }

                else  // [마심] [마심] [안마심] 이 작을 경우
                {
                    // [마심] [안마심] [마심] 이 [안마심] [마심] [마심] 보다 더 클 경우
                    if (sum[i - 1] - wine[i - 1] + wine[i] > sum[i - 1] - wine[i - 2] + wine[i])
                    {
                        drink[i] = true;
                        drink[i - 1] = false;
                        sum[i] = sum[i - 1] - wine[i - 1] + wine[i]; // [마심] [안마심] [마심] 종결 *2
                        cout << "여기 -- (3)" << i << endl << endl;
                    }

                    else
                    {
                        drink[i] = true;
                        drink[i - 2] = false;
                        sum[i] = sum[i - 1] - wine[i - 2] + wine[i]; // [안마심] [마심] [마심] 종결 *3
                        cout << "여기 -- (4)" << i << endl << endl;
                    }
                }

            }

            else  // [안마심] [마심] [현재]  또는  [마심] [안마심] [현재] -> 현재 시행은 무조건 마심
            {
                drink[i] = true;
                sum[i]   = sum[i - 1] + wine[i];
            }

            for (int a = 1; a <= i; a++)
                cout << "[" << a << "] " << drink[a] << "[sum] - " << sum[a] << endl;
            cout << endl;

            if((i > 3) && !drink[i - 3] && !drink[i - 2])   // [안마심] [안마심] [마심] [현재] 꼴 되는 경우 [안마심] 둘 중 하나 택
            {
                if(wine[i - 3] > wine[i - 2] || drink[i])   // i - 3 이 i - 2보다 더 크거나 [안][안][마][마] 꼴인 경우
                {
                    drink[i - 3] = true;
                    sum[i]       = sum[i] + wine[i - 3];
                }

                else
                {
                    drink[i - 2] = true;
                    sum[i]       = sum[i] + wine[i - 2];
                }
            }

            

            for (int a = 1; a <= i; a++)
                cout << "[" << a << "] " << drink[a] << "[sum] - " << sum[a] << endl;
            cout << endl;
        }
    }

    cout << endl;

    for(int i = 1; i <= n; i++)
        cout << "[" << i << "] " << drink[i] << endl;

    cout << sum[n] << endl;

    return 0;
}