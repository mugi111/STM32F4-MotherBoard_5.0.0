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
Sheet 4 8
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
L ADM3202 U?
U 1 1 589F654C
P 5550 2900
F 0 "U?" H 5550 3450 60  0000 C CNN
F 1 "ADM3202" H 5550 2450 60  0000 C CNN
F 2 "" H 5450 2900 60  0000 C CNN
F 3 "" H 5450 2900 60  0000 C CNN
	1    5550 2900
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 589F6577
P 4800 2500
F 0 "C?" H 4810 2570 50  0000 L CNN
F 1 "0.1uF" H 4810 2420 50  0000 L CNN
F 2 "" H 4800 2500 50  0000 C CNN
F 3 "" H 4800 2500 50  0000 C CNN
	1    4800 2500
	0    1    1    0   
$EndComp
$Comp
L C_Small C?
U 1 1 589F65AE
P 4800 2800
F 0 "C?" H 4810 2870 50  0000 L CNN
F 1 "0.1uF" H 4810 2720 50  0000 L CNN
F 2 "" H 4800 2800 50  0000 C CNN
F 3 "" H 4800 2800 50  0000 C CNN
	1    4800 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 2800 4950 2800
Wire Wire Line
	4950 2500 4900 2500
Wire Wire Line
	4700 2500 4600 2500
Wire Wire Line
	4600 2500 4600 2700
Wire Wire Line
	4600 2700 4950 2700
Wire Wire Line
	4950 2900 4600 2900
Wire Wire Line
	4600 2900 4600 2800
Wire Wire Line
	4600 2800 4700 2800
Wire Wire Line
	4950 2600 4700 2600
Wire Wire Line
	4700 2600 4700 2200
Wire Wire Line
	4700 2200 5250 2200
$Comp
L C_Small C?
U 1 1 589F661E
P 5350 2200
F 0 "C?" H 5360 2270 50  0000 L CNN
F 1 "0.1uF" H 5360 2120 50  0000 L CNN
F 2 "" H 5350 2200 50  0000 C CNN
F 3 "" H 5350 2200 50  0000 C CNN
	1    5350 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	6150 2500 6250 2500
$Comp
L C_Small C?
U 1 1 589F6660
P 6350 2500
F 0 "C?" H 6360 2570 50  0000 L CNN
F 1 "0.1uF" H 6360 2420 50  0000 L CNN
F 2 "" H 6350 2500 50  0000 C CNN
F 3 "" H 6350 2500 50  0000 C CNN
	1    6350 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	6450 2500 6800 2500
Wire Wire Line
	6150 2600 6550 2600
$Comp
L GND #PWR?
U 1 1 589F66C4
P 6800 2550
F 0 "#PWR?" H 6800 2300 50  0001 C CNN
F 1 "GND" H 6800 2400 50  0000 C CNN
F 2 "" H 6800 2550 50  0000 C CNN
F 3 "" H 6800 2550 50  0000 C CNN
	1    6800 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2600 6550 2500
Wire Wire Line
	6800 2500 6800 2550
Connection ~ 6550 2500
Wire Wire Line
	5450 2200 6200 2200
Wire Wire Line
	6200 2100 6200 2500
Connection ~ 6200 2500
$Comp
L +3.3V #PWR?
U 1 1 589F6792
P 6200 2100
F 0 "#PWR?" H 6200 1950 50  0001 C CNN
F 1 "+3.3V" H 6200 2240 50  0000 C CNN
F 2 "" H 6200 2100 50  0000 C CNN
F 3 "" H 6200 2100 50  0000 C CNN
	1    6200 2100
	1    0    0    -1  
$EndComp
Connection ~ 6200 2200
Wire Wire Line
	4950 3000 4900 3000
$Comp
L C_Small C?
U 1 1 589F67EC
P 4800 3000
F 0 "C?" H 4810 3070 50  0000 L CNN
F 1 "0.1uF" H 4810 2920 50  0000 L CNN
F 2 "" H 4800 3000 50  0000 C CNN
F 3 "" H 4800 3000 50  0000 C CNN
	1    4800 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 3000 4500 3000
$Comp
L GND #PWR?
U 1 1 589F6831
P 4500 3000
F 0 "#PWR?" H 4500 2750 50  0001 C CNN
F 1 "GND" H 4500 2850 50  0000 C CNN
F 2 "" H 4500 3000 50  0000 C CNN
F 3 "" H 4500 3000 50  0000 C CNN
	1    4500 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3100 4600 3100
