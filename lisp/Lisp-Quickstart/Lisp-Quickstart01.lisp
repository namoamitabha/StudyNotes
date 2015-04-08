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

[1]> t
T
[2]> nil
NIL
[3]> (2)

*** - EVAL: 2 is not a function name; try using a symbol instead
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead.
ABORT          :R2      Abort main loop
Break 1 [4]> :a
[5]> t
T
[6]> h

*** - SYSTEM::READ-EVAL-PRINT: variable H has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of H.
STORE-VALUE    :R2      Input a new value for H.
ABORT          :R3      Abort main loop
Break 1 [7]> :h

Commands may be abbreviated as shown in the second column.
COMMAND        ABBR     DESCRIPTION
Help           :h, ?    print this command list
Error          :e       print the last error message
Inspect        :i       inspect the last error
Abort          :a       abort to the next recent input loop
Unwind         :uw      abort to the next recent input loop
Reset          :re      toggle *PACKAGE* and *READTABLE* between the
                          local bindings and the sane values
Quit           :q       quit to the top-level input loop
Where          :w       inspect this frame
Up             :u       go up one frame, inspect it
Top            :t       go to top frame, inspect it
Down           :d       go down one frame, inspect it
Bottom         :b       go to bottom (most recent) frame, inspect it
Mode mode      :m       set stack mode for Backtrace: 1=all the stack elements
             2=all the frames                         3=only lexical frames
             4=only EVAL and APPLY frames (default)   5=only APPLY frames
Frame-limit n  :fl      set the frame-limit for Backtrace. This many frames
                          will be printed in a backtrace at most.
Backtrace [mode [limit]] :bt  inspect the stack
Break+         :br+     set breakpoint in EVAL frame
Break-         :br-     disable breakpoint in EVAL frame
Redo           :rd      re-evaluate form in EVAL frame
Return value   :rt      leave EVAL frame, prescribing the return values
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of H.
STORE-VALUE    :R2      Input a new value for H.
ABORT          :R3      Abort main loop
Break 1 [7]> :a
[8]> t
T
[9]> (+ 3 2 7 9)
21
[10]> (* 4 2.3)
9.2
[11]> (+ 3 2)
5
[12]> (subseq "Hello, World" 2 9)
"llo, Wo"
[13]> (+ 27/32 32/57)
2563/1824
[14]> (* 2.342 3.2e4)
74944.0
[15]> (* 2.342 9.212 -9.23 3/4)
-149.34949
[16]> (/ 3 5)
3/5
[17]> (/ 3.0 5)
0.6
[18]> (1+ 3)
4
[19]> (2 + 4)

*** - EVAL: 2 is not a function name; try using a symbol instead
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead.
ABORT          :R2      Abort main loop
Break 1 [20]> (2+ 3)

