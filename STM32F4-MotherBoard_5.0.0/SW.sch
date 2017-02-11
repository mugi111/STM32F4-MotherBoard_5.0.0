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
Sheet 5 10
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
L +3.3V #PWR?
U 1 1 589F1FF1
P 4250 2200
F 0 "#PWR?" H 4250 2050 50  0001 C CNN
F 1 "+3.3V" H 4250 2340 50  0000 C CNN
F 2 "" H 4250 2200 50  0000 C CNN
F 3 "" H 4250 2200 50  0000 C CNN
	1    4250 2200
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 589F2005
P 4250 2450
F 0 "R?" V 4330 2450 50  0000 C CNN
F 1 "10k" V 4250 2450 50  0000 C CNN
F 2 "" V 4180 2450 50  0000 C CNN
F 3 "" H 4250 2450 50  0000 C CNN
	1    4250 2450
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 589F2031
P 4250 3100
F 0 "SW?" H 4400 3210 50  0000 C CNN
F 1 "SW_PUSH" H 4250 3020 50  0000 C CNN
F 2 "" H 4250 3100 50  0000 C CNN
F 3 "" H 4250 3100 50  0000 C CNN
	1    4250 3100
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 589F206A
P 4550 2700
F 0 "R?" V 4630 2700 50  0000 C CNN
F 1 "1k" V 4550 2700 50  0000 C CNN
F 2 "" V 4480 2700 50  0000 C CNN
F 3 "" H 4550 2700 50  0000 C CNN
	1    4550 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 2200 4250 2300
Wire Wire Line
	4250 2600 4250 2800
Wire Wire Line
	4250 2700 4400 2700
Connection ~ 4250 2700
$Comp
L C_Small C?
U 1 1 589F20A4
P 4900 2950
F 0 "C?" H 4910 3020 50  0000 L CNN
F 1 "0.1uF" H 4910 2870 50  0000 L CNN
F 2 "" H 4900 2950 50  0000 C CNN
F 3 "" H 4900 2950 50  0000 C CNN
	1    4900 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2700 5300 2700
Wire Wire Line
	4900 2700 4900 2850
Connection ~ 4900 2700
Wire Wire Line
	4250 3400 4250 3550
Wire Wire Line
	4900 3050 4900 3550
$Comp
L GND #PWR?
U 1 1 589F2110
P 4250 3550
F 0 "#PWR?" H 4250 3300 50  0001 C CNN
F 1 "GND" H 4250 3400 50  0000 C CNN
F 2 "" H 4250 3550 50  0000 C CNN
F 3 "" H 4250 3550 50  0000 C CNN
	1    4250 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589F212E
P 4900 3550
F 0 "#PWR?" H 4900 3300 50  0001 C CNN
F 1 "GND" H 4900 3400 50  0000 C CNN
F 2 "" H 4900 3550 50  0000 C CNN
F 3 "" H 4900 3550 50  0000 C CNN
	1    4900 3550
	1    0    0    -1  
$EndComp
Text GLabel 5300 2700 2    60   Output ~ 0
PushSW
$Comp
L SW_ROTARY SW?
U 1 1 589F232D
P 6800 2400
F 0 "SW?" H 6800 2400 60  0000 C CNN
F 1 "SW_ROTARY" H 6800 2200 60  0000 C CNN
F 2 "" H 6800 2400 60  0000 C CNN
F 3 "" H 6800 2400 60  0000 C CNN
	1    6800 2400
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 589F2362
P 7550 1650
F 0 "#PWR?" H 7550 1500 50  0001 C CNN
F 1 "+3.3V" H 7550 1790 50  0000 C CNN
F 2 "" H 7550 1650 50  0000 C CNN
F 3 "" H 7550 1650 50  0000 C CNN
	1    7550 1650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 589F2380
P 7550 1950
F 0 "R?" V 7630 1950 50  0000 C CNN
F 1 "10k" V 7550 1950 50  0000 C CNN
F 2 "" V 7480 1950 50  0000 C CNN
F 3 "" H 7550 1950 50  0000 C CNN
	1    7550 1950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 589F23BF
P 7700 1950
F 0 "R?" V 7780 1950 50  0000 C CNN
F 1 "10k" V 7700 1950 50  0000 C CNN
F 2 "" V 7630 1950 50  0000 C CNN
F 3 "" H 7700 1950 50  0000 C CNN
	1    7700 1950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 589F23EA
P 7850 1950
F 0 "R?" V 7930 1950 50  0000 C CNN
F 1 "10k" V 7850 1950 50  0000 C CNN
F 2 "" V 7780 1950 50  0000 C CNN
F 3 "" H 7850 1950 50  0000 C CNN
	1    7850 1950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 589F2414
P 8000 1950
F 0 "R?" V 8080 1950 50  0000 C CNN
F 1 "10k" V 8000 1950 50  0000 C CNN
F 2 "" V 7930 1950 50  0000 C CNN
F 3 "" H 8000 1950 50  0000 C CNN
	1    8000 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2200 8150 2200
Wire Wire Line
	7550 2200 7550 2100
Wire Wire Line
	7700 2100 7700 2300
Wire Wire Line
	7450 2300 8150 2300
Wire Wire Line
	7450 2400 8150 2400
Wire Wire Line
	7850 2400 7850 2100
