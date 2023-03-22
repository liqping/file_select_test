import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'simple_printer_plug_platform_interface.dart';

/// An implementation of [SimplePrinterPlugPlatform] that uses method channels.
class MethodChannelSimplePrinterPlug extends SimplePrinterPlugPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('simple_printer_plug');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }




  @override
  Future<String?> selectPrinter() {
    return methodChannel.invokeMethod<String>('selectPrinter');
  }

}
