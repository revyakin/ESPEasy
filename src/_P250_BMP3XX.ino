#include "_Plugin_Helper.h"
#ifdef USES_P250

// #######################################################################################################
// ############################# Plugin 250 BMP3XX I2C Temp/Pressure Sensor  #############################
// #######################################################################################################

/*******************************************************************************
 * Notes:
 *   Adafruit_BMP3XX Library required (https://github.com/adafruit/Adafruit_BMP3XX)
/******************************************************************************/


# include "src/PluginStructs/P250_data_struct.h"


# define PLUGIN_250
# define PLUGIN_ID_250         250
# define PLUGIN_NAME_250       "Environment - BMP3XX"
# define PLUGIN_VALUENAME1_250 "Temperature"
# define PLUGIN_VALUENAME2_250 "Pressure"


boolean Plugin_250(uint8_t function, struct EventStruct *event, String& string)
{
  boolean success = false;

  switch (function)
  {
    case PLUGIN_DEVICE_ADD:
    {
      Device[++deviceCount].Number           = PLUGIN_ID_250;
      Device[deviceCount].Type               = DEVICE_TYPE_I2C;
      Device[deviceCount].VType              = Sensor_VType::SENSOR_TYPE_TEMP_BARO;
      Device[deviceCount].Ports              = 0;
      Device[deviceCount].PullUpOption       = false;
      Device[deviceCount].InverseLogicOption = false;
      Device[deviceCount].FormulaOption      = true;
      Device[deviceCount].ValueCount         = 2;
      Device[deviceCount].SendDataOption     = true;
      Device[deviceCount].TimerOption        = true;
      Device[deviceCount].GlobalSyncOption   = true;
      break;
    }

    case PLUGIN_GET_DEVICENAME:
    {
      string = F(PLUGIN_NAME_250);
      break;
    }

    case PLUGIN_GET_DEVICEVALUENAMES:
    {
      strcpy_P(ExtraTaskSettings.TaskDeviceValueNames[0], PSTR(PLUGIN_VALUENAME1_250));
      strcpy_P(ExtraTaskSettings.TaskDeviceValueNames[1], PSTR(PLUGIN_VALUENAME2_250));
      break;
    }

    case PLUGIN_WEBFORM_SHOW_I2C_PARAMS:
    {
      uint8_t choice = PCONFIG(0);

      /*
         String options[2];
         options[0] = F("0x76 - default settings (SDO Low)");
         options[1] = F("0x77 - alternate settings (SDO HIGH)");
       */
      int optionValues[2] = { 0x77, 0x76 };
      addFormSelectorI2C(F("i2c_addr"), 2, optionValues, choice);
      addFormNote(F("SDO Low=0x76, High=0x77"));
      break;
    }

    case PLUGIN_WEBFORM_LOAD:
    {
      addFormNumericBox(F("Altitude"), F("plugin_250_BMP3XX_elev"), PCONFIG(1));
      addUnit(F("m"));

      success = true;
      break;
    }

    case PLUGIN_WEBFORM_SAVE:
    {
      PCONFIG(0) = getFormItemInt(F("i2c_addr"));
      PCONFIG(1) = getFormItemInt(F("plugin_250_BMP3XX_elev"));
      success    = true;
      break;
    }

    case PLUGIN_INIT:
    {
      initPluginTaskData(event->TaskIndex, new (std::nothrow) P250_data_struct());
      P250_data_struct *P250_data =
        static_cast<P250_data_struct *>(getPluginTaskData(event->TaskIndex));

      if (nullptr != P250_data) {
        P250_data->initialized = false; // Force re-init just in case the address changed.
        P250_data->begin(PCONFIG(0));
        success = P250_data->initialized;
      }
      break;
    }

    case PLUGIN_READ:
    {
      P250_data_struct *P250_data =
        static_cast<P250_data_struct *>(getPluginTaskData(event->TaskIndex));

      if (nullptr != P250_data)
      {
        P250_data->begin(PCONFIG(0));

        if (!P250_data->initialized) {
          break;
        }

        if (!P250_data->bmp.performReading()) {
          P250_data->initialized = false;
          addLog(LOG_LEVEL_ERROR, F("BMP3XX : Failed to perform reading!"));
          success = false;
          break;
        }

        UserVar[event->BaseVarIndex + 0] = P250_data->bmp.temperature;

        const int elev = PCONFIG(1);
        if (elev != 0)
        {
          UserVar[event->BaseVarIndex + 1] = pressureElevation(P250_data->bmp.pressure / 100.0f, elev);
        } else {
          UserVar[event->BaseVarIndex + 1] = P250_data->bmp.pressure / 100.0f;
        }
      }

      success = true;
      break;
    }
  }
  return success;
}

#endif // ifdef USES_P250
