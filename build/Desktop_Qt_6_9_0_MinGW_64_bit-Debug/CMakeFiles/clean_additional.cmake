# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GraphVisualizer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GraphVisualizer_autogen.dir\\ParseCache.txt"
  "GraphVisualizer_autogen"
  )
endif()
