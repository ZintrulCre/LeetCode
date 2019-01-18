// #1
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int &&N = pow(n, 2);
        int m = 1, dir = 0, x = 0, y = 0;
        while (m <= N - 1) {
            if (dir == 0) {
                if (y + 1 >= n || ret[x][y + 1] != 0)
                    ++dir;
                else
                    ret[x][y++] = m++;
            } else if (dir == 1) {
                if (x + 1 >= n || ret[x + 1][y] != 0)
                    ++dir;
                else
                    ret[x++][y] = m++;
            } else if (dir == 2) {
                if (y - 1 < 0 || ret[x][y - 1] != 0)
                    ++dir;
                else
                    ret[x][y--] = m++;
            } else {
                if (x - 1 < 0 || ret[x - 1][y] != 0)
                    dir = 0;
                else
                    ret[x--][y] = m++;
            }
        }
        ret[x][y] = N;
        return ret;
    }
};


// #2
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int N = pow(n, 2), m = 1;
        int left = 0, right = n - 1, top = 0, down = n - 1;
        while (top <= down && left <= right) {
            for (int y = left; y <= right; ++y)
                ret[top][y] = m++;
            ++top;
            for (int x = top; x <= down; ++x)
                ret[x][right] = m++;
            --right;
            for (int y = right; y >= left; --y)
                ret[down][y] = m++;
            --down;
            for (int x = down; x >= top; --x)
                ret[x][left] = m++;
            ++left;
        }
        return ret;
    }
};
