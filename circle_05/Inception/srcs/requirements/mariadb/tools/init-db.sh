#!/bin/bash

if [ ! -f .initialized ];
then
	echo "Starting MariaDB..."
	mysqld_safe & until mysqladmin ping --silent; do sleep 1; done
	echo "Initializing Database"
	mysql -uroot -p"`cat /run/secrets/DB_ROOT_PASSWORD`" <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '`cat /run/secrets/DB_ROOT_PASSWORD`';
CREATE DATABASE IF NOT EXISTS $MARIA_DB_NAME;
CREATE USER IF NOT EXISTS '$MARIA_DB_USER'@'%' IDENTIFIED BY '`cat /run/secrets/DB_PASSWORD`';
GRANT ALL PRIVILEGES ON $MARIA_DB_NAME.* TO '$MARIA_DB_USER'@'%';
FLUSH PRIVILEGES;
EOF
	echo "Database initialized!"
	touch .initialized
	echo "Restarting MariaDB..."
	mysqladmin -uroot -p"`cat /run/secrets/DB_ROOT_PASSWORD`" shutdown
	mysqld_safe
else
	echo "Starting MariaDB..."
	mysqld_safe
fi

