class Solution:
    def isCommonPrefix(self, strs, prefix):
        for s in strs:
            if not s.startswith(prefix):
                return False
        return True

    def longestCommonPrefix(self, strs) -> str:
        if len(strs) == 0:
            return ""
        le, ri = 0, len(strs[0])
        while(le <= ri):
            m = (le + ri) >> 1
            if self.isCommonPrefix(strs, strs[0][:m]):
                le = m + 1
            else:
                ri = m - 1
        return strs[0][:le-1]


if __name__ == "__main__":
    solu = Solution()
    print(solu.longestCommonPrefix(["flower", "flow", "flight"]))