*** - EVAL: undefined function 2+
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of (FDEFINITION '2+).
RETRY          :R2      Retry
STORE-VALUE    :R3      Input a new value for (FDEFINITION '2+).
ABORT          :R4      Abort debug loop
ABORT          :R5      Abort main loop
Break 2 [21]> (1+ 3)
4
Break 2 [21]> (2+ 5)

*** - EVAL: undefined function 2+
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of (FDEFINITION '2+).
RETRY          :R2      Retry
STORE-VALUE    :R3      Input a new value for (FDEFINITION '2+).
ABORT          :R4      Abort debug loop
ABORT          :R5      Abort debug loop
ABORT          :R6      Abort main loop
Break 3 [22]> :a
Break 2 [21]> :a
Break 1 [20]> :a
[23]> :top
:TOP
[24]> (1+ 4)
5
[25]> (string-upcase "How about that!")
"HOW ABOUT THAT!"
[26]> (reverse "Four score and seven years ago")
"oga sraey neves dna erocs ruoF"
[27]> (length "Four score and seven years ago")
30
[28]> (sqrt 2)
1.4142135
[29]> (sqrt -1.0)
#C(0 1.0)
[30]> (SqRt -1.0)
#C(0 1.0)
[31]> (+ 100 231 201 921 221 231 -23 12 -34 134)
1994
[32]> (subseq "Four score and seven years ago" 9)
"e and seven years ago"
[33]> (subseq "Four score and seven years ago" 9 23)
"e and seven ye"
[34]> (= 4 3)
NIL
[35]> (= 4 4)
T
[36]> (< 3 9)
T
[37]> (numberp "hello")
NIL
[38]> (numberp 3)
T
[39]> (oddp 9)
T
[40]> (oddp 4)
NIL
[41]> (/ 1 0)

*** - /: division by zero
The following restarts are available:
ABORT          :R1      Abort main loop
Break 1 [42]> ^C
*** - Ctrl-C: User break
The following restarts are available:
ABORT          :R1      Abort debug loop
ABORT          :R2      Abort main loop
Break 2 [43]> :top
:TOP
Break 2 [43]> :a
Break 1 [42]> :a
[44]> (blah-blah 1 0 "foo")

*** - EVAL: undefined function BLAH-BLAH
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of (FDEFINITION 'BLAH-BLAH).
RETRY          :R2      Retry
STORE-VALUE    :R3      Input a new value for (FDEFINITION 'BLAH-BLAH).
ABORT          :R4      Abort main loop
Break 1 [45]> :R4
[46]> (+ 33 (* 2.3 4) 9)
51.2
[47]> (+ (length "Hello World") 44)
55
[48]> (* (+ 3 2.3) (/ 3 (- 9 4)))
3.1800003
[49]> (log (log (log 234231232234234123)))
1.3052895
[50]> (+ (* (sin 0.3)
            (sin 0.3))
	 (* (cos 0.3)
	    (cos 0.3)))
1.0000001
[51]> (and (< 3 (* 2 5))
	   (not (>= 2 6)))
T
[52]> (print (+ 2 3 4 1))

10 
10
[53]> (print "hello")

"hello" 
"hello"
[54]> (+ (* 2 3) (/ 3 2) 9)
33/2
[55]> (+ (print (* 2 3)) (print (/ 3 2)) 9)

6 
3/2 
33/2
[56]> (if (<= 3 2) (* 3 9) (+ 4 2 3))
9
[57]> (if (> 2 3) 9)
NIL
[58]> (if (= 2 2) (if (> 3 2) 4 6) 9)
4
[59]> (+ 4 (if (= 2 2) (* 9 2) 7))
22
[60]> (if (> 3 2)
           (progn (print "hello") (print "yo")
		  (print "whassup?") 9)
	   (+ 4 2 3))

"hello" 
"yo" 
"whassup?" 
9
[61]> (setf x (* 3 2))
6
[62]> x
6
[63]> (setf y (+ x 3))
9
[64]> (* x y)
54
[65]> (setf sin 9)
9
[66]> (sin sin)
0.4121185
[67]> z

*** - SYSTEM::READ-EVAL-PRINT: variable Z has no value
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead of Z.
STORE-VALUE    :R2      Input a new value for Z.
ABORT          :R3      Abort main loop
Break 1 [68]> :a
[69]> (+ x (setf x 3) x)
12
[70]> (setf x 4)
4
[71]> (let ((x 3))
	(print x)
	(setf x 9)
	(print x)
	(print "hello"))

3 
9 
"hello" 
"hello"
[72]> (let (print "hello"))

*** - LET: illegal variable specification "hello"
The following restarts are available:
USE-VALUE      :R1      Input a value to be used instead.
ABORT          :R2      Abort main loop
Break 1 [73]> :R2
[74]> (let ((x 3)) (print "hello"))

"hello" 
"hello"
[75]> (print "hello")

"hello" 
"hello"
[76]> x
4
[77]> (let ((x 3) (y (+ 4 9)))
	(* x y))
39
[78]> (let (( x 3))
	(print x)
	(let (x)
		(print x)
		(let ((x "hello"))
        		(print x))
		(print x))
	(print x)
	(print "yo"))

3 
NIL 
"hello" 
NIL 
3 
"yo" 
"yo"
[79]> (setf x 3)
3
[80]> (dotimes (x 4 "yo") (print "hello"))

"hello" 
"hello" 
"hello" 
"hello" 
"yo"
[81]> x 
3
[82]> (setf bag 2)
2
[83]> (dotimes (x 6) (setf bag (* bag bag)))
NIL
[84]> bag
18446744073709551616
[85]> (dotimes (x 6) (setf bag (* bag bag)) (print bag))

340282366920938463463374607431768211456 
115792089237316195423570985008687907853269984665640564039457584007913129639936 
13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096 
179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216 
32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230656 
1044388881413152506691752710716624382579964249047383780384233483283953907971557456848826811934997558340890106714439262837987573438185793607263236087851365277945956976543709998340361590134383718314428070011855946226376318839397712745672334684344586617496807908705803704071284048740118609114467977783598029006686938976881787785946905630190260940599579453432823469303026696443059025015972399867714215541693835559885291486318237914434496734087811872639496475100189041349008417061675093668333850551032972088269550769983616369411933015213796825837188091833656751221318492846368125550225998300412344784862595674492194617023806505913245610825731835380087608622102834270197698202313169017678006675195485079921636419370285375124784014907159135459982790513399611551794271106831134090584272884279791554849782954323534517065223269061394905987693002122963395687782878948440616007412945674919823050571642377154816321380631045902916136926708342856440730447899971901781465763473223850267253059899795996090799469201774624817718449867455659250178329070473119433165550807568221846571746373296884912819520317457002440926616910874148385078411929804522981857338977648103126085903001302413467189726673216491511131602920781738033436090243804708340403154190336 
NIL
[86]> bag
1044388881413152506691752710716624382579964249047383780384233483283953907971557456848826811934997558340890106714439262837987573438185793607263236087851365277945956976543709998340361590134383718314428070011855946226376318839397712745672334684344586617496807908705803704071284048740118609114467977783598029006686938976881787785946905630190260940599579453432823469303026696443059025015972399867714215541693835559885291486318237914434496734087811872639496475100189041349008417061675093668333850551032972088269550769983616369411933015213796825837188091833656751221318492846368125550225998300412344784862595674492194617023806505913245610825731835380087608622102834270197698202313169017678006675195485079921636419370285375124784014907159135459982790513399611551794271106831134090584272884279791554849782954323534517065223269061394905987693002122963395687782878948440616007412945674919823050571642377154816321380631045902916136926708342856440730447899971901781465763473223850267253059899795996090799469201774624817718449867455659250178329070473119433165550807568221846571746373296884912819520317457002440926616910874148385078411929804522981857338977648103126085903001302413467189726673216491511131602920781738033436090243804708340403154190336
[87]> (setf bag 2)
2
[88]> (dotimes (x 6) (setf bag (* bag bag)) (print bag))

4 
16 
256 
65536 
4294967296 
18446744073709551616 
NIL
[89]> 
