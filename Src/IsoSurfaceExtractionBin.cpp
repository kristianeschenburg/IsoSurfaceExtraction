/*
Copyright (c) 2015, Michael Kazhdan
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of
conditions and the following disclaimer. Redistributions in binary form must reproduce
the above copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the distribution.

Neither the name of the Johns Hopkins University nor the names of its contributors
may be used to endorse or promote products derived from this software without specific
prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.
*/

#include "IsoSurfaceExtraction.h"

#include <Src/CmdLineParser.h>

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <map>
#include <algorithm>

void ShowUsage( const char* ex );

const float DEFAULT_DIMENSIONS[] = { 1.f , 1.f , 1.f };
cmdLineParameter< char* > In( "in" ) , Out( "out" );
cmdLineParameterArray< int , 3 > Resolution( "res" );
cmdLineParameter< int > SmoothIterations( "sIters" , 0 );
cmdLineParameter< float > IsoValue( "iso" , 0.f );
cmdLineParameterArray< float , 3 > Dimensions( "dim" , DEFAULT_DIMENSIONS );
cmdLineReadable Float( "float" ) , FullCaseTable( "full" ) , FlipOrientation( "flip" ) , QuadraticFit( "quadratic" ) , Polygons( "polygons" ) , NonManifold( "nonManifold" );

cmdLineReadable* params[] = { &In , &Out , &Resolution , &IsoValue , &FullCaseTable , &FlipOrientation , &QuadraticFit , &Polygons , &SmoothIterations , &Float , &Dimensions , &NonManifold , NULL };

void ShowUsage( const char* ex )
{
	printf( "Usage %s:\n" , ex );
	printf( "\t --%s <input voxel grid>\n" , In.name );
	printf( "\t --%s <input resolution>\n" , Resolution.name );
	printf( "\t[--%s <output iso-surface>]\n" , Out.name );
	printf( "\t[--%s <iso-value>=%f]\n" , IsoValue.name , IsoValue.value );
	printf( "\t[--%s <smoothing iterations>=%d]\n" , SmoothIterations.name , SmoothIterations.value );
	printf( "\t[--%s <dimensions of a voxel>=%f %f %f]\n" , Dimensions.name , Dimensions.values[0] , Dimensions.values[1] , Dimensions.values[2] );
	printf( "\t[--%s]\n" , FullCaseTable.name );
	printf( "\t[--%s]\n" , FlipOrientation.name );
	printf( "\t[--%s]\n" , QuadraticFit.name );
	printf( "\t[--%s]\n" , Polygons.name );
	printf( "\t[--%s]\n" , NonManifold.name );
	printf( "\t[--%s]\n" , Float.name );
}

int main( int argc , char* argv[] )
{
	cmdLineParse( argc-1 , argv+1 , params );
	if( !Resolution.set && !In.set ){ ShowUsage( argv[0] ) ; return EXIT_FAILURE; }

	FILE* fp = fopen( In.value , "rb" );
	if( !fp )
	{
		fprintf( stderr , "[ERROR] Failed to open file for reading: %s\n" , In.value );
		return EXIT_FAILURE;
	}

  char *filename = Out.set ? Out.value : NULL;

  return IsoSurfaceExtraction( fp, SmoothIterations.value, Float.set, Dimensions.values, Resolution.values, IsoValue.value, Out.set, filename, Polygons.set, FullCaseTable.set, QuadraticFit.set, FlipOrientation.set, NonManifold.set );

	return EXIT_SUCCESS;
}
