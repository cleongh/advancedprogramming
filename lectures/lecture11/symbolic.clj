; clj
; (load-file "symbolic.clj")
; (-main)

; macros DON'T get their parameters evaluated before the call
(defmacro twice [e] `(do ~e ~e))

(defn -main []
  ; defining a value for "a". quoting prevents evaluation
  (let [a '(println "hola")]
    ; run println. same structure as data
    (println "hola")
    ; run a. eval'ing a quoted s-exp "removes" the quote
    (eval a)
    (eval a)
    (twice (println "hola macro"))))

