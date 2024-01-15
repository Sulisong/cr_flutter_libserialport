import Cocoa
import FlutterMacOS
import Foundation

public class CrFlutterLibserialportPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    setenv("LIBSERIALPORT_PATH", Bundle.main.privateFrameworksPath! + "/libserialport.framework/libserialport", 0);
  }
}
