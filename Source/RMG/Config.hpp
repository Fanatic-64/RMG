#ifndef CONFIG_HPP
#define CONFIG_HPP

#define WINDOW_TITLE "Rosalie's Mupen GUI"
#define WINDOW_WIDGET_SIZE_W 640
#define WINDOW_WIDGET_SIZE_H 480

#define APP_URL_SUPPORT "https://discord.gg/PdFNesY"
#define APP_URL_HOMEPAGE "https://github.com/Rosalie241/RMG"

#define APP_LOG_DIR "Log"
#define APP_LOG_FILE APP_LOG_DIR"""/RMG.txt"

#define APP_SETTINGS_ORG "rosalie"
#define APP_SETTINGS_NAME WINDOW_TITLE
#define APP_SETTINGS_GEOMETRY "geometry"

#define APP_ROMSEARCHER_MAX 50

#ifdef _WIN32
#define MUPEN_CORE_FILE "Core\\mupen64plus.dll"
#define SO_EXT "dll"
#else // Unix
#define MUPEN_CORE_FILE "Core/libmupen64plus.so.2.0.0"
#define SO_EXT "so"
#endif
#define MUPEN_CONFIG_DIR "Config"
#define MUPEN_DATA_DIR "Data"
#define MUPEN_PLUGIN_RSP "Plugin/RSP/mupen64plus-rsp-hle.""" SO_EXT
#define MUPEN_PLUGIN_GFX "Plugin/GFX/mupen64plus-video-GLideN64.""" SO_EXT
#define MUPEN_PLUGIN_AUDIO "Plugin/Audio/mupen64plus-audio-sdl.""" SO_EXT
#define MUPEN_PLUGIN_INPUT "Plugin/Input/mupen64plus-input-raphnetraw.""" SO_EXT

#endif // CONFIG_HPP
