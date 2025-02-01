#!/bin/bash

# Создаем директорию для сборки
mkdir -p build
cd build

# Конфигурируем CMake
cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
    -DCMAKE_CXX_FLAGS="-fPIC -fvisibility=hidden -fvisibility-inlines-hidden" \
    -DTorch_DIR=/usr/lib/cmake/Torch

# Собираем
cmake --build . --config Release

# Копируем библиотеку в нужное место
cp libtch.a .. 