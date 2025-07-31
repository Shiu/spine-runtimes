# spine-flutter Runtime Documentation

> **Licensing**
>
> Please see the [Spine Runtimes License](/spine-runtimes-license) before integrating the Spine Runtimes into your applications.

# Getting Started
The spine-flutter runtime is implemented as a [Flutter FFI plugin](https://docs.flutter.dev/development/packages-and-plugins/developing-packages#plugin-ffi) on top of [spine-cpp](/spine-cpp). It supports all platforms supported by Flutter (desktop, Android, iOS, web), and supports all Spine features except tint black and screen blend mode.


## Installation
spine-flutter is supported from Flutter 3.10.5 onwards. To use spine-flutter in your Flutter project, add the following dependency to your project's `pubspec.yaml` file:

```yaml
dependencies:
  ...
  spine_flutter: ^4.2.36
```

See [spine_flutter on pub.dev](https://pub.dev/packages/spine_flutter) for the latest version.

Ensure that the `major.minor` version of spine-flutter matches the `major.minor` Spine Editor version you are exporting from. See [Spine Versioning](/spine-versioning#Synchronizing-versions) for more information.

In your `main()` function, add these two lines in the beginning to initialize the spine-flutter runtime:

```dart
void main() async {
    await initSpineFlutter(enableMemoryDebugging: false);
    ...
}
```

> **Note:** the `main()` method must be `async`.

## Samples
The spine-flutter runtime includes several samples that showcase its feature set.

You can run the example project following these steps:

1. Install the [Flutter SDK](https://docs.flutter.dev/get-started/install), then run `flutter doctor` which will instruct you what other dependencies to install.
2. Clone the spine-runtimes repository: `git clone https://github.com/esotericsoftware/spine-runtimes`
3. Run the `setup.sh` script in the `spine-flutter/` folder. On Windows, you can use [Git Bash](https://gitforwindows.org/) included in Git for Window to run the `setup.sh` Bash script.

You can then open `spine-flutter` in an IDE or editor of your choice that supports Flutter, like [IntelliJ IDEA/Android Studio](https://docs.flutter.dev/get-started/editor?tab=androidstudio) or [Visual Studio Code](https://docs.flutter.dev/get-started/editor?tab=vscode) to inspect and run the example.

Alternatively, you can run the example from the [command line](https://docs.flutter.dev/get-started/test-drive?tab=terminal).

The example project contains the following examples:
* [`example/lib/simple_animation.dart`](/git/spine-runtimes/spine-flutter/example/lib/simple_animation.dart): demonstrates the basic use of `SpineWidget` and `SpineWidgetController` to load an exported Spine skeleton, display it in the widget, and playback a specific animation.
* [`example/lib/pause_play_animation.dart`](/git/spine-runtimes/spine-flutter/example/lib/pause_play_animation.dart): demonstrates how to pause and resume an animation.
* [`example/lib/animation_state_events`](/git/spine-runtimes/spine-flutter/example/lib/animation_state_events.dart): demonstrates how set a slot's color, how to queue multiple animations, and how to to listen for animation state events.
* [`example/lib/debug_rendering.dart`](/git/spine-runtimes/spine-flutter/example/lib/debug_rendering.dart): shows how to perform custom drawing on top of the rendered skeleton via the `SpineWidgetController` `onAfterPaint` callback.
* [`example/lib/dress_up.dart`](/git/spine-runtimes/spine-flutter/example/lib/dress_up.dart): demonstrates Spine's skins feature as well as rendering a skeleton to a thumbnail for use in a character creation UI.
* [`example/lib/ik_following.dart`](/git/spine-runtimes/spine-flutter/example/lib/ik_following.dart): demonstrates how to let the user drag one of the skeleton's bones via mouse or touch input.
* [`example/lib/flame_example.dart`](/git/spine-runtimes/spine-flutter/example/lib/flame_example.dart): demonstrates how to write a simple [Flame](https://flame-engine.org/) component to use spine-flutter with the Flame game engine.

## Updating the spine-flutter Runtime
Before updating your project's spine-flutter runtime, please consult our [guide on Spine editor and runtime version management](/spine-runtime-architecture#Versioning).

To update the spine-flutter runtime, simply modify the version string of the `spine_flutter` package in your `pubspec.yaml`.

> **Note:** If you change the `major.minor` version of the `spine_flutter` package, you have to re-export your Spine skeletons with the same Spine Editor `major.minor` version!

# Using spine-flutter
The spine-flutter runtime is an idiomatic [Dart FFI wrapper](https://dart.dev/guides/libraries/c-interop) around the generic [spine-cpp](/spine-cpp) which supports loading, playback and manipulation of animations created with Spine. The spine-flutter runtime exposes almost all of the spine-cpp API as idiomatic Dart and provides Flutter and [Flame](https://flame-engine.org/) specific classes to easily display and interact with Spine skeletons.

The spine-flutter runtime supports all Spine features except tint black and screen blend mode.

## Asset Management
### Exporting for spine-flutter
![](/img/spine-runtimes-guide/spine-ue4/export.png)
Please follow the instructions in the Spine User Guide on how to

1. [Export skeleton & animation data](/spine-export)
2. [Export texture atlases containing the images of your skeleton](/spine-texture-packer)

An export of the skeleton data and texture atlas of your skeleton will yield the following files:

![](/img/spine-runtimes-guide/spine-ue4/exported-files.png)

1. `skeleton-name.json` or `skeleton-name.skel`, containing your skeleton and animation data.
2. `skeleton-name.atlas`, containing information about the texture atlas.
3. One or more `.png` files, each representing on page of your texture atlas containing the packed images your skeleton uses.

> **Note**: You should prefer binary skeleton exports over JSON exports, as they are smaller in size and faster to load.

The files can be loaded via spine-flutter classes like `Atlas`, `SkeletonData`, `SkeletonDrawable`, `SpineWidget`.

> **Note**: The spine-flutter runtime currently does not support atlases exported using pre-multiplied alpha due to technical limitations in Flutter. Flutter's rendering engine ensures that common non-premultiplied alpha artifacts are avoided.

### Updating Spine Assets
During development, you may frequently update your Spine skeleton data and texture atlas files. You can simply overwrite these source files (`.json`, `.skel`, `.atlas`, `.png`) by re-exporting from the Spine Editor and replacing the existing files in your Flutter project.

Ensure that the `major.minor` version of spine-flutter matches the `major.minor` Spine Editor version you are exporting from. See [Spine Versioning](/spine-versioning#Synchronizing-versions) for more information.

## Core classes
The spine-flutter API is built on top of the generic [spine-cpp](/spine-cpp) runtime, which provides platform independent  core classes and algorithms to load, query, modify, and animate Spine skeletons. The core classes are wrapped via Dart FFI and exposed as idiomatic Dart classes.

Here, we will briefly discuss the most important core classes that you will  encounter in your day-to-day use of spine-flutter. Please consult the [Spine Runtimes Guide](/spine-runtimes-guide)
for a detailed overview of the Spine Runtimes architecture, core classes, and API usage.

The [`Atlas`](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L102) class stores the data loaded from an `.atlas` file and its corresponding `.png` image files.

The [`SkeletonData`](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L199) class stores the data loaded from a `.json` or `.skel` skeleton file.  The skeleton data contains information about the bone hierarchy, slots, attachments, constraints, skins, and animations. A `SkeletonData` instance is usually loaded by also providing an `Atlas` from which it sources the images to be used by the skeleton it represents. It serves as a blueprint for creating `Skeleton` instances. Multiple skeletons can be instantiated from the same atlas and skeleton data, which then share the loaded data, minimizing both load times and memory consumption at runtime.

The [`Skeleton`](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L2734) class stores an instance of a skeleton, created from a `SkeletonData` instance. A skeleton stores its current pose, that is the position of bones and the current configuration of slots, attachments, and active skin. The current pose can be computed by either manually modifying the bone hierarchy, or, more commonly, by applying animations via an `AnimationState`.

The [`AnimationState`](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L3663) class is responsible for keeping track of which animation(s) should be applied to a skeleton, advancing and mixing those animations based on the elapsed time between the last and current rendering frame, and applying the animations to a skeleton instance, thereby setting its current pose. The `AnimationState` queries an [`AnimationStateData`](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L3600) instance to retrieve mixing times between animations, or fetches the default mix time if no mixing time is available for a pair of animations.

The spine-flutter runtime builds on top of these core classes.

## SpineWidget
![/img/spine-runtimes-guide/spine-flutter/simple-animation.png](/img/spine-runtimes-guide/spine-flutter/simple-animation.png)

A [`SpineWidget`](/git/spine-runtimes/spine-flutter/lib/spine_widget.dart#L261) is a [StatefulWidget](https://api.flutter.dev/flutter/widgets/StatefulWidget-class.html) responsible for loading and displaying a Spine skeleton. At a minimum, the widget needs to know from where to load the skeleton and atlas files, and it must receive a `SpineWidgetController` instance that is responsible for modifying the state of the widget, such as setting an animation, or changing the skin of the skeleton.

In the simplest case, a `SpineWidget` can be instantiated inside another widget's `build()` method like this:

```dart
@override
Widget build(BuildContext context) {
    final controller = SpineWidgetController(onInitialized: (controller) {
      // Set the walk animation on track 0, let it loop
      controller.animationState.setAnimationByName(0, "walk", true);
    });

    return Scaffold(
      appBar: AppBar(title: const Text('Simple Animation')),
      body: SpineWidget.fromAsset("assets/spineboy.atlas", "assets/spineboy-pro.skel", controller)
    );
}
```

Upon instantiation, the `SpineWidget` will asynchronously load the specified files and construct the underlying core class instances from them, namely instances of `Atlas`, `SkeletonData`, `Skeleton`, `AnimationStateData`, and `AnimationState`.

Once loading is complete, the `SpineWidgetController` is called, allowing it to modify the state of the widget, such as setting one or more animations, manipulating the bone hierarchy, or modifying the skin of the skeleton. See the section on `SpineWidgetController` below.

The `SpineWidget` class provides multiple static factory methods to load skeleton and atlas files from different sources:

* `SpineWidget.fromAsset()` loads files from the root bundle, or a provided bundle.
* `SpineWidget.fromFile()` loads files from the file system.
* `SpineWidget.fromHttp()` loads files from URLs.
* `SpineWidget.fromDrawable()` constructs a widget from a `SkeletonDrawable`. This is useful when the skeleton data should be preloaded, cached, and/or shared between `SpineWidget` instances. See the section "Pre-loading and sharing skeleton data" below.

All factory methods have optional arguments that let you further define how the Spine skeleton is fitted and aligned inside the widget, and how the widget is sized.

* `fit`, the [BoxFit](https://api.flutter.dev/flutter/painting/BoxFit.html) to use to fit the skeleton inside the widget.
* `alignment`, the [Alignment](https://api.flutter.dev/flutter/painting/Alignment-class.html) to use to align the skeleton inside the widget.
* `BoundsProvider`, used to calculate the pixel size of the bounding box to be used for the skeleton when computing the fit and alignment. By default, the skeleton's setup pose bounding box is used. See the class documentation for [`SetupPoseBounds`](/git/spine-runtimes/spine-flutter/lib/spine_widget.dart#L173), [`RawBounds`](/git/spine-runtimes/spine-flutter/lib/spine_widget.dart#L183), and [`SkinAndAnimationBounds`](/git/spine-runtimes/spine-flutter/lib/spine_widget.dart#L196) for additional information.
* `sizedByBounds`, defines whether to size the widgets by the bounds computed by the `BoundsProvider`, or have it sized by its parent widget.

## Pre-loading and sharing skeleton data
If you want to share the atlas and skeleton data between multiple `SpineWidget` instances, you can manually pre-load the assets:

```
final atlas = await Atlas.fromAsset("assets/test.atlas");
final skeletonData = await SkeletonData.fromAsset("assets/test.json", atlas);
```

You can then instantiate one or more `SpineWidget` instances from the same data, saving on load time and memory:

```
SpineWidget.fromDrawable(SkeletonDrawable(skeletonData, atlas));
```

You are responsible for disposing of the atlas and skeleton data one no `SpineWidget` (or `SkeletonDrawable`) refercing them exists anymore.

```
skeletonData.dispose();
atlas.dispose();
```

## SpineWidgetController
A [`SpineWidgetController`](/git/spine-runtimes/spine-flutter/lib/spine_widget.dart#L64) controls how the skeleton of a `SpineWidget` is animated and rendered. The controller is provided with a set of optional callbacks as constructor arguments, which are called at specific times during the life-time of the `SpineWidget`.

The controller exposes the skeleton state through getters returning Spine Runtimes API objects such as the `Atlas`, `SkeletonData`, `Skeleton`, and `AnimationState`, through which the state can be manipulated. See the [Spine Runtimes Guide](/spine-runtimes-guide), and the [class documentation](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart) for more information.

Upon initialization of a `SpineWidget`, the controller's `onInitialized()` callback method is invoked once. This method can be used to setup the initial animation(s) to be played back, or set the skin of the skeleton, among other things.

After initialization is complete, the `SpineWidget` is rendered continuously at the screen refresh rate. Each frame, the `AnimationState` is updated based on the currently queued animations, and applied to the `Skeleton`.

Next, the optional `onBeforeUpdateWorldTransforms()` callback is invoked, which can modify the skeleton before its current pose is calculated using `Skeleton.updateWorldTransform()`.

After the current pose has been calculated, the optional `onAfterUpdateWorldTransforms()` callback is invoked, which can further modify the current pose before the skeleton is rendered. This is a good place to manually position bones.

Before the skeleton is rendered by the `SpineWidget`, the optional `onBeforePaint()` callback is invoked, which allows rendering backgrounds or other objects that should go behind the skeleton on the [`Canvas`](https://api.flutter.dev/flutter/dart-ui/Canvas-class.html).

After the `SpineWidget` has rendered the current skeleton pose to the `Canvas`, the optional `onAfterPaint()` callback is invoked, which allows rendering additional objects on top of the skeleton.

By default, the widget updates and renders the skeleton every frame. The `SpineWidgetController.pause()` method can be used to pause updating and rendering the skeleton. The `SpineWidgetController.resume()` method resumes updating and rendering the skeleton. The `SpineWidgetController.isPlaying()` getter reports the current playback state. See the [`example/lib/animation_state_events.dart`](/git/spine-runtimes/spine-flutter/example/lib/animation_state_events.dart) example.

## SkeletonDrawable
A `SkeletonDrawable` bundles loading, storing, updating, and rendering a `Skeleton` and its associated `AnimationState` into a single, easy to use class. The class can be used as the basis for a custom widget implementation. The `SpineWidget` encapsulates the state of the skeleton it displays via an instance of a `SkeletonDrawable`.

Use the `fromAsset()`, `fromFile()`, or `fromHttp()` methods to construct a `SkeletonDrawable` from file assets. To share `Atlas` and `SkeletonData` among multiple `SkeletonDrawable` instances, instantiate the drawables via the constructor, passing the same atlas and skeleton data to each of them.

The `SkeletonDrawable` exposes the `Skeleton` and `AnimationState` to query, modify, and animate the skeleton. It also exposes the `Atlas` and `SkeletonData` from which the skeleton and animation state have been constructed.

To animate the skeleton, queue animations on one or more tracks via the `AnimationState` API, such as `AnimationState.setAnimation()` or `AnimationState.addAnimation()`.

To update the animation state, apply it to the skeleton, and update the current skeleton pose, call the `SkeletonDrawable.update()` method, providing it a delta time in seconds to advance the animations.

To render the current pose of the skeleton, use the rendering methods `SkeletonDrawable.render()`, `SkeletonDrawable.renderToCanvas()`, `SkeletonDrawable.renderToPictureRecorder()`, `SkeletonDrawable.renderToPng()`, or `SkeletonDrawable.renderToRawImageData()`.

The `SkeletonDrawable` stores objects allocated on the native heap. The native objects need to be manually disposed of via a call to `SkeletonDrawable.dispose()` if the `SkeletonDrawable` is no longer needed. Not doing so will result in a native memory leak.

> **Note:** when using `SpineWidget`, you do not have to manually dispose of the `SkeletonDrawable` the widget uses. The widget will dispose the `SkeletonDrawable` when it is disposed itself.

## Applying Animations
Applying animations to a skeleton displayed by a `SpineWidget` is done through the `AnimationState` in the callbacks of a `SpineWidgetController`.

> **Note:** See [Applying Animations](/spine-applying-animations#AnimationState-API) in the Spine Runtimes Guide for more in-depth information, specifically about animation tracks and animation queueing.

To set a specific animation on track 0, call `AnimationState.setAnimation()`:

```dart
final controller = SpineWidgetController(onInitialized: (controller) {
   // Set the walk animation on track 0, let it loop
   controller.animationState.setAnimationByName(0, "walk", true);
});
```

The first parameter specifies the track, the second parameter is the name of the animation, and the third parameter defines whether to loop the animation.

You can queue multiple animations:

```dart
controller.animationState.setAnimationByName(0, "walk", true);
controller.animationState.addAnimationByName(0, "jump", false, 2);
controller.animationState.addAnimationByName(0, "run", true, 0);
```

The first parameter to `addAnimationByName()` is the track. The second parameter is the name of the animation. The third parameter specifies the delay in seconds, after which this animation should replace the previous animation on the track. The final parameter defines whether to loop the animation.

In the example above, the `"walk"` animation is played back first. 2 seconds later, the `"jump"` animation is played back once, followed by a transition to the `"run"` animation, which will be looped.

When transitioning from one animation to another, `AnimationState` will mix the animations for a specificable duration. These mix times are defined in an `AnimationStateData` instance, from which the `AnimationState` retrieves mix times.

The `AnimationStateData` instance is also available through the controller. You can set the default mix time, or the mix time for a specific pair of animations:

```dart
controller.animationStateData.setDefaultMix(0.2);
controller.animationStateData.setMixByName("walk", "jump", 0.1);
```

When setting or adding an animation, a `TrackEntry` object is returned, which allows further modification of that animation's playback. For example, you can set the track entry to reverse the animation playback:

```dart
final entry = controller.animationState.setAnimationByName(0, "walk", true);
entry.setReverse(true);
```

See the [`TrackEntry` class documentation](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L3100) for more options.

> **Note:** Do not hold on to `TrackEntry` instances outside the function you are using them in. Track entries are re-used internally and will thus become invalid once the animation it represents has been completed.

You can set or queue empty animations on an animation track to smoothly reset the skeleton back to its setup pose:

```dart
controller.animationState.setEmptyAnimation(0, 0.5);
controller.animationState.addEmptyAnimation(0, 0.5, 0.5);
```

The first parameter to `setEmptyAnimation()` specifies the track. The second parameter specifies the mix duration in seconds used to mix out the previous animation and mix in the "empty" animation.

The first parameter to `addEmptyAnimation()` specifies the track. The second parameter specifies the mix duration. The third parameter is the delay in seconds, after which the empty animation should replace the previous animation on the track via mixing.

All animations on a track can be cleared immediately via `AnimationState.clearTrack()`. To clear all tracks at once, `AnimationState.clearTracks()` can be used. This will leave the skeleton in the last pose it was in.

To reset the pose of a skeleton to the setup pose, use `Skeleton.setToSetupPose()`:

```dart
controller.skeleton.setToSetupPose();
```

This will reset both the bones and slots to their setup pose configuration. Use `Skeleton.setSlotsToSetupPose()` to only reset the slots to their setup pose configuration.

## AnimationState Events
An `AnimationState` emits events during the life-cycle of an animation that is being played back. You can listen for this events to react as needed. The Spine Runtimes API defines the following [event types](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L3429):

* `Start`: emitted when an animation is started.
* `Interrupted`: emitted when an animation's track was cleared, or a new animation was set.
* `Completed`: emitted when an animation completes a loop.
* `Ended`: emitted when an animation will never be applied again.
* `Disposed`: emitted when the animation's track entry is disposed.
* `Event`: emitted when a user defined [event](/spine-events#Events) happened.

To receive events, you can register an [`AnimationStateListener`](/git/spine-runtimes/spine-flutter/lib/spine_flutter.dart#L3597) callback with either the `AnimationState` to receive events across all animations, or with the `TrackEntry` of a specific animation queued for playback:

```dart
final entry = controller.animationState.setAnimationByName(0, "walk", true);
entry.setListener((type, trackEntry, event) {
   if (type == EventType.event) {
      print("User defined event: ${event?.getData().getName()}");
   }
});

controller.animationState.setListener((type, trackEntry, event) {
   print("Animation state event $type");
});
```

See the [`example/lib/animation_state_events.dart`](/git/spine-runtimes/spine-flutter/example/lib/animation_state_events.dart) example.

## Skins
![/img/spine-runtimes-guide/spine-flutter/skins.png](/img/spine-runtimes-guide/spine-flutter/skins.png)

Many applications and games allow users to create custom avatars out of many individual items, such as hair, eyes, pants, or accessories like earrings or bags. With Spine, this can be achieved by [mixing and matching skins](/spine-examples-mix-and-match).

You can create custom skins from other skins like this:

```dart
final data = controller.skeletonData;
final skeleton = controller.skeleton;
final customSkin = Skin("custom-skin");
customSkin.addSkin(data.findSkin("skin-base")!);
customSkin.addSkin(data.findSkin("nose/short")!);
customSkin.addSkin(data.findSkin("eyelids/girly")!);
customSkin.addSkin(data.findSkin("eyes/violet")!);
customSkin.addSkin(data.findSkin("hair/brown")!);
customSkin.addSkin(data.findSkin("clothes/hoodie-orange")!);
customSkin.addSkin(data.findSkin("legs/pants-jeans")!);
customSkin.addSkin(data.findSkin("accessories/bag")!);
customSkin.addSkin(data.findSkin("accessories/hat-red-yellow")!);
skeleton.setSkin(customSkin);
skeleton.setSlotsToSetupPose();
```

Create a custom skin with the `Skin()` constructor.

Next, fetch the `SkeletonData` from the controller. It is used to look up skins by name via `SkeletonData.findSkin()`.

Add all the skins you want to combine into the new custom skin via `Skin.addSkin()`.

Finally, set the new skin on the `Skeleton` and call `Skeleton.setSlotsToSetupPose()` to ensure no attachments from previous skins and/or animations are left over.

> **Note:** A `Skin` wraps an underlying C++ object. It needs to be manually disposed via a call to `Skin.dispose()` when it is no longer in use.

See the [`example/lib/dress_up.dart`](/git/spine-runtimes/spine-flutter/example/lib/dress_up.dart) example, which also demonstrate how to render thumbnail previews of skins using `SkeletonDrawable`.

## Setting Bone Transforms
![/img/spine-runtimes-guide/spine-flutter/simple-animation.png](/img/spine-runtimes-guide/spine-flutter/bone-transform.png)

When authoring a skeleton in the Spine Editor, the skeleton is defined in what is called the skeleton coordinate system. This coordinate system may not align with the coordinate system of the `SpineWidget` the skeleton is rendered by. Touch coordinates relative to the `SpineWidget` need thus be converted to the skeleton coordinate system, e.g. if a user should be able to move a bone by touch.

The `SpineWidgetController` offers the method `toSkeletonCoordinates()` which takes an [`Offset`](https://api.flutter.dev/flutter/dart-ui/Offset-class.html) relative to the `SpineWidget` it is associated with, and converts it to the skeleton's coordinate system.

See the [`example/lib/ik_following.dart`](/git/spine-runtimes/spine-flutter/example/lib/ik_following.dart) example.

## Flame Integration
![/img/spine-runtimes-guide/spine-flutter/flame.png](/img/spine-runtimes-guide/spine-flutter/flame.png)

spine-flutter includes an example that shows how to load and renderer Spine skeletons in [Flame Engine](https://flame-engine.org/). See the [`example/lib/flame_example.dart`](/git/spine-runtimes/spine-flutter/example/lib/flame_example.dart) source file.

The example features a simple `SpineComponent` that extends Flame's `PositionComponent`. The `SpineComponent` can be instantiated through the static `SpineComponent.fromAsset()` method, or through the constructor.

The static method can be used as a quick, one-off loading mechanism when the skeleton and atlas data doesn't have to be shared with other components. The example contains a `FlameGame` implementation called `SimpleFlameExample` which demonstrates this simple way of getting a Spine skeleton on screen as part of a Flame game.

Creating a `SpineComponent` via the constructor allows more fine-grained management of the data loading and sharing by taking a `SkeletonDrawable`. E.g. you can pre-load the skeleton data and atlas, then share it across multiple `SpineComponent` instances. This will both improve memory usage and rendering performance, as data is shared, and rendering can be batched. See the `FlameGame` implementation called `PreloadAndShareSpineDataExample` for an example.

By design, Flame can not know when a component has reached its end of life. However, a `SpineComponent` handles native resources that need to be released at the end of its life. It is thus your responsibility to either call `SpineComponent.dispose()` if a `SpineComponent` is no longer in use. If the `SpineComponent` was constructed from a `SkeletonDrawable`, you may also have to manually dispose the `SkeletonData` and `Atlas` from which it was constructed, like in the `PreloadAndShareSpineDataExample` example.

# Spine Runtimes API access
spine-flutter maps almost all of the Spine Runtime API to Dart. Objects returned by `SpineWidgetController` or `SkeletonDrawable`, like `Skeleton` or `AnimationState` are 1:1 translations of the spine-cpp API to Dart. You can thus apply almost all of the materials in the generic [Spine Runtimes Guide](/spine-runtimes-guide) to your Dart code.

Due to the nature of the spine-cpp to Dart FFI bridge, there are however a few limitations:

* Any returned array or map is a copy of the internal array. Modification will not have an effect. However, returned `Float32List` or `Int32List` instances are wrappers around the underlying native memory, and can thus be used to modify the native data.
* You can not create, add or remove bones, slots, and other Spine objects directly.
* The C++ class hierarchies of timelines are not exposed in Dart.