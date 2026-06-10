# Core module sources
set(CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/capturerequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/capturerequest.h
    ${CMAKE_CURRENT_SOURCE_DIR}/qguiappcurrentscreen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/qguiappcurrentscreen.h
    ${CMAKE_CURRENT_SOURCE_DIR}/signaldaemon.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/signaldaemon.h
    ${CMAKE_CURRENT_SOURCE_DIR}/zshot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zshot.h
    ${CMAKE_CURRENT_SOURCE_DIR}/zshotdaemon.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zshotdaemon.h
)
# Propagate to parent scope
set(CORE_SOURCES ${CORE_SOURCES} PARENT_SCOPE)
