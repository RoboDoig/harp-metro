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

// Harp App Register Setup.
const size_t reg_count = 2;

// Define register contents.
#pragma pack(push, 1)
struct app_regs_t
{
    volatile uint8_t test_byte;  // app register 0
    volatile uint32_t test_uint; // app register 1
} app_regs;
#pragma pack(pop)

// Define register "specs."
RegSpecs app_reg_specs[reg_count]
{
    {(uint8_t*)&app_regs.test_byte, sizeof(app_regs.test_byte), U8},
    {(uint8_t*)&app_regs.test_uint, sizeof(app_regs.test_uint), U32}
};

// Define register read-and-write handler functions.
RegFnPair reg_handler_fns[reg_count]
{
    {&HarpCore::read_reg_generic, &HarpCore::write_reg_generic},
    {&HarpCore::read_reg_generic, &HarpCore::write_to_read_only_reg_error}
};

int main() {
    gpio_init(13);
    gpio_set_dir(13, GPIO_OUT);
    gpio_init(8);
    gpio_set_dir(8, GPIO_IN);
    while(true) {
        // gpio_put(13, true);
        // sleep_ms(100);
        // gpio_put(13, false);
        // sleep_ms(100);
        gpio_put(13, gpio_get(8));
    }
}