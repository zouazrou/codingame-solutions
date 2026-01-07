#include <iostream>
#include <vector>

using namespace std;

#define VISITED 42
#define OCEAN 0

int n;
vector<vector<int>> m;

bool    DFS(int x, int y)
{
    int currPlot = m[y][x];

    if (m[y][x] == VISITED)
        return (false);
    if (m[y][x] == OCEAN)
        return (true);
    m[y][x] = VISITED;
    if (x - 1 >= 0) {
        if (abs(currPlot-m[y][x-1]) <= 1 && DFS(x-1, y))
            return (true);
    }
    if (y - 1 >= 0) {
        if (abs(currPlot-m[y-1][x]) <= 1 && DFS(x, y-1))
            return (true);
    }
    if (x + 1 < n) {
        if (abs(currPlot-m[y][x+1]) <= 1 && DFS(x+1, y))
            return (true);
    }
    if (y + 1 < n) {
        if (abs(currPlot-m[y+1][x]) <= 1 && DFS(x, y+1))
            return (true);
    }
    return (false);
}

int main(int ac, char** av)
{
    if (ac != 2)
    {
        cout << "Entre fileName" << endl;
        return (1);
    }
    ifstream in(av[1]);

    in >> n;
    m.resize(n);
    for (int i = 0; i < n; i++) {
        m[i].resize(n);
        for (int j = 0; j < n; j++) {
            int elevation;
            if (!(in >> elevation)) {
                cerr << "Invalid input at (" << i << "," << j << ")\n";
                return (1);
            }
            m[i][j] = elevation;
        }
    }
    return 0;
}