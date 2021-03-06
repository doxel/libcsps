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

    /*! \file   csps-device.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  CSPS device descriptors
     */

/*
    Header - Include guard
 */

    # ifndef __LP_DEVICE__
    # define __LP_DEVICE__

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
    # include "csps-device-camera.h"
    # include "csps-device-gps.h"
    # include "csps-device-imu.h"

/*
    Header - Preprocessor definitions
 */

    /* Define device type indexes */
    # define LP_DEVICE_ID_CAM       lp_Enum_s( 1 )
    # define LP_DEVICE_ID_GPS       lp_Enum_s( 2 )
    # define LP_DEVICE_ID_IMU       lp_Enum_s( 3 )

    /* Define device types */
    # define LP_DEVICE_TYPE_CAM     "cam"
    # define LP_DEVICE_TYPE_GPS     "gps"
    # define LP_DEVICE_TYPE_IMU     "imu"

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

