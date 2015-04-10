;;function-funcall-and-apply

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

[1]>  (function print)
#<SYSTEM-FUNCTION PRINT>
[2]> (function if)

*** - FUNCTION: undefined function IF
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of (FDEFINITION 'IF).
RETRY          :R2      Retry
STORE-VALUE    :R3      Input a new value for (FDEFINITION 'IF).
ABORT          :R4      Abort main loop
Break 1 [3]> :R4
[4]> (setf *temp* (function *))
#<SYSTEM-FUNCTION *>
[5]> *temp

*** - SYSTEM::READ-EVAL-PRINT: variable *TEMP has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of *TEMP.
STORE-VALUE    :R2      Input a new value for *TEMP.
ABORT          :R3      Abort main loop
Break 1 [6]> :R3
[7]> *temp*
#<SYSTEM-FUNCTION *>
[8]> #'print
#<SYSTEM-FUNCTION PRINT>
[9]> (setf *temp* #'*)
#<SYSTEM-FUNCTION *>
[10]> *temp*
#<SYSTEM-FUNCTION *>
[11]> (setf *new-print* (function print))
#<SYSTEM-FUNCTION PRINT>
[12]> (*new-print* "hello world")

*** - EVAL: undefined function *NEW-PRINT*
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of (FDEFINITION '*NEW-PRINT*).
RETRY          :R2      Retry
STORE-VALUE    :R3      Input a new value for (FDEFINITION '*NEW-PRINT*).
ABORT          :R4      Abort main loop
Break 1 [13]> :a
[14]> (setf *new-print* (function print))
#<SYSTEM-FUNCTION PRINT>
[15]> (funcall *new-print* "hello world")

"hello world" 
"hello world"
[16]> (funcall #'+ 1 2 3 4 5 6 7)
28
[17]> (funcall #'funcall #'+ 1 2 3 4 5 6 7)
28
[18]> (apply #'+ '(1 2 3 4 5 6))
21
[19]> (apply #'+ 1 2 3 4 5 6 nil)
21
[20]> (apply #'apply #'+ '(1 2 3 (4 5 6)))
21
[21]> (apply #'funcall #'+ '(1 2 3 4 5 6))
21
[22]> (funcall #'apply #'+ '(1 2 3 4 5 6))
21
[23]>   


