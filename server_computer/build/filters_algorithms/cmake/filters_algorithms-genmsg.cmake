# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "filters_algorithms: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ifilters_algorithms:/home/love/Documents/server_computer/src/filters_algorithms/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(filters_algorithms_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg" NAME_WE)
add_custom_target(_filters_algorithms_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "filters_algorithms" "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(filters_algorithms
  "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/filters_algorithms
)

### Generating Services

### Generating Module File
_generate_module_cpp(filters_algorithms
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/filters_algorithms
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(filters_algorithms_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(filters_algorithms_generate_messages filters_algorithms_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg" NAME_WE)
add_dependencies(filters_algorithms_generate_messages_cpp _filters_algorithms_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(filters_algorithms_gencpp)
add_dependencies(filters_algorithms_gencpp filters_algorithms_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS filters_algorithms_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(filters_algorithms
  "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/filters_algorithms
)

### Generating Services

### Generating Module File
_generate_module_eus(filters_algorithms
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/filters_algorithms
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(filters_algorithms_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(filters_algorithms_generate_messages filters_algorithms_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg" NAME_WE)
add_dependencies(filters_algorithms_generate_messages_eus _filters_algorithms_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(filters_algorithms_geneus)
add_dependencies(filters_algorithms_geneus filters_algorithms_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS filters_algorithms_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(filters_algorithms
  "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/filters_algorithms
)

### Generating Services

### Generating Module File
_generate_module_lisp(filters_algorithms
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/filters_algorithms
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(filters_algorithms_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(filters_algorithms_generate_messages filters_algorithms_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg" NAME_WE)
add_dependencies(filters_algorithms_generate_messages_lisp _filters_algorithms_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(filters_algorithms_genlisp)
add_dependencies(filters_algorithms_genlisp filters_algorithms_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS filters_algorithms_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(filters_algorithms
  "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/filters_algorithms
)

### Generating Services

### Generating Module File
_generate_module_nodejs(filters_algorithms
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/filters_algorithms
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(filters_algorithms_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(filters_algorithms_generate_messages filters_algorithms_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg" NAME_WE)
add_dependencies(filters_algorithms_generate_messages_nodejs _filters_algorithms_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(filters_algorithms_gennodejs)
add_dependencies(filters_algorithms_gennodejs filters_algorithms_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS filters_algorithms_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(filters_algorithms
  "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/filters_algorithms
)

### Generating Services

### Generating Module File
_generate_module_py(filters_algorithms
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/filters_algorithms
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(filters_algorithms_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(filters_algorithms_generate_messages filters_algorithms_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/love/Documents/server_computer/src/filters_algorithms/msg/path.msg" NAME_WE)
add_dependencies(filters_algorithms_generate_messages_py _filters_algorithms_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(filters_algorithms_genpy)
add_dependencies(filters_algorithms_genpy filters_algorithms_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS filters_algorithms_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/filters_algorithms)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/filters_algorithms
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(filters_algorithms_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(filters_algorithms_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/filters_algorithms)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/filters_algorithms
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(filters_algorithms_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(filters_algorithms_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/filters_algorithms)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/filters_algorithms
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(filters_algorithms_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(filters_algorithms_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/filters_algorithms)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/filters_algorithms
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(filters_algorithms_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(filters_algorithms_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/filters_algorithms)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/filters_algorithms\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/filters_algorithms
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(filters_algorithms_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(filters_algorithms_generate_messages_py geometry_msgs_generate_messages_py)
endif()
