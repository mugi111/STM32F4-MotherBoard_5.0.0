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
Sheet 6 12
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
L CONN_02X05 P3
U 1 1 589F2DDA
P 5050 3200
F 0 "P3" H 5050 3500 50  0000 C CNN
F 1 "DIO0" H 5050 2900 50  0000 C CNN
F 2 "" H 5050 2000 50  0000 C CNN
F 3 "" H 5050 2000 50  0000 C CNN
	1    5050 3200
	1    0    0    -1  
$EndComp
Text GLabel 4500 3100 0    60   BiDi ~ 0
DIO0_0
Text GLabel 4500 3200 0    60   BiDi ~ 0
DIO0_2
Text GLabel 4500 3300 0    60   BiDi ~ 0
DIO0_4
Text GLabel 4500 3400 0    60   BiDi ~ 0
DIO0_6
Text GLabel 5600 3400 2    60   BiDi ~ 0
DIO0_7
Text GLabel 5600 3300 2    60   BiDi ~ 0
DIO0_5
Text GLabel 5600 3200 2    60   BiDi ~ 0
DIO0_3
Text GLabel 5600 3100 2    60   BiDi ~ 0
DIO0_1
Wire Wire Line
	5600 3400 5300 3400
Wire Wire Line
	5300 3300 5600 3300
Wire Wire Line
	5600 3200 5300 3200
Wire Wire Line
	5300 3100 5600 3100
Wire Wire Line
	4800 3100 4500 3100
Wire Wire Line
	4500 3200 4800 3200
Wire Wire Line
	4800 3300 4500 3300
Wire Wire Line
	4500 3400 4800 3400
Wire Wire Line
	4800 3000 4650 3000
Wire Wire Line
	4650 3000 4650 2800
$Comp
L +5V #PWR051
U 1 1 589F2E96
P 4650 2800
F 0 "#PWR051" H 4650 2650 50  0001 C CNN
F 1 "+5V" H 4650 2940 50  0000 C CNN
F 2 "" H 4650 2800 50  0000 C CNN
F 3 "" H 4650 2800 50  0000 C CNN
	1    4650 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3000 5450 3000
Wire Wire Line
	5450 3000 5450 3500
$Comp
L GND #PWR052
U 1 1 589F2EBA
P 5450 3500
F 0 "#PWR052" H 5450 3250 50  0001 C CNN
F 1 "GND" H 5450 3350 50  0000 C CNN
F 2 "" H 5450 3500 50  0000 C CNN
F 3 "" H 5450 3500 50  0000 C CNN
	1    5450 3500
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P5
U 1 1 589F2EFF
P 7050 3200
F 0 "P5" H 7050 3500 50  0000 C CNN
F 1 "DIO1" H 7050 2900 50  0000 C CNN
F 2 "" H 7050 2000 50  0000 C CNN
F 3 "" H 7050 2000 50  0000 C CNN
	1    7050 3200
	1    0    0    -1  
$EndComp
Text GLabel 6500 3100 0    60   BiDi ~ 0
DIO1_0
Text GLabel 6500 3200 0    60   BiDi ~ 0
DIO1_2
Text GLabel 6500 3300 0    60   BiDi ~ 0
DIO1_4
Text GLabel 6500 3400 0    60   BiDi ~ 0
DIO1_6
Text GLabel 7600 3400 2    60   BiDi ~ 0
DIO1_7
Text GLabel 7600 3300 2    60   BiDi ~ 0
DIO1_5
Text GLabel 7600 3200 2    60   BiDi ~ 0
DIO1_3
Text GLabel 7600 3100 2    60   BiDi ~ 0
DIO1_1
Wire Wire Line
	7600 3400 7300 3400
Wire Wire Line
	7300 3300 7600 3300
Wire Wire Line
	7600 3200 7300 3200
Wire Wire Line
	7300 3100 7600 3100
Wire Wire Line
	6800 3100 6500 3100
Wire Wire Line
	6500 3200 6800 3200
