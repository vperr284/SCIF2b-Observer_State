cmake_minimum_required(VERSION 3.19)
project(TP_State)

set(CMAKE_CXX_STANDARD 14)

add_executable(TP_State main.cpp Capteur.cpp Capteur.h CapteurImpl.cpp CapteurImpl.h Moniteur.cpp Moniteur.h State.cpp State.h StateAnomalie.cpp StateAnomalie.h StateNormal.cpp StateNormal.h StatePanne.cpp StatePanne.h)