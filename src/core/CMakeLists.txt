# Core module sources
set(CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/capturerequest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/capturerequest.h
    ${CMAKE_CURRENT_SOURCE_DIR}/globalshortcutfilter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/globalshortcutfilter.h
    ${CMAKE_CURRENT_SOURCE_DIR}/qguiappcurrentscreen.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/qguiappcurrentscreen.h
    ${CMAKE_CURRENT_SOURCE_DIR}/zshot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zshot.h
    ${CMAKE_CURRENT_SOURCE_DIR}/zshotdaemon.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/zshotdaemon.h
)
# signaldaemon is Unix-only (uses socketpair/syscalls)
if(NOT WIN32)
    list(APPEND CORE_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/signaldaemon.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/signaldaemon.h
    )
endif()
# Propagate to parent scope
set(CORE_SOURCES ${CORE_SOURCES} PARENT_SCOPE)