Wire Wire Line
	6800 3300 6500 3300
Wire Wire Line
	6500 3400 6800 3400
Wire Wire Line
	6800 3000 6650 3000
Wire Wire Line
	6650 3000 6650 2800
$Comp
L +5V #PWR053
U 1 1 589F2F17
P 6650 2800
F 0 "#PWR053" H 6650 2650 50  0001 C CNN
F 1 "+5V" H 6650 2940 50  0000 C CNN
F 2 "" H 6650 2800 50  0000 C CNN
F 3 "" H 6650 2800 50  0000 C CNN
	1    6650 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 3000 7450 3000
Wire Wire Line
	7450 3000 7450 3500
$Comp
L GND #PWR054
U 1 1 589F2F1F
P 7450 3500
F 0 "#PWR054" H 7450 3250 50  0001 C CNN
F 1 "GND" H 7450 3350 50  0000 C CNN
F 2 "" H 7450 3500 50  0000 C CNN
F 3 "" H 7450 3500 50  0000 C CNN
	1    7450 3500
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P4
U 1 1 589F2F6A
P 5050 4750
F 0 "P4" H 5050 5050 50  0000 C CNN
F 1 "ADC" H 5050 4450 50  0000 C CNN
F 2 "" H 5050 3550 50  0000 C CNN
F 3 "" H 5050 3550 50  0000 C CNN
	1    5050 4750
	1    0    0    -1  
$EndComp
Text GLabel 3800 4650 0    60   Output ~ 0
ADC0
Text GLabel 3800 4750 0    60   Output ~ 0
ADC2
Text GLabel 3800 4850 0    60   Output ~ 0
ADC4
Text GLabel 3800 4950 0    60   Output ~ 0
ADC6
Text GLabel 6300 4950 2    60   Output ~ 0
ADC7
Text GLabel 6300 4850 2    60   Output ~ 0
ADC5
Text GLabel 6300 4750 2    60   Output ~ 0
ADC3
Text GLabel 6300 4650 2    60   Output ~ 0
ADC1
Wire Wire Line
	4800 4550 4650 4550
Wire Wire Line
	4650 4550 4650 4350
$Comp
L +5V #PWR055
U 1 1 589F2F82
P 4650 4350
F 0 "#PWR055" H 4650 4200 50  0001 C CNN
F 1 "+5V" H 4650 4490 50  0000 C CNN
F 2 "" H 4650 4350 50  0000 C CNN
F 3 "" H 4650 4350 50  0000 C CNN
	1    4650 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4550 5450 4550
Wire Wire Line
	5450 4550 5450 5050
$Comp
L GND #PWR056
U 1 1 589F2F8A
P 5450 5050
F 0 "#PWR056" H 5450 4800 50  0001 C CNN
F 1 "GND" H 5450 4900 50  0000 C CNN
F 2 "" H 5450 5050 50  0000 C CNN
F 3 "" H 5450 5050 50  0000 C CNN
	1    5450 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4650 5500 4650
Wire Wire Line
	5500 4750 5300 4750
Wire Wire Line
	5300 4850 5500 4850
Wire Wire Line
	5500 4950 5300 4950
Wire Wire Line
	4800 4950 4600 4950
Wire Wire Line
	4600 4850 4800 4850
Wire Wire Line
	4800 4750 4600 4750
Wire Wire Line
	4600 4650 4800 4650
$Comp
L R R19
U 1 1 589F3102
P 4450 4650
F 0 "R19" V 4530 4650 50  0000 C CNN
F 1 "4.7k" V 4450 4650 50  0000 C CNN
F 2 "" V 4380 4650 50  0000 C CNN
F 3 "" H 4450 4650 50  0000 C CNN
	1    4450 4650
	0    1    1    0   
$EndComp
$Comp
L R R20
U 1 1 589F312B
P 4450 4750
F 0 "R20" V 4530 4750 50  0000 C CNN
F 1 "4.7k" V 4450 4750 50  0000 C CNN
F 2 "" V 4380 4750 50  0000 C CNN
F 3 "" H 4450 4750 50  0000 C CNN
	1    4450 4750
	0    1    1    0   
