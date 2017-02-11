EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:Altera
LIBS:analog_devices
LIBS:brooktre
LIBS:cmos_ieee
LIBS:dc-dc
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:ir
LIBS:Lattice
LIBS:logo
LIBS:maxim
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:motor_drivers
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:Oscillators
LIBS:Power_Management
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:ttl_ieee
LIBS:video
LIBS:Xicor
LIBS:Zilog
LIBS:STM32F4-MotherBoard_1.0.2-cache
LIBS:STM32F4-MotherBoard_3.0.0-cache
LIBS:STM32F4-MotherBoard_5.0.0-cache
EELAYER 25 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 14857 1944 500  150 
U 589AA5CF
F0 "power" 79
F1 "power.sch" 79
$EndSheet
$Sheet
S 14851 2334 546  228 
U 589AA5D3
F0 "CAN" 79
F1 "CAN.sch" 79
$EndSheet
$Sheet
S 14923 2856 528  188 
U 589AA672
F0 "RS-232" 79
F1 "RS-232.sch" 79
$EndSheet
$Sheet
S 15031 3304 500  176 
U 589AA67C
F0 "SW" 79
F1 "SW.sch" 79
$EndSheet
$Sheet
S 15072 3762 516  162 
U 589AA689
F0 "DIO-ADC" 60
F1 "DIO-ADC.sch" 60
$EndSheet
$Sheet
S 15035 4184 508  150 
U 589AA6A8
F0 "Display" 79
F1 "Display.sch" 79
$EndSheet
$Sheet
S 15061 4647 552  165 
U 589AA7A7
F0 "ST-Link" 79
F1 "ST-Link.sch" 79
$EndSheet
$Comp
L STM32F407VG U?
U 1 1 589AAFA6
P 7650 5850
F 0 "U?" H 7650 5850 50  0000 C CNN
F 1 "STM32F407VG" H 7650 5950 50  0000 C CNN
F 2 "TQFP100" H 7650 5750 50  0000 C CNN
F 3 "" H 7650 5850 50  0000 C CNN
	1    7650 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 2850 8350 2800
Wire Wire Line
	8350 2800 6850 2800
Wire Wire Line
	6850 2550 6850 2850
Wire Wire Line
	7150 2850 7150 2800
Connection ~ 7150 2800
Wire Wire Line
	7450 2850 7450 2800
Connection ~ 7450 2800
Wire Wire Line
	7750 2850 7750 2800
Connection ~ 7750 2800
Wire Wire Line
	8050 2850 8050 2800
Connection ~ 8050 2800
Wire Wire Line
	6850 2550 7000 2550
Connection ~ 6850 2800
Text GLabel 7000 2550 2    60   Input ~ 0
power
Text GLabel 2350 5150 0    60   Input ~ 0
ENC0_Z
Text GLabel 2350 5250 0    60   Input ~ 0
ENC1_Z
Text GLabel 2350 5350 0    60   Input ~ 0
ADC0
Text GLabel 2350 5450 0    60   Input ~ 0
ADC1
Text GLabel 2350 5550 0    60   Input ~ 0
XL
Text GLabel 2350 5650 0    60   Input ~ 0
YB
Text GLabel 2350 5750 0    60   Input ~ 0
XR
Text GLabel 2350 5850 0    60   Input ~ 0
YT
Text GLabel 2350 5950 0    60   Input ~ 0
DIO0_4
Text GLabel 2350 6050 0    60   Input ~ 0
RS-232(PC)_TX
Text GLabel 2350 6150 0    60   Input ~ 0
RS-232(PC)_RX
Text GLabel 2350 6250 0    60   Input ~ 0
DIO0_5
Text GLabel 2350 6350 0    60   Input ~ 0
DIO0_6
Text GLabel 2350 6450 0    60   Input ~ 0
SWDIO
Text GLabel 2350 6550 0    60   Input ~ 0
SWCLK
Text GLabel 2350 6650 0    60   Input ~ 0
LED
Text GLabel 2350 6950 0    60   Input ~ 0
ADC2
Text GLabel 2350 7050 0    60   Input ~ 0
ADC3
Text GLabel 2350 7250 0    60   Input ~ 0
SWO
Text GLabel 2350 7350 0    60   Input ~ 0
ENC0_A
Text GLabel 2350 7450 0    60   Input ~ 0
ENC0_B
Text GLabel 2350 7550 0    60   Input ~ 0
DIO0_7
Text GLabel 2350 7650 0    60   Input ~ 0
DIO0_0
Text GLabel 2350 7750 0    60   Input ~ 0
CAN_RX
Text GLabel 2350 7850 0    60   Input ~ 0
CAN_TX
Text GLabel 2350 7950 0    60   Input ~ 0
pushSW
Text GLabel 2350 8050 0    60   Input ~ 0
DIO0_2
Text GLabel 2350 8150 0    60   Input ~ 0
DIO0_3
Text GLabel 12950 6950 2    60   Input ~ 0
DIO0_1
Text GLabel 12950 7050 2    60   Input ~ 0
ADC4
Text GLabel 12950 7150 2    60   Input ~ 0
ADC5
Text GLabel 12950 7250 2    60   Input ~ 0
DIO1_6
Text GLabel 12950 7350 2    60   Input ~ 0
ADC6
Text GLabel 12950 7450 2    60   Input ~ 0
ADC7
Text GLabel 12950 7550 2    60   Input ~ 0
RS-232(Controller)_TX
Text GLabel 12950 7650 2    60   Input ~ 0
RS-232(Controller)_RX
Text GLabel 12950 7750 2    60   Input ~ 0
DIO1_0
Text GLabel 12950 7850 2    60   Input ~ 0
DIO1_1
Text GLabel 12950 7950 2    60   Input ~ 0
RotarySW0
Text GLabel 12950 8150 2    60   Input ~ 0
RotarySW1
Text GLabel 12950 8050 2    60   Input ~ 0
DIO1_2
NoConn ~ 12650 8250
NoConn ~ 12650 8350
NoConn ~ 12650 8450
Wire Wire Line
	12950 6950 12650 6950
