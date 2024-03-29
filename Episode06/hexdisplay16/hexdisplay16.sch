EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "16 bit hex display"
Date ""
Rev ""
Comp "daveho hacks"
Comment1 "https://ohwr.org/cern_ohl_p_v2.txt"
Comment2 "Open source hardware"
Comment3 "Copyright (c) 2021, David H. Hovemeyer"
Comment4 ""
$EndDescr
$Comp
L ATMEGA164A-AU:ATMEGA164A-AU U1
U 1 1 603C1C37
P 4450 2400
F 0 "U1" H 4450 4170 50  0000 C CNN
F 1 "ATMEGA164A-AU" H 4450 4079 50  0000 C CNN
F 2 "Package_QFP:LQFP-44_10x10mm_P0.8mm" H 4450 2400 50  0001 L BNN
F 3 "" H 4450 2400 50  0001 L BNN
F 4 "1841601" H 4450 2400 50  0001 L BNN "OC_FARNELL"
F 5 "12T1293" H 4450 2400 50  0001 L BNN "OC_NEWARK"
F 6 "ATMEL" H 4450 2400 50  0001 L BNN "SUPPLIER"
F 7 "QFP-44" H 4450 2400 50  0001 L BNN "PACKAGE"
F 8 "Microcontroller" H 4450 2400 50  0001 L BNN "DESCRIPTION"
F 9 "ATMEGA164A-AU" H 4450 2400 50  0001 L BNN "MPN"
	1    4450 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 1900 7200 1900
Wire Wire Line
	6650 2000 7200 2000
Wire Wire Line
	6650 2100 7200 2100
Wire Wire Line
	6650 2200 7200 2200
Wire Wire Line
	6650 2300 7200 2300
Wire Wire Line
	6650 2400 7200 2400
Wire Wire Line
	6650 2500 7200 2500
Wire Wire Line
	6650 2600 7200 2600
Text Label 6950 1900 0    50   ~ 0
D0
Text Label 6950 2000 0    50   ~ 0
D1
Text Label 6950 2100 0    50   ~ 0
D2
Text Label 6950 2200 0    50   ~ 0
D3
Text Label 6950 2300 0    50   ~ 0
D4
Text Label 6950 2400 0    50   ~ 0
D5
Text Label 6950 2500 0    50   ~ 0
D6
Text Label 6950 2600 0    50   ~ 0
D7
Wire Wire Line
	6650 1000 7200 1000
Wire Wire Line
	6650 1100 7200 1100
Wire Wire Line
	6650 1200 7200 1200
Wire Wire Line
	6650 1300 7200 1300
Wire Wire Line
	6650 1400 7200 1400
Wire Wire Line
	6650 1500 7200 1500
Wire Wire Line
	6650 1600 7200 1600
Wire Wire Line
	6650 1700 7200 1700
Text Label 6950 1000 0    50   ~ 0
D8
Text Label 6950 1100 0    50   ~ 0
D9
Text Label 6950 1200 0    50   ~ 0
D10
Text Label 6950 1300 0    50   ~ 0
D11
Text Label 6950 1400 0    50   ~ 0
D12
Text Label 6950 1500 0    50   ~ 0
D13
Text Label 6950 1600 0    50   ~ 0
D14
Text Label 6950 1700 0    50   ~ 0
D15
$Comp
L power:GND #PWR02
U 1 1 603C9A9A
P 1950 4200
F 0 "#PWR02" H 1950 3950 50  0001 C CNN
F 1 "GND" H 1955 4027 50  0000 C CNN
F 2 "" H 1950 4200 50  0001 C CNN
F 3 "" H 1950 4200 50  0001 C CNN
	1    1950 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 3700 1950 3700
Wire Wire Line
	1950 3700 1950 3800
Wire Wire Line
	2250 3800 1950 3800
Connection ~ 1950 3800
Wire Wire Line
	1950 3800 1950 3900
Wire Wire Line
	2250 3900 1950 3900
