#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"

#include "rgb_lcd.h"

struct Displaystate disp;
struct Displaystate *disp_ptr = &disp;
const char initmsg[17] = "Starting demo...";

void setup()
{
    // Set up i2c, this needs to happen since the lcd library depends on
    // default i2c working
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    // Make the I2C pins available to picotool
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    // Set up Grove LCD monitor
    lcd_init(disp_ptr);
    // Use 16 columns, 2 rows
    lcd_begin(disp_ptr, 16, 2);
    // Initialize cursor to start
    lcd_set_cursor(disp_ptr, 0, 0);
}

int main()
{
    setup();

    for (uint32_t i = 0; i < 16; i++)
    {
        lcd_write(disp_ptr, initmsg[i]);
        sleep_ms(50);
    }
    sleep_ms(2000);

    while (1)
    {
        for (uint32_t i = 0; i < 16; i++)
        {
            lcd_set_cursor(disp_ptr, i, 0);
            lcd_write(disp_ptr, '*');
            sleep_ms(150);
            lcd_set_cursor(disp_ptr, i, 1);
            lcd_write(disp_ptr, '*');
            sleep_ms(150);
        }
        for (int32_t i = 15; i >= 0; i--)
        {
            lcd_set_cursor(disp_ptr, i, 1);
            lcd_write(disp_ptr, ' ');
            sleep_ms(150);
            lcd_set_cursor(disp_ptr, i, 0);
            lcd_write(disp_ptr, ' ');
            sleep_ms(150);
        }
        for (int32_t i = 15; i >= 0; i--)
        {
            lcd_set_cursor(disp_ptr, i, 0);
            lcd_write(disp_ptr, '*');
            sleep_ms(150);
            lcd_set_cursor(disp_ptr, i, 1);
            lcd_write(disp_ptr, '*');
            sleep_ms(150);
        }
        for (uint32_t i = 0; i < 16; i++)
        {
            lcd_set_cursor(disp_ptr, i, 1);
            lcd_write(disp_ptr, ' ');
            sleep_ms(150);
            lcd_set_cursor(disp_ptr, i, 0);
            lcd_write(disp_ptr, ' ');
            sleep_ms(150);
        }
    }

    return 0;
}
