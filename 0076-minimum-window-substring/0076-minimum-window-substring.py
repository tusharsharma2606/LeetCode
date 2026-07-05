class Solution(object):
    def minWindow(self, s, t):

        if len(t)>len(s):
            return""

        need = Counter(t)
        window = {}

        have = 0
        needCount = len(need)

        left = 0

        res=[-1,-1]
        resLen = float("inf")

        for right in range(len(s)):

            c=s[right]
            window[c] = window.get(c,0)+1

            if c in need and window[c] == need[c]:
               have += 1

            while have == needCount:

                if(right-left+1)<resLen:
                    res = [left,right]
                    resLen = right - left+1

                window[s[left]] -=1

                if s[left] in need and window[s[left]]<need[s[left]]:
                    have -= 1

                left += 1

        l, r = res

        return s[l:r+1] if resLen != float("inf") else""                         
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        