
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

[1]> (defun mean (first-num &rest others)
        "returns the mean of a bunch of numbers.
	There must be at least one number."
	(let ((nums (cons first-num others))) ; nums is list of the numbers
	(/ (apply #'+ nums)
	   (length nums))))
MEAN
[2]> (mean 10 2 3 4)
19/4
[3]> (mean 10)
10
[4]> (mean)

*** - EVAL/APPLY: Too few arguments (0 instead of at least 1) given to
      MEAN
The following restarts are available:
ABORT          :R1      Abort main loop
Break 1 [5]> :R1
[6]> 
