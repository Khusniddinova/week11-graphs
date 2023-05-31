#include <bits/stdc++.h>

using namespace std;

void floodFill(vector<vector<int>>& image, int sr, int sc, int color, int startColor) {
    int n = image.size();
    int m = image[0].size();

    // Base case: If the current pixel is out of bounds or already has the new color
    // or it has a different color than the starting pixel, then return
    if (sr < 0  sr >= n  sc < 0  sc >= m  image[sr][sc] != startColor || image[sr][sc] == color) {
        return;
    }

    // Change the color of the current pixel
    image[sr][sc] = color;

    // Recursive calls to the adjacent pixels
    floodFill(image, sr + 1, sc, color, startColor); // Down
    floodFill(image, sr - 1, sc, color, startColor); // Up
    floodFill(image, sr, sc + 1, color, startColor); // Right
    floodFill(image, sr, sc - 1, color, startColor); // Left
}

vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int color) {
    // Store the color of the starting pixel
    int startColor = image[sr][sc];

    // Perform flood fill starting from the given position
    floodFill(image, sr, sc, color, startColor);

    return image;
}

// Do not modify the code below
int main() {
    int n;
    cin >> n;
    vector<vector<int>> image(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> ans = solve(image, sr, sc, color);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
            if (j != n - 1) {
                cout << ' ';
            }
        }
        if (i != n - 1) {
            cout << '\n';
        }
    }

    return 0;
}

