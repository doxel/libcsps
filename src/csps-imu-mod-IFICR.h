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

    /*! \file   csps-imu-mod-IFICR.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  IFICR - Inertial Frame Initial Condition Rotation
     */

/*
    Header - Include guard
 */

    # ifndef __LP_IMU_IFICR__
    # define __LP_IMU_IFICR__

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
    # include "csps-rotation.h"
    # include "csps-stream.h"
    # include "csps-timestamp.h"

/*
    Header - Preprocessor definitions
 */

    /* CSPS module identification */
    # define LP_IMU_IFICR_MOD "mod-IFICR"
    # define LP_IMU_IFICR_DES "Inertial Frame Initial Condition Rotation"

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

    /*! \brief Inertial frame initial conditions rotation
     *  
     *  This function consider the inertial frame initial conditions provdied as
     *  input and apply the three rotation around z, y and x axis, in this order,
     *  on the initial conditions using angles provided as parameters.
     * 
     *  \param lpPath   Path to CSPS directory structure
     *  \param lpIMU    IMU device structure
     *  \param lpIMUmod Inertial frame initial conditions initiator module
     *  \param lpxAngle Rotation angle, in radian, around x-axis
     *  \param lpyAngle Rotation angle, in radian, around y-axis
     *  \param lpzAngle Rotation angle, in radian, around z-axis
     */

    lp_Void_t lp_imu_mod_IFICR(

        lp_Char_t const * const lpPath, 
        lp_IMU_t  const         lpIMU,
        lp_Char_t const * const lpIMUmod,
        lp_Real_t const         lpxAngle,
        lp_Real_t const         lpyAngle,
        lp_Real_t const         lpzAngle

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

