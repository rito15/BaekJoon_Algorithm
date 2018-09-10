#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> box;
    int n, k;
    int a = 1;

    cin >> n;

    box.resize(n*n + 1);
    box[0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            box[a++] = i * j;

    sort(box.begin(), box.end());

    //cin >> k;
    for(int i = 1; i <= n*n; i++)
        cout << box[i] << endl;
    
    return 0;
}