#include <Src/ISEDriver.h>

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#ifdef __cplusplus
extern "C" {
#endif

void ExtractIsoSurfaceDriver( uint32_t *grid, uint32_t *dims, int *Resolution, float isoValue, bool flip ) {

  printf("Received a voxel grid with first three values: %d %d %d\n", grid[0], grid[1], grid[2]);
  printf("The grid has dimensions %d x %d x %d with resolution %d x %d x %d\n", dims[0], dims[1], dims[2], Resolution[0], Resolution[1], Resolution[2]);
  if (flip == true) {
    printf("Proceeding to extract value %f with flip!\n", isoValue);
  }
  else {
    printf("Proceeding to extract value %f.\n", isoValue);
  }

  int SmoothIterations = 0;
  // ndstore has the opposite convention for dims / resolution as IsoSurfaceExtraction
  // ndstore dims = voxelgrid size = isosurfaceextraction resolution
  // ndstore resolution = size of a voxel = isosurfaceextraction dims
  float NewDims[3];
  for (int i = 0; i < 3; i++) {
    NewDims[i] = (float)Resolution[i];
  }

  int NewResolution[3];
  for (int i = 0; i < 3; i++) {
    NewResolution[i] = (int)dims[i];
  }

  printf("New dims: %f %f %f\n", NewDims[0], NewDims[1], NewDims[2]);
  printf("New Res: %d %d %d\n", NewResolution[0], NewResolution[1], NewResolution[2]);
  bool Out = true;
  char filename[] = "/tmp/test1.ply";

  bool Polygons = false; // we want triangles
  bool FullCaseTable = false;
  bool QuadraticFit = false;
  bool NonManifold = false;

  int ret = IsoSurfaceExtractionVoxelGrid( grid, SmoothIterations, NewDims, NewResolution, isoValue, Out, filename, Polygons, FullCaseTable, QuadraticFit, flip, NonManifold );

  if (ret) {
    printf("Success!\n");
  }
  else {
    printf("Failure\n");
  }

}

void alexTest( float x, unsigned int *y ) {

    char name[] = "Alex";
    printf("Hey go, it's %s in C! ", name);
    printf("Thanks for passing in %f.\n", x);
    printf("Also received the following array values: %d, %d, %d\n", y[0], y[1], y[2]);
    // what happens if we change a value?
    y[0] = 10;
    return;
}


#ifdef __cplusplus
}
#endif
