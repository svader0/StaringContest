![Staring Contest](res/logoWhite.png "Staring Contest")

Stare at yourself using the power of computer vision!
This project was created for the 2021 [GunnHacks](https://www.gunnhacks.com/)
hackathon.

## Screenshots
Note: Update this part with screenshots of final submission

## Build
#### Dependencies
This project requires that you install [OpenCV](https://opencv.org/) and [SFML](https://www.sfml-dev.org/).
Personally, I recommend using [vcpkg](https://github.com/Microsoft/vcpkg) to install them both.

```bash
vcpkg install SFML
vcpkg install opencv:x64-windows
```

#### CMAKE

This project is built using [CMAKE](https://cmake.org/).
```bash
mkdir build
cd build
cmake ..
make && sudo make install
```
