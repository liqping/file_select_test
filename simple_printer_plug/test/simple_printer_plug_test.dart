import 'package:flutter_test/flutter_test.dart';
import 'package:simple_printer_plug/simple_printer_plug.dart';
import 'package:simple_printer_plug/simple_printer_plug_platform_interface.dart';
import 'package:simple_printer_plug/simple_printer_plug_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockSimplePrinterPlugPlatform
    with MockPlatformInterfaceMixin
    implements SimplePrinterPlugPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
  @override
  Future<String?> selectPrinter() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }

}

void main() {
  final SimplePrinterPlugPlatform initialPlatform = SimplePrinterPlugPlatform.instance;

  test('$MethodChannelSimplePrinterPlug is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelSimplePrinterPlug>());
  });

  test('getPlatformVersion', () async {
    SimplePrinterPlug simplePrinterPlugPlugin = SimplePrinterPlug();
    MockSimplePrinterPlugPlatform fakePlatform = MockSimplePrinterPlugPlatform();
    SimplePrinterPlugPlatform.instance = fakePlatform;

    expect(await simplePrinterPlugPlugin.getPlatformVersion(), '42');
  });
}
