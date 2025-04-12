#include <cstring>
#include <harp_c_app.h>
#include <harp_synchronizer.h>
#include <core_registers.h>
#include <reg_types.h>
#ifdef DEBUG
    #include <pico/stdlib.h> // for uart printing
    #include <cstdio> // for printf
#endif

// Create device name array.
const uint16_t who_am_i = 1234;
const uint8_t hw_version_major = 1;
const uint8_t hw_version_minor = 0;
const uint8_t assembly_version = 2;
const uint8_t harp_version_major = 2;
const uint8_t harp_version_minor = 0;
const uint8_t fw_version_major = 3;
const uint8_t fw_version_minor = 0;
const uint16_t serial_number = 0xCAFE;