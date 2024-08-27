# SMART HOME AUTOMATION using HC 05 Bluetooth Module:
# Introduction:
- This project involves automatic controlling of home appliances using completely different technologies and controllers over desktops, laptops, phones or tablets.
# Features:
- This project is implemented in 2 modes
  1. Bluetooth mode (default mode)
  2. Manual mode
# Working:
- Implemented smart phone based home automation project using HC 05 Bluetooth Module.
- External Interrupt is used to select the mode between default Bluetooth mode and Manual mode with every switch press.
  - MANUAL MODE:
    - LED3 is in ON state when in manual mode and in OFF state for BT mode.
    - SW1 is used to control the light bulb.
    - SW2 is used to control the fan.
  - BLUETOOTH MODE:
    - The menu is displayed as below on BT terminal for the user to select from:
      Menu\:
      - a/A Bulb ON
      - b/B Bulb OFF
      - c/C Fan ON
      - d/D Fan OFF
      - e/E Both ON
      - f/F Both OFF
    - Here, UART interrupt is used to give input command to control the home appliances accordingly.
# Test file:
- smart_home_automation.hex link:
  https://github.com/karravennela/SMART_HOME_AUTOMATION_using_HC05-BTmodule_and__Interrupts/blob/main/smart_home_automation.hex