Connection ~ 1950 3900
Wire Wire Line
	1950 3900 1950 4000
Wire Wire Line
	2250 4000 1950 4000
Connection ~ 1950 4000
Wire Wire Line
	1950 4000 1950 4200
Wire Wire Line
	2250 1300 1950 1300
Wire Wire Line
	1950 1300 1950 1200
Wire Wire Line
	2250 1000 1950 1000
Connection ~ 1950 1000
Wire Wire Line
	1950 1000 1950 850 
Wire Wire Line
	2250 1100 1950 1100
Connection ~ 1950 1100
Wire Wire Line
	1950 1100 1950 1000
Wire Wire Line
	2250 1200 1950 1200
Connection ~ 1950 1200
Wire Wire Line
	1950 1200 1950 1100
$Comp
L power:VCC #PWR01
U 1 1 603D1AE9
P 1950 850
F 0 "#PWR01" H 1950 700 50  0001 C CNN
F 1 "VCC" H 1967 1023 50  0000 C CNN
F 2 "" H 1950 850 50  0001 C CNN
F 3 "" H 1950 850 50  0001 C CNN
	1    1950 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 1600 1950 1600
Wire Wire Line
	1950 1600 1950 1300
Connection ~ 1950 1300
Text Label 1550 1500 0    50   ~ 0
~RESET
Wire Wire Line
	2250 2000 1300 2000
Wire Wire Line
	2250 2100 1300 2100
Wire Wire Line
	2250 2200 1300 2200
Wire Wire Line
	2250 2300 1300 2300
Wire Wire Line
	2250 2400 1300 2400
Wire Wire Line
	2250 2500 1300 2500
$Comp
L device:R R1
U 1 1 603D8792
P 1150 1900
F 0 "R1" V 1100 1650 50  0000 C CNN
F 1 "330" V 1150 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1080 1900 50  0001 C CNN
F 3 "" H 1150 1900 50  0001 C CNN
	1    1150 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	1300 1900 2250 1900
$Comp
L device:R R2
U 1 1 603DFBC0
P 1150 2000
F 0 "R2" V 1100 1750 50  0000 C CNN
F 1 "330" V 1150 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1080 2000 50  0001 C CNN
F 3 "" H 1150 2000 50  0001 C CNN
	1    1150 2000
	0    1    1    0   
$EndComp
$Comp
L device:R R3
U 1 1 603E27DC
P 1150 2100
F 0 "R3" V 1100 1850 50  0000 C CNN
F 1 "330" V 1150 2100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1080 2100 50  0001 C CNN
F 3 "" H 1150 2100 50  0001 C CNN
	1    1150 2100
	0    1    1    0   
$EndComp
$Comp
L device:R R4
U 1 1 603E287F
P 1150 2200
F 0 "R4" V 1100 1950 50  0000 C CNN
F 1 "330" V 1150 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1080 2200 50  0001 C CNN
F 3 "" H 1150 2200 50  0001 C CNN
	1    1150 2200
	0    1    1    0   
$EndComp
$Comp
L device:R R5
U 1 1 603E5E32
P 1150 2300
F 0 "R5" V 1100 2050 50  0000 C CNN
F 1 "330" V 1150 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1080 2300 50  0001 C CNN
F 3 "" H 1150 2300 50  0001 C CNN
	1    1150 2300
	0    1    1    0   
$EndComp
$Comp
L device:R R6
U 1 1 603E5EF5
P 1150 2400
F 0 "R6" V 1100 2150 50  0000 C CNN
F 1 "330" V 1150 2400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1080 2400 50  0001 C CNN
F 3 "" H 1150 2400 50  0001 C CNN
	1    1150 2400
	0    1    1    0   
$EndComp
$Comp
L device:R R7
U 1 1 603E5F00
P 1150 2500
F 0 "R7" V 1100 2250 50  0000 C CNN
F 1 "330" V 1150 2500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1080 2500 50  0001 C CNN
F 3 "" H 1150 2500 50  0001 C CNN
	1    1150 2500
	0    1    1    0   
