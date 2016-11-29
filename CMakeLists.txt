################################################################################
##                                                                            ##
##              Copyright(C) C3P-GROUP International 2007 - 2015              ##
##                            All Rights Reserved                             ##
##                       Proprietary and Trade Secret                         ##
##                                                                            ##
################################################################################

cmake_minimum_required (VERSION 2.6)

project (Fill)

add_executable (Fill main.c)
target_compile_options (Fill PRIVATE "/MT$<$<CONFIG:Debug>:d>")
