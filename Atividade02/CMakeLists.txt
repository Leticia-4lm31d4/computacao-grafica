cmake_minimum_required(VERSION 3.10)
project(Atividade02)

find_package(GTest REQUIRED)

# Cabeçalho do Google Test
include_directories(${GTEST_INCLUDE_DIRS})

# Adicione seus arquivos de origem (código principal)
add_executable(t.out testes.cpp)

target_link_libraries(t.out ${GTEST_LIBRARIES})

enable_testing()
add_test(add t.out)
