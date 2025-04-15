# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TressetteGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TressetteGame_autogen.dir\\ParseCache.txt"
  "TressetteGame_autogen"
  )
endif()
