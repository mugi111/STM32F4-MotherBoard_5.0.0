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
Sheet 3 12
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
L MCP2551-I/SN U4
U 1 1 58A2CD9A
P 5450 3500
F 0 "U4" H 5050 3850 50  0000 L CNN
F 1 "MCP2551-I/SN" H 5550 3850 50  0000 L CNN
F 2 "SO-8" H 5450 3500 50  0000 C CIN
F 3 "" H 5450 3500 50  0000 C CNN
	1    5450 3500
	1    0    0    -1  
$EndComp
Text GLabel 4500 3400 0    60   Input ~ 0
CAN_TX
Text GLabel 4500 3300 0    60   Input ~ 0
CAN_RX
Wire Wire Line
	4500 3300 4950 3300
Wire Wire Line
	4950 3400 4500 3400
$Comp
L RJ45 J1
U 1 1 58A2F3E9
P 7200 2750
F 0 "J1" H 7400 3250 50  0000 C CNN
F 1 "RJ45" H 7050 3250 50  0000 C CNN
F 2 "" H 7200 2750 50  0000 C CNN
F 3 "" H 7200 2750 50  0000 C CNN
	1    7200 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3400 7450 3200
Wire Wire Line
	7350 3200 7350 3250
Wire Wire Line
	7350 3250 7250 3250
Wire Wire Line
	7250 3250 7250 3200
Wire Wire Line
	7300 3250 7300 3700
Connection ~ 7300 3250
Wire Wire Line
	7150 3200 7150 3250
Wire Wire Line
	7150 3250 7050 3250
Wire Wire Line
	7050 3250 7050 3200
Wire Wire Line
	7100 3250 7100 3350
Wire Wire Line
	6400 2800 6400 3350
Connection ~ 7100 3250
Wire Wire Line
	6850 3200 6850 3250
Wire Wire Line
	6850 3250 6950 3250
Wire Wire Line
	6950 3250 6950 3200
Wire Wire Line
	6900 3250 6900 3300
Wire Wire Line
	6900 3300 6600 3300
Wire Wire Line
	6600 3300 6600 2800
Connection ~ 6900 3250
Wire Wire Line
	6400 3350 7100 3350
Wire Wire Line
	7550 3200 7550 3600
Wire Wire Line
	9100 3600 5950 3600
$Comp
L RJ45 J2
U 1 1 58A2F54B
P 8750 2750
F 0 "J2" H 8950 3250 50  0000 C CNN
F 1 "RJ45" H 8600 3250 50  0000 C CNN
F 2 "" H 8750 2750 50  0000 C CNN
F 3 "" H 8750 2750 50  0000 C CNN
	1    8750 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 3200 8400 3250
Wire Wire Line
	8400 3250 8500 3250
Wire Wire Line
	8500 3250 8500 3200
Wire Wire Line
	8600 3200 8600 3250
Wire Wire Line
	8600 3250 8700 3250
Wire Wire Line
	8700 3250 8700 3200
Wire Wire Line
	8450 3250 8450 3300
Wire Wire Line
	8450 3300 8150 3300
Wire Wire Line
	8150 3300 8150 2800
Connection ~ 8450 3250
Wire Wire Line
	8650 3250 8650 3350
Wire Wire Line
	8650 3350 7950 3350
Wire Wire Line
	7950 3350 7950 2800
Connection ~ 8650 3250
Wire Wire Line
	8800 3200 8800 3250
Wire Wire Line
	8800 3250 8900 3250
Wire Wire Line
	8900 3250 8900 3200
Wire Wire Line
	9000 3200 9000 3400
Wire Wire Line
	9100 3200 9100 3600
Wire Wire Line
	8850 3250 8850 3700
Connection ~ 7450 3400
Connection ~ 8850 3250
Wire Wire Line
	9000 3400 5950 3400
