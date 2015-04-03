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

;;exercise on page
;;http://bzg.fr/learn-emacs-lisp-in-15-minutes.html
(+ 2 2)


(+ 2 (+ 1 1))


(+ 3 (+ 1 2))


(setq my-name "Bastien")


(insert "Hello!")


(insert "Hello" " world!")


(insert "Hello, I am " my-name)


(defun hello () (insert "Hello, I am " my-name))
(hello)


(defun hello (name) (insert "Hello " name))
(hello "you")


(switch-to-buffer-other-window "*test*")
#<buffer *test*>


(progn
  (switch-to-buffer-other-window "*test*")
  (hello "you"))


(progn
  (switch-to-buffer-other-window "*test*")
  (erase-buffer)
  (hello "there"))


(progn
  (switch-to-buffer-other-window "*test*")
  (erase-buffer)
  (hello "you")
  (other-window 1))


(let ((local-name "there"))
  (switch-to-buffer-other-window "*test*")
  (erase-buffer)
  (hello local-name)
  (other-window 1))


(format "Hello %s!\n" "Visitor")


(defun hello (name)
  (insert (format "Hello %s!\n" name)))
(hello "you")


(defun greeting (name)
  (let ((your-name "Bastien"))
    (insert (format "Hello %s!\n\nI am %s."
		    name
		    your-name
		    ))))
(greeting "you")


(read-from-minibuffer "Enter your name: ")


(defun greeting (from-name)
  (let ((your-name (read-from-minibuffer "Enter your name: ")))
    (insert (format "Hello!\n\nI am %s and you are %s."
		    from-name
		    your-name))))
(greeting "Bastien")


(defun greeting (from-name)
  (let ((your-name (read-from-minibuffer "Enter your name: ")))
    (switch-to-buffer-other-window "*test*")
    (erase-buffer)
    (insert (format "Hello %s!\n\nI am %s." your-name from-name))
    (other-window 1)))
(greeting "Bastien")


(setq list-of-names '("Sarah" "Chloe" "Mathilde"))
(car list-of-names)
(cdr list-of-names)
(push "Stephanie" list-of-names)

(mapcar 'hello list-of-names)


(defun greeting ()
  (switch-to-buffer-other-window "*test*")
  (erase-buffer)
  (mapcar 'hello list-of-names)
  (other-window 1))

(greeting)


(defun replace-hello-by-bonjour ()
  (switch-to-buffer-other-window "*test*")
  (goto-char (point-min))
  (while (search-forward "Hello")
    (replace-match "Bonjour"))
  (other-window 1))

(replace-hello-by-bonjour)


(defun hello-to-bonjour ()
  (switch-to-buffer-other-window "*test*")
  (erase-buffer)
  (mapcar 'hello list-of-names)
  (goto-char (point-min))
  (while (search-forward "Hello" nil t)
    (replace-match "Bonjour"))
  (other-window 1))

(hello-to-bonjour)


(defun boldify-names ()
  (switch-to-buffer-other-window "*test*")
  (goto-char (point-min))
  (while (re-search-forward "Bonjour \\(.+\\)!" nil t)
    (add-text-properties (match-beginning 1)
			 (match-end 1)
			 (list 'face 'bold)))
  (other-window 1))

(boldify-names)
