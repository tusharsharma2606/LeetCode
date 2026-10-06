class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        lavda = {}

        def dfs(i, j):
            if i == len(triangle):
                return 0

            if (i, j) in lavda:
                return lavda[(i, j)]

            left = triangle[i][j] + dfs(i + 1, j)
            right = triangle[i][j] + dfs(i + 1, j + 1)

            lavda[(i, j)] = min(left, right)

            return lavda[(i, j)]

        return dfs(0, 0)