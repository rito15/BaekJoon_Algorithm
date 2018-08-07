/*      좋은 수열       */

/*  입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.
*/

/*  출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내는 수열만 출력한다.
수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N; // 수열 길이 (1~80), 입력받음
    string seq = "1"; // 길이 N만큼의 수열. 1, 2, 3으로만 이루어진다.
    bool flag = false; // true : 나쁜 수열에 해당됨

    int chkPoint = 0; // 무한루프 지점

    cin >> N; // 입력

              //i = 현재 수열의 길이
    for (int i = 2; i <= N; i++)
    {
        if (flag)
        {
            if (seq[i - 3] == '1')
                seq += '2';

            else if (seq[i - 3] == '2')
                seq += '3';

            else
                seq += '1';

            flag = false;
        }

        else
            seq += '1';

        for (int m = 1; (i - (m * 2) >= 0) && !flag; m++)
        {
            if (seq.substr(i - m, m) == seq.substr(i - (m * 2), m))
            {
                if (seq[i - 1] == '1')
                    seq[i - 1] = '2';

                else if (seq[i - 1] == '2')
                    seq[i - 1] = '3';

                else
                {
                    if (i != chkPoint)
                    {
                        seq.erase(i - 2, 2);
                        i -= 2;
                    }

                    else
                    {
                        seq.erase(i - 3, 3);
                        i -= 3;
                    }

                    flag = true;
                    chkPoint = i + 2;

                }
                m = 0;
            }
        }

    }

    cout << seq; // 출력

    return 0;
}