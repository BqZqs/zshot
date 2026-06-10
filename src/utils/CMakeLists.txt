# Utils module sources
set(UTILS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/abstractlogger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/abstractlogger.h
    ${CMAKE_CURRENT_SOURCE_DIR}/colorutils.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/colorutils.h
    ${CMAKE_CURRENT_SOURCE_DIR}/confighandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/confighandler.h
    ${CMAKE_CURRENT_SOURCE_DIR}/desktopinfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/desktopinfo.h
    ${CMAKE_CURRENT_SOURCE_DIR}/filenamehandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/filenamehandler.h
    ${CMAKE_CURRENT_SOURCE_DIR}/globalvalues.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/globalvalues.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pathinfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pathinfo.h
    ${CMAKE_CURRENT_SOURCE_DIR}/screengrabber.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/screengrabber.h
    ${CMAKE_CURRENT_SOURCE_DIR}/screenshotsaver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/screenshotsaver.h
    ${CMAKE_CURRENT_SOURCE_DIR}/systemnotification.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/systemnotification.h
    ${CMAKE_CURRENT_SOURCE_DIR}/valuehandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/valuehandler.h
)
set(UTILS_SOURCES ${UTILS_SOURCES} PARENT_SCOPE)
