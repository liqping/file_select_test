#include "simple_printer_plug_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>
#include <thread>

namespace simple_printer_plug {

	flutter::FlutterView* flutterView = nullptr;

	// wchar-> utf-8 
	std::string wchar2utf8(LPWSTR wchar) {
		if (wchar == nullptr) {
			return std::string();
		}
		int target_length = ::WideCharToMultiByte(
			CP_UTF8, WC_ERR_INVALID_CHARS, wchar,
			-1, nullptr, 0, nullptr, nullptr);
		if (target_length == 0) {
			return std::string();
		}
		std::string utf8_string;
		utf8_string.resize(target_length);
		int converted_length = ::WideCharToMultiByte(
			CP_UTF8, WC_ERR_INVALID_CHARS, wchar,
			-1, utf8_string.data(),
			target_length, nullptr, nullptr);
		if (converted_length == 0) {
			return std::string();
		}
		return utf8_string;
	}

// static
void SimplePrinterPlugPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "simple_printer_plug",
          &flutter::StandardMethodCodec::GetInstance());

  flutterView = registrar->GetView();

  auto plugin = std::make_unique<SimplePrinterPlugPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

SimplePrinterPlugPlugin::SimplePrinterPlugPlugin() {}

SimplePrinterPlugPlugin::~SimplePrinterPlugPlugin() {}

void SimplePrinterPlugPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
	if (method_call.method_name().compare("selectPrinter") == 0) {

		//// It works fine to uncomment thread code 

		//std::thread([](std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
			// Display the printer dialog box so the user can select the 
//  printer and the number of copies to print.
			BOOL            printDlgReturn = FALSE;
			//HDC                printerDC = NULL;
			PRINTDLG        printDlgInfo = { 0 };
			LPWSTR            localPrinterName = NULL;
			PDEVMODE        returnedDevmode = NULL;
			PDEVMODE        localDevmode = NULL;

			// Initialize the print dialog box's data structure.
			printDlgInfo.lStructSize = sizeof(printDlgInfo);
			printDlgInfo.Flags =
				// Return a printer device context.
				//PD_RETURNDC
				// Don't allow separate print to file.
				// Remove these flags if you want to support this feature.
				PD_HIDEPRINTTOFILE
				| PD_DISABLEPRINTTOFILE
				// Don't allow selecting individual document pages to print.
				// Remove this flag if you want to support this feature.
				| PD_NOSELECTION;

			// Display the printer dialog and retrieve the printer DC.
			printDlgReturn = PrintDlg(&printDlgInfo);

			// Check the return value.
			if (TRUE == printDlgReturn)
			{
				// The user clicked OK so the printer dialog box data 
				//  structure was returned with the user's selections.
				//  Copy the relevant data from the data structure and 
				//  save them to a local data structure.

				//
				// Get the HDC of the selected printer
				//printerDC = printDlgInfo.hDC;

				// In this example, the DEVMODE structure returned by 
				//    the printer dialog box is copied to a local memory
				//    block and a pointer to the printer name that is 
				//    stored in the copied DEVMODE structure is saved.

				//
				//  Lock the handle to get a pointer to the DEVMODE structure.
				returnedDevmode = (PDEVMODE)GlobalLock(printDlgInfo.hDevMode);

				localDevmode = (LPDEVMODE)HeapAlloc(
					GetProcessHeap(),
					HEAP_ZERO_MEMORY | HEAP_GENERATE_EXCEPTIONS,
					returnedDevmode->dmSize);

				if (NULL != localDevmode)
				{
					memcpy(
						(LPVOID)localDevmode,
						(LPVOID)returnedDevmode,
						returnedDevmode->dmSize);

					// Save the printer name from the DEVMODE structure.
					//  This is done here just to illustrate how to access
					//  the name field. The printer name can also be accessed
					//  by referring to the dmDeviceName in the local 
					//  copy of the DEVMODE structure.
					localPrinterName = localDevmode->dmDeviceName;

				}
				// Free the DEVMODE structure returned by the print 
				//  dialog box.
				if (NULL != printDlgInfo.hDevMode)
				{
					GlobalFree(printDlgInfo.hDevMode);
				}

				if (NULL != localPrinterName) {
					auto printName = wchar2utf8(localPrinterName);
					if (!printName.empty()) {
						result->Success(printName);
					}
					else {
						result->Success();
					}

				}
				else
				{
					result->Success();
				}

			}
			else
			{
				// The user cancelled out of the print dialog box.
				result->Success();
			}
		//},std::move(result)).detach();
    } else {
    result->NotImplemented();
  }
}

}  // namespace simple_printer_plug
