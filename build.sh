#!/bin/sh

g++ -Wall -Wextra -std=c++20 -ggdb -o main main.cpp $(pkg-config --libs "raylib")

