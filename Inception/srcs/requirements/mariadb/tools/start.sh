if [ ! -d "/var/lib/mysql/mysql" ]; then

	chown -R mysql:mysql /var/lib/mysql

	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null

	temp_file=`mktemp`
	if [ ! -f "$temp_file" ]; then
		return 1
	fi
	cat << EOF > $temp_file
USE mysql;
FLUSH PRIVILEGES ;
GRANT ALL ON *.* TO '$DB_ADMIN_NAME'@'%' identified by '$DB_ADMIN_PWD' WITH GRANT OPTION ;
GRANT ALL ON *.* TO '$DB_ADMIN_NAME'@'localhost' identified by '$DB_ADMIN_PWD' WITH GRANT OPTION ;
SET PASSWORD FOR '$DB_ADMIN_NAME'@'localhost'=PASSWORD('$DB_ADMIN_PWD') ;
DROP DATABASE IF EXISTS test ;
FLUSH PRIVILEGES ;
CREATE DATABASE $DB_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '$DB_USER_NAME'@'%' IDENTIFIED by '$DB_USER_PWD';
CREATE USER '$DB_USER_NAME'@'localhost' IDENTIFIED by '$DB_USER_PWD';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER_NAME'@'%';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER_NAME'@'localhost';
FLUSH PRIVILEGES;
EOF

	/usr/bin/mysqld --user=mysql --bootstrap < $temp_file
	rm -f $temp_file
fi

sed -i "s|skip-networking|# skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

exec /usr/bin/mysqld --user=mysql --console

