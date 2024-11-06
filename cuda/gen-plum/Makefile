
BINARY = gen-plum.exe

all:
	gcc gen-plum.c -o $(BINARY) -lm


c: clean

clean:
	rm -rf $(BINARY) *~ .*~ *.o
	rm -f ./data.inp*


generates:
	./gen-plum.exe 1; mv ./data.inp ./data.inp.0001024
	./gen-plum.exe 2; mv ./data.inp ./data.inp.0002048
	./gen-plum.exe 4; mv ./data.inp ./data.inp.0004096
	./gen-plum.exe 8; mv ./data.inp ./data.inp.0008192
	./gen-plum.exe 16; mv ./data.inp ./data.inp.0016384
	./gen-plum.exe 32; mv ./data.inp ./data.inp.0032768
	./gen-plum.exe 64; mv ./data.inp ./data.inp.0065536
	./gen-plum.exe 128; mv ./data.inp ./data.inp.0131072
	./gen-plum.exe 256; mv ./data.inp ./data.inp.0262144
	./gen-plum.exe 512; mv ./data.inp ./data.inp.0524288
	./gen-plum.exe 1024; mv ./data.inp ./data.inp.1048576
	cp ./backup/data.inp.0000128 ./
	cp ./backup/data.inp.0000256 ./
	cp ./backup/data.inp.0000512 ./
	sha256sum --check ./sha256sum.txt
