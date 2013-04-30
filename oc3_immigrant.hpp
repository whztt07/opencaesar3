// This file is part of openCaesar3.
//
// openCaesar3 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// openCaesar3 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with openCaesar3.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __OPENCAESAR3_IMMIGRANT_H_INCLUDED__
#define __OPENCAESAR3_IMMIGRANT_H_INCLUDED__

#include "oc3_walker.hpp"

class City;
class House;

/** This is an immigrant coming with his stuff */
class Immigrant : public Walker
{
public:
  static Immigrant* create( City& city, const Building& startPoint, 
                            const unsigned char peoples );

  void onDestination();
  ~Immigrant();

protected:
  virtual Immigrant* clone() const;

  void setCartPicture( Picture* pic );
  virtual Picture* getCartPicture();
  
  Immigrant( City& city, unsigned char peoples );

  void assignPath( Tile& startTile );
  void _checkPath( Tile& startPoint, Building* house );
  House* _findBlankHouse();

protected:
  void _setPeoplesCount( const unsigned char num );
  unsigned char _getPeoplesCount() const;

private:
  class Impl;
  std::auto_ptr< Impl > _d;
};

#endif