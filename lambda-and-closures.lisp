
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

[1]> (map car #'(lambda (x) (print (* x 2)))
	       '(1 2 3 4 5 6))

*** - SYSTEM::READ-EVAL-PRINT: variable CAR has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of CAR.
STORE-VALUE    :R2      Input a new value for CAR.
ABORT          :R3      Abort main loop
Break 1 [2]> :R3
[3]> (mapcar #'(lambda (x) (print (* x 2)))
	      '(1 2 3 4 5 6))

2 
4 
6 
8 
10 
12 
(2 4 6 8 10 12)
[4]> (reduce #'(lambda (a b) (/ a (* b b)))
	      '(2 3 4))
1/72
[5]> (funcall #'(lambda (a b) (/ a (* b b))) 9 7)
9/49
[6]> (defun build-a-function (x)
	#'(lambda (y) (+ x y)))
BUILD-A-FUNCTION
[7]> (setf *+3* (build-a-function 3))
#<FUNCTION :LAMBDA (Y) (+ X Y)>
[8]> (funcall *+3* 9)
12
[9]> (funcall *+3* 2)
5
[10]> (setf *-6* (build-a-function -6)
)
#<FUNCTION :LAMBDA (Y) (+ X Y)>
[11]> (funcall *-6* 21)
15
[12]> (funcall *-6* (funcall *+3* 38))
35
[13]> (defun add-to-list (val list-of-numbers)
	(mapcar #'(lambda (num) (+ val num))
		list-of-numbers))
ADD-TO-LIST
[14]> (add-to-list 4 '(1 2 3 4 5))
(5 6 7 8 9)
[15]> (print "here's the more c++ way to do it...")

"here's the more c++ way to do it..." 
"here's the more c++ way to do it..."
[16]> (defun icky-add-to-list (val list-of-numbers)
	(let (bag)
	  (dolist (x list-of-numbers)
	    (push (+ val x) bag))
	  (reverse bag)))
ICKY-ADD-TO-LIST
[17]> (icky-add-to-list 4 '(1 2 3 4 5))
(5 6 7 8 9)
[18]> (let ((seed 1234))
	(defun rand ()
	  (setf seed (mod (* seed 16807) 2147483647))))
RAND
[19]> (rand)
20739838
[20]> (rand)
682106452
[21]> (rand)
895431078
[22]> seed

*** - SYSTEM::READ-EVAL-PRINT: variable SEED has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of SEED.
STORE-VALUE    :R2      Input a new value for SEED.
ABORT          :R3      Abort main loop
Break 1 [23]> :a
[24]> (let ((account 0))
	(defun deposit ($$$)
	  (setf account (+ account $$$)))
	(defun withdraw ($$$)
	  (setf account (- account $$$)))
	(defun amount ()
	  account))
AMOUNT
[25]> (deposit 42)
42
[26]> (withdraw 5)
37
[27]> (amount)
37
[28]> account

*** - SYSTEM::READ-EVAL-PRINT: variable ACCOUNT has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of ACCOUNT.
STORE-VALUE    :R2      Input a new value for ACCOUNT.
ABORT          :R3      Abort main loop
Break 1 [29]> :a
[30]> 
