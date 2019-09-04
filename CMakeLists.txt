cmake_minimum_required(VERSION 3.14)
project(poker-bot)

set(CMAKE_CXX_STANDARD 17)

include_directories(${includes/})


set(HEADERS_FILES includes/BaseClasses/BaseImage.hpp includes/ScreenShot.hpp includes/utils.hpp includes/TableItens/Card.hpp includes/TableItens/Player.hpp includes/Game.hpp includes/PlayerItens/PlayerStatus.hpp includes/PlayerItens/Dealer.hpp includes/PlayerItens/Stack.hpp includes/BaseClasses/BaseImageCompare.hpp includes/BaseClasses/BaseImageFindNumber.hpp includes/TableItens/Pot.hpp includes/BaseClasses/BaseMouse.hpp includes/AbstractClasses/AbstractVisitor.hpp includes/ImageVisitor.hpp includes/AbstractClasses/AbstractVisitable.hpp includes/TableItens/Table.hpp includes/Buttons/Fold.hpp includes/Buttons/Call.hpp includes/Buttons/Bet.hpp includes/Buttons/RaiseButton.hpp includes/Application.hpp includes/TableItens/CommunityCards.hpp)
#
set(SOURCES_FILES src/minecraft-2.3.cpp  src/utils.cpp src/BaseClasses/BaseImage.cpp src/TableItens/Card.cpp src/TableItens/Player.cpp src/Game.cpp src/PlayerItens/PlayerStatus.cpp src/PlayerItens/Dealer.cpp src/PlayerItens/Stack.cpp src/BaseClasses/BaseImageCompare.cpp src/BaseClasses/BaseImageFindNumber.cpp src/TableItens/Pot.cpp src/BaseClasses/BaseMouse.cpp src/ImageVisitor.cpp src/TableItens/Table.cpp src/ScreenShot.cpp src/Buttons/Fold.cpp src/Buttons/Call.cpp src/Buttons/Bet.cpp src/Buttons/RaiseButton.cpp src/Application.cpp src/TableItens/CommunityCards.cpp)

#file(GLOB HEADERS_FILES includes/*.hpp)
#file(GLOB SOURCES_FILES src/*.cpp)

#
add_executable(${PROJECT_NAME} ${SOURCES_FILES} ${HEADERS_FILES})

# Encontra X11 para o projeto
find_package(X11 REQUIRED)
include_directories(${X11_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})


# Encontra opencv
find_package( OpenCV REQUIRED core highgui imgproc)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

#Encontra thread
find_package( Threads )
target_link_libraries( ${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} )
