class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        memo = {}

        def dfs(i, j):
            if i == len(triangle):
                return 0

            if (i, j) in memo:
                return memo[(i, j)]

            left = triangle[i][j] + dfs(i + 1, j)
            right = triangle[i][j] + dfs(i + 1, j + 1)

            memo[(i, j)] = min(left, right)

            return memo[(i, j)]

        return dfs(0, 0)