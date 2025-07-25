# Spine C++ Nullability Cleanup

## Instructions

**Review and Update Process**
For each unchecked checkbox (now with implementations inlined):
1. **Present both implementations** from the checkbox
2. **Ask if we need to change the C++ signature** based on Java nullability patterns (y/n)
3. **Make changes if needed**
   - Change the signature in the header file
   - Update the implementation in the corresponding .cpp file
   - Run `../../spine-cpp/build.sh` to confirm the changes compile successfully
4. **Confirm changes**
   - Summarize what was changed
   - Ask for confirmation that the changes are correct (y/n)
   - If yes, check the checkbox and move to the next unchecked item

## Methods to Review

- [x] [../../spine-cpp/include/spine/AnimationState.h:428](../../spine-cpp/include/spine/AnimationState.h#L428) TrackEntry * AnimationState::setAnimation(size_t trackIndex, const String & animationName, bool loop) // returns nullable pointer: TrackEntry *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:655
  655:TrackEntry *AnimationState::setAnimation(size_t trackIndex, const String &animationName, bool loop) {
  656-	Animation *animation = _data->_skeletonData->findAnimation(animationName);
  657-	assert(animation != NULL);
  658-	return setAnimation(trackIndex, animation, loop);
  659-}
  660-
  661:TrackEntry *AnimationState::setAnimation(size_t trackIndex, Animation *animation, bool loop) {
  662-	assert(animation != NULL);
  663-
  664-	bool interrupt = true;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:572
  572:	 * See {@link #setAnimation(int, Animation, boolean)}. */
  573:	public TrackEntry setAnimation (int trackIndex, String animationName, boolean loop) {
  574-		Animation animation = data.skeletonData.findAnimation(animationName);
  575-		if (animation == null) throw new IllegalArgumentException("Animation not found: " + animationName);
  576:		return setAnimation(trackIndex, animation, loop);
  577-	}
  578-
  579-	/** Sets the current animation for a track, discarding any queued animations.
  580-	 * <p>
  581-	 * If the formerly current track entry is for the same animation and was never applied to a skeleton, it is replaced (not mixed
  ```
- [x] [../../spine-cpp/include/spine/AnimationState.h:440](../../spine-cpp/include/spine/AnimationState.h#L440) TrackEntry * AnimationState::setAnimation(size_t trackIndex, Animation * animation, bool loop) // returns nullable pointer: TrackEntry *; takes nullable parameter 'animation': Animation *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:655
  655:TrackEntry *AnimationState::setAnimation(size_t trackIndex, const String &animationName, bool loop) {
  656-	Animation *animation = _data->_skeletonData->findAnimation(animationName);
  657-	assert(animation != NULL);
  658-	return setAnimation(trackIndex, animation, loop);
  659-}
  660-
  661:TrackEntry *AnimationState::setAnimation(size_t trackIndex, Animation *animation, bool loop) {
  662-	assert(animation != NULL);
  663-
  664-	bool interrupt = true;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:572
  572:	 * See {@link #setAnimation(int, Animation, boolean)}. */
  573:	public TrackEntry setAnimation (int trackIndex, String animationName, boolean loop) {
  574-		Animation animation = data.skeletonData.findAnimation(animationName);
  575-		if (animation == null) throw new IllegalArgumentException("Animation not found: " + animationName);
  576:		return setAnimation(trackIndex, animation, loop);
  577-	}
  578-
  579-	/** Sets the current animation for a track, discarding any queued animations.
  580-	 * <p>
  581-	 * If the formerly current track entry is for the same animation and was never applied to a skeleton, it is replaced (not mixed
  ```
- [x] [../../spine-cpp/include/spine/AnimationState.h:445](../../spine-cpp/include/spine/AnimationState.h#L445) TrackEntry * AnimationState::addAnimation(size_t trackIndex, const String & animationName, bool loop, float delay) // returns nullable pointer: TrackEntry *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:687
  687:TrackEntry *AnimationState::addAnimation(size_t trackIndex, const String &animationName, bool loop, float delay) {
  688-	Animation *animation = _data->_skeletonData->findAnimation(animationName);
  689-	assert(animation != NULL);
  690-	return addAnimation(trackIndex, animation, loop, delay);
  691-}
  692-
  693:TrackEntry *AnimationState::addAnimation(size_t trackIndex, Animation *animation, bool loop, float delay) {
  694-	assert(animation != NULL);
  695-
  696-	TrackEntry *last = expandToIndex(trackIndex);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:612
  612:	 * See {@link #addAnimation(int, Animation, boolean, float)}. */
  613:	public TrackEntry addAnimation (int trackIndex, String animationName, boolean loop, float delay) {
  614-		Animation animation = data.skeletonData.findAnimation(animationName);
  615-		if (animation == null) throw new IllegalArgumentException("Animation not found: " + animationName);
  616:		return addAnimation(trackIndex, animation, loop, delay);
  617-	}
  618-
  619-	/** Adds an animation to be played after the current or last queued animation for a track. If the track has no entries, this is
  620-	 * equivalent to calling {@link #setAnimation(int, Animation, boolean)}.
  621-	 * @param delay If > 0, sets {@link TrackEntry#getDelay()}. If <= 0, the delay set is the duration of the previous track entry
  ```
- [x] [../../spine-cpp/include/spine/AnimationState.h:455](../../spine-cpp/include/spine/AnimationState.h#L455) TrackEntry * AnimationState::addAnimation(size_t trackIndex, Animation * animation, bool loop, float delay) // returns nullable pointer: TrackEntry *; takes nullable parameter 'animation': Animation *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:687
  687:TrackEntry *AnimationState::addAnimation(size_t trackIndex, const String &animationName, bool loop, float delay) {
  688-	Animation *animation = _data->_skeletonData->findAnimation(animationName);
  689-	assert(animation != NULL);
  690-	return addAnimation(trackIndex, animation, loop, delay);
  691-}
  692-
  693:TrackEntry *AnimationState::addAnimation(size_t trackIndex, Animation *animation, bool loop, float delay) {
  694-	assert(animation != NULL);
  695-
  696-	TrackEntry *last = expandToIndex(trackIndex);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:612
  612:	 * See {@link #addAnimation(int, Animation, boolean, float)}. */
  613:	public TrackEntry addAnimation (int trackIndex, String animationName, boolean loop, float delay) {
  614-		Animation animation = data.skeletonData.findAnimation(animationName);
  615-		if (animation == null) throw new IllegalArgumentException("Animation not found: " + animationName);
  616:		return addAnimation(trackIndex, animation, loop, delay);
  617-	}
  618-
  619-	/** Adds an animation to be played after the current or last queued animation for a track. If the track has no entries, this is
  620-	 * equivalent to calling {@link #setAnimation(int, Animation, boolean)}.
  621-	 * @param delay If > 0, sets {@link TrackEntry#getDelay()}. If <= 0, the delay set is the duration of the previous track entry
  ```
- [x] [../../spine-cpp/include/spine/AnimationState.h:474](../../spine-cpp/include/spine/AnimationState.h#L474) TrackEntry * AnimationState::setEmptyAnimation(size_t trackIndex, float mixDuration) // returns nullable pointer: TrackEntry *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:717
  717:TrackEntry *AnimationState::setEmptyAnimation(size_t trackIndex, float mixDuration) {
  718-	TrackEntry *entry = setAnimation(trackIndex, AnimationState::getEmptyAnimation(), false);
  719-	entry->_mixDuration = mixDuration;
  720-	entry->_trackEnd = mixDuration;
  721-	return entry;
  722-}
  723-
  724-TrackEntry *AnimationState::addEmptyAnimation(size_t trackIndex, float mixDuration, float delay) {
  725-	TrackEntry *entry = addAnimation(trackIndex, AnimationState::getEmptyAnimation(), false, delay);
  726-	if (delay <= 0) entry->_delay = MathUtil::max(entry->_delay + entry->_mixDuration - mixDuration, 0.0f);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:522
  522:	 * It may be desired to use {@link AnimationState#setEmptyAnimation(int, float)} to mix the skeletons back to the setup pose,
  523-	 * rather than leaving them in their current pose. */
  524-	public void clearTrack (int trackIndex) {
  525-		if (trackIndex < 0) throw new IllegalArgumentException("trackIndex must be >= 0.");
  526-		if (trackIndex >= tracks.size) return;
  527-		TrackEntry current = tracks.items[trackIndex];
  528-		if (current == null) return;
  529-
  530-		queue.end(current);
  531-
  ```
- [x] [../../spine-cpp/include/spine/AnimationState.h:489](../../spine-cpp/include/spine/AnimationState.h#L489) TrackEntry * AnimationState::addEmptyAnimation(size_t trackIndex, float mixDuration, float delay) // returns nullable pointer: TrackEntry *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:724
  724:TrackEntry *AnimationState::addEmptyAnimation(size_t trackIndex, float mixDuration, float delay) {
  725-	TrackEntry *entry = addAnimation(trackIndex, AnimationState::getEmptyAnimation(), false, delay);
  726-	if (delay <= 0) entry->_delay = MathUtil::max(entry->_delay + entry->_mixDuration - mixDuration, 0.0f);
  727-	entry->_mixDuration = mixDuration;
  728-	entry->_trackEnd = mixDuration;
  729-	return entry;
  730-}
  731-
  732-void AnimationState::setEmptyAnimations(float mixDuration) {
  733-	bool oldDrainDisabled = _queue->_drainDisabled;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:657
  657:	 * {@link #setEmptyAnimations(float)}, or {@link #addEmptyAnimation(int, float, float)}. Mixing to an empty animation causes
  658-	 * the previous animation to be applied less and less over the mix duration. Properties keyed in the previous animation
  659-	 * transition to the value from lower tracks or to the setup pose value if no lower tracks key the property. A mix duration of
  660-	 * 0 still mixes out over one frame.
  661-	 * <p>
  662-	 * Mixing in is done by first setting an empty animation, then adding an animation using
  663-	 * {@link #addAnimation(int, Animation, boolean, float)} with the desired delay (an empty animation has a duration of 0) and on
  664-	 * the returned track entry, set the {@link TrackEntry#setMixDuration(float)}. Mixing from an empty animation causes the new
  665-	 * animation to be applied more and more over the mix duration. Properties keyed in the new animation transition from the value
  666-	 * from lower tracks or from the setup pose value if no lower tracks key the property to the value keyed in the new animation.
  ```
- [x] [../../spine-cpp/include/spine/AnimationState.h:498](../../spine-cpp/include/spine/AnimationState.h#L498) TrackEntry * AnimationState::getCurrent(size_t trackIndex) // returns nullable pointer: TrackEntry *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:745
  745:TrackEntry *AnimationState::getCurrent(size_t trackIndex) {
  746-	return trackIndex >= _tracks.size() ? NULL : _tracks[trackIndex];
  747-}
  748-
  749-AnimationStateData &AnimationState::getData() {
  750-	return *_data;
  751-}
  752-
  753-Array<TrackEntry *> &AnimationState::getTracks() {
  754-	return _tracks;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:826
  826:	public @Null TrackEntry getCurrent (int trackIndex) {
  827-		if (trackIndex < 0) throw new IllegalArgumentException("trackIndex must be >= 0.");
  828-		if (trackIndex >= tracks.size) return null;
  829-		return tracks.items[trackIndex];
  830-	}
  831-
  832-	/** Adds a listener to receive events for all track entries. */
  833-	public void addListener (AnimationStateListener listener) {
  834-		if (listener == null) throw new IllegalArgumentException("listener cannot be null.");
  835-		listeners.add(listener);
  ```
- [x] [../../spine-cpp/include/spine/AnimationState.h:528](../../spine-cpp/include/spine/AnimationState.h#L528) void AnimationState::disposeTrackEntry(TrackEntry * entry) // takes nullable parameter 'entry': TrackEntry *
  ```cpp
  ../../spine-cpp/src/spine/AnimationState.cpp:791
  791:void AnimationState::disposeTrackEntry(TrackEntry *entry) {
  792-	entry->reset();
  793-	_trackEntryPool.free(entry);
  794-}
  795-
  796-Animation *AnimationState::getEmptyAnimation() {
  797-	static Array<Timeline *> timelines;
  798-	static Animation ret(String("<empty>"), timelines, 0);
  799-	return &ret;
  800-}
  ```
  ```java
  NOT FOUND - searched for class "AnimationState" (from C++ "AnimationState") and method "disposeTrackEntry" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/AnimationStateData.h:52](../../spine-cpp/include/spine/AnimationStateData.h#L52) SkeletonData * AnimationStateData::getSkeletonData() // returns nullable pointer: SkeletonData *
  ```cpp
  ../../spine-cpp/src/spine/AnimationStateData.cpp:64
  64:SkeletonData *AnimationStateData::getSkeletonData() {
  65-	return _skeletonData;
  66-}
  67-
  68-float AnimationStateData::getDefaultMix() {
  69-	return _defaultMix;
  70-}
  71-
  72-void AnimationStateData::setDefaultMix(float inValue) {
  73-	_defaultMix = inValue;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationStateData.java:49
  49:	public SkeletonData getSkeletonData () {
  50-		return skeletonData;
  51-	}
  52-
  53-	/** Sets a mix duration by animation name.
  54-	 * <p>
  55-	 * See {@link #setMix(Animation, Animation, float)}. */
  56-	public void setMix (String fromName, String toName, float duration) {
  57-		Animation from = skeletonData.findAnimation(fromName);
  58-		if (from == null) throw new IllegalArgumentException("Animation not found: " + fromName);
  ```
- [x] [../../spine-cpp/include/spine/AnimationStateData.h:64](../../spine-cpp/include/spine/AnimationStateData.h#L64) void AnimationStateData::setMix(Animation * from, Animation * to, float duration) // takes nullable parameter 'from': Animation *; takes nullable parameter 'to': Animation *
  ```cpp
  ../../spine-cpp/src/spine/AnimationStateData.cpp:39
  39:void AnimationStateData::setMix(const String &fromName, const String &toName, float duration) {
  40-	Animation *from = _skeletonData->findAnimation(fromName);
  41-	Animation *to = _skeletonData->findAnimation(toName);
  42-
  43-	setMix(from, to, duration);
  44-}
  45-
  46:void AnimationStateData::setMix(Animation *from, Animation *to, float duration) {
  47-	assert(from != NULL);
  48-	assert(to != NULL);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationStateData.java:55
  55:	 * See {@link #setMix(Animation, Animation, float)}. */
  56:	public void setMix (String fromName, String toName, float duration) {
  57-		Animation from = skeletonData.findAnimation(fromName);
  58-		if (from == null) throw new IllegalArgumentException("Animation not found: " + fromName);
  59-		Animation to = skeletonData.findAnimation(toName);
  60-		if (to == null) throw new IllegalArgumentException("Animation not found: " + toName);
  61:		setMix(from, to, duration);
  62-	}
  63-
  64-	/** Sets the mix duration when changing from the specified animation to the other.
  ```
- [x] [../../spine-cpp/include/spine/AnimationStateData.h:68](../../spine-cpp/include/spine/AnimationStateData.h#L68) float AnimationStateData::getMix(Animation * from, Animation * to) // takes nullable parameter 'from': Animation *; takes nullable parameter 'to': Animation *
  ```cpp
  ../../spine-cpp/src/spine/AnimationStateData.cpp:54
  54:float AnimationStateData::getMix(Animation *from, Animation *to) {
  55-	assert(from != NULL);
  56-	assert(to != NULL);
  57-
  58-	AnimationPair key(from, to);
  59-
  60-	if (_animationToMixTime.containsKey(key)) return _animationToMixTime[key];
  61-	return _defaultMix;
  62-}
  63-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationStateData.java:78
  78:	public float getMix (Animation from, Animation to) {
  79-		if (from == null) throw new IllegalArgumentException("from cannot be null.");
  80-		if (to == null) throw new IllegalArgumentException("to cannot be null.");
  81-		tempKey.a1 = from;
  82-		tempKey.a2 = to;
  83-		return animationToMixTime.get(tempKey, defaultMix);
  84-	}
  85-
  86-	/** The mix duration to use when no mix duration has been defined between two animations. */
  87-	public float getDefaultMix () {
  ```
- [x] [../../spine-cpp/include/spine/Atlas.h:258](../../spine-cpp/include/spine/Atlas.h#L258) AtlasRegion * Atlas::findRegion(const String & name) // returns nullable pointer: AtlasRegion *
  ```cpp
  ../../spine-cpp/src/spine/Atlas.cpp:88
  88:AtlasRegion *Atlas::findRegion(const String &name) {
  89-	for (size_t i = 0, n = _regions.size(); i < n; ++i)
  90-		if (_regions[i]->_name == name) return _regions[i];
  91-	return nullptr;
  92-}
  93-
  94-Array<AtlasPage *> &Atlas::getPages() {
  95-	return _pages;
  96-}
  97-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:56
  56:			regions[i] = atlas.findRegion(path);
  57-			if (regions[i] == null) throw new RuntimeException("Region not found in atlas: " + path + " (sequence: " + name + ")");
  58-		}
  59-	}
  60-
  61-	public RegionAttachment newRegionAttachment (Skin skin, String name, String path, @Null Sequence sequence) {
  62-		var attachment = new RegionAttachment(name);
  63-		if (sequence != null)
  64-			loadSequence(name, path, sequence);
  65-		else {
  ```
- [x] [../../spine-cpp/include/spine/AtlasAttachmentLoader.h:51](../../spine-cpp/include/spine/AtlasAttachmentLoader.h#L51) RegionAttachment * AtlasAttachmentLoader::newRegionAttachment(Skin & skin, const String & name, const String & path, Sequence * sequence) // returns nullable pointer: RegionAttachment *; takes nullable parameter 'sequence': Sequence *
  ```cpp
  ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp:56
  56:RegionAttachment *AtlasAttachmentLoader::newRegionAttachment(Skin &skin, const String &name, const String &path, Sequence *sequence) {
  57-	SP_UNUSED(skin);
  58-	RegionAttachment *attachment = new (__FILE__, __LINE__) RegionAttachment(name);
  59-	if (sequence) {
  60-		if (!loadSequence(_atlas, path, sequence)) return NULL;
  61-	} else {
  62-		AtlasRegion *region = findRegion(path);
  63-		if (!region) return NULL;
  64-		attachment->setRegion(region);
  65-	}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:61
  61:	public RegionAttachment newRegionAttachment (Skin skin, String name, String path, @Null Sequence sequence) {
  62-		var attachment = new RegionAttachment(name);
  63-		if (sequence != null)
  64-			loadSequence(name, path, sequence);
  65-		else {
  66-			AtlasRegion region = atlas.findRegion(path);
  67-			if (region == null)
  68-				throw new RuntimeException("Region not found in atlas: " + path + " (region attachment: " + name + ")");
  69-			attachment.setRegion(region);
  70-		}
  ```
- [x] [../../spine-cpp/include/spine/AtlasAttachmentLoader.h:53](../../spine-cpp/include/spine/AtlasAttachmentLoader.h#L53) MeshAttachment * AtlasAttachmentLoader::newMeshAttachment(Skin & skin, const String & name, const String & path, Sequence * sequence) // returns nullable pointer: MeshAttachment *; takes nullable parameter 'sequence': Sequence *
  ```cpp
  ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp:69
  69:MeshAttachment *AtlasAttachmentLoader::newMeshAttachment(Skin &skin, const String &name, const String &path, Sequence *sequence) {
  70-	SP_UNUSED(skin);
  71-	MeshAttachment *attachment = new (__FILE__, __LINE__) MeshAttachment(name);
  72-
  73-	if (sequence) {
  74-		if (!loadSequence(_atlas, path, sequence)) return NULL;
  75-	} else {
  76-		AtlasRegion *region = findRegion(path);
  77-		if (!region) return NULL;
  78-		attachment->setRegion(region);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:74
  74:	public MeshAttachment newMeshAttachment (Skin skin, String name, String path, @Null Sequence sequence) {
  75-		var attachment = new MeshAttachment(name);
  76-		if (sequence != null)
  77-			loadSequence(name, path, sequence);
  78-		else {
  79-			AtlasRegion region = atlas.findRegion(path);
  80-			if (region == null)
  81-				throw new RuntimeException("Region not found in atlas: " + path + " (mesh attachment: " + name + ")");
  82-			attachment.setRegion(region);
  83-		}
  ```
- [x] [../../spine-cpp/include/spine/AtlasAttachmentLoader.h:55](../../spine-cpp/include/spine/AtlasAttachmentLoader.h#L55) BoundingBoxAttachment * AtlasAttachmentLoader::newBoundingBoxAttachment(Skin & skin, const String & name) // returns nullable pointer: BoundingBoxAttachment *
  ```cpp
  ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp:83
  83:BoundingBoxAttachment *AtlasAttachmentLoader::newBoundingBoxAttachment(Skin &skin, const String &name) {
  84-	SP_UNUSED(skin);
  85-	return new (__FILE__, __LINE__) BoundingBoxAttachment(name);
  86-}
  87-
  88-PathAttachment *AtlasAttachmentLoader::newPathAttachment(Skin &skin, const String &name) {
  89-	SP_UNUSED(skin);
  90-	return new (__FILE__, __LINE__) PathAttachment(name);
  91-}
  92-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:87
  87:	public BoundingBoxAttachment newBoundingBoxAttachment (Skin skin, String name) {
  88-		return new BoundingBoxAttachment(name);
  89-	}
  90-
  91-	public ClippingAttachment newClippingAttachment (Skin skin, String name) {
  92-		return new ClippingAttachment(name);
  93-	}
  94-
  95-	public PathAttachment newPathAttachment (Skin skin, String name) {
  96-		return new PathAttachment(name);
  ```
- [x] [../../spine-cpp/include/spine/AtlasAttachmentLoader.h:57](../../spine-cpp/include/spine/AtlasAttachmentLoader.h#L57) PathAttachment * AtlasAttachmentLoader::newPathAttachment(Skin & skin, const String & name) // returns nullable pointer: PathAttachment *
  ```cpp
  ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp:88
  88:PathAttachment *AtlasAttachmentLoader::newPathAttachment(Skin &skin, const String &name) {
  89-	SP_UNUSED(skin);
  90-	return new (__FILE__, __LINE__) PathAttachment(name);
  91-}
  92-
  93-PointAttachment *AtlasAttachmentLoader::newPointAttachment(Skin &skin, const String &name) {
  94-	SP_UNUSED(skin);
  95-	return new (__FILE__, __LINE__) PointAttachment(name);
  96-}
  97-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:95
  95:	public PathAttachment newPathAttachment (Skin skin, String name) {
  96-		return new PathAttachment(name);
  97-	}
  98-
  99-	public PointAttachment newPointAttachment (Skin skin, String name) {
  100-		return new PointAttachment(name);
  101-	}
  102-}
  ```
- [x] [../../spine-cpp/include/spine/AtlasAttachmentLoader.h:59](../../spine-cpp/include/spine/AtlasAttachmentLoader.h#L59) PointAttachment * AtlasAttachmentLoader::newPointAttachment(Skin & skin, const String & name) // returns nullable pointer: PointAttachment *
  ```cpp
  ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp:93
  93:PointAttachment *AtlasAttachmentLoader::newPointAttachment(Skin &skin, const String &name) {
  94-	SP_UNUSED(skin);
  95-	return new (__FILE__, __LINE__) PointAttachment(name);
  96-}
  97-
  98-ClippingAttachment *AtlasAttachmentLoader::newClippingAttachment(Skin &skin, const String &name) {
  99-	SP_UNUSED(skin);
  100-	return new (__FILE__, __LINE__) ClippingAttachment(name);
  101-}
  102-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:99
  99:	public PointAttachment newPointAttachment (Skin skin, String name) {
  100-		return new PointAttachment(name);
  101-	}
  102-}
  ```
- [x] [../../spine-cpp/include/spine/AtlasAttachmentLoader.h:61](../../spine-cpp/include/spine/AtlasAttachmentLoader.h#L61) ClippingAttachment * AtlasAttachmentLoader::newClippingAttachment(Skin & skin, const String & name) // returns nullable pointer: ClippingAttachment *
  ```cpp
  ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp:98
  98:ClippingAttachment *AtlasAttachmentLoader::newClippingAttachment(Skin &skin, const String &name) {
  99-	SP_UNUSED(skin);
  100-	return new (__FILE__, __LINE__) ClippingAttachment(name);
  101-}
  102-
  103-AtlasRegion *AtlasAttachmentLoader::findRegion(const String &name) {
  104-	return _atlas->findRegion(name);
  105-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:91
  91:	public ClippingAttachment newClippingAttachment (Skin skin, String name) {
  92-		return new ClippingAttachment(name);
  93-	}
  94-
  95-	public PathAttachment newPathAttachment (Skin skin, String name) {
  96-		return new PathAttachment(name);
  97-	}
  98-
  99-	public PointAttachment newPointAttachment (Skin skin, String name) {
  100-		return new PointAttachment(name);
  ```
- [x] [../../spine-cpp/include/spine/AtlasAttachmentLoader.h:63](../../spine-cpp/include/spine/AtlasAttachmentLoader.h#L63) AtlasRegion * AtlasAttachmentLoader::findRegion(const String & name) // returns nullable pointer: AtlasRegion *
  ```cpp
  ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp:103
  103:AtlasRegion *AtlasAttachmentLoader::findRegion(const String &name) {
  104-	return _atlas->findRegion(name);
  105-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AtlasAttachmentLoader.java:56
  56:			regions[i] = atlas.findRegion(path);
  57-			if (regions[i] == null) throw new RuntimeException("Region not found in atlas: " + path + " (sequence: " + name + ")");
  58-		}
  59-	}
  60-
  61-	public RegionAttachment newRegionAttachment (Skin skin, String name, String path, @Null Sequence sequence) {
  62-		var attachment = new RegionAttachment(name);
  63-		if (sequence != null)
  64-			loadSequence(name, path, sequence);
  65-		else {
  ```
- [x] [../../spine-cpp/include/spine/AtlasRegion.h:124](../../spine-cpp/include/spine/AtlasRegion.h#L124) AtlasPage * AtlasRegion::getPage() // returns nullable pointer: AtlasPage *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/AtlasRegion.cpp
  ```
  ```java
  NOT FOUND - searched for class "AtlasRegion" (from C++ "AtlasRegion") and method "getPage" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/AtlasRegion.h:175](../../spine-cpp/include/spine/AtlasRegion.h#L175) void AtlasRegion::setPage(AtlasPage * value) // takes nullable parameter 'value': AtlasPage *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/AtlasRegion.cpp
  ```
  ```java
  NOT FOUND - searched for class "AtlasRegion" (from C++ "AtlasRegion") and method "setPage" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/Attachment.h:48](../../spine-cpp/include/spine/Attachment.h#L48) Attachment * Attachment::copy() // returns nullable pointer: Attachment *
  ```cpp
  PURE VIRTUAL - concrete implementations in: ../../spine-cpp/src/spine/PointAttachment.cpp, ../../spine-cpp/src/spine/RegionAttachment.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/Attachment.java:56
  56:	abstract public Attachment copy ();
  57-}
  ```
- [x] [../../spine-cpp/include/spine/AttachmentLoader.h:63](../../spine-cpp/include/spine/AttachmentLoader.h#L63) RegionAttachment * AttachmentLoader::newRegionAttachment(Skin & skin, const String & name, const String & path, Sequence * sequence) // returns nullable pointer: RegionAttachment *; takes nullable parameter 'sequence': Sequence *
  ```cpp
  PURE VIRTUAL - concrete implementations in: ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AttachmentLoader.java:42
  42:	public @Null RegionAttachment newRegionAttachment (Skin skin, String name, String path, @Null Sequence sequence);
  43-
  44-	/** @return May be null to not load the attachment. In that case null should also be returned for child meshes. */
  45-	public @Null MeshAttachment newMeshAttachment (Skin skin, String name, String path, @Null Sequence sequence);
  46-
  47-	/** @return May be null to not load the attachment. */
  48-	public @Null BoundingBoxAttachment newBoundingBoxAttachment (Skin skin, String name);
  49-
  50-	/** @return May be null to not load the attachment. */
  51-	public @Null ClippingAttachment newClippingAttachment (Skin skin, String name);
  ```
- [x] [../../spine-cpp/include/spine/AttachmentLoader.h:66](../../spine-cpp/include/spine/AttachmentLoader.h#L66) MeshAttachment * AttachmentLoader::newMeshAttachment(Skin & skin, const String & name, const String & path, Sequence * sequence) // returns nullable pointer: MeshAttachment *; takes nullable parameter 'sequence': Sequence *
  ```cpp
  PURE VIRTUAL - concrete implementations in: ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AttachmentLoader.java:45
  45:	public @Null MeshAttachment newMeshAttachment (Skin skin, String name, String path, @Null Sequence sequence);
  46-
  47-	/** @return May be null to not load the attachment. */
  48-	public @Null BoundingBoxAttachment newBoundingBoxAttachment (Skin skin, String name);
  49-
  50-	/** @return May be null to not load the attachment. */
  51-	public @Null ClippingAttachment newClippingAttachment (Skin skin, String name);
  52-
  53-	/** @return May be null to not load the attachment. */
  54-	public @Null PathAttachment newPathAttachment (Skin skin, String name);
  ```
- [x] [../../spine-cpp/include/spine/AttachmentLoader.h:69](../../spine-cpp/include/spine/AttachmentLoader.h#L69) BoundingBoxAttachment * AttachmentLoader::newBoundingBoxAttachment(Skin & skin, const String & name) // returns nullable pointer: BoundingBoxAttachment *
  ```cpp
  PURE VIRTUAL - concrete implementations in: ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AttachmentLoader.java:48
  48:	public @Null BoundingBoxAttachment newBoundingBoxAttachment (Skin skin, String name);
  49-
  50-	/** @return May be null to not load the attachment. */
  51-	public @Null ClippingAttachment newClippingAttachment (Skin skin, String name);
  52-
  53-	/** @return May be null to not load the attachment. */
  54-	public @Null PathAttachment newPathAttachment (Skin skin, String name);
  55-
  56-	/** @return May be null to not load the attachment. */
  57-	public @Null PointAttachment newPointAttachment (Skin skin, String name);
  ```
- [x] [../../spine-cpp/include/spine/AttachmentLoader.h:72](../../spine-cpp/include/spine/AttachmentLoader.h#L72) PathAttachment * AttachmentLoader::newPathAttachment(Skin & skin, const String & name) // returns nullable pointer: PathAttachment *
  ```cpp
  PURE VIRTUAL - concrete implementations in: ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AttachmentLoader.java:54
  54:	public @Null PathAttachment newPathAttachment (Skin skin, String name);
  55-
  56-	/** @return May be null to not load the attachment. */
  57-	public @Null PointAttachment newPointAttachment (Skin skin, String name);
  58-}
  ```
- [x] [../../spine-cpp/include/spine/AttachmentLoader.h:74](../../spine-cpp/include/spine/AttachmentLoader.h#L74) PointAttachment * AttachmentLoader::newPointAttachment(Skin & skin, const String & name) // returns nullable pointer: PointAttachment *
  ```cpp
  PURE VIRTUAL - concrete implementations in: ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AttachmentLoader.java:57
  57:	public @Null PointAttachment newPointAttachment (Skin skin, String name);
  58-}
  ```
- [x] [../../spine-cpp/include/spine/AttachmentLoader.h:76](../../spine-cpp/include/spine/AttachmentLoader.h#L76) ClippingAttachment * AttachmentLoader::newClippingAttachment(Skin & skin, const String & name) // returns nullable pointer: ClippingAttachment *
  ```cpp
  PURE VIRTUAL - concrete implementations in: ../../spine-cpp/src/spine/AtlasAttachmentLoader.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/AttachmentLoader.java:51
  51:	public @Null ClippingAttachment newClippingAttachment (Skin skin, String name);
  52-
  53-	/** @return May be null to not load the attachment. */
  54-	public @Null PathAttachment newPathAttachment (Skin skin, String name);
  55-
  56-	/** @return May be null to not load the attachment. */
  57-	public @Null PointAttachment newPointAttachment (Skin skin, String name);
  58-}
  ```
- [x] [../../spine-cpp/include/spine/Bone.h:85](../../spine-cpp/include/spine/Bone.h#L85) Bone * Bone::getParent() // returns nullable pointer: Bone *
  ```cpp
  ../../spine-cpp/src/spine/Bone.cpp:54
  54:Bone *Bone::getParent() {
  55-	return _parent;
  56-}
  57-
  58-Array<Bone *> &Bone::getChildren() {
  59-	return _children;
  60-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Bone.java:60
  60:	public @Null Bone getParent () {
  61-		return parent;
  62-	}
  63-
  64-	/** The immediate children of this bone. */
  65-	public Array<Bone> getChildren () {
  66-		return children;
  67-	}
  68-}
  ```
- [x] [../../spine-cpp/include/spine/BoneData.h:76](../../spine-cpp/include/spine/BoneData.h#L76) BoneData * BoneData::getParent() // returns nullable pointer: BoneData *
  ```cpp
  ../../spine-cpp/src/spine/BoneData.cpp:45
  45:BoneData *BoneData::getParent() {
  46-	return _parent;
  47-}
  48-
  49-float BoneData::getLength() {
  50-	return _length;
  51-}
  52-
  53-void BoneData::setLength(float inValue) {
  54-	_length = inValue;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/BoneData.java:66
  66:	public @Null BoneData getParent () {
  67-		return parent;
  68-	}
  69-
  70-	/** The bone's length. */
  71-	public float getLength () {
  72-		return length;
  73-	}
  74-
  75-	public void setLength (float length) {
  ```
- [x] [../../spine-cpp/include/spine/BoundingBoxAttachment.h:47](../../spine-cpp/include/spine/BoundingBoxAttachment.h#L47) Attachment & BoundingBoxAttachment::copy() // returns non-null reference: Attachment &
  ```cpp
  ../../spine-cpp/src/spine/BoundingBoxAttachment.cpp:43
  43:Attachment *BoundingBoxAttachment::copy() {
  44-	BoundingBoxAttachment *copy = new (__FILE__, __LINE__) BoundingBoxAttachment(getName());
  45-	copyTo(copy);
  46-	return copy;
  47-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/BoundingBoxAttachment.java:61
  61:	public BoundingBoxAttachment copy () {
  62-		return new BoundingBoxAttachment(this);
  63-	}
  64-}
  ```
- [x] [../../spine-cpp/include/spine/ClippingAttachment.h:51](../../spine-cpp/include/spine/ClippingAttachment.h#L51) SlotData * ClippingAttachment::getEndSlot() // returns nullable pointer: SlotData *
  ```cpp
  ../../spine-cpp/src/spine/ClippingAttachment.cpp:41
  41:SlotData *ClippingAttachment::getEndSlot() {
  42-	return _endSlot;
  43-}
  44-
  45-void ClippingAttachment::setEndSlot(SlotData *inValue) {
  46-	_endSlot = inValue;
  47-}
  48-
  49-Color &ClippingAttachment::getColor() {
  50-	return _color;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/ClippingAttachment.java:57
  57:	public @Null SlotData getEndSlot () {
  58-		return endSlot;
  59-	}
  60-
  61-	public void setEndSlot (@Null SlotData endSlot) {
  62-		this.endSlot = endSlot;
  63-	}
  64-
  65-	/** The color of the clipping attachment as it was in Spine, or a default color if nonessential data was not exported. Clipping
  66-	 * attachments are not usually rendered at runtime. */
  ```
- [x] [../../spine-cpp/include/spine/ClippingAttachment.h:53](../../spine-cpp/include/spine/ClippingAttachment.h#L53) void ClippingAttachment::setEndSlot(SlotData * inValue) // takes nullable parameter 'inValue': SlotData *
  ```cpp
  ../../spine-cpp/src/spine/ClippingAttachment.cpp:45
  45:void ClippingAttachment::setEndSlot(SlotData *inValue) {
  46-	_endSlot = inValue;
  47-}
  48-
  49-Color &ClippingAttachment::getColor() {
  50-	return _color;
  51-}
  52-
  53-Attachment *ClippingAttachment::copy() {
  54-	ClippingAttachment *copy = new (__FILE__, __LINE__) ClippingAttachment(getName());
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/ClippingAttachment.java:61
  61:	public void setEndSlot (@Null SlotData endSlot) {
  62-		this.endSlot = endSlot;
  63-	}
  64-
  65-	/** The color of the clipping attachment as it was in Spine, or a default color if nonessential data was not exported. Clipping
  66-	 * attachments are not usually rendered at runtime. */
  67-	public Color getColor () {
  68-		return color;
  69-	}
  70-
  ```
- [x] [../../spine-cpp/include/spine/ClippingAttachment.h:57](../../spine-cpp/include/spine/ClippingAttachment.h#L57) Attachment & ClippingAttachment::copy() // returns non-null reference: Attachment &
  ```cpp
  ../../spine-cpp/src/spine/ClippingAttachment.cpp:53
  53:Attachment *ClippingAttachment::copy() {
  54-	ClippingAttachment *copy = new (__FILE__, __LINE__) ClippingAttachment(getName());
  55-	copyTo(copy);
  56-	copy->_endSlot = _endSlot;
  57-	return copy;
  58-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/ClippingAttachment.java:71
  71:	public ClippingAttachment copy () {
  72-		return new ClippingAttachment(this);
  73-	}
  74-}
  ```
- [x] [../../spine-cpp/include/spine/ConstraintData.h:53](../../spine-cpp/include/spine/ConstraintData.h#L53) Constraint & ConstraintData::create(Skeleton & skeleton) // returns non-null reference: Constraint &
  ```cpp
  PURE VIRTUAL - no concrete subclasses found
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/ConstraintData.java:13
  13:	abstract public T create (Skeleton skeleton);
  14-}
  ```
- [x] [../../spine-cpp/include/spine/ConstraintDataGeneric.h:69](../../spine-cpp/include/spine/ConstraintDataGeneric.h#L69) Constraint & ConstraintDataGeneric::create(Skeleton & skeleton) // returns non-null reference: Constraint &
  ```cpp
  PURE VIRTUAL - no concrete subclasses found
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/ConstraintData.java:13
  13:	abstract public T create (Skeleton skeleton);
  14-}
  ```
- [x] [../../spine-cpp/include/spine/DeformTimeline.h:56](../../spine-cpp/include/spine/DeformTimeline.h#L56) VertexAttachment * DeformTimeline::getAttachment() // returns nullable pointer: VertexAttachment *
  ```cpp
  ../../spine-cpp/src/spine/DeformTimeline.cpp:304
  304:VertexAttachment *DeformTimeline::getAttachment() {
  305-	return _attachment;
  306-}
  307-
  308-void DeformTimeline::setAttachment(VertexAttachment *inValue) {
  309-	_attachment = inValue;
  310-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Animation.java:1406
  1406:	/** Changes a slot's {@link SlotPose#getAttachment()}. */
  1407-	static public class AttachmentTimeline extends Timeline implements SlotTimeline {
  1408-		final int slotIndex;
  1409-		final String[] attachmentNames;
  1410-
  1411-		public AttachmentTimeline (int frameCount, int slotIndex) {
  1412-			super(frameCount, Property.attachment.ordinal() + "|" + slotIndex);
  1413-			this.slotIndex = slotIndex;
  1414-			attachmentNames = new String[frameCount];
  1415-		}
  ```
- [x] [../../spine-cpp/include/spine/DeformTimeline.h:58](../../spine-cpp/include/spine/DeformTimeline.h#L58) void DeformTimeline::setAttachment(VertexAttachment * inValue) // takes nullable parameter 'inValue': VertexAttachment *
  ```cpp
  ../../spine-cpp/src/spine/DeformTimeline.cpp:308
  308:void DeformTimeline::setAttachment(VertexAttachment *inValue) {
  309-	_attachment = inValue;
  310-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Animation.java:1446
  1446:				if (blend == setup) setAttachment(skeleton, pose, slot.data.attachmentName);
  1447-			} else if (time < this.frames[0]) {
  1448:				if (blend == setup || blend == first) setAttachment(skeleton, pose, slot.data.attachmentName);
  1449-			} else
  1450:				setAttachment(skeleton, pose, attachmentNames[search(this.frames, time)]);
  1451-		}
  1452-
  1453:		private void setAttachment (Skeleton skeleton, SlotPose pose, @Null String attachmentName) {
  1454:			pose.setAttachment(attachmentName == null ? null : skeleton.getAttachment(slotIndex, attachmentName));
  1455-		}
  ```
- [x] [../../spine-cpp/include/spine/EventTimeline.h:60](../../spine-cpp/include/spine/EventTimeline.h#L60) void EventTimeline::setFrame(size_t frame, Event * event) // takes nullable parameter 'event': Event *
  ```cpp
  ../../spine-cpp/src/spine/EventTimeline.cpp:93
  93:void EventTimeline::setFrame(size_t frame, Event *event) {
  94-	_frames[frame] = event->getTime();
  95-	_events[frame] = event;
  96-}
  97-
  98-size_t EventTimeline::getFrameCount() {
  99-	return _frames.size();
  100-}
  101-
  102-Array<Event *> &EventTimeline::getEvents() {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Animation.java:413
  413:		public void setFrame (int frame, float time, float value) {
  414-			frame <<= 1;
  415-			frames[frame] = time;
  416-			frames[frame + VALUE] = value;
  417-		}
  418-
  419-		/** Returns the interpolated value for the specified time. */
  420-		public float getCurveValue (float time) {
  421-			float[] frames = this.frames;
  422-			int i = frames.length - 2;
  ```
- [x] [../../spine-cpp/include/spine/IkConstraint.h:54](../../spine-cpp/include/spine/IkConstraint.h#L54) IkConstraint * IkConstraint::copy(Skeleton & skeleton) // returns nullable pointer: IkConstraint *
  ```cpp
  ../../spine-cpp/src/spine/IkConstraint.cpp:54
  54:IkConstraint *IkConstraint::copy(Skeleton &skeleton) {
  55-	IkConstraint *copy = new (__FILE__, __LINE__) IkConstraint(_data, skeleton);
  56-	copy->_pose.set(_pose);
  57-	return copy;
  58-}
  59-
  60-void IkConstraint::update(Skeleton &skeleton, Physics physics) {
  61-	IkConstraintPose &p = *_applied;
  62-	if (p._mix == 0) return;
  63-	BonePose &target = *_target->_applied;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/IkConstraint.java:57
  57:	public IkConstraint copy (Skeleton skeleton) {
  58-		var copy = new IkConstraint(data, skeleton);
  59-		copy.pose.set(pose);
  60-		return copy;
  61-	}
  62-
  63-	/** Applies the constraint to the constrained bones. */
  64-	public void update (Skeleton skeleton, Physics physics) {
  65-		IkConstraintPose p = applied;
  66-		if (p.mix == 0) return;
  ```
- [x] [../../spine-cpp/include/spine/IkConstraint.h:66](../../spine-cpp/include/spine/IkConstraint.h#L66) Bone * IkConstraint::getTarget() // returns nullable pointer: Bone *
  ```cpp
  ../../spine-cpp/src/spine/IkConstraint.cpp:94
  94:Bone *IkConstraint::getTarget() {
  95-	return _target;
  96-}
  97-
  98-void IkConstraint::setTarget(Bone *target) {
  99-	_target = target;
  100-}
  101-
  102-bool IkConstraint::isSourceActive() {
  103-	return _target->_active;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/IkConstraint.java:97
  97:	public Bone getTarget () {
  98-		return target;
  99-	}
  100-
  101-	public void setTarget (Bone target) {
  102-		if (target == null) throw new IllegalArgumentException("target cannot be null.");
  103-		this.target = target;
  104-	}
  105-
  106-	/** Applies 1 bone IK. The target is specified in the world coordinate system. */
  ```
- [x] [../../spine-cpp/include/spine/IkConstraint.h:68](../../spine-cpp/include/spine/IkConstraint.h#L68) void IkConstraint::setTarget(Bone * inValue) // takes nullable parameter 'inValue': Bone *
  ```cpp
  ../../spine-cpp/src/spine/IkConstraint.cpp:98
  98:void IkConstraint::setTarget(Bone *target) {
  99-	_target = target;
  100-}
  101-
  102-bool IkConstraint::isSourceActive() {
  103-	return _target->_active;
  104-}
  105-
  106-void IkConstraint::apply(Skeleton &skeleton, BonePose &bone, float targetX, float targetY, bool compress, bool stretch, bool uniform, float mix) {
  107-	bone.modifyLocal(skeleton);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/IkConstraint.java:101
  101:	public void setTarget (Bone target) {
  102-		if (target == null) throw new IllegalArgumentException("target cannot be null.");
  103-		this.target = target;
  104-	}
  105-
  106-	/** Applies 1 bone IK. The target is specified in the world coordinate system. */
  107-	static public void apply (Skeleton skeleton, BonePose bone, float targetX, float targetY, boolean compress, boolean stretch,
  108-		boolean uniform, float mix) {
  109-		if (bone == null) throw new IllegalArgumentException("bone cannot be null.");
  110-		bone.modifyLocal(skeleton);
  ```
- [x] [../../spine-cpp/include/spine/IkConstraintData.h:60](../../spine-cpp/include/spine/IkConstraintData.h#L60) Constraint * IkConstraintData::create(Skeleton & skeleton) // returns nullable pointer: Constraint *
  ```cpp
  ../../spine-cpp/src/spine/IkConstraintData.cpp:62
  62:Constraint *IkConstraintData::create(Skeleton &skeleton) {
  63-	return new (__FILE__, __LINE__) IkConstraint(*this, skeleton);
  64-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/IkConstraintData.java:46
  46:	public IkConstraint create (Skeleton skeleton) {
  47-		return new IkConstraint(this, skeleton);
  48-	}
  49-
  50-	/** The bones that are constrained by this IK constraint. */
  51-	public Array<BoneData> getBones () {
  52-		return bones;
  53-	}
  54-
  55-	/** The bone that is the IK target. */
  ```
- [x] [../../spine-cpp/include/spine/IkConstraintData.h:66](../../spine-cpp/include/spine/IkConstraintData.h#L66) BoneData * IkConstraintData::getTarget() // returns nullable pointer: BoneData *
  ```cpp
  ../../spine-cpp/src/spine/IkConstraintData.cpp:46
  46:BoneData *IkConstraintData::getTarget() {
  47-	return _target;
  48-}
  49-
  50-void IkConstraintData::setTarget(BoneData *inValue) {
  51-	_target = inValue;
  52-}
  53-
  54-bool IkConstraintData::getUniform() {
  55-	return _uniform;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/IkConstraintData.java:56
  56:	public BoneData getTarget () {
  57-		return target;
  58-	}
  59-
  60-	public void setTarget (BoneData target) {
  61-		if (target == null) throw new IllegalArgumentException("target cannot be null.");
  62-		this.target = target;
  63-	}
  64-
  65-	/** When true and {@link IkConstraintPose#getCompress()} or {@link IkConstraintPose#getStretch()} is used, the bone is scaled
  ```
- [x] [../../spine-cpp/include/spine/IkConstraintData.h:68](../../spine-cpp/include/spine/IkConstraintData.h#L68) void IkConstraintData::setTarget(BoneData * inValue) // takes nullable parameter 'inValue': BoneData *
  ```cpp
  ../../spine-cpp/src/spine/IkConstraintData.cpp:50
  50:void IkConstraintData::setTarget(BoneData *inValue) {
  51-	_target = inValue;
  52-}
  53-
  54-bool IkConstraintData::getUniform() {
  55-	return _uniform;
  56-}
  57-
  58-void IkConstraintData::setUniform(bool uniform) {
  59-	_uniform = uniform;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/IkConstraintData.java:60
  60:	public void setTarget (BoneData target) {
  61-		if (target == null) throw new IllegalArgumentException("target cannot be null.");
  62-		this.target = target;
  63-	}
  64-
  65-	/** When true and {@link IkConstraintPose#getCompress()} or {@link IkConstraintPose#getStretch()} is used, the bone is scaled
  66-	 * on both the X and Y axes. */
  67-	public boolean getUniform () {
  68-		return uniform;
  69-	}
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:84](../../spine-cpp/include/spine/MeshAttachment.h#L84) TextureRegion * MeshAttachment::getRegion() // returns nullable pointer: TextureRegion *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:128
  128:Array<float> &MeshAttachment::getRegionUVs() {
  129-	return _regionUVs;
  130-}
  131-
  132-void MeshAttachment::setRegionUVs(Array<float> &inValue) {
  133-	_regionUVs.clearAndAddAll(inValue);
  134-}
  135-
  136-Array<float> &MeshAttachment::getUVs() {
  137-	return _uvs;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:100
  100:	public @Null TextureRegion getRegion () {
  101-		return region;
  102-	}
  103-
  104-	/** Calculates {@link #uvs} using the {@link #regionUVs} and region. Must be called if the region, the region's properties, or
  105-	 * the {@link #regionUVs} are changed. */
  106-	public void updateRegion () {
  107-		float[] regionUVs = this.regionUVs;
  108-		if (this.uvs == null || this.uvs.length != regionUVs.length) this.uvs = new float[regionUVs.length];
  109-		float[] uvs = this.uvs;
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:86](../../spine-cpp/include/spine/MeshAttachment.h#L86) void MeshAttachment::setRegion(TextureRegion * region) // takes nullable parameter 'region': TextureRegion *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:132
  132:void MeshAttachment::setRegionUVs(Array<float> &inValue) {
  133-	_regionUVs.clearAndAddAll(inValue);
  134-}
  135-
  136-Array<float> &MeshAttachment::getUVs() {
  137-	return _uvs;
  138-}
  139-
  140-Array<unsigned short> &MeshAttachment::getTriangles() {
  141-	return _triangles;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:95
  95:	public void setRegion (TextureRegion region) {
  96-		if (region == null) throw new IllegalArgumentException("region cannot be null.");
  97-		this.region = region;
  98-	}
  99-
  100-	public @Null TextureRegion getRegion () {
  101-		return region;
  102-	}
  103-
  104-	/** Calculates {@link #uvs} using the {@link #regionUVs} and region. Must be called if the region, the region's properties, or
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:88](../../spine-cpp/include/spine/MeshAttachment.h#L88) Sequence * MeshAttachment::getSequence() // returns nullable pointer: Sequence *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:164
  164:Sequence *MeshAttachment::getSequence() {
  165-	return _sequence;
  166-}
  167-
  168-void MeshAttachment::setSequence(Sequence *sequence) {
  169-	_sequence = sequence;
  170-}
  171-
  172-MeshAttachment *MeshAttachment::getParentMesh() {
  173-	return _parentMesh;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:258
  258:	public @Null Sequence getSequence () {
  259-		return sequence;
  260-	}
  261-
  262-	public void setSequence (@Null Sequence sequence) {
  263-		this.sequence = sequence;
  264-	}
  265-
  266-	/** The parent mesh if this is a linked mesh, else null. A linked mesh shares the {@link #bones}, {@link #vertices},
  267-	 * {@link #regionUVs}, {@link #triangles}, {@link #hullLength}, {@link #edges}, {@link #width}, and {@link #height} with the
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:90](../../spine-cpp/include/spine/MeshAttachment.h#L90) void MeshAttachment::setSequence(Sequence * sequence) // takes nullable parameter 'sequence': Sequence *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:168
  168:void MeshAttachment::setSequence(Sequence *sequence) {
  169-	_sequence = sequence;
  170-}
  171-
  172-MeshAttachment *MeshAttachment::getParentMesh() {
  173-	return _parentMesh;
  174-}
  175-
  176-void MeshAttachment::setParentMesh(MeshAttachment *inValue) {
  177-	_parentMesh = inValue;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:262
  262:	public void setSequence (@Null Sequence sequence) {
  263-		this.sequence = sequence;
  264-	}
  265-
  266-	/** The parent mesh if this is a linked mesh, else null. A linked mesh shares the {@link #bones}, {@link #vertices},
  267-	 * {@link #regionUVs}, {@link #triangles}, {@link #hullLength}, {@link #edges}, {@link #width}, and {@link #height} with the
  268-	 * parent mesh, but may have a different {@link #name} or {@link #path} (and therefore a different texture). */
  269-	public @Null MeshAttachment getParentMesh () {
  270-		return parentMesh;
  271-	}
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:92](../../spine-cpp/include/spine/MeshAttachment.h#L92) MeshAttachment * MeshAttachment::getParentMesh() // returns nullable pointer: MeshAttachment *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:172
  172:MeshAttachment *MeshAttachment::getParentMesh() {
  173-	return _parentMesh;
  174-}
  175-
  176-void MeshAttachment::setParentMesh(MeshAttachment *inValue) {
  177-	_parentMesh = inValue;
  178-	if (inValue != NULL) {
  179-		_bones.clearAndAddAll(inValue->_bones);
  180-		_vertices.clearAndAddAll(inValue->_vertices);
  181-		_worldVerticesLength = inValue->_worldVerticesLength;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:269
  269:	public @Null MeshAttachment getParentMesh () {
  270-		return parentMesh;
  271-	}
  272-
  273-	public void setParentMesh (@Null MeshAttachment parentMesh) {
  274-		this.parentMesh = parentMesh;
  275-		if (parentMesh != null) {
  276-			bones = parentMesh.bones;
  277-			vertices = parentMesh.vertices;
  278-			regionUVs = parentMesh.regionUVs;
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:94](../../spine-cpp/include/spine/MeshAttachment.h#L94) void MeshAttachment::setParentMesh(MeshAttachment * inValue) // takes nullable parameter 'inValue': MeshAttachment *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:176
  176:void MeshAttachment::setParentMesh(MeshAttachment *inValue) {
  177-	_parentMesh = inValue;
  178-	if (inValue != NULL) {
  179-		_bones.clearAndAddAll(inValue->_bones);
  180-		_vertices.clearAndAddAll(inValue->_vertices);
  181-		_worldVerticesLength = inValue->_worldVerticesLength;
  182-		_regionUVs.clearAndAddAll(inValue->_regionUVs);
  183-		_triangles.clearAndAddAll(inValue->_triangles);
  184-		_hullLength = inValue->_hullLength;
  185-		_edges.clearAndAddAll(inValue->_edges);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:273
  273:	public void setParentMesh (@Null MeshAttachment parentMesh) {
  274-		this.parentMesh = parentMesh;
  275-		if (parentMesh != null) {
  276-			bones = parentMesh.bones;
  277-			vertices = parentMesh.vertices;
  278-			regionUVs = parentMesh.regionUVs;
  279-			triangles = parentMesh.triangles;
  280-			hullLength = parentMesh.hullLength;
  281-			worldVerticesLength = parentMesh.worldVerticesLength;
  282-			edges = parentMesh.edges;
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:109](../../spine-cpp/include/spine/MeshAttachment.h#L109) Attachment * MeshAttachment::copy() // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:219
  219:Attachment *MeshAttachment::copy() {
  220-	if (_parentMesh) return newLinkedMesh();
  221-
  222-	MeshAttachment *copy = new (__FILE__, __LINE__) MeshAttachment(getName());
  223-	copy->setRegion(_region);
  224-	copy->setSequence(_sequence != NULL ? _sequence->copy() : NULL);
  225-	copy->_path = _path;
  226-	copy->_color.set(_color);
  227-
  228-	copyTo(copy);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:300
  300:	public MeshAttachment copy () {
  301-		return parentMesh != null ? newLinkedMesh() : new MeshAttachment(this);
  302-	}
  303-}
  ```
- [x] [../../spine-cpp/include/spine/MeshAttachment.h:111](../../spine-cpp/include/spine/MeshAttachment.h#L111) MeshAttachment * MeshAttachment::newLinkedMesh() // returns nullable pointer: MeshAttachment *
  ```cpp
  ../../spine-cpp/src/spine/MeshAttachment.cpp:241
  241:MeshAttachment *MeshAttachment::newLinkedMesh() {
  242-	MeshAttachment *copy = new (__FILE__, __LINE__) MeshAttachment(getName());
  243-	copy->setRegion(_region);
  244-	copy->_path = _path;
  245-	copy->_color.set(_color);
  246-	copy->_timelineAttachment = this->_timelineAttachment;
  247-	copy->setParentMesh(_parentMesh ? _parentMesh : this);
  248-	if (copy->_region) copy->updateRegion();
  249-	return copy;
  250-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/MeshAttachment.java:64
  64:	/** Copy constructor. Use {@link #newLinkedMesh()} if the other mesh is a linked mesh. */
  65-	protected MeshAttachment (MeshAttachment other) {
  66-		super(other);
  67-
  68-		if (parentMesh != null) throw new IllegalArgumentException("Use newLinkedMesh to copy a linked mesh.");
  69-
  70-		region = other.region;
  71-		path = other.path;
  72-		color.set(other.color);
  73-
  ```
- [x] [../../spine-cpp/include/spine/PathAttachment.h:62](../../spine-cpp/include/spine/PathAttachment.h#L62) Attachment * PathAttachment::copy() // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/PathAttachment.cpp:67
  67:Attachment *PathAttachment::copy() {
  68-	PathAttachment *copy = new (__FILE__, __LINE__) PathAttachment(getName());
  69-	copyTo(copy);
  70-	copy->_lengths.clearAndAddAll(_lengths);
  71-	copy->_closed = _closed;
  72-	copy->_constantSpeed = _constantSpeed;
  73-	return copy;
  74-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/PathAttachment.java:98
  98:	public PathAttachment copy () {
  99-		return new PathAttachment(this);
  100-	}
  101-}
  ```
- [x] [../../spine-cpp/include/spine/PathConstraint.h:67](../../spine-cpp/include/spine/PathConstraint.h#L67) PathConstraint * PathConstraint::copy(Skeleton & skeleton) // returns nullable pointer: PathConstraint *
  ```cpp
  ../../spine-cpp/src/spine/PathConstraint.cpp:67
  67:PathConstraint *PathConstraint::copy(Skeleton &skeleton) {
  68-	PathConstraint *copy = new (__FILE__, __LINE__) PathConstraint(_data, skeleton);
  69-	copy->_pose.set(_pose);
  70-	return copy;
  71-}
  72-
  73-void PathConstraint::update(Skeleton &skeleton, Physics physics) {
  74-	Attachment *baseAttachment = _slot->_applied->_attachment;
  75-	if (baseAttachment == NULL || !baseAttachment->getRTTI().instanceOf(PathAttachment::rtti)) {
  76-		return;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PathConstraint.java:72
  72:	public PathConstraint copy (Skeleton skeleton) {
  73-		var copy = new PathConstraint(data, skeleton);
  74-		copy.pose.set(pose);
  75-		return copy;
  76-	}
  77-
  78-	/** Applies the constraint to the constrained bones. */
  79-	public void update (Skeleton skeleton, Physics physics) {
  80-		if (!(slot.applied.attachment instanceof PathAttachment pathAttachment)) return;
  81-
  ```
- [x] [../../spine-cpp/include/spine/PathConstraint.h:80](../../spine-cpp/include/spine/PathConstraint.h#L80) Slot * PathConstraint::getSlot() // returns nullable pointer: Slot *
  ```cpp
  ../../spine-cpp/src/spine/PathConstraint.cpp:247
  247:Slot *PathConstraint::getSlot() {
  248-	return _slot;
  249-}
  250-
  251-void PathConstraint::setSlot(Slot *slot) {
  252-	_slot = slot;
  253-}
  254-
  255-Array<float> &PathConstraint::computeWorldPositions(Skeleton &skeleton, PathAttachment &path, int spacesCount, bool tangents) {
  256-	float position = _applied->_position;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PathConstraint.java:517
  517:	public Slot getSlot () {
  518-		return slot;
  519-	}
  520-
  521-	public void setSlot (Slot slot) {
  522-		if (slot == null) throw new IllegalArgumentException("slot cannot be null.");
  523-		this.slot = slot;
  524-	}
  525-}
  ```
- [x] [../../spine-cpp/include/spine/PathConstraint.h:82](../../spine-cpp/include/spine/PathConstraint.h#L82) void PathConstraint::setSlot(Slot * slot) // takes nullable parameter 'slot': Slot *
  ```cpp
  ../../spine-cpp/src/spine/PathConstraint.cpp:251
  251:void PathConstraint::setSlot(Slot *slot) {
  252-	_slot = slot;
  253-}
  254-
  255-Array<float> &PathConstraint::computeWorldPositions(Skeleton &skeleton, PathAttachment &path, int spacesCount, bool tangents) {
  256-	float position = _applied->_position;
  257-	float *spaces = _spaces.buffer();
  258-	_positions.setSize(spacesCount * 3 + 2, 0);
  259-	Array<float> &out = _positions;
  260-	Array<float> &world = _world;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PathConstraint.java:521
  521:	public void setSlot (Slot slot) {
  522-		if (slot == null) throw new IllegalArgumentException("slot cannot be null.");
  523-		this.slot = slot;
  524-	}
  525-}
  ```
- [x] [../../spine-cpp/include/spine/PathConstraintData.h:70](../../spine-cpp/include/spine/PathConstraintData.h#L70) Constraint * PathConstraintData::create(Skeleton & skeleton) // returns nullable pointer: Constraint *
  ```cpp
  ../../spine-cpp/src/spine/PathConstraintData.cpp:90
  90:Constraint *PathConstraintData::create(Skeleton &skeleton) {
  91-	return new (__FILE__, __LINE__) PathConstraint(*this, skeleton);
  92-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PathConstraintData.java:49
  49:	public PathConstraint create (Skeleton skeleton) {
  50-		return new PathConstraint(this, skeleton);
  51-	}
  52-
  53-	/** The bones that will be modified by this path constraint. */
  54-	public Array<BoneData> getBones () {
  55-		return bones;
  56-	}
  57-
  58-	/** The slot whose path attachment will be used to constrained the bones. */
  ```
- [x] [../../spine-cpp/include/spine/PathConstraintData.h:77](../../spine-cpp/include/spine/PathConstraintData.h#L77) SlotData * PathConstraintData::getSlot() // returns nullable pointer: SlotData *
  ```cpp
  ../../spine-cpp/src/spine/PathConstraintData.cpp:50
  50:SlotData *PathConstraintData::getSlot() {
  51-	return _slot;
  52-}
  53-
  54-void PathConstraintData::setSlot(SlotData *slot) {
  55-	_slot = slot;
  56-}
  57-
  58-PositionMode PathConstraintData::getPositionMode() {
  59-	return _positionMode;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PathConstraintData.java:59
  59:	public SlotData getSlot () {
  60-		return slot;
  61-	}
  62-
  63-	public void setSlot (SlotData slot) {
  64-		if (slot == null) throw new IllegalArgumentException("slot cannot be null.");
  65-		this.slot = slot;
  66-	}
  67-
  68-	/** The mode for positioning the first bone on the path. */
  ```
- [x] [../../spine-cpp/include/spine/PathConstraintData.h:79](../../spine-cpp/include/spine/PathConstraintData.h#L79) void PathConstraintData::setSlot(SlotData * slot) // takes nullable parameter 'slot': SlotData *
  ```cpp
  ../../spine-cpp/src/spine/PathConstraintData.cpp:54
  54:void PathConstraintData::setSlot(SlotData *slot) {
  55-	_slot = slot;
  56-}
  57-
  58-PositionMode PathConstraintData::getPositionMode() {
  59-	return _positionMode;
  60-}
  61-
  62-void PathConstraintData::setPositionMode(PositionMode positionMode) {
  63-	_positionMode = positionMode;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PathConstraintData.java:63
  63:	public void setSlot (SlotData slot) {
  64-		if (slot == null) throw new IllegalArgumentException("slot cannot be null.");
  65-		this.slot = slot;
  66-	}
  67-
  68-	/** The mode for positioning the first bone on the path. */
  69-	public PositionMode getPositionMode () {
  70-		return positionMode;
  71-	}
  72-
  ```
- [x] [../../spine-cpp/include/spine/PhysicsConstraint.h:67](../../spine-cpp/include/spine/PhysicsConstraint.h#L67) PhysicsConstraint * PhysicsConstraint::copy(Skeleton & skeleton) // returns nullable pointer: PhysicsConstraint *
  ```cpp
  ../../spine-cpp/src/spine/PhysicsConstraint.cpp:52
  52:PhysicsConstraint *PhysicsConstraint::copy(Skeleton &skeleton) {
  53-	PhysicsConstraint *copy = new (__FILE__, __LINE__) PhysicsConstraint(_data, skeleton);
  54-	copy->_pose.set(_pose);
  55-	return copy;
  56-}
  57-
  58-void PhysicsConstraint::reset(Skeleton &skeleton) {
  59-	_remaining = 0;
  60-	_lastTime = skeleton.getTime();
  61-	_reset = true;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PhysicsConstraint.java:55
  55:	public PhysicsConstraint copy (Skeleton skeleton) {
  56-		var copy = new PhysicsConstraint(data, skeleton);
  57-		copy.pose.set(pose);
  58-		return copy;
  59-	}
  60-
  61-	public void reset (Skeleton skeleton) {
  62-		remaining = 0;
  63-		lastTime = skeleton.time;
  64-		reset = true;
  ```
- [x] [../../spine-cpp/include/spine/PhysicsConstraintData.h:54](../../spine-cpp/include/spine/PhysicsConstraintData.h#L54) Constraint * PhysicsConstraintData::create(Skeleton & skeleton) // returns nullable pointer: Constraint *
  ```cpp
  ../../spine-cpp/src/spine/PhysicsConstraintData.cpp:165
  165:Constraint *PhysicsConstraintData::create(Skeleton &skeleton) {
  166-	return new (__FILE__, __LINE__) PhysicsConstraint(*this, skeleton);
  167-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PhysicsConstraintData.java:44
  44:	public PhysicsConstraint create (Skeleton skeleton) {
  45-		return new PhysicsConstraint(this, skeleton);
  46-	}
  47-
  48-	/** The bone constrained by this physics constraint. */
  49-	public BoneData getBone () {
  50-		return bone;
  51-	}
  52-
  53-	public void setBone (BoneData bone) {
  ```
- [x] [../../spine-cpp/include/spine/PhysicsConstraintData.h:57](../../spine-cpp/include/spine/PhysicsConstraintData.h#L57) BoneData * PhysicsConstraintData::getBone() // returns nullable pointer: BoneData *
  ```cpp
  ../../spine-cpp/src/spine/PhysicsConstraintData.cpp:45
  45:BoneData *PhysicsConstraintData::getBone() {
  46-	return _bone;
  47-}
  48-
  49-void PhysicsConstraintData::setBone(BoneData *bone) {
  50-	_bone = bone;
  51-}
  52-
  53-float PhysicsConstraintData::getStep() {
  54-	return _step;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PhysicsConstraintData.java:49
  49:	public BoneData getBone () {
  50-		return bone;
  51-	}
  52-
  53-	public void setBone (BoneData bone) {
  54-		this.bone = bone;
  55-	}
  56-
  57-	public float getStep () {
  58-		return step;
  ```
- [x] [../../spine-cpp/include/spine/PhysicsConstraintData.h:58](../../spine-cpp/include/spine/PhysicsConstraintData.h#L58) void PhysicsConstraintData::setBone(BoneData * bone) // takes nullable parameter 'bone': BoneData *
  ```cpp
  ../../spine-cpp/src/spine/PhysicsConstraintData.cpp:49
  49:void PhysicsConstraintData::setBone(BoneData *bone) {
  50-	_bone = bone;
  51-}
  52-
  53-float PhysicsConstraintData::getStep() {
  54-	return _step;
  55-}
  56-
  57-void PhysicsConstraintData::setStep(float step) {
  58-	_step = step;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/PhysicsConstraintData.java:53
  53:	public void setBone (BoneData bone) {
  54-		this.bone = bone;
  55-	}
  56-
  57-	public float getStep () {
  58-		return step;
  59-	}
  60-
  61-	public void setStep (float step) {
  62-		this.step = step;
  ```
- [x] [../../spine-cpp/include/spine/PointAttachment.h:74](../../spine-cpp/include/spine/PointAttachment.h#L74) Attachment * PointAttachment::copy() // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/PointAttachment.cpp:83
  83:Attachment *PointAttachment::copy() {
  84-	PointAttachment *copy = new (__FILE__, __LINE__) PointAttachment(getName());
  85-	copy->_x = _x;
  86-	copy->_y = _y;
  87-	copy->_rotation = _rotation;
  88-	copy->_color.set(_color);
  89-	return copy;
  90-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/PointAttachment.java:106
  106:	public PointAttachment copy () {
  107-		return new PointAttachment(this);
  108-	}
  109-}
  ```
- [x] [../../spine-cpp/include/spine/RegionAttachment.h:105](../../spine-cpp/include/spine/RegionAttachment.h#L105) TextureRegion * RegionAttachment::getRegion() // returns nullable pointer: TextureRegion *
  ```cpp
  ../../spine-cpp/src/spine/RegionAttachment.cpp:241
  241:TextureRegion *RegionAttachment::getRegion() {
  242-	return _region;
  243-}
  244-
  245-void RegionAttachment::setRegion(TextureRegion *region) {
  246-	_region = region;
  247-}
  248-
  249-Sequence *RegionAttachment::getSequence() {
  250-	return _sequence;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/RegionAttachment.java:163
  163:	public @Null TextureRegion getRegion () {
  164-		return region;
  165-	}
  166-
  167-	/** Transforms the attachment's four vertices to world coordinates. If the attachment has a {@link #sequence}, the region may
  168-	 * be changed.
  169-	 * <p>
  170-	 * See <a href="https://esotericsoftware.com/spine-runtime-skeletons#World-transforms">World transforms</a> in the Spine
  171-	 * Runtimes Guide.
  172-	 * @param worldVertices The output world vertices. Must have a length >= <code>offset</code> + 8.
  ```
- [x] [../../spine-cpp/include/spine/RegionAttachment.h:107](../../spine-cpp/include/spine/RegionAttachment.h#L107) void RegionAttachment::setRegion(TextureRegion * region) // takes nullable parameter 'region': TextureRegion *
  ```cpp
  ../../spine-cpp/src/spine/RegionAttachment.cpp:245
  245:void RegionAttachment::setRegion(TextureRegion *region) {
  246-	_region = region;
  247-}
  248-
  249-Sequence *RegionAttachment::getSequence() {
  250-	return _sequence;
  251-}
  252-
  253-void RegionAttachment::setSequence(Sequence *sequence) {
  254-	_sequence = sequence;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/RegionAttachment.java:158
  158:	public void setRegion (TextureRegion region) {
  159-		if (region == null) throw new IllegalArgumentException("region cannot be null.");
  160-		this.region = region;
  161-	}
  162-
  163-	public @Null TextureRegion getRegion () {
  164-		return region;
  165-	}
  166-
  167-	/** Transforms the attachment's four vertices to world coordinates. If the attachment has a {@link #sequence}, the region may
  ```
- [x] [../../spine-cpp/include/spine/RegionAttachment.h:109](../../spine-cpp/include/spine/RegionAttachment.h#L109) Sequence * RegionAttachment::getSequence() // returns nullable pointer: Sequence *
  ```cpp
  ../../spine-cpp/src/spine/RegionAttachment.cpp:249
  249:Sequence *RegionAttachment::getSequence() {
  250-	return _sequence;
  251-}
  252-
  253-void RegionAttachment::setSequence(Sequence *sequence) {
  254-	_sequence = sequence;
  255-}
  256-
  257-Array<float> &RegionAttachment::getOffset() {
  258-	return _offset;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/RegionAttachment.java:294
  294:	public @Null Sequence getSequence () {
  295-		return sequence;
  296-	}
  297-
  298-	public void setSequence (@Null Sequence sequence) {
  299-		this.sequence = sequence;
  300-	}
  301-
  302-	public RegionAttachment copy () {
  303-		return new RegionAttachment(this);
  ```
- [x] [../../spine-cpp/include/spine/RegionAttachment.h:111](../../spine-cpp/include/spine/RegionAttachment.h#L111) void RegionAttachment::setSequence(Sequence * sequence) // takes nullable parameter 'sequence': Sequence *
  ```cpp
  ../../spine-cpp/src/spine/RegionAttachment.cpp:253
  253:void RegionAttachment::setSequence(Sequence *sequence) {
  254-	_sequence = sequence;
  255-}
  256-
  257-Array<float> &RegionAttachment::getOffset() {
  258-	return _offset;
  259-}
  260-
  261-Array<float> &RegionAttachment::getUVs() {
  262-	return _uvs;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/RegionAttachment.java:298
  298:	public void setSequence (@Null Sequence sequence) {
  299-		this.sequence = sequence;
  300-	}
  301-
  302-	public RegionAttachment copy () {
  303-		return new RegionAttachment(this);
  304-	}
  305-}
  ```
- [x] [../../spine-cpp/include/spine/RegionAttachment.h:117](../../spine-cpp/include/spine/RegionAttachment.h#L117) Attachment * RegionAttachment::copy() // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/RegionAttachment.cpp:269
  269:Attachment *RegionAttachment::copy() {
  270-	RegionAttachment *copy = new (__FILE__, __LINE__) RegionAttachment(getName());
  271-	copy->_region = _region;
  272-	copy->_path = _path;
  273-	copy->_x = _x;
  274-	copy->_y = _y;
  275-	copy->_scaleX = _scaleX;
  276-	copy->_scaleY = _scaleY;
  277-	copy->_rotation = _rotation;
  278-	copy->_width = _width;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/RegionAttachment.java:302
  302:	public RegionAttachment copy () {
  303-		return new RegionAttachment(this);
  304-	}
  305-}
  ```
- [x] [../../spine-cpp/include/spine/Sequence.h:54](../../spine-cpp/include/spine/Sequence.h#L54) Sequence * Sequence::copy() // returns nullable pointer: Sequence *
  ```cpp
  ../../spine-cpp/src/spine/Sequence.cpp:48
  48:Sequence *Sequence::copy() {
  49-	Sequence *copy = new (__FILE__, __LINE__) Sequence((int) _regions.size());
  50-	for (size_t i = 0; i < _regions.size(); i++) {
  51-		copy->_regions[i] = _regions[i];
  52-	}
  53-	copy->_start = _start;
  54-	copy->_digits = _digits;
  55-	copy->_setupIndex = _setupIndex;
  56-	return copy;
  57-}
  ```
  ```java
  NOT FOUND - searched for class "Sequence" (from C++ "Sequence") and method "copy" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/Sequence.h:56](../../spine-cpp/include/spine/Sequence.h#L56) void Sequence::apply(SlotPose * slot, Attachment * attachment) // takes nullable parameter 'slot': SlotPose *; takes nullable parameter 'attachment': Attachment *
  ```cpp
  ../../spine-cpp/src/spine/Sequence.cpp:59
  59:void Sequence::apply(SlotPose *slot, Attachment *attachment) {
  60-	int index = slot->getSequenceIndex();
  61-	if (index == -1) index = _setupIndex;
  62-	if (index >= (int) _regions.size()) index = (int) _regions.size() - 1;
  63-	TextureRegion *region = _regions[index];
  64-
  65-	if (attachment->getRTTI().isExactly(RegionAttachment::rtti)) {
  66-		RegionAttachment *regionAttachment = static_cast<RegionAttachment *>(attachment);
  67-		if (regionAttachment->getRegion() != region) {
  68-			regionAttachment->setRegion(region);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/Sequence.java:59
  59:	public void apply (SlotPose slot, HasTextureRegion attachment) {
  60-		int index = slot.getSequenceIndex();
  61-		if (index == -1) index = setupIndex;
  62-		if (index >= regions.length) index = regions.length - 1;
  63-		TextureRegion region = regions[index];
  64-		if (attachment.getRegion() != region) {
  65-			attachment.setRegion(region);
  66-			attachment.updateRegion();
  67-		}
  68-	}
  ```
- [x] [../../spine-cpp/include/spine/SequenceTimeline.h:62](../../spine-cpp/include/spine/SequenceTimeline.h#L62) Attachment * SequenceTimeline::getAttachment() // returns nullable pointer: Attachment *
  ```cpp
  NOT FOUND - searched for pattern "SequenceTimeline::getAttachment" in ../../spine-cpp/src/spine/SequenceTimeline.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Animation.java:1406
  1406:	/** Changes a slot's {@link SlotPose#getAttachment()}. */
  1407-	static public class AttachmentTimeline extends Timeline implements SlotTimeline {
  1408-		final int slotIndex;
  1409-		final String[] attachmentNames;
  1410-
  1411-		public AttachmentTimeline (int frameCount, int slotIndex) {
  1412-			super(frameCount, Property.attachment.ordinal() + "|" + slotIndex);
  1413-			this.slotIndex = slotIndex;
  1414-			attachmentNames = new String[frameCount];
  1415-		}
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:166](../../spine-cpp/include/spine/Skeleton.h#L166) void Skeleton::sortBone(Bone * bone) // takes nullable parameter 'bone': Bone *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:194
  194:void Skeleton::sortBone(Bone *bone) {
  195-	if (bone->_sorted || !bone->_active) return;
  196-	Bone *parent = bone->_parent;
  197-	if (parent != NULL) sortBone(parent);
  198-	bone->_sorted = true;
  199-	_updateCache.add((Update *) bone);
  200-}
  201-
  202-void Skeleton::sortReset(Array<Bone *> &bones) {
  203-	Bone **items = bones.buffer();
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:193
  193:			sortBone(bones[i]);
  194-
  195-		Object[] updateCache = this.updateCache.items;
  196-		n = this.updateCache.size;
  197-		for (int i = 0; i < n; i++)
  198-			if (updateCache[i] instanceof Bone bone) updateCache[i] = bone.applied;
  199-	}
  200-
  201-	void constrained (Posed object) {
  202-		if (object.pose == object.applied) {
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:176](../../spine-cpp/include/spine/Skeleton.h#L176) void Skeleton::updateWorldTransform(Physics physics, BonePose * parent) // takes nullable parameter 'parent': BonePose *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:213
  213:void Skeleton::updateWorldTransform(Physics physics) {
  214-	_update++;
  215-
  216-	Posed **resetCache = _resetCache.buffer();
  217-	for (size_t i = 0, n = _resetCache.size(); i < n; i++) {
  218-		resetCache[i]->resetConstrained();
  219-	}
  220-
  221-	Update **updateCache = _updateCache.buffer();
  222-	for (size_t i = 0, n = _updateCache.size(); i < n; i++) {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:231
  231:	public void updateWorldTransform (Physics physics) {
  232-		update++;
  233-
  234-		Posed[] resetCache = this.resetCache.items;
  235-		for (int i = 0, n = this.resetCache.size; i < n; i++)
  236-			resetCache[i].reset();
  237-
  238-		Object[] updateCache = this.updateCache.items;
  239-		for (int i = 0, n = this.updateCache.size; i < n; i++)
  240-			((Update)updateCache[i]).update(this, physics);
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:186](../../spine-cpp/include/spine/Skeleton.h#L186) SkeletonData * Skeleton::getData() // returns nullable pointer: SkeletonData *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:293
  293:SkeletonData *Skeleton::getData() {
  294-	return &_data;
  295-}
  296-
  297-Array<Bone *> &Skeleton::getBones() {
  298-	return _bones;
  299-}
  300-
  301-Array<Update *> &Skeleton::getUpdateCache() {
  302-	return _updateCache;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:309
  309:	public SkeletonData getData () {
  310-		return data;
  311-	}
  312-
  313-	/** The skeleton's bones, sorted parent first. The root bone is always the first bone. */
  314-	public Array<Bone> getBones () {
  315-		return bones;
  316-	}
  317-
  318-	/** The list of bones and constraints, sorted in the order they should be updated, as computed by {@link #updateCache()}. */
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:192](../../spine-cpp/include/spine/Skeleton.h#L192) Bone * Skeleton::getRootBone() // returns nullable pointer: Bone *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:305
  305:Bone *Skeleton::getRootBone() {
  306-	return _bones.size() == 0 ? NULL : _bones[0];
  307-}
  308-
  309-Bone *Skeleton::findBone(const String &boneName) {
  310-	if (boneName.isEmpty()) return NULL;
  311-	Bone **bones = _bones.buffer();
  312-	for (size_t i = 0, n = _bones.size(); i < n; i++) {
  313-		if (bones[i]->_data.getName() == boneName) return bones[i];
  314-	}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:258
  258:		BonePose rootBone = getRootBone().applied;
  259-		float pa = parent.a, pb = parent.b, pc = parent.c, pd = parent.d;
  260-		rootBone.worldX = pa * x + pb * y + parent.worldX;
  261-		rootBone.worldY = pc * x + pd * y + parent.worldY;
  262-
  263-		float rx = (rootBone.rotation + rootBone.shearX) * degRad;
  264-		float ry = (rootBone.rotation + 90 + rootBone.shearY) * degRad;
  265-		float la = cos(rx) * rootBone.scaleX;
  266-		float lb = cos(ry) * rootBone.scaleY;
  267-		float lc = sin(rx) * rootBone.scaleX;
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:195](../../spine-cpp/include/spine/Skeleton.h#L195) Bone * Skeleton::findBone(const String & boneName) // returns nullable pointer: Bone *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:309
  309:Bone *Skeleton::findBone(const String &boneName) {
  310-	if (boneName.isEmpty()) return NULL;
  311-	Bone **bones = _bones.buffer();
  312-	for (size_t i = 0, n = _bones.size(); i < n; i++) {
  313-		if (bones[i]->_data.getName() == boneName) return bones[i];
  314-	}
  315-	return NULL;
  316-}
  317-
  318-Array<Slot *> &Skeleton::getSlots() {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:330
  330:	public @Null Bone findBone (String boneName) {
  331-		if (boneName == null) throw new IllegalArgumentException("boneName cannot be null.");
  332-		Bone[] bones = this.bones.items;
  333-		for (int i = 0, n = this.bones.size; i < n; i++)
  334-			if (bones[i].data.name.equals(boneName)) return bones[i];
  335-		return null;
  336-	}
  337-
  338-	/** The skeleton's slots. */
  339-	public Array<Slot> getSlots () {
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:200](../../spine-cpp/include/spine/Skeleton.h#L200) Slot * Skeleton::findSlot(const String & slotName) // returns nullable pointer: Slot *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:322
  322:Slot *Skeleton::findSlot(const String &slotName) {
  323-	if (slotName.isEmpty()) return NULL;
  324-	Slot **slots = _slots.buffer();
  325-	for (size_t i = 0, n = _slots.size(); i < n; i++) {
  326-		if (slots[i]->_data.getName() == slotName) return slots[i];
  327-	}
  328-	return NULL;
  329-}
  330-
  331-Array<Slot *> &Skeleton::getDrawOrder() {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:345
  345:	public @Null Slot findSlot (String slotName) {
  346-		if (slotName == null) throw new IllegalArgumentException("slotName cannot be null.");
  347-		Slot[] slots = this.slots.items;
  348-		for (int i = 0, n = this.slots.size; i < n; i++)
  349-			if (slots[i].data.name.equals(slotName)) return slots[i];
  350-		return null;
  351-	}
  352-
  353-	/** The skeleton's slots in the order they should be drawn. The returned array may be modified to change the draw order. */
  354-	public Array<Slot> getDrawOrder () {
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:204](../../spine-cpp/include/spine/Skeleton.h#L204) Skin * Skeleton::getSkin() // returns nullable pointer: Skin *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:335
  335:Skin *Skeleton::getSkin() {
  336-	return _skin;
  337-}
  338-
  339-void Skeleton::setSkin(const String &skinName) {
  340-	Skin *skin = skinName.isEmpty() ? NULL : _data.findSkin(skinName);
  341-	if (skin == NULL) return;
  342-	setSkin(skin);
  343-}
  344-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:151
  151:	/** Caches information about bones and constraints. Must be called if the {@link #getSkin()} is modified or if bones,
  152-	 * constraints, or weighted path attachments are added or removed. */
  153-	public void updateCache () {
  154-		updateCache.clear();
  155-		resetCache.clear();
  156-
  157-		Slot[] slots = this.slots.items;
  158-		for (int i = 0, n = this.slots.size; i < n; i++)
  159-			slots[i].pose();
  160-
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:216](../../spine-cpp/include/spine/Skeleton.h#L216) void Skeleton::setSkin(Skin * newSkin) // takes nullable parameter 'newSkin': Skin *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:339
  339:void Skeleton::setSkin(const String &skinName) {
  340-	Skin *skin = skinName.isEmpty() ? NULL : _data.findSkin(skinName);
  341-	if (skin == NULL) return;
  342-	setSkin(skin);
  343-}
  344-
  345:void Skeleton::setSkin(Skin *newSkin) {
  346-	if (_skin == newSkin) return;
  347-	if (newSkin != NULL) {
  348-		if (_skin != NULL) {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:370
  370:	 * See {@link #setSkin(Skin)}. */
  371:	public void setSkin (String skinName) {
  372-		Skin skin = data.findSkin(skinName);
  373-		if (skin == null) throw new IllegalArgumentException("Skin not found: " + skinName);
  374:		setSkin(skin);
  375-	}
  376-
  377-	/** Sets the skin used to look up attachments before looking in the {@link SkeletonData#getDefaultSkin() default skin}. If the
  378-	 * skin is changed, {@link #updateCache()} is called.
  379-	 * <p>
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:219](../../spine-cpp/include/spine/Skeleton.h#L219) Attachment * Skeleton::getAttachment(const String & slotName, const String & attachmentName) // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:368
  368:Attachment *Skeleton::getAttachment(const String &slotName, const String &attachmentName) {
  369-	SlotData *slot = _data.findSlot(slotName);
  370-	if (slot == NULL) return NULL;
  371-	return getAttachment(slot->getIndex(), attachmentName);
  372-}
  373-
  374:Attachment *Skeleton::getAttachment(int slotIndex, const String &attachmentName) {
  375-	if (attachmentName.isEmpty()) return NULL;
  376-	if (_skin != NULL) {
  377-		Attachment *attachment = _skin->getAttachment(slotIndex, attachmentName);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:397
  397:						Attachment attachment = newSkin.getAttachment(i, name);
  398-						if (attachment != null) slot.pose.setAttachment(attachment);
  399-					}
  400-				}
  401-			}
  402-		}
  403-		skin = newSkin;
  404-		updateCache();
  405-	}
  406-
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:222](../../spine-cpp/include/spine/Skeleton.h#L222) Attachment * Skeleton::getAttachment(int slotIndex, const String & attachmentName) // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:368
  368:Attachment *Skeleton::getAttachment(const String &slotName, const String &attachmentName) {
  369-	SlotData *slot = _data.findSlot(slotName);
  370-	if (slot == NULL) return NULL;
  371-	return getAttachment(slot->getIndex(), attachmentName);
  372-}
  373-
  374:Attachment *Skeleton::getAttachment(int slotIndex, const String &attachmentName) {
  375-	if (attachmentName.isEmpty()) return NULL;
  376-	if (_skin != NULL) {
  377-		Attachment *attachment = _skin->getAttachment(slotIndex, attachmentName);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:397
  397:						Attachment attachment = newSkin.getAttachment(i, name);
  398-						if (attachment != null) slot.pose.setAttachment(attachment);
  399-					}
  400-				}
  401-			}
  402-		}
  403-		skin = newSkin;
  404-		updateCache();
  405-	}
  406-
  ```
- [x] [../../spine-cpp/include/spine/Skeleton.h:253](../../spine-cpp/include/spine/Skeleton.h#L253) void Skeleton::getBounds(float & outX, float & outY, float & outWidth, float & outHeight, Array<float> & outVertexBuffer, SkeletonClipping * clipper) // takes nullable parameter 'clipper': SkeletonClipping *
  ```cpp
  ../../spine-cpp/src/spine/Skeleton.cpp:404
  404:void Skeleton::getBounds(float &outX, float &outY, float &outWidth, float &outHeight, Array<float> &outVertexBuffer) {
  405-	getBounds(outX, outY, outWidth, outHeight, outVertexBuffer, NULL);
  406-}
  407-
  408:void Skeleton::getBounds(float &outX, float &outY, float &outWidth, float &outHeight, Array<float> &outVertexBuffer, SkeletonClipping *clipper) {
  409-	static unsigned short quadIndices[] = {0, 1, 2, 2, 3, 0};
  410-	float minX = FLT_MAX;
  411-	float minY = FLT_MAX;
  412-	float maxX = -FLT_MAX;
  413-	float maxY = -FLT_MAX;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skeleton.java:471
  471:	public void getBounds (Vector2 offset, Vector2 size, FloatArray temp) {
  472:		getBounds(offset, size, temp, null);
  473-	}
  474-
  475-	/** Returns the axis aligned bounding box (AABB) of the region and mesh attachments for the current pose. Optionally applies
  476-	 * clipping.
  477-	 * @param offset An output value, the distance from the skeleton origin to the bottom left corner of the AABB.
  478-	 * @param size An output value, the width and height of the AABB.
  479-	 * @param temp Working memory to temporarily store attachments' computed world vertices.
  480-	 * @param clipper {@link SkeletonClipping} to use. If <code>null</code>, no clipping is applied. */
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBinary.h:124](../../spine-cpp/include/spine/SkeletonBinary.h#L124) SkeletonData * SkeletonBinary::readSkeletonData(const unsigned char * binary, int length) // returns nullable pointer: SkeletonData *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBinary.cpp:98
  98:SkeletonData *SkeletonBinary::readSkeletonDataFile(const String &path) {
  99-	int length;
  100-	const char *binary = SpineExtension::readFile(path.buffer(), &length);
  101-	if (length == 0 || !binary) {
  102-		setError("Unable to read skeleton file: ", path.buffer());
  103-		return NULL;
  104-	}
  105-
  106-	SkeletonData *skeletonData = readSkeletonData((unsigned char *) binary, length);
  107-	SpineExtension::free(binary, __FILE__, __LINE__);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonBinary.java:181
  181:	public SkeletonData readSkeletonData (FileHandle file) {
  182-		if (file == null) throw new IllegalArgumentException("file cannot be null.");
  183-		try {
  184:			SkeletonData skeletonData = readSkeletonData(file.read());
  185-			skeletonData.name = file.nameWithoutExtension();
  186-			return skeletonData;
  187-		} catch (Throwable ex) {
  188-			throw new SerializationException("Error reading binary skeleton file: " + file, ex);
  189-		}
  190-	}
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBinary.h:126](../../spine-cpp/include/spine/SkeletonBinary.h#L126) SkeletonData * SkeletonBinary::readSkeletonDataFile(const String & path) // returns nullable pointer: SkeletonData *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBinary.cpp:98
  98:SkeletonData *SkeletonBinary::readSkeletonDataFile(const String &path) {
  99-	int length;
  100-	const char *binary = SpineExtension::readFile(path.buffer(), &length);
  101-	if (length == 0 || !binary) {
  102-		setError("Unable to read skeleton file: ", path.buffer());
  103-		return NULL;
  104-	}
  105-
  106-	SkeletonData *skeletonData = readSkeletonData((unsigned char *) binary, length);
  107-	SpineExtension::free(binary, __FILE__, __LINE__);
  ```
  ```java
  NOT FOUND - searched for class "SkeletonBinary" (from C++ "SkeletonBinary") and method "readSkeletonDataFile" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBounds.h:71](../../spine-cpp/include/spine/SkeletonBounds.h#L71) bool SkeletonBounds::containsPoint(Polygon & polygon, float x, float y) // changed to reference
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBounds.cpp:123
  123:bool SkeletonBounds::containsPoint(Polygon *polygon, float x, float y) {
  124-	Array<float> &vertices = polygon->_vertices;
  125-	int nn = polygon->_count;
  126-
  127-	int prevIndex = nn - 2;
  128-	bool inside = false;
  129-	for (int ii = 0; ii < nn; ii += 2) {
  130-		float vertexY = vertices[ii + 1];
  131-		float prevY = vertices[prevIndex + 1];
  132-		if ((vertexY < y && prevY >= y) || (prevY < y && vertexY >= y)) {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonBounds.java:145
  145:	public @Null BoundingBoxAttachment containsPoint (float x, float y) {
  146-		FloatArray[] polygons = this.polygons.items;
  147-		for (int i = 0, n = this.polygons.size; i < n; i++)
  148:			if (containsPoint(polygons[i], x, y)) return boundingBoxes.items[i];
  149-		return null;
  150-	}
  151-
  152-	/** Returns true if the polygon contains the point. */
  153:	public boolean containsPoint (FloatArray polygon, float x, float y) {
  154-		if (polygon == null) throw new IllegalArgumentException("polygon cannot be null.");
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBounds.h:75](../../spine-cpp/include/spine/SkeletonBounds.h#L75) BoundingBoxAttachment * SkeletonBounds::containsPoint(float x, float y) // returns nullable pointer: BoundingBoxAttachment *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBounds.cpp:123
  123:bool SkeletonBounds::containsPoint(Polygon *polygon, float x, float y) {
  124-	Array<float> &vertices = polygon->_vertices;
  125-	int nn = polygon->_count;
  126-
  127-	int prevIndex = nn - 2;
  128-	bool inside = false;
  129-	for (int ii = 0; ii < nn; ii += 2) {
  130-		float vertexY = vertices[ii + 1];
  131-		float prevY = vertices[prevIndex + 1];
  132-		if ((vertexY < y && prevY >= y) || (prevY < y && vertexY >= y)) {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonBounds.java:145
  145:	public @Null BoundingBoxAttachment containsPoint (float x, float y) {
  146-		FloatArray[] polygons = this.polygons.items;
  147-		for (int i = 0, n = this.polygons.size; i < n; i++)
  148:			if (containsPoint(polygons[i], x, y)) return boundingBoxes.items[i];
  149-		return null;
  150-	}
  151-
  152-	/** Returns true if the polygon contains the point. */
  153:	public boolean containsPoint (FloatArray polygon, float x, float y) {
  154-		if (polygon == null) throw new IllegalArgumentException("polygon cannot be null.");
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBounds.h:79](../../spine-cpp/include/spine/SkeletonBounds.h#L79) BoundingBoxAttachment * SkeletonBounds::intersectsSegment(float x1, float y1, float x2, float y2) // returns nullable pointer: BoundingBoxAttachment *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBounds.cpp:149
  149:BoundingBoxAttachment *SkeletonBounds::intersectsSegment(float x1, float y1, float x2, float y2) {
  150-	for (size_t i = 0, n = _polygons.size(); i < n; ++i)
  151-		if (intersectsSegment(_polygons[i], x1, y1, x2, y2)) return _boundingBoxes[i];
  152-	return NULL;
  153-}
  154-
  155:bool SkeletonBounds::intersectsSegment(Polygon *polygon, float x1, float y1, float x2, float y2) {
  156-	Array<float> &vertices = polygon->_vertices;
  157-	size_t nn = polygon->_count;
  158-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonBounds.java:175
  175:	public @Null BoundingBoxAttachment intersectsSegment (float x1, float y1, float x2, float y2) {
  176-		FloatArray[] polygons = this.polygons.items;
  177-		for (int i = 0, n = this.polygons.size; i < n; i++)
  178:			if (intersectsSegment(polygons[i], x1, y1, x2, y2)) return boundingBoxes.items[i];
  179-		return null;
  180-	}
  181-
  182-	/** Returns true if the polygon contains any part of the line segment. */
  183:	public boolean intersectsSegment (FloatArray polygon, float x1, float y1, float x2, float y2) {
  184-		if (polygon == null) throw new IllegalArgumentException("polygon cannot be null.");
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBounds.h:82](../../spine-cpp/include/spine/SkeletonBounds.h#L82) bool SkeletonBounds::intersectsSegment(Polygon & polygon, float x1, float y1, float x2, float y2) // changed to reference
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBounds.cpp:149
  149:BoundingBoxAttachment *SkeletonBounds::intersectsSegment(float x1, float y1, float x2, float y2) {
  150-	for (size_t i = 0, n = _polygons.size(); i < n; ++i)
  151-		if (intersectsSegment(_polygons[i], x1, y1, x2, y2)) return _boundingBoxes[i];
  152-	return NULL;
  153-}
  154-
  155:bool SkeletonBounds::intersectsSegment(Polygon *polygon, float x1, float y1, float x2, float y2) {
  156-	Array<float> &vertices = polygon->_vertices;
  157-	size_t nn = polygon->_count;
  158-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonBounds.java:175
  175:	public @Null BoundingBoxAttachment intersectsSegment (float x1, float y1, float x2, float y2) {
  176-		FloatArray[] polygons = this.polygons.items;
  177-		for (int i = 0, n = this.polygons.size; i < n; i++)
  178:			if (intersectsSegment(polygons[i], x1, y1, x2, y2)) return boundingBoxes.items[i];
  179-		return null;
  180-	}
  181-
  182-	/** Returns true if the polygon contains any part of the line segment. */
  183:	public boolean intersectsSegment (FloatArray polygon, float x1, float y1, float x2, float y2) {
  184-		if (polygon == null) throw new IllegalArgumentException("polygon cannot be null.");
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBounds.h:86](../../spine-cpp/include/spine/SkeletonBounds.h#L86) Polygon * SkeletonBounds::getPolygon(BoundingBoxAttachment * attachment) // returns nullable pointer: Polygon *; takes nullable parameter 'attachment': BoundingBoxAttachment *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBounds.cpp:181
  181:Polygon *SkeletonBounds::getPolygon(BoundingBoxAttachment *attachment) {
  182-	int index = _boundingBoxes.indexOf(attachment);
  183-	return index == -1 ? NULL : _polygons[index];
  184-}
  185-
  186-BoundingBoxAttachment *SkeletonBounds::getBoundingBox(Polygon *polygon) {
  187-	int index = _polygons.indexOf(polygon);
  188-	return index == -1 ? NULL : _boundingBoxes[index];
  189-}
  190-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonBounds.java:248
  248:	public @Null FloatArray getPolygon (BoundingBoxAttachment boundingBox) {
  249-		if (boundingBox == null) throw new IllegalArgumentException("boundingBox cannot be null.");
  250-		int index = boundingBoxes.indexOf(boundingBox, true);
  251-		return index == -1 ? null : polygons.items[index];
  252-	}
  253-}
  ```
- [x] [../../spine-cpp/include/spine/SkeletonBounds.h:89](../../spine-cpp/include/spine/SkeletonBounds.h#L89) BoundingBoxAttachment * SkeletonBounds::getBoundingBox(Polygon * polygon) // returns nullable pointer: BoundingBoxAttachment *; takes nullable parameter 'polygon': Polygon *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonBounds.cpp:186
  186:BoundingBoxAttachment *SkeletonBounds::getBoundingBox(Polygon *polygon) {
  187-	int index = _polygons.indexOf(polygon);
  188-	return index == -1 ? NULL : _boundingBoxes[index];
  189-}
  190-
  191-Array<Polygon *> &SkeletonBounds::getPolygons() {
  192-	return _polygons;
  193-}
  194-
  195:Array<BoundingBoxAttachment *> &SkeletonBounds::getBoundingBoxes() {
  ```
  ```java
  NOT FOUND - searched for class "SkeletonBounds" (from C++ "SkeletonBounds") and method "getBoundingBox" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/SkeletonClipping.h:45](../../spine-cpp/include/spine/SkeletonClipping.h#L45) size_t SkeletonClipping::clipStart(Skeleton & skeleton, Slot & slot, ClippingAttachment * clip) // takes nullable parameter 'clip': ClippingAttachment *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonClipping.cpp:44
  44:size_t SkeletonClipping::clipStart(Skeleton &skeleton, Slot &slot, ClippingAttachment *clip) {
  45-	if (_clipAttachment != NULL) {
  46-		return 0;
  47-	}
  48-
  49-	_clipAttachment = clip;
  50-
  51-	int n = (int) clip->getWorldVerticesLength();
  52-	if (n < 6) {
  53-		return 0;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/utils/SkeletonClipping.java:52
  52:	public void clipStart (Skeleton skeleton, Slot slot, ClippingAttachment clip) {
  53-		if (clipAttachment != null) return;
  54-		int n = clip.getWorldVerticesLength();
  55-		if (n < 6) return;
  56-		clipAttachment = clip;
  57-
  58-		float[] vertices = clippingPolygon.setSize(n);
  59-		clip.computeWorldVertices(skeleton, slot, 0, n, vertices, 0, 2);
  60-		makeClockwise(clippingPolygon);
  61-		ShortArray triangles = triangulator.triangulate(clippingPolygon);
  ```
- [x] [../../spine-cpp/include/spine/SkeletonData.h:77](../../spine-cpp/include/spine/SkeletonData.h#L77) BoneData * SkeletonData::findBone(const String & boneName) // returns nullable pointer: BoneData *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonData.cpp:67
  67:BoneData *SkeletonData::findBone(const String &boneName) {
  68-	return ArrayUtils::findWithName(_bones, boneName);
  69-}
  70-
  71-SlotData *SkeletonData::findSlot(const String &slotName) {
  72-	return ArrayUtils::findWithName(_slots, slotName);
  73-}
  74-
  75-Skin *SkeletonData::findSkin(const String &skinName) {
  76-	return ArrayUtils::findWithName(_skins, skinName);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonData.java:68
  68:	public @Null BoneData findBone (String boneName) {
  69-		if (boneName == null) throw new IllegalArgumentException("boneName cannot be null.");
  70-		BoneData[] bones = this.bones.items;
  71-		for (int i = 0, n = this.bones.size; i < n; i++)
  72-			if (bones[i].name.equals(boneName)) return bones[i];
  73-		return null;
  74-	}
  75-
  76-	// --- Slots.
  77-
  ```
- [x] [../../spine-cpp/include/spine/SkeletonData.h:80](../../spine-cpp/include/spine/SkeletonData.h#L80) SlotData * SkeletonData::findSlot(const String & slotName) // returns nullable pointer: SlotData *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonData.cpp:71
  71:SlotData *SkeletonData::findSlot(const String &slotName) {
  72-	return ArrayUtils::findWithName(_slots, slotName);
  73-}
  74-
  75-Skin *SkeletonData::findSkin(const String &skinName) {
  76-	return ArrayUtils::findWithName(_skins, skinName);
  77-}
  78-
  79-EventData *SkeletonData::findEvent(const String &eventDataName) {
  80-	return ArrayUtils::findWithName(_events, eventDataName);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonData.java:85
  85:	public @Null SlotData findSlot (String slotName) {
  86-		if (slotName == null) throw new IllegalArgumentException("slotName cannot be null.");
  87-		SlotData[] slots = this.slots.items;
  88-		for (int i = 0, n = this.slots.size; i < n; i++)
  89-			if (slots[i].name.equals(slotName)) return slots[i];
  90-		return null;
  91-	}
  92-
  93-	// --- Skins.
  94-
  ```
- [x] [../../spine-cpp/include/spine/SkeletonData.h:83](../../spine-cpp/include/spine/SkeletonData.h#L83) Skin * SkeletonData::findSkin(const String & skinName) // returns nullable pointer: Skin *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonData.cpp:75
  75:Skin *SkeletonData::findSkin(const String &skinName) {
  76-	return ArrayUtils::findWithName(_skins, skinName);
  77-}
  78-
  79-EventData *SkeletonData::findEvent(const String &eventDataName) {
  80-	return ArrayUtils::findWithName(_events, eventDataName);
  81-}
  82-
  83-Animation *SkeletonData::findAnimation(const String &animationName) {
  84-	return ArrayUtils::findWithName(_animations, animationName);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonData.java:108
  108:	public @Null Skin findSkin (String skinName) {
  109-		if (skinName == null) throw new IllegalArgumentException("skinName cannot be null.");
  110-		for (Skin skin : skins)
  111-			if (skin.name.equals(skinName)) return skin;
  112-		return null;
  113-	}
  114-
  115-	/** All skins, including the default skin. */
  116-	public Array<Skin> getSkins () {
  117-		return skins;
  ```
- [x] [../../spine-cpp/include/spine/SkeletonData.h:86](../../spine-cpp/include/spine/SkeletonData.h#L86) EventData * SkeletonData::findEvent(const String & eventDataName) // returns nullable pointer: EventData *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonData.cpp:79
  79:EventData *SkeletonData::findEvent(const String &eventDataName) {
  80-	return ArrayUtils::findWithName(_events, eventDataName);
  81-}
  82-
  83-Animation *SkeletonData::findAnimation(const String &animationName) {
  84-	return ArrayUtils::findWithName(_animations, animationName);
  85-}
  86-
  87-const String &SkeletonData::getName() {
  88-	return _name;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonData.java:124
  124:	public @Null EventData findEvent (String eventDataName) {
  125-		if (eventDataName == null) throw new IllegalArgumentException("eventDataName cannot be null.");
  126-		for (EventData eventData : events)
  127-			if (eventData.name.equals(eventDataName)) return eventData;
  128-		return null;
  129-	}
  130-
  131-	/** The skeleton's events. */
  132-	public Array<EventData> getEvents () {
  133-		return events;
  ```
- [x] [../../spine-cpp/include/spine/SkeletonData.h:89](../../spine-cpp/include/spine/SkeletonData.h#L89) Animation * SkeletonData::findAnimation(const String & animationName) // returns nullable pointer: Animation *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonData.cpp:83
  83:Animation *SkeletonData::findAnimation(const String &animationName) {
  84-	return ArrayUtils::findWithName(_animations, animationName);
  85-}
  86-
  87-const String &SkeletonData::getName() {
  88-	return _name;
  89-}
  90-
  91-void SkeletonData::setName(const String &inValue) {
  92-	_name = inValue;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonData.java:145
  145:	public @Null Animation findAnimation (String animationName) {
  146-		if (animationName == null) throw new IllegalArgumentException("animationName cannot be null.");
  147-		Animation[] animations = this.animations.items;
  148-		for (int i = 0, n = this.animations.size; i < n; i++)
  149-			if (animations[i].name.equals(animationName)) return animations[i];
  150-		return null;
  151-	}
  152-
  153-	// --- Constraints.
  154-
  ```
- [x] [../../spine-cpp/include/spine/SkeletonData.h:109](../../spine-cpp/include/spine/SkeletonData.h#L109) Skin * SkeletonData::getDefaultSkin() // returns nullable pointer: Skin *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonData.cpp:107
  107:Skin *SkeletonData::getDefaultSkin() {
  108-	return _defaultSkin;
  109-}
  110-
  111-void SkeletonData::setDefaultSkin(Skin *inValue) {
  112-	_defaultSkin = inValue;
  113-}
  114-
  115-Array<EventData *> &SkeletonData::getEvents() {
  116-	return _events;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonData.java:98
  98:	public @Null Skin getDefaultSkin () {
  99-		return defaultSkin;
  100-	}
  101-
  102-	public void setDefaultSkin (@Null Skin defaultSkin) {
  103-		this.defaultSkin = defaultSkin;
  104-	}
  105-
  106-	/** Finds a skin by comparing each skin's name. It is more efficient to cache the results of this method than to call it
  107-	 * multiple times. */
  ```
- [x] [../../spine-cpp/include/spine/SkeletonData.h:111](../../spine-cpp/include/spine/SkeletonData.h#L111) void SkeletonData::setDefaultSkin(Skin * inValue) // takes nullable parameter 'inValue': Skin *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonData.cpp:111
  111:void SkeletonData::setDefaultSkin(Skin *inValue) {
  112-	_defaultSkin = inValue;
  113-}
  114-
  115-Array<EventData *> &SkeletonData::getEvents() {
  116-	return _events;
  117-}
  118-
  119-Array<Animation *> &SkeletonData::getAnimations() {
  120-	return _animations;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonData.java:102
  102:	public void setDefaultSkin (@Null Skin defaultSkin) {
  103-		this.defaultSkin = defaultSkin;
  104-	}
  105-
  106-	/** Finds a skin by comparing each skin's name. It is more efficient to cache the results of this method than to call it
  107-	 * multiple times. */
  108-	public @Null Skin findSkin (String skinName) {
  109-		if (skinName == null) throw new IllegalArgumentException("skinName cannot be null.");
  110-		for (Skin skin : skins)
  111-			if (skin.name.equals(skinName)) return skin;
  ```
- [x] [../../spine-cpp/include/spine/SkeletonJson.h:76](../../spine-cpp/include/spine/SkeletonJson.h#L76) SkeletonData * SkeletonJson::readSkeletonDataFile(const String & path) // returns nullable pointer: SkeletonData *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonJson.cpp:138
  138:SkeletonData *SkeletonJson::readSkeletonDataFile(const String &path) {
  139-	int length;
  140-	SkeletonData *skeletonData;
  141-	const char *json = SpineExtension::readFile(path, &length);
  142-	if (length == 0 || !json) {
  143-		setError(NULL, "Unable to read skeleton file: ", path);
  144-		return NULL;
  145-	}
  146-
  147-	skeletonData = readSkeletonData(json);
  ```
  ```java
  NOT FOUND - searched for class "SkeletonJson" (from C++ "SkeletonJson") and method "readSkeletonDataFile" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/SkeletonJson.h:78](../../spine-cpp/include/spine/SkeletonJson.h#L78) SkeletonData * SkeletonJson::readSkeletonData(const char * json) // returns nullable pointer: SkeletonData *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonJson.cpp:138
  138:SkeletonData *SkeletonJson::readSkeletonDataFile(const String &path) {
  139-	int length;
  140-	SkeletonData *skeletonData;
  141-	const char *json = SpineExtension::readFile(path, &length);
  142-	if (length == 0 || !json) {
  143-		setError(NULL, "Unable to read skeleton file: ", path);
  144-		return NULL;
  145-	}
  146-
  147-	skeletonData = readSkeletonData(json);
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SkeletonJson.java:136
  136:	public SkeletonData readSkeletonData (FileHandle file) {
  137-		if (file == null) throw new IllegalArgumentException("file cannot be null.");
  138-		try {
  139:			SkeletonData skeletonData = readSkeletonData(new JsonReader().parse(file));
  140-			skeletonData.name = file.nameWithoutExtension();
  141-			return skeletonData;
  142-		} catch (Throwable ex) {
  143-			throw new SerializationException("Error reading JSON skeleton file: " + file, ex);
  144-		}
  145-	}
  ```
- [x] [../../spine-cpp/include/spine/SkeletonRenderer.h:59](../../spine-cpp/include/spine/SkeletonRenderer.h#L59) RenderCommand * SkeletonRenderer::render(Skeleton & skeleton) // returns nullable pointer: RenderCommand *
  ```cpp
  ../../spine-cpp/src/spine/SkeletonRenderer.cpp:136
  136:RenderCommand *SkeletonRenderer::render(Skeleton &skeleton) {
  137-	_allocator.compress();
  138-	_renderCommands.clear();
  139-
  140-	SkeletonClipping &clipper = _clipping;
  141-
  142-	for (unsigned i = 0; i < skeleton.getSlots().size(); ++i) {
  143-		Slot &slot = *skeleton.getDrawOrder()[i];
  144-		Attachment *attachment = slot.getAppliedPose().getAttachment();
  145-		if (!attachment) {
  ```
  ```java
  NOT FOUND - searched for class "SkeletonRenderer" (from C++ "SkeletonRenderer") and method "render" across all Java files
  ```
- [x] [../../spine-cpp/include/spine/Skin.h:121](../../spine-cpp/include/spine/Skin.h#L121) void Skin::setAttachment(size_t slotIndex, const String & name, Attachment * attachment) // takes nullable parameter 'attachment': Attachment *
  ```cpp
  ../../spine-cpp/src/spine/Skin.cpp:102
  102:void Skin::setAttachment(size_t slotIndex, const String &name, Attachment *attachment) {
  103-	assert(attachment);
  104-	_attachments.put(slotIndex, name, attachment);
  105-}
  106-
  107-Attachment *Skin::getAttachment(size_t slotIndex, const String &name) {
  108-	return _attachments.get(slotIndex, name);
  109-}
  110-
  111-void Skin::removeAttachment(size_t slotIndex, const String &name) {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skin.java:61
  61:	public void setAttachment (int slotIndex, String name, Attachment attachment) {
  62-		if (attachment == null) throw new IllegalArgumentException("attachment cannot be null.");
  63-		var entry = new SkinEntry(slotIndex, name, attachment);
  64-		if (!attachments.add(entry)) attachments.get(entry).attachment = attachment;
  65-	}
  66-
  67-	/** Adds all attachments, bones, and constraints from the specified skin to this skin. */
  68-	public void addSkin (Skin skin) {
  69-		if (skin == null) throw new IllegalArgumentException("skin cannot be null.");
  70-
  ```
- [x] [../../spine-cpp/include/spine/Skin.h:124](../../spine-cpp/include/spine/Skin.h#L124) Attachment * Skin::getAttachment(size_t slotIndex, const String & name) // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/Skin.cpp:107
  107:Attachment *Skin::getAttachment(size_t slotIndex, const String &name) {
  108-	return _attachments.get(slotIndex, name);
  109-}
  110-
  111-void Skin::removeAttachment(size_t slotIndex, const String &name) {
  112-	_attachments.remove(slotIndex, name);
  113-}
  114-
  115-void Skin::findNamesForSlot(size_t slotIndex, Array<String> &names) {
  116-	Skin::AttachmentMap::Entries entries = _attachments.getEntries();
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skin.java:101
  101:	public @Null Attachment getAttachment (int slotIndex, String name) {
  102-		lookup.set(slotIndex, name);
  103-		SkinEntry entry = attachments.get(lookup);
  104-		return entry != null ? entry.attachment : null;
  105-	}
  106-
  107-	/** Removes the attachment in the skin for the specified slot index and name, if any. */
  108-	public void removeAttachment (int slotIndex, String name) {
  109-		lookup.set(slotIndex, name);
  110-		attachments.remove(lookup);
  ```
- [x] [../../spine-cpp/include/spine/Skin.h:142](../../spine-cpp/include/spine/Skin.h#L142) void Skin::addSkin(Skin * other) // takes nullable parameter 'other': Skin *
  ```cpp
  ../../spine-cpp/src/spine/Skin.cpp:156
  156:void Skin::addSkin(Skin *other) {
  157-	for (size_t i = 0; i < other->getBones().size(); i++)
  158-		if (!_bones.contains(other->getBones()[i])) _bones.add(other->getBones()[i]);
  159-
  160-	for (size_t i = 0; i < other->getConstraints().size(); i++)
  161-		if (!_constraints.contains(other->getConstraints()[i])) _constraints.add(other->getConstraints()[i]);
  162-
  163-	AttachmentMap::Entries entries = other->getAttachments();
  164-	while (entries.hasNext()) {
  165-		AttachmentMap::Entry &entry = entries.next();
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skin.java:68
  68:	public void addSkin (Skin skin) {
  69-		if (skin == null) throw new IllegalArgumentException("skin cannot be null.");
  70-
  71-		for (BoneData data : skin.bones)
  72-			if (!bones.contains(data, true)) bones.add(data);
  73-
  74-		for (ConstraintData data : skin.constraints)
  75-			if (!constraints.contains(data, true)) constraints.add(data);
  76-
  77-		for (SkinEntry entry : skin.attachments.orderedItems())
  ```
- [x] [../../spine-cpp/include/spine/Skin.h:145](../../spine-cpp/include/spine/Skin.h#L145) void Skin::copySkin(Skin * other) // takes nullable parameter 'other': Skin *
  ```cpp
  ../../spine-cpp/src/spine/Skin.cpp:170
  170:void Skin::copySkin(Skin *other) {
  171-	for (size_t i = 0; i < other->getBones().size(); i++)
  172-		if (!_bones.contains(other->getBones()[i])) _bones.add(other->getBones()[i]);
  173-
  174-	for (size_t i = 0; i < other->getConstraints().size(); i++)
  175-		if (!_constraints.contains(other->getConstraints()[i])) _constraints.add(other->getConstraints()[i]);
  176-
  177-	AttachmentMap::Entries entries = other->getAttachments();
  178-	while (entries.hasNext()) {
  179-		AttachmentMap::Entry &entry = entries.next();
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Skin.java:83
  83:	public void copySkin (Skin skin) {
  84-		if (skin == null) throw new IllegalArgumentException("skin cannot be null.");
  85-
  86-		for (BoneData data : skin.bones)
  87-			if (!bones.contains(data, true)) bones.add(data);
  88-
  89-		for (ConstraintData data : skin.constraints)
  90-			if (!constraints.contains(data, true)) constraints.add(data);
  91-
  92-		for (SkinEntry entry : skin.attachments.orderedItems()) {
  ```
- [x] [../../spine-cpp/include/spine/Slider.h:55](../../spine-cpp/include/spine/Slider.h#L55) Slider * Slider::copy(Skeleton & skeleton) // returns nullable pointer: Slider *
  ```cpp
  ../../spine-cpp/src/spine/Slider.cpp:59
  59:Slider *Slider::copy(Skeleton &skeleton) {
  60-	Slider *copy = new (__FILE__, __LINE__) Slider(_data, skeleton);
  61-	copy->_pose.set(_pose);
  62-	return copy;
  63-}
  64-
  65-void Slider::update(Skeleton &skeleton, Physics physics) {
  66-	SliderPose &p = *_applied;
  67-	if (p._mix == 0) return;
  68-
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Slider.java:54
  54:	public Slider copy (Skeleton skeleton) {
  55-		var copy = new Slider(data, skeleton);
  56-		copy.pose.set(pose);
  57-		return copy;
  58-	}
  59-
  60-	public void update (Skeleton skeleton, Physics physics) {
  61-		SliderPose p = applied;
  62-		if (p.mix == 0) return;
  63-
  ```
- [x] [../../spine-cpp/include/spine/Slider.h:63](../../spine-cpp/include/spine/Slider.h#L63) Bone * Slider::getBone() // returns nullable pointer: Bone *
  ```cpp
  ../../spine-cpp/src/spine/Slider.cpp:129
  129:Bone *Slider::getBone() {
  130-	return _bone;
  131-}
  132-
  133-void Slider::setBone(Bone *bone) {
  134-	_bone = bone;
  135-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Slider.java:118
  118:	public Bone getBone () {
  119-		return bone;
  120-	}
  121-
  122-	public void setBone (Bone bone) {
  123-		this.bone = bone;
  124-	}
  125-}
  ```
- [x] [../../spine-cpp/include/spine/Slider.h:65](../../spine-cpp/include/spine/Slider.h#L65) void Slider::setBone(Bone * bone) // takes nullable parameter 'bone': Bone *
  ```cpp
  ../../spine-cpp/src/spine/Slider.cpp:133
  133:void Slider::setBone(Bone *bone) {
  134-	_bone = bone;
  135-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/Slider.java:122
  122:	public void setBone (Bone bone) {
  123-		this.bone = bone;
  124-	}
  125-}
  ```
- [x] [../../spine-cpp/include/spine/SliderData.h:59](../../spine-cpp/include/spine/SliderData.h#L59) Constraint * SliderData::create(Skeleton & skeleton) // returns nullable pointer: Constraint *
  ```cpp
  ../../spine-cpp/src/spine/SliderData.cpp:43
  43:Constraint *SliderData::create(Skeleton &skeleton) {
  44-	return new (__FILE__, __LINE__) Slider(*this, skeleton);
  45-}
  46-
  47-Animation *SliderData::getAnimation() {
  48-	return _animation;
  49-}
  50-
  51-void SliderData::setAnimation(Animation *animation) {
  52-	_animation = animation;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SliderData.java:49
  49:	public Slider create (Skeleton skeleton) {
  50-		return new Slider(this, skeleton);
  51-	}
  52-
  53-	public Animation getAnimation () {
  54-		return animation;
  55-	}
  56-
  57-	public void setAnimation (Animation animation) {
  58-		this.animation = animation;
  ```
- [x] [../../spine-cpp/include/spine/SliderData.h:61](../../spine-cpp/include/spine/SliderData.h#L61) Animation * SliderData::getAnimation() // returns nullable pointer: Animation *
  ```cpp
  ../../spine-cpp/src/spine/SliderData.cpp:47
  47:Animation *SliderData::getAnimation() {
  48-	return _animation;
  49-}
  50-
  51-void SliderData::setAnimation(Animation *animation) {
  52-	_animation = animation;
  53-}
  54-
  55-bool SliderData::getAdditive() {
  56-	return _additive;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SliderData.java:53
  53:	public Animation getAnimation () {
  54-		return animation;
  55-	}
  56-
  57-	public void setAnimation (Animation animation) {
  58-		this.animation = animation;
  59-	}
  60-
  61-	public boolean getAdditive () {
  62-		return additive;
  ```
- [x] [../../spine-cpp/include/spine/SliderData.h:62](../../spine-cpp/include/spine/SliderData.h#L62) void SliderData::setAnimation(Animation * animation) // takes nullable parameter 'animation': Animation *
  ```cpp
  ../../spine-cpp/src/spine/SliderData.cpp:51
  51:void SliderData::setAnimation(Animation *animation) {
  52-	_animation = animation;
  53-}
  54-
  55-bool SliderData::getAdditive() {
  56-	return _additive;
  57-}
  58-
  59-void SliderData::setAdditive(bool additive) {
  60-	_additive = additive;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SliderData.java:57
  57:	public void setAnimation (Animation animation) {
  58-		this.animation = animation;
  59-	}
  60-
  61-	public boolean getAdditive () {
  62-		return additive;
  63-	}
  64-
  65-	public void setAdditive (boolean additive) {
  66-		this.additive = additive;
  ```
- [x] [../../spine-cpp/include/spine/SliderData.h:70](../../spine-cpp/include/spine/SliderData.h#L70) BoneData * SliderData::getBone() // returns nullable pointer: BoneData *
  ```cpp
  ../../spine-cpp/src/spine/SliderData.cpp:71
  71:BoneData *SliderData::getBone() {
  72-	return _bone;
  73-}
  74-
  75-void SliderData::setBone(BoneData *bone) {
  76-	_bone = bone;
  77-}
  78-
  79-FromProperty *SliderData::getProperty() {
  80-	return _property;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SliderData.java:77
  77:	public @Null BoneData getBone () {
  78-		return bone;
  79-	}
  80-
  81-	public void setBone (@Null BoneData bone) {
  82-		this.bone = bone;
  83-	}
  84-
  85-	public @Null FromProperty getProperty () {
  86-		return property;
  ```
- [x] [../../spine-cpp/include/spine/SliderData.h:71](../../spine-cpp/include/spine/SliderData.h#L71) void SliderData::setBone(BoneData * bone) // takes nullable parameter 'bone': BoneData *
  ```cpp
  ../../spine-cpp/src/spine/SliderData.cpp:75
  75:void SliderData::setBone(BoneData *bone) {
  76-	_bone = bone;
  77-}
  78-
  79-FromProperty *SliderData::getProperty() {
  80-	return _property;
  81-}
  82-
  83-void SliderData::setProperty(FromProperty *property) {
  84-	_property = property;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SliderData.java:81
  81:	public void setBone (@Null BoneData bone) {
  82-		this.bone = bone;
  83-	}
  84-
  85-	public @Null FromProperty getProperty () {
  86-		return property;
  87-	}
  88-
  89-	public void setProperty (@Null FromProperty property) {
  90-		this.property = property;
  ```
- [x] [../../spine-cpp/include/spine/SliderData.h:73](../../spine-cpp/include/spine/SliderData.h#L73) FromProperty * SliderData::getProperty() // returns nullable pointer: FromProperty *
  ```cpp
  ../../spine-cpp/src/spine/SliderData.cpp:79
  79:FromProperty *SliderData::getProperty() {
  80-	return _property;
  81-}
  82-
  83-void SliderData::setProperty(FromProperty *property) {
  84-	_property = property;
  85-}
  86-
  87-float SliderData::getScale() {
  88-	return _scale;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SliderData.java:85
  85:	public @Null FromProperty getProperty () {
  86-		return property;
  87-	}
  88-
  89-	public void setProperty (@Null FromProperty property) {
  90-		this.property = property;
  91-	}
  92-
  93-	public float getOffset () {
  94-		return offset;
  ```
- [x] [../../spine-cpp/include/spine/SliderData.h:74](../../spine-cpp/include/spine/SliderData.h#L74) void SliderData::setProperty(FromProperty * property) // takes nullable parameter 'property': FromProperty *
  ```cpp
  ../../spine-cpp/src/spine/SliderData.cpp:83
  83:void SliderData::setProperty(FromProperty *property) {
  84-	_property = property;
  85-}
  86-
  87-float SliderData::getScale() {
  88-	return _scale;
  89-}
  90-
  91-void SliderData::setScale(float scale) {
  92-	_scale = scale;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SliderData.java:89
  89:	public void setProperty (@Null FromProperty property) {
  90-		this.property = property;
  91-	}
  92-
  93-	public float getOffset () {
  94-		return offset;
  95-	}
  96-
  97-	public void setOffset (float offset) {
  98-		this.offset = offset;
  ```
- [x] [../../spine-cpp/include/spine/SlotPose.h:85](../../spine-cpp/include/spine/SlotPose.h#L85) Attachment * SlotPose::getAttachment() // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/SlotPose.cpp:68
  68:Attachment *SlotPose::getAttachment() {
  69-	return _attachment;
  70-}
  71-
  72-void SlotPose::setAttachment(Attachment *attachment) {
  73-	if (_attachment == attachment) return;
  74-
  75-	// Check if we need to clear deform based on timeline attachment
  76-	if (!attachment || !_attachment || !attachment->getRTTI().instanceOf(VertexAttachment::rtti) ||
  77-		!_attachment->getRTTI().instanceOf(VertexAttachment::rtti) ||
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SlotPose.java:77
  77:	public @Null Attachment getAttachment () {
  78-		return attachment;
  79-	}
  80-
  81-	/** Sets the slot's attachment and, if the attachment changed, resets {@link #sequenceIndex} and clears the {@link #deform}.
  82-	 * The deform is not cleared if the old attachment has the same {@link VertexAttachment#getTimelineAttachment()} as the
  83-	 * specified attachment. */
  84-	public void setAttachment (@Null Attachment attachment) {
  85-		if (this.attachment == attachment) return;
  86-		if (!(attachment instanceof VertexAttachment newAttachment) || !(this.attachment instanceof VertexAttachment oldAttachment)
  ```
- [x] [../../spine-cpp/include/spine/SlotPose.h:90](../../spine-cpp/include/spine/SlotPose.h#L90) void SlotPose::setAttachment(Attachment * attachment) // takes nullable parameter 'attachment': Attachment *
  ```cpp
  ../../spine-cpp/src/spine/SlotPose.cpp:72
  72:void SlotPose::setAttachment(Attachment *attachment) {
  73-	if (_attachment == attachment) return;
  74-
  75-	// Check if we need to clear deform based on timeline attachment
  76-	if (!attachment || !_attachment || !attachment->getRTTI().instanceOf(VertexAttachment::rtti) ||
  77-		!_attachment->getRTTI().instanceOf(VertexAttachment::rtti) ||
  78-		static_cast<VertexAttachment *>(attachment)->getTimelineAttachment() !=
  79-			static_cast<VertexAttachment *>(_attachment)->getTimelineAttachment()) {
  80-		_deform.clear();
  81-	}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/SlotPose.java:84
  84:	public void setAttachment (@Null Attachment attachment) {
  85-		if (this.attachment == attachment) return;
  86-		if (!(attachment instanceof VertexAttachment newAttachment) || !(this.attachment instanceof VertexAttachment oldAttachment)
  87-			|| newAttachment.getTimelineAttachment() != oldAttachment.getTimelineAttachment()) {
  88-			deform.clear();
  89-		}
  90-		this.attachment = attachment;
  91-		sequenceIndex = -1;
  92-	}
  93-
  ```
- [x] [../../spine-cpp/include/spine/TrackEntry.h:107](../../spine-cpp/include/spine/TrackEntry.h#L107) Animation * TrackEntry::getAnimation() // returns nullable pointer: Animation *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/TrackEntry.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:934
  934:		public Animation getAnimation () {
  935-			return animation;
  936-		}
  937-
  938-		public void setAnimation (Animation animation) {
  939-			if (animation == null) throw new IllegalArgumentException("animation cannot be null.");
  940-			this.animation = animation;
  941-		}
  942-
  943-		/** If true, the animation will repeat. If false it will not, instead its last frame is applied if played beyond its
  ```
- [x] [../../spine-cpp/include/spine/TrackEntry.h:110](../../spine-cpp/include/spine/TrackEntry.h#L110) void TrackEntry::setAnimation(Animation * animation) // takes nullable parameter 'animation': Animation *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/TrackEntry.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:572
  572:	 * See {@link #setAnimation(int, Animation, boolean)}. */
  573:	public TrackEntry setAnimation (int trackIndex, String animationName, boolean loop) {
  574-		Animation animation = data.skeletonData.findAnimation(animationName);
  575-		if (animation == null) throw new IllegalArgumentException("Animation not found: " + animationName);
  576:		return setAnimation(trackIndex, animation, loop);
  577-	}
  578-
  579-	/** Sets the current animation for a track, discarding any queued animations.
  580-	 * <p>
  581-	 * If the formerly current track entry is for the same animation and was never applied to a skeleton, it is replaced (not mixed
  ```
- [x] [../../spine-cpp/include/spine/TrackEntry.h:112](../../spine-cpp/include/spine/TrackEntry.h#L112) TrackEntry * TrackEntry::getPrevious() // returns nullable pointer: TrackEntry *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/TrackEntry.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:1160
  1160:		public @Null TrackEntry getPrevious () {
  1161-			return previous;
  1162-		}
  1163-
  1164-		/** Returns true if this track entry has been applied at least once.
  1165-		 * <p>
  1166-		 * See {@link AnimationState#apply(Skeleton)}. */
  1167-		public boolean wasApplied () {
  1168-			return nextTrackLast != -1;
  1169-		}
  ```
- [x] [../../spine-cpp/include/spine/TrackEntry.h:258](../../spine-cpp/include/spine/TrackEntry.h#L258) TrackEntry * TrackEntry::getNext() // returns nullable pointer: TrackEntry *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/TrackEntry.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:757
  757:	/** Removes the {@link TrackEntry#getNext() next entry} and all entries after it for the specified entry. */
  758-	public void clearNext (TrackEntry entry) {
  759-		TrackEntry next = entry.next;
  760-		while (next != null) {
  761-			queue.dispose(next);
  762-			next = next.next;
  763-		}
  764-		entry.next = null;
  765-	}
  766-
  ```
- [x] [../../spine-cpp/include/spine/TrackEntry.h:294](../../spine-cpp/include/spine/TrackEntry.h#L294) TrackEntry * TrackEntry::getMixingFrom() // returns nullable pointer: TrackEntry *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/TrackEntry.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:1252
  1252:		public @Null TrackEntry getMixingFrom () {
  1253-			return mixingFrom;
  1254-		}
  1255-
  1256-		/** The track entry for the next animation when mixing from this animation to the next animation, or null if no mixing is
  1257-		 * currently occurring. When mixing to multiple animations, <code>mixingTo</code> makes up a linked list. */
  1258-		public @Null TrackEntry getMixingTo () {
  1259-			return mixingTo;
  1260-		}
  1261-
  ```
- [x] [../../spine-cpp/include/spine/TrackEntry.h:298](../../spine-cpp/include/spine/TrackEntry.h#L298) TrackEntry * TrackEntry::getMixingTo() // returns nullable pointer: TrackEntry *
  ```cpp
  NOT FOUND - file does not exist: ../../spine-cpp/src/spine/TrackEntry.cpp
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/AnimationState.java:1258
  1258:		public @Null TrackEntry getMixingTo () {
  1259-			return mixingTo;
  1260-		}
  1261-
  1262-		public void setHoldPrevious (boolean holdPrevious) {
  1263-			this.holdPrevious = holdPrevious;
  1264-		}
  1265-
  1266-		/** If true, when mixing from the previous animation to this animation, the previous animation is applied as normal instead
  1267-		 * of being mixed out.
  ```
- [x] [../../spine-cpp/include/spine/TransformConstraint.h:52](../../spine-cpp/include/spine/TransformConstraint.h#L52) TransformConstraint * TransformConstraint::copy(Skeleton & skeleton) // returns nullable pointer: TransformConstraint *
  ```cpp
  ../../spine-cpp/src/spine/TransformConstraint.cpp:56
  56:TransformConstraint *TransformConstraint::copy(Skeleton &skeleton) {
  57-	TransformConstraint *copy = new (__FILE__, __LINE__) TransformConstraint(_data, skeleton);
  58-	copy->_pose.set(_pose);
  59-	return copy;
  60-}
  61-
  62-/// Applies the constraint to the constrained bones.
  63-void TransformConstraint::update(Skeleton &skeleton, Physics physics) {
  64-	TransformConstraintPose &p = *_applied;
  65-	if (p._mixRotate == 0 && p._mixX == 0 && p._mixY == 0 && p._mixScaleX == 0 && p._mixScaleY == 0 && p._mixShearY == 0) return;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/TransformConstraint.java:58
  58:	public TransformConstraint copy (Skeleton skeleton) {
  59-		var copy = new TransformConstraint(data, skeleton);
  60-		copy.pose.set(pose);
  61-		return copy;
  62-	}
  63-
  64-	/** Applies the constraint to the constrained bones. */
  65-	public void update (Skeleton skeleton, Physics physics) {
  66-		TransformConstraintPose p = applied;
  67-		if (p.mixRotate == 0 & p.mixX == 0 & p.mixY == 0 & p.mixScaleX == 0 & p.mixScaleY == 0 & p.mixShearY == 0) return;
  ```
- [x] [../../spine-cpp/include/spine/TransformConstraint.h:65](../../spine-cpp/include/spine/TransformConstraint.h#L65) Bone * TransformConstraint::getSource() // returns nullable pointer: Bone *
  ```cpp
  ../../spine-cpp/src/spine/TransformConstraint.cpp:134
  134:Bone *TransformConstraint::getSource() {
  135-	return _source;
  136-}
  137-
  138-void TransformConstraint::setSource(Bone *source) {
  139-	_source = source;
  140-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/TransformConstraint.java:133
  133:	public Bone getSource () {
  134-		return source;
  135-	}
  136-
  137-	public void setSource (Bone source) {
  138-		if (source == null) throw new IllegalArgumentException("source cannot be null.");
  139-		this.source = source;
  140-	}
  141-}
  ```
- [x] [../../spine-cpp/include/spine/TransformConstraint.h:67](../../spine-cpp/include/spine/TransformConstraint.h#L67) void TransformConstraint::setSource(Bone * source) // takes nullable parameter 'source': Bone *
  ```cpp
  ../../spine-cpp/src/spine/TransformConstraint.cpp:138
  138:void TransformConstraint::setSource(Bone *source) {
  139-	_source = source;
  140-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/TransformConstraint.java:137
  137:	public void setSource (Bone source) {
  138-		if (source == null) throw new IllegalArgumentException("source cannot be null.");
  139-		this.source = source;
  140-	}
  141-}
  ```
- [x] [../../spine-cpp/include/spine/TransformConstraintData.h:260](../../spine-cpp/include/spine/TransformConstraintData.h#L260) Constraint * TransformConstraintData::create(Skeleton & skeleton) // returns nullable pointer: Constraint *
  ```cpp
  ../../spine-cpp/src/spine/TransformConstraintData.cpp:353
  353:Constraint *TransformConstraintData::create(Skeleton &skeleton) {
  354-	return new (__FILE__, __LINE__) TransformConstraint(*this, skeleton);
  355-}
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/TransformConstraintData.java:52
  52:	public TransformConstraint create (Skeleton skeleton) {
  53-		return new TransformConstraint(this, skeleton);
  54-	}
  55-
  56-	/** The bones that will be modified by this transform constraint. */
  57-	public Array<BoneData> getBones () {
  58-		return bones;
  59-	}
  60-
  61-	/** The bone whose world transform will be copied to the constrained bones. */
  ```
- [x] [../../spine-cpp/include/spine/TransformConstraintData.h:266](../../spine-cpp/include/spine/TransformConstraintData.h#L266) BoneData * TransformConstraintData::getSource() // returns nullable pointer: BoneData *
  ```cpp
  ../../spine-cpp/src/spine/TransformConstraintData.cpp:69
  69:BoneData *TransformConstraintData::getSource() {
  70-	return _source;
  71-}
  72-
  73-void TransformConstraintData::setSource(BoneData *source) {
  74-	_source = source;
  75-}
  76-
  77-float TransformConstraintData::getOffsetRotation() {
  78-	return _offsets[ROTATION];
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/TransformConstraintData.java:62
  62:	public BoneData getSource () {
  63-		return source;
  64-	}
  65-
  66-	public void setSource (BoneData source) {
  67-		if (source == null) throw new IllegalArgumentException("source cannot be null.");
  68-		this.source = source;
  69-	}
  70-
  71-	/** An offset added to the constrained bone rotation. */
  ```
- [x] [../../spine-cpp/include/spine/TransformConstraintData.h:267](../../spine-cpp/include/spine/TransformConstraintData.h#L267) void TransformConstraintData::setSource(BoneData * source) // takes nullable parameter 'source': BoneData *
  ```cpp
  ../../spine-cpp/src/spine/TransformConstraintData.cpp:73
  73:void TransformConstraintData::setSource(BoneData *source) {
  74-	_source = source;
  75-}
  76-
  77-float TransformConstraintData::getOffsetRotation() {
  78-	return _offsets[ROTATION];
  79-}
  80-
  81-void TransformConstraintData::setOffsetRotation(float offsetRotation) {
  82-	_offsets[ROTATION] = offsetRotation;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/TransformConstraintData.java:66
  66:	public void setSource (BoneData source) {
  67-		if (source == null) throw new IllegalArgumentException("source cannot be null.");
  68-		this.source = source;
  69-	}
  70-
  71-	/** An offset added to the constrained bone rotation. */
  72-	public float getOffsetRotation () {
  73-		return offsets[ROTATION];
  74-	}
  75-
  ```
- [x] [../../spine-cpp/include/spine/VertexAttachment.h:89](../../spine-cpp/include/spine/VertexAttachment.h#L89) Attachment * VertexAttachment::getTimelineAttachment() // returns nullable pointer: Attachment *
  ```cpp
  ../../spine-cpp/src/spine/VertexAttachment.cpp:148
  148:Attachment *VertexAttachment::getTimelineAttachment() {
  149-	return _timelineAttachment;
  150-}
  151-
  152-void VertexAttachment::setTimelineAttachment(Attachment *attachment) {
  153-	_timelineAttachment = attachment;
  154-}
  155-
  156-int VertexAttachment::getNextID() {
  157-	static int nextID = 0;
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/VertexAttachment.java:182
  182:	public @Null Attachment getTimelineAttachment () {
  183-		return timelineAttachment;
  184-	}
  185-
  186-	/** @param timelineAttachment May be null if no attachment-specific timelines should be applied. */
  187-	public void setTimelineAttachment (Attachment timelineAttachment) {
  188-		this.timelineAttachment = timelineAttachment;
  189-	}
  190-
  191-	/** Returns a unique ID for this attachment. */
  ```
- [x] [../../spine-cpp/include/spine/VertexAttachment.h:91](../../spine-cpp/include/spine/VertexAttachment.h#L91) void VertexAttachment::setTimelineAttachment(Attachment * attachment) // takes nullable parameter 'attachment': Attachment *
  ```cpp
  ../../spine-cpp/src/spine/VertexAttachment.cpp:152
  152:void VertexAttachment::setTimelineAttachment(Attachment *attachment) {
  153-	_timelineAttachment = attachment;
  154-}
  155-
  156-int VertexAttachment::getNextID() {
  157-	static int nextID = 0;
  158-	return nextID++;
  159-}
  160-
  161-void VertexAttachment::copyTo(VertexAttachment *other) {
  ```
  ```java
  ../../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/attachments/VertexAttachment.java:187
  187:	public void setTimelineAttachment (Attachment timelineAttachment) {
  188-		this.timelineAttachment = timelineAttachment;
  189-	}
  190-
  191-	/** Returns a unique ID for this attachment. */
  192-	public int getId () {
  193-		return id;
  194-	}
  195-
  196-	static private synchronized int nextID () {
  ```
- [x] [../../spine-cpp/include/spine/VertexAttachment.h:93](../../spine-cpp/include/spine/VertexAttachment.h#L93) void VertexAttachment::copyTo(VertexAttachment * other) // takes nullable parameter 'other': VertexAttachment *
  ```cpp
  ../../spine-cpp/src/spine/VertexAttachment.cpp:161
  161:void VertexAttachment::copyTo(VertexAttachment *other) {
  162-	other->_bones.clearAndAddAll(this->_bones);
  163-	other->_vertices.clearAndAddAll(this->_vertices);
  164-	other->_worldVerticesLength = this->_worldVerticesLength;
  165-	other->_timelineAttachment = this->_timelineAttachment;
  166-}
  ```
  ```java
  NOT FOUND - searched for class "VertexAttachment" (from C++ "VertexAttachment") and method "copyTo" across all Java files
  ```
