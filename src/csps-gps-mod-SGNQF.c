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


/*
    Source - Includes
 */

    # include "csps-gps-mod-SGNQF.h"

/*
    Source - GPS signal quality filtering
 */

    lp_Void_t lp_gps_mod_SGNQF( 

        lp_Char_t const * const lpPath, 
        lp_GPS_t  const         lpGPS, 
        lp_Char_t const * const lpGPSmod

    ) {

        /* Integration variables */
        lp_Size_t lpParse = lp_Size_s( 0 );
        lp_Size_t lpIndex = lp_Size_s( 0 );

        /* Stream size variables */
        lp_Size_t lpSize = lp_Size_s( 0 );

        /* Stream memory variables */
        lp_Real_t * lpGPSlat = NULL;
        lp_Real_t * lpGPSlon = NULL;
        lp_Real_t * lpGPSalt = NULL;
        lp_Real_t * lpGPSgdh = NULL;
        lp_Time_t * lpGPSsyn = NULL;
        lp_Time_t * lpGPSqbf = NULL;

        /* Obtain stream size */
        if ( ( lpSize = lp_stream_size( lpPath, lpGPS.dvTag, lpGPSmod ) ) > lp_Size_s( 0 ) ) {

            /* Read streams */
            lpGPSlat = lp_stream_read( lpPath, lpGPS.dvTag, lpGPSmod, LP_STREAM_CPN_LAT, sizeof( lp_Real_t ) * lpSize );
            lpGPSlon = lp_stream_read( lpPath, lpGPS.dvTag, lpGPSmod, LP_STREAM_CPN_LON, sizeof( lp_Real_t ) * lpSize );
            lpGPSalt = lp_stream_read( lpPath, lpGPS.dvTag, lpGPSmod, LP_STREAM_CPN_ALT, sizeof( lp_Real_t ) * lpSize );
            lpGPSgdh = lp_stream_read( lpPath, lpGPS.dvTag, lpGPSmod, LP_STREAM_CPN_GDH, sizeof( lp_Real_t ) * lpSize );
            lpGPSqbf = lp_stream_read( lpPath, lpGPS.dvTag, lpGPSmod, LP_STREAM_CPN_TAG, sizeof( lp_Time_t ) * lpSize );
            lpGPSsyn = lp_stream_read( lpPath, lpGPS.dvTag, lpGPSmod, LP_STREAM_CPN_SYN, sizeof( lp_Time_t ) * lpSize );

            /* Signal quality filtering */
            for ( lpParse = lp_Size_s( 0 ) ; lpParse < lpSize - lp_Size_s( 1 ) ; lpParse ++ ) {

                /* Check signal QBF threshold */
                if ( lp_qbf_threshold( lpGPSqbf[lpParse] ) == LP_FALSE ) {

                    /* Rethrow values */
                    lpGPSlat[lpIndex] = lpGPSlat[lpParse];
                    lpGPSlon[lpIndex] = lpGPSlon[lpParse];
                    lpGPSalt[lpIndex] = lpGPSalt[lpParse];
                    lpGPSgdh[lpIndex] = lpGPSgdh[lpParse];
                    lpGPSsyn[lpIndex] = lpGPSsyn[lpParse];
                    lpGPSqbf[lpIndex] = lpGPSqbf[lpParse];

                    /* Update rethrown value index */
                    lpIndex ++;

                }

            }

            /* Write stream data */
            lp_stream_write( lpPath, lpGPS.dvTag, LP_GPS_SGNQF_MOD, LP_STREAM_CPN_LAT, lpGPSlat, sizeof( lp_Real_t ) * lpIndex );
            lp_stream_write( lpPath, lpGPS.dvTag, LP_GPS_SGNQF_MOD, LP_STREAM_CPN_LON, lpGPSlon, sizeof( lp_Real_t ) * lpIndex );
            lp_stream_write( lpPath, lpGPS.dvTag, LP_GPS_SGNQF_MOD, LP_STREAM_CPN_ALT, lpGPSalt, sizeof( lp_Real_t ) * lpIndex );
            lp_stream_write( lpPath, lpGPS.dvTag, LP_GPS_SGNQF_MOD, LP_STREAM_CPN_GDH, lpGPSgdh, sizeof( lp_Real_t ) * lpIndex );
            lp_stream_write( lpPath, lpGPS.dvTag, LP_GPS_SGNQF_MOD, LP_STREAM_CPN_TAG, lpGPSqbf, sizeof( lp_Time_t ) * lpIndex );
            lp_stream_write( lpPath, lpGPS.dvTag, LP_GPS_SGNQF_MOD, LP_STREAM_CPN_SYN, lpGPSsyn, sizeof( lp_Time_t ) * lpIndex );

            /* Unallocate buffer memory */
            lpGPSlat = lp_stream_delete( lpGPSlat );
            lpGPSlon = lp_stream_delete( lpGPSlon );
            lpGPSalt = lp_stream_delete( lpGPSalt );
            lpGPSgdh = lp_stream_delete( lpGPSgdh );
            lpGPSsyn = lp_stream_delete( lpGPSsyn );
            lpGPSqbf = lp_stream_delete( lpGPSqbf );

        }

    }

