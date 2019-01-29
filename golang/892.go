func min(i, j int) int {
\u0009if i < j {
\u0009\u0009return i
\u0009}
\u0009return j
}

func surfaceArea(grid [][]int) int {
\u0009var x int = len(grid)
\u0009if x == 0 {
\u0009\u0009return 0
\u0009}
\u0009var y int = len(grid[0])
\u0009var total, area int = 0, 0
\u0009for i := 0; i < x; i++ {
\u0009\u0009for j := 0; j < y; j++ {
\u0009\u0009\u0009if grid[i][j] == 0 {
\u0009\u0009\u0009\u0009continue
\u0009\u0009\u0009}
\u0009\u0009\u0009area = 2 + 4*grid[i][j]
\u0009\u0009\u0009if i-1 >= 0 {
\u0009\u0009\u0009\u0009area -= min(grid[i-1][j], grid[i][j])
\u0009\u0009\u0009}
\u0009\u0009\u0009if (j-1 >= 0) {
\u0009\u0009\u0009\u0009area -= min(grid[i][j-1], grid[i][j])
\u0009\u0009\u0009}
\u0009\u0009\u0009if (i+1 < x) {
\u0009\u0009\u0009\u0009area -= min(grid[i+1][j], grid[i][j])
\u0009\u0009\u0009}
\u0009\u0009\u0009if (j+1 < y) {
\u0009\u0009\u0009\u0009area -= min(grid[i][j+1], grid[i][j]);
\u0009\u0009\u0009}
\u0009\u0009\u0009total += area;
\u0009\u0009}
\u0009}
\u0009return total
}
