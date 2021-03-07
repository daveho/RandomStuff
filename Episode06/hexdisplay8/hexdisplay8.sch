EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "8 bit hex display"
Date ""
Rev ""
Comp "daveho hacks"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATTINY2313A-SU:ATTINY2313A-SU U1
U 1 1 60451980
P 2750 3800
F 0 "U1" H 2750 4770 50  0000 C CNN
F 1 "ATTINY2313A-SU" H 2750 4679 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 2750 3800 50  0001 L BNN
F 3 "" H 2750 3800 50  0001 L BNN
F 4 "Atmel" H 2750 3800 50  0001 L BNN "SUPPLIER"
F 5 "ATTINY2313A-SU" H 2750 3800 50  0001 L BNN "MPN"
F 6 "1841617" H 2750 3800 50  0001 L BNN "OC_FARNELL"
F 7 "12T1334" H 2750 3800 50  0001 L BNN "OC_NEWARK"
F 8 "SOIC-20" H 2750 3800 50  0001 L BNN "PACKAGE"
	1    2750 3800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J2
U 1 1 6045265A
P 7950 3850
F 0 "J2" H 8000 4267 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 8000 4176 50  0000 C CNN
F 2 "Package_DIP:DIP-10_W7.62mm" H 7950 3850 50  0001 C CNN
F 3 "" H 7950 3850 50  0001 C CNN
	1    7950 3850
	1    0    0    -1  
$EndComp
$Comp
L MMBT3906:MMBT3906 Q1
U 1 1 60453C20
P 3200 5950
F 0 "Q1" H 3353 5996 50  0000 L CNN
F 1 "MMBT3906" H 3353 5905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3200 5950 50  0001 L BNN
F 3 "" H 3200 5950 50  0001 L BNN
F 4 "Fairchild Semiconductor" H 3200 5950 50  0001 L BNN "MANUFACTURER"
	1    3200 5950
	1    0    0    -1  
$EndComp
$Comp
L MMBT3906:MMBT3906 Q2
U 1 1 60453FAA
P 3350 6900
F 0 "Q2" H 3503 6946 50  0000 L CNN
F 1 "MMBT3906" H 3503 6855 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3350 6900 50  0001 L BNN
F 3 "" H 3350 6900 50  0001 L BNN
F 4 "Fairchild Semiconductor" H 3350 6900 50  0001 L BNN "MANUFACTURER"
	1    3350 6900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J1
U 1 1 60455147
P 7950 2800
F 0 "J1" H 8000 3217 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 8000 3126 50  0000 C CNN
F 2 "Package_DIP:DIP-10_W7.62mm" H 7950 2800 50  0001 C CNN
F 3 "" H 7950 2800 50  0001 C CNN
	1    7950 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4300 1550 4300
Wire Wire Line
	2050 4400 1550 4400
Wire Wire Line
	2050 4500 1550 4500
$Comp
L Connector_Generic:Conn_01x06 J5
U 1 1 604585DD
P 4350 1700
F 0 "J5" H 4430 1692 50  0000 L CNN
F 1 "Conn_01x06" H 4430 1601 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 4350 1700 50  0001 C CNN
F 3 "" H 4350 1700 50  0001 C CNN
	1    4350 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 1500 3700 1500
Wire Wire Line
	4150 1600 3700 1600
Wire Wire Line
	4150 1700 3700 1700
Wire Wire Line
	4150 1800 3700 1800
Wire Wire Line
	4150 1900 3700 1900
Wire Wire Line
	4150 2000 3700 2000
Text Label 3750 1500 0    50   ~ 0
GND
Text Label 3750 1600 0    50   ~ 0
VCC
Text Label 3750 1900 0    50   ~ 0
~RESET
Wire Wire Line
	2050 3600 1550 3600
Text Label 1650 3600 0    50   ~ 0
~RESET
Text Notes 3950 1300 0    50   ~ 0
AVR programming header
Wire Wire Line
	2050 3200 1850 3200
Wire Wire Line
	1850 3200 1850 3100
$Comp
L power:VCC #PWR0101
U 1 1 60461FFF
P 1850 3100
F 0 "#PWR0101" H 1850 2950 50  0001 C CNN
F 1 "VCC" H 1867 3273 50  0000 C CNN
F 2 "" H 1850 3100 50  0001 C CNN
F 3 "" H 1850 3100 50  0001 C CNN
	1    1850 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4700 1850 4700
