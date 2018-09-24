#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma region Macro

// Input enter on console.
#define ENTER std::cout << std::endl;

#define FOR(var, a)          for(int var = 0;  var <  a;  var++)
#define FOR_(var, a1, a2)    for(int var = a1; var <  a2; var++)

#pragma endregion

// 이분수 체크
bool bipartiteCheck(int number)
{
    bool   numbers[10] = {false, };
    string strNumber   = to_string(number);
    int    checkCount  = 0;

    FOR(i, (int)strNumber.length())
    {
        int thisNumber = strNumber[i] - '0';

        // 현재의 숫자가 앞 숫자와 다른데, 이미 현재의 숫자가 등장했던 경우
        // 예) 111331 -> 이분수가 아님
        if (i > 0)
            if (strNumber[i - 1]    != strNumber[i] &&
                numbers[thisNumber] == true)
                return false;

        if(numbers[thisNumber] == false)
           numbers[thisNumber] = true;
    }

    FOR(i, 10)
        if(numbers[i])
            checkCount++;

    if(checkCount == 2)
        return true;
    else
        return false;
}

// 이분수 만들기
int makeBipartite(int number)
{
    int bipartite = number;

    // 매 시행마다 이분수 체크 및 값 증가
    while(!bipartiteCheck(bipartite))
    {
        bipartite += number;
    }

    return bipartite;
}

// 이분수를 비밀키 표현으로 바꿈
string expressSecretKey(int bipartiteNumber)
{
    // a x b y 꼴 표현 (a개의 x, b개의 y)
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    string strNumber = to_string(bipartiteNumber);

    FOR(i, (int)strNumber.length())
    {
        int thisNumber = strNumber[i] - '0';

        // a, x가 있는 경우 b, y 초기화
        if(a > 0 && thisNumber != x)
        {
            y = thisNumber;
            b++;
        }
        // a, x 초기화
        else
        {
            x = thisNumber;
            a++;
        }
    }

    return to_string(a) + " " + to_string(x) + " " + to_string(b) + " " + to_string(y);
}

int main()
{
    int T;   // input count
    int num; // input number
    vector<int> inputs;
    vector<string> outputs;

    cout << "Enter the repeat count = ";
    cin >> T;
    ENTER;

    cout << "(sample input)" << endl;

    // 입력 및 함수 호출
    FOR(i, T)
    {
        cin >> num;
        inputs.push_back(num);
        outputs.push_back(expressSecretKey(makeBipartite(num)));
    }

    cout << endl << "(sample output)" << endl;

    FOR(i, T)
        cout << inputs[i] << " : " << outputs[i] << endl;

    return 0;
}