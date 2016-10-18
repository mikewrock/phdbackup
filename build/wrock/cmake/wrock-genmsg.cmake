# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "wrock: 6 messages, 2 services")

set(MSG_I_FLAGS "-Iwrock:/home/mike/catkin_ws/src/wrock/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/hydro/share/actionlib_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/hydro/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(wrock_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)
_generate_msg_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/arm_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)
_generate_msg_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/joint_kin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)
_generate_msg_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/joint_pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)
_generate_msg_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_kin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)
_generate_msg_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)

### Generating Services
_generate_srv_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/srv/inverse_d.srv"
  "${MSG_I_FLAGS}"
  "/home/mike/catkin_ws/src/wrock/msg/cube_pose.msg;/home/mike/catkin_ws/src/wrock/msg/joint_pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)
_generate_srv_cpp(wrock
  "/home/mike/catkin_ws/src/wrock/srv/laser_scan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
)

### Generating Module File
_generate_module_cpp(wrock
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(wrock_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(wrock_generate_messages wrock_generate_messages_cpp)

# target for backward compatibility
add_custom_target(wrock_gencpp)
add_dependencies(wrock_gencpp wrock_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wrock_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)
_generate_msg_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/arm_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)
_generate_msg_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/joint_kin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)
_generate_msg_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/joint_pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)
_generate_msg_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_kin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)
_generate_msg_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)

### Generating Services
_generate_srv_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/srv/inverse_d.srv"
  "${MSG_I_FLAGS}"
  "/home/mike/catkin_ws/src/wrock/msg/cube_pose.msg;/home/mike/catkin_ws/src/wrock/msg/joint_pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)
_generate_srv_lisp(wrock
  "/home/mike/catkin_ws/src/wrock/srv/laser_scan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
)

### Generating Module File
_generate_module_lisp(wrock
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(wrock_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(wrock_generate_messages wrock_generate_messages_lisp)

# target for backward compatibility
add_custom_target(wrock_genlisp)
add_dependencies(wrock_genlisp wrock_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wrock_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)
_generate_msg_py(wrock
  "/home/mike/catkin_ws/src/wrock/msg/arm_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)
_generate_msg_py(wrock
  "/home/mike/catkin_ws/src/wrock/msg/joint_kin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)
_generate_msg_py(wrock
  "/home/mike/catkin_ws/src/wrock/msg/joint_pose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)
_generate_msg_py(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_kin.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)
_generate_msg_py(wrock
  "/home/mike/catkin_ws/src/wrock/msg/cube_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)

### Generating Services
_generate_srv_py(wrock
  "/home/mike/catkin_ws/src/wrock/srv/inverse_d.srv"
  "${MSG_I_FLAGS}"
  "/home/mike/catkin_ws/src/wrock/msg/cube_pose.msg;/home/mike/catkin_ws/src/wrock/msg/joint_pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)
_generate_srv_py(wrock
  "/home/mike/catkin_ws/src/wrock/srv/laser_scan.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
)

### Generating Module File
_generate_module_py(wrock
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(wrock_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(wrock_generate_messages wrock_generate_messages_py)

# target for backward compatibility
add_custom_target(wrock_genpy)
add_dependencies(wrock_genpy wrock_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS wrock_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/wrock
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(wrock_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(wrock_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
add_dependencies(wrock_generate_messages_cpp sensor_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/wrock
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(wrock_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(wrock_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
add_dependencies(wrock_generate_messages_lisp sensor_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/wrock
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(wrock_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(wrock_generate_messages_py actionlib_msgs_generate_messages_py)
add_dependencies(wrock_generate_messages_py sensor_msgs_generate_messages_py)
