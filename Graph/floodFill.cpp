

#include <bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, int inicolor, int m, int n, int color, vector<vector<int>> &image)
{
    image[sr][sc] = color;

    if (sr - 1 >= 0 && image[sr - 1][sc] == inicolor && image[sr - 1][sc] != color)
    {
        dfs(sr - 1, sc, inicolor, m, n, color, image);
    }
    if (sr + 1 < m && image[sr + 1][sc] == inicolor && image[sr + 1][sc] != color)
    {
        dfs(sr + 1, sc, inicolor, m, n, color, image);
    }

    if (sc - 1 >= 0 && image[sr][sc - 1] == inicolor && image[sr][sc - 1] != color)
    {
        dfs(sr, sc - 1, inicolor, m, n, color, image);
    }

    if (sc + 1 < n && image[sr][sc + 1] == inicolor && image[sr][sc + 1] != color)
    {
        dfs(sr, sc + 1, inicolor, m, n, color, image);
    }

    return;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color)
{
    int m = image.size();
    int n = image[0].size();

    int inicolor = image[sr][sc];

    dfs(sr, sc, inicolor, m, n, color, image);

    return image;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sc = 1;
    int sr = 1;
    int color = 2;

    image = floodFill(image, sr, sc, color);

    for (int i = 0; i < image.size(); ++i)
    {
        for (int j = 0; j < image[i].size(); ++j)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}