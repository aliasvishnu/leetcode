class Solution(object):

    def checkIPv4(self, ip):
        v4 = ip.split('.')
        print v4
        if len(v4) == 4 and ':' not in v4:
            for item in v4:
                print len(item)
                if len(item) > 3 or len(item) == 0:
                    return False
                if item[0] == '0' and len(item) != 1:
                    return False
                for c in item:
                    if c > '9' or c < '0':
                        return False

                if int(item) >= 256 or int(item) < 0:
                    return False
        else:
            return False

        return True

    def checkIPv6(self, ip):
        v6 = ip.split(':')
        print v6
        if len(v6) == 8 and '.' not in v6:
            for item in v6:
                print len(item)
                if len(item) > 4 or len(item) <= 0:
                    return False

                for c in item:
                    if (c >= '0' and c <= '9') or (c >= 'A' and c <= 'F') or (c >= 'a' and c <= 'f'):
                        continue
                    else:
                        return False
            return True
        return False

    def validIPAddress(self, ip):
        """
        :type IP: str
        :rtype: str
        """

        if(self.checkIPv4(ip)):
            return "IPv4"

        if(self.checkIPv6(ip)):
            return "IPv6"

        return "Neither"



        
