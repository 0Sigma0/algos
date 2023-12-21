class Solution:
    def checkValid(self, matrix: list[list[int]]) -> bool:
        count = 0
        listOfNums = [i for i in range(1, len(matrix) + 1)]
        for i in range(len(matrix)):
            tempList = []
            tempList2 = []
            for j in range(len(matrix)):
                tempList.append(matrix[i][j])
                tempList2.append(matrix[j][i])
            tempList.sort()
            tempList2.sort()
            if (tempList == listOfNums) & (tempList2 == listOfNums):
                count += 2
            else:
                break
        return count == 2 * len(matrix)
