
(defun skip-decimal-fraction (n)
  (multiple-value-bind (q r) (truncate (* 10 n))
    r))

(defun decimal-fractions (start)
  (loop for n = start then (skip-decimal-fraction n)
    until (or (= n 0) (member n seq))
    collecting n into seq
    finally (return (values n seq))))

(defun find-cycle (num)
    (multiple-value-bind (repeated-fraction fractions)
            (decimal-fractions num)
        (let ((pos (position repeated-fraction fractions)))
            (if pos
                (subseq fractions pos)
                '()))))

(defun find-cycle-len (d)
    (length (find-cycle (/ 1 d))))

(loop 
    with max = 0
    with max-d = 0
    with len = 0
    for d from 2 upto 1000
    do (setf len (find-cycle-len d))
    if (< max len)
    do (setf max len 
             max-d d)
    finally
        (format t "max is 1/~a with length ~a.~%"  max-d max))

