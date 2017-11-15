cmake_minimum_required(VERSION 2.8.11)

project(Automat-komorkowy)
set (CMAKE_PREFIX_PATH "C:\\Qt\\5.3\\msvc2013_64")
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Script)


qt5_wrap_ui(uiheaders Editor.ui Generate.ui GUI.ui FileSelect.ui) 

# Tworzenie .exe
add_executable(Automat-komorkowy WIN32 main.cpp ${uiheaders})
target_sources(Automat-komorkowy PUBLIC Editor.cpp Editor.h Generate.cpp Generate.h GUI.cpp GUI.h    Komorka.cpp Komorka.h Pole.cpp Pole.h Worker.cpp Worker.h qrc_GUI.cpp GUI.qrc)
#ui_Editor.h ui_Generate.h ui_GUI.h
# Use the Widgets module from Qt 5.
target_link_libraries(Automat-komorkowy Qt5::Widgets)
target_link_libraries(Automat-komorkowy Qt5::Script)

add_custom_command(TARGET Automat-komorkowy POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${PROJECT_SOURCE_DIR}/libraries"
    $<TARGET_FILE_DIR:Automat-komorkowy>)

#ustawienie projektu startowego	
set_property (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Automat-komorkowy) 