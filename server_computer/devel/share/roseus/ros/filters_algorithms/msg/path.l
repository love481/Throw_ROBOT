;; Auto-generated. Do not edit!


(when (boundp 'filters_algorithms::path)
  (if (not (find-package "FILTERS_ALGORITHMS"))
    (make-package "FILTERS_ALGORITHMS"))
  (shadow 'path (find-package "FILTERS_ALGORITHMS")))
(unless (find-package "FILTERS_ALGORITHMS::PATH")
  (make-package "FILTERS_ALGORITHMS::PATH"))

(in-package "ROS")
;;//! \htmlinclude path.msg.html


(defclass filters_algorithms::path
  :super ros::object
  :slots ())

(defmethod filters_algorithms::path
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(setf (get filters_algorithms::path :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get filters_algorithms::path :datatype-) "filters_algorithms/path")
(setf (get filters_algorithms::path :definition-)
      "
")



(provide :filters_algorithms/path "d41d8cd98f00b204e9800998ecf8427e")


