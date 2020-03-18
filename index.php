<?php

class Solution {

    /**
     * @param String $s
     * @return String
     */
    function longestPalindrome($s) {

    	$s_max = $s_idx = $cur_rep = 0;
    	$lps = Array();
    	for($i=0; $i<strlen($s); $i++) {
    		for($x=0; $x<$i+1; $x++) {
    			if($x > strlen($s)/2) break;
    			if($i-$x-1 < 0 || $i+$x > strlen($s)-1) break;
    			if($s[$i-$x-1] == $s[$i+$x]) {
    				if($x*2+2 > $s_max) {
    					$s_max = $x*2+2;
    					$s_idx = $x;
    					$cur_rep = 1;
    				}
    				$lps[$x] = $i;
    			} else {
    				break;
    			}
    		}
    		for($x=0; $x<$i+1; $x++) {
    			if($x > strlen($s)/2) break;
    			if($i-$x < 0 || $i+$x > strlen($s)-1) break;
    			if($s[$i-$x] == $s[$i+$x]) {
    				if($x*2+1 > $s_max) {
    					$s_max = $x*2+1;
    					$s_idx = $x;
    					$cur_rep = 0;
    					$lps[$x] = $i;
    				}
    			} else {
    				break;
    			}
    		}
    	}
    	if(strlen($s) > 0) {
    		return substr($s, $lps[$s_idx] - $s_idx - $cur_rep, $s_max);
    	} else {
    		return "";
    	}
    }
}

$msg = array("abcabcbb","bbbbb","pwwkew","dvdf","bbtablud","nfpdmpi","dfevdfg","jbpnbwwd","umvejcuuk","tmmzuxt","ohvhjdml","anviaj",
"yfsrsrpzuya");
$testSolution = new Solution();
for($i=0; $i<count($msg); $i++) {
	printf("%s => %s\n",$msg[$i], $testSolution->longestPalindrome($msg[$i]));
}

?>