/*
 * libcsps - Crossed-signal positioning system library
 *
 * Copyright (c) 2013-2014 FOXEL SA - http://foxel.ch
 * Please read <http://foxel.ch/license> for more information.
 *
 *
 * Author(s):
 *
 *      Nils Hamel <n.hamel@foxel.ch>
 *
 *
 * This file is part of the FOXEL project <http://foxel.ch>.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Additional Terms:
 *
 *      You are required to preserve legal notices and author attributions in
 *      that material or in the Appropriate Legal Notices displayed by works
 *      containing it.
 *
 *      You are required to attribute the work as explained in the "Usage and
 *      Attribution" section of <http://foxel.ch/license>.
 */

    /*! \file   csps-gps-mod-SGNQF.h
     *  \author Nils Hamel (n.hamel@foxel.ch)
     *
     *  GPS signal quality filtering module (SGNQF - SiGNal Quality Filtering)
     */

/*
    Header - Include guard
 */

    # ifndef __LP_GPS_MODSGNQF__
    # define __LP_GPS_MODSGNQF__

/*
    Header - C/C++ compatibility
 */

    # ifdef __cplusplus
    extern "C" {
    # endif

/*
    Header - Includes
 */

    # include "csps.h"
    # include "csps-device.h"
    # include "csps-path.h"
    # include "csps-qbf.h"
    # include "csps-stream.h"
    # include "csps-timestamp.h"

/*
    Header - Preprocessor definitions
 */

/*
    Header - Preprocessor macros
 */

    /* CSPS module identification */
    # define LP_GPS_MODSGNQF_DEV "gps"
    # define LP_GPS_MODSGNQF_MOD "mod-SGNQF"
    # define LP_GPS_MODSGNQF_DES "SiGNal Quality Filtering"

/*
    Header - Typedefs
 */

/*
    Header - Structures
 */

/*
    Header - Function prototypes
 */

    /*! \brief GPS signal loss component removal module
     *  
     *  This module removes GPS measure on the base of the signal quality. The
     *  output stream contains only measure that have a satisfying quality.
     *  
     *  \param lpPath Path to the CSPS directory structure
     *  \param lpDevice GPS device descriptor
     *  \param lpName GPS device name
     *  \param CSPS input stream
     *  \return Returns lpDevice structure
     */

    lp_GPS lp_gps_mod_SGNQF(

        const lp_Char_t * const lpPath,
        lp_GPS lpDevice,
        const lp_Char_t * const lpPS__

    );

/*
    Header - C/C++ compatibility
 */

    # ifdef __cplusplus
    }
    # endif

/*
    Header - Include guard
 */

    # endif
