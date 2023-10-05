# Digital Clock Firmware
This is the firmware for a digital clock running on Texas Instrument's MSP430 microcontroller.
To build the project you will need:
- `make`
- GNU/Linux GCC (for tests)
- MSP430 GCC
- `mspdebug`

## Build firmware only
```
$ make main.elf
```

## Build firmware and program connected MSP430 Launchpad
```
$ make install.main
```

## Build and run tests
```
$ make test
$ ./test.o
```