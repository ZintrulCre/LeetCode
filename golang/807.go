func min(i, j int) int {
\u0009if i < j {
\u0009\u0009return i
\u0009}
\u0009return j
}

func max(i, j int) int {
\u0009if i > j {
\u0009\u0009return i
\u0009}
\u0009return j
}

func maxIncreaseKeepingSkyline(grid [][]int) int {
\u0009m := len(grid)
\u0009if m == 0 {
\u0009\u0009return 0
\u0009}
\u0009n := len(grid[0])
\u0009row := make([]int, m)
\u0009col := make([]int, n)
\u0009for i := 0; i < m; i++ {
\u0009\u0009for j := 0; j < n; j++ {
\u0009\u0009\u0009row[i] = max(row[i], grid[i][j])
\u0009\u0009\u0009col[j] = max(col[j], grid[i][j])
\u0009\u0009}
\u0009}
\u0009total := 0
\u0009for i := 0; i < m; i++ {
\u0009\u0009for j := 0; j < n; j++ {
\u0009\u0009\u0009highest := min(row[i], col[j]);
\u0009\u0009\u0009total += max(0, highest-grid[i][j]);
\u0009\u0009}
\u0009}
\u0009return total
}
