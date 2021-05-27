cmake_minimum_required(VERSION 3.19)
project(num_an_lab_04)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

add_executable(${PROJECT_NAME} mainwindow.h mainwindow.cpp main.cpp dirichlet_problem_solver.cpp dirichlet_problem_solver.h)

list(APPEND CMAKE_PREFIX_PATH "/opt/Qt/5.15.2/gcc_64")
list(APPEND CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\msvc2019_64")
list(APPEND CMAKE_PREFIX_PATH "D:\\sdks\\Qt\\5.15.2\\msvc2019_64")

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
