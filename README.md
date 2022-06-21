# RayDroid

![RayDroid](screenshots/screenshot000.png "RayDroid")

## How to clone and how to work on it
1. `git clone git@github.com:seprab/raydroid.git`
2. `git submodule update --init --recursive`
3. To work on it, open the [raydroid solution](./raydroid.sln) with VS2022
4. To build it:
    1. Download w64devkit https://github.com/skeeto/w64devkit/releases
    2. Add its bin/ folder to path `set PATH=c:\path\to\w64devkit\bin;%PATH%`
    3. Manually execute w64devkit.exe from the installation path
    4. From the w64devkit terminal move raydroid directory
    5. Call `make`

### Notes
> * Don't try to build from VS. Atm, I believe it corrupts something in the compiled objects.
> * Invoking w64devkit from Win terminal or Git bash, and then calling `make` doesn't complete the build.
> * The built application should be executed manually from File explorer or from w64devkit by calling `./_bin/Debug/raydroid.exe`. When called from Win terminal, some resources are not loaded.

## Adding new source files to game
Must be related in [_build\raydroid.make](_build\raydroid.make)
```
$(OBJDIR)/<new file name>.o: ../game/src/<new file name>.cpp
	@echo $(notdir $<)
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
```
## Building for other OpenGL targets
If you need to build for a different OpenGL version than the default (OpenGL 3.3) you can specify an openGL version in your premake command line. Just modify the bat file or add the following to your command line

### For OpenGL 1.1
    --graphics-api=opengl11

### For OpenGL 2.1
    --graphics-api=opengl21

### For OpenGL 4.3
    --graphics-api=opengl43


## Description

$(Your Game Description)

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

 - $(Developer 01) - $(Role/Tasks Developed)
 - $(Developer 02) - $(Role/Tasks Developed)
 - $(Developer 03) - $(Role/Tasks Developed)

## Links

 - YouTube Gameplay: $(YouTube Link)
 - itch.io Release: $(itch.io Game Page)
 - Steam Release: $(Steam Game Page)

## License

This game sources are licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.

$(Additional Licenses)

*Copyright (c) $(Year) $(User Name) ($(User Twitter/GitHub Name))*
