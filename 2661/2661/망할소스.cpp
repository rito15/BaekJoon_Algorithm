/*      ���� ����       */

/*  �Է�
�Է��� ���� N�ϳ��� �̷������. N�� 1 �̻� 80 �����̴�.
*/

/*  ���
ù ��° �ٿ� 1, 2, 3���θ� �̷���� �ִ� ���̰� N�� ���� ������ �߿��� ���� ���� ���� ��Ÿ���� ������ ����Ѵ�.
������ �̷�� 1, 2, 3�� ���̿��� ��ĭ�� ���� �ʴ´�.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N; // ���� ���� (1~80), �Է¹���
    string seq = "1"; // ���� N��ŭ�� ����. 1, 2, 3���θ� �̷������.
    bool flag = false; // true : ���� ������ �ش��

    int chkPoint = 0; // ���ѷ��� ����

    cin >> N; // �Է�

              //i = ���� ������ ����
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

    cout << seq; // ���

    return 0;
}