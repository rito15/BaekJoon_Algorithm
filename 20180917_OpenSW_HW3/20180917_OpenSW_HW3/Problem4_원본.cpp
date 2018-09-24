// 디버그 코드를 제거하기 전, 이제 막 기능을 완성한 상태
// 한번에 하나의 input -> 하나의 output만 가능한 상태

// 무무형 제발 이건 좀

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#define FOR(i, a)     for(int i = 0; i < a; i++)
#define FOR_(i, a, b) for(int i = a; i <= b; i++)

#define ENTER         std::cout << std::endl;

bool debugFlag = true;

#define DEBUG_OFF             debugFlag = false;
#define DEBUG_                if(debugFlag)
#define DEBUG_VAL(variable)   if(debugFlag) std::cout << "[DEBUG]_ " << ((void)variable, #variable) << " = " << variable << std::endl;


int L;  // Original Message의 길이
int N;  // Original Message에서 1의 개수
int M;  // Original Message에서 0의 개수 (L - N)
int expansion; // 확장될 가능성 있는 최대 숫자 
               //(comp에서 a를  origin의 b로 확장할 경우 이 때 a의 십진수 값을 나타냄) 
std::vector<std::string> originalStrings;   // 복원한 오리지널 메시지들

// 10진수 정수 -> 2진수 스트링
std::string decToBin(int decimal);

// 2진수 스트링 -> 10진수 정수;

// 압축된 compressed 스트링에서 part 스트링을 찾아 압축해제 수행
void expand(std::string& compressed, std::string part, int place);

// Decompression : 상호 호출 상위 단계 함수
void findOrigin(std::string compressedString, int pos);

// Expansion : 상호 호출 하위 단계 함수
void findExpansion(std::string compressedString, int pos);

int main()
{
    bool uniqueness = false; // compd -> origin 유니크하게 가능한지 여부

    std::string originalMessage;    // 원래 메시지
    std::string compressedMessage;  // 압축된 메시지


    std::cin >> L >> N;
    M = L - N;

    std::cin >> compressedMessage; ENTER;

    /*
    L = 9; N = 7; M = L - N;
    compressedMessage = "1010101";
    */

    int cL = 0;  // Compressed Message의 길이
    int cN = 0;  // Compressed Message에서 1의 개수
    int cM = 0;  // Compressed Message에서 0의 개수 (cL - cN)

    FOR(i, (int)compressedMessage.length())  // comp에서 1의 개수
        if (compressedMessage[i] == '1')
            cN++;

    cL = (int)compressedMessage.length();    // comp의 길이
    cM = cL - cN;                           // comp에서 0의 개수

    expansion = (N - cN) * (int)pow(2.0, (double)(cM - M));

    findOrigin(compressedMessage, 0);

    for (int i = 0; i < (int)originalStrings.size(); i++)
        std::cout << "오예 " << originalStrings[i] << std::endl;

    return 0;
}

std::string decToBin(int decimal)
{
    std::string binary = "";
    int n = 1073741824; // 2^30

    while (n > 0)
    {
        if (decimal >= n)
        {
            decimal -= n;
            binary += "1";
        }

        else if ((int)binary.length() > 0)
            binary += "0";

        n /= 2;
    }

    return binary;
}

int binToDec(std::string binary)
{
    int decimal = 0;
    int n = 1;

    for (int i = (int)binary.length() - 1; i >= 0; i--, n *= 2)
        decimal += (binary[i] - '0') * n;

    return decimal;
}

void expand(std::string& compressed, std::string part, int place)
{
    std::string expandedPart = "";

    // 원래의 연속된 1짜리 스트링 생성
    for (int i = 0; i < binToDec(part); i++)
        expandedPart += "1";

    // 스트링 확장
    compressed =
        compressed.substr(0, place) +
        expandedPart +
        compressed.substr(place + (int)part.length());
}

void findOrigin(std::string compressedString, int pos)
{
    int cL = 0;  // Compressed Message의 길이
    int cN = 0;  // Compressed Message에서 1의 개수
    int cM = 0;  // Compressed Message에서 0의 개수 (cL - cN)

    FOR(i, (int)compressedString.length())  // comp에서 1의 개수
        if (compressedString[i] == '1')
            cN++;

    cL = (int)compressedString.length();    // comp의 길이
    cM = cL - cN;                           // comp에서 0의 개수

    if (L == cL && N == cN)  // 성공적으로 복원 시
    {
        DEBUG_
            std::cout << "시발 나는 이걸 저장할꺼야 =  " << compressedString << std::endl << std::endl;

        originalStrings.push_back(compressedString);
        return;
    }

    if (L < cL || N < cN || M > cM)  // 종료 조건
        return;


    for (int i = pos; i < (int)compressedString.length(); i++)
    {
        DEBUG_
            std::cout << " 여기 i 값 =  " << i << std::endl;
        DEBUG_
            std::cout << " 스트링 =  " << compressedString << std::endl << std::endl;

        findExpansion(compressedString, i);
    }
}

void findExpansion(std::string compressedString, int pos)
{
    int cL = 0;  // Compressed Message의 길이
    int cN = 0;  // Compressed Message에서 1의 개수
    int cM = 0;  // Compressed Message에서 0의 개수 (cL - cN)

    FOR(i, (int)compressedString.length())  // comp에서 1의 개수
        if (compressedString[i] == '1')
            cN++;

    cL = (int)compressedString.length();    // comp의 길이
    cM = cL - cN;                           // comp에서 0의 개수

    if (L < cL || N < cN || M > cM)  // 종료 조건
        return;

    for (int nowExpansion = expansion; nowExpansion > 2; nowExpansion--)
    {
        std::string expanStr = decToBin(nowExpansion);  // 현재 expansion을 이진수로 변환
        int expanLength = (int)expanStr.length();

        // 배보다 배꼽이 큰 경우 - 지나갑니다
        if (expanLength > (int)compressedString.length())
            continue;

        // 일치하는 경우 - 확장 후 또 다른 분기 시작
        if (compressedString.substr(pos, expanLength) == expanStr)
        {
            std::string tmpStr = compressedString;

            expand(compressedString, expanStr, pos);    // 확장

            DEBUG_
                std::cout << " ㅎㅇㅎㅇ : " << compressedString << " 그리고 ~ " << expanStr << std::endl;
            DEBUG_
                std::cout << " 새로운 숫자 =  " << pos + nowExpansion + 1 << std::endl;
            
            //system("pause > nul");
            system(("timeout /t " + std::to_string(0) + " > nul").c_str());
            //system("cls");

            findOrigin(compressedString, pos + nowExpansion + 1);   // 분기 시작

            compressedString = tmpStr;
        }
    }
}