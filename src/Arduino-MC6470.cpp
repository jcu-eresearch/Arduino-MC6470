#include "Arduino-MC6470.h"

ArduinoMC6470::ArduinoMC6470(TwoWire *i2c, MC6470_Address_e address)
{
    this->i2c = i2c;
    dev.ctx = this;
    MC6470_Init(&dev, address);
};

ArduinoMC6470::~ArduinoMC6470()
{
};

uint32_t ArduinoMC6470::begin()
{
    return !MC6470_IS_ERROR(MC6470_begin(&dev));
};


void ArduinoMC6470::setStream(Stream *output)
{
    this->output = output;
};

uint32_t ArduinoMC6470::getData(MC6470_MagReading &mag_data, MC6470_AccelReading &accel_data)
{
    uint32_t result = 0;
    result |= MC6470_getData(&dev, &mag_data, &accel_data);
    return result;
};

uint32_t ArduinoMC6470::readIDs()
{
    uint32_t result = 0;
    result |= MC6470_check_ids(&dev);
    return result;
}