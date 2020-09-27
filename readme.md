### USB Audio

#### Introduction

This is a project of USB DAC. STM32F4 is used for USB-I2S bridge. PCM1798 is DAC. OPA1612 is used as I/V converter and amplifier. A split-rail converter is used to produce negative voltage.

#### Notes (27 Sept 2020)
* PCM1798 should be configured to right-justified to work with 16-bit input.
* Sound quality is poor.
* ~ 100mA more current drawn when negative rail has load when no audio data input (5V 150mA when all component soldered. <50mA when op-amp not soldered).
