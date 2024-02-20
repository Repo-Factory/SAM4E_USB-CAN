# SAM4E_CAN

This Project aims to create a USB-CAN Driver targeted for the SAM4E platform using an XplainedPro board.

## Building/Linking/Flashing

Atmel encourages their use of Atmel Studio to deal with the workflow of the SAM chip but the software is only available on Windows. Instead here, a custom CMakeLists.txt was made for the build and openocd is utilized for the flashing process to code from an adequate OS. Please refer to the [compile.txt](compile.txt) file to see a bit on the building and flashing process for the chip from linux.

## Getting Started

Clone this repository

    git clone https://github.com/Repo-Factory/SAM4E_USB-CAN

`ASF` - Will hold some libraries and modules included from manufacturer with header definitions and functions to use
`config` - Provided by Atmel, no need to touch
`utilities` - Will hold helper functions
`projects` - Will hold source code individual to this project 

To build a specific project, go the CMakeLists.txt and add the project files to the src list. 