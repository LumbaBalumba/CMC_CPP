<<<<<<< HEAD
CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
project(contest2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O2 -m64 -fsanitize=leak -fsanitize=address -fsanitize=undefined -Wall -Werror")
=======
project(contest2)
CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O2 -Wall -Werror -fsanitize=leak -fsanitize=undefined -fsanitize=address")
>>>>>>> de5813b5430d839c9fecbda881a4b0690ee23980

add_executable(1-1 1/1.cpp)
add_executable(1-2 1/2.cpp)
add_executable(1-3 1/3.cpp)
add_executable(1-4 1/4.cpp)
add_executable(1-5 1/5.cpp)
add_executable(1-6 1/6.cpp)