Wire Wire Line
	8000 2100 8000 2600
Wire Wire Line
	7450 2600 8150 2600
Connection ~ 7550 2200
Connection ~ 7700 2300
Connection ~ 7850 2400
Connection ~ 8000 2600
Wire Wire Line
	7450 2500 7650 2500
Wire Wire Line
	7650 2500 7650 2750
$Comp
L GND #PWR?
U 1 1 589F2548
P 7650 2750
F 0 "#PWR?" H 7650 2500 50  0001 C CNN
F 1 "GND" H 7650 2600 50  0000 C CNN
F 2 "" H 7650 2750 50  0000 C CNN
F 3 "" H 7650 2750 50  0000 C CNN
	1    7650 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 1650 7550 1800
Wire Wire Line
	7550 1750 8000 1750
Wire Wire Line
	8000 1750 8000 1800
Connection ~ 7550 1750
Wire Wire Line
	7850 1800 7850 1750
Connection ~ 7850 1750
Wire Wire Line
	7700 1750 7700 1800
Connection ~ 7700 1750
Text GLabel 8150 2200 2    60   Output ~ 0
RotarySW0
Text GLabel 8150 2300 2    60   Output ~ 0
RotarySW1
Text GLabel 8150 2400 2    60   Output ~ 0
RotarySW2
Text GLabel 8150 2600 2    60   Output ~ 0
RotarySW3
$Comp
L SW_PUSH SW?
U 1 1 589F289A
P 3300 4300
F 0 "SW?" H 3450 4410 50  0000 C CNN
F 1 "Reset" H 3300 4220 50  0000 C CNN
F 2 "" H 3300 4300 50  0000 C CNN
F 3 "" H 3300 4300 50  0000 C CNN
	1    3300 4300
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 589F29F9
P 2900 4550
F 0 "C?" H 2910 4620 50  0000 L CNN
F 1 "0.1uF" H 2910 4470 50  0000 L CNN
F 2 "" H 2900 4550 50  0000 C CNN
F 3 "" H 2900 4550 50  0000 C CNN
	1    2900 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589F2A59
P 2900 4750
F 0 "#PWR?" H 2900 4500 50  0001 C CNN
F 1 "GND" H 2900 4600 50  0000 C CNN
F 2 "" H 2900 4750 50  0000 C CNN
F 3 "" H 2900 4750 50  0000 C CNN
	1    2900 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589F2A8C
P 3700 4750
F 0 "#PWR?" H 3700 4500 50  0001 C CNN
F 1 "GND" H 3700 4600 50  0000 C CNN
F 2 "" H 3700 4750 50  0000 C CNN
F 3 "" H 3700 4750 50  0000 C CNN
	1    3700 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 4750 3700 4300
Wire Wire Line
	3700 4300 3600 4300
Wire Wire Line
	2750 4300 3000 4300
Wire Wire Line
	2900 4300 2900 4450
Wire Wire Line
	2900 4650 2900 4750
Connection ~ 2900 4300
Text GLabel 2750 4300 0    60   Input ~ 0
NRST
Text GLabel 7850 4100 2    60   Output ~ 0
Write
$Comp
L SW_TOGLE_5P SW?
U 1 1 589F8C6F
P 7150 4100
F 0 "SW?" H 7000 4300 60  0000 C CNN
F 1 "WRITE/RUN" H 6950 3950 60  0000 C CNN
F 2 "" H 7250 4100 60  0000 C CNN
F 3 "" H 7250 4100 60  0000 C CNN
	1    7150 4100
	-1   0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 589F8D4E
P 6500 3750
F 0 "#PWR?" H 6500 3600 50  0001 C CNN
F 1 "+3.3V" H 6500 3890 50  0000 C CNN
F 2 "" H 6500 3750 50  0000 C CNN
F 3 "" H 6500 3750 50  0000 C CNN
	1    6500 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3750 6500 4000
Wire Wire Line
	6500 4000 6650 4000
Wire Wire Line
	6650 4200 6500 4200
Wire Wire Line
	6500 4200 6500 4500
Wire Wire Line
	7750 4100 7750 4150
$Comp
L R R?
U 1 1 589F8E1B
P 7750 4300
F 0 "R?" V 7830 4300 50  0000 C CNN
F 1 "10k" V 7750 4300 50  0000 C CNN
F 2 "" V 7680 4300 50  0000 C CNN
F 3 "" H 7750 4300 50  0000 C CNN
	1    7750 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4450 7750 4500
$Comp
L GND #PWR?
U 1 1 589F8EA5
P 7750 4500
F 0 "#PWR?" H 7750 4250 50  0001 C CNN
F 1 "GND" H 7750 4350 50  0000 C CNN
F 2 "" H 7750 4500 50  0000 C CNN
F 3 "" H 7750 4500 50  0000 C CNN
	1    7750 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 4100 7850 4100
Connection ~ 7750 4100
$Comp
L GND #PWR?
U 1 1 589F8F49
P 6500 4500
F 0 "#PWR?" H 6500 4250 50  0001 C CNN
F 1 "GND" H 6500 4350 50  0000 C CNN
F 2 "" H 6500 4500 50  0000 C CNN
F 3 "" H 6500 4500 50  0000 C CNN
	1    6500 4500
	1    0    0    -1  
$EndComp
$EndSCHEMATC
