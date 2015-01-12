/*
 * libcsps - Crossed-signal positioning system library
 *
 * Copyright (c) 2013-2015 FOXEL SA - http://foxel.ch
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

    /*! \file   csps-gps-mod-DSIDE.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  DSIDE - Device-Specitic Initial Data Extraction
     */

/*
    Header - Include guard
 */

    # ifndef __LP_GPS_DSIDE__
    # define __LP_GPS_DSIDE__

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
    # include "csps-nmea.h"
    # include "csps-path.h"
    # include "csps-stream.h"
    # include "csps-timestamp.h"

/*
    Header - Preprocessor definitions
 */

    /* CSPS module identification */
    # define LP_GPS_DSIDE_MOD "mod-DSIDE"
    # define LP_GPS_DSIDE_DES "Device-Specitic Initial Data Extraction"

/*
    Header - Preprocessor macros
 */

/*
    Header - Typedefs
 */

/*
    Header - Structures
 */

/*
    Header - Function prototypes
 */

    /*! \brief Device extraction switch
     *  
     *  Switch on device-specific extractor. On the base of the device 
     *  descriptor given as parameter, the device-specific extractor is called.
     *
     *  \param lpPath   Path CSPS structure
     *  \param lpGPS    Device descriptor
     */

    lp_Void_t lp_gps_mod_DSIDE( 

        lp_Char_t const * const lpPath, 
        lp_GPS_t  const         lpGPS, 
        lp_Size_t const         lpBlock

    );

    /*! \brief LS20031 GPS reciever specific initial extractor
     *
     *  LS20031 GPS device specific extraction sub-module.
     *
     *  \param lpPath   Path CSPS structure
     *  \param lpGPS    Device descriptor
     */

    lp_Void_t lp_gps_DSIDE_LS20031( 

        lp_Char_t const * const lpPath, 
        lp_GPS_t  const         lpGPS, 
        lp_Size_t const         lpBlock 

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

