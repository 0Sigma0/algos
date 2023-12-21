class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        matrix = [[1] * n for _ in range(n)]
        row_start, row_end, col_start, col_end = 0, n - 1, 0, n - 1
        spiralNumber = 1
        while row_start <= row_end and col_start <= col_end:
            for j in range(col_start, col_end + 1):
                matrix[row_start][j] = spiralNumber
                spiralNumber += 1
            row_start += 1
            for i in range(row_start, row_end + 1):
                matrix[i][col_end] = spiralNumber
                spiralNumber += 1
            col_end -= 1
            if row_start <= row_end:
                for j in range(col_end, col_start - 1, -1):
                    matrix[row_end][j] = spiralNumber
                    spiralNumber += 1
                row_end -= 1
            if col_start <= col_end:
                for i in range(row_end, row_start - 1, -1):
                    matrix[i][col_start] = spiralNumber
                    spiralNumber += 1
                col_start += 1
        return matrix
