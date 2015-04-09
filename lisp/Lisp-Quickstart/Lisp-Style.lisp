;;lisp style

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

[1]> (load "Lisp-Style02.lisp")
;; Loading file Lisp-Style02.lisp ...
;; Loaded file Lisp-Style02.lisp
T
[2]> (documentation 'estimate-pi 'function)
"Estimates pi using Leibniz's formula.
degree must be an integer greater than 0."
[3]> (describe 'estimate-pi)

ESTIMATE-PI is the symbol ESTIMATE-PI, lies in #<PACKAGE COMMON-LISP-USER>, is
accessible in 1 package COMMON-LISP-USER, names a function, has 2 properties
SYSTEM::DEFINITION, SYSTEM::DOC.
Documentation as a FUNCTION:
Estimates pi using Leibniz's formula.
degree must be an integer greater than 0.
For more information, evaluate (SYMBOL-PLIST 'ESTIMATE-PI).

 #<PACKAGE COMMON-LISP-USER> is the package named COMMON-LISP-USER. It has 2
 nicknames CL-USER, USER.
 It imports the external symbols of 2 packages COMMON-LISP, EXT and exports
 no symbols, but no package uses these exports.

 #<FUNCTION ESTIMATE-PI (DEGREE) ...> is an interpreted function.
 Argument list: (DEGREE)
 Documentation:
 Estimates pi using Leibniz's formula.
 degree must be an integer greater than 0.

Documentation:
SYSTEM::FILE:
((SYSTEM::DEFUN/DEFMACRO
   #P"/home/angelo/git-root/study-notes/lisp/Lisp-Quickstart/Lisp-Style02.lisp"
   1 22))

[4]> (defparameter *tuning-value* 4.0
        "The tuning value of the amplitude dial")
*TUNING-VALUE*
[5]> (defconstant *low-quality-pi* 3.14159
        "Pi to only six digits")
*LOW-QUALITY-PI*
[6]> (documentation '*tuning-value* 'variable)
"The tuning value of the amplitude dial"
[7]> (describe '*low-quality-pi*)

*LOW-QUALITY-PI* is the symbol *LOW-QUALITY-PI*, lies in
#<PACKAGE COMMON-LISP-USER>, is accessible in 1 package COMMON-LISP-USER, a
constant, value: 3.14159, has 1 property SYSTEM::DOC.
Documentation as a VARIABLE:
Pi to only six digits
For more information, evaluate (SYMBOL-PLIST '*LOW-QUALITY-PI*).

 #<PACKAGE COMMON-LISP-USER> is the package named COMMON-LISP-USER. It has 2
 nicknames CL-USER, USER.
 It imports the external symbols of 2 packages COMMON-LISP, EXT and exports
 no symbols, but no package uses these exports.

 3.14159 is a float with 24 bits of mantissa (single-float).

Documentation:
VARIABLE:
"Pi to only six digits"

[8]> 
