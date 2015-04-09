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

[1]> (defun do-hello-world ()
	"Hello, World!")
DO-HELLO-WORLD
[2]> (do-hello-world)
"Hello, World!"
[3]> (defun add-four (x)
	(+ x 4))
ADD-FOUR
[4]> (add-four 7)
11
[5]> (defun hypoteneuse (length width)
	(sqrt (+ (* length length)
		 (* width width))))
HYPOTENEUSE
[6]> (hypoteneuse 7 9)
11.401754
[7]> (defun first-n-chars (string n reverse-first)
	(if reverse-first
		(subseq (reverse string) 0 n)
		(subseq string 0 n)))
FIRST-N-CHARS
[8]> (first-n-chars "hello world" 5 nil)
"hello"
[9]> (first-n-chars "hello world" 5 t)
"dlrow"
[10]> (first-n-chars "hello world" 5 18)
"dlrow"
[11]> (defun print-string-stuff (string-1)
	(print string-1)
	(print (reverse string-1))
	(print (length string-1))
	string-1)
PRINT-STRING-STUFF
[12]> (print-string-stuff "Hello, World!")

"Hello, World!" 
"!dlroW ,olleH" 
13 
"Hello, World!"
[13]> (setf my-global-counter 0)
0
[14]> (defun increment-global-and-multiply (by-me)
	(setf my-global-counter (1+ my-global-counter))
	(* my-global-counter by-me))
INCREMENT-GLOBAL-AND-MULTIPLY
[15]> (increment-global-and-multiply 3)
3
[16]> (increment-global-and-multiply 5)
10
[17]> (increment-global-and-multiply 4)
12
[18]> (increment-global-and-multiply 7)
28
[19]> (defun factorial (n)
	(let ((sum 1))
	  (dotimes (x n)
	    (setf sum (* sum (1+ x))))
	  sum))
FACTORIAL
[20]> (factorial 1000)
402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
[21]> 

2       
2
[22]> (factorial 10)
3628800
[23]> (factorial 2)
2
[24]> (factorial 3)
6
[25]> (defun my-equation (n)
	(+ n (* (sin n) (cos n))))
MY-EQUATION
[26]> (my-equation 2)
1.6215987
[27]> (defun weird-function (n)
		(setf n 4)
		n)
WEIRD-FUNCTION
[28]> (setf abc 17)
17
[29]> (weird-function abc)
4
[30]> abc
17
[31]> (defun factorial (n)
	  (if (<= n 0)
		1
		(* n (factorial (- n 1)))))
FACTORIAL
[32]> (factorial 5)
120
[33]> (factorial 1000)
402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
[34]> (defun first-n-chars (string n &optional reverse-first)
	(if reverse-first
	  (subseq (reverse string) 0 n)
	  (subseq string 0 n)))
FIRST-N-CHARS
[35]> (first-n-chars "hello world" 5 nil) 
"hello"
[36]> (first-n-chars "hello world" 5)
"hello"
[37]> (first-n-chars "hello world" 5 t)
"dlrow"
[38]> (defun multiply-then-maybe-add (x y &optional (z 0))
	(+ (* x y) z))
MULTIPLY-THEN-MAYBE-ADD
[39]> (multiply-then-maybe-add 9 2)
18
[40]> (multiply-then-maybe-add 9 2 7)
25
[41]> (defun first-n-chars (string n
		&key reverse-first
		     (capitalize-first t))
	(let ((val (if capitalize-first
			(string-upcase string)
			string)))
	  (if reverse-first
	    (subseq (reverse val) 0 n)
	    (subseq val 0 n))))
FIRST-N-CHARS
[42]> (first-n-chars "hello world" 5 :revese-first t)

*** - FIRST-N-CHARS: illegal keyword/value pair :REVESE-FIRST, T in argument
      list.
      The allowed keywords are (:REVERSE-FIRST :CAPITALIZE-FIRST)
The following restarts are available:
ABORT          :R1      Abort main loop
Break 1 [43]> :R1
[44]> (first-n-chars "hello world" 5 :reverse-first t)
"DLROW"
[45]> (first-n-chars "hello world" 5
		:reverse-first t :capitalize-first nil)
"dlrow"
[46]> (first-n-chars "hello world" 5
		:capitalize-first nil :reverse-first t)
"dlrow"
[47]> (first-n-chars "hello world" 5)
"HELLO"
[48]> (first-n-chars "hello world" 5 :capitalize-first nil)
"hello"
[49]>     