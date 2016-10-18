
(cl:in-package :asdf)

(defsystem "wrock-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :husky_wrock-msg
               :wrock-msg
)
  :components ((:file "_package")
    (:file "forward_d" :depends-on ("_package_forward_d"))
    (:file "_package_forward_d" :depends-on ("_package"))
    (:file "AddTwoInts" :depends-on ("_package_AddTwoInts"))
    (:file "_package_AddTwoInts" :depends-on ("_package"))
    (:file "inverse_d" :depends-on ("_package_inverse_d"))
    (:file "_package_inverse_d" :depends-on ("_package"))
    (:file "inverse_k" :depends-on ("_package_inverse_k"))
    (:file "_package_inverse_k" :depends-on ("_package"))
    (:file "laser_scan" :depends-on ("_package_laser_scan"))
    (:file "_package_laser_scan" :depends-on ("_package"))
  ))