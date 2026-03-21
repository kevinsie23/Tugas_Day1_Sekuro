# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_antar_menu_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED antar_menu_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(antar_menu_FOUND FALSE)
  elseif(NOT antar_menu_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(antar_menu_FOUND FALSE)
  endif()
  return()
endif()
set(_antar_menu_CONFIG_INCLUDED TRUE)

# output package information
if(NOT antar_menu_FIND_QUIETLY)
  message(STATUS "Found antar_menu: 0.0.0 (${antar_menu_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'antar_menu' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${antar_menu_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(antar_menu_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${antar_menu_DIR}/${_extra}")
endforeach()
