math.wasm: math.cpp
	em++ math.cpp -s WASM=1 -s SIDE_MODULE=1 -s ONLY_MY_CODE=1 -Oz -o math.wasm

clean:
	rm *.wasm
