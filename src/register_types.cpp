#include "register_types.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "openxr_fb_scene_capture_extension_wrapper.h"

using namespace godot;

void scene_capture_initialize(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_CORE)
	{
		ClassDB::register_class<OpenXRFbSceneCaptureExtensionWrapper>();
		OpenXRFbSceneCaptureExtensionWrapper::get_singleton()->register_extension_wrapper();
	}
}

void scene_capture_terminate(ModuleInitializationLevel p_level)
{
}

extern "C"
{
	GDNativeBool GDN_EXPORT scene_capture_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization)
	{
		godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

		init_obj.register_initializer(scene_capture_initialize);
		init_obj.register_terminator(scene_capture_terminate);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_CORE);

		return init_obj.init();
	}
}
