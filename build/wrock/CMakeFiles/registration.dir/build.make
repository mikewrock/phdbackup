# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mike/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mike/catkin_ws/build

# Include any dependencies generated for this target.
include wrock/CMakeFiles/registration.dir/depend.make

# Include the progress variables for this target.
include wrock/CMakeFiles/registration.dir/progress.make

# Include the compile flags for this target's objects.
include wrock/CMakeFiles/registration.dir/flags.make

wrock/CMakeFiles/registration.dir/src/registration.cpp.o: wrock/CMakeFiles/registration.dir/flags.make
wrock/CMakeFiles/registration.dir/src/registration.cpp.o: /home/mike/catkin_ws/src/wrock/src/registration.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mike/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object wrock/CMakeFiles/registration.dir/src/registration.cpp.o"
	cd /home/mike/catkin_ws/build/wrock && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -Wno-deprecated -o CMakeFiles/registration.dir/src/registration.cpp.o -c /home/mike/catkin_ws/src/wrock/src/registration.cpp

wrock/CMakeFiles/registration.dir/src/registration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/registration.dir/src/registration.cpp.i"
	cd /home/mike/catkin_ws/build/wrock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -Wno-deprecated -E /home/mike/catkin_ws/src/wrock/src/registration.cpp > CMakeFiles/registration.dir/src/registration.cpp.i

wrock/CMakeFiles/registration.dir/src/registration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/registration.dir/src/registration.cpp.s"
	cd /home/mike/catkin_ws/build/wrock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -Wno-deprecated -S /home/mike/catkin_ws/src/wrock/src/registration.cpp -o CMakeFiles/registration.dir/src/registration.cpp.s

wrock/CMakeFiles/registration.dir/src/registration.cpp.o.requires:
.PHONY : wrock/CMakeFiles/registration.dir/src/registration.cpp.o.requires

wrock/CMakeFiles/registration.dir/src/registration.cpp.o.provides: wrock/CMakeFiles/registration.dir/src/registration.cpp.o.requires
	$(MAKE) -f wrock/CMakeFiles/registration.dir/build.make wrock/CMakeFiles/registration.dir/src/registration.cpp.o.provides.build
.PHONY : wrock/CMakeFiles/registration.dir/src/registration.cpp.o.provides

wrock/CMakeFiles/registration.dir/src/registration.cpp.o.provides.build: wrock/CMakeFiles/registration.dir/src/registration.cpp.o

# Object files for target registration
registration_OBJECTS = \
"CMakeFiles/registration.dir/src/registration.cpp.o"

# External object files for target registration
registration_EXTERNAL_OBJECTS =

/home/mike/catkin_ws/devel/lib/wrock/registration: wrock/CMakeFiles/registration.dir/src/registration.cpp.o
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/liburdf.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/liburdfdom_sensor.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/liburdfdom_model_state.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/liburdfdom_model.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/liburdfdom_world.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/librosconsole_bridge.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /home/mike/catkin_ws/devel/lib/libm5api.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libntcan.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libpcan.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/liblaser_geometry.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libmean.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libparams.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libincrement.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libmedian.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libtransfer_function.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libpcl_ros_filters.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libpcl_ros_io.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libpcl_ros_tf.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_common.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_kdtree.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_octree.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_search.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_io.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_sample_consensus.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_filters.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_visualization.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_outofcore.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_features.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_segmentation.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_people.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_registration.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_recognition.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_keypoints.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_surface.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_tracking.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libpcl_apps.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_iostreams-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_serialization-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libqhull.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libOpenNI.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libflann_cpp_s.a
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libvtkCommon.so.5.8.0
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libvtkRendering.so.5.8.0
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libvtkHybrid.so.5.8.0
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libvtkCharts.so.5.8.0
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libdynamic_reconfigure_config_init_mutex.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libnodeletlib.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libbondcpp.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/x86_64-linux-gnu/libuuid.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libtinyxml.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libclass_loader.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libPocoFoundation.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/x86_64-linux-gnu/libdl.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libroslib.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/librosbag.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/librosbag_storage.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_program_options-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libtopic_tools.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libtf.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libtf2_ros.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libactionlib.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libmessage_filters.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libroscpp.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_signals-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_filesystem-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libxmlrpcpp.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libtf2.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libroscpp_serialization.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/librosconsole.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/librosconsole_log4cxx.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/librosconsole_backend_interface.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/liblog4cxx.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_regex-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/librostime.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_date_time-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_system-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/libboost_thread-mt.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libcpp_common.so
/home/mike/catkin_ws/devel/lib/wrock/registration: /opt/ros/hydro/lib/libconsole_bridge.so
/home/mike/catkin_ws/devel/lib/wrock/registration: wrock/CMakeFiles/registration.dir/build.make
/home/mike/catkin_ws/devel/lib/wrock/registration: wrock/CMakeFiles/registration.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/mike/catkin_ws/devel/lib/wrock/registration"
	cd /home/mike/catkin_ws/build/wrock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/registration.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wrock/CMakeFiles/registration.dir/build: /home/mike/catkin_ws/devel/lib/wrock/registration
.PHONY : wrock/CMakeFiles/registration.dir/build

wrock/CMakeFiles/registration.dir/requires: wrock/CMakeFiles/registration.dir/src/registration.cpp.o.requires
.PHONY : wrock/CMakeFiles/registration.dir/requires

wrock/CMakeFiles/registration.dir/clean:
	cd /home/mike/catkin_ws/build/wrock && $(CMAKE_COMMAND) -P CMakeFiles/registration.dir/cmake_clean.cmake
.PHONY : wrock/CMakeFiles/registration.dir/clean

wrock/CMakeFiles/registration.dir/depend:
	cd /home/mike/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mike/catkin_ws/src /home/mike/catkin_ws/src/wrock /home/mike/catkin_ws/build /home/mike/catkin_ws/build/wrock /home/mike/catkin_ws/build/wrock/CMakeFiles/registration.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wrock/CMakeFiles/registration.dir/depend
