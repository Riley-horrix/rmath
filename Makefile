all:
	@ mkdir -p build;\
	cd build;\
	cmake ..;\
	make;\
	cd ..

test:
	@ pushd build;\
	make;\
	ctest --output-on-failure;\
	popd

.PHONY: all test