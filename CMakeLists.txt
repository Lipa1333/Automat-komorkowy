cmake_minimum_required(VERSION 2.8.11)

project(Automat-komorkowy)
set (CMAKE_PREFIX_PATH "C:\\Qt\\5.3\\msvc2013_64\\")
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

# Tworzenie .exe
add_executable(Automat-komorkowy main.cpp)
target_sources(Automat-komorkowy PUBLIC GUI.cpp GUI.h GUI.qrc GUI.ui ui_GUI.h qrc_GUI Komorka.cpp Komorka.h Pole.cpp Pole.h Worker.cpp Worker.h )

# Use the Widgets module from Qt 5.
target_link_libraries(Automat-komorkowy Qt5::Widgets)

add_custom_command(TARGET Automat-komorkowy POST_BUILD 
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${PROJECT_SOURCE_DIR}/libs"
    $<TARGET_FILE_DIR:Automat-komorkowy>)