$EndComp
$Comp
L R R21
U 1 1 589F314A
P 4450 4850
F 0 "R21" V 4530 4850 50  0000 C CNN
F 1 "4.7k" V 4450 4850 50  0000 C CNN
F 2 "" V 4380 4850 50  0000 C CNN
F 3 "" H 4450 4850 50  0000 C CNN
	1    4450 4850
	0    1    1    0   
$EndComp
$Comp
L R R22
U 1 1 589F316C
P 4450 4950
F 0 "R22" V 4530 4950 50  0000 C CNN
F 1 "4.7k" V 4450 4950 50  0000 C CNN
F 2 "" V 4380 4950 50  0000 C CNN
F 3 "" H 4450 4950 50  0000 C CNN
	1    4450 4950
	0    1    1    0   
$EndComp
$Comp
L R R26
U 1 1 589F3191
P 5650 4950
F 0 "R26" V 5730 4950 50  0000 C CNN
F 1 "4.7k" V 5650 4950 50  0000 C CNN
F 2 "" V 5580 4950 50  0000 C CNN
F 3 "" H 5650 4950 50  0000 C CNN
	1    5650 4950
	0    1    1    0   
$EndComp
$Comp
L R R25
U 1 1 589F31E5
P 5650 4850
F 0 "R25" V 5730 4850 50  0000 C CNN
F 1 "4.7k" V 5650 4850 50  0000 C CNN
F 2 "" V 5580 4850 50  0000 C CNN
F 3 "" H 5650 4850 50  0000 C CNN
	1    5650 4850
	0    1    1    0   
$EndComp
$Comp
L R R24
U 1 1 589F3210
P 5650 4750
F 0 "R24" V 5730 4750 50  0000 C CNN
F 1 "4.7k" V 5650 4750 50  0000 C CNN
F 2 "" V 5580 4750 50  0000 C CNN
F 3 "" H 5650 4750 50  0000 C CNN
	1    5650 4750
	0    1    1    0   
$EndComp
$Comp
L R R23
U 1 1 589F323E
P 5650 4650
F 0 "R23" V 5730 4650 50  0000 C CNN
F 1 "4.7k" V 5650 4650 50  0000 C CNN
F 2 "" V 5580 4650 50  0000 C CNN
F 3 "" H 5650 4650 50  0000 C CNN
	1    5650 4650
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 4650 4200 5100
Wire Wire Line
	3800 4750 4300 4750
Wire Wire Line
	4100 4750 4100 5100
Wire Wire Line
	3800 4850 4300 4850
Wire Wire Line
	4000 4850 4000 5100
Wire Wire Line
	3800 4950 4300 4950
Wire Wire Line
	3900 4950 3900 5100
Wire Wire Line
	5800 4650 6300 4650
Wire Wire Line
	5900 4650 5900 5100
Wire Wire Line
	5800 4750 6300 4750
Wire Wire Line
	6000 4750 6000 5100
Wire Wire Line
	5800 4850 6300 4850
Wire Wire Line
	6100 4850 6100 5100
Wire Wire Line
	5800 4950 6300 4950
Wire Wire Line
	6200 4950 6200 5100
Connection ~ 6200 4950
Connection ~ 6100 4850
Connection ~ 6000 4750
Connection ~ 5900 4650
Connection ~ 4200 4650
Connection ~ 3900 4950
Connection ~ 4000 4850
Connection ~ 4100 4750
Wire Wire Line
	3800 4650 4300 4650
