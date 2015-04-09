;;;[A well-commented file]
;;; pi-estimation package
;;; Sean Luke
;;; Wednesday, 8/21/2002



;; ESTIMATE-PI will compute the value of pi to
;; the degree given, maintaining the value as a giant
;; fraction.  It uses the Leibniz (1674)
;; formula of pi = 4 * ( 1/1 - 1/3 + 1/5 - 1/7 + ...  )
;; degree must be an integer > 0.

(defun estimate-pi (degree)
  "Estimates pi using Leibniz's formula.
degree must be an integer greater than 0."
  (let ((sum 0) (inc 1))                ; inc goes 1, 5, 7, ...
    (dotimes (x degree (* 4 sum))       ; we return 4*sum
         #| (setf sum (+ sum (/ 1 inc))
                 (- 0 (/ 1 (+ inc 2)))) |#     ; yucky
      (setf sum (+ sum (/ 1 inc) (/ -1 (+ inc 2))))
      (setf inc (+ 4 inc)))))
