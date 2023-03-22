
import 'simple_printer_plug_platform_interface.dart';

class SimplePrinterPlug {
  Future<String?> getPlatformVersion() {
    return SimplePrinterPlugPlatform.instance.getPlatformVersion();
  }

  Future<String?> selectPrinter(){
    return SimplePrinterPlugPlatform.instance.selectPrinter();
  }

}
