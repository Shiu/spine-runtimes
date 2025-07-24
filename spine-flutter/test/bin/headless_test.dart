import 'dart:io';
import 'package:spine_flutter/spine_flutter.dart';

void main() async {
  print('Testing atlas and skeleton data loading...');

  // Initialize with debug extension enabled
  await initSpineFlutter(enableMemoryDebugging: true);

  // Load atlas
  final atlasData = File('../example/assets/spineboy.atlas').readAsStringSync();
  final atlas = AtlasExtensions.fromString(atlasData);

  print('Atlas loaded successfully');
  print('Number of regions: ${atlas.regions.length}');

  // Load skeleton data
  final skeletonJson = File('../example/assets/spineboy-pro.json').readAsStringSync();
  final skeletonDataResult = SkeletonDataExtensions.fromJson(atlas, skeletonJson);

  if (skeletonDataResult.error != null) {
    print('Error loading skeleton: ${skeletonDataResult.error}');
  } else {
    print('Skeleton data loaded successfully');
    final skeletonData = skeletonDataResult.skeletonData!;
    print('Number of bones: ${skeletonData.bones.length}');
    print('Number of slots: ${skeletonData.slots.length}');
    print('Number of animations: ${skeletonData.animations.length}');
  }

  // Cleanup
  skeletonDataResult.dispose();
  atlas.dispose();

  // Report memory leaks
  reportLeaks();
  print('Test complete');
}
