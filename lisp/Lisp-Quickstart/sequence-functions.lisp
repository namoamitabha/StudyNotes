
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

[1]> (elt "hello world" 4)
#\o
[2]> (elt '(yo yo yo whats up?) 4)
UP?
[3]> (elt #(yo yo yo whats' up?) 4)
'UP?
[4]> (copy-seq "hello world")
"hello world"
[5]> (concatnate 'string '(#\y #\o) #(#\space) "what's up?")

*** - EVAL: undefined function CONCATNATE
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of (FDEFINITION 'CONCATNATE).
RETRY          :R2      Retry
STORE-VALUE    :R3      Input a new value for (FDEFINITION 'CONCATNATE).
ABORT          :R4      Abort main loop
Break 1 [6]> :R4
[7]> (concatenate 'string '(#\y #\o) #(#\space) "what's up?")
"yo what's up?"
[8]> (make-sequence 'string 4 :initial-element #\e)
"eeee"
[9]> (count #\l "hello world")
3
[10]> (count-if #'(lambda (i) (find i "aeiou")) "hello world")
3
[11]> (count-if-not #'alpha-char-p "hello world4")
2
[12]> (remove-if #'alpha-char-p "hello world4")
" 4"
[13]> (find-if #'(lambda (x) (< x 4)) #(4 9 7 2 1 0 3))
2
[14]> (position-if #'(lambda (x) (< x 4)) #(4 9 7 2 1 0 3))
3
[15]> (substitute-if 'number #'numberp '(a b 3 d "yo" 4.2 e))
(A B NUMBER D "yo" NUMBER E)
[16]> (substitute 3.14159 'pi
	'(pi a b pi c d e pi f pi pi g h pi)
	:start 4 :end 10)
(PI A B PI C D E 3.14159 F 3.14159 PI G H PI)
[17]> (search "wor" "hello world")
6
[18]> (setf *j* "hello world")
"hello world"
[19]> (substitute #\Q #\l *j*)
"heQQo worQd"
[20]> *j*
"hello world"
[21]> (nsubstitute #\Q #\l *j*)
"heQQo worQd"
[22]> *j*
"heQQo worQd"
[23]> (sort '(4 3 5 2 3 1 3) #'>)
(5 4 3 3 3 2 1)
[24]> (sort '(4 3 5 2 3 1 3) #'<)
(1 2 3 3 3 4 5)
[25]> 
