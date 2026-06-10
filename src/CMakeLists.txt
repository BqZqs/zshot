cmake_minimum_required(VERSION 3.22)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

add_subdirectory(core)
add_subdirectory(tools)
add_subdirectory(widgets)
add_subdirectory(utils)
add_subdirectory(config)

set(ZSHOT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CORE_SOURCES}
    ${TOOLS_SOURCES}
    ${WIDGET_SOURCES}
    ${UTILS_SOURCES}
    ${CONFIG_SOURCES}
)

add_executable(zshot
    ${ZSHOT_SOURCES}
    ${CMAKE_SOURCE_DIR}/data/graphics.qrc
    ${CMAKE_SOURCE_DIR}/data/zshot.rc
)

set_target_properties(zshot PROPERTIES
    WIN32_EXECUTABLE TRUE
)

# Suppress warnings from generated moc/ui files
target_include_directories(zshot PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_definitions(zshot PRIVATE
    APP_VERSION="${PROJECT_VERSION}"
    ZSHOT_GIT_HASH="unknown"
    ZSHOT_APP_VERSION_URL="none"
    USE_PORTABLE_CONFIG
    DISABLE_UPDATE_CHECKER
    PREDEFINED_COLOR_PALETTE_LARGE=false
)

target_compile_features(zshot PRIVATE cxx_std_20)

target_link_libraries(zshot PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
    Qt6::Network
)

# Install executable to root of package
install(TARGETS zshot
    RUNTIME DESTINATION .
    BUNDLE DESTINATION .
)