$EndComp
Text Label 650  2500 0    50   ~ 0
G
Text Label 650  2400 0    50   ~ 0
F
Text Label 650  2300 0    50   ~ 0
E
Text Label 650  2200 0    50   ~ 0
D
Text Label 650  2100 0    50   ~ 0
C
Text Label 650  2000 0    50   ~ 0
B
Text Label 650  1900 0    50   ~ 0
A
Wire Wire Line
	1000 2500 600  2500
Wire Wire Line
	1000 2400 600  2400
Wire Wire Line
	1000 2300 600  2300
Wire Wire Line
	1000 2200 600  2200
Wire Wire Line
	1000 2100 600  2100
Wire Wire Line
	1000 2000 600  2000
Wire Wire Line
	1000 1900 600  1900
$Comp
L MMBT3906:MMBT3906 Q1
U 1 1 603FB756
P 2300 5000
F 0 "Q1" H 2453 5046 50  0000 L CNN
F 1 "MMBT3906" H 2453 4955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2300 5000 50  0001 L BNN
F 3 "" H 2300 5000 50  0001 L BNN
F 4 "Fairchild Semiconductor" H 2300 5000 50  0001 L BNN "MANUFACTURER"
	1    2300 5000
	1    0    0    -1  
$EndComp
$Comp
L device:R R8
U 1 1 603FD24E
P 1800 5000
F 0 "R8" V 1593 5000 50  0000 C CNN
F 1 "4k7" V 1684 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1730 5000 50  0001 C CNN
F 3 "" H 1800 5000 50  0001 C CNN
	1    1800 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	2200 5000 1950 5000
$Comp
L power:VCC #PWR03
U 1 1 60408E03
P 3350 4500
F 0 "#PWR03" H 3350 4350 50  0001 C CNN
F 1 "VCC" H 3367 4673 50  0000 C CNN
F 2 "" H 3350 4500 50  0001 C CNN
F 3 "" H 3350 4500 50  0001 C CNN
	1    3350 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 4700 2400 4650
Wire Wire Line
	2400 4650 3350 4650
Wire Wire Line
	3350 4650 3350 4500
Wire Wire Line
	2250 2800 1050 2800
Wire Wire Line
	1050 2800 1050 5000
Wire Wire Line
	1050 5000 1650 5000
Wire Wire Line
	2400 5300 2400 5350
$Comp
L MMBT3906:MMBT3906 Q2
U 1 1 60417F22
P 2400 5800
F 0 "Q2" H 2553 5846 50  0000 L CNN
F 1 "MMBT3906" H 2553 5755 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2400 5800 50  0001 L BNN
F 3 "" H 2400 5800 50  0001 L BNN
F 4 "Fairchild Semiconductor" H 2400 5800 50  0001 L BNN "MANUFACTURER"
	1    2400 5800
	1    0    0    -1  
$EndComp
$Comp
L device:R R9
U 1 1 60417FCE
P 1900 5800
F 0 "R9" V 1693 5800 50  0000 C CNN
F 1 "4k7" V 1784 5800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1830 5800 50  0001 C CNN
F 3 "" H 1900 5800 50  0001 C CNN
	1    1900 5800
	0    1    1    0   
$EndComp
Wire Wire Line
	2300 5800 2050 5800
Wire Wire Line
	2500 5500 2500 5450
Wire Wire Line
	2500 6100 2500 6150
$Comp
L MMBT3906:MMBT3906 Q3
U 1 1 6042EE45
P 2500 6600
F 0 "Q3" H 2653 6646 50  0000 L CNN
F 1 "MMBT3906" H 2653 6555 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2500 6600 50  0001 L BNN
F 3 "" H 2500 6600 50  0001 L BNN
F 4 "Fairchild Semiconductor" H 2500 6600 50  0001 L BNN "MANUFACTURER"
	1    2500 6600
	1    0    0    -1  
