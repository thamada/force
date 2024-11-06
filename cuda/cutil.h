#ifndef CUTIL_H_
#define CUTIL_H_
#include <stdio.h>
#include <stdlib.h>

inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

#define CUDA_SAFE_CALL(ans) { gpuAssert((ans), __FILE__, __LINE__); }

#define CUT_CHECK_ERROR(message) { \
	cudaError_t stat = cudaGetLastError(); \
	if ( stat != cudaSuccess ) { \
		fprintf(stderr, "cuda error %s: stat %x, file '%s', line %i.\n", message, (unsigned int)stat, __FILE__, __LINE__ ); \
                exit(EXIT_FAILURE); \
	} \
}

#endif
