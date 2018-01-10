cmake_minimum_required(VERSION 3.1)

project(Automat-komorkowy)
#Ustawienie zmiennej środowiskowej wskazującej na folder instalacji Qt
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.9.2\\msvc2017_64")
# Szukanie plików źródłowych w tym samym folderu
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Kazanie Cmakeowi automatycznie zrobić pliki Moc
set(CMAKE_AUTOMOC ON)

# Wyszukanie bibliotek na podstaiwe zmiennej środowiskowej
find_package(Qt5Widgets)
find_package(Qt5Script)

#OBsługa plików ui i generowanie nadłowków do nich
qt5_wrap_ui(uiheaders Scope.ui Generate.ui GUI.ui FileSelect.ui) 
#obsluga rescources i generowanie .cpp dla nich
qt5_add_resources(rescources GUI.qrc)
#dodanie plików źródłowych do projektu
set(cppsources Generate.cpp GUI.cpp Komorka.cpp Pole.cpp Scope.cpp Worker.cpp Baza.cpp)
#nagłowki
set(hheaders Generate.h GUI.h Komorka.h Pole.h Scope.h Worker.h Baza.h)

# Tworzenie .exe
add_executable(Automat-komorkowy WIN32 main.cpp ${uiheaders} ${rescources} ${hheaders} ${cppsources})

# Kazanie Cmakeowi uzyć bibliotek przy kompilacji
target_link_libraries(Automat-komorkowy Qt5::Widgets)
target_link_libraries(Automat-komorkowy Qt5::Script)

# Uruchomianie windeployqt jesli znajdzie go, program szuka biblioteki runtime i kopiuje je do folderu z plikiem .exe
if(WIN32) 
find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${QTDIR} ENV QTDIR PATH_SUFFIXES bin) 
add_custom_command(TARGET Automat-komorkowy POST_BUILD 
	COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:Automat-komorkowy>) 
	endif()
