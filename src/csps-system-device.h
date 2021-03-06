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

    /*! \file   csps-system-device.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  CSPS library topology interpreter device interface
     */

/*
    Header - Include guard
 */

    # ifndef __LP_SYSTEM_DEVICE__
    # define __LP_SYSTEM_DEVICE__

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
    # include "csps-system-token.h"

/*
    Header - Preprocessor definitions
 */

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

    /*! \brief Camera devices interface
     * 
     *  This function is the topology parser specific camera device interface.
     *  Its role is to read the device section in the topology file in order to
     *  push the device in the topology device structures stack.
     *
     *  The topology file provided as parameter has to be already openned and
     *  its position has to point token comming just after the 'device' keyword.
     *  The function update the file position to position just after 'end'
     *  keyword at device section end.
     *
     *  \param lpStack  Pointer to device structures stack
     *  \param lpStream Topology file handle
     */

    lp_Void_t lp_system_device_cam(

        lp_Stack_t * const lpStack,
        FILE       * const lpStream

    );

    /*! \brief GPS recievers interface
     * 
     *  This function is the topology parser specific GPS device interface. Its
     *  role is to read the device section in the topology file in order to
     *  push the device in the topology device structures stack.
     *
     *  The topology file provided as parameter has to be already openned and
     *  its position has to point token comming just after the 'device' keyword.
     *  The function update the file position to position just after 'end'
     *  keyword at device section end.
     *
     *  \param lpStack  Pointer to device structures stack
     *  \param lpStream Topology file handle
     */

    lp_Void_t lp_system_device_gps(

        lp_Stack_t * const lpStack,
        FILE       * const lpStream

    );

    /*! \brief IMU sensor interface
     * 
     *  This function is the topology parser specific IMU device interface. Its
     *  role is to read the device section in the topology file in order to
     *  push the device in the topology device structures stack.
     *
     *  The topology file provided as parameter has to be already openned and
     *  its position has to point token comming just after the 'device' keyword.
     *  The function update the file position to position just after 'end'
     *  keyword at device section end.
     *
     *  \param lpStack  Pointer to device structures stack
     *  \param lpStream Topology file handle
     */

    lp_Void_t lp_system_device_imu(

        lp_Stack_t * const lpStack,
        FILE       * const lpStream

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

