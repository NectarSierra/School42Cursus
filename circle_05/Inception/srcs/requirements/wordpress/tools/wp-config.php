<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the website, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://developer.wordpress.org/advanced-administration/wordpress/wp-config/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('WORDPRESS_DB_NAME') );

/** Database username */
define( 'DB_USER', getenv('WORDPRESS_DB_USER') );

/** Database password */
$dbpasswd = rtrim(file_get_contents("/run/secrets/DB_PASSWORD"));
define( 'DB_PASSWORD', $dbpasswd );

/** Database hostname */
define( 'DB_HOST', getenv('WORDPRESS_DB_HOST') );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

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
define( 'AUTH_KEY',         '=.0`:E4&C=06c!|UzAh1LCTY%Vnt6;|%ALhO=7Bw9M}NyolX9y8aXcrwP$]ZAS8(' );
define( 'SECURE_AUTH_KEY',  '*jOA0$p$3u(^V)/5uX9iGDe8PD*~=(kO%3,xaa4u.5!F~U{quSGKAUQvDd|d2Zs ' );
define( 'LOGGED_IN_KEY',    'O_gA*!7&f%l-%9]M}XG*>M06VzAnf~%_(fzq/z~aD>_v~agDh=;QjuPp#g`GGfAT' );
define( 'NONCE_KEY',        'TR66goz|~SsadGXm)QYAyov/4JCSVqf1P5Ca[nYlFkN@Pg!@$QcvGl)}GgYB7Fjo' );
define( 'AUTH_SALT',        'h1+~!M|a3T- T~fm*dly|[|.AE*jON$fCQj!P4l(3wWMswHx>!/R43H@Iw<D&x1l' );
define( 'SECURE_AUTH_SALT', 'y$8^?La$2]=JPgH9i%@z9NBeL>Zj9<RmnLY7gQcKEqWTG8c,?x#qc-(.cjd-3.;m' );
define( 'LOGGED_IN_SALT',   '$K1~tsD@U-o}h`fnt1vRHt<vBLe9xAX#~  Yi`!kheoM>^ fAFI4U9uL_rYC3b4@' );
define( 'NONCE_SALT',       'DhuIUDB9:lo{Vxlz(H-kG{G7mo47Y2FYiME`}pD*i*ghozb9GlE5vN;mH}-St@dC' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 *
 * At the installation time, database tables are created with the specified prefix.
 * Changing this value after WordPress is installed will make your site think
 * it has not been installed.
 *
 * @link https://developer.wordpress.org/advanced-administration/wordpress/wp-config/#table-prefix
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
 * @link https://developer.wordpress.org/advanced-administration/debug/debug-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */

if (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && strpos($_SERVER['HTTP_X_FORWARDED_PROTO'], 'https') !== false) {
    $_SERVER['HTTPS'] = 'on';
}

// Define the site URLs dynamically using an environment variable
define('WP_HOME', 'https://' . getenv('DOMAIN_NAME'));
define('WP_SITEURL', 'https://' . getenv('DOMAIN_NAME'));

// For good measure, also force SSL on the admin login
define('FORCE_SSL_ADMIN', true);
define('FORCE_SSL_LOGIN', true);

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