Wire Wire Line
	4600 3100 4600 3200
Wire Wire Line
	4600 3200 3600 3200
Wire Wire Line
	4950 3200 4700 3200
Wire Wire Line
	4700 3200 4700 3300
Wire Wire Line
	4700 3300 3500 3300
Wire Wire Line
	6150 3100 6300 3100
Wire Wire Line
	6150 3200 6300 3200
Text GLabel 6300 3100 2    60   Input ~ 0
RS-232(PC)_TX
Text GLabel 6300 3200 2    60   Input ~ 0
RS-232(PC)_RX
Text GLabel 6300 3000 2    60   Input ~ 0
RS-232(Controller)_TX
Text GLabel 6300 2900 2    60   Input ~ 0
RS-232(Controller)_RX
Wire Wire Line
	2550 3500 7550 3500
Wire Wire Line
	6150 2800 7550 2800
Wire Wire Line
	7450 3400 2650 3400
Wire Wire Line
	6150 2900 6300 2900
Wire Wire Line
	6300 3000 6150 3000
$Comp
L RJ12 J?
U 1 1 589F6AEB
P 3400 2650
F 0 "J?" H 3600 3150 50  0000 C CNN
F 1 "RJ12" H 3250 3150 50  0000 C CNN
F 2 "" H 3400 2650 50  0000 C CNN
F 3 "" H 3400 2650 50  0000 C CNN
	1    3400 2650
	1    0    0    -1  
$EndComp
NoConn ~ 3900 2250
NoConn ~ 3900 2350
$Comp
L RJ12 J?
U 1 1 589F6B76
P 2450 2650
F 0 "J?" H 2650 3150 50  0000 C CNN
F 1 "RJ12" H 2300 3150 50  0000 C CNN
F 2 "" H 2450 2650 50  0000 C CNN
F 3 "" H 2450 2650 50  0000 C CNN
	1    2450 2650
	1    0    0    -1  
$EndComp
NoConn ~ 2950 2250
NoConn ~ 2950 2350
Wire Wire Line
	3400 3100 3400 3150
Wire Wire Line
	2450 3100 2450 3150
$Comp
L GND #PWR?
U 1 1 589F6C63
P 2450 3150
F 0 "#PWR?" H 2450 2900 50  0001 C CNN
F 1 "GND" H 2450 3000 50  0000 C CNN
F 2 "" H 2450 3150 50  0000 C CNN
F 3 "" H 2450 3150 50  0000 C CNN
	1    2450 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 589F6C8D
P 3400 3150
F 0 "#PWR?" H 3400 2900 50  0001 C CNN
F 1 "GND" H 3400 3000 50  0000 C CNN
F 2 "" H 3400 3150 50  0000 C CNN
F 3 "" H 3400 3150 50  0000 C CNN
	1    3400 3150
	1    0    0    -1  
$EndComp
NoConn ~ 3700 3100
NoConn ~ 3200 3100
NoConn ~ 2750 3100
NoConn ~ 2250 3100
Wire Wire Line
	2350 3100 2350 3200
Wire Wire Line
	2350 3200 2000 3200
Wire Wire Line
	2000 3200 2000 2900
Wire Wire Line
	3300 3100 3300 3200
Wire Wire Line
	3300 3200 2950 3200
Wire Wire Line
	2950 3200 2950 2900
$Comp
L +5V #PWR?
U 1 1 589F6D4F
P 2950 2900
F 0 "#PWR?" H 2950 2750 50  0001 C CNN
F 1 "+5V" H 2950 3040 50  0000 C CNN
F 2 "" H 2950 2900 50  0000 C CNN
F 3 "" H 2950 2900 50  0000 C CNN
	1    2950 2900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 589F6D79
P 2000 2900
F 0 "#PWR?" H 2000 2750 50  0001 C CNN
F 1 "+5V" H 2000 3040 50  0000 C CNN
F 2 "" H 2000 2900 50  0000 C CNN
F 3 "" H 2000 2900 50  0000 C CNN
	1    2000 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3200 3600 3100
Wire Wire Line
	3500 3300 3500 3100
Wire Wire Line
	2650 3400 2650 3100
Wire Wire Line
	2550 3100 2550 3500
Wire Wire Line
	7550 2800 7550 3500
Wire Wire Line
	6150 2700 7450 2700
Wire Wire Line
	7450 2700 7450 3400
$EndSCHEMATC
