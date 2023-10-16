cmake_minimum_required(VERSION 3.10)

project(Atividade02)

# Encontre a biblioteca Google Test
find_package(GTest REQUIRED)

# Inclua o cabeçalho do Google Test
include_directories(${GTEST_INCLUDE_DIRS})

# Adicione seus arquivos de origem (código principal)
add_executable(Atividade02 main.cpp)

# Adicione a biblioteca Google Test e seus arquivos de teste
add_executable(AT2Test testes.cpp)

# Adicione a biblioteca Google Test ao seu alvo de teste
target_link_libraries(AT2Test GTest::GTest GTest::Main)

# Adicione seus arquivos de origem e inclua o diretório de código principal
target_sources(AT2Test PRIVATE main.cpp)

# Configuração para executar os testes usando ctest
enable_testing()
add_test(NAME AT2Test COMMAND AT2Test)
