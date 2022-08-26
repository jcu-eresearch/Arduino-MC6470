/*
 * An Arduino library for the mCube MC6470 6-axis eCompass. 
 * Copyright (C) 2022  eResearch, James Cook University
 * Author: NigelB
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 */

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