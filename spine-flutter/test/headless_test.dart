import 'dart:io';
import 'package:spine_flutter/spine_dart.dart';

void main() async {
  print('Testing atlas and skeleton data loading...');

  // Initialize with debug extension enabled
  await initSpineDart(enableMemoryDebugging: true);

  // Load atlas
  final atlasData = File('../example/assets/spineboy.atlas').readAsStringSync();
  final atlas = loadAtlas(atlasData);

  print('Atlas loaded successfully');
  print('Number of regions: ${atlas.regions.length}');

  // Load skeleton data
  final skeletonJson = File('../example/assets/spineboy-pro.json').readAsStringSync();
  final skeletonData = loadSkeletonDataJson(atlas, skeletonJson);

  print('Skeleton data loaded successfully');
  print('Number of bones: ${skeletonData.bones.length}');
  print('Number of slots: ${skeletonData.slots.length}');
  print('Number of animations: ${skeletonData.animations.length}');

  final skeleton = Skeleton(skeletonData);
  print('Skeleton created successfully');
  print('Skeleton has ${skeleton.slots.length} slots and ${skeleton.bones.length} bones');

  // Cleanup
  skeleton.dispose();
  skeletonData.dispose();
  atlas.dispose();

  // Report memory leaks
  reportLeaks();
  print('Test complete');
}
