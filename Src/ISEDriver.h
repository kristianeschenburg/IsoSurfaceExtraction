#ifndef ISE_DRIVER_INCLUDED
#define ISE_DRIVER_INCLUDED

#include <Src/IsoSurfaceExtraction.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
#include <cstring>
#else
#include <string.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

  void ExtractIsoSurfaceDriver( uint32_t *grid, uint32_t *dims, int *res, float isoValue, bool flip );
  void alexTest( float x, unsigned int *y );

#ifdef __cplusplus
}
#endif

#endif
