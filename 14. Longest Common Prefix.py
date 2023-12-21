class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        strs.sort(key=len)
        answer = ""
        for i in range(len(strs[0])):
            count = 0
            for j in range(1, len(strs)):
                if strs[0][i] != strs[j][i]:
                    return answer
                else:
                    count += 1
            if count == len(strs) - 1:
                answer += strs[0][i]
        return answer
