/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0x0C45
#define PRODUCT_ID      0x652F
#define DEVICE_VER      0x0001
#define MANUFACTURER    TECWARE
#define PRODUCT         Phantom TKL
#define DESCRIPTION     "Mechanical keyboard"

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 13

/* key matrix pins */
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D4, D5, D6 }
#define MATRIX_COL_PINS { C1, C2, A0, A1, A2, A3, A6, A7, A8, A9, A10, A11, A12 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
//#define DIODE_DIRECTION COL2ROW
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5


#define NO_DEBUG 1
#define NO_PRINT 1

//#define FORCE_NKRO TRUE
