#!/usr/local/bin/perl

for($a = 0; $a <= 256; $a = $a + 1) {
    if (chr($a) =~ /^[a-z]$/) {
	printf chr($a);
    }
}
printf "\n";
