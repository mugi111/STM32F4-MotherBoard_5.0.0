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
$Descr A4 11693 8268
encoding utf-8
Sheet 7 11
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L AS021350D U?
U 1 1 589F41CD
P 5600 2850
F 0 "U?" H 5600 3000 60  0000 C CNN
F 1 "AS021350D" H 5600 2900 60  0000 C CNN
F 2 "" H 5600 2850 60  0000 C CNN
F 3 "" H 5600 2850 60  0000 C CNN
	1    5600 2850
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 589F41F4
P 4800 2550
F 0 "#PWR?" H 4800 2400 50  0001 C CNN
F 1 "+3.3V" H 4800 2690 50  0000 C CNN
F 2 "" H 4800 2550 50  0000 C CNN
F 3 "" H 4800 2550 50  0000 C CNN
	1    4800 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2550 4800 3250
Wire Wire Line
	4800 3250 4900 3250
Wire Wire Line
	4900 3150 4800 3150
Connection ~ 4800 3150
Wire Wire Line
	4900 2950 4850 2950
Wire Wire Line
	4850 2950 4850 5100
Wire Wire Line
	4850 3050 4900 3050
Wire Wire Line
	4850 5100 6450 5100
Connection ~ 4850 3050
Wire Wire Line
	6300 4750 6350 4750
$Comp
L R R?
U 1 1 589F424B
P 6450 4550
F 0 "R?" V 6530 4550 50  0000 C CNN
F 1 "510" V 6450 4550 50  0000 C CNN
F 2 "" V 6380 4550 50  0000 C CNN
F 3 "" H 6450 4550 50  0000 C CNN
	1    6450 4550
	1    0    0    -1  
$EndComp
Connection ~ 6350 5100
$Comp
L GND #PWR?
U 1 1 589F4284
P 6350 5150
F 0 "#PWR?" H 6350 4900 50  0001 C CNN
F 1 "GND" H 6350 5000 50  0000 C CNN
F 2 "" H 6350 5150 50  0000 C CNN
F 3 "" H 6350 5150 50  0000 C CNN
	1    6350 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 5100 6450 4700
Wire Wire Line
	6450 4050 6450 4400
Wire Wire Line
	6450 4250 6300 4250
Wire Wire Line
	6300 4150 6450 4150
Connection ~ 6450 4250
Wire Wire Line
	6300 4050 6450 4050
Connection ~ 6450 4150
Wire Wire Line
	6300 4350 7300 4350
Wire Wire Line
	7300 4350 7300 4250
$Comp
L RVAR R?
U 1 1 589F433B
P 7300 4000
F 0 "R?" V 7380 3950 50  0000 C CNN
F 1 "1k" V 7220 4060 50  0000 C CNN
F 2 "" H 7300 4000 50  0000 C CNN
F 3 "" H 7300 4000 50  0000 C CNN
	1    7300 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	7300 3750 7300 3600
$Comp
L +3.3V #PWR?
U 1 1 589F43A6
P 7300 3600
F 0 "#PWR?" H 7300 3450 50  0001 C CNN
F 1 "+3.3V" H 7300 3740 50  0000 C CNN
F 2 "" H 7300 3600 50  0000 C CNN
F 3 "" H 7300 3600 50  0000 C CNN
	1    7300 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3350 4750 3350
Wire Wire Line
	4750 3450 4900 3450
Wire Wire Line
	4900 3550 4750 3550
Wire Wire Line
	4750 3650 4900 3650
Wire Wire Line
	4900 3750 4750 3750
Wire Wire Line
	4750 3850 4900 3850
Wire Wire Line
	4900 3950 4750 3950
Wire Wire Line
	4750 4050 4900 4050
Wire Wire Line
	4900 4150 4750 4150
Wire Wire Line
	4750 4250 4900 4250
Wire Wire Line
	4900 4350 4750 4350
Wire Wire Line
	4750 4450 4900 4450
Wire Wire Line
	4900 4550 4750 4550
Wire Wire Line
	4750 4650 4900 4650
Wire Wire Line
	4900 4750 4750 4750
Wire Wire Line
	4750 4850 4900 4850
Wire Wire Line
	6300 2950 6450 2950
Wire Wire Line
	6450 3050 6300 3050
Wire Wire Line
	6300 3150 6450 3150
Wire Wire Line
	6450 3250 6300 3250
Wire Wire Line
	6450 3650 6300 3650
Wire Wire Line
	6300 3750 6450 3750
Wire Wire Line
	6450 3850 6300 3850
Wire Wire Line
	6300 3950 6450 3950
Wire Wire Line
	6300 3450 7050 3450
Wire Wire Line
	7050 3450 7050 3600
Wire Wire Line
	6300 3550 6400 3550
Wire Wire Line
	6400 3550 6400 3450
Connection ~ 6400 3450
$Comp
L R R?
U 1 1 589F454D
P 7050 3750
F 0 "R?" V 7130 3750 50  0000 C CNN
F 1 "10k" V 7050 3750 50  0000 C CNN
F 2 "" V 6980 3750 50  0000 C CNN
F 3 "" H 7050 3750 50  0000 C CNN
	1    7050 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589F457E
P 7050 4050
F 0 "#PWR?" H 7050 3800 50  0001 C CNN
F 1 "GND" H 7050 3900 50  0000 C CNN
F 2 "" H 7050 4050 50  0000 C CNN
F 3 "" H 7050 4050 50  0000 C CNN
	1    7050 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4050 7050 3900
Text GLabel 6450 3750 2    60   Input ~ 0
XL
Text GLabel 6450 3650 2    60   Input ~ 0
YB
Text GLabel 6450 3950 2    60   Input ~ 0
XR
Text GLabel 6450 3850 2    60   Input ~ 0
YT
Text GLabel 4750 4150 0    60   Input ~ 0
FSMC_D4
Text GLabel 4750 4250 0    60   Input ~ 0
FSMC_D5
Text GLabel 4750 4350 0    60   Input ~ 0
FSMC_D6
Text GLabel 4750 4450 0    60   Input ~ 0
FSMC_D7
Text GLabel 4750 4650 0    60   Input ~ 0
FSMC_D9
Text GLabel 4750 4550 0    60   Input ~ 0
FSMC_D8
Text GLabel 4750 4750 0    60   Input ~ 0
FSMC_D10
Text GLabel 4750 4850 0    60   Input ~ 0
FSMC_D11
Text GLabel 6450 2950 2    60   Input ~ 0
FSMC_D12
Text GLabel 6450 3050 2    60   Input ~ 0
FSMC_D13
Text GLabel 6450 3150 2    60   Input ~ 0
FSMC_D14
Text GLabel 6450 3250 2    60   Input ~ 0
FSMC_D15
Text GLabel 4750 3950 0    60   Input ~ 0
FSMC_D2
Text GLabel 4750 4050 0    60   Input ~ 0
FSMC_D3
Text GLabel 4750 3750 0    60   Input ~ 0
FSMC_D0
Text GLabel 4750 3850 0    60   Input ~ 0
FSMC_D1
Text GLabel 4750 3650 0    60   Input ~ 0
RD
Text GLabel 4750 3550 0    60   Input ~ 0
WR
Text GLabel 4750 3450 0    60   Input ~ 0
RS
Text GLabel 4750 3350 0    60   Input ~ 0
CS
Wire Wire Line
	6350 4750 6350 5150
Text GLabel 6450 3350 2    60   Input ~ 0
RST
Wire Wire Line
	6450 3350 6300 3350
$EndSCHEMATC
