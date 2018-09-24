// ����� �ڵ带 �����ϱ� ��, ���� �� ����� �ϼ��� ����
// �ѹ��� �ϳ��� input -> �ϳ��� output�� ������ ����

// ������ ���� �̰� ��

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


int L;  // Original Message�� ����
int N;  // Original Message���� 1�� ����
int M;  // Original Message���� 0�� ���� (L - N)
int expansion; // Ȯ��� ���ɼ� �ִ� �ִ� ���� 
               //(comp���� a��  origin�� b�� Ȯ���� ��� �� �� a�� ������ ���� ��Ÿ��) 
std::vector<std::string> originalStrings;   // ������ �������� �޽�����

// 10���� ���� -> 2���� ��Ʈ��
std::string decToBin(int decimal);

// 2���� ��Ʈ�� -> 10���� ����;

// ����� compressed ��Ʈ������ part ��Ʈ���� ã�� �������� ����
void expand(std::string& compressed, std::string part, int place);

// Decompression : ��ȣ ȣ�� ���� �ܰ� �Լ�
void findOrigin(std::string compressedString, int pos);

// Expansion : ��ȣ ȣ�� ���� �ܰ� �Լ�
void findExpansion(std::string compressedString, int pos);

int main()
{
    bool uniqueness = false; // compd -> origin ����ũ�ϰ� �������� ����

    std::string originalMessage;    // ���� �޽���
    std::string compressedMessage;  // ����� �޽���


    std::cin >> L >> N;
    M = L - N;

    std::cin >> compressedMessage; ENTER;

    /*
    L = 9; N = 7; M = L - N;
    compressedMessage = "1010101";
    */

    int cL = 0;  // Compressed Message�� ����
    int cN = 0;  // Compressed Message���� 1�� ����
    int cM = 0;  // Compressed Message���� 0�� ���� (cL - cN)

    FOR(i, (int)compressedMessage.length())  // comp���� 1�� ����
        if (compressedMessage[i] == '1')
            cN++;

    cL = (int)compressedMessage.length();    // comp�� ����
    cM = cL - cN;                           // comp���� 0�� ����

    expansion = (N - cN) * (int)pow(2.0, (double)(cM - M));

    findOrigin(compressedMessage, 0);

    for (int i = 0; i < (int)originalStrings.size(); i++)
        std::cout << "���� " << originalStrings[i] << std::endl;

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

    // ������ ���ӵ� 1¥�� ��Ʈ�� ����
    for (int i = 0; i < binToDec(part); i++)
        expandedPart += "1";

    // ��Ʈ�� Ȯ��
    compressed =
        compressed.substr(0, place) +
        expandedPart +
        compressed.substr(place + (int)part.length());
}

void findOrigin(std::string compressedString, int pos)
{
    int cL = 0;  // Compressed Message�� ����
    int cN = 0;  // Compressed Message���� 1�� ����
    int cM = 0;  // Compressed Message���� 0�� ���� (cL - cN)

    FOR(i, (int)compressedString.length())  // comp���� 1�� ����
        if (compressedString[i] == '1')
            cN++;

    cL = (int)compressedString.length();    // comp�� ����
    cM = cL - cN;                           // comp���� 0�� ����

    if (L == cL && N == cN)  // ���������� ���� ��
    {
        DEBUG_
            std::cout << "�ù� ���� �̰� �����Ҳ��� =  " << compressedString << std::endl << std::endl;

        originalStrings.push_back(compressedString);
        return;
    }

    if (L < cL || N < cN || M > cM)  // ���� ����
        return;


    for (int i = pos; i < (int)compressedString.length(); i++)
    {
        DEBUG_
            std::cout << " ���� i �� =  " << i << std::endl;
        DEBUG_
            std::cout << " ��Ʈ�� =  " << compressedString << std::endl << std::endl;

        findExpansion(compressedString, i);
    }
}

void findExpansion(std::string compressedString, int pos)
{
    int cL = 0;  // Compressed Message�� ����
    int cN = 0;  // Compressed Message���� 1�� ����
    int cM = 0;  // Compressed Message���� 0�� ���� (cL - cN)

    FOR(i, (int)compressedString.length())  // comp���� 1�� ����
        if (compressedString[i] == '1')
            cN++;

    cL = (int)compressedString.length();    // comp�� ����
    cM = cL - cN;                           // comp���� 0�� ����

    if (L < cL || N < cN || M > cM)  // ���� ����
        return;

    for (int nowExpansion = expansion; nowExpansion > 2; nowExpansion--)
    {
        std::string expanStr = decToBin(nowExpansion);  // ���� expansion�� �������� ��ȯ
        int expanLength = (int)expanStr.length();

        // �躸�� ����� ū ��� - �������ϴ�
        if (expanLength > (int)compressedString.length())
            continue;

        // ��ġ�ϴ� ��� - Ȯ�� �� �� �ٸ� �б� ����
        if (compressedString.substr(pos, expanLength) == expanStr)
        {
            std::string tmpStr = compressedString;

            expand(compressedString, expanStr, pos);    // Ȯ��

            DEBUG_
                std::cout << " �������� : " << compressedString << " �׸��� ~ " << expanStr << std::endl;
            DEBUG_
                std::cout << " ���ο� ���� =  " << pos + nowExpansion + 1 << std::endl;
            
            //system("pause > nul");
            system(("timeout /t " + std::to_string(0) + " > nul").c_str());
            //system("cls");

            findOrigin(compressedString, pos + nowExpansion + 1);   // �б� ����

            compressedString = tmpStr;
        }
    }
}