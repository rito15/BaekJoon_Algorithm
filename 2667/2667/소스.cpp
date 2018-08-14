/*
    <�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. 
    ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. 
    ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. 
    �밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�. 
    ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


�Է�
    ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, 
    �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
    ù ��° �ٿ��� �� �������� ����Ͻÿ�. 
    �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N; // ������ ũ��
int **house; // N * N �������� �� �迭
int **visited; // house�� ���� ������, �湮 ���� ��Ÿ��

int houses = 0; // ���� ���� �� ��

bool isVisited(int i, int j)    // �湮�� ���̰ų� ���� ���� ���̸� true ����
{
    if(i < 0 || j < 0) return true;
    if(i >= N || j >= N) return true;

    if(visited[i][j] == 0) return false;
    else return true;
}

void search(int i, int j)   // ��� �湮
{
    if(!isVisited(i, j))
    {
        visited[i][j] = 1;
        houses++;
    }

    if (!isVisited(i - 1, j)) search(i - 1, j); // ��
    if (!isVisited(i + 1, j)) search(i + 1, j); // ��
    if (!isVisited(i, j - 1)) search(i, j - 1); // ��
    if (!isVisited(i, j + 1)) search(i, j + 1); // ��

}

int main()
{
    string line; // �Է¹޴� �� ��
    vector<int> complex; // ���� �� �� �� ���

    cin >> N;       // �Էº�

    house = new int*[N];
    visited = new int*[N];

    for(int i = 0; i < N; i++)
    {
        house[i] = new int[N];
        visited[i] = new int[N];
    }

    for(int i = 0; i < N; i++)
    {
        cin >> line;

        for(int j = 0; j < N; j++)
        {
            house[i][j] = line[j] - '0';

            if(house[i][j]) visited[i][j] = 0;
            else            visited[i][j] = -1;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            houses = 0;
            if (visited[i][j] == 0) // �湮���� ���� ���� Ž�� ����
                search(i, j);

            if(houses > 0) 
                complex.push_back(houses);
        }
    }

    sort(complex.begin(), complex.end());   // ���� �� ����

    cout << (int)complex.size() << endl;            // ��� ���
    for(int i = 0; i < (int)complex.size(); i++)
        cout << complex[i] << endl;

    return 0;
}