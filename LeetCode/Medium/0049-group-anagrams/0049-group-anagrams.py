class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        str_dic = {}

        for string in strs:
            sorted_string = ''.join(sorted(string))

            if sorted_string not in str_dic:
                str_dic[sorted_string] = []
            
            str_dic[sorted_string].append(string)
        
        return list(str_dic.values())
        