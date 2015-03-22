;; test
(+ 2 2)
(+ 2 (+ 1 1))
(+ 3 (+ 1 2))
(setq my-name "Bastien")
(insert "Hello!" "World!")
(insert "Helo, I am " my-name)
(defun hello () (insert "hello, I am " my-name))
(hello)
(defun hello (name) (insert "Hello " name))
(hello "you")