Connection ~ 7550 3600
$Comp
L GND #PWR027
U 1 1 58A2F791
P 7300 3700
F 0 "#PWR027" H 7300 3450 50  0001 C CNN
F 1 "GND" H 7300 3550 50  0000 C CNN
F 2 "" H 7300 3700 50  0000 C CNN
F 3 "" H 7300 3700 50  0000 C CNN
	1    7300 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 58A2F7AB
P 8850 3700
F 0 "#PWR028" H 8850 3450 50  0001 C CNN
F 1 "GND" H 8850 3550 50  0000 C CNN
F 2 "" H 8850 3700 50  0000 C CNN
F 3 "" H 8850 3700 50  0000 C CNN
	1    8850 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2450 7800 2400
Wire Wire Line
	7800 2400 7750 2400
Wire Wire Line
	9300 2400 9350 2400
Wire Wire Line
	9350 2400 9350 2450
$Comp
L GND #PWR029
U 1 1 58A2F85E
P 7800 2450
F 0 "#PWR029" H 7800 2200 50  0001 C CNN
F 1 "GND" H 7800 2300 50  0000 C CNN
F 2 "" H 7800 2450 50  0000 C CNN
F 3 "" H 7800 2450 50  0000 C CNN
	1    7800 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR030
U 1 1 58A2F879
P 9350 2450
F 0 "#PWR030" H 9350 2200 50  0001 C CNN
F 1 "GND" H 9350 2300 50  0000 C CNN
F 2 "" H 9350 2450 50  0000 C CNN
F 3 "" H 9350 2450 50  0000 C CNN
	1    9350 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3700 4850 3700
Wire Wire Line
	4850 3700 4850 3800
$Comp
L R R7
U 1 1 58A2F8FF
P 4850 3950
F 0 "R7" V 4930 3950 50  0000 C CNN
F 1 "10k" V 4850 3950 50  0000 C CNN
F 2 "" V 4780 3950 50  0000 C CNN
F 3 "" H 4850 3950 50  0000 C CNN
	1    4850 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4100 4850 4150
$Comp
L GND #PWR031
U 1 1 58A2F983
P 4850 4150
F 0 "#PWR031" H 4850 3900 50  0001 C CNN
F 1 "GND" H 4850 4000 50  0000 C CNN
F 2 "" H 4850 4150 50  0000 C CNN
F 3 "" H 4850 4150 50  0000 C CNN
	1    4850 4150
	1    0    0    -1  
$EndComp
NoConn ~ 4950 3600
Wire Wire Line
	5450 3100 5450 3000
$Comp
L +5V #PWR032
U 1 1 58A58045
P 5450 3000
F 0 "#PWR032" H 5450 2850 50  0001 C CNN
F 1 "+5V" H 5450 3140 50  0000 C CNN
F 2 "" H 5450 3000 50  0000 C CNN
F 3 "" H 5450 3000 50  0000 C CNN
	1    5450 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3050 6000 3050
Wire Wire Line
	6000 3050 6000 3950
Connection ~ 5450 3050
Wire Wire Line
	6000 3950 5950 3950
$Comp
L C C20
U 1 1 58A5811F
P 5800 3950
F 0 "C20" H 5825 4050 50  0000 L CNN
F 1 "C" H 5825 3850 50  0000 L CNN
F 2 "" H 5838 3800 50  0000 C CNN
F 3 "" H 5800 3950 50  0000 C CNN
	1    5800 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 3950 5450 3950
Wire Wire Line
	5450 3900 5450 4000
Connection ~ 5450 3950
$Comp
L GND #PWR033
U 1 1 58A581D8
P 5450 4000
F 0 "#PWR033" H 5450 3750 50  0001 C CNN
F 1 "GND" H 5450 3850 50  0000 C CNN
F 2 "" H 5450 4000 50  0000 C CNN
F 3 "" H 5450 4000 50  0000 C CNN
	1    5450 4000
	1    0    0    -1  
$EndComp
$EndSCHEMATC