Wire Wire Line
	1850 4700 1850 4850
$Comp
L power:GND #PWR0102
U 1 1 60462A72
P 1850 4850
F 0 "#PWR0102" H 1850 4600 50  0001 C CNN
F 1 "GND" H 1855 4677 50  0000 C CNN
F 2 "" H 1850 4850 50  0001 C CNN
F 3 "" H 1850 4850 50  0001 C CNN
	1    1850 4850
	1    0    0    -1  
$EndComp
Text Label 1650 4200 0    50   ~ 0
D4
Text Label 1650 4100 0    50   ~ 0
D3
Text Label 1650 4000 0    50   ~ 0
D2
Text Label 1650 3900 0    50   ~ 0
D1
Text Label 1650 3800 0    50   ~ 0
D0
Wire Wire Line
	2050 4200 1550 4200
Wire Wire Line
	2050 4100 1550 4100
Wire Wire Line
	2050 4000 1550 4000
Wire Wire Line
	2050 3900 1550 3900
Wire Wire Line
	2050 3800 1550 3800
Text Notes 3400 2000 0    50   ~ 0
MOSI
Text Notes 3400 1800 0    50   ~ 0
SCK
Text Notes 3400 1700 0    50   ~ 0
MISO
Text Label 3750 1800 0    50   ~ 0
D7
Text Label 1650 4500 0    50   ~ 0
D7
Text Label 3750 2000 0    50   ~ 0
D5
Text Label 1650 4300 0    50   ~ 0
D5
Text Label 3750 1700 0    50   ~ 0
D6
Text Label 1650 4400 0    50   ~ 0
D6
Wire Wire Line
	3950 3200 4450 3200
Wire Wire Line
	3950 3300 4450 3300
Wire Wire Line
	3950 3400 4450 3400
Wire Wire Line
	3950 3500 4450 3500
Wire Wire Line
	3950 3600 4450 3600
Wire Wire Line
	3950 3700 4450 3700
Wire Wire Line
	3950 3800 4450 3800
Text Label 4250 3200 0    50   ~ 0
A
Text Label 4250 3300 0    50   ~ 0
B
Text Label 4250 3400 0    50   ~ 0
C
Text Label 4250 3500 0    50   ~ 0
D
Text Label 4250 3600 0    50   ~ 0
E
Text Label 4250 3700 0    50   ~ 0
F
Text Label 4250 3800 0    50   ~ 0
G
$Comp
L device:R R1
U 1 1 6046A68A
P 3800 3200
F 0 "R1" V 3750 3400 50  0000 C CNN
F 1 "330" V 3800 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3200 50  0001 C CNN
F 3 "" H 3800 3200 50  0001 C CNN
	1    3800 3200
	0    1    1    0   
$EndComp
$Comp
L device:R R2
U 1 1 6046BEAB
P 3800 3300
F 0 "R2" V 3750 3500 50  0000 C CNN
F 1 "330" V 3800 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3300 50  0001 C CNN
F 3 "" H 3800 3300 50  0001 C CNN
	1    3800 3300
	0    1    1    0   
$EndComp
$Comp
L device:R R3
U 1 1 6046DDCC
P 3800 3400
F 0 "R3" V 3750 3600 50  0000 C CNN
F 1 "330" V 3800 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3400 50  0001 C CNN
F 3 "" H 3800 3400 50  0001 C CNN
	1    3800 3400
	0    1    1    0   
$EndComp
$Comp
L device:R R4
U 1 1 6046DED2
P 3800 3500
F 0 "R4" V 3750 3700 50  0000 C CNN
F 1 "330" V 3800 3500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3500 50  0001 C CNN
F 3 "" H 3800 3500 50  0001 C CNN
	1    3800 3500
	0    1    1    0   
$EndComp
$Comp
L device:R R5
U 1 1 60470244
P 3800 3600
F 0 "R5" V 3750 3800 50  0000 C CNN
F 1 "330" V 3800 3600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3600 50  0001 C CNN
F 3 "" H 3800 3600 50  0001 C CNN
	1    3800 3600
	0    1    1    0   
$EndComp
$Comp
L device:R R6
U 1 1 6047036A
P 3800 3700
F 0 "R6" V 3750 3900 50  0000 C CNN
F 1 "330" V 3800 3700 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3700 50  0001 C CNN
F 3 "" H 3800 3700 50  0001 C CNN
	1    3800 3700
	0    1    1    0   
