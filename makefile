build_pc:
	cmake -GNinja --toolchain tools/gcc.cmake -Bbuild/gcc -DPC=1
	cmake --build build/gcc

build_target:
	cmake -GNinja --toolchain tools/arm.cmake -Bbuild/arm -DPC=0
	cmake --build build/arm

clean:
	rm -rf build/*