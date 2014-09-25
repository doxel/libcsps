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

    /*! \file   csps-system.h
     *  \author Nils Hamel <n.hamel@foxel.ch>
     *
     *  CSPS library topology interpreter
     */

/*
    Header - Include guard
 */

    # ifndef __LP_SYSTEM__
    # define __LP_SYSTEM__

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
    # include "csps-cam-mod-DSIDE.h"
    # include "csps-gps-mod-DSIDE.h"
    # include "csps-gps-mod-SGNQF.h"
    # include "csps-imu-mod-DSIDE.h"
    # include "csps-imu-mod-SGNDN.h"
    # include "csps-imu-mod-SGSFR.h"
    # include "csps-imu-mod-IFETI.h"
    # include "csps-imu-mod-IFICR.h"
    # include "csps-imu-mod-IOBMA.h"
    # include "csps-imu-mod-IOISA.h"
    # include "csps-imu-mod-GYLAE.h"
    # include "csps-imu-mod-ISRAD.h"

/*
    Header - Preprocessor definitions
 */

    /* Define maximum number of token */
    # define LP_SYSTEM_TOKEN        lp_Size_s( 16 )

    /* Define maximum number of devices */
    # define LP_SYSTEM_DEVICE       lp_Size_s( 1024 )

    /* Define maximum number of modules */
    # define LP_SYSTEM_MODULE       lp_Size_s( 1024 )

    /* Define invalid device */
    # define LP_SYSTEM_NODEVICE     lp_Size_s( -1 )

    /* Define topology keywords */
    # define LP_SYSTEM_KW_DEVICE    "device"
    # define LP_SYSTEM_KW_MODULE    "module"
    # define LP_SYSTEM_KW_ENDLIN    "end"
    # define LP_SYSTEM_KW_DVTYPE    "model"
    # define LP_SYSTEM_KW_DVTAGS    "tag"
    # define LP_SYSTEM_KW_DVBLOC    "block"
    # define LP_SYSTEM_KW_DVFREQ    "downsampling"
    # define LP_SYSTEM_KW_DVICRX    "x-rotation"
    # define LP_SYSTEM_KW_DVICRY    "y-rotation"
    # define LP_SYSTEM_KW_DVICRZ    "z-rotation"
    # define LP_SYSTEM_KW_DVIRMX    "isr-max-ranges"
    # define LP_SYSTEM_KW_DVIRMN    "isr-min-accum"
    # define LP_SYSTEM_KW_DVIRTG    "isr-gyros-threshold"
    # define LP_SYSTEM_KW_DVIRTT    "isr-trans-threshold"


    /* Define topology analysis modes */
    # define LP_SYSTEM_MODE_MAIN    lp_Enum_s( 0 )
    # define LP_SYSTEM_MODE_IDEV    lp_Enum_s( 1 )
    # define LP_SYSTEM_MODE_XMOD    lp_Enum_s( 2 )
    # define LP_SYSTEM_MODE_ICAM    lp_Enum_s( 3 )
    # define LP_SYSTEM_MODE_IGPS    lp_Enum_s( 4 )
    # define LP_SYSTEM_MODE_IIMU    lp_Enum_s( 5 )

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

    /*! \brief CSPS topology interpreter
     *
     * This function provides a front-end between CSPS module
     * and the library users. It reads a file that contains the
     * CSPS topology and execute it.
     *
     *  \param lpPath Path CSPS structure
     * \param lpFile Path to the file containing the CSPS topology
     */

    lp_Void_t lp_system(

        const lp_Char_t * const lpPath,
        const lp_Char_t * const lpFile

    );

    /*! \brief File token reader
     *
     * This function simply reads a token from specified file. It
     * returns the pointer to read token buffer.
     * 
     * \param lpFile File from which token is read
     * \param lpToken Read token buffer
     * \return Returns pointer to string allocation that contains read token
     */

    lp_Char_t * lp_system_token(

        FILE      * lpFile,
        lp_Char_t * lpToken

    );

    /*! \brief Device search in stack
     * 
     * This function is a coprocess of topology file interpreter. It
     * searches in devices stack the index of device defined by the
     * specified tag. If the device is not found, an invalid code
     * is returned.
     *
     * \param lpTag Tag of the device to search in stack
     * \param lpType Type of the device to search
     * \param lpIndex Size of the devices stack in device units
     * \param lpTypes Devices type stack array
     * \param lpDescs Devices descriptor stack array
     * \return Return device index in the stack or invalid value
     */

    lp_Size_t lp_system_device_by_tag(

        const lp_Char_t * const lpTag,
        const lp_Enum_t         lpType,
        lp_Size_t               lpIndex,
        lp_Enum_t *             lpTypes,
        lp_Void_t **            lpDescs

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

