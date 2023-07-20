# Godot FB Scene Capture OpenXR Extension Wrapper

This is an example project showcasing how to implement OpenXR extension wrappers through GDExtensions. It requires the following PR to work: https://github.com/godotengine/godot/pull/68259. After building Godot, godot-headers should be updated following https://github.com/godotengine/godot-headers#updating-headers.

The ```godotopenxr``` addon should be built and added to the project following the instructions at https://github.com/GodotVR/godot_openxr_loaders. Please note that for the sample to work, the commit https://github.com/GodotVR/godot_openxr_loaders/pull/40/commits/7118479c84cacd15612ae27a5914db216ef9ff7f also needs to be applied.

The scene_capture addon implements an extension wrapper for the XR_FB_scene_capture OpenXR extension, which allows requesting a scene capture from the user. To build the addon, the path of the Oculus SDK must be provided to SCons:

```
scons oculus_sdk_path=/path/to/ovr_openxr_mobile_sdk/ target=template_debug
scons oculus_sdk_path=/path/to/ovr_openxr_mobile_sdk/ target=template_release
```

To build the extension for Android, the following commands need to be run:
```
export ANDROID_NDK_ROOT=/path/to/android/ndk
scons oculus_sdk_path=/path/to/ovr_openxr_mobile_sdk/ platform=android target=template_debug
scons oculus_sdk_path=/path/to/ovr_openxr_mobile_sdk/ platform=android target=template_release
```

The example project requests a single scene capture upon successful initialization. It also shows how to connect a callback to scene capture completion. It is based on https://github.com/nathanfranke/gdextension and https://github.com/BastiaanOlij/godot4_openxr_demo, and uses https://github.com/GodotVR/godot_openxr_loaders.

The project has been tested with Oculus Quest 2.