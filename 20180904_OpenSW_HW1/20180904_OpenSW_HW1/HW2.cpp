#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> a;
    int n; // a의 크기
    int i1 = 0, i2 = 0, i3 = 0;	// 3개의 인덱스
    string input;
    bool found = false; // 찾았는지 여부

    cout << "정수 배열 A의 크기(N) = ";
    cin >> n;

    cout << "정수 배열 A의 원소 입력 = ";

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    for (i1 = 0; i1 < n - 2; i1++)
    {
        for (i2 = i1 + 1; i2 < n - 1; i2++)
        {
            for (i3 = i2 + 1; i3 < n; i3++)
            {
                if (a[i1] + a[i2] + a[i3] == 0)
                {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) break;
    }

    if (!found)
        cout << "Indexes : None" << endl;
    else
        cout << "Indexes : " << i1 << " " << i2 << " " << i3 << endl;

    return 0;
}