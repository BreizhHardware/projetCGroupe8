cmake_minimum_required(VERSION 3.7)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled Filmotheque.c main.c Movie.c NodeTrie.c List.c)
