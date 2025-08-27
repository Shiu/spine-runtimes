# spine-sdl Runtime Documentation

> **Licensing**
>
> Please see the [Spine Runtimes License](/spine-runtimes-license) before integrating the Spine Runtimes into your applications.

# Getting Started
spine-sdl is a C and C++ based runtime to load, manipulate and render Spine skeletons with [SDL](https://www.libsdl.org/).

spine-sdl requires SDL +2.0 and supports all Spine features except [two-color tinting](https://en.esotericsoftware.com/spine-slots#Tint-black)

## Installation

The spine-sdl runtime is available as a C and C++ API. The C API is based on the generic [spine-c](/spine-c) runtime, the C++ API is based on generic [spine-cpp](/spine-cpp) runtime. To integrate spine-sdl into your project:

1. Create a new SDL project. See the [SDL documentation](https://wiki.libsdl.org/FrontPage) or have a look at the example in [spine-runtimes repository](/git/spine-runtimes/tree/spine-sdl), which uses [CMake](https://cmake.org) as the build system.
2. Download the Spine Runtimes source using git (`git clone https://github.com/esotericsoftware/spine-runtimes`).
3. If you are using C:
   * Add the sources from `spine-c/spine-c/src/spine` and the file `spine-sdl/src/spine-sdl-c.c` to your project.
   * Add the folders `spine-c/spine-c/include` and `spine-sdl/src/` to your header search path.
3. If you are using C++:
   * Add the sources from `spine-cpp/spine-cpp/src/spine` and the file `spine-sdl/src/spine-sdl-cpp.cpp` to your project.
   * Add the folders `spine-cpp/spine-cpp/include` and `spine-sdl/src` to your header search path.

In your C or C++ code, include either of the following header files to get access to the `spine-sdl` API:

```
// C API
#include <spine-sdl-c.h>

// C++ API
#include <spine-sdl-cpp.h>
```

> *Note:* spine-sdl requires the [`SDL_RenderGeometry`](https://wiki.libsdl.org/SDL_RenderGeometry) API which is available since SDL 2.0.18. Earlier versions of SDL are not compatible with spine-sdl.

## Samples
The spine-sdl example works on Windows, Linux and Mac OS X. For a [spine-c](/spine-c) based example, see [example/main.c](/git/spine-runtimes/tree/spine-sdl/example/main.c), for a spine-cpp example see [example/main.cpp](/git/spine-runtimes/tree/spine-sdl/example/main.cpp).

### Windows
1. Install [Visual Studio Community](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx). Make sure you install support for C++ and CMake.
1. Download the Spine Runtimes repository using git (`git clone https://github.com/esotericsoftware/spine-runtimes`) or download it as a zip via the download button above.
1. Open Visual Studio Community, then open `spine-sdl/` via the `Open a local folder` button in the Visual Studio Community launcher
1. Wait for CMake to finish, then select either `spine-sdl-c-example.exe` or `spine-sdl-cpp-example.exe` as the start-up project and start debugging.

The entire example code is contained in [main.cpp](/git/spine-runtimes/tree/spine-sdl/example/main.cpp#L61).

### Linux
1. Install the [SDL build dependencies](https://github.com/libsdl-org/SDL/blob/main/docs/README-linux.md).
3. Download the Spine Runtimes repository using git (`git clone https://github.com/esotericsoftware/spine-runtimes`) or download it as a zip via the download button above.
4. Open a terminal, and `cd` into the `spine-runtimes/spine-sdl` folder.
5. Type `mkdir build && cd build && cmake ..` to generate Make files.
6. Type `make -j` to compile the example.
7. Run the example by `./spine-sdl-c-example` (C) or by `./spine-sdl-cpp-example` (C++).

### Mac OS X
1. Install [Xcode](https://developer.apple.com/xcode/).
2. Install [Homebrew](http://brew.sh/).
3. Open a terminal and install CMake via `brew install cmake`.
3. Download the Spine Runtimes repository using git (`git clone https://github.com/esotericsoftware/spine-runtimes`) or download it as a zip via the download button above.
4. Open a terminal, and `cd` into the `spine-runtimes/spine-sdl` folder.
5. Type `mkdir build && cd build && cmake -G Xcode ..` to generate Make files.
6. Type `open spine-sdl.xcodeproj` to open the Xcode project.
7. Run the example `spine-sdl-c-example` (C) or spine-sdl-cpp-example` (C++).

## Using spine-sdl
The spine-sdl runtime supports playback and manipulation of animations created with Spine with [SDL](https://www.libsdl.org). The spine-sdl runtime comes as both a C and C++ implementation, based on the generic [spine-c](/spine-c) and [spine-cpp](/spine-cpp) runtimes. It adds loading and rendering implementations based on the SDL APIs.

Please consult the [Spine Runtimes Guide](/spine-runtimes) for a detailed overview of the Spine Runtime architecture, and the [spine-c](/spine-c) and [spine-cpp](/spine-cpp) documentation for information on the core APIs used to playback and manipulate animations created with Spine with C and C++.

### Exporting for SDL
![](/img/spine-runtimes-guide/spine-ue4/export.png)
Please follow the instructions in the Spine User Guide on how to

1. [Export skeleton & animation data](/spine-export)
2. [Export texture atlases containing the images of your skeleton](/spine-texture-packer)

An export of the skeleton data and texture atlas of your skeleton will yield the following files:

![](/img/spine-runtimes-guide/spine-ue4/exported-files.png)

1. `skeleton-name.json` or `skeleton-name.skel`, containing your skeleton and animation data.
2. `skeleton-name.atlas`, containing information about the texture atlas.
3. One or more `.png` files, each representing on page of your texture atlas containing the packed images your skeleton uses.

> **Note:** The spine-sdl runtime does also not support two color tinting and the screen blend mode available in the Spine editor.

### Loading Spine skeletons
The spine-sdl runtime uses the [`SDL_Renderer`](https://wiki.libsdl.org/SDL_Renderer) API to display skeletons. Before a skeleton can be loaded from exported files, an `SDL_Renderer` must be created:

```
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
```

Next, the texture atlas can be loaded like this using the C API:

```
// C API
spAtlas *atlas = spAtlas_createFromFile("data/spineboy.atlas", renderer);

```

For the C++ API, a `SDLTextureLoader` is needed:

```
// C++ API
spine::SDLTextureLoader textureLoader(renderer);
spine::Atlas atlas("data/spineboy.atlas", &textureLoader);

```

With the atlas loaded, the `.json` or `.skel` file can be loaded using the C-API like this:

```
// C API
spSkeletonJson *json = spSkeletonJson_create(atlas);
spSkeletonData *skeletonData = spSkeletonJson_readSkeletonDataFile(json, "data/spineboy-pro.json");
spSkeletonJson_dispose(json);
```

For the C++ API, loading of the skeleton file is achieved like this:

```
// C++ API
spine::AtlasAttachmentLoader attachmentLoader(&atlas);
spine::SkeletonJson json(&attachmentLoader);
spine::SkeletonData *skeletonData = json.readSkeletonDataFile("data/spineboy-pro.json");
```

The `spAtlas`/`spine::Atlas` and `spSkeletonData`/`spine::SkeletonData` instances can then be used to create `spSkeletonDrawable`/`spine::SkeletonDrawable` instances to render the skeleton data.

> *Note:* the loaded skeleton data and atlas can and should be shared across `spSkeletonDrawable`/`spine::SkeletonDrawable` instances to reduce memory consumption and enable batched rendering of skeletons that share the same atlas data.

### Skeleton drawable
The main addition of spine-sdl on top of [spine-c](/spine-c) and [spine-cpp](/spine-cpp) is the skeleton drawable. It holds a `spSkeleton` (C API) or `spine::Skeleton` (C++ API), which stores the skeletons bones, slots, attachments, constraints and so on, and a `spAnimationState` (C API) or `spine::AnimationState`, which manages animating the skeleton. The skeleton drawable provides methods to update the animation state, apply it to the skeleton, update the skeleton and draw the skeleton using `SDL_Renderer`.

You can creating a skeleton drawable using the C API like this:

```
// C API
spAnimationStateData *animationStateData = spAnimationStateData_create(skeletonData);
spSkeletonDrawable *drawable = spSkeletonDrawable_create(skeletonData, animationStateData);
```

The `spAnimationStateData` stores mix times between animations and is required to construct the internal `spAnimationState`. Please refer to the [spine-c](/spine-c) documentation for more information.

For the C++ API, creating a skeleton drawable works like this:

```
// C++ API
spine::SkeletonDrawable drawable(skeletonData);
```

You can optionally pass a `spine::AnimationStateData` to the `spine::SkeletonDrawable` constructor if you want to share mix times between drawables. Please refer to the [spine-cpp](/spine-cpp) documentation for more information.

With the skeleton drawable created, you can access the contained skeleton and animation state instances to manipulate them.

```
// C API
drawable->skeleton->x = 400;
drawable->skeleton->y = 500;
spSkeleton_setToSetupPose(drawable->skeleton);

spAnimationState_setAnimationByName(drawable->animationState, 0, "portal", 0);
spAnimationState_addAnimationByName(drawable->animationState, 0, "run", -1, 0);
```

Or in C++:

```
// C++ API
drawable.skeleton->setPosition(400, 500);
drawable.skeleton->setToSetupPose();

drawable.animationState->setAnimation(0, "portal", true);
drawable.animationState->addAnimation(0, "run", true, 0);
```

Please refer to the [spine-c](/spine-c) and [spine-cpp](/spine-cpp) documentation for more information on the APIs to manipulate skeletons and animation states.

The skeleton drawable also provides a method to conveniently update the skeleton and animation state it contains:

```
// C API
spSkeletonDrawable_update(drawable, deltaTimeInSeconds);

// C++ API
drawable.update(deltaTimeInSeconds);
```

The update method takes the delta time between the last and current frame in seconds and then updates the animation state, applies the animation state to the skeleton, and finally udpates the world transforms of the skeleton.

After the animation state and skeleton have been updated, it can be drawn:

```
// C API
spSkeletonDrawable_draw(drawable, renderer);

// C++ API
drawable.draw(renderer);
```

Once you no longer need the skeleton drawable, you can free its memory via:

```
// C API
spSkeletonDrawable_dipose(drawable);

// C++ API, if the drawable was allocated on the heap via new
delete drawable;
```

> *Note:* freeing a skeleton drawable does not free the skeleton data and atlas it was created from. The skeleton data and atlas need to be freed separately through the respective API (`spSkeletonData_dipose(skeletonData)`/`spAtlas_dispose(atlas)` in C, or `delete` in C++).