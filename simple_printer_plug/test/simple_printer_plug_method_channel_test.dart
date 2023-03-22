import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:simple_printer_plug/simple_printer_plug_method_channel.dart';

void main() {
  MethodChannelSimplePrinterPlug platform = MethodChannelSimplePrinterPlug();
  const MethodChannel channel = MethodChannel('simple_printer_plug');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.getPlatformVersion(), '42');
  });
}
