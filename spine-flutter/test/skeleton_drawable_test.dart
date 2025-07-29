import 'dart:io';
import 'package:spine_flutter/spine_dart.dart';

void main() async {
  print('Testing SkeletonDrawable and event listeners...');

  // Initialize with debug extension enabled
  await initSpineDart(enableMemoryDebugging: true);

  // Load atlas and skeleton data
  final atlasData = File('../example/assets/spineboy.atlas').readAsStringSync();
  final atlas = loadAtlas(atlasData);
  final skeletonJson = File('../example/assets/spineboy-pro.json').readAsStringSync();
  final skeletonData = loadSkeletonDataJson(atlas, skeletonJson);

  // Create skeleton drawable
  final drawable = SkeletonDrawable(skeletonData);
  print('SkeletonDrawable created successfully');

  // Track events
  final events = <String>[];

  // Set global animation state listener
  drawable.setListener((type, entry, event) {
    final eventName = event?.data.name ?? 'null';
    events.add('State: $type, event: $eventName');
  });

  // Set an animation
  final trackEntry = drawable.animationState.setAnimation(0, 'walk', true);
  print('Set animation: walk');

  // Set track entry specific listener
  trackEntry.setListener(drawable, (type, entry, event) {
    final eventName = event?.data.name ?? 'null';
    events.add('TrackEntry: $type, event: $eventName');
  });

  // Update several times to trigger events
  print('\nUpdating animation state...');
  for (int i = 0; i < 5; i++) {
    drawable.update(0.016); // ~60fps
  }

  // Print collected events
  print('\nCollected events:');
  for (final event in events) {
    print('  $event');
  }

  // Test switching animations
  print('\nSwitching to run animation...');
  events.clear();
  drawable.animationState.setAnimation(0, 'run', true);

  // Update a few more times
  for (int i = 0; i < 3; i++) {
    drawable.update(0.016);
  }

  print('\nEvents after switching:');
  for (final event in events) {
    print('  $event');
  }

  // Cleanup
  drawable.dispose();
  skeletonData.dispose();
  atlas.dispose();

  // Report memory leaks
  reportLeaks();
  print('\nTest complete');
}
