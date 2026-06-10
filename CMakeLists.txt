cmake_minimum_required(VERSION 3.22)

set(ZSHOT_VERSION 0.1.0)

project(zshot
    VERSION ${ZSHOT_VERSION}
    LANGUAGES CXX
)

# Windows only
if(NOT WIN32)
    message(FATAL_ERROR "zshot supports Windows only at this time.")
endif()

add_definitions(-DZSHOT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
add_definitions(-DZSHOT_VERSION_MINOR=${PROJECT_VERSION_MINOR})
add_definitions(-DZSHOT_VERSION_BUGFIX=${PROJECT_VERSION_PATCH})
add_definitions(-DZSHOT_VERSION_BUILD=1)
add_definitions(-DZSHOT_VERSION_STRING="${PROJECT_VERSION}")

set(USE_PORTABLE_CONFIG ON CACHE BOOL "Store config in application folder")
add_compile_definitions(USE_PORTABLE_CONFIG)
add_compile_definitions(DISABLE_UPDATE_CHECKER)

add_subdirectory(src)

# CPack ZIP packaging
set(CPACK_PACKAGE_VENDOR "zshot-org")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Lightweight pixel-art screenshot tool for Windows.")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/BqZqs/zshot")
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_FILE_NAME "zshot-${PROJECT_VERSION}-win64")
set(CPACK_GENERATOR ZIP)
include(CPack)
