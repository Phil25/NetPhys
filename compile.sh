#!/bin/bash

g++ src/body.cpp src/phys.cpp src/renderer.cpp src/main.cpp -o netphys `pkg-config --static --libs glfw3` `pkg-config --static --libs gl` `pkg-config --static --libs glew`
