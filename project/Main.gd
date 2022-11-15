extends Node3D

var interface : XRInterface

func _ready():
	interface = XRServer.find_interface("OpenXR")
	if interface and interface.is_initialized():
		print("OpenXR initialised successfully")

		var vp : Viewport = get_viewport()
		vp.use_xr = true

		var scene_capture: OpenXRFbSceneCaptureExtensionWrapper = OpenXRFbSceneCaptureExtensionWrapper.get_singleton()
		scene_capture.connect("scene_capture_completed", _on_scene_capture_completed)
		scene_capture.request_scene_capture()
	else:
		print("OpenXR not initialised, please check if your headset is connected")

func _on_scene_capture_completed():
	print("Scene Capture completed")
