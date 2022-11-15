#!/usr/bin/env python
from glob import glob
from pathlib import Path

# TODO: Do not copy environment after godot-cpp/test is updated <https://github.com/godotengine/godot-cpp/blob/master/test/SConstruct>.
env = SConscript("godot-cpp/SConstruct")

opts = Variables('custom.py')
opts.Add("oculus_sdk_path", "Path of the Oculus SDK (required for openxr_scene_capture)", "")
opts.Update(env)

# Add source files.
env.Append(CPPPATH=[
    "src/",
    "openxr/include/"
    ])
sources = Glob("src/*.cpp")

if env["oculus_sdk_path"] == "":
    print("Scene capture requires oculus_sdk_path to be specified.")
    Exit(255)
env.Append(CPPPATH=[env["oculus_sdk_path"] + "/OpenXR/Include"])

# Find gdextension path
(extension_path,) = glob("project/addons/*/*.gdextension")

# Find the addon path
addon_path = Path(extension_path).parent

# Find the project name from the gdextension file
project_name = Path(extension_path).stem

# Create the library target
if env["platform"] == "macos":
    library = env.SharedLibrary(
        "{0}/bin/lib{1}.{2}.{3}.framework/{1}.{2}.{3}".format(
            addon_path,
            project_name,
            env["platform"],
            env["target"],
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "{}/bin/lib{}.{}.{}.{}{}".format(
            addon_path,
            project_name,
            env["platform"],
            env["target"],
            env["arch"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )

Default(library)
