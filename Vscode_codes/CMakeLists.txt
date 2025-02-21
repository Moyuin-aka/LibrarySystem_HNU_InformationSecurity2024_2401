cmake_minimum_required(VERSION 3.30)
project(codes)

set(CMAKE_CXX_STANDARD 14)

include_directories(account)
include_directories(book)
include_directories(charts)
include_directories(menu)
include_directories(user)

add_executable(codes
    account/AccountManager.cpp
    account/AccountManager.h
    book/Book.cpp
    book/Book.h
    book/BookManager.cpp
    book/BookManager.h
    charts/charts.cpp
    charts/charts.h
    menu/AdminMenu.cpp
    menu/AdminMenu.h
    menu/MenuManager.cpp
    menu/MenuManager.h
    menu/ReaderMenu.cpp
    menu/ReaderMenu.h
    user/User.cpp
    user/User.h
    user/UserManager.cpp
    user/UserManager.h
    main.cpp)

file(COPY ${CMAKE_SOURCE_DIR}/admin_password.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/users.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/books.txt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/return_history.txt DESTINATION ${CMAKE_BINARY_DIR})
