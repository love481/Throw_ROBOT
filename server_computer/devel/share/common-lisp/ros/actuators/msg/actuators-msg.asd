
(cl:in-package :asdf)

(defsystem "actuators-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Vector2" :depends-on ("_package_Vector2"))
    (:file "_package_Vector2" :depends-on ("_package"))
    (:file "Vector3" :depends-on ("_package_Vector3"))
    (:file "_package_Vector3" :depends-on ("_package"))
    (:file "Vector4" :depends-on ("_package_Vector4"))
    (:file "_package_Vector4" :depends-on ("_package"))
    (:file "motor_driver_param" :depends-on ("_package_motor_driver_param"))
    (:file "_package_motor_driver_param" :depends-on ("_package"))
  ))