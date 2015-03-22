(+ 2 4)

(+ 3 4 8)

'(this is a quoted list)

3

(+ 3 4 8)

(+ (* 3 (+ 7 19.5)) 4)

(+ (* 3 5)
   (* 47
      (- 20 6.8))
   12)

(defun foo () 5)
(foo)

(defun A () (* 5 5))
(* (A) (A))

(defun B () (+ (A) (* 5 (A))))
(B)

( + (A) (/ (B) 5))

(defun C () (+ (B) (B)))
(C)

(defun square (x) (* x x))
(square 10)
(square 1001)
(square (+ 5 7))
(+ (square 3) (square 4))
(square (square (square 1001))) ;; the value is not expectd that same as video
(insert "test" '(square (square (square 1001))))
square
;; (defun square (lambda (x) (* x x)))
;; (square 10)
