cmake_minimum_required(VERSION 3.19)
project(TP_Observer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TP_Observer
        main.cpp
        observer.cpp
        observer.h
        observerimpl.cpp
        observerimpl.h
        subject.cpp
        subject.h
        subjectimpl.cpp
        subjectimpl.h)
