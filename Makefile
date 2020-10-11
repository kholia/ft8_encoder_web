# https://raw.githubusercontent.com/emscripten-core/emscripten/master/src/shell_minimal.html
# https://gist.github.com/bd1es/a782e2529b8289288fadd35e407f6440

stuff:
	emcc hello.c ft8_enc_top.cpp gen_ft8.cpp fft/*.c ft8/*.cpp -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s "EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" -s EXPORTED_FUNCTIONS="['_malloc', '_main']" -o ft8_encoder.html --shell-file html_template/shell_minimal.html

	cp ft8_encoder* ~/repos/kholia.github.io/

copy:
	cp ft8_encoder* ~/repos/kholia.github.io/

run:
	python3 -m http.server

check:
	tidy ft8_encoder.html
