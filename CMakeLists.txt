cmake_minimum_required(VERSION 3.13)
project(CiEmulator C)

set(CMAKE_C_STANDARD 11)

add_executable(CiEmulator main.c src/Validators/validator.c src/Validators/validator.h)