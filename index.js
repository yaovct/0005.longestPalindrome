/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {

	var s_max, s_idx, cur_rep;
	s_max = s_idx = cur_rep = 0;
	var lps = []
	var dic = [];
	for(var i=0; i<s.length; i++) {
		for(var x=0; x<i+1; x++) {
			if(x > s.length/2) break;
			if( i-x-1 < 0 || i+x > s.length-1) break;
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
		for(var x=0; x<i+1; x++) {
			if(x > s.length/2) break;
			if( i-x < 0 || i+x > s.length-1) break;
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
	return s.substr(lps[s_idx] - s_idx - cur_rep, s_max);
};

var msg = ["abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya"];

for(var i=0; i<msg.length; i++) {
	console.log(msg[i] + " = " + longestPalindrome(msg[i]));
}
