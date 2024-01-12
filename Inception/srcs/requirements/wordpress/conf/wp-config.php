<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv("DB_NAME") );

/** Database username */
define( 'DB_USER', getenv("DB_USER_NAME") );

/** Database password */
define( 'DB_PASSWORD', getenv("DB_USER_PWD") );

/** Database hostname */
define( 'DB_HOST', getenv("DB_SERVER"));

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );


// https://wordpress.org/support/article/installing-wordpress-in-your-language/
define ('WPLANG', 'fr_FR');

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'PP^U| v?*MAs}Yl9G9I(ra|b9<R>s~d#B|41|!FaIFl?|P7|/v$o38WM_,L{4k|v');
define('SECURE_AUTH_KEY',  '>wjXLh|=|0$_z6:^T-QXqk`#@>Kl.R0l5jc;qVp o u-IXa*;n5+/EB+Z=|&f:rk');
define('LOGGED_IN_KEY',    'y+V7pdlHmx2-]F>l.-Tz3jwnlYzzcGU|!xu`jU:N9HE:oC Ws{ca4Ac-jp8](m_U');
define('NONCE_KEY',        'Ah+VQHn=+[B.Gk6|+.j;outSbo<?R33@d~ZHG6ykd/eE/~Geo-mo+7r~xi7X{b$Q');
define('AUTH_SALT',        '1zCyd@UW)fK5;-8,G{wNz]8FiWo?CaqA3&EB-1)ikr>D}1laMDQ*lK*.wMGw~mFv');
define('SECURE_AUTH_SALT', '5K7O}]u<%A+bZCm$iJ0]5?AZ=:M:`U2#|,69Jrne4555b!Jr7FHHx9F^kx;/K~(Y');
define('LOGGED_IN_SALT',   '9^}bnX6i~v+NVo.wj,%9aTr|-b_)QJ9i{|;>,PW&]|Z8-:-CuSm]-&5gtyD*VKIK');
define('NONCE_SALT',       '=-j.N+{Ulck`~>N-6U-N}Ww}16#~rW*+#[EZ[|4ZKqRK|rz}k`)5#PmdI40wm6+8');


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
