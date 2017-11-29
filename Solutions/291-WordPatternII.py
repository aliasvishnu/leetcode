class Solution(object):

    def backtrack(self, p, s, sp, ps, k):

        if(len(p) == 0 and len(s) == 0):
            return True

        if((len(p) == 0 and len(s) != 0) or (len(p) != 0 and len(s) == 0)):
            return False

        isValid = False
        st = False

        for i in range(1, len(s)+1):
            if p[0] in ps:
                if ps[p[0]] != s[0:i]:
                    continue
                else:
                    st = True

            if s[0:i] in sp and sp[s[0:i]] != p[0]:
                continue

            ps[p[0]] = s[0:i]
            sp[s[0:i]] = p[0]

            if(self.backtrack(p[1:], s[i:], sp, ps, k+1)):
                isValid = True

            if(st == False):
                del ps[p[0]]
                del sp[s[0:i]]

        return isValid


    def wordPatternMatch(self, pattern, s):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """

        return self.backtrack(pattern, s, {}, {}, 0)

        
