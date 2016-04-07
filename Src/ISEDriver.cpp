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

  // allocate an array for our grid data and copy in grid data
  /*
  Pointer( float ) voxelValues = NewPointer< float >( Resolution[0] * Resolution[1] * Resolution[2] );
  if( !voxelValues )
	{
		fprintf( stderr , "[ERROR] Failed to allocte voxel grid: %d x %d x %d\n" , Resolution[0] , Resolution[1] , Resolution[2] );
		//return EXIT_FAILURE;
	}
  #pragma omp parallel for
    for( int i=0 ; i<Resolution[0]*Resolution[1]*Resolution[2] ; i++ )
      voxelValues[i] = (float)grid[i];
    //DeletePointer( _voxelValues );
    */




  //LoadGrid( grid, dims );

  // create an array to transcribe the input data into
  //Pointer( float ) voxelValues = NewPointer< float >( dims[0]*dims[1]*dims[2] );

  //for (int i = 0; i <dims[0]*dims[1]*dims[2]; i++)
  //  voxelValues[i] = (float)grid[i];

}

// void ExtractIsoSurface( int resX , int resY , int resZ , ConstPointer( float ) values , float isoValue , std::vector< IsoVertex >& vertices , std::vector< std::vector< int > >& polygons, std::vector< std::vector< int > >& polygon_cubes , bool fullCaseTable , bool quadratic , bool flip )



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
