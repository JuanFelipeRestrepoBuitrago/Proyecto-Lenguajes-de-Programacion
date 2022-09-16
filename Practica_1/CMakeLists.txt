cmake_minimum_required(VERSION 3.23)
project(ProyectoLenguajesProgramacion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Practica_1 main.cpp LinkedList/Node.cpp LinkedList/Node.h LinkedList/LinkedList.cpp LinkedList/LinkedList.h FileHandling/Storage.cpp FileHandling/Storage.h Outputs/Output.cpp Outputs/Output.h Inputs/Input.cpp Inputs/Input.h Exceptions/Exceptions.cpp Exceptions/Exceptions.h InternalProcessing/Processing.cpp InternalProcessing/Processing.h)
