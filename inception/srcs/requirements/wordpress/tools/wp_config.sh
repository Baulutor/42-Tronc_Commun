#!/bin/sh

# Pour s'assurer que le script s'arrete a la premiere erreure
#set -e

# Attends 5 secondes pour que mariadb soit bien configuree
# pas de boucle until car cree un warning dans le log de mariadb
#sleep 5


#if ! wp core is-installed --path=${INSTAL_WP}; then
#if [ ! -f /var/www/html/wp-config.php ]; then
#	cd ${INSTAL_WP}
	# Telechargement des fichiers de wordpress
#	wp core download --allow-root
	# Creation de la config
#	wp config create \
#		--allow-root \
#		--dbname=${DATABASE} \
#		--dbuser=${DATA_USER} \
#		--dbpass=${PASS} \
#		--dbhost=${HOST_ID}
	# Creation du site et de l'admin
#	wp core install \
#		--allow-root \
#		--url=${URL} \
#		--title=${TITLE} \
#		--admin_user=${ADMIN} \
#		--admin_password=${ADMIN_PASS} \
#		--admin_email=${ADMIN_MAIL}
	# Creation du User
#	wp user create --allow-root ${USER} ${USER_MAIL} --role=${USER_ROLE} --user_pass=${USER_PASS}
#fi

# Lancement de php-fpm
#php-fpm8.2 -F



#!/bin/bash

if [ ! -f /var/www/html/wp-config.php ]; then
    echo "wp-config.php n'existe pas. Téléchargement et configuration de WordPress..."
    cd /var/www/html

    wp core download --allow-root
    echo "WordPress téléchargé."

    echo dbname=$DATABASE dbuser=$DATA_USER dbpass=$PASS \
                     dbhost="mariadb:3306" path="/var/www/html"

    wp config create --allow-root --dbname=$DATABASE --dbuser=$DATA_USER --dbpass=$PASS \
                     --dbhost="mariadb:3306" --path="/var/www/html"
    
    echo "Fichier de configuration wp-config.php créé."

    wp core install --allow-root --url=$URL --title=$TITLE --admin_user=$ADMIN \
                    --admin_password=$ADMIN_PASS --admin_email=$ADMIN_MAIL
    echo "WordPress installé."

    wp user create --allow-root $USER $USER_MAIL --user_pass=$USER_PASS
    echo "Utilisateur WordPress créé."
else
    echo "wp-config.php existe déjà. Aucune action nécessaire."
fi

exec "$@"
