#include "../PluginStructs/P250_data_struct.h"

#ifdef USES_P250


// Needed also here for PlatformIO's library finder as the .h file
// is in a directory which is excluded in the src_filter
# include <Adafruit_Sensor.h>
# include <Adafruit_BMP3XX.h>


bool P250_data_struct::begin(uint8_t addr, bool initSettings)
{
  if (!initialized) {
    initialized = bmp.begin_I2C(addr); //, initSettings);

    if (initialized) {
      bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_2X);
      bmp.setPressureOversampling(BMP3_OVERSAMPLING_32X);
      bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_1);
      bmp.setOutputDataRate(BMP3_ODR_3_1_HZ);
    }
  }

  return initialized;
}

#endif // ifdef USES_P250
