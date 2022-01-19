;; Auto-generated. Do not edit!


(when (boundp 'actuators::motor_driver_param)
  (if (not (find-package "ACTUATORS"))
    (make-package "ACTUATORS"))
  (shadow 'motor_driver_param (find-package "ACTUATORS")))
(unless (find-package "ACTUATORS::MOTOR_DRIVER_PARAM")
  (make-package "ACTUATORS::MOTOR_DRIVER_PARAM"))

(in-package "ROS")
;;//! \htmlinclude motor_driver_param.msg.html


(defclass actuators::motor_driver_param
  :super ros::object
  :slots (_id _dir1 _dir2 _pwm ))

(defmethod actuators::motor_driver_param
  (:init
   (&key
    ((:id __id) 0)
    ((:dir1 __dir1) 0)
    ((:dir2 __dir2) 0)
    ((:pwm __pwm) 0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _dir1 (round __dir1))
   (setq _dir2 (round __dir2))
   (setq _pwm (round __pwm))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:dir1
   (&optional __dir1)
   (if __dir1 (setq _dir1 __dir1)) _dir1)
  (:dir2
   (&optional __dir2)
   (if __dir2 (setq _dir2 __dir2)) _dir2)
  (:pwm
   (&optional __pwm)
   (if __pwm (setq _pwm __pwm)) _pwm)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ;; uint8 _dir1
    1
    ;; uint8 _dir2
    1
    ;; uint16 _pwm
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;; uint8 _dir1
       (write-byte _dir1 s)
     ;; uint8 _dir2
       (write-byte _dir2 s)
     ;; uint16 _pwm
       (write-word _pwm s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _dir1
     (setq _dir1 (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _dir2
     (setq _dir2 (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _pwm
     (setq _pwm (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get actuators::motor_driver_param :md5sum-) "4dd7daa3fbb798d83aefe25263d7d1e1")
(setf (get actuators::motor_driver_param :datatype-) "actuators/motor_driver_param")
(setf (get actuators::motor_driver_param :definition-)
      "#motor driving param
uint8 id
uint8 dir1
uint8 dir2
uint16 pwm
")



(provide :actuators/motor_driver_param "4dd7daa3fbb798d83aefe25263d7d1e1")


