mkdir -p build
cd build || exit

cmake ..
cmake --build . --parallel
