; Auto-generated. Do not edit!


(cl:in-package wrock-srv)


;//! \htmlinclude inverse_d-request.msg.html

(cl:defclass <inverse_d-request> (roslisp-msg-protocol:ros-message)
  ((pose
    :reader pose
    :initarg :pose
    :type wrock-msg:cube_pose
    :initform (cl:make-instance 'wrock-msg:cube_pose)))
)

(cl:defclass inverse_d-request (<inverse_d-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <inverse_d-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'inverse_d-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name wrock-srv:<inverse_d-request> is deprecated: use wrock-srv:inverse_d-request instead.")))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <inverse_d-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wrock-srv:pose-val is deprecated.  Use wrock-srv:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <inverse_d-request>) ostream)
  "Serializes a message object of type '<inverse_d-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <inverse_d-request>) istream)
  "Deserializes a message object of type '<inverse_d-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<inverse_d-request>)))
  "Returns string type for a service object of type '<inverse_d-request>"
  "wrock/inverse_dRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'inverse_d-request)))
  "Returns string type for a service object of type 'inverse_d-request"
  "wrock/inverse_dRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<inverse_d-request>)))
  "Returns md5sum for a message object of type '<inverse_d-request>"
  "6873795dc2f218e6b937d13b0214e87f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'inverse_d-request)))
  "Returns md5sum for a message object of type 'inverse_d-request"
  "6873795dc2f218e6b937d13b0214e87f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<inverse_d-request>)))
  "Returns full string definition for message of type '<inverse_d-request>"
  (cl:format cl:nil "wrock/cube_pose pose~%~%================================================================================~%MSG: wrock/cube_pose~%float32 x~%float32 y~%float32 z~%float32 pitch~%float32 yaw~%float32 xrot~%float32 yrot~%float32 zrot~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'inverse_d-request)))
  "Returns full string definition for message of type 'inverse_d-request"
  (cl:format cl:nil "wrock/cube_pose pose~%~%================================================================================~%MSG: wrock/cube_pose~%float32 x~%float32 y~%float32 z~%float32 pitch~%float32 yaw~%float32 xrot~%float32 yrot~%float32 zrot~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <inverse_d-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <inverse_d-request>))
  "Converts a ROS message object to a list"
  (cl:list 'inverse_d-request
    (cl:cons ':pose (pose msg))
))
;//! \htmlinclude inverse_d-response.msg.html

(cl:defclass <inverse_d-response> (roslisp-msg-protocol:ros-message)
  ((joints
    :reader joints
    :initarg :joints
    :type wrock-msg:joint_pose
    :initform (cl:make-instance 'wrock-msg:joint_pose)))
)

(cl:defclass inverse_d-response (<inverse_d-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <inverse_d-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'inverse_d-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name wrock-srv:<inverse_d-response> is deprecated: use wrock-srv:inverse_d-response instead.")))

(cl:ensure-generic-function 'joints-val :lambda-list '(m))
(cl:defmethod joints-val ((m <inverse_d-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wrock-srv:joints-val is deprecated.  Use wrock-srv:joints instead.")
  (joints m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <inverse_d-response>) ostream)
  "Serializes a message object of type '<inverse_d-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'joints) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <inverse_d-response>) istream)
  "Deserializes a message object of type '<inverse_d-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'joints) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<inverse_d-response>)))
  "Returns string type for a service object of type '<inverse_d-response>"
  "wrock/inverse_dResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'inverse_d-response)))
  "Returns string type for a service object of type 'inverse_d-response"
  "wrock/inverse_dResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<inverse_d-response>)))
  "Returns md5sum for a message object of type '<inverse_d-response>"
  "6873795dc2f218e6b937d13b0214e87f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'inverse_d-response)))
  "Returns md5sum for a message object of type 'inverse_d-response"
  "6873795dc2f218e6b937d13b0214e87f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<inverse_d-response>)))
  "Returns full string definition for message of type '<inverse_d-response>"
  (cl:format cl:nil "wrock/joint_pose joints~%~%~%================================================================================~%MSG: wrock/joint_pose~%float32 j1~%float32 j2~%float32 j3~%float32 j4~%float32 j5~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'inverse_d-response)))
  "Returns full string definition for message of type 'inverse_d-response"
  (cl:format cl:nil "wrock/joint_pose joints~%~%~%================================================================================~%MSG: wrock/joint_pose~%float32 j1~%float32 j2~%float32 j3~%float32 j4~%float32 j5~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <inverse_d-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'joints))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <inverse_d-response>))
  "Converts a ROS message object to a list"
  (cl:list 'inverse_d-response
    (cl:cons ':joints (joints msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'inverse_d)))
  'inverse_d-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'inverse_d)))
  'inverse_d-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'inverse_d)))
  "Returns string type for a service object of type '<inverse_d>"
  "wrock/inverse_d")