$EndComp
$Comp
L device:R R10
U 1 1 6042EF8D
P 2000 6600
F 0 "R10" V 1793 6600 50  0000 C CNN
F 1 "4k7" V 1884 6600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 1930 6600 50  0001 C CNN
F 3 "" H 2000 6600 50  0001 C CNN
	1    2000 6600
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 6600 2150 6600
Wire Wire Line
	2600 6300 2600 6250
Wire Wire Line
	2600 6900 2600 6950
$Comp
L MMBT3906:MMBT3906 Q4
U 1 1 60444C6E
P 2600 7400
F 0 "Q4" H 2753 7446 50  0000 L CNN
F 1 "MMBT3906" H 2753 7355 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2600 7400 50  0001 L BNN
F 3 "" H 2600 7400 50  0001 L BNN
F 4 "Fairchild Semiconductor" H 2600 7400 50  0001 L BNN "MANUFACTURER"
	1    2600 7400
	1    0    0    -1  
$EndComp
$Comp
L device:R R11
U 1 1 60444D80
P 2100 7400
F 0 "R11" V 1893 7400 50  0000 C CNN
F 1 "4k7" V 1984 7400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 2030 7400 50  0001 C CNN
F 3 "" H 2100 7400 50  0001 C CNN
	1    2100 7400
	0    1    1    0   
$EndComp
Wire Wire Line
	2500 7400 2250 7400
Wire Wire Line
	2700 7100 2700 7050
Wire Wire Line
	2700 7700 2700 7750
Wire Wire Line
	3350 5450 3350 4650
Wire Wire Line
	2500 5450 3350 5450
Connection ~ 3350 4650
Wire Wire Line
	3350 6250 3350 5450
Wire Wire Line
	2600 6250 3350 6250
Connection ~ 3350 5450
Wire Wire Line
	3350 7050 3350 6250
Wire Wire Line
	2700 7050 3350 7050
Connection ~ 3350 6250
Wire Wire Line
	2400 5350 3850 5350
Wire Wire Line
	2500 6150 3850 6150
Wire Wire Line
	2600 6950 3850 6950
Wire Wire Line
	2700 7750 3850 7750
Wire Wire Line
	2250 2900 950  2900
Wire Wire Line
	950  2900 950  5800
Wire Wire Line
	950  5800 1750 5800
Wire Wire Line
	2250 3000 850  3000
Wire Wire Line
	850  3000 850  6600
Wire Wire Line
	850  6600 1850 6600
Wire Wire Line
	2250 3100 750  3100
Wire Wire Line
	750  3100 750  7400
Wire Wire Line
	750  7400 1950 7400
Text Label 3550 5350 0    50   ~ 0
CA1
Text Label 3550 6150 0    50   ~ 0
CA2
Text Label 3550 6950 0    50   ~ 0
CA3
Text Label 3550 7750 0    50   ~ 0
CA4
Text Notes 8500 4650 0    50   ~ 0
Digit 2
Text Notes 8500 3700 0    50   ~ 0
Digit 1
Text Notes 8500 2750 0    50   ~ 0
Digit 0\n(least significant/rightmost)
Wire Wire Line
	9000 3050 8450 3050
Text Label 8500 3050 0    50   ~ 0
CA4
Wire Wire Line
	9500 3450 9950 3450
Text Label 9800 3450 0    50   ~ 0
CA4
Wire Wire Line
	9500 3050 9950 3050
Text Label 9850 3050 0    50   ~ 0
A
Wire Wire Line
	9500 3150 9950 3150
Text Label 9850 3150 0    50   ~ 0
B
Wire Wire Line
	9500 3250 9950 3250
Text Label 9850 3250 0    50   ~ 0
C
Wire Wire Line
	9000 3450 8450 3450
Text Label 8500 3450 0    50   ~ 0
D
Wire Wire Line
	9000 3150 8450 3150
Text Label 8500 3150 0    50   ~ 0
F
Wire Wire Line
	9000 3250 8450 3250
