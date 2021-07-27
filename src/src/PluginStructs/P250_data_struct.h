#ifndef PLUGINSTRUCTS_P250_DATA_STRUCT_H
#define PLUGINSTRUCTS_P250_DATA_STRUCT_H

#include "../../_Plugin_Helper.h"
#ifdef USES_P250


# include <Adafruit_Sensor.h>
# include <Adafruit_BMP3XX.h>

struct P250_data_struct : public PluginTaskData_base {
  bool begin(uint8_t addr,
             bool    initSettings = true);

  Adafruit_BMP3XX bmp;
  bool initialized = false;
};

#endif // ifdef USES_P250
#endif // ifndef PLUGINSTRUCTS_P250_DATA_STRUCT_H