$EndComp
$Comp
L device:R R7
U 1 1 60470374
P 3800 3800
F 0 "R7" V 3750 4000 50  0000 C CNN
F 1 "330" V 3800 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 3730 3800 50  0001 C CNN
F 3 "" H 3800 3800 50  0001 C CNN
	1    3800 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 3200 3650 3200
Wire Wire Line
	3450 3300 3650 3300
Wire Wire Line
	3450 3400 3650 3400
Wire Wire Line
	3450 3500 3650 3500
Wire Wire Line
	3450 3600 3650 3600
Wire Wire Line
	3450 3700 3650 3700
Wire Wire Line
	3450 3800 3650 3800
Text Notes 7600 3400 0    50   ~ 0
Left digit (most significant)
Text Notes 7550 2350 0    50   ~ 0
Right digit (least significant)
$Comp
L device:R R8
U 1 1 60485D79
P 2650 5950
F 0 "R8" V 2550 5950 50  0000 C CNN
F 1 "4k7" V 2650 5950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 2580 5950 50  0001 C CNN
F 3 "" H 2650 5950 50  0001 C CNN
	1    2650 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	2800 5950 3100 5950
$Comp
L device:R R9
U 1 1 6048800D
P 2800 6900
F 0 "R9" V 2700 6900 50  0000 C CNN
F 1 "4k7" V 2800 6900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 2730 6900 50  0001 C CNN
F 3 "" H 2800 6900 50  0001 C CNN
	1    2800 6900
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 6900 3250 6900
Wire Wire Line
	3300 5650 3300 5450
Wire Wire Line
	3300 5450 4300 5450
Wire Wire Line
	4300 5450 4300 5250
$Comp
L power:VCC #PWR0103
U 1 1 6048B22B
P 4300 5250
F 0 "#PWR0103" H 4300 5100 50  0001 C CNN
F 1 "VCC" H 4317 5423 50  0000 C CNN
F 2 "" H 4300 5250 50  0001 C CNN
F 3 "" H 4300 5250 50  0001 C CNN
	1    4300 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 6600 3450 6400
Wire Wire Line
	3450 6400 4300 6400
Wire Wire Line
	4300 6400 4300 5450
Connection ~ 4300 5450
Wire Wire Line
	3300 6250 4800 6250
Text Label 4600 6250 0    50   ~ 0
CA1
Text Label 4650 7200 0    50   ~ 0
CA2
Wire Wire Line
	3450 7200 4850 7200
Wire Wire Line
	2500 5950 1250 5950
Wire Wire Line
	1250 5950 1250 3500
Wire Wire Line
	1250 3500 2050 3500
Wire Wire Line
	2650 6900 1150 6900
Wire Wire Line
	1150 6900 1150 3400
Wire Wire Line
	1150 3400 2050 3400
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 604B02DC
P 2400 1600
F 0 "J3" H 2480 1592 50  0000 L CNN
F 1 "Conn_01x02" H 2480 1501 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2400 1600 50  0001 C CNN
F 3 "" H 2400 1600 50  0001 C CNN
	1    2400 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1600 1750 1600
Wire Wire Line
	2200 1700 1750 1700
Text Label 1800 1600 0    50   ~ 0
GND
Text Label 1800 1700 0    50   ~ 0
VCC
Text Notes 2250 1400 0    50   ~ 0
Power
Wire Wire Line
	1750 1600 1750 1400
Wire Wire Line
	1750 1950 1750 1900
$Comp
L power:VCC #PWR0104
U 1 1 604BADE0
P 1750 1350
F 0 "#PWR0104" H 1750 1200 50  0001 C CNN
F 1 "VCC" H 1767 1523 50  0000 C CNN
F 2 "" H 1750 1350 50  0001 C CNN
F 3 "" H 1750 1350 50  0001 C CNN
	1    1750 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 604BB1BF
P 1750 1950
F 0 "#PWR0105" H 1750 1700 50  0001 C CNN
F 1 "GND" H 1755 1777 50  0000 C CNN
F 2 "" H 1750 1950 50  0001 C CNN
F 3 "" H 1750 1950 50  0001 C CNN
	1    1750 1950
	1    0    0    -1  
