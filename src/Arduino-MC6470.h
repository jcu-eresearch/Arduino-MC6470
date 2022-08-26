#ifndef __ARDUINO_MC6470_H__
#define __ARDUINO_MC6470_H__

#if defined(__cplusplus)
extern "C"
{
#endif

#include "mc6470.h"

#if defined(__cplusplus)
}
#endif

#include "Wire.h"

class ArduinoMC6470
{
    friend uint32_t MC6470_I2C_Write(MC6470_Dev_t *dev, MC6470_Address_e address, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length);
    friend uint32_t MC6470_I2C_Read(MC6470_Dev_t *dev, MC6470_Address_e address, MC6470_reg_addr reg_address, uint8_t *buffer, size_t buffer_length);
    friend int MC6470_printf(MC6470_Dev_t *dev, const char *format, ...);
    private:
        MC6470_Dev_t dev;
        Stream *output = nullptr;
        TwoWire *i2c = nullptr;
    public:

   

        ArduinoMC6470(TwoWire *i2c, MC6470_Address_e address);
        ~ArduinoMC6470();
        uint32_t begin();
        void setStream(Stream *output);
        uint32_t getData(MC6470_MagReading &mag_data, MC6470_AccelReading &accel_data);
        uint32_t readIDs();


};

#endif