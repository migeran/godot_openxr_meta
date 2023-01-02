# Godot FB Scene Capture OpenXR Extension Wrapper

This is an example project showcasing how to implement OpenXR extension wrappers through GDExtensions. It requires the following PR to work: https://github.com/godotengine/godot/pull/68259. After building Godot, godot-headers should be updated following https://github.com/godotengine/godot-headers#updating-headers.

The scene_capture addon implements an extension wrapper for the XR_FB_scene_capture OpenXR extension, which allows requesting a scene capture from the user. To build the addon, the path of the Oculus SDK must be provided to SCons:

```
scons oculus_sdk_path=/path/to/ovr_openxr_mobile_sdk/
```

To build the extension for Android, the following commands need to be run:
```
export ANDROID_NDK_ROOT=/path/to/android/ndk
scons oculus_sdk_path=/path/to/ovr_openxr_mobile_sdk/ platform=android
```

After installing the Android build templates, the MetaOpenXRAndroid plugin also needs to be built:

```
cd project/android/plugins/MetaOpenXRAndroid/
./gradlew build
```

The example project requests a single scene capture upon successful initialization. It also shows how to connect a callback to scene capture completion. It is based on https://github.com/nathanfranke/gdextension and https://github.com/BastiaanOlij/godot4_openxr_demo.

The project has been tested with Oculus Quest 2.