#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
#

# CMakeLists.txt - SUPL Client Library for Zephyr

if(CONFIG_FPU)
  if(CONFIG_FP_HARDABI)
    set(float_dir hard-float)
  else()
    assert(0 "Unreachable code")
  endif()
else()
  set(float_dir soft-float)
endif()

assert(GCC_M_CPU "GCC_M_CPU must be set to find correct lib")

set(lib_path lib/${GCC_M_CPU}/${float_dir})
set(SUPL_CLIENT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${lib_path})

set(SUPL_CLIENT_TARGET supl_client)

zephyr_include_directories(include)
zephyr_library_import(${SUPL_CLIENT_TARGET} ${SUPL_CLIENT_LIB_PATH}/libsupl.a)
