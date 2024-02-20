# SAM4E_USB-CAN

This Project aims to create a USB-CAN Driver targeted for the SAM4E platform using an XplainedPro board.

## Building/Linking/Flashing of SAM4E XplainedPro Board

Atmel encourages their use of Atmel Studio to deal with the workflow of the SAM chip but the software is only available on Windows. Instead here, a custom CMakeLists.txt was made for the build and openocd is utilized for the flashing process to code from an adequate OS. Please refer to the [compile.txt](compile.txt) file to see a bit on the building and flashing process for the chip from linux.

## Getting Started

Clone this repository

    git clone https://github.com/Repo-Factory/SAM4E_USB-CAN

`ASF` - Will hold some libraries and modules provided by the manufacturer with header definitions and functions to use. Note that because of the custom build, only the libraries I foresee being used for the project are stored here. If others are needed, they would have to be manually included or a new build file could be made from scratch by referring to Atmel's generated Makefile after importing modules from the ASF Wizard in Atmel Studio. Note: this is pretty unpleasant.   

`config` - Provided by Atmel, no need to touch   

`utilities` - Will hold helper functions   

`projects` - Will hold source code individual to this project   

To build a specific project, go the CMakeLists.txt and add the project files to the src list. 

## Maintainers

[@Conner Sommerfield](https://github.com/Repo-Factory/)