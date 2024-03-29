# RayDroid

<img src="https://github.com/raysan5/raylib/blob/master/logo/raylib_logo_animation.gif" width="288px">
<!-- ![RayDroid](screenshots/screenshot000.png "RayDroid") -->

## Description
I'm just learning and practicing the following:
* Raylib
* C++ desktop development
* C++ android development
* Make utility

## Roadmap
- [x] Configure the project to build a Windows executable with Make
- [x] Configure the project to build a Windows executable with VS2022
- [x] Configure the project to build an Android APK with Make, src in C++

The steps above are working by [653dc34442](https://github.com/seprab/raydroid/tree/653dc34442d1b17e65faff112aeabb87877477ab)

> Additional note: The project is not compiling anymore for Android as Clang++ cannot access the standard library used in C++. The flag -stdlib=libc++ seems to help but throws more errors with raylib libraries. For now, I will continue on desktop development.

So, what about creating an RPG with cards interactions. I recall king made in Unity
- [x] Follow cards example by JeffM2501 [ref link](https://github.com/raylib-extras/examples-cpp/tree/main/cards)
- [ ] Create RPG character classes

## How to clone and how to work on it
1. `git clone git@github.com:seprab/raydroid.git`
2. `git submodule update --init --recursive`
3. To work on it, open the [raydroid solution](./raydroid.sln) with VS2022

## Android: How to build it
It must be built with Make using CMD (Windows tested):

### Pre-requisites:
- Use raylib bb87d2a (this should be automatically cloned with the submodule). The latest version is not working
- NDK 21.4.7075529 and save it in C:/android-ndk. -> For referece, I downloaded it from [here](https://download.java.net/java/GA/jdk13.0.2/d4173c853231432d94f001e99d882ca7/8/GPL/openjdk-13.0.2_windows-x64_bin.zip).
- SDK Min: API 29 Max: I tested API 33
- SDK Build Tools 29.0.3
- Set SDK path in `Makefile.Android`
- OpenJDK 13 and save it in C:/open-jdk

### Process:
1. Compile raylib source code
    1. navigate from command line to directory raylib/src/
    2. Call `mingw32-make PLATFORM=PLATFORM_ANDROID`
2. Compile game
    1. Navigate back to the root directory
    2. Call `mingw32-make PLATFORM=PLATFORM_ANDROID`

>The mingw32-make command works for me because I configured the envioronment path to `C:\w64devkit\bin`. I downloaded it from https://github.com/skeeto/w64devkit/releases/download/v1.15.0/w64devkit-1.15.0.zip

### Troubleshooting:
1. The audio might not work as it is. https://github.com/raysan5/raylib/issues/2118
Workaround:  
```
--- a/src/Makefile
+++ b/src/Makefile
@@ -535,6 +535,10 @@ ifeq ($(RAYLIB_MODULE_MODELS),TRUE)
 endif
 ifeq ($(RAYLIB_MODULE_AUDIO),TRUE)
     OBJS += raudio.o
+    # XXX: https://github.com/raysan5/raylib/issues/2118
+    ifeq ($(PLATFORM),PLATFORM_ANDROID)
+      CFLAGS += -DMA_SUPPORT_AAUDIO
+    endif
 endif
 ifeq ($(RAYLIB_MODULE_RAYGUI),TRUE)
     OBJS += raygui.o
```
## Windows: How to build it
It can be built with make or VS:

### VS2022:
1. Simply open the solution and build.
>There's a need to manually copy de resources folder to `_bin/Debug/` when building the solution. When using the local windows debugger (play button), it plays sounds as expected.

### MAKE:
1. Download w64devkit https://github.com/skeeto/w64devkit/releases
2. Add its bin/ folder to path `set PATH=c:\path\to\w64devkit\bin;%PATH%`
3. Manually execute w64devkit.exe from the installation path
4. From the w64devkit terminal move raydroid directory
5. Call `make`
6. Execute the program by calling `./desktop.raylib_game/raydroid.exe`
>If I ain't wrong, I need to compile raylib first. Go to `raylib/src` and call `make`.

### Notes
> * Both build methods cannot be used sequentially. Before switching build methods, call `git reset --hard && git clean -fdx`
> * Invoking w64devkit from Win terminal or Git bash, and then calling `make` doesn't complete the build.

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
