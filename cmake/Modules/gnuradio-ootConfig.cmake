find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_OOT gnuradio-oot)

FIND_PATH(
    GR_OOT_INCLUDE_DIRS
    NAMES gnuradio/oot/api.h
    HINTS $ENV{OOT_DIR}/include
        ${PC_OOT_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_OOT_LIBRARIES
    NAMES gnuradio-oot
    HINTS $ENV{OOT_DIR}/lib
        ${PC_OOT_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-ootTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_OOT DEFAULT_MSG GR_OOT_LIBRARIES GR_OOT_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_OOT_LIBRARIES GR_OOT_INCLUDE_DIRS)
