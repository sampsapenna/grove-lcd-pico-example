# Grove RGB LCD Raspberry Pi Pico SDK example
An example / demo of scrolling asterisks on screen, outlining the correct
way to set up the LCD using the Pico SDK port of Grove RGB LCD library.

> CAUTION: THOUGH LCD SILKSCREEN MIGHT SUGGEST USING VCC, OR 5V INPUT FOR
> POWER THIS WILL BREAK YOUR PICO MICROCONTROLLER. POWER THE LCD VIA 3.3V
> OUTPUT FROM PICO PIN 36 INSTEAD, TO RUN THE SCREEN @ 3.3 VOLTS. THE
> SCREEN WILL STILL WORK JUST FINE AT LOWER VOLTAGE.

## Getting started
Repository contains `pico sdk` and `grove-lcd-pico` as submodules. Before
compiling run
```bash
git submodule init && git submodule update --recursive
```

## Usage
To build the software run following commands.
```bash
mkdir build
cd build
cmake ..
make
```

Copy the resulting `lcd_example.uf2` on your Pico. Be sure to connect the
correct i2c pins. Raspberry Pi Pico defaults are pins 6 and 7.
