/* fribidi-mirroring.h - get mirrored character
 *
 * Copyright (C) 2004  Sharif FarsiWeb, Inc
 * Copyright (C) 2001, 2002, 2004  Behdad Esfahbod
 * Copyright (C) 1999, 2000  Dov Grobgeld
 *
 * This file is part of GNU FriBidi.
 *
 * GNU FriBidi is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GNU FriBidi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with GNU FriBidi; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * For licensing issues, contact <license@farsiweb.info> or write to
 * Sharif FarsiWeb, Inc., PO Box 13445-389, Tehran, Iran.
 */
/* $Id: fribidi-mirroring.h,v 1.10 2004-09-28 07:58:57 behdad Exp $
 * $Author: behdad $
 * $Date: 2004-09-28 07:58:57 $
 * $Revision: 1.10 $
 * $Source:
 * /home/behdad/src/fdo/fribidi/togit/git/../fribidi/fribidi2/lib/fribidi-mirroring.h,v
 *$
 *
 * Author(s):
 *   Behdad Esfahbod, 2001, 2002, 2004
 *   Dov Grobgeld, 1999, 2000
 */

/**
 * @file fribidi-mirroring.h
 * @brief Get mirrored character
 * @author Mahyar Abbaspour
 * @author Copyright (C) 2001,2002,2004 Behdad Esfahbod
 * @author Copyright (C) 1999,2000 Dov Grobgeld
 */

#ifndef _FRIBIDI_MIRRORING_H
#define _FRIBIDI_MIRRORING_H

#include "fribidi-common.h"

#include "fribidi-types.h"
#include "fribidi-bidi-types.h"

#include "fribidi-begindecls.h"

#define fribidi_get_mirror_char FRIBIDI_NAMESPACE(get_mirror_char)
/** 
 * @breif Get mirrored character
 *
 * This function finds the mirrored equivalent of a character as defined in
 * the file BidiMirroring.txt of the Unicode Character Database available at
 * http://www.unicode.org/Public/UNIDATA/BidiMirroring.txt.
 *
 * If  the input character is a declared as a mirroring character in the
 * Unicode standard and has a mirrored equivalent.  The matching mirrored
 * character is put in the output, otherwise the input character itself is
 * put.
 *
 * @param ch input character
 * @param mirrored_ch output mirrored character
 * @return If the character has a mirroring equivalent or not.
 */
FRIBIDI_ENTRY fribidi_boolean
fribidi_get_mirror_char(FriBidiChar ch, FriBidiChar *mirrored_ch);

#define fribidi_shape_mirroring FRIBIDI_NAMESPACE(shape_mirroring)
/** 
 * @brief Do mirroring shaping
 *
 * This functions replaces mirroring characters on right-to-left embeddings in
 * string with their mirrored equivalent as returned by
 * fribidi_get_mirror_char().
 *
 * This function implements rule L4 of the Unicode Bidirectional Algorithm
 * available at http://www.unicode.org/reports/tr9/#L4.
 *
 * @param embedding_levels input list of embedding levels, as returned by
          fribidi_get_par_embedding_levels
 * @param len input string length
 * @param str string to shape
 */
FRIBIDI_ENTRY void fribidi_shape_mirroring(
    const FriBidiLevel *embedding_levels,    
	const FriBidiStrIndex len,
    FriBidiChar *str);

#include "fribidi-enddecls.h"

#endif /* !_FRIBIDI_MIRRORING_H */