$Comp
L R R15
U 1 1 589F38D9
P 3900 5250
F 0 "R15" V 3980 5250 50  0000 C CNN
F 1 "8.4k" V 3900 5250 50  0000 C CNN
F 2 "" V 3830 5250 50  0000 C CNN
F 3 "" H 3900 5250 50  0000 C CNN
	1    3900 5250
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 589F391A
P 4000 5250
F 0 "R16" V 4080 5250 50  0000 C CNN
F 1 "8.4k" V 4000 5250 50  0000 C CNN
F 2 "" V 3930 5250 50  0000 C CNN
F 3 "" H 4000 5250 50  0000 C CNN
	1    4000 5250
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 589F3951
P 4100 5250
F 0 "R17" V 4180 5250 50  0000 C CNN
F 1 "8.4k" V 4100 5250 50  0000 C CNN
F 2 "" V 4030 5250 50  0000 C CNN
F 3 "" H 4100 5250 50  0000 C CNN
	1    4100 5250
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 589F398B
P 4200 5250
F 0 "R18" V 4280 5250 50  0000 C CNN
F 1 "8.4k" V 4200 5250 50  0000 C CNN
F 2 "" V 4130 5250 50  0000 C CNN
F 3 "" H 4200 5250 50  0000 C CNN
	1    4200 5250
	1    0    0    -1  
$EndComp
$Comp
L R R27
U 1 1 589F3AE8
P 5900 5250
F 0 "R27" V 5980 5250 50  0000 C CNN
F 1 "8.4k" V 5900 5250 50  0000 C CNN
F 2 "" V 5830 5250 50  0000 C CNN
F 3 "" H 5900 5250 50  0000 C CNN
	1    5900 5250
	1    0    0    -1  
$EndComp
$Comp
L R R28
U 1 1 589F3AEE
P 6000 5250
F 0 "R28" V 6080 5250 50  0000 C CNN
F 1 "8.4k" V 6000 5250 50  0000 C CNN
F 2 "" V 5930 5250 50  0000 C CNN
F 3 "" H 6000 5250 50  0000 C CNN
	1    6000 5250
	1    0    0    -1  
$EndComp
$Comp
L R R29
U 1 1 589F3AF4
P 6100 5250
F 0 "R29" V 6180 5250 50  0000 C CNN
F 1 "8.4k" V 6100 5250 50  0000 C CNN
F 2 "" V 6030 5250 50  0000 C CNN
F 3 "" H 6100 5250 50  0000 C CNN
	1    6100 5250
	1    0    0    -1  
$EndComp
$Comp
L R R30
U 1 1 589F3AFA
P 6200 5250
F 0 "R30" V 6280 5250 50  0000 C CNN
F 1 "8.4k" V 6200 5250 50  0000 C CNN
F 2 "" V 6130 5250 50  0000 C CNN
F 3 "" H 6200 5250 50  0000 C CNN
	1    6200 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 5400 3900 5450
Wire Wire Line
	3900 5450 4200 5450
Wire Wire Line
	4200 5400 4200 5500
Wire Wire Line
	4100 5400 4100 5450
Connection ~ 4100 5450
Wire Wire Line
	4000 5450 4000 5400
Connection ~ 4000 5450
Wire Wire Line
	5900 5400 5900 5500
Wire Wire Line
	5900 5450 6200 5450
Wire Wire Line
	6200 5450 6200 5400
Wire Wire Line
	6100 5400 6100 5450
Connection ~ 6100 5450
Wire Wire Line
	6000 5450 6000 5400
Connection ~ 6000 5450
Connection ~ 5900 5450
Connection ~ 4200 5450
$Comp
L GND #PWR057
U 1 1 589F3DEA
P 4200 5500
F 0 "#PWR057" H 4200 5250 50  0001 C CNN
F 1 "GND" H 4200 5350 50  0000 C CNN
F 2 "" H 4200 5500 50  0000 C CNN
F 3 "" H 4200 5500 50  0000 C CNN
	1    4200 5500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR058
U 1 1 589F3E35
P 5900 5500
F 0 "#PWR058" H 5900 5250 50  0001 C CNN
F 1 "GND" H 5900 5350 50  0000 C CNN
F 2 "" H 5900 5500 50  0000 C CNN
F 3 "" H 5900 5500 50  0000 C CNN
	1    5900 5500
	1    0    0    -1  
$EndComp
$EndSCHEMATC
