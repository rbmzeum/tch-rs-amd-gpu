cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(tch)

find_package(Torch REQUIRED)

# Добавляем определение для предотвращения дублирования символов
add_definitions(-DTCH_EXTERN_SYMBOLS)

# Основная сборка библиотеки tch
add_library(tch STATIC torch_api.cpp torch_api_generated.cpp)
target_link_libraries(tch "${TORCH_LIBRARIES}")
set_property(TARGET tch PROPERTY CXX_STANDARD 14)
set_property(TARGET tch PROPERTY POSITION_INDEPENDENT_CODE ON)

# Добавляем флаги компиляции для избежания конфликтов символов
target_compile_options(tch PRIVATE 
    -fvisibility=hidden
    -fvisibility-inlines-hidden
)

install(TARGETS tch DESTINATION .)

# Опциональная сборка примера, если указана цель example
option(BUILD_EXAMPLE "Build the example application" OFF)

if(BUILD_EXAMPLE)
    cmake_minimum_required(VERSION 3.14)
    find_package(glog REQUIRED)

    # Добавляем исполняемый файл
    add_executable(example_app example.cpp)
    add_executable(example_app2 example2.cpp)

    # Подключаем библиотеки
    target_link_libraries(example_app ${TORCH_LIBRARIES} glog::glog)
    target_link_libraries(example_app2 tch glog::glog)

    # Устанавливаем стандарт C++
    set_property(TARGET example_app PROPERTY CXX_STANDARD 14)
    set_property(TARGET example_app2 PROPERTY CXX_STANDARD 14)
endif()
