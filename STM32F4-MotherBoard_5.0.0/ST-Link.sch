EESchema Schematic File Version 2
LIBS:STM32F4-MotherBoard_5.0.0-rescue
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
Sheet 8 12
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
L CONN_01X06 P6
U 1 1 589F4C21
P 5650 3050
F 0 "P6" H 5650 3400 50  0000 C CNN
F 1 "SWD" V 5750 3050 50  0000 C CNN
F 2 "mylib:PinHeader-6" H 5650 3050 50  0001 C CNN
F 3 "" H 5650 3050 50  0000 C CNN
	1    5650 3050
	-1   0    0    -1  
$EndComp
$Comp
L R R34
U 1 1 589F4C7C
P 6100 2900
F 0 "R34" V 6180 2900 50  0000 C CNN
F 1 "22" V 6100 2900 50  0000 C CNN
F 2 "" V 6030 2900 50  0001 C CNN
F 3 "" H 6100 2900 50  0000 C CNN
	1    6100 2900
	0    1    1    0   
$EndComp
$Comp
L R R35
U 1 1 589F4CC4
P 6100 3100
F 0 "R35" V 6180 3100 50  0000 C CNN
F 1 "22" V 6100 3100 50  0000 C CNN
F 2 "" V 6030 3100 50  0001 C CNN
F 3 "" H 6100 3100 50  0000 C CNN
	1    6100 3100
	0    1    1    0   
$EndComp
$Comp
L R R36
U 1 1 589F4CE0
P 6100 3200
F 0 "R36" V 6180 3200 50  0000 C CNN
F 1 "22" V 6100 3200 50  0000 C CNN
F 2 "" V 6030 3200 50  0001 C CNN
F 3 "" H 6100 3200 50  0000 C CNN
	1    6100 3200
	0    1    1    0   
$EndComp
$Comp
L R R37
U 1 1 589F4D03
P 6100 3300
F 0 "R37" V 6180 3300 50  0000 C CNN
F 1 "22" V 6100 3300 50  0000 C CNN
F 2 "" V 6030 3300 50  0001 C CNN
F 3 "" H 6100 3300 50  0000 C CNN
	1    6100 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 3300 5850 3300
Wire Wire Line
	5850 3200 5950 3200
Wire Wire Line
	5950 3100 5850 3100
Wire Wire Line
	5950 2900 5850 2900
Wire Wire Line
	6250 2900 6350 2900
Wire Wire Line
	6250 3100 6350 3100
Wire Wire Line
	6350 3200 6250 3200
Wire Wire Line
	6250 3300 6350 3300
Text GLabel 6350 2900 2    60   Input ~ 0
SWCLK
NoConn ~ 5850 2800
Wire Wire Line
	5850 3000 5900 3000
Wire Wire Line
	5900 3000 5900 3400
$Comp
L GND #PWR065
U 1 1 589F4E4F
P 5900 3400
F 0 "#PWR065" H 5900 3150 50  0001 C CNN
F 1 "GND" H 5900 3250 50  0000 C CNN
F 2 "" H 5900 3400 50  0000 C CNN
F 3 "" H 5900 3400 50  0000 C CNN
	1    5900 3400
	1    0    0    -1  
$EndComp
Text GLabel 6350 3100 2    60   Input ~ 0
SWDIO
Text GLabel 6350 3200 2    60   Input ~ 0
NRST
Text GLabel 6350 3300 2    60   Input ~ 0
SWO
$EndSCHEMATC
