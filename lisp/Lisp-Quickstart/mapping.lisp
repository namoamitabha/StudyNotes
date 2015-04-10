
[angelo@centos Lisp-Quickstart]$ clisp
  i i i i i i i       ooooo    o        ooooooo   ooooo   ooooo
  I I I I I I I      8     8   8           8     8     o  8    8
  I  \ `+' /  I      8         8           8     8        8    8
   \  `-+-'  /       8         8           8      ooooo   8oooo
    `-__|__-'        8         8           8           8  8
        |            8     o   8           8     o     8  8
  ------+------       ooooo    8oooooo  ooo8ooo   ooooo   8

Welcome to GNU CLISP 2.49 (2010-07-07) <http://clisp.cons.org/>

Copyright (c) Bruno Haible, Michael Stoll 1992, 1993
Copyright (c) Bruno Haible, Marcus Daniels 1994-1997
Copyright (c) Bruno Haible, Pierpaolo Bernardi, Sam Steingold 1998
Copyright (c) Bruno Haible, Sam Steingold 1999-2000
Copyright (c) Sam Steingold, Bruno Haible 2001-2010

Type :h and hit Enter for context help.

[1]> (mapcar #'sqrt '(3 4 5 6 7))
(1.7320508 2 2.236068 2.4494898 2.6457512)
[2]> (mapcar (function print) '(hello there how are you))

HELLO 
THERE 
HOW 
ARE 
YOU 
(HELLO THERE HOW ARE YOU)
[3]> (mapcar #'/ '(1 2 3 4 5) '(7 8 9 10 11))
(1/7 1/4 1/3 2/5 5/11)
[4]> (mapcar #'* '(1 2 3 4) '(5 6) '(7 8 9))
(35 96)
[5]> (reduce #'expt '(2 3 4 5))
1152921504606846976
[6]> (reduce #'expt '(2 3 4) :from-end t)
2417851639229258349412352
[7]> (expt 3 4)
81
[8]> (expt 2 81)
2417851639229258349412352
[9]> 
