class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        if not matrix:
            return []

        m, n = len(matrix), len(matrix[0])
        row_start, row_end, col_start, col_end = 0, m - 1, 0, n - 1
        result = []

        while row_start <= row_end and col_start <= col_end:
            for j in range(col_start, col_end + 1):
                result.append(matrix[row_start][j])
            row_start += 1

            for i in range(row_start, row_end + 1):
                result.append(matrix[i][col_end])
            col_end -= 1

            if row_start <= row_end:
                for j in range(col_end, col_start - 1, -1):
                    result.append(matrix[row_end][j])
                row_end -= 1

            if col_start <= col_end:
                for i in range(row_end, row_start - 1, -1):
                    result.append(matrix[i][col_start])
                col_start += 1

        return result
