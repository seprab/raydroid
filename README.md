# RayDroid

![RayDroid](screenshots/screenshot000.png "RayDroid")

## Description
I'm just learning and practicing the following:
* Raylib
* C++ desktop development
* C++ android development
* Make utility

## Roadmap
- [ ] Configure the project to build a Windows executable with Make
- [ ] Configure the project to build a Windows executable with VS2022
- [x] Configure the project to build an Android APK with Make, src in C
- [ ] Configure the project to build an Android APK with Make, src in C++
- [ ] Plan next steps (ex. planning and creating a minigame)

## How to clone and how to work on it
1. `git clone git@github.com:seprab/raydroid.git`
2. `git submodule update --init --recursive`
3. To work on it, open the [raydroid solution](./raydroid.sln) with VS2022

## Android: How to build it
It must be built with Make using CMD (Windows tested):

### Pre-requisites:
- Use raylib bb87d2a (this should be automatically cloned with the submodule). The latest version is not working
- NDK 21.4.7075529 and save it in C:/android-ndk
- SDK Min: API 29 Max: I tested API 33
- SDK Build Tools 29.0.3
- OpenJDK 13 and save it in C:/open-jdk

### Process:
1. Compile raylib source code
    1. navigate from command line to directory raylib/src/
    2. Call `mingw32-make PLATFORM=PLATFORM_ANDROID`
2. Compile game
    1. Navigate back to the root directory
    2. Call `mingw32-make PLATFORM=PLATFORM_ANDROID`


## Windows: How to build it
It can be built with make or VS:

### VS2022:
1. Simply open the solution and build

### MAKE:
1. Download w64devkit https://github.com/skeeto/w64devkit/releases
2. Add its bin/ folder to path `set PATH=c:\path\to\w64devkit\bin;%PATH%`
3. Manually execute w64devkit.exe from the installation path
4. From the w64devkit terminal move raydroid directory
5. Call `make`
6. Execute the program by calling `./_bin/Debug/raydroid.exe`

### Notes
> * Both build methods cannot be used sequentially. Before switching build methods, call `git reset --hard && git clean -fdx`
> * Invoking w64devkit from Win terminal or Git bash, and then calling `make` doesn't complete the build.

### Adding new source files to game when using MAKE
Must be related in [_build\raydroid.make](_build\raydroid.make)
```
$(OBJDIR)/<new file name>.o: ../game/src/<new file name>.cpp
	@echo $(notdir $<)
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
```
### Building for other OpenGL targets
If you need to build for a different OpenGL version than the default (OpenGL 3.3) you can specify an openGL version in your premake command line. Just modify the bat file or add the following to your command line

#### For OpenGL 1.1
    --graphics-api=opengl11

#### For OpenGL 2.1
    --graphics-api=opengl21

#### For OpenGL 4.3
    --graphics-api=opengl43

## Features

 - $(Game Feature 01)
 - $(Game Feature 02)
 - $(Game Feature 03)

## Controls

Keyboard:
 - $(Game Control 01)
 - $(Game Control 02)
 - $(Game Control 03)

## Screenshots

_TODO: Show your game to the world, animated GIFs recommended!._

## Developers

 - SepraB - Doing whatever
 - $(Developer 02) - $(Role/Tasks Developed)
 - $(Developer 03) - $(Role/Tasks Developed)

## Links

 - YouTube Gameplay: $(YouTube Link)
 - itch.io Release: $(itch.io Game Page)
 - Steam Release: $(Steam Game Page)

## Credits
* [game-premake](https://github.com/raylib-extras/game-premake): I used to generate the initial files in this project.


## License

This game sources are licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.

$(Additional Licenses)

*Copyright (c) 2022 seprab [github](https://github.com/seprab)
