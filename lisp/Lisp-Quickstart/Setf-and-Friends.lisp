;;Setf-and-Friends

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

[1]> (setf *j* #(a b c d e))
#(A B C D E)
[2]> (setf (svref *j* 3) 'hello)
HELLO
[3]> (setf *k* (make-array '(3 3 3) :initial-element 4))
#3A(((4 4 4) (4 4 4) (4 4 4))
    ((4 4 4) (4 4 4) (4 4 4))
    ((4 4 4) (4 4 4) (4 4 4)))
[4]> (vector-pop *j*)

*** - VECTOR-POP: vector #(A B C HELLO E) has no fill pointer
The following restarts are available:
ABORT          :R1      Abort main loop
Break 1 [5]> :R1
[6]> (setf (aref *k* 2 1 1) 'yo)
YO
[7]> *k*
#3A(((4 4 4) (4 4 4) (4 4 4))
    ((4 4 4) (4 4 4) (4 4 4))
    ((4 4 4) (4 YO 4) (4 4 4)))
[8]> (setf *l* "hello world")
"hello world"
[9]> (setf (char *l* 4) #\B)
#\B
[10]> *l*
"hellB world"
[11]> (setf *j* #(1 2 3 4 5))
#(1 2 3 4 5)
[12]> (incf (svref *j* 3) 4)
8
[13]> *j*
#(1 2 3 8 5)
[14]> (setf *k* 4)
4
[15]> (incf *k*)
5
[16]> *k*
5
[17]> (decf *k* 100)
-95
[18]> *k*
-95
[19]> (setf *j* #((a b) (c d) (e f)))
#((A B) (C D) (E F))
[20]> (push 'hello (svref *j* 1))
(HELLO C D)
[21]> *j*
#((A B) (HELLO C D) (E F))
[22]> (push 'world (svref *j* 2))
(WORLD E F)
[23]> *j*
#((A B) (HELLO C D) (WORLD E F))
[24]> (setf *k* '(yo yo ma))
(YO YO MA)
[25]> (pop *k*)
YO
[26]> *k*
(YO MA)
[27]> (setf *j* #(gracias senor))
#(GRACIAS SENOR)
[28]> (setf *k* 'hello)
HELLO
[29]> (rotatef (elt *j* 0) (elt *j* 1) *k*)
NIL
[30]> *j*
#(SENOR HELLO)
[31]> *k*
GRACIAS
[32]> (setf *z* #(1 2 3 4 5))
#(1 2 3 4 5)
[33]> (rotatef (elt *z* 1) (elt *z* 4))
NIL
[34]> *z*
#(1 5 3 4 2)
[35]> 


