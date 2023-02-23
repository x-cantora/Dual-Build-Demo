build_pc:
	cmake -GNinja --toolchain tools/gcc.cmake -Bbuild/gcc -DPC=1 -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/gcc

build_target:
	cmake -GNinja --toolchain tools/avr.cmake -Bbuild/avr -DPC=0
	cmake --build build/avr

flash_target:
	avr-objdump -h -S build/avr/bin/DualBuildDemo > build/avr/bin/DualBuildDemo.lst
	avr-objcopy -j .text -j .data -I ihex build/avr/bin/DualBuildDemo build/avr/bin/DualBuildDemo.hex
	avrdude -p m2560 -c wiring -D -P $(target) -b 115200 -F -U flash:w:build/avr/bin/DualBuildDemo.hex

clean:
	rm -rf build/*