Wire Wire Line
	12650 7050 12950 7050
Wire Wire Line
	12950 7150 12650 7150
Wire Wire Line
	12650 7250 12950 7250
Wire Wire Line
	12950 7350 12650 7350
Wire Wire Line
	12650 7450 12950 7450
Wire Wire Line
	12950 7550 12650 7550
Wire Wire Line
	12650 7650 12950 7650
Wire Wire Line
	12950 7750 12650 7750
Wire Wire Line
	12650 7850 12950 7850
Wire Wire Line
	12950 7950 12650 7950
Wire Wire Line
	12650 8050 12950 8050
Wire Wire Line
	12950 8150 12650 8150
Wire Wire Line
	2350 5150 2650 5150
Wire Wire Line
	2350 5250 2650 5250
Wire Wire Line
	2350 5350 2650 5350
Wire Wire Line
	2650 5450 2350 5450
Wire Wire Line
	2350 5550 2650 5550
Wire Wire Line
	2650 5650 2350 5650
Wire Wire Line
	2350 5750 2650 5750
Wire Wire Line
	2350 5850 2650 5850
Wire Wire Line
	2350 5950 2650 5950
Wire Wire Line
	2350 6050 2650 6050
Wire Wire Line
	2650 6150 2350 6150
Wire Wire Line
	2350 6250 2650 6250
Wire Wire Line
	2650 6350 2350 6350
Wire Wire Line
	2350 6450 2650 6450
Wire Wire Line
	2650 6550 2350 6550
Wire Wire Line
	2350 6650 2650 6650
Wire Wire Line
	2350 6950 2650 6950
Wire Wire Line
	2350 7050 2650 7050
Wire Wire Line
	2650 7250 2350 7250
Wire Wire Line
	2350 7350 2650 7350
Wire Wire Line
	2650 7450 2350 7450
Wire Wire Line
	2350 7550 2650 7550
Wire Wire Line
	2350 7650 2650 7650
Wire Wire Line
	2350 7750 2650 7750
Wire Wire Line
	2350 7850 2650 7850
Wire Wire Line
	2650 7950 2350 7950
Wire Wire Line
	2350 8050 2650 8050
Wire Wire Line
	2650 8150 2350 8150
Wire Wire Line
	2350 8250 2650 8250
Wire Wire Line
	2650 8350 2350 8350
Wire Wire Line
	2350 8450 2650 8450
Wire Wire Line
	12650 5150 12950 5150
Wire Wire Line
	12650 5250 12950 5250
Wire Wire Line
	12650 5350 12950 5350
Wire Wire Line
	12950 5450 12650 5450
Wire Wire Line
	12650 5550 12950 5550
Wire Wire Line
	12950 5650 12650 5650
Wire Wire Line
	12650 5750 12950 5750
Wire Wire Line
	12650 5850 12950 5850
Wire Wire Line
	12650 5950 12950 5950
Wire Wire Line
	12650 6050 12950 6050
Wire Wire Line
	12950 6150 12650 6150
Wire Wire Line
	12650 6250 12950 6250
Wire Wire Line
	12950 6350 12650 6350
Wire Wire Line
	12650 6450 12950 6450
Wire Wire Line
	12950 6550 12650 6550
Wire Wire Line
	12650 6650 12950 6650
