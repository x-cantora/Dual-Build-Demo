build_pc:
	cmake -GNinja --toolchain tools/gcc.cmake -Bbuild/gcc -DPC=1
	cmake --build build/gcc

build_target:
	echo "To Do: Implement this"

clean:
	rm -rf build/*