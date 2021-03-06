#include <iostream>
#include <string>
#include <vector>
#include <math.h>

int L;  // Original Message의 길이
int N;  // Original Message에서 1의 개수
int M;  // Original Message에서 0의 개수 (L - N)
int expansion; // 확장될 가능성 있는 최대 숫자 
               //(comp에서 a를  origin의 b로 확장할 경우 이 때 a의 십진수 값을 나타냄) 
std::vector<std::string> originalStrings;   // 복원한 오리지널 메시지들
std::vector<std::string> outputs;           // 출력할 output 메시지

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
    int repeat; // case 수
    std::cout << "Input the number of Cases = "; std::cin >> repeat;
    std::cout << "=============================" << std::endl << std::endl;
    std::cout << "(Sample input)" << std::endl;

    for(int count = 0; count < repeat; count++)
    {
        originalStrings.clear();

        std::string compressedMessage;  // 압축된 메시지

        std::cin >> L >> N;
        M = L - N;

        std::cin >> compressedMessage;
    
        int cL = 0;  // Compressed Message의 길이
        int cN = 0;  // Compressed Message에서 1의 개수
        int cM = 0;  // Compressed Message에서 0의 개수 (cL - cN)

        for(int i = 0; i < (int)compressedMessage.length(); i++)
            if (compressedMessage[i] == '1')
                cN++;   // comp에서 1의 개수

        cL = (int)compressedMessage.length();    // comp의 길이
        cM = cL - cN;                           // comp에서 0의 개수

        expansion = (N - cN) * (int)pow(2.0, (double)(cM - M));

        // 상위 함수 호출
        findOrigin(compressedMessage, 0);

        // output 스트링들 저장
        switch((int)originalStrings.size())
        {
        case 0:
            outputs.push_back("NO");
            break;

        case 1:
            outputs.push_back("YES");
            break;

        default:
            outputs.push_back("NOT UNIQUE");
            break;
        }

        //for (int i = 0; i < (int)originalStrings.size(); i++)
            //std::cout << "Decompression 결과[" << i + 1 << "] : " << originalStrings[i] << std::endl;
    }

    std::cout << std::endl << "(Sample output)" << std::endl;

    for(int i = 0; i < (int)outputs.size(); i++)
        std::cout << "Case " << i + 1 << " : " << outputs[i] << std::endl;

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

    for (int i = 0; i < (int)compressedString.length(); i++)
        if (compressedString[i] == '1')
            cN++;   // comp에서 1의 개수

    cL = (int)compressedString.length();    // comp의 길이
    cM = cL - cN;                           // comp에서 0의 개수

    if (L == cL && N == cN)  // 성공적으로 복원 시 벡터에 저장
    {
        originalStrings.push_back(compressedString);
        return;
    }

    if (L < cL || N < cN || M > cM)  // 종료 조건
        return;

    // 하위 함수 호출
    for (int i = pos; i < (int)compressedString.length(); i++)
    {
        findExpansion(compressedString, i);
    }
}

void findExpansion(std::string compressedString, int pos)
{
    int cL = 0;  // Compressed Message의 길이
    int cN = 0;  // Compressed Message에서 1의 개수
    int cM = 0;  // Compressed Message에서 0의 개수 (cL - cN)

    for(int i = 0; i < (int)compressedString.length(); i++)
        if (compressedString[i] == '1')
            cN++;   // comp에서 1의 개수

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

            findOrigin(compressedString, pos + nowExpansion + 1);   // 분기 시작 (상위 함수 호출)

            compressedString = tmpStr; // 스트링 복원 후 for 문 다음 진행
        }
    }
}