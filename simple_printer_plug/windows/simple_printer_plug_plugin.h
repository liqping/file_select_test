#ifndef FLUTTER_PLUGIN_SIMPLE_PRINTER_PLUG_PLUGIN_H_
#define FLUTTER_PLUGIN_SIMPLE_PRINTER_PLUG_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace simple_printer_plug {

class SimplePrinterPlugPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  SimplePrinterPlugPlugin();

  virtual ~SimplePrinterPlugPlugin();

  // Disallow copy and assign.
  SimplePrinterPlugPlugin(const SimplePrinterPlugPlugin&) = delete;
  SimplePrinterPlugPlugin& operator=(const SimplePrinterPlugPlugin&) = delete;

 private:
  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace simple_printer_plug

#endif  // FLUTTER_PLUGIN_SIMPLE_PRINTER_PLUG_PLUGIN_H_
