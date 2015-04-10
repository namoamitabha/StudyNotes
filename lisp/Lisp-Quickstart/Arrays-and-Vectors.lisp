
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

[1]> "Arrays and Vectors"
"Arrays and Vectors"
[2]> (make-array 4)
#(NIL NIL NIL NIL)
[3]> #(a b c)
#(A B C)
[4]> (make-array '(4 3 8))
#3A(((NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL))
    ((NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL))
    ((NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL))
    ((NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL)
     (NIL NIL NIL NIL NIL NIL NIL NIL)))
[5]> (make-array '(2 2) :initial-element 0)
#2A((0 0) (0 0))
[6]> (setf *j* #2A((1 2 3) (4 5 6)))
#2A((1 2 3) (4 5 6))
[7]> *j*
#2A((1 2 3) (4 5 6))
[8]> (aref *j* 1 1)
5
[9]> (aref #(a b c d e) 3)
D
[10]> (svref #(a b c d e) 3)
D
[11]> time (svref #(a b c d e) 3)

*** - SYSTEM::READ-EVAL-PRINT: variable TIME has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of TIME.
STORE-VALUE    :R2      Input a new value for TIME.
ABORT          :R3      Abort main loop
Break 1 [12]> :R3
[13]> (setf *j* (make-array 0 :file-pointer t :adjustable t))

*** - MAKE-ARRAY: illegal keyword/value pair :FILE-POINTER, T in argument
      list.
      The allowed keywords are
       (:ADJUSTABLE :ELEMENT-TYPE :INITIAL-ELEMENT :INITIAL-CONTENTS
        :FILL-POINTER :DISPLACED-TO :DISPLACED-INDEX-OFFSET)

The following restarts are available:
ABORT          :R1      Abort main loop
Break 1 [14]> :R1
[15]> (setf *j* (make-array 0 :fill-pointer t :adjustable t))
#()
[16]> (vector-push-extend 10 *j*)
0
[17]> *j*
#(10)
[18]> (vector-push-extend 'hello *j*)
1
[19]> *j*
#(10 HELLO)
[20]> (aref *j* 1)
HELLO
[21]> (vector-pop *j*)
HELLO
[22]> *j*
#(10)
[23]> (vector-pop *j*)
10
[24]> (vector-pop *j*)

*** - VECTOR-POP: #() has length zero
The following restarts are available:
ABORT          :R1      Abort main loop
Break 1 [25]> :R1
[26]> (aref "hello world" 3)
#\l
[27]> (char "hello world" 6)
#\w
[28]> 
