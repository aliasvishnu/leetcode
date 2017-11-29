class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        strsplit = str.split(" ")
        dct = {}
        dctr = {}

        if len(pattern) != len(strsplit):
            return False

        for i in range(0, len(pattern)):
            if(pattern[i] not in dct):
                dct[pattern[i]] = strsplit[i]
            elif (dct[pattern[i]] != strsplit[i]):
                return False

            if(strsplit[i] not in dctr):
                dctr[strsplit[i]] = pattern[i]
            elif (dctr[strsplit[i]] != pattern[i]):
                return False

        return True
