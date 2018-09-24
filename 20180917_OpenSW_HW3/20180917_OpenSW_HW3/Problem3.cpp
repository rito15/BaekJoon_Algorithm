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

// �̺м� üũ
bool bipartiteCheck(int number)
{
    bool   numbers[10] = {false, };
    string strNumber   = to_string(number);
    int    checkCount  = 0;

    FOR(i, (int)strNumber.length())
    {
        int thisNumber = strNumber[i] - '0';

        // ������ ���ڰ� �� ���ڿ� �ٸ���, �̹� ������ ���ڰ� �����ߴ� ���
        // ��) 111331 -> �̺м��� �ƴ�
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

// �̺м� �����
int makeBipartite(int number)
{
    int bipartite = number;

    // �� ���ึ�� �̺м� üũ �� �� ����
    while(!bipartiteCheck(bipartite))
    {
        bipartite += number;
    }

    return bipartite;
}

// �̺м��� ���Ű ǥ������ �ٲ�
string expressSecretKey(int bipartiteNumber)
{
    // a x b y �� ǥ�� (a���� x, b���� y)
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    string strNumber = to_string(bipartiteNumber);

    FOR(i, (int)strNumber.length())
    {
        int thisNumber = strNumber[i] - '0';

        // a, x�� �ִ� ��� b, y �ʱ�ȭ
        if(a > 0 && thisNumber != x)
        {
            y = thisNumber;
            b++;
        }
        // a, x �ʱ�ȭ
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

    // �Է� �� �Լ� ȣ��
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