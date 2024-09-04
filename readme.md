# Open95Keygen

_by Alex Free_

Open95Keygen is a portable open source program that generates random valid Product Keys (both OEM and Retail types) for Microsoft's Windows 95 and Windows NT 4.0 operating systems.

The Windows 95/NT 4.0 OEM/Retail Product Key algorithms have been reverse engineered by many people. Open95Keygen is a **[clean room design](https://en.wikipedia.org/wiki/Clean_room_design)** implementation not based on any existing software, it is written based on the specifications of the algorithm which is **inherently not copyright infringement**. I was inspired to write Open95Keygen after watching the YouTuber [stack smashing's](https://www.youtube.com/channel/UC3S8vxwRfqLBdIhgRlDRVzw) video [Why 111-1111111 is a valid Windows 95 key](https://www.youtube.com/watch?v=cwyH59nACzQ).

| [GitHub](https://github.com/alex-free/open95keygen) | [HomePage](https://alex-free.github.io/open95keygen) |

## Table Of Contents

* [Downloads](#downloads)
* [Usage](#usage)
* [Building From Source](#building-from-source)
* [License](#license)

## Downloads

### Version 1.0.3 (9/3/2024)

Changes:

* Implemented my [ezre](https://github.com/alex-free/ezre) build system.

* Bug fix for [issue #2](https://github.com/alex-free/open95keygen/issues/2). The last digit of the 'divisible by 7 with no remainder' portion of OEM keys is now checked to ensure it is not 0, 8, or 9. No more invalid keys.

* Cleaned up code and documentation.

----------------------------------------------------

*	[open95keygen-v1.0.3-windows-i686-static.zip](https://github.com/alex-free/open95keygen/releases/download/v1.0.3/open95keygen-v1.0.3-windows-i686-static.zip) _Portable Release For Windows 95 OSR 2.5 and above, Pentium CPU minimum (32 bit)_

*	[open95keygen-v1.0.3-windows-x86\_64-static.zip](https://github.com/alex-free/open95keygen/releases/download/v1.0.3/open95keygen-v1.0.3-windows-x86_64-static.zip) _Portable Release For x86_64 Windows (64 bit)_

*	[open95keygen-v1.0.3-linux-i386-static.zip](https://github.com/alex-free/open95keygen/releases/download/v1.0.3/open95keygen-v1.0.3-linux-i386-static.zip) _Portable Release For Linux 3.2.0 and above, 386 CPU minimum (32 bit)_

*	[open95keygen-v1.0.3-linux-i386-static.deb](https://github.com/alex-free/open95keygen/releases/download/v1.0.3/open95keygen-v1.0.3-linux-i386-static.deb) _Deb package file For Linux 3.2.0 and above, 386 CPU minimum (32 bit)_

*	[open95keygen-v1.0.3-linux-x86\_64-static.zip](https://github.com/alex-free/open95keygen/releases/download/v1.0.3/open95keygen-v1.0.3-linux-x86_64-static.zip) _Portable Release For x86\_64 Linux 3.2.0 and above (64 bit)_

*	[open95keygen-v1.0.3-linux-x86\_64-static.deb](https://github.com/alex-free/open95keygen/releases/download/v1.0.3/open95keygen-v1.0.3-linux-x86_64-static.deb) _Deb package file for x86_64 Linux 3.2.0 and above (64 bit)_

---------------------------------------

[Previous versions](changelog.md)

## Usage

This is a command line program, so on Windows you first must open the `command.com` or `cmd.exe` program. Then just drag o95kg.exe into the `command.com` or `cmd.exe` window and press the `enter` or `return` key.

On Linux, you may be able to just double click the `o95kg` file to start Open95Keygen. If this does not work, start your terminal program and execute `./o95kg` from inside the release directory.

### OEM or Retail?

On Windows 95/NT 4.0, if you see the word OEM in between where you enter the Product Key, use the generated OEM Product Key. If you do not see the word OEM when asked to enter a Product Key, use the generated Retail Product Key:

### Retail:

![Retail Windows 95 enter key](images/win95_retail_enter_key.png)

### OEM:

![OEM Windows 95 enter key](images/win95_oem_enter_key.png)

## License

Open95Keygen is released under the 3-BSD license, see the file [license.md](license.md).