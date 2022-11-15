package com.godot.metaopenxrandroid;

import org.godotengine.godot.Godot;
import java.util.Set;


public class GodotMetaOpenXRAndroid extends org.godotengine.godot.plugin.GodotPlugin{

    public GodotMetaOpenXRAndroid(Godot godot) {
        super(godot);
    }

    @Override
    public String getPluginName() {
        return "MetaOpenXRAndroid";
    }

    @Override
    protected Set<String> getPluginGDNativeLibrariesPaths() {
        return super.getPluginGDNativeLibrariesPaths();
    }
}
