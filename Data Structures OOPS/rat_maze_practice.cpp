#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(int n, int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

void solve(int x, int y, int n, vector<vector<int>> &maze, vector<string> &ans, string path, vector<vector<int>> &visited)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    int newx = x + 1;
    int newy = y;
    if (isSafe(n, newx, newy, maze, visited))
    {
        path.push_back('D');
        solve(newx, newy, n, maze, ans, path, visited);
        path.pop_back();
    }
    newx = x - 1;
    newy = y;
    if (isSafe(n, newx, newy, maze, visited))
    {
        path.push_back('U');
        solve(newx, newy, n, maze, ans, path, visited);
        path.pop_back();
    }
    newx = x;
    newy = y + 1;
    if (isSafe(n, newx, newy, maze, visited))
    {
        path.push_back('R');
        solve(newx, newy, n, maze, ans, path, visited);
        path.pop_back();
    }
    newx = x;
    newy = y - 1;
    if (isSafe(n, newx, newy, maze, visited))
    {
        path.push_back('L');
        solve(newx, newy, n, maze, ans, path, visited);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findpath(vector<vector<int>> maze, int n)
{
    vector<string> ans;
    if (maze[0][0] == 0)
    {
        return ans;
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int srcx = 0;
    int srcy = 0;
    string path = "";
    solve(srcx, srcy, n, maze, ans, path, visited);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    vector<string> paths = findpath(maze, n);
    if (paths.empty())
    {
        cout << "No path";
    }
    else

    {
        for (const string i : paths)
        {
            cout << i << endl;
        }
    }
    return 0;
}
