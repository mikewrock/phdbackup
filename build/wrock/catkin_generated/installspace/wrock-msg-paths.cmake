# generated from genmsg/cmake/pkg-msg-paths.cmake.em

# message include dirs in installspace
_prepend_path("${wrock_DIR}/.." "msg" wrock_MSG_INCLUDE_DIRS UNIQUE)
set(wrock_MSG_DEPENDENCIES std_msgs;actionlib_msgs;sensor_msgs)
