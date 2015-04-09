
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

[1]> '"Loading and Compiling Lisp"
"Loading and Compiling Lisp"
[2]> (defun slow-function (a)
	(dotimes (x 100000)
		(setf a (+ a 1)))
	a)
SLOW-FUNCTION
[3]> (time (slow-function 0))
Real time: 0.070409 sec.
Run time: 0.070484 sec.
Space: 0 Bytes
100000
[4]> (compile 'slow-function)
SLOW-FUNCTION ;
NIL ;
NIL
[5]> (time (slow-function 0))
Real time: 0.003373 sec.
Run time: 0.003371 sec.
Space: 0 Bytes
100000
[6]> load ~/git-root/study-notes/lisp/Lisp-Quickstart/Loading-and-Compiling-Lisp01.lisp

*** - SYSTEM::READ-EVAL-PRINT: variable LOAD has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of LOAD.
STORE-VALUE    :R2      Input a new value for LOAD.
ABORT          :R3      Abort main loop
Break 1 [7]> (load "~/git-root/study-notes/lisp/Lisp-Quickstart/Loading-and-Compiling-Lisp01.lisp
"
)

*** - LOAD: A file with name

      /home/angelo/git-root/study-notes/lisp/Lisp-Quickstart/Loading-and-Compiling-Lisp01.lisp
      does not exist
The following restarts are available:
ABORT          :R1      Abort debug loop
ABORT          :R2      Abort main loop
Break 2 [8]> :R2
[9]> 


[angelo@centos Lisp-Quickstart]$ pwd
/home/angelo/git-root/study-notes/lisp/Lisp-Quickstart
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

[1]> (load "Loading-and-Compiling-Lisp01.lisp")
;; Loading file Loading-and-Compiling-Lisp01.lisp ...
HELLO 
;; Loaded file Loading-and-Compiling-Lisp01.lisp
T
[2]> (load "Loading-and-Compiling-Lisp01.lisp" :print t)
;; Loading file Loading-and-Compiling-Lisp01.lisp ...
3
MY-FUNC
3
0.14112
HELLO 
HELLO
;; Loaded file Loading-and-Compiling-Lisp01.lisp
T
[3]> (compile-file "Loading-and-Compiling-Lisp01.lisp")
;; Compiling file /home/angelo/git-root/study-notes/lisp/Lisp-Quickstart/Loading-and-Compiling-Lisp01.lisp ...
WARNING: in #:|1 1 (SETF FOO 3)-1| in line 1 : FOO is neither declared nor
         bound,
         it will be treated as if it were declared SPECIAL.
WARNING: in #:|4 5 FOO-3| in lines 4..5 : FOO is neither declared nor bound,
         it will be treated as if it were declared SPECIAL.
WARNING: in #:|5 5 (SIN FOO)-4| in line 5 : FOO is neither declared nor bound,
         it will be treated as if it were declared SPECIAL.
;; Wrote file /home/angelo/git-root/study-notes/lisp/Lisp-Quickstart/Loading-and-Compiling-Lisp01.fas
The following special variables were not defined:
 FOO
0 errors, 3 warnings
#P"/home/angelo/git-root/study-notes/lisp/Lisp-Quickstart/Loading-and-Compiling-Lisp01.fas" ;
3 ;
3
[4]> (load "Loading-and-Compiling-Lisp01.fas")
;; Loading file Loading-and-Compiling-Lisp01.fas ...
HELLO 
;; Loaded file Loading-and-Compiling-Lisp01.fas
T
[5]> 
