import 'spine_dart.dart';
export 'spine_dart.dart';
export 'spine_widget.dart';

// Backwards compatibility
Future<void> initSpineFlutter({bool useStaticLinkage = false, bool enableMemoryDebugging = false}) async {
  await initSpineDart(useStaticLinkage: useStaticLinkage, enableMemoryDebugging: enableMemoryDebugging);
  return;
}
