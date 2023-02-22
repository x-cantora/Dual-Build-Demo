build_pc:
	cmake -GNinja --toolchain tools/gcc.cmake -Bbuild/gcc -DPC=1
	cmake --build build/gcc

build_target:
	cmake -GNinja --toolchain tools/avr.cmake -Bbuild/avr -DPC=0
	cmake --build build/avr

flash_target:
	avr-objdump -h -S build/avr/bin/DualBuildDemo > build/avr/DualBuildDemo.lst
	avr-objcopy -j .text -j .data -I ihex build/avr/bin/DualBuildDemo build/avr/bin/DualBuildDemo.hex
	avrdude -b115200 -carduino -patmega328p -U flash:w:build/avr/bin/DualBuildDemo.hex -P $(target)

clean:
	rm -rf build/*