import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'simple_printer_plug_method_channel.dart';

abstract class SimplePrinterPlugPlatform extends PlatformInterface {
  /// Constructs a SimplePrinterPlugPlatform.
  SimplePrinterPlugPlatform() : super(token: _token);

  static final Object _token = Object();

  static SimplePrinterPlugPlatform _instance = MethodChannelSimplePrinterPlug();

  /// The default instance of [SimplePrinterPlugPlatform] to use.
  ///
  /// Defaults to [MethodChannelSimplePrinterPlug].
  static SimplePrinterPlugPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [SimplePrinterPlugPlatform] when
  /// they register themselves.
  static set instance(SimplePrinterPlugPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }


  /// only pop a windows native dialog to select printer
  Future<String?> selectPrinter() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }

}
