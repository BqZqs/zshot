# Widgets module — includes capture and panel subdirectories
add_subdirectory(capture)
add_subdirectory(panel)

set(WIDGET_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/colorpickerwidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/colorpickerwidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/draggablewidgetmaker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/draggablewidgetmaker.h
    ${CMAKE_CURRENT_SOURCE_DIR}/imagelabel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imagelabel.h
    ${CMAKE_CURRENT_SOURCE_DIR}/orientablepushbutton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/orientablepushbutton.h
    ${CMAKE_CURRENT_SOURCE_DIR}/trayicon.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/trayicon.h
    ${CAPTURE_SOURCES}
    ${PANEL_SOURCES}
)
set(WIDGET_SOURCES ${WIDGET_SOURCES} PARENT_SCOPE)
