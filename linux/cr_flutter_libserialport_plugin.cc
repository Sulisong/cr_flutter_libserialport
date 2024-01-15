#include "include/cr_flutter_libserialport/cr_flutter_libserialport_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <glib.h>

#define CR_FLUTTER_LIBSERIALPORT_PLUGIN(obj)                                     \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), cr_flutter_libserialport_plugin_get_type(), \
                              CrFlutterLibserialportPlugin))

struct _CrFlutterLibserialportPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(CrFlutterLibserialportPlugin, cr_flutter_libserialport_plugin,
              g_object_get_type())

static void cr_flutter_libserialport_plugin_class_init(
    CrFlutterLibserialportPluginClass* klass) {}

static void cr_flutter_libserialport_plugin_init(
    CrFlutterLibserialportPlugin* self) {}

static gchar* g_self_exe() {
  g_autoptr(GError) error = nullptr;
  g_autofree gchar* self_exe = g_file_read_link("/proc/self/exe", &error);
  if (error) {
    g_critical("g_file_read_link: %s", error->message);
  }
  return g_path_get_dirname(self_exe);
}

void cr_flutter_libserialport_plugin_register_with_registrar(
    FlPluginRegistrar* registrar) {
  CrFlutterLibserialportPlugin* plugin = CR_FLUTTER_LIBSERIALPORT_PLUGIN(
      g_object_new(cr_flutter_libserialport_plugin_get_type(), nullptr));

  g_autofree gchar* self_exe = g_self_exe();
  g_autofree gchar* libserialport_path =
      g_build_filename(self_exe, "lib", "libserialport.so", nullptr);
  g_setenv("LIBSERIALPORT_PATH", libserialport_path, 0);

  g_object_unref(plugin);
}
