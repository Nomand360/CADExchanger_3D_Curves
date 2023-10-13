cmake_minimum_required(VERSION 3.5)

project(3DGeometryCurves LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(3DGeometryCurves main.cpp
    Vec3.h
    Curves_3D.h
    Curves_3D.cpp)

install(TARGETS 3DGeometryCurves
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
