#ifndef CR_FLUTTER_PLUGIN_CR_FLUTTER_LIBSERIALPORT_PLUGIN_H_
#define CR_FLUTTER_PLUGIN_CR_FLUTTER_LIBSERIALPORT_PLUGIN_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

typedef struct _CrFlutterLibserialportPlugin CrFlutterLibserialportPlugin;
typedef struct {
  GObjectClass parent_class;
} CrFlutterLibserialportPluginClass;

FLUTTER_PLUGIN_EXPORT GType cr_flutter_libserialport_plugin_get_type();

FLUTTER_PLUGIN_EXPORT void cr_flutter_libserialport_plugin_register_with_registrar(
    FlPluginRegistrar* registrar);

G_END_DECLS

#endif  // CR_FLUTTER_PLUGIN_CR_FLUTTER_LIBSERIALPORT_PLUGIN_H_
