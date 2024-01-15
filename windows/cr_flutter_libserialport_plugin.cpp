#include "include/cr_flutter_libserialport/cr_flutter_libserialport_plugin.h"
#include <flutter/plugin_registrar_windows.h>
#include <windows.h>

#include <memory>

namespace {

class CrFlutterLibserialportPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  CrFlutterLibserialportPlugin();

  virtual ~CrFlutterLibserialportPlugin();
};

void CrFlutterLibserialportPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto plugin = std::make_unique<CrFlutterLibserialportPlugin>();
  registrar->AddPlugin(std::move(plugin));
}

CrFlutterLibserialportPlugin::CrFlutterLibserialportPlugin() {}

CrFlutterLibserialportPlugin::~CrFlutterLibserialportPlugin() {}

}  // namespace

void CrFlutterLibserialportPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  CrFlutterLibserialportPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