Text Label 8500 3250 0    50   ~ 0
G
Wire Wire Line
	2250 1500 1500 1500
Wire Wire Line
	2250 3300 1650 3300
Wire Wire Line
	2250 3400 1650 3400
Wire Wire Line
	2250 3500 1650 3500
Text Label 1750 3300 0    50   ~ 0
MOSI
Text Label 1750 3400 0    50   ~ 0
MISO
Text Label 1750 3500 0    50   ~ 0
SCK
Text Notes 8850 2500 0    50   ~ 0
Hex displays are HDSP-F501\nor similar (DIP 10, common\nanode). Adjust current limiting\nresistors (R1-R7) to suit.
Wire Wire Line
	7300 5300 6950 5300
Wire Wire Line
	7300 5400 6850 5400
Wire Wire Line
	7300 5500 6250 5500
Wire Wire Line
	7300 5600 6250 5600
Wire Wire Line
	7300 5700 6250 5700
Wire Wire Line
	7300 5800 6250 5800
Wire Wire Line
	6950 5300 6950 5950
$Comp
L power:GND #PWR05
U 1 1 606580A8
P 6950 5950
F 0 "#PWR05" H 6950 5700 50  0001 C CNN
F 1 "GND" H 6955 5777 50  0000 C CNN
F 2 "" H 6950 5950 50  0001 C CNN
F 3 "" H 6950 5950 50  0001 C CNN
	1    6950 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 5400 6850 5150
$Comp
L power:VCC #PWR04
U 1 1 606730D8
P 6850 5150
F 0 "#PWR04" H 6850 5000 50  0001 C CNN
F 1 "VCC" H 6867 5323 50  0000 C CNN
F 2 "" H 6850 5150 50  0001 C CNN
F 3 "" H 6850 5150 50  0001 C CNN
	1    6850 5150
	1    0    0    -1  
$EndComp
Text Label 6300 5500 0    50   ~ 0
MISO
Text Label 6300 5600 0    50   ~ 0
SCK
Text Label 6300 5700 0    50   ~ 0
~RESET
Text Label 6300 5800 0    50   ~ 0
MOSI
Text Notes 6650 4900 0    50   ~ 0
AVR programming\nheader
Wire Wire Line
	5050 5150 5400 5150
Wire Wire Line
	5400 5150 5400 5000
Wire Wire Line
	5050 5250 5400 5250
Wire Wire Line
	5400 5250 5400 5400
$Comp
L power:VCC #PWR0101
U 1 1 606C797B
P 5400 4900
F 0 "#PWR0101" H 5400 4750 50  0001 C CNN
F 1 "VCC" H 5417 5073 50  0000 C CNN
F 2 "" H 5400 4900 50  0001 C CNN
F 3 "" H 5400 4900 50  0001 C CNN
	1    5400 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 606C80BF
P 5400 5500
F 0 "#PWR0102" H 5400 5250 50  0001 C CNN
F 1 "GND" H 5405 5327 50  0000 C CNN
F 2 "" H 5400 5500 50  0001 C CNN
F 3 "" H 5400 5500 50  0001 C CNN
	1    5400 5500
	1    0    0    -1  
$EndComp
$Comp
L device:C C1
U 1 1 606D296E
P 5700 5200
F 0 "C1" H 5815 5246 50  0000 L CNN
F 1 "100nF" H 5815 5155 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 5738 5050 50  0001 C CNN
F 3 "" H 5700 5200 50  0001 C CNN
	1    5700 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5050 5700 5000
Wire Wire Line
	5700 5000 5400 5000
Connection ~ 5400 5000
Wire Wire Line
	5400 5000 5400 4900
Wire Wire Line
	5700 5350 5700 5400
Wire Wire Line
	5700 5400 5400 5400
Connection ~ 5400 5400
Wire Wire Line
	5400 5400 5400 5500
Text Notes 5050 4600 0    50   ~ 0
Power connector\nand decoupling cap
Wire Wire Line
	5400 6200 4750 6200
