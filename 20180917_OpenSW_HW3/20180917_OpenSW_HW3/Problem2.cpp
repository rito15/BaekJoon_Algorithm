#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
public:
    vector<int> node;

    void addNode(int index)
    {
        this->node.push_back(index);
    }
};

int T = 0; // number of test cases
int N = 0; // number of nodes
Graph* grp;	// graph
vector<int> stack;	// dfs stack

void push(int value)
{
    stack.push_back(value);
}

int pop()
{
    if (stack.empty())
        return -1;

    int tmp = stack.back();	// 끝 값 리턴

    stack.pop_back(); // 끝 값 제거

    return tmp;
}

// DFS 탐색
void dfs(Graph& graph, vector<bool>& visited)
{
    for (int i = 0; i < (int)graph.node.size(); i++)
    {
        if (graph.node[i] != 0)	// 지워진 노드일 경우 미방문
            push(graph.node[i]);
    }

    graph.node.clear();

    int next = pop();

    while (next != -1)
    {
        if (!visited[next])	// 미방문시
        {
            dfs(grp[next], visited);
            visited[next] = true;
        }

        next = pop();
    }
}

// visited가 모두 true이면 true 리턴, 하나라도 아니면 false 리턴 (index 0은 무시, 1부터)
bool isConquered(vector<bool>& visited)
{
    for (int i = 1; i < (int)visited.size(); i++)
        if (!visited[i])
            return false;
    return true;
}

// 노드 하나 연결 끊기
void cut(int index)
{
    for (int i = 1; i < N + 1; i++)
    {
        if (i == index)
            for (int j = 0; j < (int)grp[i].node.size(); j++)
                grp[i].node[j] = 0;

        else
        {
            for (int j = 0; j < (int)grp[i].node.size(); j++)
            {
                if (grp[i].node[j] == index)
                    grp[i].node[j] = 0;
            }
        }
    }
}

int main()
{
    string connection = ""; // input of connections
    vector<bool> visited;
    vector<vector<int>> cutNodes;

    cout << "<sample input>" << endl;
    cin >> T;
    cutNodes.resize(T);

    for (int t = 0; t < T; t++)
    {
        cin >> N;
        cin.ignore();
        getline(cin, connection, '\n');

        for (int i = 1; i <= N; i++)
        {
            visited.resize(N + 1, false);
            for(int v = 0; v <= N; v++)
                visited[v] = false;

            grp = new Graph[N + 1];

            // add nodes into the graph
            for (int j = 0; j < (int)connection.length(); j += 4)
            {
                grp[connection[j] - '0'].addNode(connection[j + 2] - '0');
                grp[connection[j + 2] - '0'].addNode(connection[j] - '0');
            }
            
            cut(i);

            dfs(grp[i % N + 1], visited);
            visited[i] = true;

            if (!isConquered(visited))
                cutNodes[t].push_back(i);

            delete[] grp;
        } // For N End
    }   // For T End

    cout << endl << "<sample input>" << endl;

    for(int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << " : Cut nodes = ";
        
        for(int j = 0; j < (int)cutNodes[i].size(); j++)
        {
            cout << cutNodes[i][j];

            if(j < (int)cutNodes[i].size() - 1)
                cout << ", ";
        }
        
        cout << endl;
    }

    return 0;
}