Text GLabel 12950 5150 2    60   Input ~ 0
FSMC_D2
Text GLabel 12950 5250 2    60   Input ~ 0
FSMC_D3
Text GLabel 12950 5350 2    60   Input ~ 0
DIO1_5
Text GLabel 12950 5450 2    60   Input ~ 0
RST
Text GLabel 12950 5550 2    60   Input ~ 0
RD
Text GLabel 12950 5650 2    60   Input ~ 0
WR
Text GLabel 12950 5750 2    60   Input ~ 0
DIO1_7
Text GLabel 12950 5850 2    60   Input ~ 0
CS
Text GLabel 12950 5950 2    60   Input ~ 0
FSMC_D13
Text GLabel 12950 6050 2    60   Input ~ 0
FSMC_D14
Text GLabel 12950 6150 2    60   Input ~ 0
FSMC_D15
Text GLabel 12950 6350 2    60   Input ~ 0
ENC1_A
Text GLabel 12950 6250 2    60   Input ~ 0
RS
Text GLabel 12950 6450 2    60   Input ~ 0
ENC1_B
Text GLabel 12950 6550 2    60   Input ~ 0
FSMC_D0
Text GLabel 12950 6650 2    60   Input ~ 0
FSMC_D1
Wire Wire Line
	12650 3350 12950 3350
Wire Wire Line
	12650 3450 12950 3450
Wire Wire Line
	12650 3550 12950 3550
Wire Wire Line
	12950 3650 12650 3650
Wire Wire Line
	12650 3750 12950 3750
Wire Wire Line
	12950 3850 12650 3850
Wire Wire Line
	12650 3950 12950 3950
Wire Wire Line
	12650 4050 12950 4050
Wire Wire Line
	12650 4150 12950 4150
Wire Wire Line
	12650 4250 12950 4250
Wire Wire Line
	12950 4350 12650 4350
Wire Wire Line
	12650 4450 12950 4450
Wire Wire Line
	12950 4550 12650 4550
Wire Wire Line
	12650 4650 12950 4650
Wire Wire Line
	12950 4750 12650 4750
Wire Wire Line
	12650 4850 12950 4850
Text GLabel 12950 3350 2    60   Input ~ 0
RotarySW2
Text GLabel 12950 3450 2    60   Input ~ 0
RotarySW3
Text GLabel 12950 3550 2    60   Input ~ 0
DIO1_3
Text GLabel 12950 3650 2    60   Input ~ 0
DIO1_4
Text GLabel 12950 3750 2    60   Input ~ 0
ENC2_Z
Text GLabel 12950 3850 2    60   Input ~ 0
ENC2_A
Text GLabel 12950 3950 2    60   Input ~ 0
ENC2_B
Text GLabel 12950 4050 2    60   Input ~ 0
FSMC_D4
Text GLabel 12950 4150 2    60   Input ~ 0
FSMC_D5
Text GLabel 12950 4250 2    60   Input ~ 0
FSMC_D6
Text GLabel 12950 4350 2    60   Input ~ 0
FSMC_D7
Text GLabel 12950 4550 2    60   Input ~ 0
FSMC_D9
Text GLabel 12950 4450 2    60   Input ~ 0
FSMC_D8
Text GLabel 12950 4650 2    60   Input ~ 0
FSMC_D10
Text GLabel 12950 4750 2    60   Input ~ 0
FSMC_D11
Text GLabel 12950 4850 2    60   Input ~ 0
FSMC_D12
Wire Wire Line
	2650 3750 2350 3750
Wire Wire Line
	2350 4350 2650 4350
Text GLabel 2350 3750 0    60   Input ~ 0
OSC_IN
Text GLabel 2350 4350 0    60   Input ~ 0
OSC_OUT
Wire Wire Line
	2650 7150 1600 7150
Wire Wire Line
	1600 7150 1600 7350
$Comp
L R R?
U 1 1 589F1F0A
P 1600 7500
F 0 "R?" V 1680 7500 50  0000 C CNN
F 1 "100k" V 1600 7500 50  0000 C CNN
F 2 "" V 1530 7500 50  0000 C CNN
F 3 "" H 1600 7500 50  0000 C CNN
	1    1600 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 7650 1600 7750
$Comp
L GND #PWR?
U 1 1 589F1F9C
P 1600 7750
F 0 "#PWR?" H 1600 7500 50  0001 C CNN
F 1 "GND" H 1600 7600 50  0000 C CNN
F 2 "" H 1600 7750 50  0000 C CNN
F 3 "" H 1600 7750 50  0000 C CNN
	1    1600 7750
	1    0    0    -1  
$EndComp
$Sheet
S 15100 5200 600  150 
U 589F74EA
F0 "OSC" 79
F1 "OSC.sch" 79
$EndSheet
$EndSCHEMATC