$EndComp
$Comp
L device:C C1
U 1 1 604BB56B
P 1350 1650
F 0 "C1" H 1465 1696 50  0000 L CNN
F 1 "100nF" H 1465 1605 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 1388 1500 50  0001 C CNN
F 3 "" H 1350 1650 50  0001 C CNN
	1    1350 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1500 1350 1400
Wire Wire Line
	1350 1400 1750 1400
Connection ~ 1750 1400
Wire Wire Line
	1750 1400 1750 1350
Wire Wire Line
	1350 1800 1350 1900
Wire Wire Line
	1350 1900 1750 1900
Connection ~ 1750 1900
Wire Wire Line
	1750 1900 1750 1700
Wire Wire Line
	7750 3650 7350 3650
Wire Wire Line
	7750 3750 7350 3750
Wire Wire Line
	7750 3850 7350 3850
Wire Wire Line
	7750 3950 7350 3950
Wire Wire Line
	7750 4050 7350 4050
Wire Wire Line
	8650 3650 8250 3650
Wire Wire Line
	8650 3750 8250 3750
Wire Wire Line
	8650 3850 8250 3850
Wire Wire Line
	8650 4050 8250 4050
Text Label 7450 3650 0    50   ~ 0
CA1
Text Label 8500 4050 0    50   ~ 0
CA1
Text Label 7450 3750 0    50   ~ 0
F
Text Label 7450 3850 0    50   ~ 0
G
Text Label 7450 3950 0    50   ~ 0
E
Text Label 7450 4050 0    50   ~ 0
D
Text Label 8500 3650 0    50   ~ 0
A
Text Label 8500 3750 0    50   ~ 0
B
Text Label 8500 3850 0    50   ~ 0
C
NoConn ~ 8250 3950
Wire Wire Line
	7750 2600 7350 2600
Wire Wire Line
	7750 2700 7350 2700
Wire Wire Line
	7750 2800 7350 2800
Wire Wire Line
	7750 2900 7350 2900
Wire Wire Line
	7750 3000 7350 3000
Text Label 7450 2600 0    50   ~ 0
CA2
Text Label 7450 2700 0    50   ~ 0
F
Text Label 7450 2800 0    50   ~ 0
G
Text Label 7450 2900 0    50   ~ 0
E
Text Label 7450 3000 0    50   ~ 0
D
Wire Wire Line
	8650 2600 8250 2600
Wire Wire Line
	8650 2700 8250 2700
Wire Wire Line
	8650 2800 8250 2800
Wire Wire Line
	8650 3000 8250 3000
Text Label 8500 3000 0    50   ~ 0
CA2
Text Label 8500 2600 0    50   ~ 0
A
Text Label 8500 2700 0    50   ~ 0
B
Text Label 8500 2800 0    50   ~ 0
C
NoConn ~ 8250 2900
Text Notes 7400 2100 0    50   ~ 0
Hex displays are HDSP-F501\nor similar (DIP 10, common\nanode).  Adjust current limiting\nresistors (R1-R7) to suit.
$Comp
L Connector_Generic:Conn_01x08 J4
U 1 1 60507906
P 6050 5150
F 0 "J4" H 6130 5142 50  0000 L CNN
F 1 "Conn_01x08" H 6130 5051 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 6050 5150 50  0001 C CNN
F 3 "" H 6050 5150 50  0001 C CNN
	1    6050 5150
	1    0    0    -1  
$EndComp
Text Notes 5800 4650 0    50   ~ 0
Data inputs
Wire Wire Line
	5850 5350 5350 5350
Wire Wire Line
	5850 5450 5350 5450
Wire Wire Line
	5850 5550 5350 5550
Text Label 5450 5250 0    50   ~ 0
D4
Text Label 5450 5150 0    50   ~ 0
D3
Text Label 5450 5050 0    50   ~ 0
D2
Text Label 5450 4950 0    50   ~ 0
D1
Text Label 5450 4850 0    50   ~ 0
D0
Wire Wire Line
	5850 5250 5350 5250
Wire Wire Line
	5850 5150 5350 5150
Wire Wire Line
	5850 5050 5350 5050
Wire Wire Line
	5850 4950 5350 4950
Wire Wire Line
	5850 4850 5350 4850
Text Label 5450 5550 0    50   ~ 0
D7
Text Label 5450 5350 0    50   ~ 0
D5
Text Label 5450 5450 0    50   ~ 0
D6
$EndSCHEMATC
