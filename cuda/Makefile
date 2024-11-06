#-------------------- 
#CUDACODE = code1
#CUDACODE = code2
#CUDACODE = code3
#CUDACODE = code4
CUDACODE = code5
#CUDACODE = code6
#--------------------

CXX = g++
INCLUDES  = -I. -I$(CUDA_INSTALL_PATH)/include -I$(SDK_INSTALL_PATH)/common/inc
MAIN = main
TARGET = run.x

all: $(TARGET)


c: clean

clean : 
	rm -f ${TARGET}
	rm -f *~ .*~ *.o
	rm -f $(CUDACODE).ptx

CXXFLAGS = -Wall -Ofast
LDFLAGS = -lm -lcudart -L /usr/local/cuda/lib64

${TARGET} : main.o ${CUDACODE}.o
	$(CXX) $^ -o $@ $(LDFLAGS)

$(MAIN).o : $(MAIN).cc

$(CUDACODE).o : $(CUDACODE).cu
	nvcc  --x 'cu' -c $(CUDACODE).cu -Xcompiler "-m64" -Xcompiler "-O3" -Xcompiler "-ffast-math" --machine 64 -DUNIX -O3 $(INCLUDES)
	rm  -f kernel.o
	ln -s $(CUDACODE).o kernel.o

ptx : clean
	nvcc  --host-compilation 'C++' cunbody_lib.cu --ptx $(INCLUDES)


cubin:
	nvcc  --host-compilation 'C++' -cubin dummy_main.cu  $(INCLUDES)
	grep smem dummy_main.cubin
	grep reg dummy_main.cubin

export:
	tar cjvf ../cuda.`date +"%Y%m%d-%H%M%S"`.tbz ../cuda


b: export

t: test

test:
	./run.x gen-plum/data.inp.131072 10

logs:
	./run.x gen-plum/backup/data.inp.000128 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.000256 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.000512 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.001024 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.002048 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.004096 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.008192 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.016384 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.032768 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.065536 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.131072 16 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.262144  8 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.524288  8 |tee -a /tmp/log.txt
	./run.x gen-plum/backup/data.inp.1M 4      |tee -a /tmp/log.txt
