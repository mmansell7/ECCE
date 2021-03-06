/*
 * ChemSelectionElement.h
 *
 *  This file defines the ChemSelectionElement class.
 *
 * Copyright 1996, 1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 *
 * UNPUBLISHED -- Rights reserved under the copyright laws of the United
 * States.   Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 *
 * U.S. GOVERNMENT RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in FAR 52.227.19(c)(2) or subparagraph (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS 252.227-7013 and/or
 * in similar or successor clauses in the FAR, or the DOD or NASA FAR
 * Supplement.  Contractor/manufacturer is Silicon Graphics, Inc.,
 * 2011 N. Shoreline Blvd. Mountain View, CA 94039-7311.
 *
 * THE CONTENT OF THIS WORK CONTAINS CONFIDENTIAL AND PROPRIETARY
 * INFORMATION OF SILICON GRAPHICS, INC. ANY DUPLICATION, MODIFICATION,
 * DISTRIBUTION, OR DISCLOSURE IN ANY FORM, IN WHOLE, OR IN PART, IS STRICTLY
 * PROHIBITED WITHOUT THE PRIOR EXPRESS WRITTEN PERMISSION OF SILICON
 * GRAPHICS, INC.
 */
/**************************************************************************\
 *
 * OpenMOIV - C++ library for molecular visualization using Inventor.
 * Copyright (C) 2001-2003 Universitat Pompeu Fabra - Barcelona (Spain)
 * 
 * Developers: Interactive Technology Group (GTI)
 * Team: Josep Blat, Eduard Gonzalez, Sergi Gonzalez,
 *       Daniel Soto, Alejandro Ramirez, Oscar Civit.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details (see the file 
 * LICENSE.LGPL at the root directory).
 *
 * REMARK: This library is a derived product.
 *         You need also to accept all other applicable licenses.
 * 
 * Homepage: http://www.tecn.upf.es/openMOIV/
 * Contact:  openmoiv@upf.es
 *
\**************************************************************************/

#ident "$Revision: 22148 $"

#ifndef  __CHEM_SELECTION_ELEMENT_H__
#define  __CHEM_SELECTION_ELEMENT_H__

#include "inv/elements/SoInt32Element.H"

#include "inv/ChemKit/ChemkitBasic.H"

//////////////////////////////////////////////////////////////////////////////
//
//  Class: ChemSelectionElement
//
//  Element that stores the current ChemSelection parts.
//
//////////////////////////////////////////////////////////////////////////////

class CHEMKIT_DLL_API ChemSelectionElement : public SoInt32Element {

    SO_ELEMENT_HEADER(ChemSelectionElement);

  public:
    // These are the items which can be selected.
    enum ChemPart {
        ATOMS = 0x01,
        BONDS = 0x02,
        ATOMLABELS = 0x04,
        BONDLABELS = 0x08,
        CHEMLABELS = 0x10,
        CHEMMONITORS = 0x20,
// --> residue selection
				RESIDUES = 0x40,
				RESIDUELABELS = 0x80,
				ALL = 0xFF
				//ALL = 0x3F,
// <-- residue selection
    };

    // Initializes element
    virtual void        init(SoState *state);

    // Sets the current ChemSelection parts in the state
    static void         set(SoState *state, ChemPart parts)
        { SoInt32Element::set(classStackIndex, state, (int32_t)parts); }

#ifndef IV_STRICT
    static void         set(SoState *state, SoNode *, ChemPart parts)
        { set(state, parts); }
#endif

    // Returns current ChemSelection parts from the state
    static ChemPart        get(SoState *state)
        { return (ChemPart)SoInt32Element::get(classStackIndex, state); }

    // Returns the default ChemSelection parts
    static ChemPart        getDefault()            { return ALL; }

    // Prints element (for debugging)
    virtual void        print(FILE *fp) const;

  SoINTERNAL public:
    // Initializes the ChemSelectionElement class
    static void         initClass();

  protected:
    virtual ~ChemSelectionElement();
};

#endif /* __CHEM_SELECTION_ELEMENT_H__ */
