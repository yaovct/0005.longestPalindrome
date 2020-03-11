#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	int s_max, s_idx, cur_rep;
    	s_max = s_idx = cur_rep = 0;
    	int lps[500];
    	for(int i=0; i<s.size(); i++) {
    		for(int x=0; x<i+1; x++) {
    			if(x > s.size()/2) break;
    			if(i-x-1 < 0 || i+x > s.size()-1) break;
    			if(s[i-x-1] == s[i+x]) {
    				if(x*2+2 > s_max) {
    					s_max = x*2+2;
    					s_idx = x;
    					cur_rep = 1;
    				}
    				lps[x] = i;
    			} else {
    				break;
    			}
    		}
    		for(int x=0; x<i+1; x++) {
    			if(x > s.size()/2) break;
    			if(i-x < 0 || i+x > s.size()-1) break;
    			if(s[i-x] == s[i+x]) {
    				if(x*2+1 > s_max) {
    					s_max = x*2+1;
    					s_idx = x;
    					cur_rep = 0;
    					lps[x] = i;
    				}
    			} else {
    				break;
    			}
    		}
    	}
    	if(s.size() > 0) {
    		return s.substr(lps[s_idx] - s_idx - cur_rep, s_max);
    	} else {
    		return "";
    	}
    }
};

int main(int argc, char *argv[]) {
	string msg[14] = {"abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj","yfsrsrpzuya",""};

	Solution mySolution;
	for(int i=0; i<sizeof(msg)/sizeof(msg[0]); i++) {
		cout << msg[i] << " = " << mySolution.longestPalindrome(msg[i]) << endl;
	}
}