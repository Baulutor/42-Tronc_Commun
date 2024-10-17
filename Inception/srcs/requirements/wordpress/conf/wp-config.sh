#!/bin/bash

if [ ! -f /var/www/html/wp-config.php ]; then
	mkdir -p /run/php/ && mkdir -p /var/www/html
	chown -R www-data:www-data /var/www/*

    echo "wp-config.php n'existe pas. Téléchargement et configuration de WordPress..."
    cd /var/www/html

    wp core download --allow-root
    echo "WordPress téléchargé."

    echo dbname=$MYSQL_DATABASE dbuser=$MYSQL_USER dbpass=$MYSQL_PASSWORD \
                     dbhost="mariadb:3306" path="/var/www/html"

    wp config create --allow-root --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD \
                     --dbhost="mariadb:3306" --path="/var/www/html"
    
    echo "Fichier de configuration wp-config.php créé."

    wp core install --allow-root --url=$WP_URL --title=$WP_TITLE --admin_user=$ADMIN_USER \
                    --admin_password=$WP_ADMIN_PASSWORD --admin_email=$ADMIN_EMAIL
    echo "WordPress installé."

    wp user create --allow-root $WP_USER_LOGIN $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD
    echo "Utilisateur WordPress créé."
else
    echo "wp-config.php existe déjà. Aucune action nécessaire."
fi

exec "$@"
