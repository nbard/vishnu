#
# Try to find the LOADLEVELER installation
#

find_path(LOADLEVELER_INCLUDE_DIR
 llapi.h
  paths
	${LOADLEVELER_DIR}/include
	$ENV{LOADLEVELER_DIR}/include
	/usr/include
	/usr/local/include
	/opt/local/include
)

find_library(LOADLEVELER_LIB
  llapi 
  paths
	${LOADLEVELER_DIR}/lib
  $ENV{LOADLEVELER_DIR}/lib
	/usr/lib
	/usr/local/lib
  /opt/local/lib
)


if (LOADLEVELER_INCLUDE_DIR AND  LOADLEVELER_LIB)
  set(LOADLEVELER_FOUND "Yes")
  mark_as_advanced(LOADLEVELER_INCLUDE_DIR)
  mark_as_advanced(LOADLEVELER_LIB)
endif(LOADLEVELER_INCLUDE_DIR AND LOADLEVELER_LIB)


