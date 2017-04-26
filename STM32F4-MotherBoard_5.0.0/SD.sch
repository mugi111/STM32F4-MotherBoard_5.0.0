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
LIBS:DM3AT-SF-PEJM5
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 12
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 4350 4600 0    60   Input ~ 0
SPI_SCK
Text GLabel 4350 4500 0    60   Input ~ 0
SPI_MOSI
Text GLabel 4350 4100 0    60   Output ~ 0
SPI_MISO
Wire Wire Line
	5300 4100 4350 4100
Wire Wire Line
	4350 4500 5300 4500
Wire Wire Line
	4350 4600 5300 4600
Wire Wire Line
	4350 4400 5300 4400
$Comp
L GND #PWR072
U 1 1 58A2FE1C
P 5200 5050
F 0 "#PWR072" H 5200 4800 50  0001 C CNN
F 1 "GND" H 5200 4900 50  0000 C CNN
F 2 "" H 5200 5050 50  0000 C CNN
F 3 "" H 5200 5050 50  0000 C CNN
	1    5200 5050
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR073
U 1 1 58A2FE3B
P 5100 3950
F 0 "#PWR073" H 5100 3800 50  0001 C CNN
F 1 "+3.3V" H 5100 4090 50  0000 C CNN
F 2 "" H 5100 3950 50  0000 C CNN
F 3 "" H 5100 3950 50  0000 C CNN
	1    5100 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4000 5300 4000
Wire Wire Line
	5300 4700 5200 4700
NoConn ~ 5300 4200
Text GLabel 4350 4400 0    60   Input ~ 0
SPI_CS
NoConn ~ 5300 4300
$Comp
L DM3AT-SF-PEJM5 J5
U 1 1 58DE04A7
P 5500 4500
F 0 "J5" H 5500 5120 50  0000 L CNN
F 1 "DM3AT-SF-PEJM5" H 5500 3780 50  0000 L CNN
F 2 "DM3AT-SF-PEJM5:HRS_DM3AT-SF-PEJM5" H 5500 4500 50  0001 L CNN
F 3 "DM3AT-SF-PEJM5" H 5500 4500 50  0001 L CNN
F 4 "Good" H 5500 4500 50  0001 L CNN "Availability"
F 5 "DM3 Series 8 Position Right Angle SMT Push Push Ejection MicroSD Card Connector" H 5500 4500 50  0001 L CNN "Description"
F 6 "None" H 5500 4500 50  0001 L CNN "Package"
F 7 "Hirose" H 5500 4500 50  0001 L CNN "MF"
F 8 "1.96 USD" H 5500 4500 50  0001 L CNN "Price"
	1    5500 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4700 5200 5050
Wire Wire Line
	5100 4000 5100 3950
NoConn ~ 5300 4900
NoConn ~ 5300 5000
$EndSCHEMATC
