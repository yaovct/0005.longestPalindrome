#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_SIZE 40
	
char * longestPalindrome(char * s){
	int s_max, s_idx, cur_rep;
  s_max = s_idx = cur_rep = 0;
  int lps[500];
  if(strlen(s) == 0) return "";
	for(int i=0; i<strlen(s); i++) {
		for(int x=0; x<i+1; x++) {
			if(x > strlen(s)/2) break;
			if(i-x-1 < 0 || i+x > strlen(s)-1) break;
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
			if(x > strlen(s)/2) break;
			if(i-x < 0 || i+x > strlen(s)-1) break;
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
	int start = lps[s_idx] - s_idx - cur_rep;
	s[start + s_max] = '\0';
	
	return &s[start];
}


int main(int argc, char *argv[]) {
	char msg[][MAX_STRING_SIZE] = {"abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj","yfsrsrpzuya",""};

	for(int i=0; i<sizeof(msg)/sizeof(msg[0]); i++) {
		printf("%s = %s\n", msg[i], longestPalindrome(msg[i]));
	}
}