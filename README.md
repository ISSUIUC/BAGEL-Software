# BAGEL Bluetooth Switch Board Software

Here's the epic GitHub Repo for the software for BAGEL, our Bluetooth Switch Board!

## Getting Started

After you clone the repository, install [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) and [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html). 

CubeMX is used to configure project characteristics such as the pin functions, clock configuration, and for our application, also BLE settings (using the STM32-WPAN package). CubeMX will autogenerate code to configure those settings.

CubeIDE is what we use to write and flash the software. To open the CubeIDE project, open the `.project` file in the `BAGEL` directory and select the workspace you'd like to import it into (I personally just use the BAGEL-Software folder, though it shouldn't actually matter). To keep the repository clean, we gitignore some of the debug and release files, but these will automatically be created when you build and flash the code.

For initial setup of the BLE stack on a new BAGEL board, use of [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html) with the [STM32WB Copro Wireless Binaries](https://github.com/STMicroelectronics/STM32CubeWB/tree/master/Projects/STM32WB_Copro_Wireless_Binaries/STM32WB1x) is required. See the [STM32Wiki](https://wiki.st.com/stm32mcu/wiki/Connectivity:STM32WB_BLE_Hardware_Setup#FUS_and_wireless_stack_update) and [Release Notes](https://github.com/STMicroelectronics/STM32CubeWB/blob/master/Projects/STM32WB_Copro_Wireless_Binaries/STM32WB1x/Release_Notes.html) for more information. Make sure to press the "Start Wireless Stack" button upon completing the flashing of the binaries (I have not seen documentation about this anywhere but it seems to be required).

Have fun in all of your STM32 BLE endeavors!!