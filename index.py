class Solution(object):
  def longestPalindrome(self, s):
    """
    :type s: str
    :rtype: str
    """
    # lps[3] = 3 (d) for abcdcbak
    # lps[2] = 4 (b) for cccabac
    # lps[1] = 1 (b) for caba
    lps = {} # to save the longest palindromic substring with steps (key)
    dic = []
    s_idx = 0
    s_max = 0
    cur_rep = 0
    for index, e in enumerate(s):

    	for x in range(0, index+1):
    		if x > len(s)/2:
    			break
    		if index - x - 1 < 0 or index + x > len(s) - 1:
    			break
    		if s[index - x - 1] == s[index + x]:
    			if x * 2 + 2 > s_max:
    				s_max = x * 2 + 2
    				s_idx = x
    				cur_rep = 1
    			lps[x] = index
    		else:
    			break

    	for x in range(0, index+1):
    		if x > len(s)/2:
    			break
    		if index - x < 0 or index + x > len(s) - 1:
    			break
    		if s[index - x] == s[index + x]:
    			if x * 2 + 1 > s_max:
    				s_max = x * 2 + 1
    				s_idx = x
    				cur_rep = 0
    				lps[x] = index
    		else:
    			break

    #print("%s %d" % (lps, cur_rep))
    for i in range(0, s_max):
    	dic.append(s[lps[s_idx] - s_idx + i - cur_rep])
    
    return ''.join(dic)

my_test = Solution()
msg = ["abcbabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj","yfsrsrpzuya"]
for m in msg:
	print("%s = %s" % (m,my_test.longestPalindrome(m)))
    	