Wire Wire Line
	5400 6300 4750 6300
Wire Wire Line
	5400 6400 4750 6400
Wire Wire Line
	5400 6500 4750 6500
Wire Wire Line
	5400 6600 4750 6600
Wire Wire Line
	5400 6700 4750 6700
Wire Wire Line
	5400 6800 4750 6800
Wire Wire Line
	5400 6900 4750 6900
Wire Wire Line
	5400 7000 4750 7000
Wire Wire Line
	5400 7100 4750 7100
Wire Wire Line
	5400 7200 4750 7200
Wire Wire Line
	5400 7300 4750 7300
Wire Wire Line
	5400 7400 4750 7400
Wire Wire Line
	5400 7500 4750 7500
Wire Wire Line
	5400 7600 4750 7600
Wire Wire Line
	5400 7700 4750 7700
Text Label 4800 6200 0    50   ~ 0
D0
Text Label 4800 6300 0    50   ~ 0
D1
Text Label 4800 6400 0    50   ~ 0
D2
Text Label 4800 6500 0    50   ~ 0
D3
Text Label 4800 6600 0    50   ~ 0
D4
Text Label 4800 6700 0    50   ~ 0
D5
Text Label 4800 6800 0    50   ~ 0
D6
Text Label 4800 6900 0    50   ~ 0
D7
Text Label 4800 7000 0    50   ~ 0
D8
Text Label 4800 7100 0    50   ~ 0
D9
Text Label 4800 7200 0    50   ~ 0
D10
Text Label 4800 7300 0    50   ~ 0
D11
Text Label 4800 7400 0    50   ~ 0
D12
Text Label 4800 7500 0    50   ~ 0
D13
Text Label 4800 7600 0    50   ~ 0
D14
Text Label 4800 7700 0    50   ~ 0
D15
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 6044CE3B
P 4850 5250
F 0 "J5" H 4768 4925 50  0000 C CNN
F 1 "Conn_01x02" H 4768 5016 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4850 5250 50  0001 C CNN
F 3 "~" H 4850 5250 50  0001 C CNN
	1    4850 5250
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x16 J6
U 1 1 6044F3A1
P 5600 6900
F 0 "J6" H 5680 6892 50  0000 L CNN
F 1 "Conn_01x16" H 5680 6801 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Vertical" H 5600 6900 50  0001 C CNN
F 3 "~" H 5600 6900 50  0001 C CNN
	1    5600 6900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J7
U 1 1 604FDEE5
P 7500 5500
F 0 "J7" H 7580 5492 50  0000 L CNN
F 1 "Conn_01x06" H 7580 5401 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 7500 5500 50  0001 C CNN
F 3 "~" H 7500 5500 50  0001 C CNN
	1    7500 5500
	1    0    0    -1  
$EndComp
Text Notes 8500 5700 0    50   ~ 0
Digit 3\n(most significant/leftmost)
Wire Wire Line
	9000 3350 8450 3350
Text Label 8500 3350 0    50   ~ 0
E
Wire Wire Line
	9000 4000 8450 4000
Text Label 8500 4000 0    50   ~ 0
CA3
Wire Wire Line
	9000 4400 8450 4400
Text Label 8500 4400 0    50   ~ 0
D
Wire Wire Line
	9000 4100 8450 4100
Text Label 8500 4100 0    50   ~ 0
F
Wire Wire Line
	9000 4200 8450 4200
Text Label 8500 4200 0    50   ~ 0
G
Wire Wire Line
	9000 4300 8450 4300
Text Label 8500 4300 0    50   ~ 0
E
Wire Wire Line
	9000 4950 8450 4950
Text Label 8500 4950 0    50   ~ 0
CA2
Wire Wire Line
	9000 5350 8450 5350
Text Label 8500 5350 0    50   ~ 0
D
Wire Wire Line
	9000 5050 8450 5050
Text Label 8500 5050 0    50   ~ 0
F
Wire Wire Line
	9000 5150 8450 5150
