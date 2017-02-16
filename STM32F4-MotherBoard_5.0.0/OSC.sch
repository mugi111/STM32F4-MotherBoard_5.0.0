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
Sheet 9 12
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 4100 2500 0    60   Output ~ 0
OSC_IN
Text GLabel 4100 3100 0    60   Input ~ 0
OSC_OUT
$Comp
L Crystal Y1
U 1 1 589F7562
P 4600 2800
F 0 "Y1" H 4600 2950 50  0000 C CNN
F 1 "8MHz" H 4600 2650 50  0000 C CNN
F 2 "" H 4600 2800 50  0000 C CNN
F 3 "" H 4600 2800 50  0000 C CNN
	1    4600 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	4100 2500 4750 2500
Wire Wire Line
	4600 2500 4600 2650
Wire Wire Line
	4600 2950 4600 3100
$Comp
L R R38
U 1 1 589F75A6
P 4350 3100
F 0 "R38" V 4430 3100 50  0000 C CNN
F 1 "220" V 4350 3100 50  0000 C CNN
F 2 "" V 4280 3100 50  0000 C CNN
F 3 "" H 4350 3100 50  0000 C CNN
	1    4350 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 3100 4100 3100
Wire Wire Line
	4500 3100 4750 3100
$Comp
L C_Small C19
U 1 1 589F75D2
P 4850 3100
F 0 "C19" H 4860 3170 50  0000 L CNN
F 1 "22uF" H 4860 3020 50  0000 L CNN
F 2 "" H 4850 3100 50  0000 C CNN
F 3 "" H 4850 3100 50  0000 C CNN
	1    4850 3100
	0    1    1    0   
$EndComp
$Comp
L C_Small C18
U 1 1 589F75F6
P 4850 2500
F 0 "C18" H 4860 2570 50  0000 L CNN
F 1 "22uF" H 4860 2420 50  0000 L CNN
F 2 "" H 4850 2500 50  0000 C CNN
F 3 "" H 4850 2500 50  0000 C CNN
	1    4850 2500
	0    1    1    0   
$EndComp
Connection ~ 4600 2500
Connection ~ 4600 3100
Wire Wire Line
	4950 3100 5050 3100
Wire Wire Line
	5050 2500 5050 3250
Wire Wire Line
	5050 2500 4950 2500
Connection ~ 5050 3100
$Comp
L GND #PWR064
U 1 1 589F765B
P 5050 3250
F 0 "#PWR064" H 5050 3000 50  0001 C CNN
F 1 "GND" H 5050 3100 50  0000 C CNN
F 2 "" H 5050 3250 50  0000 C CNN
F 3 "" H 5050 3250 50  0000 C CNN
	1    5050 3250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
