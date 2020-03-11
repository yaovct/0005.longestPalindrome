import java.lang.*;
import java.util.*;

class Solution {
  public String longestPalindrome(String s) {
  	int s_max = 0;
  	int s_idx = 0;
  	int cur_rep = 0;
  	int[] lps = new int[500];
  	for(int i=0; i<s.length(); i++) {
  		for(int x=0; x<i+1; x++) {
  			if(x > s.length()/2) break;
  			if(i-x-1 < 0 || i+x > s.length()-1) break;
  			if(s.charAt(i-x-1) == s.charAt(i+x)) {
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
  			if(x > s.length()/2) break;
  			if( i-x < 0 || i+x > s.length()-1) break;
  			if(s.charAt(i-x) == s.charAt(i+x)) {
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
  	//char[] dic = new char[s_max];
  	//for(int i=0; i<s_max; i++) {
  	//	dic[i] = s.charAt(lps[s_idx] - s_idx + i - cur_rep);
  	//}
  	//System.out.printf("%d\n",dic.length);
  	//return new String(dic);
  	return s.substring(lps[s_idx] - s_idx - cur_rep, lps[s_idx] - s_idx - cur_rep + s_max);
  }
}

public class index {

	public static void main(String[] args) {
		String[] msg = new String[] {"babad", "abcabacbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya"};

    Solution demo = new Solution();
    for(int i=0; i<msg.length; i++) {
    	System.out.printf("%s = %s\n", msg[i], demo.longestPalindrome(msg[i]));
    }
	}
}