Text Label 8500 5150 0    50   ~ 0
G
Wire Wire Line
	9000 5250 8450 5250
Text Label 8500 5250 0    50   ~ 0
E
Wire Wire Line
	9000 6000 8450 6000
Text Label 8500 6000 0    50   ~ 0
CA1
Wire Wire Line
	9000 6400 8450 6400
Text Label 8500 6400 0    50   ~ 0
D
Wire Wire Line
	9000 6100 8450 6100
Text Label 8500 6100 0    50   ~ 0
F
Wire Wire Line
	9000 6200 8450 6200
Text Label 8500 6200 0    50   ~ 0
G
Wire Wire Line
	9000 6300 8450 6300
Text Label 8500 6300 0    50   ~ 0
E
Wire Wire Line
	9500 4400 9950 4400
Text Label 9800 4400 0    50   ~ 0
CA3
Wire Wire Line
	9500 4000 9950 4000
Text Label 9850 4000 0    50   ~ 0
A
Wire Wire Line
	9500 4100 9950 4100
Text Label 9850 4100 0    50   ~ 0
B
Wire Wire Line
	9500 4200 9950 4200
Text Label 9850 4200 0    50   ~ 0
C
Wire Wire Line
	9500 5350 9950 5350
Text Label 9800 5350 0    50   ~ 0
CA2
Wire Wire Line
	9500 4950 9950 4950
Text Label 9850 4950 0    50   ~ 0
A
Wire Wire Line
	9500 5050 9950 5050
Text Label 9850 5050 0    50   ~ 0
B
Wire Wire Line
	9500 5150 9950 5150
Text Label 9850 5150 0    50   ~ 0
C
Wire Wire Line
	9500 6400 9950 6400
Text Label 9800 6400 0    50   ~ 0
CA1
Wire Wire Line
	9500 6000 9950 6000
Text Label 9850 6000 0    50   ~ 0
A
Wire Wire Line
	9500 6100 9950 6100
Text Label 9850 6100 0    50   ~ 0
B
Wire Wire Line
	9500 6200 9950 6200
Text Label 9850 6200 0    50   ~ 0
C
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J1
U 1 1 6060FA50
P 9200 3250
F 0 "J1" H 9250 3667 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 9250 3576 50  0000 C CNN
F 2 "Package_DIP:DIP-10_W7.62mm" H 9200 3250 50  0001 C CNN
F 3 "~" H 9200 3250 50  0001 C CNN
	1    9200 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J2
U 1 1 60639211
P 9200 4200
F 0 "J2" H 9250 4617 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 9250 4526 50  0000 C CNN
F 2 "Package_DIP:DIP-10_W7.62mm" H 9200 4200 50  0001 C CNN
F 3 "~" H 9200 4200 50  0001 C CNN
	1    9200 4200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J3
U 1 1 6064A1C9
P 9200 5150
F 0 "J3" H 9250 5567 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 9250 5476 50  0000 C CNN
F 2 "Package_DIP:DIP-10_W7.62mm" H 9200 5150 50  0001 C CNN
F 3 "~" H 9200 5150 50  0001 C CNN
	1    9200 5150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Counter_Clockwise J4
U 1 1 6064A521
P 9200 6200
F 0 "J4" H 9250 6617 50  0000 C CNN
F 1 "Conn_02x05_Counter_Clockwise" H 9250 6526 50  0000 C CNN
F 2 "Package_DIP:DIP-10_W7.62mm" H 9200 6200 50  0001 C CNN
F 3 "~" H 9200 6200 50  0001 C CNN
	1    9200 6200
	1    0    0    -1  
$EndComp
NoConn ~ 9500 3350
NoConn ~ 9500 4300
NoConn ~ 9500 5250
NoConn ~ 9500 6300
Text Notes 4950 700  0    50   ~ 0
atmega324, 644, and 1284 variants in\nTQFP-44 packages should also work
$EndSCHEMATC
