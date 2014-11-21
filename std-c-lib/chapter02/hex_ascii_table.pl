#!/usr/local/bin/perl

for($a = 0; $a <= 256; $a = $a + 1) {
    if (chr($a) =~ /^[a-z]$/i) {
	printf " '%s', ", uc(chr($a));
    } else {
	printf "0x%.2x, ", $a;
    }
    
    if (($a < 8) && ($a != 0) && (0 == (($a) % 7))) {
	printf "\n";
    } elsif (0 == (($a - 7) % 8)) {
	printf "\n";
    }

}
