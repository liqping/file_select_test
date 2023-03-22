#include "include/simple_printer_plug/simple_printer_plug_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "simple_printer_plug_plugin.h"

void SimplePrinterPlugPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  simple_printer_plug::SimplePrinterPlugPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
