# Open95Keygen GNUMakefile by Alex Free
CC=gcc
CFLAGS=-Wall -Werror
VER=1.0.2

o95kg: clean
	$(CC) $(CFLAGS) o95kg.c -o o95kg

clean:
	rm -rf o95kg.exe o95kg

fedora-deps:
	sudo dnf install zip gcc glibc-devel glibc-devel.i686 glibc-static glibc-static.i686 make mingw32-gcc mingw64-gcc

linux-x86:
	make o95kg CFLAGS="-m32 -static -Wall -Werror -Ofast"

linux-x86_64:
	make o95kg CFLAGS="-static -Wall -Werror -Ofast"

windows-x86:
	make o95kg CC="i686-w64-mingw32-gcc"

windows-x86_64:
	make o95kg CC="x86_64-w64-mingw32-gcc"

linux-release:
	rm -rf open95keygen-$(VER)-$(PLATFORM) open95keygen-$(VER)-$(PLATFORM).zip
	mkdir open95keygen-$(VER)-$(PLATFORM)
	cp -rv o95kg images readme.md license.txt open95keygen-$(VER)-$(PLATFORM)
	chmod -R 777 open95keygen-$(VER)-$(PLATFORM)
	zip -r open95keygen-$(VER)-$(PLATFORM).zip open95keygen-$(VER)-$(PLATFORM)
	rm -rf open95keygen-$(VER)-$(PLATFORM)

windows-release:
	rm -rf open95keygen-$(VER)-$(PLATFORM) open95keygen-$(VER)-$(PLATFORM).zip
	mkdir open95keygen-$(VER)-$(PLATFORM)
	cp -rv o95kg.exe images readme.md license.txt open95keygen-$(VER)-$(PLATFORM)
	chmod -R 777 open95keygen-$(VER)-$(PLATFORM)
	zip -r open95keygen-$(VER)-$(PLATFORM).zip open95keygen-$(VER)-$(PLATFORM)
	rm -rf open95keygen-$(VER)-$(PLATFORM)

linux-x86-release: linux-x86
	make linux-release PLATFORM=linux_x86

linux-x86_64-release: linux-x86_64
	make linux-release PLATFORM=linux_x86_64

windows-x86-release: windows-x86
	make windows-release PLATFORM=windows_x86

windows-x86_64-release: windows-x86_64
	make windows-release PLATFORM=windows_x86_64

clean-zip: clean
	rm -rf *.zip

all: linux-x86-release linux-x86_64-release windows-x86-release windows-x86_64-release
