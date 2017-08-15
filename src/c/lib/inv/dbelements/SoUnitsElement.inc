/*
 *
 *  Copyright (C) 2000 Silicon Graphics, Inc.  All Rights Reserved. 
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  Further, this software is distributed without any warranty that it is
 *  free of the rightful claim of any third person regarding infringement
 *  or the like.  Any license provided herein, whether implied or
 *  otherwise, applies only to this software file.  Patent licenses, if
 *  any, provided herein do not apply to combinations of this program with
 *  other software, or any other product whatsoever.
 * 
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,
 *  Mountain View, CA  94043, or:
 * 
 *  http://www.sgi.com 
 * 
 *  For further information regarding this notice, see: 
 * 
 *  http://oss.sgi.com/projects/GenInfo/NoticeExplan/
 *
 */

/*
 * Copyright (C) 1990,91   Silicon Graphics, Inc.
 *
 _______________________________________________________________________
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 |
 |   $Revision: 22147 $
 |
 |   Classes:
 |	SoUnitsElement
 |
 |   Author(s)		: Paul S. Strauss
 |
 ______________  S I L I C O N   G R A P H I C S   I N C .  ____________
 _______________________________________________________________________
 */

#include "inv/elements/SoUnitsElement.H"

SO_ELEMENT_SOURCE(SoUnitsElement);

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Destructor.
//
// Use: private

SoUnitsElement::~SoUnitsElement()
//
////////////////////////////////////////////////////////////////////////
{
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Initializes element
//
// Use: public

void
SoUnitsElement::init(SoState *)
//
////////////////////////////////////////////////////////////////////////
{
    data = getDefault();
}

////////////////////////////////////////////////////////////////////////
//
// Description:
//    Prints element for debugging.
//
// Use: public
//
////////////////////////////////////////////////////////////////////////

#ifdef DEBUG
void
SoUnitsElement::print(FILE *fp) const
{
    const char *unitsName;

    SoElement::print(fp);

    switch ((Units)data) {

      case METERS:
	unitsName = "METERS";
	break;

      case CENTIMETERS:
	unitsName = "CENTIMETERS";
	break;

      case MILLIMETERS:
	unitsName = "MILLIMETERS";
	break;

      case MICROMETERS:
	unitsName = "MICROMETERS";
	break;

      case MICRONS:
	unitsName = "MICRONS";
	break;

      case NANOMETERS:
	unitsName = "NANOMETERS";
	break;

      case ANGSTROMS:
	unitsName = "ANGSTROMS";
	break;

      case KILOMETERS:
	unitsName = "KILOMETERS";
	break;

      case FEET:
	unitsName = "FEET";
	break;

      case INCHES:
	unitsName = "INCHES";
	break;

      case POINTS:
	unitsName = "POINTS";
	break;

      case YARDS:
	unitsName = "YARDS";
	break;

      case MILES:
	unitsName = "MILES";
	break;

      case NAUTICAL_MILES:
	unitsName = "NAUTICAL_MILES";
	break;
    }

    fprintf(fp, "\tUnits = %s\n", unitsName);
}
#else  /* DEBUG */
void
SoUnitsElement::print(FILE *) const
{
}
#endif /* DEBUG */