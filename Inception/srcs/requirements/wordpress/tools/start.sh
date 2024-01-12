if [ ! -f "/var/www/html/wordpress/index.php" ]; then
	wp core download --allow-root
	wp config create --dbname=$DB_NAME --dbuser=$DB_USER_NAME --dbpass=$DB_USER_PWD --dbhost=$DB_SERVER --dbcharset="utf8"  --allow-root
	wp core install --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_NAME --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email   --allow-root
	wp user create $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD   --allow-root
	wp theme install hitchcock --activate --allow-root
fi

exec php-fpm7.3 -F
