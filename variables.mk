# Variables of EzRe GNUMakefile for Linux/Windows by Alex Free https://github.com/alex-free/ezre

# REQUIRED: Basename of all release files (.zip, .deb).
RELEASE_BASE_NAME=open95keygen
# REQUIRED: Version number, passed as 'VERSION' string to $(SOURCE_FILES).
VERSION=v1.0.3
# REQUIRED: Appeneded to end of release file name.
LINUX_I386_RELEASE_NAME_SUFFIX=linux-i386-static
LINUX_X86_64_RELEASE_NAME_SUFFIX=linux-x86_64-static
WINDOWS_I686_RELEASE_NAME_SUFFIX=windows-i686-static
WINDOWS_X86_64_RELEASE_NAME_SUFFIX=windows-x86_64-static
# Release file format is $(RELEASE_BASE_NAME)-$(VERSION)-$(RELEASE_NAME_SUFFIX).

# OPTIONAL: additional files included in all portable zip releases.
RELEASE_FILES=*.md
# OPTIONAL: files included only in the Linux portable releases (.zip).
LINUX_SPECIFIC_RELEASE_FILES=
# OPTIONAL: files included only in the Windows portable releases (.zip).
WINDOWS_SPECIFIC_RELEASE_FILES=

# All dependencies required to build the software, to be installed when using the `deps-apt` EzRe Makefile rule (For Debian/Ubuntu/Pop!OS and derivatives). This covers C and C++.
BUILD_DEPENDS_APT=build-essential g++-multilib gcc-multilib mingw-w64-tools g++-mingw-w64 zip dpkg-dev
# All dependencies required to build the software, to be installed when using the `deps-dnf` EzRe Makefile rule (For Fedora and Red Hat). This covers C and C++.
BUILD_DEPENDS_DNF=gcc g++ libstdc++-static.i686 glibc-static.i686 libstdc++-static.x86_64 mingw64-gcc mingw32-gcc mingw32-gcc-c++ mingw64-gcc-c++ zip

# REQUIRED: executable name in release (.exe file extension is appended for Windows builds).
PROGRAM=o95kg
# REQUIRED: source files to be compiled into $(PROGRAM) target. Can use wildcard (i.e. *.c, *.cpp, etc) or specify files specifically. These files are looked for in the same directory that the EZRE `Makefile` and `variables.mk` files are in (relative).
SOURCE_FILES=*.c
# REQUIRED: set to `YES` to build additional libraries (must edit Makefile with relevant info). By default this is set to `NO`.
BUILD_LIB=NO
# REQUIRED: create builds in this directory relative to $(SOURCE_FILES). THIS DIRECTORY WILL BE DELETED WHEN EXECUTING `make clean-build` so be extremely careful with what you set this to.
BUILD_DIR=build

# REQUIRED: Linux Compiler For i386 and x86_64.
LINUX_COMPILER=gcc
# OPTIONAL: Linux AR command (for building libraries with EZRE used by the target program).
AR=ar
# REQUIRED: Windows Cross Compiler For i686.
WINDOWS_I686_COMPILER=i686-w64-mingw32-gcc
# OPTIONAL: Windows i686 AR command (for building libraries with EZRE used by the target program).
WINDOWS_I686_AR=i686-w64-mingw32-ar
# REQUIRED: Windows Cross Compiler For x86_64.
WINDOWS_X86_64_COMPILER=x86_64-w64-mingw32-gcc
# OPTIONAL: Windows x86_64 AR command (for building libraries with EZRE used by the target program).
WINDOWS_X86_64_AR=x86_64-w64-mingw32-ar
# REQUIRED: Host system compiler.
COMPILER=$(LINUX_COMPILER)

# REQUIRED: compiler flags used to compile $(SOURCE_FILES). To make a C/C++ program portable, you probably at least want `-static` as shown below. I like using `-Wall -Wextra -Werror -pedantic -static` or some variation.
COMPILER_FLAGS=-static
# REQUIRED: compiler flag appended to $(COMPILER_FLAGS) to compile $(SOURCE_FILES) for Linux x86 builds. This tells GCC to build i386 code on an x86_64 system.
COMPILER_FLAGS_LINUX_X86=-m32
# OPTIONAL: You may compile a library with different CFLAGS set here. (i.e. `-Wall -Wextra -Werror -pedantic -Wno-unused-function`)
COMPILER_FLAGS_LIB=