# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CBitmap_autogen"
  "CMakeFiles/CBitmap_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CBitmap_autogen.dir/ParseCache.txt"
  )
endif()
