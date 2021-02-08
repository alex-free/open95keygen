# Open95Keygen GNUmakefile, N/A for classic Mac OS
version := 1.0

o95kg: clean
	gcc o95kg.c -o o95kg
	
all: linux-static64 linux-static32 cross-win32

mac-ppc: clean
	gcc -isysroot/Developer/SDKs/MacOSX10.3.9.sdk -mmacosx-version-min=10.3 -arch ppc o95kg.c -o o95kg
	mkdir open95keygen_$(version)_mac_os_x_powerpc
	cp -rv o95kg readme.html license.txt open95keygen_$(version)_mac_os_x_powerpc/

linux-static64: clean
	gcc -static o95kg.c -o o95kg
	mkdir open95keygen_$(version)_linux_x86_64
	cp -rv o95kg readme.html license.txt open95keygen_$(version)_linux_x86_64/
linux-static32: clean
	gcc -static -m32 o95kg.c -o o95kg
	mkdir open95keygen_$(version)_linux_x86
	cp -rv o95kg readme.html license.txt open95keygen_$(version)_linux_x86/
cross-win32: clean
	i686-w64-mingw32-gcc o95kg.c -o o95kg.exe
	mkdir open95keygen_$(version)_win32
	cp -rv o95kg.exe readme.html license.txt open95keygen_$(version)_win32/
 
clean:
	rm -rf o95kg o95kg.exe open95keygen_$(version)_linux_x86_64 open95keygen_$(version)_linux_x86 open95keygen_$(version)_win32 open95keygen_$(version)_mac_os_x_powerpc

