SMART HOME AUTOMATION using HC 05 Bluetooth Module:
Introduction:
- Home automation systems advancing towards mechanization processes whereby less human efforts are required by the machinery equipment to control numerous systems in homes. It involves automatic controlling of home appliances using completely different technologies and controllers over desktops, laptops good phones or tablets.
Features:
- This project is implemented in 2 modes
  1. Bluetooth mode (default mode)
  2. Manual mode
Working:
- Implemented smart phone based home automation mini-project using HC 05 Bluetooth Module.
- External Interrupt0 (EINT0 -> SW3-P0.16) is used to select the mode between default Bluetooth mode and Manual mode with every switch (SW3) press.
  - MANUAL MODE:
    - LED3 (P0.19) is in ON state when in manual mode and in OFF state for BT mode.
    - SW1 (P0.14) is used to control the light bulb.
    - SW2 (P0.15) is used to control the fan.
  - BLUETOOTH MODE:
    - In this mode, Bluetooth Terminal HC-05 app is installled on phone and connected to HC-05 module via bluetooth.
    - And hence lets you send signals to microcontroller LPC2129 so that it can perform desired operations successfully.
    - The menu is displayed as below on BT terminal for the user to select from:
      Menu\:
      - a/A Bulb ON
      - b/B Bulb OFF
      - c/C Fan ON
      - d/D Fan OFF
      - e/E Both ON
      - f/F Both OFF
    - Here, UART0 interrupt (UINT0) is used to give input command to control the home appliances accordingly. 
Test file:
smart_home_automation.hex link:
