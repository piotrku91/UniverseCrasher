
sudo dnf install SDL2 SDL2-devel SDL2_image SDL2_image-devel SDL2_ttf SDL2_ttf-devel
mkdir build
cd build
cmake ..
make -j4 && ./UniverseCrasher