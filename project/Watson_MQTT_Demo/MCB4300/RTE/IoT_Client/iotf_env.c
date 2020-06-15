// Environment
#include <string.h>

#define xstr(s) str(s)
#define str(s) #s

char *getenv(const char *name) {

#ifdef IOT_EMBDC_HOME
  if ((strcmp(name, "IOT_EMBDC_HOME")) == 0) {
    return xstr(IOT_EMBDC_HOME);
  }
#endif

#ifdef IOT_EMBDC_LOGGING
  if ((strcmp(name, "IOT_EMBDC_LOGGING")) == 0) {
    return "ON";
  }
#endif

  return NULL;
}
