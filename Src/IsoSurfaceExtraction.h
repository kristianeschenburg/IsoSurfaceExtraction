#ifndef ISO_SURFACE_EXTRACTION_INCLUDED
#define ISO_SURFACE_EXTRACTION_INCLUDED

#include <Src/CmdLineParser.h>
#include <Src/Geometry.h>
#include <Src/Array.h>

void ShowUsage( const char* ex );

float    LinearInterpolant( float x1 , float x2 , float isoValue );
float QuadraticInterpolant( float x0 , float x1 , float x2 , float x3 , float isoValue );

void ExtractIsoSurface( int resX , int resY , int resZ , ConstPointer( float ) values , float isoValue , std::vector< Point3D< float > >& vertices , std::vector< std::vector< int > >& polygons , bool fullCaseTable , bool quadratic , bool flip );
#endif
