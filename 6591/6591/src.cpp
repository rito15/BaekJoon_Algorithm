/*
    n���� ���� �߿��� k���� ���� ���� �����ϴ� ����� ���� �� ���� �ϱ�?


�Է�
    �Է��� �ϳ� �Ǵ� �� �̻��� �׽�Ʈ ���̽��� �̷���� �ִ�.

    �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, 2^31-1 �� ���� �ʴ� �� �ڿ��� n(n �� 1)�� k(0 �� k ��n)�� �̷���� �ִ�.

    �Է��� ������ �ٿ��� 0�� �� �� �־�����.


���
    �� �׽�Ʈ ���̽��� ���ؼ�, ������ ����Ѵ�. �׻� ������ 2^31���� ���� ��츸 �Է����� �־�����.

*/

#include <iostream>
using namespace std;

typedef struct node
{
    long data;
    struct node* link;
} node;

typedef node* node_pointer;

int main()
{
    int n = 1, r = 1;
    long result;
    
    node_pointer head, tail;
    tail = new node;
    tail->link = NULL;
    
    head = tail;

    while (true)
    {
        cin >> n >> r;
        if ((n == 0) && (r == 0)) break;

        if(n - r < r) r = n - r;

        result = 1;
        for(int i = 1; i <= r; i++, n--)
        {
            result *= n;
            result /= i;
        }
        
        tail->link = new node;

        tail = tail->link;
        tail->data = result;
        tail->link = NULL;
    }
    
    head = head->link;
    while(head)
    {
        cout << head->data << endl;
        head = head->link;
    }
}