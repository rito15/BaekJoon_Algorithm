/*
    선영이는 이번 학기에 오스트레일리아로 교환 학생을 가게 되었다. 

    호주에 도착하고 처음 몇 일은 한국 생각을 잊으면서 즐겁게 지냈다. 몇 주가 지나니 한국이 그리워지기 시작했다. 

    선영이는 한국에 두고온 서버에 접속해서 디렉토리 안에 들어있는 파일 이름을 보면서 그리움을 잊기로 했다. 

    매일 밤, 파일 이름을 보면서 파일 하나하나에 얽힌 사연을 기억하면서 한국을 생각하고 있었다.

    어느날이었다. 한국에 있는 서버가 망가졌고, 그 결과 특정 패턴과 일치하는 파일 이름을 적절히 출력하지 못하는 버그가 생겼다.

    패턴은 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열이다.

    파일 이름이 패턴에 일치하려면, 

    패턴에 있는 별표를 알파벳 소문자로 이루어진 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다. 

    별표는 빈 문자열로 바꿀 수도 있다. 예를 들어, "abcd", "ad", "anestonestod"는 모두 패턴 "a*d"와 일치한다. 

    하지만, "bcd"는 일치하지 않는다.

    패턴과 파일 이름이 모두 주어졌을 때, 각각의 파일 이름이 패턴과 일치하는지 아닌지를 구하는 프로그램을 작성하시오.


입력
    첫째 줄에 파일의 개수 N이 주어진다. (1 ≤ N ≤ 100)

    둘째 줄에는 패턴이 주어진다. 패턴은 알파벳 소문자와 별표(아스키값 42) 한 개로 이루어져 있다. 

    문자열의 길이는 100을 넘지 않으며, 별표는 문자열의 시작과 끝에 있지 않다.

    다음 N개 줄에는 파일 이름이 주어진다. 파일 이름은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.


출력
    총 N개의 줄에 걸쳐서, 입력으로 주어진 i번째 파일 이름이 패턴과 일치하면 "DA", 일치하지 않으면 "NE"를 출력한다.

    참고로, "DA"는 크로아티어어로 "YES"를, "NE"는 "NO"를 의미한다.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N;              // 파일의 개수 (입력받음)
    int p1, p2;         // 분리된 각각 패턴 스트링의 길이
    vector<string> file;   // 각각 파일명 (입력받음)
    vector<string> result; // 결과 스트링
    string pattern;     // 패턴 스트링 (입력받음)
    string patt_1 = "", patt_2 = ""; // 별표 전후 패턴값 (pattern으로부터 분리)

    cin >> N;           // 입력 첫 줄 : 파일의 개수
    cin >> pattern;     // 입력 둘째 줄 : 패턴 스트링

    file.resize(N);
    result.resize(N);

    for(int i = 0; i < N; i++)  // 입력 셋째 줄 이후 : 파일명
        cin >> file[i];

    int i = 0;
    for(; pattern[i] != '*'; i++)    // 패턴 스트링 분리 1
        patt_1 += pattern[i];

    for(i++; i < (int)pattern.length(); i++) // 패턴 스트링 분리 2
        patt_2 += pattern[i];
     
    p1 = (int)patt_1.length();
    p2 = (int)patt_2.length();

    for(i = 0; i < N; i++)
    {
        // if((int)file[i].length() <= p1 || (int)file[i].length() <= p2)   -> 틀림
        //    result[i] = "NE";
        /*
            만약 패턴이 AB*BCD인 경우,
            파일명이 ABCD이면 p1 = 2, p2 = 3, length = 4이므로

            length가 p1, p2보다 크기 때문에 조건에 해당되지 않아 DA가 출력된다.

            하지만 파일명 "ABCD"는 "AB"로 시작해서 "BCD"로 끝나는 패턴에 부합하지 않으므로
            NE가 출력되어야 한다.

            따라서 파일명은 시작패턴의 길이와 종료패턴의 길이 합을 최소 길이로 가져야만 한다.
            length >= p1 + p2

        */

        if((int)file[i].length() < p1 + p2)  // 예외처리(런타임 에러 발생 부분) - 이건 맞음
        {
            result[i] = "NE";
            continue;
        }

        if(file[i].substr(0, p1) == patt_1 && file[i].substr((int)file[i].length() - p2, p2) == patt_2) // 패턴 찾기
            result[i] = "DA";
        else
            result[i] = "NE";
    }

    for(i = 0; i < N; i++)
        cout << result[i] << endl;

    return 0;   
}   // 시불