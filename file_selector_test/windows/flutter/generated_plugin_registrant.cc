//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <file_selector_windows/file_selector_windows.h>
#include <simple_printer_plug/simple_printer_plug_plugin_c_api.h>

void RegisterPlugins(flutter::PluginRegistry* registry) {
  FileSelectorWindowsRegisterWithRegistrar(
      registry->GetRegistrarForPlugin("FileSelectorWindows"));
  SimplePrinterPlugPluginCApiRegisterWithRegistrar(
      registry->GetRegistrarForPlugin("SimplePrinterPlugPluginCApi"));
}
