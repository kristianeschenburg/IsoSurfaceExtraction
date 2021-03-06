#ifndef ISO_SURFACE_EXTRACTION_INCLUDED
#define ISO_SURFACE_EXTRACTION_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int IsoSurfaceExtractionFile( FILE* fp, int SmoothIterations, bool Float, float *Dims, int *Resolution, float IsoValue, bool Out, char *filename, bool Polygons, bool FullCaseTable, bool QuadraticFit, bool FlipOrientation, bool NonManifold );
int IsoSurfaceExtractionVoxelGrid( uint32_t* grid, int SmoothIterations, float *Dims, int *Resolution, float IsoValue, bool Out, char *filename, bool Polygons, bool FullCaseTable, bool QuadraticFit, bool FlipOrientation, bool NonManifold );
float    LinearInterpolant( float x1 , float x2 , float isoValue );
float QuadraticInterpolant( float x0 , float x1 , float x2 , float x3 , float isoValue );

#endif
