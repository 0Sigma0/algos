from typing import List


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points = sorted(points)
        maxdif = abs(points[0][0] - points[1][0])
        for i in range(1, len(points) - 1):
            dif = abs(points[i][0] - points[i + 1][0])
            if dif > maxdif:
                maxdif = dif
        return maxdif


sol = Solution()
points = [[3, 1], [9, 0], [1, 0], [1, 4], [5, 3], [8, 8]]
print(sol.maxWidthOfVerticalArea(points))
