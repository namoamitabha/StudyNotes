
[angelo@centos ~]$ clisp
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

[1]> "List"  
"List"
[2]> "Lists and Symbols as Data"
"Lists and Symbols as Data"
[3]> (quote (hello world 1 2 3))
(HELLO WORLD 1 2 3)
[4]> (quote (what is (going on) here?))
(WHAT IS (GOING ON) HERE?)
[5]> (quote my-symbol)
MY-SYMBOL
[6]> (quote (+ 4 (* 3 2 9)))
(+ 4 (* 3 2 9))
[7]> (setf my-variable (quote hello))
HELLO
[8]> my-variable
HELLO
[9]> (setf my-variable (quote (hey yo yo)))
(HEY YO YO)
[10]> my-variable
(HEY YO YO)
[11]> (setf var2 (first my-variable))
HEY
[12]> (first my-variable)
HEY
[13]> (rest my-variable)
(YO YO)
[14]> (car my-variable)
HEY
[15]> (cdr my-variable)
(YO YO)
[16]> (setf var3 (rest my-variable))
(YO YO)
[17]> (cons 4 (rest my-variable))
(4 YO YO)
[18]> (append my-variable (quote (a b c)) my-variable)
(HEY YO YO A B C HEY YO YO)
[19]> (quote "hello")
"hello"
[20]> (quote 4.3)
4.3
[21]> (setf my-variable 'hello)
HELLO
[22]> (setf my-variable '(hey yo yo))
(HEY YO YO)
[23]> (append my-variable '(a b c) my-varible)

*** - SYSTEM::READ-EVAL-PRINT: variable MY-VARIBLE has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of MY-VARIBLE.
STORE-VALUE    :R2      Input a new value for MY-VARIBLE.
ABORT          :R3      Abort main loop
Break 1 [24]> '"hello"
"hello"
Break 1 [24]> '4.3
4.3
Break 1 [24]> '
test
TEST
Break 1 [24]> '(123.32 "hello" (how are (you there)) a)
(123.32 "hello" (HOW ARE (YOU THERE)) A)
Break 1 [24]> '(((wow)) a list consisting of a list of a list!)
(((WOW)) A LIST CONSISTING OF A LIST OF A LIST!)
Break 1 [24]> '()
NIL
Break 1 [24]> (rest '(list-of-one-thing))
NIL
Break 1 [24]> (append '(list-of-one-thing) nil)
(LIST-OF-ONE-THING)
Break 1 [24]> '(a b c () g h i)
(A B C NIL G H I)
Break 1 [24]> (dolist (x '(a b c d e))
		(print x))

A 
B 
C 
D 
E 
NIL
Break 1 [24]> (defun my-reverse (list)
		  (let (new-list)
		    (dolist (x list)
		      (setf new-list (cons x new-list)))
		    new-list))
MY-REVERSE
Break 1 [24]> (my-reverse '(a b c d e f g))
(G F E D C B A)
Break 1 [24]> (reverse '(a b c d e))
(E D C B A)
Break 1 [24]> (reverse "abcde")
"edcba"
Break 1 [24]> (subseq "Hello World" 2 9)
"llo Wor"
Break 1 [24]> (subseq '(yo hello there how are you) 2 4)
(THERE HOW)
Break 1 [24]> 
